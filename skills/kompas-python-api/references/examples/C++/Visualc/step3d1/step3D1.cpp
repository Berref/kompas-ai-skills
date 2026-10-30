////////////////////////////////////////////////////////////////////////////////
//
// step3d1.cpp - Операции
//
// 1. Базовая операция выдавливания - CreateExtrusion
// 2. Операции вращения             - OperationRotated
// 3. Операции по сечениям          - OperationLoft
// 4. Создание фаски и скругления   - CreateFilletAndChamfer
// 5. Операции : оболочка, уклон, сечение плоскостью, сечение эскизом"
//                                  - CreateNextOper
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE StepDLL = { NULL, NULL };


//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
  UNREFERENCED_PARAMETER( lpReserved );

  if ( dwReason == DLL_PROCESS_ATTACH )
  {
    TRACE0( "DLL Initializing!" );
 
    if ( !AfxInitExtensionModule( StepDLL, hInstance ) )
      return 0;

    new CDynLinkLibrary( StepDLL );
  }
  else if ( dwReason == DLL_PROCESS_DETACH )
  {
    TRACE0( "DLL Terminating!" );
    AfxTermExtensionModule( StepDLL );
  }
  return 1;
}

 
//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// Ресурсы ( имя библиотеки, состав меню, слайд ) находятся в <res\step3d1.rc2> , идентификаторы в <step3d1.rh>
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void CreateExtrusion( IPartPtr& part, IDocument3DPtr & pDocument3d );
void OperationRotated( IPartPtr& part );
void OperationLoft( IPartPtr& part );
void LoftSurface( IPartPtr & part ); 
void CreateFilletAndChamfer( IPartPtr& part );
void CreateNextOper( IPartPtr& part );


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( UINT comm )
{
  IDocument3DPtr pDocument3d( ksGetActive3dDocument(), false ); // Получить указатель на активный документ трехмерной модели
  if ( (bool)pDocument3d /*&& pDocument3d->IsDetail()*/ )
  {
    pDocument3d->SetTreeNeedRebuild( false ); 
    bool addUndoContainer = false;
    IKompasDocument3DPtr doc3D( IUnknownPtr( ksTransferInterface(pDocument3d, ksAPI7Dual, 0), false) );
    if ( doc3D && YesNoT(_T("Объединить команды в UNDO ?")) == 1 )
    {
      doc3D->UndoContainer = true;
      addUndoContainer = true;
    }

    // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
    // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
    IPartPtr part( pDocument3d->GetPart( pTop_Part ), false );
    if ( part )
    {
      switch ( comm )
      {
        case 1 : CreateExtrusion       ( part, pDocument3d ); break; // Базовая операция выдавливания
        case 2 : OperationRotated      ( part ); break; // Операции вращения
        case 3 : OperationLoft         ( part ); break; // Операции по сечениям
//        case 3 : LoftSurface           ( part ); break;
        case 4 : CreateFilletAndChamfer( part ); break; // Создание фаски и скругления
        case 5 : CreateNextOper        ( part ); break; // Операции : оболочка, уклон, сечение плоскостью, сечение эскизом
      }
    }
    pDocument3d->SetTreeNeedRebuild( true );
    if ( doc3D && addUndoContainer )
      doc3D->UndoContainer = false;
  }
  else
  {
    CString strError;
    strError.LoadString( IDS_3DDOCERROR ); // "Документ не активизирован или не является 3D-моделью"
    ErrorT( ( LPTSTR )( LPCTSTR )strError ); // Выдать сообщение о ошибке
  }
  if ( ReturnResult() == etError10 )       // "Ошибка! Вырожденный объект"
    ResultNULL();                          // Обнулить ошибки
}


//-------------------------------------------------------------------------------
// Удалить все объекты из текущего эскиза
// ---
void ClearCurrentSketch()
{
  // Создаим итератор и удалим все существующие объекты в эскизе
  reference rIterator = CreateIterator( ALL_OBJ, 0 );
  if ( rIterator )
  {
    reference rObject = MoveIterator( rIterator, 'F' ); // Сместить указатель на первый элемент в списке
    // В цикле сместить указатель на следующий элемент в списке пока не дойдем до последнего
    while ( rObject )
    {
      // Если объект существует удалить его
      if ( ExistObj( rObject ) )
        DeleteObj( rObject );
      // Следующий элемент в списке
      rObject = MoveIterator( rIterator, 'N' );
    }
    DeleteIterator( rIterator ); // Удалим итератор
  }
}


//-------------------------------------------------------------------------------
// Оперция выдавливания, работа с экизом
// ---
void CreateExtrusion( IPartPtr& part, IDocument3DPtr & pDocument3d )
{
  // Создадим новый эскиз
  IEntityPtr entitySketch( part->NewEntity(o3d_sketch), false /*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    ISketchDefinitionPtr sketchDefinition( IUnknownPtr( entitySketch->GetDefinition(), false /*AddRef*/ ) );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY), false /*AddRef*/ );
 
      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
      sketchDefinition->SetAngle( 45 );        // Угол поворота эскиза
 
      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
     if ( sketchDefinition->BeginEdit() )
     {
       // Введем новый эскиз - квадрат
       LineSeg(  50,  50, -50,  50, 1 );
       LineSeg(  50, -50, -50, -50, 1 );
       LineSeg(  50, -50,  50,  50, 1 );
       LineSeg( -50, -50, -50,  50, 1 );
//       RegularPolygonParam par;
//       par.count=5;
//       par.xc = 0;
//       par.yc = 0;
//       par.ang=0;
//       par.describe = 0;
//       par.radius = 200;
//       par.style=1; 
//       par.pCorner = 0;
//       reference p = ksRegularPolygon( &par, 2 );
//       ksDestroyObjects( p );

       // Выйти из режима редактирования эскиза
       sketchDefinition->EndEdit();
     }

     // Оперция выдавливани
     IEntityPtr entityExtrusion( part->NewEntity( o3d_bossExtrusion ), false /*AddRef*/ );
     if ( entityExtrusion )
     {
       // Интерфейс базовой операции выдавливания
       IBossExtrusionDefinitionPtr extrusionDefinition( IUnknownPtr( entityExtrusion->GetDefinition(), false/*AddRef*/ ) );
       if ( extrusionDefinition )
       {
         // Установка параметров операции выдавливания
         extrusionDefinition->SetDirectionType( dtNormal );     // Направление выдавливания ( dtNormal	- прямое
                                                                // направление, для тонкой стенки - наружу,
                                                                // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
         // Изменить параметры выдавливания в одном направлении
         extrusionDefinition->SetSideParam( true,               // Направление выдавливания ( TRUE - прямое направление,
                                                                // FALSE - обратное направление )
                                            etBlind,            // Тип выдавливания ( etBlind - строго на глубину,
                                                                // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                                // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                                // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                // etUpToNearSurface	- до ближайшей поверхности )
                                            200,                // Глубина выдавливания
                                            0,                  // Угол уклона
                                            false );            // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
         // Изменить параметры тонкой стенки
         extrusionDefinition->SetThinParam( true,               // Признак тонкостенной операции
                                            dtBoth,             // Направление построения тонкой стенки
                                            10,                 // Толщина стенки в прямом направлении
                                            10 );               // Толщина стенки в обратном направлении
         extrusionDefinition->SetSketch( entitySketch );        // Эскиз операции выдавливания

         // Создать операцию выдавливания
         entityExtrusion->Create();  
//         return;
         MessageT( _T("Операция выдавливания") );

         // Изменим параметры операции выдавливания              
         extrusionDefinition->SetDirectionType( dtBoth );       // Направление выдавливания ( dtNormal	- прямое
                                                                // направление, для тонкой стенки - наружу,
                                                                // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
         // Изменить параметры выдавливания в одном направлении
         extrusionDefinition->SetSideParam( false,              // Направление выдавливания ( TRUE - прямое направление,
                                                                // FALSE - обратное направление )
                                            etBlind,            // Тип выдавливания ( etBlind - строго на глубину,
                                                                // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                                // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                                // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                // etUpToNearSurface	- до ближайшей поверхности )
                                            150,                // Глубина выдавливания
                                            0,                  // Угол уклона
                                            false );            // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
             
         // Обновить параметры
         entityExtrusion->Update(); 
         MessageT( _T("Изменили параметры операции выдавливания") );

         // Войти в режим редактирования эскиза
         if ( sketchDefinition->BeginEdit())
         {
           // Удалить все объекты из текущего эскиза
           ClearCurrentSketch();                
           // Введем в эскиз окружность
           Circle( 0, 0, 100, 1 );
           // Выйти из режима редактирования эскиза
           sketchDefinition->EndEdit(); 
         }
             
         // Обновить параметры эскиза
         entitySketch->Update();               
         // Обновить параметры операции выдавливания
         entityExtrusion->Update();   
         MessageT( _T("Поменяли эскиз") );

         // Создадим новый эскиз
         IEntityPtr entitySketch2( part->NewEntity( o3d_sketch ), false /*AddRef*/ );
         if ( entitySketch2 ) 
         {
           // Получить указатель на интерфейс параметров объектов и элементов
           ISketchDefinitionPtr sketchDefinition2( IUnknownPtr( entitySketch2->GetDefinition(), false /*AddRef*/ ) );
           if ( sketchDefinition2 ) 
           {
             // Установка параметров эскиза
             sketchDefinition2->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
             sketchDefinition2->SetAngle( 45 );        // Повернем эскиз на 45 град.
               
             // Создадим эскиз
             entitySketch2->Create(); 

             // Войти в режим редактирования эскиза
             if ( sketchDefinition2->BeginEdit() )
             {
               // Введем новый эскиз - окружность
               Circle( 0, 0, 150, 1 );
               // Выйти из режима редактирования эскиза
               sketchDefinition2->EndEdit();
             }

             // Приклеим выдавливанием
             IEntityPtr entityBossExtrusion( part->NewEntity( o3d_bossExtrusion ), false /*AddRef*/ );
             if ( entityBossExtrusion ) 
             {
               
               // Получить указатель на интерфейс параметров объектов и элементов
               // Интерфейс параметров приклеенного элемента выдавливания
               IBossExtrusionDefinitionPtr bossExtrusionDefinition( IUnknownPtr( entityBossExtrusion->GetDefinition(), false /*AddRef*/ ) );
               if ( bossExtrusionDefinition ) 
               {
                 IExtrusionParamPtr extrusionParam( bossExtrusionDefinition->ExtrusionParam(), false /*AddRef*/ ); // Интерфейс структуры параметров выдавливания
                 IThinParamPtr      thinParam( bossExtrusionDefinition->ThinParam(), false /*AddRef*/ );           // Интерфейс структуры параметров тонкой стенки
                 if ( (bool)extrusionParam && (bool)thinParam ) 
                 {
                   // Установка параметров элемента выдавливания
                   bossExtrusionDefinition->SetSketch( entitySketch2 ); // Эскиз операции выдавливания

                   extrusionParam->SetDirection( dtNormal ); // Направление выдавливания ( dtNormal	- прямое
                                                             // направление, для тонкой стенки - наружу,
                                                             // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                             // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
                   extrusionParam->SetTypeNormal( etBlind ); // Тип выдавливания ( etBlind - строго на глубину,
                                                             // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                             // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на расстояние
                                                             // до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                             // etUpToNearSurface - до ближайшей поверхности )
                   extrusionParam->SetDepthNormal( 100 );    // Глубина выдавливания
                   thinParam->SetThin( false );              // Признак формирования тонкой стенки элемента ( TRUE	- тонкая стенка, 
                                                             // формируется, FALSE - тонкая стенка не формируется )
                   entityBossExtrusion->Create(); // Приклеим выдавливанием
                   MessageT( _T("Приклеим выдавливанием") );            
                 }
               }

               // Создадим новый эскиз
               IEntityPtr entitySketch3( part->NewEntity( o3d_sketch ), false /*AddRef*/ );
               if ( entitySketch3 )
               {
                 
                 // Получить указатель на интерфейс параметров объектов и элементов
                 // Интерфейс свойств эскиза
                 ISketchDefinitionPtr sketchDefinition3( IUnknownPtr(entitySketch3->GetDefinition(), false /*AddRef*/ ) );
                 if ( sketchDefinition3 )
                 {
                   // Установка параметров эскиза
                   sketchDefinition3->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
                   sketchDefinition3->SetAngle( 45 );        // Повернем эскиз на 45 град.
                     
                   // Создадим эскиз              
                   entitySketch3->Create(); 

                   // Войти в режим редактирования эскиза
                   if ( sketchDefinition3->BeginEdit() )
                   {
                     // Введем новый эскиз - квадрат
                     LineSeg(  50,  50, -50,  50, 1 );
                     LineSeg(  50, -50, -50, -50, 1 );
                     LineSeg(  50, -50,  50,  50, 1 );
                     LineSeg( -50, -50, -50,  50, 1 );
                     // Выйти из режима редактирования эскиза
                     sketchDefinition3->EndEdit();
                   }
                     
                   // Вырежим выдавливанием
                   IEntityPtr entityCutExtrusion( part->NewEntity( o3d_cutExtrusion ), false /*AddRef*/ ); 
                   if ( entityCutExtrusion ) 
                   {
                     
                     // Получить указатель на интерфейс параметров объектов и элементов
                     // Интерфейс параметров вырезанного элемента выдавливания
                     ICutExtrusionDefinitionPtr cutExtrusionDefinition( IUnknownPtr( entityCutExtrusion->GetDefinition(), false /*AddRef*/ ) );
                     if ( cutExtrusionDefinition ) 
                     {
                       // Установка параметров операции выдавливания
                       cutExtrusionDefinition->SetDirectionType( dtReverse );   // Направление выдавливания ( dtNormal	- прямое
                                                                               // направление, для тонкой стенки - наружу,
                                                                               // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                               // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
                       // Изменить параметры выдавливания в одном направлении
                       cutExtrusionDefinition->SetSideParam( false,            // Направление выдавливания ( TRUE - прямое направление,
                                                                               // FALSE - обратное направление )
                                                             etBlind,          // Тип выдавливания ( etBlind - строго на глубину,
                                                                               // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,                  
                                                                               // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                                               // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                               // etUpToNearSurface	- до ближайшей поверхности )
                                                             50,               // Глубина выдавливания
                                                             0,                // Угол уклона
                                                             false );          // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
                       // Изменить параметры тонкой стенки
                       cutExtrusionDefinition->SetThinParam( false,                 // Признак тонкостенной операции
                                                             0,                     // Направление построения тонкой стенки
                                                             0,                     // Толщина стенки в прямом направлении
                                                             0 );                   // Толщина стенки в обратном направлении
                       cutExtrusionDefinition->SetSketch( entitySketch3 );          // Эскиз операции выдавливания

                       // Вырежим выдавливанием
                       entityCutExtrusion->Create();
                       MessageT( _T("Вырежем выдавливанием") );
                     }
                   }
                 }
               }
             }
           }
         }
       }
     }
   }
 }
}


//-------------------------------------------------------------------------------
// Cоздание фаски и скругления
// ---
void CreateFilletAndChamfer( IPartPtr& part ) 
{
  // Создадим новый эскиз
  IEntityPtr entitySketch( part->NewEntity(o3d_sketch), false /*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
     
    ISketchDefinitionPtr sketchDefinition( IUnknownPtr( entitySketch->GetDefinition(), false /*AddRef*/ ) );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );
 
      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
      sketchDefinition->SetAngle( 45 );        // Угол поворота эскиза
 
      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition->BeginEdit() )
      {
        // Введем новый эскиз - квадрат
        LineSeg(  50,  50, -50,  50, 1 );
        LineSeg(  50, -50, -50, -50, 1 );
        LineSeg(  50, -50,  50,  50, 1 );
        LineSeg( -50, -50, -50,  50, 1 );
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }
        
      // Оперция выдавливани
      IEntityPtr entityExtrusion( part->NewEntity( o3d_bossExtrusion ), false /*AddRef*/ );
      if ( entityExtrusion )
      {
        
        // Интерфейс базовой операции выдавливания
        IBossExtrusionDefinitionPtr extrusionDefinition( IUnknownPtr( entityExtrusion->GetDefinition(), false /*AddRef*/ ) );
        if ( extrusionDefinition )
        {
          // Установка параметров операции выдавливания
          extrusionDefinition->SetDirectionType( dtNormal );     // Направление выдавливания ( dtNormal	- прямое
                                                                 // направление, для тонкой стенки - наружу,
                                                                 // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                 // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          extrusionDefinition->SetSideParam( true,               // Направление выдавливания ( TRUE - прямое направление,
                                                                 // FALSE - обратное направление )
                                             etBlind,            // Тип выдавливания ( etBlind - строго на глубину,
                                                                 // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                                 // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                                 // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                 // etUpToNearSurface	- до ближайшей поверхности )
                                             100,                // Глубина выдавливания
                                             0,                  // Угол уклона
                                             false );            // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
          // Изменить параметры тонкой стенки
          extrusionDefinition->SetThinParam( false,              // Признак тонкостенной операции
                                             0,                  // Направление построения тонкой стенки
                                             0,                  // Толщина стенки в прямом направлении
                                             0 );                // Толщина стенки в обратном направлении
          extrusionDefinition->SetSketch( entitySketch );        // Эскиз операции выдавливания
 
          // Создать операцию выдавливания
          entityExtrusion->Create();  
              
          // Формирует массив объектов и возвращает указатель на его интерфейс - массив граней компонента       
          IEntityCollectionPtr entityCollection( part->EntityCollection( o3d_face ), false /*AddRef*/ );
          if ( (bool)entityCollection && entityCollection->SelectByPoint( 0, 0, 0 ) && // Выбор по точке
               entityCollection->GetCount() )                // Получить количество элементов в массиве
          {
            // Скругление 
            IEntityPtr entityFillet( part->NewEntity( o3d_fillet ), false /*AddRef*/ );
            if ( entityFillet ) 
            {
              
              // Получить указатель на интерфейс параметров объектов и элементов
              IFilletDefinitionPtr filletDefinition( IUnknownPtr( entityFillet->GetDefinition(), false /*AddRef*/ ) );
              if ( filletDefinition ) 
              {
                // Установка параметров скругления
                filletDefinition->SetRadius( 10 );      // Радиус скругления
                filletDefinition->SetTangent( false );  // Продолжить по касательной
                IEntityCollectionPtr arrayFilletDefinition( filletDefinition->Array(), false /*AddRef*/ ); // Динамический массив объектов  
                if ( arrayFilletDefinition ) 
                {
                  // Получение граней для скругления 
                  for ( int i = 0, count = entityCollection->GetCount(); i < count; i++ ) {
                    IEntityPtr ent( entityCollection->GetByIndex(i), false/*AddRef*/ ); 
                    arrayFilletDefinition->Add( ent );
                  }
                  // Создать операцию скругления
                  entityFillet->Create();
                  MessageT( _T("Скругление") );
                }
              }
            }

            // Формирует массив объектов и возвращает указатель на его интерфейс - массив граней компонента        
            IEntityCollectionPtr entityCollection2( part->EntityCollection( o3d_face ), false /*AddRef*/ );
            if ( (bool)entityCollection2 && 
                       entityCollection2->SelectByPoint( 0, 0, 100 ) && // Выбор по точке
                       entityCollection2->GetCount() )                  // Получить количество элементов в массиве
            {
              // Фаска 
              IEntityPtr entityChamfer( part->NewEntity( o3d_chamfer ), false /*AddRef*/ );
              if ( entityChamfer ) 
              {
                 
                // Получить указатель на интерфейс параметров объектов и элементов
                IChamferDefinitionPtr chamferDefinition( IUnknownPtr( entityChamfer->GetDefinition(), false /*AddRef*/ ) );
                if ( chamferDefinition ) 
                {
                   // Установка параметров фаски
                  chamferDefinition->SetTangent( false );   // Продолжить по касательной
                  chamferDefinition->SetChamferParam( true, // Признак направления фаски
                                                      10,   // Размер первого катета фаски 
                                                      10 ); // Размер второго катета фаски
                  IEntityCollectionPtr arrayChamferDefinition( chamferDefinition->Array(), false /*AddRef*/ ); // Динамический массив объектов  
                  if ( arrayChamferDefinition ) 
                  {
                    // Получение граней для фаски 
                    for ( int i = 0, count = entityCollection2->GetCount(); i < count; i++ ) {
                      IEntityPtr ePtr ( entityCollection2->GetByIndex( i ), false/*AddRef*/ );
                      arrayChamferDefinition->Add( ePtr );
                    }
                        // Создание фаски
                    entityChamfer->Create();
                    MessageT( _T("Фаска") );
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Операции вращения
// ---
void OperationRotated( IPartPtr & part ) 
{
  // Создадим новый эскиз
  IEntityPtr entitySketch( part->NewEntity(o3d_sketch), false/*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition( IUnknownPtr( entitySketch->GetDefinition(), false /*AddRef*/ ) );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );
 
      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
 
      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition->BeginEdit() )
      {
        // Введем новый эскиз
        ArcByAngle( 0, 0, 20, -90, 90, 1, 1 );
        LineSeg( 0, -20, 0, 20, 3 );
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }
      // Операции вращения
      IEntityPtr entityRotate( part->NewEntity( o3d_bossRotated ), false/*AddRef*/ );
      if ( entityRotate ) 
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс базовой операции вращения
        IBossRotatedDefinitionPtr baseRotatedDefinition( IUnknownPtr( entityRotate->GetDefinition(), false/*AddRef*/ ) ); 
        if ( baseRotatedDefinition ) 
        {
          baseRotatedDefinition->SetToroidShapeType( false );      // Признак тороида ( TRUE - тороид, FALSE - сфероид )
          baseRotatedDefinition->SetDirectionType( dtBoth );       // Направление вращения ( dtNormal - прямое направление, для тонкой стенки - наружу
                                                                   // dtReverse - обратное направление, для тонкой стенки - внутрь, dtBoth - в обе стороны,
                                                                   // dtMiddlePlane - от средней плоскости )
          // Изменить параметры тонкой стенки
          baseRotatedDefinition->SetThinParam( true,               // Признак тонкостенной операции
                                               dtBoth,             // Направление построения тонкой стенки
                                               1,                  // Толщина стенки в прямом направлении
                                               1 );                // Толщина стенки в обратном направлении
          // Изменить параметры выдавливания в одном направлении
          baseRotatedDefinition->SetSideParam( true,               // Направление вращения ( TRUE - прямое, FALSE - обратное )
                                               180 );              // Угол вращения
          // Изменить параметры выдавливания в одном направлении
          baseRotatedDefinition->SetSideParam( false,              // Направление вращения ( TRUE - прямое, FALSE - обратное )
                                               180 );              // Угол вращения
          baseRotatedDefinition->SetSketch( entitySketch );        // Эскиз операции выдавливания                                                                 
          // Создать операцию              
          entityRotate->Create();    
          MessageT( _T("Базовая операция вращения") );                    
        }
      }
    }
  }  

  // Создадим новый эскиз
  IEntityPtr entitySketch2( part->NewEntity( o3d_sketch ), false /*AddRef*/ );
  if ( entitySketch2 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition2( IUnknownPtr( entitySketch2->GetDefinition(), false /*AddRef*/ ) );
    if ( sketchDefinition2 )
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );
 
      // Установка параметров эскиза
      sketchDefinition2->SetPlane( basePlane );    // Установим плоскость XOY базовой для эскиза
 
      // Создадим эскиз
      entitySketch2->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition2->BeginEdit() )
      {
        // Введем новый эскиз
        ArcByAngle( 15, 0, 10, -90, 90, 1, 1 );
        LineSeg( 15, -10, 15, 10, 3 );
        // Выйти из режима редактирования эскиза
        sketchDefinition2->EndEdit();
      }
        
      // Операция приклеивания вращением
      IEntityPtr entityBossRotate( part->NewEntity( o3d_bossRotated ), false /*AddRef*/ );
      if ( entityBossRotate ) 
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс базовой операции вращения
        IBossRotatedDefinitionPtr bossRotatedDefinition( IUnknownPtr( entityBossRotate->GetDefinition(), false/*AddRef*/ ) ); 
        if ( bossRotatedDefinition ) 
        {
          bossRotatedDefinition->SetToroidShapeType( false );       // Признак тороида ( TRUE - тороид, FALSE - сфероид )
          bossRotatedDefinition->SetDirectionType( dtNormal );      // Направление вращения ( dtNormal - прямое направление, для тонкой стенки - наружу 
                                                                    // dtReverse - обратное направление, для тонкой стенки - внутрь, dtBoth - в обе стороны,
                                                                    // dtMiddlePlane - от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          bossRotatedDefinition->SetSideParam( true,                // Направление вращения ( TRUE - прямое, FALSE - обратное )
                                               360 );               // Угол вращения
          // Изменить параметры тонкой стенки
          bossRotatedDefinition->SetThinParam( true,                // Признак тонкостенной операции
                                               dtBoth,              // Направление построения тонкой стенки
                                               1,                   // Толщина стенки в прямом направлении
                                               1 );                 // Толщина стенки в обратном направлении
          bossRotatedDefinition->SetSketch( entitySketch2 );    // Эскиз операции выдавливания                                                                 
          // Операция приклеивания вращением            
          entityBossRotate->Create();  
          MessageT( _T("Операция приклеивания вращением") );                      
        }
      }
    }
  }

  // Создадим новый эскиз
  IEntityPtr entitySketch3( part->NewEntity( o3d_sketch ), false /*AddRef*/ );
  if ( entitySketch2 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition3( IUnknownPtr( entitySketch3->GetDefinition(), false /*AddRef*/ ) );
    if ( sketchDefinition3 )
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );
 
      // Установка параметров эскиза
      sketchDefinition3->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
 
      // Создадим эскиз
      entitySketch3->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition3->BeginEdit() )
      {
        // Введем новый эскиз
        ArcByAngle( 20, 0, 20, 90, 270, 1, 1 );
        LineSeg( 20, -20, 20, 20, 3 );
        // Выйти из режима редактирования эскиза
        sketchDefinition3->EndEdit();
      }
        
      // Операция вырезания вращением
      IEntityPtr entityCutRotate( part->NewEntity( o3d_cutRotated ), false /*AddRef*/ );
      if ( entityCutRotate ) 
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс базовой операции вращения
        ICutRotatedDefinitionPtr cutRotatedDefinition( IUnknownPtr( entityCutRotate->GetDefinition(), false /*AddRef*/ ) ); 
        if ( cutRotatedDefinition ) 
        {
          cutRotatedDefinition->SetToroidShapeType( false );           // Признак тороида ( TRUE - тороид, FALSE - сфероид )
          cutRotatedDefinition->SetDirectionType( dtNormal );          // Направление вращения ( dtNormal - прямое направление, для тонкой стенки - наружу
                                                                       // dtReverse - обратное направление, для тонкой стенки - внутрь, dtBoth - в обе стороны,
                                                                       // dtMiddlePlane - от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          cutRotatedDefinition->SetSideParam( true,                    // Направление вращения ( TRUE - прямое, FALSE - обратное )
                                              90 );                    // Угол вращения
          // Изменить параметры тонкой стенки
          cutRotatedDefinition->SetThinParam( true,                    // Признак тонкостенной операции
                                              dtBoth,                  // Направление построения тонкой стенки
                                              5,                       // Толщина стенки в прямом направлении
                                              7 );                     // Толщина стенки в обратном направлении
          cutRotatedDefinition->SetSketch( entitySketch3 );            // Эскиз операции выдавливания                                                                 
          // Операция вырезания вращением          
          entityCutRotate->Create();  
          MessageT( _T("Операция вырезания вращением") );                      
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Операции по сечениям
// ---
void OperationLoft( IPartPtr & part ) 
{
  // Создадим новый эскиз
  IEntityPtr entitySketch1(part->NewEntity(o3d_sketch), false /*AddRef*/);
  if (entitySketch1)
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition1(IUnknownPtr(entitySketch1->GetDefinition(), false /*AddRef*/));
    if (sketchDefinition1)
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );
          
      // Установка параметров эскиза
      sketchDefinition1->SetPlane(basePlane); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch1->Create();
      entitySketch1->SetHidden(false);

      // Войти в режим редактирования эскиза
      if (sketchDefinition1->BeginEdit())
      {
        // Введем новый эскиз - окружность
         Circle( 0, 0, 4.5, 1 );
        // Выйти из режима редактирования эскиза
        sketchDefinition1->EndEdit();
      }
    }
  }

  // Создадим смещенную плоскость ( для создания на ней эскиза )
  IEntityPtr entityPlaneOffset2( part->NewEntity( o3d_planeOffset ), false /*AddRef*/ );
  // Создадим новый эскиз
  IEntityPtr entitySketch2( part->NewEntity( o3d_sketch ), false /*AddRef*/ );  
  if ( (bool)entityPlaneOffset2 && (bool)entitySketch2 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств смещенной плоскости
    IPlaneOffsetDefinitionPtr planeOffsetDefinition2( IUnknownPtr( entityPlaneOffset2->GetDefinition(), false /*AddRef*/ ) );
    if ( planeOffsetDefinition2 ) 
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition2->SetOffset( 30 ); // Расстояние от базовой плоскости
        
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );

      planeOffsetDefinition2->SetPlane( basePlane );                     // Установим плоскость XOY базовой для плоскости
        
      entityPlaneOffset2->SetName( _bstr_t( _T("Смещенная плоскость 2") ) ); // Имя для смещенной плоскости
        
      entityPlaneOffset2->SetHidden( true );                // Скрыть смещенную плоскость
        
      // Создать смещенную плоскость
      entityPlaneOffset2->Create();             
        
      // Получить указатель на интерфейс параметров объектов и элементов
      // Интерфейс свойств эскиза
      ISketchDefinitionPtr sketchDefinition2( IUnknownPtr( entitySketch2->GetDefinition(), false/*AddRef*/ ) );
      if ( sketchDefinition2 )
      {
        // Установка параметров эскиза
        sketchDefinition2->SetPlane( entityPlaneOffset2 ); // Установим смещенную плоскость базовой для эскиза
 
        // Создадим эскиз
        entitySketch2->Create();

        // Войти в режим редактирования эскиза
        if ( sketchDefinition2->BeginEdit() )
        {
          // Введем новый эскиз - окружность
          Circle( 0, 0, 8, 1 );
          // Выйти из режима редактирования эскиза
          sketchDefinition2->EndEdit();
        }
      }
    }
  }
  
  // Создадим смещенную плоскость ( для создания на ней эскиза )
  IEntityPtr entityPlaneOffset3( part->NewEntity( o3d_planeOffset ), false /*AddRef*/ );
  // Создадим новый эскиз
  IEntityPtr entitySketch3( part->NewEntity( o3d_sketch ), false /*AddRef*/ );  
  if ( (bool)entityPlaneOffset3 && (bool)entitySketch3 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств смещенной плоскости
    IPlaneOffsetDefinitionPtr planeOffsetDefinition3( IUnknownPtr( entityPlaneOffset3->GetDefinition(), false /*AddRef*/ ) );
    if ( planeOffsetDefinition3 ) 
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition3->SetOffset( 60 ); // Расстояние от базовой плоскости
        
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );

      planeOffsetDefinition3->SetPlane( basePlane );         // Установим плоскость XOY базовой для плоскости
        
      // Получить строку
      entityPlaneOffset3->SetName( _bstr_t(_T("Смещенная плоскость 3")) );                 // Имя для смещенной плоскости
      // Освободить строку
        
      entityPlaneOffset3->SetHidden( true );               // Скрыть смещенную плоскость
        
      // Создать смещенную плоскость
      entityPlaneOffset3->Create();             
        
      // Получить указатель на интерфейс параметров объектов и элементов
      // Интерфейс свойств эскиза
      ISketchDefinitionPtr sketchDefinition3( IUnknownPtr( entitySketch3->GetDefinition(), false/*AddRef*/ ) );
      if ( sketchDefinition3 )
      {
        // Установка параметров эскиза
        sketchDefinition3->SetPlane( entityPlaneOffset3 ); // Установим смещенную плоскость базовой для эскиза

        // Создадим эскиз
        entitySketch3->Create();

        // Войти в режим редактирования эскиза
        if ( sketchDefinition3->BeginEdit() )
        {
          // Введем новый эскиз - окружность
          Circle( 0, 0, 1.5, 1 );
          // Выйти из режима редактирования эскиза
          sketchDefinition3->EndEdit();
        }
      }
    }
  }
 
  // Создадим базовую операцию по сечениям
  IEntityPtr entityBaseLoft( part->NewEntity( o3d_bossLoft ), false /*AddRef*/ );
  if ( entityBaseLoft ) 
  {
    IBossLoftDefinitionPtr baseLoftDefinition( IUnknownPtr( entityBaseLoft->GetDefinition(), false /*AddRef*/ ) );
    if ( baseLoftDefinition ) 
    {
      IEntityCollectionPtr entityCollection( baseLoftDefinition->Sketchs(), false /*AddRef*/ );
      if ( entityCollection ) 
      {
        entityCollection->Add(entitySketch1);
        entityCollection->Add( entitySketch2 );
        entityCollection->Add( entitySketch3 );
      }
        
      entityBaseLoft->SetName( _bstr_t(_T("Ручка")) ); // Имя для операции по сечениям
      // Изменить параметры цвета и визуальных свойств объекта
      entityBaseLoft->SetAdvancedColor( 12345678,  // Цвет
                                        0.8,       // Общий свет
                                        0.8,       // Диффузия
                                        0.8,       // Зеркальность
                                        0.8,       // Блеск
                                        1,         // Прозрачность
                                        0.8 );     // Излучение

      // Cоздать операцию по сечениям
      entityBaseLoft->Create(); 
      MessageT( _T("Базовая операция по сечениям") );                       
    }
  }
  
  // Создадим эскиз в уже созданной смещенной плоскости
  IEntityPtr entitySketch4( part->NewEntity( o3d_sketch ), false /*AddRef*/ );  
  if (  entitySketch4 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition4( IUnknownPtr( entitySketch4->GetDefinition(), false /*AddRef*/ ) );
    if ( sketchDefinition4 )
    {
      // Установка параметров эскиза
      sketchDefinition4->SetPlane( entityPlaneOffset3 ); // Установим смещенную плоскость базовой для эскиза
        
      // Создадим эскиз
      entitySketch4->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition4->BeginEdit() )
      {
        // Введем новый эскиз - окружность
        Circle( 0, 0, 1.5, 1 );
        // Выйти из режима редактирования эскиза
        sketchDefinition4->EndEdit();
      }
    }
  }
    
  // Создадим смещенную плоскость ( для создания на ней эскиза )
  IEntityPtr entityPlaneOffset5( part->NewEntity( o3d_planeOffset ), false /*AddRef*/ );
  // Создадим новый эскиз
  IEntityPtr entitySketch5( part->NewEntity( o3d_sketch ), false /*AddRef*/ );  
  if ( (bool)entityPlaneOffset5 && (bool)entitySketch5 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств смещенной плоскости
    IPlaneOffsetDefinitionPtr planeOffsetDefinition5( IUnknownPtr( entityPlaneOffset5->GetDefinition(), false /*AddRef*/ ) );
    if ( planeOffsetDefinition5 ) 
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition5->SetOffset( 120 ); // Расстояние от базовой плоскости
        
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );

      planeOffsetDefinition5->SetPlane( basePlane ); // Установим плоскость XOY базовой для плоскости
      
      entityPlaneOffset5->SetName( _bstr_t(_T("Смещенная плоскость 5")) );                 // Имя для смещенной плоскости
      
      entityPlaneOffset5->SetHidden( true );               // Скрыть смещенную плоскость
      
      // Создать смещенную плоскость
      entityPlaneOffset5->Create();             
        
      // Получить указатель на интерфейс параметров объектов и элементов
      // Интерфейс свойств эскиза
      ISketchDefinitionPtr sketchDefinition5( IUnknownPtr( entitySketch5->GetDefinition(), false /*AddRef*/ ) );
      if ( sketchDefinition5 )
      {
        // Установка параметров эскиза
        sketchDefinition5->SetPlane( entityPlaneOffset5 ); // Установим смещенную плоскость базовой для эскиза
 
        // Создадим эскиз
        entitySketch5->Create();

        // Войти в режим редактирования эскиза
        if ( sketchDefinition5->BeginEdit() )
        {
          // Введем новый эскиз - окружность
          Circle( 0, 0, 1.8, 1 );
          // Выйти из режима редактирования эскиза
          sketchDefinition5->EndEdit();
        }
      }
    }
  }  

  // Создадим операцию приклеивания по сечениям
  IEntityPtr entityBossLoft( part->NewEntity( o3d_bossLoft ), false /*AddRef*/ );
  if ( entityBossLoft ) 
  {
    IBossLoftDefinitionPtr bossLoftDefinition( IUnknownPtr( entityBossLoft->GetDefinition(), false /*AddRef*/ ) );
    if ( bossLoftDefinition ) 
    {
      IEntityCollectionPtr entityCollection( bossLoftDefinition->Sketchs(), false /*AddRef*/ );
      if ( entityCollection ) 
      {
        entityCollection->Add( entitySketch4 );
        entityCollection->Add( entitySketch5 );
      }
        
      entityBossLoft->SetName( _bstr_t(_T("Цивьё")) );  // Имя для операции по сечениям
      // Изменить параметры цвета и визуальных свойств объекта
      entityBossLoft->SetAdvancedColor( 1234567890, // Цвет
                                        0.8,        // Общий свет
                                        0.8,        // Диффузия
                                        0.8,        // Зеркальность
                                        0.8,        // Блеск
                                        1,          // Прозрачность
                                        0.8 );      // Излучение

      // Cоздать операцию приклеивания по сечениям
      entityBossLoft->Create(); 
      MessageT( _T("Операция приклеивания по сечениям") );                       
    }
  }

  // Создадим эскиз в уже созданной смещенной плоскости
  IEntityPtr entitySketch6( part->NewEntity(o3d_sketch), false/*AddRef*/ );  
  if (  entitySketch6 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition6( IUnknownPtr( entitySketch6->GetDefinition(), false/*AddRef*/ ) );
    if ( sketchDefinition6 )
    {
      // Установка параметров эскиза
      sketchDefinition6->SetPlane( entityPlaneOffset5 );       // Установим смещенную плоскость базовой для эскиза
        
      // Создадим эскиз
      entitySketch6->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition6->BeginEdit() )
      {
        // Введем новый эскиз - прямоугольник
        RectangleParam parRectangle; // Структура параметров прямоугольника
        memset( &parRectangle, 0, sizeof( parRectangle ) );          
        parRectangle.x       = -1.8;                         // Координаты базовой точки прямоугольника - одной из его вершин
        parRectangle.y = -0.4;
        parRectangle.height = 0.8;                           // Высота прямоугольника
        parRectangle.width   = 3.6;                          // Ширина прямоугольника
        parRectangle.style   = 1;                            // Стиль линии
        parRectangle.pCorner = CreateArray( CORNER_ARR, 0 ); // Динамический массив структур параметров скругленных (или усеченных) углов
        ksRectangle( &parRectangle, 0 ); // Создать прямоугольник
        // Выйти из режима редактирования эскиза
        sketchDefinition6->EndEdit();
      }
    }
  }

  // Создадим смещенную плоскость ( для создания на ней эскиза )
  IEntityPtr entityPlaneOffset7( part->NewEntity( o3d_planeOffset ), false /*AddRef*/ );
  // Создадим новый эскиз
  IEntityPtr entitySketch7( part->NewEntity( o3d_sketch ), false /*AddRef*/ );  
  if ( (bool)entityPlaneOffset7 && (bool)entitySketch7 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств смещенной плоскости
    IPlaneOffsetDefinitionPtr planeOffsetDefinition7( IUnknownPtr(entityPlaneOffset7->GetDefinition(), false /*AddRef*/ ) );
    
    if ( planeOffsetDefinition7 ) 
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition7->SetOffset( 110 ); // Расстояние от базовой плоскости
        
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );

      planeOffsetDefinition7->SetPlane( basePlane );                   // Установим плоскость XOY базовой для плоскости
        
      entityPlaneOffset7->SetName( _bstr_t(_T("Смещенная плоскость 7")) ); // Имя для смещенной плоскости
      
      entityPlaneOffset7->SetHidden( true );                           // Скрыть смещенную плоскость
        
      // Создать смещенную плоскость
      entityPlaneOffset7->Create();             
        
      // Получить указатель на интерфейс параметров объектов и элементов
      // Интерфейс свойств эскиза
      ISketchDefinitionPtr sketchDefinition7( IUnknownPtr(entitySketch7->GetDefinition(), false/*AddRef*/ ) );
      if ( sketchDefinition7 )
      {
        // Установка параметров эскиза
        sketchDefinition7->SetPlane( entityPlaneOffset7 );     // Установим смещенную плоскость базовой для эскиза
 
        // Создадим эскиз
        entitySketch7->Create();

        // Войти в режим редактирования эскиза
        if ( sketchDefinition7->BeginEdit() )
        {
          // Введем новый эскиз - прямоугольник
          RectangleParam parRectangle; // Структура параметров прямоугольника
          memset( &parRectangle, 0, sizeof( parRectangle ) );          
          parRectangle.x       = -1.8;                         // Координаты базовой точки прямоугольника - одной из его вершин
          parRectangle.y       = -1.8;
          parRectangle.height  = 3.6;                          // Высота прямоугольника
          parRectangle.width   = 3.6;                          // Ширина прямоугольника
          parRectangle.style   = 1;                            // Стиль линии
          parRectangle.pCorner = CreateArray( CORNER_ARR, 0 ); // Динамический массив структур параметров скругленных (или усеченных) углов
          ksRectangle( &parRectangle, 0 ); // Создать прямоугольник
          // Выйти из режима редактирования эскиза
          sketchDefinition7->EndEdit();
        }
      }
    }
  } 

  // Создадим операцию вырезания по сечениям
  IEntityPtr entityCutLoft( part->NewEntity( o3d_cutLoft ), false /*AddRef*/ );
  if ( entityCutLoft ) 
  {
    ICutLoftDefinitionPtr cutLoftDefinition( IUnknownPtr( entityCutLoft->GetDefinition(), false /*AddRef*/ ) );
    if ( cutLoftDefinition ) 
    {
      IEntityCollectionPtr entityCollection( cutLoftDefinition->Sketchs(), false /*AddRef*/ );
      if ( entityCollection ) 
      {
        entityCollection->Add( entitySketch6 );
        entityCollection->Add( entitySketch7 );
      }
        
      // Изменить параметры тонкой стенки
      cutLoftDefinition->SetThinParam( true,     // Признак тонкостенной операции
                                       dtNormal, // Направление построения тонкой стенки
                                       3,        // Толщина стенки в прямом направлении
                                       0 );      // Толщина стенки в обратном направлении
      entityCutLoft->SetName( _bstr_t(_T("Рабочая поверхность")) ); // Имя для операции по сечениям

      // Изменить параметры цвета и визуальных свойств объекта
      entityCutLoft->SetAdvancedColor( 1234,  // Цвет
                                       0.8,   // Общий свет
                                       0.8,   // Диффузия
                                       0.8,   // Зеркальность
                                       0.8,   // Блеск
                                       1,     // Прозрачность
                                       0.8 ); // Излучение

      // Cоздать операцию вырезания по сечениям
      entityCutLoft->Create(); 
      MessageT( _T("Операция вырезания по сечениям") );                       
    }
  }  
}


//-------------------------------------------------------------------------------
// Операции по сечениям
// ---
void LoftSurface( IPartPtr & part ) 
{
  // Создадим новый эскиз
  IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false /*AddRef*/ );  
  if (  entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition( IUnknownPtr( entitySketch->GetDefinition(), false /*AddRef*/ ) );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );
          
      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch->Create();
      entitySketch->SetHidden(false);

      // Войти в режим редактирования эскиза
      if ( sketchDefinition->BeginEdit() )
      {
        // Введем новый эскиз - окружность
         Circle( 0, 0, 4.5, 1 );
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }
    }
  }

  // Создадим смещенную плоскость ( для создания на ней эскиза )
  IEntityPtr entityPlaneOffset2( part->NewEntity( o3d_planeOffset ), false /*AddRef*/ );
  // Создадим новый эскиз
  IEntityPtr entitySketch2( part->NewEntity( o3d_sketch ), false /*AddRef*/ );  
  if ( (bool)entityPlaneOffset2 && (bool)entitySketch2 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств смещенной плоскости
    IPlaneOffsetDefinitionPtr planeOffsetDefinition2( IUnknownPtr( entityPlaneOffset2->GetDefinition(), false /*AddRef*/ ) );
    if ( planeOffsetDefinition2 ) 
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition2->SetOffset( 30 ); // Расстояние от базовой плоскости
        
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );

      planeOffsetDefinition2->SetPlane( basePlane );                     // Установим плоскость XOY базовой для плоскости
        
      entityPlaneOffset2->SetName( _bstr_t( _T("Смещенная плоскость 2") ) ); // Имя для смещенной плоскости
        
      entityPlaneOffset2->SetHidden( true );                // Скрыть смещенную плоскость
        
      // Создать смещенную плоскость
      entityPlaneOffset2->Create();             
        
      // Получить указатель на интерфейс параметров объектов и элементов
      // Интерфейс свойств эскиза
      ISketchDefinitionPtr sketchDefinition2( IUnknownPtr( entitySketch2->GetDefinition(), false/*AddRef*/ ) );
      if ( sketchDefinition2 )
      {
        // Установка параметров эскиза
        sketchDefinition2->SetPlane( entityPlaneOffset2 ); // Установим смещенную плоскость базовой для эскиза
 
        // Создадим эскиз
        entitySketch2->Create();

        // Войти в режим редактирования эскиза
        if ( sketchDefinition2->BeginEdit() )
        {
          // Введем новый эскиз - окружность
          Circle( 0, 0, 8, 1 );
          // Выйти из режима редактирования эскиза
          sketchDefinition2->EndEdit();
        }
      }
    }
  }
  
  // Создадим смещенную плоскость ( для создания на ней эскиза )
  IEntityPtr entityPlaneOffset3( part->NewEntity( o3d_planeOffset ), false /*AddRef*/ );
  // Создадим новый эскиз
  IEntityPtr entitySketch3( part->NewEntity( o3d_sketch ), false /*AddRef*/ );  
  if ( (bool)entityPlaneOffset3 && (bool)entitySketch3 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств смещенной плоскости
    IPlaneOffsetDefinitionPtr planeOffsetDefinition3( IUnknownPtr( entityPlaneOffset3->GetDefinition(), false /*AddRef*/ ) );
    if ( planeOffsetDefinition3 ) 
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition3->SetOffset( 60 ); // Расстояние от базовой плоскости
        
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );

      planeOffsetDefinition3->SetPlane( basePlane );         // Установим плоскость XOY базовой для плоскости
        
      // Получить строку
      entityPlaneOffset3->SetName( _bstr_t(_T("Смещенная плоскость 3")) );                 // Имя для смещенной плоскости
      // Освободить строку
        
      entityPlaneOffset3->SetHidden( true );               // Скрыть смещенную плоскость
        
      // Создать смещенную плоскость
      entityPlaneOffset3->Create();             
        
      // Получить указатель на интерфейс параметров объектов и элементов
      // Интерфейс свойств эскиза
      ISketchDefinitionPtr sketchDefinition3( IUnknownPtr( entitySketch3->GetDefinition(), false/*AddRef*/ ) );
      if ( sketchDefinition3 )
      {
        // Установка параметров эскиза
        sketchDefinition3->SetPlane( entityPlaneOffset3 ); // Установим смещенную плоскость базовой для эскиза

        // Создадим эскиз
        entitySketch3->Create();

        // Войти в режим редактирования эскиза
        if ( sketchDefinition3->BeginEdit() )
        {
          // Введем новый эскиз - окружность
          Circle( 0, 0, 1.5, 1 );
          // Выйти из режима редактирования эскиза
          sketchDefinition3->EndEdit();
        }
      }
    }
  }
 
  // Создадим базовую операцию по сечениям
  IEntityPtr entityBaseLoft( part->NewEntity( o3d_LoftSurface ), false /*AddRef*/ );
  if ( entityBaseLoft ) 
  {
    ILoftSurfaceDefinitionPtr baseLoftDefinition( IUnknownPtr( entityBaseLoft->GetDefinition(), false /*AddRef*/ ) );
    if ( baseLoftDefinition ) 
    {
      IEntityCollectionPtr entityCollection( baseLoftDefinition->Sketchs(), false /*AddRef*/ );
      if ( entityCollection ) 
      {
        entityCollection->Add( entitySketch );
        entityCollection->Add( entitySketch2 );
        entityCollection->Add( entitySketch3 );
      }
        
      entityBaseLoft->SetName( _bstr_t(_T("Ручка")) ); // Имя для операции по сечениям
      // Изменить параметры цвета и визуальных свойств объекта
      entityBaseLoft->SetAdvancedColor( 12345678,  // Цвет
                                        0.8,       // Общий свет
                                        0.8,       // Диффузия
                                        0.8,       // Зеркальность
                                        0.8,       // Блеск
                                        1,         // Прозрачность
                                        0.8 );     // Излучение

      // Cоздать операцию по сечениям
      entityBaseLoft->Create(); 
      MessageT( _T("Поверхность по сечениям") );                       
    }
  }
}

//-----------------------------------------------------------------------------------
// Операции : оболочка, уклон, сечение плоскостью, сечение эскизом
//---
void CreateNextOper( IPartPtr& part )
{
  // создадим эскиз для базовой операции
  IEntityPtr entitySketch( part->NewEntity(o3d_sketch), false /*AddRef*/ );
	if ( entitySketch ) {
		// получим интерфейс свойств эскиза
		ISketchDefinitionPtr sketchDef( IUnknownPtr( entitySketch->GetDefinition(), false /*AddRef*/ ) );
		if ( sketchDef ) {
			// получим интерфейс базовой плоскости XOY
			IEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY), false /*AddRef*/ );
			sketchDef->SetPlane( basePlane );    // установим плоскость XOY базовой для эскиза
  		sketchDef->SetAngle( 0 );            // угол поворота эскиза
			entitySketch->Create();              // создадим эскиз

			// интерфейс редактора эскиза
			sketchDef->BeginEdit(); 
				// введем новый эскиз - квадрат
        LineSeg(  50,  50, -50,  50, 1 );
		  	LineSeg(  50, -50, -50, -50, 1 ); 
				LineSeg(  50, -50,  50,  50, 1 );
				LineSeg( -50, -50, -50,  50, 1 );
			sketchDef->EndEdit();                   // завершение редактирования эскиза                

			MessageT( _T("Создаем операцию выдавливания") );
			
      // Создаем операцию выдавливания
			IEntityPtr entityExtr( part->NewEntity(o3d_bossExtrusion), false/*AddRef*/ );
			if ( entityExtr ) {
				// интерфейс свойств базовой операции выдавливания
                IBossExtrusionDefinitionPtr extrusionDef( IUnknownPtr( entityExtr->GetDefinition(), false/*AddRef*/ ) ); 
				if ( extrusionDef ) {
					extrusionDef->SetDirectionType( dtNormal );         // направление выдавливания
					extrusionDef->SetSideParam( true/*прямое направление*/, etBlind/*строго на глубину*/, 200, 0, false ); 
					extrusionDef->SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
					extrusionDef->SetSketch( entitySketch );            // эскиз операции выдавливания
					entityExtr->Create();                               // создать операцию
				}

        bool update = false;                                 // если update = true, то параметры операции изменены 
        if ( YesNoT( _T("Создать операцию оболочка?") ) == 1 ) {
          // Создаем операцию оболочка
					IEntityPtr entShell( part->NewEntity(o3d_shellOperation), false/*AddRef*/ );
					if ( entShell ) {
						// интерфейс свойств базовой операции выдавливания
            IShellDefinitionPtr incDef( IUnknownPtr( entShell->GetDefinition(), false/*AddRef*/ ) );
						if ( incDef ) {
              IEntityCollectionPtr entCol( incDef->FaceArray(), false /*AddRef*/ );               // заведем массив граней для операции оболочка
              IEntityCollectionPtr collect( part->EntityCollection(o3d_face), false /*AddRef*/ ); // массив всех граней
              if ( (bool)entCol && (bool)collect ) {
                incDef->SetThickness( 8 );                      // толщиина оболочки
                incDef->SetThinType( true );                    // направление оболочки внутрь
                collect->SelectByPoint( 50, 0, 0 );             // выделим точку на детале для заполнения массива всех граней, рпоходяших через эту точку
                IEntityPtr ePtr( collect->GetByIndex(0), false /*AddRef*/ );
                entCol->Add( ePtr );           // добавим в массив граней для операции грань с индексом = 0 
                collect->Refresh();                             // очистим массив
                entShell->Create();                    				 // создать операцию

                if ( YesNoT( _T("Изменить параметры операции оболочка?") ) == 1 ) {
                  incDef->SetThickness( 25 );                   // толщиина оболочки
                  incDef->SetThinType( false );                 // направление оболочки наружу
                  collect->SelectByPoint( 60, 0, 10 );          // выделим точку на детале для заполнения массива всех граней, рпоходяших через эту точку
                  IEntityPtr ePtr1( collect->GetByIndex(0), false /*AddRef*/ );
                  entCol->Add( ePtr1 );        // добавим в массив граней для операции грань с индексом = 0 
                  collect->Refresh();                           // очистим массив
                  entShell->Update();                           // перестроим операцию
                  update = true;
                }
              }
            }
          }

          if ( YesNoT( _T("Создать операцию уклон?") ) == 1 ) {
            // создадим операцию уклон
            IEntityPtr entInc( part->NewEntity(o3d_incline), false /*AddRef*/ );
      			if ( entInc ) {
							// интерфейс свойств базовой операции уклона
							IInclineDefinitionPtr incDef( IUnknownPtr( entInc->GetDefinition(), false /*AddRef*/ ) );
              IEntityCollectionPtr  collect( part->EntityCollection(o3d_face), false /*AddRef*/ ); // массив всех граней
							if ( (bool)incDef && (bool)collect ) {
							  incDef->SetDirection( true );                          // Направление уклона - наружу  
                incDef->SetAngle( 3 );                                 // Угол уклона  
								incDef->SetPlane( basePlane );                         // базовая плоскость  
                IEntityCollectionPtr entColInc( incDef->FaceArray(), false /*AddRef*/ ); // заведем массив граней для операции уклон
                if ( entColInc ) {
                  collect->SelectByPoint( 0, update ? 85 : 60, 10 );  // выделим точку на детале для заполнения массива всех граней, проходяших через эту точку
                  IEntityPtr ePtr( collect->GetByIndex(0), false/*AddRef*/ );
                  entColInc->Add( ePtr );                             // добавим в массив граней для операции грань с индексом = 0 
                  collect->Refresh();                                 // очистим массив
                  entInc->Create();                    				        // создать операцию

                   if ( YesNoT( _T("Изменить параметры операции уклон?") ) == 1 ) {
    								incDef->SetDirection( false );                        // Направление уклона - внутрь
		    						incDef->SetAngle( 25 );                               // Угол уклона  
                    collect->SelectByPoint( 0, update ? -85 : -60, 10 );  // выделим точку на детале для заполнения массива всех граней, проходяших через эту точку
                    IEntityPtr ePtr1( collect->GetByIndex(0), false/*AddRef*/ );
                    entColInc->Add( ePtr1 );                              // добавим в массив граней для операции грань с индексом = 0 
                    collect->Refresh();                                   // очистим массив
                    entInc->Update();
                  }
                }
              }
            }
          }

          if ( YesNoT( _T("Создать операцию сечение плоскостью?") ) == 1 ) {
            // создадим операцию сечение плоскостью
            IEntityPtr entityOpr( part->NewEntity(o3d_cutByPlane), false /*AddRef*/ );
            if ( entityOpr ) {
              // интерфейс свойств операции сечение плоскостью
              ICutByPlaneDefinitionPtr incOpr( IUnknownPtr( entityOpr->GetDefinition(), false/*AddRef*/ ) ); // интерфейс операции
              if ( incOpr ) {
       		      // получим интерфейс базовой плоскости XOZ, которая будет являться плоскостью сечения
  	    			  IEntityPtr basePlaneXOZ( part->GetDefaultEntity(o3d_planeXOZ), false/*AddRef*/ );
                incOpr->SetPlane( basePlaneXOZ );               // задаем плоскость сечения
                incOpr->SetDirection( false );                  // направление сечения - обратное
                entityOpr->Create();                    				// создать операцию

                if ( YesNoT( _T("Изменить параметры операции сечение плоскостью?") ) == 1 ) {
                  incOpr->SetDirection( true );                 // направление сечения - прямое
                  entityOpr->Update();                  				// перестроить операцию
                }
              }
            }
          }

          if ( YesNoT( _T("Создать операцию сечение эскизом?") ) == 1 ) {
            // создадим эскиз для операции сечение эскизом
            IEntityPtr entitySketch2( part->NewEntity(o3d_sketch), false /*AddRef*/ );  
            if ( entitySketch2 ) {
              // интерфейс свойств эскиза
              ISketchDefinitionPtr sketchDef2( IUnknownPtr( entitySketch2->GetDefinition(), false /*AddRef*/ ) );
              if ( sketchDef2 ) {
       		      // получим интерфейс базовой плоскости YOZ
  	    			  IEntityPtr basePlaneYOZ( part->GetDefaultEntity(o3d_planeYOZ), false /*AddRef*/ );
                sketchDef2->SetPlane( basePlaneYOZ ); // установим плоскость yoz базовой для эскиза
                sketchDef2->SetAngle( 45 );     			// угол поворота эскиза
                entitySketch2->Create();    	  			// создадим эскиз

                // интерфейс редактора эскиза
      		      sketchDef2->BeginEdit(); 
                  // введем новый эскиз
                  ArcBy3Points( -200, 45, -150, 10, -50, 10, 1 );
                  LineSeg     ( -200, 45, -300, 20, 1 );
                  LineSeg     (  -50, 10,   60, 10, 1 );
                sketchDef2->EndEdit();                   // завершение редактирования эскиза
              
                // создадаим Операцию сечение эскизом
                IEntityPtr entityOpr( part->NewEntity(o3d_cutBySketch), false /*AddRef*/ );
                if ( entityOpr ) {
                  // интерфейс операции сечение эскизом
                  ICutBySketchDefinitionPtr incOpr( IUnknownPtr( entityOpr->GetDefinition(), false /*AddRef*/ ) ); 
                  if ( incOpr ) {
                    incOpr->SetSketch( entitySketch2 );             // задаем эскиз
                    incOpr->SetDirection( true );                   // задаем направление сечения
                    entityOpr->Create();                    				// создать операцию
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}