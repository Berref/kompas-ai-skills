////////////////////////////////////////////////////////////////////////////////
//
// Step4_API7_3D.cpp - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "Step4_API7_3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE Step4_API7_3DDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
IApplicationPtr newKompasAPI( NULL );               

void OnProcessDetach();                            // Отключение библиотеки


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void CreateAndEditPointDrivenPattern( IKompasDocumentPtr & doc );
void CreateAndEditCircularPattern   ( IKompasDocumentPtr & doc );
void CreateAndEditMirrorPattern     ( IKompasDocumentPtr & doc );
void CreateAndEditExtrusionSurface  ( IKompasDocumentPtr & doc );
void CreateAndEditMeshPointSurface  ( IKompasDocumentPtr & doc );
void CreateAndEditFilletCurve       ( IKompasDocumentPtr & doc );


//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
  g_hInstance = hInstance;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("STEP4_API7_3D.AWX Initializing!\n");

		AfxInitExtensionModule(Step4_API7_3DDLL, hInstance);

		new CDynLinkLibrary(Step4_API7_3DDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("STEP4_API7_3D.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(Step4_API7_3DDLL);
	}
	return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() 
{
  if ( !( IApplication * )newKompasAPI ) 
  {
    CString filename;
    
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
    {
      filename.ReleaseBuffer( 255 );
      CString libname;
      
      libname = LoadStr( IDR_API7 );    // kAPI7.dll
      filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
        libname );
      
      HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI7.dll
      
      if(  hAppAuto ) 
      {
        // Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH ( WINAPI * FCreateKompasApplication )(); 
        
        FCreateKompasApplication pCreateKompasApplication = 
          (FCreateKompasApplication)GetProcAddress( hAppAuto, "CreateKompasApplication" );	
        
        if ( pCreateKompasApplication )
          newKompasAPI = IDispatchPtr ( pCreateKompasApplication(), false /*AddRef*/); // Получаем интерфейс Application
        FreeLibrary( hAppAuto );  
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  GetNewKompasAPI();
  
  if ( newKompasAPI )
  {
    // Получаем текущий документ
    IKompasDocumentPtr doc( newKompasAPI->ActiveDocument );
    
    switch ( comm )
    {
      case 1: 
      {
        // Массив по точкам
        CreateAndEditPointDrivenPattern( doc ); 
        break;
      }
      
      case 2: 
      {
        // Массив по концентрической сетке
        CreateAndEditCircularPattern( doc ); 
        break;
      }
      
      case 3: 
      {
        // Зеркальный массив
        CreateAndEditMirrorPattern( doc ); 
        break;
      }
      
      case 4: 
      {
        // Поверхность выдавливания
        CreateAndEditExtrusionSurface( doc ); 
        break;
      }
      
      case 5: 
      {
        // Поверхность по сети точек
        CreateAndEditMeshPointSurface( doc ); 
        break;
      }
      
      case 6: 
      {
        // Операция скругления кривых
        CreateAndEditFilletCurve( doc ); 
        break;
      }
    }
  }
}


//-----------------------------------------------------------------------------
/**
  Получить контейнер модельных объектов
  \param doc - указатель на текущий документ
  \return указатель на интерфейс контейнера модельных объектов
*/
//---
IModelContainerPtr GetModelContainer( IKompasDocumentPtr & doc )
{
  IModelContainerPtr mCont = NULL;
  
  if ( doc )
  {
    // Получаем документ 3Д 
    IKompasDocument3DPtr document3D( doc );

    if ( document3D ) 
    {
      // Получаем верхний компонент
      IPart7Ptr part7( document3D->GetTopPart() ); 

      if ( part7 )
        // Получаем контейнер модельных объектов
        mCont = IModelContainerPtr( part7 );
    }
  }
  return mCont;
}


//-----------------------------------------------------------------------------
/**
  Получить интерфейс контейнера поверхностей
  \param doc - указатель на текущий документ
  \return указатель на интерфейс контейнера поверхностей
*/
//---
ISurfaceContainerPtr GetSurfaceContainer( IKompasDocumentPtr & doc )
{
  ISurfaceContainerPtr surfCont = NULL;
  
  if ( doc )
  {
    // Получаем документ 3Д 
    IKompasDocument3DPtr document3D ( doc );

    if ( document3D ) 
    {
      // Получаем верхний компонент
      IPart7Ptr part7( document3D->GetTopPart() ); 

      if ( part7 )
        // Получаем контейнер поверхностей
        surfCont = ISurfaceContainerPtr( part7 );
    }
  }
  return surfCont;
}


//-----------------------------------------------------------------------------
/**
  Получить интерфейс контейнера вспомогательной геометрии
  \param doc - указатель на текущий документ
  \return указатель на интерфейс контейнера вспомогательной геометрии
*/
//---
IAuxiliaryGeomContainerPtr GetAuxiliaryGeomContainer( IKompasDocumentPtr & doc )
{
  IAuxiliaryGeomContainerPtr auxCont = NULL;
  
  if ( doc )
  {
    // Получаем документ 3D 
    IKompasDocument3DPtr document3D ( doc );

    if ( document3D ) 
    {
      // Получаем верхний компонент
      IPart7Ptr part7( document3D->GetTopPart() ); 

      if ( part7 )
        // Получаем контейнер вспомогательной геометрии
        auxCont = IAuxiliaryGeomContainerPtr( part7 );
    }
  }
  return auxCont;
}


//-----------------------------------------------------------------------------
/**
  Создать эскиз в виде прямоугольника
  \param doc - указатель на текущий документ
  \param x, y - координаты базовой точки прямоугольника
  \param h - высота прямоугольника
  \param w - ширина прямоугольника
  \return указатель на интерфейс эскиза
*/
//---
ISketchPtr CreateSketch( IKompasDocumentPtr & doc, double x, double y, double h, double w )
{
  ISketchPtr sketch = NULL;
  
  if ( doc )
  {
    IModelContainerPtr modelCont( GetModelContainer(doc) );

    if ( modelCont )
    {
      // Получаем коллекцию эскзиов
      ISketchsPtr sketchs( modelCont->GetSketchs() );

      if ( sketchs )
      {
        // Добавляем новый эскиз
        sketch = sketchs->Add();

        if ( sketch )
        {
          // Получаем 3D документ
          IKompasDocument3DPtr doc3D( doc );

          if ( doc3D )
          {
            // Получаем верхнюю деталь
            IPart7Ptr part ( doc3D->TopPart );

            if ( part )
            {
              // Получаем плоскость XY
              IModelObjectPtr planeXY ( part->GetDefaultObject(o3d_planeXOY) );
              // Задаем базовую плоскость для эскиза
              sketch->Plane = planeXY;
              // Редактируем эскиз
              sketch->BeginEdit();

              // Строим прямоугольник
              RectangleParam par;
              memset( &par, 0, sizeof(par) );
              par.x = x;
              par.y = y;
              par.height = h;
              par.width = w;
              par.style = ksCSNormal;
              ksRectangle( &par, 0/*без осей*/ );

              sketch->EndEdit();
            }
          }  
          sketch->Update();   
        }  
      }
    }
  }
  return sketch;
}      

      
//-----------------------------------------------------------------------------
/**
  Создать операцию выдавливания
  \param doc - указатель на текущий документ
  \return указатель на операцию выдавливания
*/
//---
IExtrusionPtr CreateExtrusion( IKompasDocumentPtr & doc )
{
  IExtrusionPtr newExtrusion = NULL;
  
  if ( doc )
  {
    // Получаем контейнер модельных объектов
    IModelContainerPtr modelCont( GetModelContainer(doc) );

    if ( modelCont )
    {
      // Получаем коллекцию операций выдавливания
      IExtrusionsPtr extrusions( modelCont->GetExtrusions() );

      if ( extrusions )
      {
        // Добавляем новую операцию выдавливания
        newExtrusion = extrusions->Add( o3d_bossExtrusion );

        if ( newExtrusion )
        {
          // Создаем эскиз для построения операции
          ISketchPtr sketch( CreateSketch(doc, 0, 0, 25, 25) );

          if ( sketch )
            newExtrusion->Sketch = sketch;
            
          // Задаем параметры операции
          newExtrusion->PutDepth( TRUE/*normal*/, 10 );
          newExtrusion->Direction = dtNormal;
          newExtrusion->PutExtrusionType( TRUE/*normal*/, etBlind );
          newExtrusion->Update();
        }
      }
    }
  }
  return newExtrusion;
}


//-----------------------------------------------------------------------------
/**
  Создать точку
  \param doc - указатель на текущий документ
  \param x, y, z - координаты точки
  \return указатель на интерфейс точки
*/
//---
IPoint3DPtr CreatePoint( IKompasDocumentPtr & doc, double x, double y, double z )
{
  IPoint3DPtr newPoint = NULL;
  
  if ( doc )
  {
    // Получаем контейнер модельных объектов
    IModelContainerPtr modelCont( GetModelContainer(doc) );

    if ( modelCont )
    { 
      // Получаем коллекцию точек
      IPoints3DPtr pointsColl( modelCont->GetPoints3D() );

      if ( pointsColl )
      {
        // Добавляем новую точку
        newPoint = pointsColl->Add();

        if ( newPoint )
        {
          // Задаем параметры точки
          newPoint->X = x;
          newPoint->Y = y;
          newPoint->Z = z;
          newPoint->Symbol = ksDotPoint;
          newPoint->ParameterType = ksPParamCoord;
          newPoint->Update();
        }
      }
    }
  }
  return newPoint;
}


//-----------------------------------------------------------------------------
/**
  Создать SafeArray типа double 
  \param dv - массив
  \param count - количество элементов
  \param buf - SafeArray
  \return True - в случае успеха, False - в случае неудачи
*/
//---
bool CreateSafeArrayDouble( double * dv, int count, _variant_t & buf )
{
  bool res = false;
  SAFEARRAYBOUND sabNewArray;

  sabNewArray.cElements = count;
  sabNewArray.lLbound = 0;

  SAFEARRAY * pSafe = ::SafeArrayCreate( VT_R8, 1, &sabNewArray );

  if( pSafe )
  {
    for ( long i = 0; i < count; i++ )
    {
      HRESULT  hr = ::SafeArrayPutElement( pSafe, (long*)&i, (void*)&dv[i] );

      if ( FAILED(hr) ) 
        break;
    }

    V_VT(&buf) = VT_ARRAY | VT_R8;
    V_ARRAY(&buf) = pSafe;
    res = true;
  }
  return res;
}


//-----------------------------------------------------------------------------
/**
  Создать ломаную из одного сегмента
  \param doc - указатель на текущий документ
  \return указатель на интерфейс контейнера модельных объектов
*/
//---
IPolyLinePtr CreatePolyLine( IKompasDocumentPtr & doc,
                             double x1, double y1, double z1,
                             double x2, double y2, double z2 )
{
  IPolyLinePtr polyLine = NULL;
  
  // Получаем контейнер вспомогательной геометрии
  IAuxiliaryGeomContainerPtr geomCont( GetAuxiliaryGeomContainer(doc) );

  if ( geomCont )
  {
    // Получаем коллекцию ломаных
    IPolyLinesPtr coll = geomCont->GetPolyLines();

    if ( coll )
    {
      // Добавляем ломаную в коллекцию
      polyLine = coll->Add();
      
      if ( polyLine )
      {
        // Создаем вершины ломаной
        ICurveVertexParamPtr vertex1( polyLine->AddVertex(-1) );
        
        if ( vertex1 )
          vertex1->SetParamVertex( x1, y1, z1, 1 );
          
        ICurveVertexParamPtr vertex2( polyLine->AddVertex(-1) );

        if ( vertex2 )
          vertex2->SetParamVertex( x2, y2, z2, 1 );
          
        polyLine->Update();
      }
    }
  }
  return polyLine;
}


//-----------------------------------------------------------------------------
/**
  Создание и редактирование массива по точкам
  \param doc - указатель на текущий документ
  \return
*/
//---
void CreateAndEditPointDrivenPattern( IKompasDocumentPtr & doc )
{
  if ( doc )
  {
    // Получаем контейнер модельных объектов
    IModelContainerPtr modelCont( GetModelContainer(doc) );

    if ( modelCont )
    {
      // Получаем коллекцию массивов
      IFeaturePatternsPtr patternsCol( modelCont->FeaturePatterns );

      if ( patternsCol )
      {
        // Добавляем новую операцию копирования по точкам
        IPointDrivenPatternPtr newPattern( patternsCol->Add(o3d_PointDrivenPattern/*массив операций*/) );
        
        if ( newPattern )
        {
          // Создаем исходный объект для массива - операцию выдавливания
          IModelObjectPtr iniObj( CreateExtrusion(doc) );
          // Создаем точки для построения массива
          IPoint3DPtr point1( CreatePoint(doc, 27, -39, 13) );
          IPoint3DPtr point2( CreatePoint(doc, -16, -15, 31) );
          IPoint3DPtr point3( CreatePoint(doc, -41, 35, 6) );
          
          if ( iniObj && point1 && point2 && point3 )
          {
            // Устанавливаем исходный объект массива
            newPattern->InitialObjects = (LPDISPATCH)iniObj;
            
            // Проверяем пригодность точек для операции
            if ( newPattern->IsSuitableDrivenObject(point1) && 
                 newPattern->IsSuitableDrivenObject(point2) && 
                 newPattern->IsSuitableDrivenObject(point3) )
            {
              // Создаем массив точек
              _variant_t pointsArray;
              VariantInit( &pointsArray );
              SAFEARRAYBOUND sabNewArray1;
              SAFEARRAY * pSafe = NULL;
              sabNewArray1.cElements = 3;
              sabNewArray1.lLbound = 0;
              pSafe = ::SafeArrayCreate( VT_DISPATCH, 1, &sabNewArray1 );
              LPDISPATCH disp = (LPDISPATCH)point1;
              long i = 0;
              ::SafeArrayPutElement( pSafe, (long*)&i, (void*)disp );
              disp = (LPDISPATCH)point2;
              i = 1;
              ::SafeArrayPutElement( pSafe, (long*)&i, (void*)disp );
              disp = (LPDISPATCH)point3;
              i = 2;
              ::SafeArrayPutElement( pSafe, (long*)&i, (void*)disp );
              V_VT(&pointsArray) = VT_ARRAY | VT_DISPATCH;
              V_ARRAY(&pointsArray) = pSafe;
              // Задаем массив управляющих объектов
              newPattern->DrivenObjects = pointsArray;
            }
            newPattern->Update();
          }
        }
        // Редактирование массива
        if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
        {
          // Получаем массив из коллекции
          IPointDrivenPatternPtr pattern( patternsCol->GetFeaturePattern((long)0) );
          
          if ( pattern )
          {
            // Создаем массив индексов удаляемых элементов
            _variant_t indexArray;
            SAFEARRAYBOUND sabNewArray1;
            SAFEARRAY * pSafe = NULL;
            sabNewArray1.cElements = 2;
            sabNewArray1.lLbound = 0;
            pSafe = ::SafeArrayCreate( VT_I4, 1, &sabNewArray1 );
            long index = 2;
            long i = 0;
            ::SafeArrayPutElement( pSafe, (long*)&i, (void*)&index );
            index = 0;
            i = 1;
            ::SafeArrayPutElement( pSafe, (long*)&i, (void*)&index );
            V_VT(&indexArray) = VT_ARRAY | VT_I4;
            V_ARRAY(&indexArray) = pSafe;
            
            // Удаляем элемент
            pattern->InstanceDeletedIndexes = indexArray;
            pattern->Update();
          }
        }
      }
    }
  }
}


//-----------------------------------------------------------------------------
/**
  Создание и редактирование массива по концентрической сетке
  \param doc - указатель на текущий документ
  \return
*/
//---
void CreateAndEditCircularPattern( IKompasDocumentPtr & doc )
{
  if ( doc )
  {
    // Получаем контейнер модельных объектов
    IModelContainerPtr modelCont( GetModelContainer(doc) );

    if ( modelCont )
    {
      // Получаем коллекцию массивов
      IFeaturePatternsPtr patternsCol( modelCont->FeaturePatterns );

      if ( patternsCol )
      {
        // Добавляем новую операцию копирования по концентрической сетке 
        ICircularPatternPtr newPattern( patternsCol->Add(o3d_circularCopy/*массив операций*/) );
        
        if ( newPattern )
        {
          // Создаем исходный объект для массива - операцию выдавливания
          IModelObjectPtr iniObj( CreateExtrusion(doc) );
          
          if ( iniObj )
          {
            // Устанавливаем исходный объект массива
            newPattern->InitialObjects = (LPDISPATCH)iniObj;
            
            // Шаг копирования в кольцевом направлении
            newPattern->Step2 = 360;
            // Количество экземпляров в кольцевом направлении
            newPattern->Count2 = 6;
            // Шаг между крайними экземплярами
            newPattern->BoundaryInstancesStepFactor2 = TRUE;
            
            // Ось массива
            IKompasDocument3DPtr document3D( doc );

            if ( document3D ) 
            {
              IPart7Ptr part7( document3D->GetTopPart() );
              
              if ( part7 )
              {
                IModelObjectPtr axisOZ( part7->GetDefaultObject(o3d_axisOZ) );
                
                if ( axisOZ )
                  newPattern->Axis = axisOZ;
              } 
            }
            newPattern->Update();
          }
        }
        // Редактируем
        if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
        {
          // Получаем массив из коллекции
          ICircularPatternPtr pattern( patternsCol->GetFeaturePattern((long)0) );
          
          if ( pattern )
          {
            // Шаг копирования в радиальном направлении
            pattern->Step1 = 10;
            // Количество экземпляров в радиальном направлении
            pattern->Count1 = 5;
            // Исходная ориентация
            pattern->SaveInitialOrientation = TRUE;
            
            pattern->Update();
          }
        }
      }
    }
  }
}


//-----------------------------------------------------------------------------
/**
  Создание и редактирование зеркального массива
  \param doc - указатель на текущий документ
  \return
*/
//---
void CreateAndEditMirrorPattern( IKompasDocumentPtr & doc )
{
  if ( doc )
  {
    IKompasDocument3DPtr document3D( doc );
    // Получаем контейнер модельных объектов
    IModelContainerPtr modelCont( GetModelContainer(doc) );

    if ( modelCont && document3D )
    {
      // Получаем коллекцию массивов
      IFeaturePatternsPtr patternsCol( modelCont->FeaturePatterns );
      IPart7Ptr part7( document3D->GetTopPart() );

      if ( patternsCol && part7 )
      {
        // Добавляем новый зеркальный массив
        IMirrorPatternPtr newPattern( patternsCol->Add(o3d_mirrorOperation/*массив операций*/) );

        if ( newPattern )
        {
          // Создаем исходный объект для массива - операцию выдавливания
          IModelObjectPtr iniObj( CreateExtrusion(doc) );

          if ( iniObj )
          {
            // Устанавливаем исходный объект массива
            newPattern->InitialObjects = (LPDISPATCH)iniObj;
            
            // Получаем плоскость симметрии
            IModelObjectPtr planeXY( part7->GetDefaultObject(o3d_planeXOY) );

            if ( planeXY )
              newPattern->Plane = planeXY;
              
            // Оставлять исходные объекты
            newPattern->SaveInitialObjects = TRUE;
            newPattern->Update();
          }
        }
        // Редактируем
        if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
        {
          // Получаем массив из коллекции
          IMirrorPatternPtr pattern( patternsCol->GetFeaturePattern((long)0) );
          
          if ( pattern )
          {
            // Меняем плоскость симметрии
            IModelObjectPtr planeXZ( part7->GetDefaultObject(o3d_planeXOZ) );

            if ( planeXZ )
              pattern->Plane = planeXZ;
            
            pattern->Update();
          }
        }
      }
    }
  }
}


//-----------------------------------------------------------------------------
/**
  Создание и редактирование поверхности выдавливания
  \param doc - указатель на текущий документ
  \return
*/
//---
void CreateAndEditExtrusionSurface( IKompasDocumentPtr & doc )
{
  // Получаем контейнер поверхностей
  ISurfaceContainerPtr surfCont( GetSurfaceContainer(doc) );

  if ( surfCont )
  {
    // Получаем коллекцию поверхностей выдавливания
    IExtrusionsPtr exrusionsCol( surfCont->ExtrusionSurfaces );

    if ( exrusionsCol )
    {
      // Добавляем новую поверхность выдавливания
      IExtrusionSurfacePtr newSurface( exrusionsCol->Add( o3d_ExtrusionSurface) );
      IExtrusion1Ptr surface1( newSurface );
      if ( surface1 )
      {
        // Создаем эскиз
        ISketchPtr sketch( CreateSketch(doc, -25, -40, 40, 40) );
        
        if ( sketch )
        {
          // Сечение
          surface1->Profile = sketch;
          // Направляющий объект
          surface1->DirectionObject = sketch;
          // Глубина
          newSurface->Depth[TRUE] = 10;
          // Признак замкнутости поверхности
          newSurface->ClosedShell = TRUE;
          
          newSurface->Update();
        }
      }
      // Редактируем
      if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
      {
        // Получаем поверхность выдавливания из коллекции
        IExtrusionSurfacePtr surface( exrusionsCol->GetExtrusion((long)0) );
        
        if ( surface )
        {
          // Уклон внутрь
          surface->DraftOutward[TRUE] = TRUE;
          // Угол уклона
          surface->DraftValue[TRUE] = 15;
          // Глубина
          surface->Depth[TRUE] = 30;
          // Признак замкнутости поверхности
          surface->ClosedShell = FALSE;
          
          surface->Update();
        }
      }
    }
  }
}


//-----------------------------------------------------------------------------
/**
  Создание и редактирование поверхности по сети точек
  \param doc - указатель на текущий документ
  \return
*/
//---
void CreateAndEditMeshPointSurface( IKompasDocumentPtr & doc )
{
  // Получаем контейнер поверхностей
  ISurfaceContainerPtr surfCont( GetSurfaceContainer(doc) );

  if ( surfCont )
  {
    // Получаем коллекцию поверхностей по сети точек
    IMeshPointsSurfacesPtr meshCol( surfCont->MeshPointsSurfaces );

    if ( meshCol )
    {
      // Добавляем новую поверхность по сети точек
      IMeshPointsSurfacePtr newSurface( meshCol->Add() );
      
      if ( newSurface )
      {
        // 1-й ряд точек
        newSurface->BeginPointsSeries( TRUE, -1 );
        newSurface->AddPoint( 39, -62, 23, 1, ksPParamCoord, NULL );
        newSurface->AddPoint( 18, -40, 22, 1, ksPParamCoord, NULL );
        newSurface->AddPoint( -13, -24, 37, 1, ksPParamCoord, NULL );
        newSurface->EndPointsSeries();

        // 2-й ряд точек
        newSurface->BeginPointsSeries( TRUE, -1 );
        newSurface->AddPoint( 56, -52, -4, 1, ksPParamCoord, NULL );
        newSurface->AddPoint( 28, -21, 7, 1, ksPParamCoord, NULL );
        newSurface->AddPoint( 1, -11, 10, 1, ksPParamCoord, NULL );
        newSurface->EndPointsSeries();
        
        newSurface->Update();
      }
      // Редактируем
      if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
      {
        // Получаем поверхность по сети точек из коллекции
        IMeshPointsSurfacePtr surface( meshCol->GetMeshPointsSurface((long)0) );
        
        if ( surface )
        {
          double coords[9];
          _variant_t points;
          coords[0] = 73;
          coords[1] = -59;
          coords[2] = -14;
          coords[3] = 56;
          coords[4] = -41;
          coords[5] = -15;
          coords[6] = 30;
          coords[7] = -18;
          coords[8] = -13;
          CreateSafeArrayDouble( coords, 9, points );

          double weight[3];
          _variant_t weights;
          weight[0] = 1;
          weight[1] = 3;
          weight[2] = 3;
          CreateSafeArrayDouble( weight, 3, weights );
          
          // Добавляем ряд точек
          surface->AddPointsSeries( TRUE, -1, points, weights );
          
          surface->Update();
        }
      }
    }
  }
}


//-----------------------------------------------------------------------------
/**
  Создание и редактирование операции скругления кривых
  \param doc - указатель на текущий документ
  \return
*/
//---
void CreateAndEditFilletCurve( IKompasDocumentPtr & doc )
{
  // Получаем контейнер вспомогательной геометрии
  IAuxiliaryGeomContainerPtr auxCont( GetAuxiliaryGeomContainer(doc) );

  if ( auxCont )
  {
    // Получаем коллекцию операций скругления кривых
    IFilletCurvesPtr filletCol( auxCont->FilletCurves );

    if ( filletCol )
    {
      // Добавляем новую операцию скругления
      IFilletCurvePtr newFilletCurve( filletCol->Add() );
      
      if ( newFilletCurve )
      {
        // Создаем кривые
        IPolyLinePtr polyLine1( CreatePolyLine(doc, 36, -37, 55, 36, -37, 1) );
        IPolyLinePtr polyLine2( CreatePolyLine(doc, 36, -37, 1, -5, -37, 1) );
        
        if ( polyLine1 && polyLine2 )
        {
          // Задаем кривые
          newFilletCurve->Curve1 = polyLine1;
          newFilletCurve->Curve2 = polyLine2;
          // Радиус дуги скругления
          newFilletCurve->Radius = 10;
          
          newFilletCurve->Update();
        }
      }
      // Редактируем
      if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
      {
        // Получаем операцию скругления из коллекции
        IFilletCurvePtr filletCurve( filletCol->GetFilletCurve((long)0) );
        
        if ( filletCurve )
        {
          // Направление дуги скругления - обратное
          filletCurve->Direction = FALSE;
          // Радиус дуги скругления
          filletCurve->Radius = 25;
          
          filletCurve->Update();
        }
      }
    }
  }
}                 


//-------------------------------------------------------------------------------
// Завершение приложения
// ---
void OnProcessDetach()
{
  newKompasAPI = NULL;
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
CString LoadStr( int strID ) 
{
	TCHAR temp[_MAX_PATH];
	LoadString( Step4_API7_3DDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


