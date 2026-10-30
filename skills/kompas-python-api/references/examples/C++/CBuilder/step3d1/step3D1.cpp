////////////////////////////////////////////////////////////////////////////////
//
// step3D1.cpp - Операции
//
// 1. Базовая операция выдавливания - CreateExtrusion
// 2. Операции вращения             - OperationRotated
// 3. Операции по сечениям          - OperationLoft
// 4. Создание фаски и скругления   - CreateFilletAndChamfer
//
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>

#include <stdio.h>
#include <math.h>

#include <objbase.h>
#include <initguid.h>

#include "step3D1.rh"
#include "step3D1.h"
#include "ksConstants.h"

#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

HINSTANCE _hinst;

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib и kAPI3D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a и kAPI3D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")
#pragma comment(lib, "kAPI3D5bc")

//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
LPTSTR _LoadStr( int id )
{ 
	static TCHAR buf[512];
	// Конвертировать строку в соответствии с текущим словарем
	ksConvertLangStrExT( _hinst, id, buf, 512 );
  return buf;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
extern "C" unsigned int far __export __stdcall LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void CreateExtrusion( Kompas6api3d5com_tlb::IPartPtr & part );
void OperationRotated( Kompas6api3d5com_tlb::IPartPtr & part );
void OperationLoft( Kompas6api3d5com_tlb::IPartPtr & part );
void CreateFilletAndChamfer( Kompas6api3d5com_tlb::IPartPtr & part );


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
extern "C" void far __export __stdcall LIBRARYENTRY( unsigned int comm )
{
  Kompas6api3d5com_tlb::IDocument3DPtr pDocument3d( Kompas6api3d5com_tlb::ksGetActive3dDocument(), false/*AddRef*/ ); // Получить указатель на активный документ трехмерной модели
  if ( pDocument3d )
  {
    // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
    // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента
    Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( pTop_Part ), false/*AddRef*/ );
    if ( part )
    {
      switch ( comm )
      {
        case 1 : CreateExtrusion( part );        break; // Базовая операция выдавливания
        case 2 : OperationRotated( part );       break; // Операции вращения
        case 3 : OperationLoft( part );          break; // Операции по сечениям
        case 4 : CreateFilletAndChamfer( part ); break; // Создание фаски и скругления
      }
    }
  }
  else
		ErrorT( _LoadStr( STR_3DDOCERROR ) ); // Документ не активизирован или не является 3D-моделью

  if ( ReturnResult() == etError10 )     // Ошибка! Вырожденный объект
    ResultNULL();                        // Обнулить ошибки
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
void CreateExtrusion( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false/*AddRef*/ );
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );

    // Интерфейс свойств эскиза
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane );        // Установим плоскость XOY базовой для эскиза
      sketchDefinition->SetAngle( 45 );               // Угол поворота эскиза

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
      Kompas6api3d5com_tlb::IEntityPtr entityExtrusion( part->NewEntity( o3d_bossExtrusion ), false/*AddRef*/ );
      if ( entityExtrusion )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pExtrusionDefinition( entityExtrusion->GetDefinition(), false/*AddRef*/ );
        // Интерфейс базовой операции выдавливания
        Kompas6api3d5com_tlb::IBossExtrusionDefinitionPtr extrusionDefinition( pExtrusionDefinition );

        if ( extrusionDefinition )
        {
          // Установка параметров операции выдавливания
          extrusionDefinition->SetDirectionType( dtNormal );      // Направление выдавливания ( dtNormal	- прямое
                                                                  // направление, для тонкой стенки - наружу,
                                                                  // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                  // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          extrusionDefinition->SetSideParam( true,                // Направление выдавливания ( TRUE - прямое направление,
                                                                  // FALSE - обратное направление )
                                             etBlind,             // Тип выдавливания ( etBlind - строго на глубину,
                                                                  // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                                  // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                                  // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                  // etUpToNearSurface	- до ближайшей поверхности )
                                             200,                 // Глубина выдавливания
                                             0,                   // Угол уклона
                                             false );             // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
          // Изменить параметры тонкой стенки
          extrusionDefinition->SetThinParam( true,              // Признак тонкостенной операции
                                             dtBoth,            // Направление построения тонкой стенки
                                             10,                // Толщина стенки в прямом направлении
                                             10 );              // Толщина стенки в обратном направлении
          extrusionDefinition->SetSketch( entitySketch );       // Эскиз операции выдавливания

          // Создать операцию выдавливания
          entityExtrusion->Create();
					MessageT( _T("Операция выдавливания") );

          // Изменим параметры операции выдавливания
          extrusionDefinition->SetDirectionType( dtBoth );     // Направление выдавливания ( dtNormal	- прямое
                                                               // направление, для тонкой стенки - наружу,
                                                               // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                               // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          extrusionDefinition->SetSideParam( false,            // Направление выдавливания ( TRUE - прямое направление,
                                                               // FALSE - обратное направление )
                                             etBlind,          // Тип выдавливания ( etBlind - строго на глубину,
                                                               // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                               // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                               // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                               // etUpToNearSurface	- до ближайшей поверхности )
                                             150,              // Глубина выдавливания
																						 0,                // Угол уклона
                                             false );          // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )

          // Обновить параметры
          entityExtrusion->_Update();
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
          entitySketch->_Update();
          // Обновить параметры операции выдавливания
          entityExtrusion->_Update();
					MessageT( _T("Поменяли эскиз") );

          // Создадим новый эскиз
          Kompas6api3d5com_tlb::IEntityPtr entitySketch2( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
          if ( entitySketch2 )
          {
            // Получить указатель на интерфейс параметров объектов и элементов
            IUnknownPtr pDefinitionSketch2( entitySketch2->GetDefinition(), false/*AddRef*/ );
            Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition2( pDefinitionSketch2 );
            if ( sketchDefinition2 )
            {
              // Установка параметров эскиза
              sketchDefinition2->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
              sketchDefinition2->SetAngle( 45 );               // Повернем эскиз на 45 град.

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
              Kompas6api3d5com_tlb::IEntityPtr entityBossExtrusion( part->NewEntity( o3d_bossExtrusion ), false/*AddRef*/ );
              if ( entityBossExtrusion )
              {
                // Получить указатель на интерфейс параметров объектов и элементов
                IUnknownPtr pDefinitionBossExtrusion( entityBossExtrusion->GetDefinition(), false );
                Kompas6api3d5com_tlb::IBossExtrusionDefinitionPtr bossExtrusionDefinition( pDefinitionBossExtrusion );
                if ( pDefinitionBossExtrusion )
                {
                  // Интерфейс параметров приклеенного элемента выдавливания
                  if ( bossExtrusionDefinition )
                  {
                    Kompas6api3d5com_tlb::IExtrusionParamPtr extrusionParam( bossExtrusionDefinition->ExtrusionParam(), false/*AddRef*/ ); // Интерфейс структуры параметров выдавливания
                    Kompas6api3d5com_tlb::IThinParamPtr      thinParam     ( bossExtrusionDefinition->ThinParam(), false/*AddRef*/ );      // Интерфейс структуры параметров тонкой стенки
                    if ( (bool)extrusionParam && (bool)thinParam )
                    {
                      // Установка параметров элемента выдавливания
                      bossExtrusionDefinition->SetSketch( entitySketch2 ); // Эскиз операции выдавливания

                      extrusionParam->SetDirection( dtNormal );       // Направление выдавливания ( dtNormal	- прямое
                                                                      // направление, для тонкой стенки - наружу,
                                                                      // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                      // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
                      extrusionParam->SetTypeNormal( etBlind );       // Тип выдавливания ( etBlind - строго на глубину,
                                                                      // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                                      // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на расстояние
                                                                      // до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                      // etUpToNearSurface - до ближайшей поверхности )
                      extrusionParam->SetDepthNormal( 100 );          // Глубина выдавливания
                      thinParam->SetThin( false );                    // Признак формирования тонкой стенки элемента ( TRUE	- тонкая стенка,
                                                                      // формируется, FALSE - тонкая стенка не формируется )
                      entityBossExtrusion->Create();                  // Приклеим выдавливанием
											MessageT( _T("Приклеим выдавливанием") );
                    }
                  }
                }
              }

              // Создадим новый эскиз
              Kompas6api3d5com_tlb::IEntityPtr entitySketch3( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
              if ( entitySketch3 )
              {
                // Получить указатель на интерфейс параметров объектов и элементов
                IUnknownPtr pDefinitionSketch3( entitySketch3->GetDefinition(), false/*AddRef*/ );
                // Интерфейс свойств эскиза
                Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition3( pDefinitionSketch3 );
                if ( sketchDefinition3 )
                {
                  // Установка параметров эскиза
                  sketchDefinition3->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
                  sketchDefinition3->SetAngle( 45 );               // Повернем эскиз на 45 град.

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
                  Kompas6api3d5com_tlb::IEntityPtr entityCutExtrusion( part->NewEntity( o3d_cutExtrusion ), false/*AddRef*/ );
                  if ( entityCutExtrusion )
                  {
                    // Получить указатель на интерфейс параметров объектов и элементов
                    IUnknownPtr pDefinitionCutExtrusion( entityCutExtrusion->GetDefinition(), false/*AddRef*/ );     // интерфейс
                    // Интерфейс параметров вырезанного элемента выдавливания
                    Kompas6api3d5com_tlb::ICutExtrusionDefinitionPtr cutExtrusionDefinition( pDefinitionCutExtrusion );
                    if ( cutExtrusionDefinition )
                    {
                      // Установка параметров операции выдавливания
                      cutExtrusionDefinition->SetDirectionType( dtReverse );     // Направление выдавливания ( dtNormal	- прямое
                                                                                 // направление, для тонкой стенки - наружу,
                                                                                 // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                                 // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
                      // Изменить параметры выдавливания в одном направлении
                      cutExtrusionDefinition->SetSideParam( false,               // Направление выдавливания ( TRUE - прямое направление,
                                                                                 // FALSE - обратное направление )
                                                            etBlind,             // Тип выдавливания ( etBlind - строго на глубину,
                                                                                 // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                                                 // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                                                 // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                                 // etUpToNearSurface	- до ближайшей поверхности )
                                                            50,                  // Глубина выдавливания
                                                            0,                   // Угол уклона
                                                            false );             // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
                      // Изменить параметры тонкой стенки
                      cutExtrusionDefinition->SetThinParam( false,               // Признак тонкостенной операции
                                                            0,                   // Направление построения тонкой стенки
                                                            0,                   // Толщина стенки в прямом направлении
                                                            0 );                 // Толщина стенки в обратном направлении
                      cutExtrusionDefinition->SetSketch( entitySketch3 );        // Эскиз операции выдавливания

                      // Вырежим выдавливанием
                      entityCutExtrusion->Create();
											MessageT( _T("Вырежим выдавливанием") );
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
void CreateFilletAndChamfer( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane );        // Установим плоскость XOY базовой для эскиза
      sketchDefinition->SetAngle( 45 );               // Угол поворота эскиза

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
      Kompas6api3d5com_tlb::IEntityPtr entityExtrusion( part->NewEntity( o3d_bossExtrusion ), false/*AddRef*/ );
      if ( entityExtrusion )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionExtrusion( entityExtrusion->GetDefinition(), false/*AddRef*/ );
        // Интерфейс базовой операции выдавливания
        Kompas6api3d5com_tlb::IBossExtrusionDefinitionPtr extrusionDefinition( pDefinitionExtrusion );
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
          extrusionDefinition->SetSketch( entitySketch ); // Эскиз операции выдавливания

          // Создать операцию выдавливания
          entityExtrusion->Create();

          // Формирует массив объектов и возвращает указатель на его интерфейс - массив граней компонента
          Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( part->EntityCollection( o3d_face ), false );
          if ( (bool)entityCollection &&
               entityCollection->SelectByPoint( 0, 0, 0 ) && // Выбор по точке
               entityCollection->GetCount() )                // Получить количество элементов в массиве
          {
            // Скругление
            Kompas6api3d5com_tlb::IEntityPtr entityFillet( part->NewEntity( o3d_fillet ), false/*AddRef*/ );
            if ( entityFillet )
            {
              // Получить указатель на интерфейс параметров объектов и элементов
              IUnknownPtr pDefinitionFillet( entityFillet->GetDefinition(), false/*AddRef*/ );
              Kompas6api3d5com_tlb::IFilletDefinitionPtr filletDefinition( pDefinitionFillet );
              if ( filletDefinition )
              {
                // Установка параметров скругления
                filletDefinition->SetRadius( 10 );      // Радиус скругления
                filletDefinition->SetTangent( false );  // Продолжить по касательной
                Kompas6api3d5com_tlb::IEntityCollectionPtr arrayFilletDefinition( filletDefinition->Array(), false/*AddRef*/ ); // Динамический массив объектов
                if ( arrayFilletDefinition )
                {
                  // Получение граней для скругления
                  for ( int i = 0, count = entityCollection->GetCount(); i < count; i++ )
                     arrayFilletDefinition->Add( Kompas6api3d5com_tlb::IEntityPtr( entityCollection->GetByIndex( i ), false/*AddRef*/) );

                  // Создать операцию скругления
                  entityFillet->Create();
									MessageT( _T("Скругление") );
                }
              }
            }
          }
        }

        // Формирует массив объектов и возвращает указатель на его интерфейс - массив граней компонента
        Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection2( part->EntityCollection( o3d_face ), false/*AddRef*/ );
        if ( (bool)entityCollection2 &&
             entityCollection2->SelectByPoint( 0, 0, 100 ) && // Выбор по точке
             entityCollection2->GetCount() )                  // Получить количество элементов в массиве
        {
          // Фаска
          Kompas6api3d5com_tlb::IEntityPtr entityChamfer( part->NewEntity( o3d_chamfer ), false/*AddRef*/ );
          if ( entityChamfer )
          {
            // Получить указатель на интерфейс параметров объектов и элементов
            IUnknownPtr pDefinitionChamfer( entityChamfer->GetDefinition(), false/*AddRef*/ );
            Kompas6api3d5com_tlb::IChamferDefinitionPtr chamferDefinition( pDefinitionChamfer );
            if ( chamferDefinition )
            {
              // Установка параметров фаски
              chamferDefinition->SetTangent( false );   // Продолжить по касательной
              chamferDefinition->SetChamferParam( true, // Признак направления фаски
                                                  10,   // Размер первого катета фаски
                                                  10 ); // Размер второго катета фаски
              Kompas6api3d5com_tlb::IEntityCollectionPtr arrayChamferDefinition( chamferDefinition->Array(), false/*AddRef*/ ); // Динамический массив объектов
              if ( arrayChamferDefinition )
              {
                // Получение граней для фаски
                for ( int i = 0, count = entityCollection2->GetCount(); i < count; i++ )
                  arrayChamferDefinition->Add( Kompas6api3d5com_tlb::IEntityPtr(entityCollection2->GetByIndex( i ), false/*AddRef*/) );

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


//-------------------------------------------------------------------------------
// Операции вращения
// ---
void OperationRotated( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

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
      Kompas6api3d5com_tlb::IEntityPtr entityRotate( part->NewEntity( o3d_bossRotated ), false/*AddRef*/ );
      if ( entityRotate )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionRotate( entityRotate->GetDefinition(), false/*AddRef*/ );
        // Интерфейс базовой операции вращения
        Kompas6api3d5com_tlb::IBossRotatedDefinitionPtr baseRotatedDefinition( pDefinitionRotate );
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
          baseRotatedDefinition->SetSketch( entitySketch ); // Эскиз операции выдавливания
          // Создать операцию
          entityRotate->Create();
					MessageT( _T("Базовая операция вращения") );
				}
      }
    }
  }

  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch2( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( entitySketch2 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch2( entitySketch2->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition2( pDefinitionSketch2 );
    if ( sketchDefinition2 )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      // Установка параметров эскиза
      sketchDefinition2->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза

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
      Kompas6api3d5com_tlb::IEntityPtr entityBossRotate( part->NewEntity( o3d_bossRotated ), false/*AddRef*/ );
      if ( entityBossRotate )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionBossRotate( entityBossRotate->GetDefinition(), false/*AddRef*/ );
        if ( pDefinitionBossRotate )
        {
          // Интерфейс базовой операции вращения
          Kompas6api3d5com_tlb::IBossRotatedDefinitionPtr bossRotatedDefinition( pDefinitionBossRotate );
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
            bossRotatedDefinition->SetSketch( entitySketch2 );        // Эскиз операции выдавливания
            // Операция приклеивания вращением
            entityBossRotate->Create();
						MessageT( _T("Операция приклеивания вращением") );
          }
        }
      }
    }
  }

  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch3( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( entitySketch2 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch3( entitySketch3->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition3( pDefinitionSketch3 );
    if ( sketchDefinition3 )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

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
      Kompas6api3d5com_tlb::IEntityPtr entityCutRotate( part->NewEntity( o3d_cutRotated ), false/*AddRef*/ );
      if ( entityCutRotate )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionCutRotate( entityCutRotate->GetDefinition(), false/*AddRef*/ );
        // Интерфейс базовой операции вращения
        Kompas6api3d5com_tlb::ICutRotatedDefinitionPtr cutRotatedDefinition( pDefinitionCutRotate );
        if ( cutRotatedDefinition )
        {
          cutRotatedDefinition->SetToroidShapeType( false );       // Признак тороида ( TRUE - тороид, FALSE - сфероид )
          cutRotatedDefinition->SetDirectionType( dtNormal );      // Направление вращения ( dtNormal - прямое направление, для тонкой стенки - наружу
                                                                   // dtReverse - обратное направление, для тонкой стенки - внутрь, dtBoth - в обе стороны,
                                                                   // dtMiddlePlane - от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          cutRotatedDefinition->SetSideParam( true,                // Направление вращения ( TRUE - прямое, FALSE - обратное )
                                              90 );                // Угол вращения
          // Изменить параметры тонкой стенки
          cutRotatedDefinition->SetThinParam( true,                // Признак тонкостенной операции
                                              dtBoth,              // Направление построения тонкой стенки
                                              5,                   // Толщина стенки в прямом направлении
                                              7 );                 // Толщина стенки в обратном направлении
          cutRotatedDefinition->SetSketch( entitySketch3 );        // Эскиз операции выдавливания
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
void OperationLoft( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if (  entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

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
  Kompas6api3d5com_tlb::IEntityPtr entityPlaneOffset2( part->NewEntity( o3d_planeOffset ), false/*AddRef*/ );
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch2( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( (bool)entityPlaneOffset2 && (bool)entitySketch2 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionPlaneOffset2( entityPlaneOffset2->GetDefinition(), false/*AddRef*/);
    // Интерфейс свойств смещенной плоскости
    Kompas6api3d5com_tlb::IPlaneOffsetDefinitionPtr planeOffsetDefinition2( pDefinitionPlaneOffset2 );

    if ( planeOffsetDefinition2 )
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition2->SetOffset( 30 ); // Расстояние от базовой плоскости

      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      planeOffsetDefinition2->SetPlane( basePlane ); // Установим плоскость XOY базовой для плоскости

      // Получить строку
			entityPlaneOffset2->SetName( L"Смещенная плоскость 2" );                  // Имя для смещенной плоскости
			// Освободить строку

      entityPlaneOffset2->SetHidden( true );                // Скрыть смещенную плоскость

      // Создать смещенную плоскость
      entityPlaneOffset2->Create();

      // Получить указатель на интерфейс параметров объектов и элементов
      IUnknownPtr pDefinitionSketch2( entitySketch2->GetDefinition(), false );
      // Интерфейс свойств эскиза
      Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition2( pDefinitionSketch2 );
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
  Kompas6api3d5com_tlb::IEntityPtr entityPlaneOffset3( part->NewEntity( o3d_planeOffset ), false/*AddRef*/ );
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch3( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( (bool)entityPlaneOffset3 && (bool)entitySketch3 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionPlaneOffset3( entityPlaneOffset3->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств смещенной плоскости
    Kompas6api3d5com_tlb::IPlaneOffsetDefinitionPtr planeOffsetDefinition3( pDefinitionPlaneOffset3 );

    if ( planeOffsetDefinition3 )
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition3->SetOffset( 60 ); // Расстояние от базовой плоскости

      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      planeOffsetDefinition3->SetPlane( basePlane ); // Установим плоскость XOY базовой для плоскости

			entityPlaneOffset3->SetName( L"Смещенная плоскость 3" );                 // Имя для смещенной плоскости

			entityPlaneOffset3->SetHidden( true );               // Скрыть смещенную плоскость

      // Создать смещенную плоскость
      entityPlaneOffset3->Create();

      // Получить указатель на интерфейс параметров объектов и элементов
      IUnknownPtr pDefinitionSketch3( entitySketch3->GetDefinition(), false/*AddRef*/ );
      // Интерфейс свойств эскиза
      Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition3( pDefinitionSketch3 );
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
  Kompas6api3d5com_tlb::IEntityPtr entityBaseLoft( part->NewEntity( o3d_bossLoft ), false/*AddRef*/ );
  if ( entityBaseLoft )
  {
    IUnknownPtr pDefinitionBaseLoft( entityBaseLoft->GetDefinition(), false/*AddRef*/ );
    Kompas6api3d5com_tlb::IBossLoftDefinitionPtr baseLoftDefinition( pDefinitionBaseLoft );
    if ( baseLoftDefinition )
    {
      Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( baseLoftDefinition->Sketchs(), false/*AddRef*/ );
      if ( entityCollection )
      {
        entityCollection->Add( entitySketch );
        entityCollection->Add( entitySketch2 );
        entityCollection->Add( entitySketch3 );
      }

			entityBaseLoft->SetName( L"Ручка" ); // Имя для операции по сечениям
			// Изменить параметры цвета и визуальных свойств объекта
      entityBaseLoft->SetAdvancedColor( 12345678, // Цвет
                                        .8,       // Общий свет
                                        .8,       // Диффузия
                                        .8,       // Зеркальность
                                        .8,       // Блеск
                                         1,       // Прозрачность
                                        .8 );     // Излучение

      // Cоздать операцию по сечениям
      entityBaseLoft->Create();
      MessageT( _T("Базовая операция по сечениям") );
    }
  }
  
  // Создадим эскиз в уже созданной смещенной плоскости
  Kompas6api3d5com_tlb::IEntityPtr entitySketch4( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if (  entitySketch4 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch4( entitySketch4->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition4( pDefinitionSketch4 );
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
  Kompas6api3d5com_tlb::IEntityPtr entityPlaneOffset5( part->NewEntity( o3d_planeOffset ), false/*AddRef*/ );
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch5( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( (bool)entityPlaneOffset5 && (bool)entitySketch5 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionPlaneOffset5( entityPlaneOffset5->GetDefinition(), false/*AddRef*/ );

    // Интерфейс свойств смещенной плоскости
    Kompas6api3d5com_tlb::IPlaneOffsetDefinitionPtr planeOffsetDefinition5( pDefinitionPlaneOffset5 );

    if ( planeOffsetDefinition5 )
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition5->SetOffset( 120 ); // Расстояние от базовой плоскости

      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      planeOffsetDefinition5->SetPlane( basePlane ); // Установим плоскость XOY базовой для плоскости

			entityPlaneOffset5->SetName( L"Смещенная плоскость 5" );                 // Имя для смещенной плоскости

      entityPlaneOffset5->SetHidden( true );               // Скрыть смещенную плоскость

      // Создать смещенную плоскость
      entityPlaneOffset5->Create();

      // Получить указатель на интерфейс параметров объектов и элементов
      IUnknownPtr pDefinitionSketch5( entitySketch5->GetDefinition(), false/*AddRef*/ );
      // Интерфейс свойств эскиза
      Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition5( pDefinitionSketch5 );
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
  Kompas6api3d5com_tlb::IEntityPtr entityBossLoft( part->NewEntity( o3d_bossLoft ), false/*AddRef*/ );
  if ( entityBossLoft )
  {
    IUnknownPtr pDefinitionBossLoft( entityBossLoft->GetDefinition(), false/*AddRef*/ );
    Kompas6api3d5com_tlb::IBossLoftDefinitionPtr bossLoftDefinition( pDefinitionBossLoft );
    if ( bossLoftDefinition )
    {
      Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( bossLoftDefinition->Sketchs(), false/*AddRef*/ );
      if ( entityCollection )
      {
        entityCollection->Add( entitySketch4 );
        entityCollection->Add( entitySketch5 );
      }

			entityBossLoft->SetName( L"Цивьё" ); // Имя для операции по сечениям
			// Изменить параметры цвета и визуальных свойств объекта
      entityBossLoft->SetAdvancedColor( 1234567890, // Цвет
                                        .8,         // Общий свет
                                        .8,         // Диффузия
                                        .8,         // Зеркальность
                                        .8,         // Блеск
                                         1,         // Прозрачность
                                        .8 );       // Излучение

      // Cоздать операцию приклеивания по сечениям
      entityBossLoft->Create();
			MessageT( _T("Операция приклеивания по сечениям") );
    }
  }

  // Создадим эскиз в уже созданной смещенной плоскости
  Kompas6api3d5com_tlb::IEntityPtr entitySketch6( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if (  entitySketch6 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch6( entitySketch6->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition6( pDefinitionSketch6 );
    if ( sketchDefinition6 )
    {
      // Установка параметров эскиза
      sketchDefinition6->SetPlane( entityPlaneOffset5 ); // Установим смещенную плоскость базовой для эскиза

      // Создадим эскиз
      entitySketch6->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition6->BeginEdit() )
      {
        // Введем новый эскиз - прямоугольник
        RectangleParam parRectangle; // Структура параметров прямоугольника
        memset( &parRectangle, 0, sizeof( parRectangle ) );
        parRectangle.x       = -1.8;                         // Координаты базовой точки прямоугольника - одной из его вершин
        parRectangle.y       = -.4;
        parRectangle.height  = .8;                           // Высота прямоугольника
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
  Kompas6api3d5com_tlb::IEntityPtr entityPlaneOffset7( part->NewEntity( o3d_planeOffset ), false/*AddRef*/ );
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch7( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( (bool)entityPlaneOffset7 && (bool)entitySketch7 )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionPlaneOffset7( entityPlaneOffset7->GetDefinition(), false/*AddRef*/ );
    if ( pDefinitionPlaneOffset7 )
    {
      // Интерфейс свойств смещенной плоскости
      Kompas6api3d5com_tlb::IPlaneOffsetDefinitionPtr planeOffsetDefinition7( pDefinitionPlaneOffset7 );
    
      if ( planeOffsetDefinition7 ) 
      {
        // Установка параметров смещенной плоскости
        planeOffsetDefinition7->SetOffset( 110 ); // Расстояние от базовой плоскости
        
        // Получим интерфейс базовой плоскости XOY
        Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

        planeOffsetDefinition7->SetPlane( basePlane ); // Установим плоскость XOY базовой для плоскости
        
				entityPlaneOffset7->SetName( L"Смещенная плоскость 7" );                 // Имя для смещенной плоскости
        
        entityPlaneOffset7->SetHidden( true );               // Скрыть смещенную плоскость
        
        // Создать смещенную плоскость
        entityPlaneOffset7->Create();             
        
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionSketch7( entitySketch7->GetDefinition(), false/*AddRef*/ );
        // Интерфейс свойств эскиза
        Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition7( pDefinitionSketch7 );
        if ( sketchDefinition7 )
        {
          // Установка параметров эскиза
          sketchDefinition7->SetPlane( entityPlaneOffset7 ); // Установим смещенную плоскость базовой для эскиза

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
  } 

  // Создадим операцию вырезания по сечениям
  Kompas6api3d5com_tlb::IEntityPtr entityCutLoft( part->NewEntity( o3d_cutLoft ), false/*AddRef*/ );
  if ( entityCutLoft ) 
  {
    IUnknownPtr pDefinitionCutLoft( entityCutLoft->GetDefinition(), false/*AddRef*/ );
    Kompas6api3d5com_tlb::ICutLoftDefinitionPtr cutLoftDefinition( pDefinitionCutLoft );
    if ( cutLoftDefinition )
    {
      Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( cutLoftDefinition->Sketchs(), false/*AddRef*/ );
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
			entityCutLoft->SetName( L"Рабочая поверхность" ); // Имя для операции по сечениям
			// Изменить параметры цвета и визуальных свойств объекта
      entityCutLoft->SetAdvancedColor( 1234, // Цвет
                                       .8,   // Общий свет
                                       .8,   // Диффузия
                                       .8,   // Зеркальность
                                       .8,   // Блеск
                                        1,   // Прозрачность
                                       .8 ); // Излучение

      // Cоздать операцию вырезания по сечениям
      entityCutLoft->Create();
      MessageT( _T("Операция вырезания по сечениям") );
    }
  }
}

