//////////////////////////////////////////////////////////////////////////////// 
// 
// step3d3.cpp - Конструктивные оси и плоскости
// 
// 1. Конструктивная ось операции                  - ConstrAxisOperations 
// 2. Конструктивная ось по двум точкам            - ConstrAxis2Point    
// 3. Конструктивная ось, проходящая через ребро   - ConstrAxisEdge      
// 4. Смещенная плоскость, ось по двум плоскостям, 
//    плоскость под углом к другой плоскости       - ConstrElem   
// 5. Плоскость через три вершины                  - ConstrPlane3Point   
// 
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
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
  UNREFERENCED_PARAMETER(lpReserved);

  if (dwReason == DLL_PROCESS_ATTACH)
  {
    TRACE0("DLL Initializing!");

    if (!AfxInitExtensionModule(StepDLL, hInstance))
      return 0;

    new CDynLinkLibrary(StepDLL);
  }
  else if (dwReason == DLL_PROCESS_DETACH)
  {
    TRACE0("DLL Terminating!");
    AfxTermExtensionModule(StepDLL);
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// Ресурсы ( имя библиотеки, состав меню, слайд ) находятся в <res\step3d3.rc2> , идентификаторы в <step3d3.rh> 
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void ConstrAxisOperations(IPartPtr& part);
void ConstrAxis2Point(IPartPtr& part);
void ConstrAxisEdge(IPartPtr& part);
void ConstrPlane3Point(IPartPtr& part);
void ConstrElem(IPartPtr& part);


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY(unsigned int comm)
{
  IDocument3DPtr pDocument3d(ksGetActive3dDocument(), false/*AddRef*/); // Получить указатель на активный документ трехмерной модели
  if (pDocument3d)
  {
    // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
    // pEdit_Part - редактируемая деталь, pTop_Part  - верхний компонент )
    IPartPtr part(pDocument3d->GetPart(pTop_Part), false/*AddRef*/);
    if (part)
    {
      switch (comm)
      {
        case 1: ConstrAxisOperations(part); break; // Конструктивная ось операции
        case 2: ConstrAxis2Point(part); break; // Конструктивная ось по двум точкам
        case 3: ConstrAxisEdge(part); break; // Конструктивная ось, проходящая через ребро
        case 4: ConstrElem(part); break; // Смещенная плоскость, ось по двум плоскостям, плоскость под углом к другой пло-ти
        case 5: ConstrPlane3Point(part); break; // Плоскость через три вершины
      }
    }
  }
  else
  {
    CString strError;
    strError.LoadString(IDS_3DDOCERROR); // "Документ не активизирован или не является 3D-моделью"
    ErrorT((LPTSTR)(LPCTSTR)strError); // Выдать сообщение о ошибке
  }
  if (ReturnResult() == etError10) // "Ошибка! Вырожденный объект"
    ResultNULL(); // Обнулить ошибки
}


//-------------------------------------------------------------------------------
// Конструктивная ось операции
// ---
void ConstrAxisOperations(IPartPtr& part)
{
  // Создадим новый эскиз
  IEntityPtr entitySketch(part->NewEntity(o3d_sketch), false/*AddRef*/);
  if (entitySketch)
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition(IUnknownPtr(entitySketch->GetDefinition(), false/*AddRef*/));
    if (sketchDefinition)
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane(part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/);

      // Установка параметров эскиза
      sketchDefinition->SetPlane(basePlane); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if (sketchDefinition->BeginEdit())
      {
        // Введем новый эскиз
        Circle(20, 0, 10, 1);
        LineSeg(0, 0, 0, 5, 3);
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }

      // Операция вращения
      IEntityPtr entityRotate(part->NewEntity(o3d_bossRotated), false/*AddRef*/);
      if (entityRotate)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс базовой операции вращения
        IBossRotatedDefinitionPtr baseRotatedDefinition(IUnknownPtr(entityRotate->GetDefinition(), false/*AddRef*/));
        if (baseRotatedDefinition)
        {
          // Параметры базовой операции вращения
          IRotatedParamPtr rotatedParam(baseRotatedDefinition->RotatedParam(), false/*AddRef*/);
          if (rotatedParam)
          {
            rotatedParam->SetDirection(dtBoth);  // Направление вращения ( dtNormal - прямое направление,
            // dtReverse - обратное направление, dtBoth - в обе стороны,
            // dtMiddlePlane - от средней плоскости )
            rotatedParam->SetToroidShape(false); // Признак тороида ( TRUE - тороид, FALSE - сфероид )
          }
          // Изменить параметры тонкой стенки элемента
          baseRotatedDefinition->SetThinParam(true,   // Признак тонкостенной операции 
                                              dtBoth, // Направление построения тонкой стенки ( dtNormal - прямое направление,
                                              // dtReverse - обратное направление, dtBoth - в обе стороны,
                                              // dtMiddlePlane - от средней плоскости )
                                              1,      // Толщина стенки в прямом направлении
                                              1);    // Толщина стенки в обратном направлении   
          // Изменить параметры вращения в одном направлении 
          baseRotatedDefinition->SetSideParam(true,   // Направление вращения ( TRUE - прямое, FALSE - обратное )
                                              180);  // Угол вращения 
          baseRotatedDefinition->SetSideParam(false, 180);
          baseRotatedDefinition->SetSketch(entitySketch); // Эскиз операции вращения 
          entityRotate->Create(); // Создать операцию вращения
        }
      }

      // Создадим ось операции
      IEntityPtr entityAxisOperation(part->NewEntity(o3d_axisOperation), false/*AddRef*/);
      if (entityAxisOperation)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс оси операции
        IAxisOperationsDefinitionPtr axisOperationsDefinition(IUnknownPtr(entityAxisOperation->GetDefinition(), false/*AddRef*/));
        if (axisOperationsDefinition)
        {
          axisOperationsDefinition->SetOperation(entityRotate); // Изменить базовый формообразующий элемент
          entityAxisOperation->Create(); // Cоздать ось операции
        }
      }
      MessageT(_T("Ось операции"));
    }
  }
}


//-------------------------------------------------------------------------------
// Конструктивная ось по двум точкам
// ---
void ConstrAxis2Point(IPartPtr& part)
{
  // Создадим новый эскиз
  IEntityPtr entitySketch(part->NewEntity(o3d_sketch), false/*AddRef*/);
  if (entitySketch)
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition(IUnknownPtr(entitySketch->GetDefinition(), false/*AddRef*/));
    if (sketchDefinition)
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane(part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/);

      // Установка параметров эскиза
      sketchDefinition->SetPlane(basePlane); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if (sketchDefinition->BeginEdit())
      {
        // Введем новый эскиз - квадрат
        LineSeg(50, 50, -50, 50, 1);
        LineSeg(50, -50, -50, -50, 1);
        LineSeg(50, -50, 50, 50, 1);
        LineSeg(-50, -50, -50, 50, 1);
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }

      // Базовая операция выдавливания
      IEntityPtr entityExtrusion(part->NewEntity(o3d_bossExtrusion), false/*AddRef*/);
      if (entityExtrusion)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс базовой операции выдавливания
        IBossExtrusionDefinitionPtr baseExtrusionDefinition(IUnknownPtr(entityExtrusion->GetDefinition(), false/*AddRef*/));
        if (baseExtrusionDefinition)
        {
          baseExtrusionDefinition->SetDirectionType(dtNormal);  // Направление выдавливания ( dtNormal  - прямое направление,
          // dtReverse - обратное направление, dtBoth - в обе стороны,
          // dtMiddlePlane - от средней плоскости )
// Изменить параметры выдавливания в одном направлении
          baseExtrusionDefinition->SetSideParam(true,    // Направление выдавливания ( TRUE - прямое направление, FALSE - обратное направление )
                                                etBlind, // Тип выдавливания ( etBlind - строго на глубину,
                                                // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на расстояние до поверхности,
                                                // etUpToSurfaceFrom  - на расстояние за поверхность, etUpToNearSurface - до ближайшей поверхности )
                                                20,      // Глубина выдавливания
                                                0,       // Угол уклона
                                                false); // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
          // Изменить параметры тонкой стенки элемента
          baseExtrusionDefinition->SetThinParam(true,   // Признак тонкостенной операции 
                                                dtBoth, // Направление построения тонкой стенки ( dtNormal - прямое направление,
                                                // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                // dtMiddlePlane - от средней плоскости )
                                                20,     // Толщина стенки в прямом направлении
                                                20);   // Толщина стенки в обратном направлении  
          baseExtrusionDefinition->SetSketch(entitySketch); // Эскиз операции выдавливания
          entityExtrusion->Create(); // Создать операцию выдавливания
        }
      }
    }

    // Ось по двум точкам
    // Формирует массив объектов и возвращает указатель на его интерфейс - массив вершин компонента  
    IEntityCollectionPtr entityCollection(part->EntityCollection(o3d_vertex), false/*AddRef*/);
    if ((bool)entityCollection && entityCollection->GetCount())
    {
      // Создадим ось по двум точкам
      IEntityPtr entityAxis2Point(part->NewEntity(o3d_axis2Points), false/*AddRef*/);
      if (entityAxis2Point)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс вспомогательной оси, проходящей через две точки
        IAxis2PointsDefinitionPtr axis2PointsDefinition(IUnknownPtr(entityAxis2Point->GetDefinition(), false/*AddRef*/));
        if (axis2PointsDefinition)
        {
          // Изменить указатель на интерфейс точки с указанным номером
          IEntityPtr ePtr1(entityCollection->GetByIndex(0), false/*AddRef*/);
          axis2PointsDefinition->SetPoint(1, ePtr1); // Указатель на интерфейс точки Номер точки (1 или 2)

          IEntityPtr ePtr2(entityCollection->GetByIndex(entityCollection->GetCount() - 1), false/*AddRef*/);
          axis2PointsDefinition->SetPoint(2, ePtr2);
          entityAxis2Point->Create(); // Создать вспомогательную ось, проходящюю через две точки
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Конструктивная ось, проходящая через ребро
// ---
void ConstrAxisEdge(IPartPtr& part)
{
  // Создадим новый эскиз
  IEntityPtr entitySketch(part->NewEntity(o3d_sketch), false/*AddRef*/);
  if (entitySketch)
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr  sketchDefinition(IUnknownPtr(entitySketch->GetDefinition(), false/*AddRef*/));
    if (sketchDefinition)
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane(part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/);

      // Установка параметров эскиза
      sketchDefinition->SetPlane(basePlane); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if (sketchDefinition->BeginEdit())
      {
        // Введем новый эскиз - квадрат
        LineSeg(50, 50, -50, 50, 1);
        LineSeg(50, -50, -50, -50, 1);
        LineSeg(50, -50, 50, 50, 1);
        LineSeg(-50, -50, -50, 50, 1);
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }

      // Базовая операция выдавливания
      IEntityPtr entityExtrusion(part->NewEntity(o3d_bossExtrusion), false/*AddRef*/);
      if (entityExtrusion)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс базовой операции выдавливания
        IBossExtrusionDefinitionPtr baseExtrusionDefinition(IUnknownPtr(entityExtrusion->GetDefinition(), false/*AddRef*/));
        if (baseExtrusionDefinition)
        {
          baseExtrusionDefinition->SetDirectionType(dtNormal);  // Направление выдавливания ( dtNormal  - прямое направление,
          // dtReverse - обратное направление, dtBoth - в обе стороны,
          // dtMiddlePlane - от средней плоскости )
// Изменить параметры выдавливания в одном направлении
          baseExtrusionDefinition->SetSideParam(true,    // Направление выдавливания ( TRUE - прямое направление, FALSE - обратное направление )
                                                etBlind, // Тип выдавливания ( etBlind - строго на глубину,
                                                // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на расстояние до поверхности,
                                                // etUpToSurfaceFrom  - на расстояние за поверхность, etUpToNearSurface - до ближайшей поверхности )
                                                20,      // Глубина выдавливания
                                                0,       // Угол уклона
                                                false); // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
          // Изменить параметры тонкой стенки элемента
          baseExtrusionDefinition->SetThinParam(true,   // Признак тонкостенной операции 
                                                dtBoth, // Направление построения тонкой стенки ( dtNormal - прямое направление,
                                                // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                // dtMiddlePlane - от средней плоскости )
                                                20,     // Толщина стенки в прямом направлении
                                                20);   // Толщина стенки в обратном направлении  
          baseExtrusionDefinition->SetSketch(entitySketch); // Эскиз операции выдавливания
          entityExtrusion->Create(); // Создать операцию выдавливания
        }
      }
    }

    // Ось через грань
    // Формирует массив объектов и возвращает указатель на его интерфейс - массив граней компонента 
    IEntityCollectionPtr entityCollection(part->EntityCollection(o3d_edge), false/*AddRef*/);
    if ((bool)entityCollection && entityCollection->GetCount())
    {
      // Создадим ось через грань
      IEntityPtr entityAxisEdge(part->NewEntity(o3d_axisEdge), false/*AddRef*/);
      if (entityAxisEdge)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс вспомогательной оси, проходящей через прямолинейное ребро
        IAxisEdgeDefinitionPtr axisEdgeDefinition(IUnknownPtr(entityAxisEdge->GetDefinition(), false/*AddRef*/));
        if (axisEdgeDefinition)
        {
          // Изменить указатель на интерфейс базового ребра
          IEntityPtr ePtr(entityCollection->GetByIndex(0), false/*AddRef*/);
          axisEdgeDefinition->SetEdge(ePtr);
          entityAxisEdge->Create(); // Создать вспомогательную ось, проходящюю через прямолинейное ребро
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Плоскость через три вершины
// ---
void ConstrPlane3Point(IPartPtr& part)
{
  // Создадим новый эскиз
  IEntityPtr entitySketch(part->NewEntity(o3d_sketch), false/*AddRef*/);
  if (entitySketch)
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств эскиза
    ISketchDefinitionPtr sketchDefinition(IUnknownPtr(entitySketch->GetDefinition(), false/*AddRef*/));
    if (sketchDefinition)
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane(part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/);

      // Установка параметров эскиза
      sketchDefinition->SetPlane(basePlane); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if (sketchDefinition->BeginEdit())
      {
        // Введем новый эскиз - квадрат
        LineSeg(50, 50, -50, 50, 1);
        LineSeg(50, -50, -50, -50, 1);
        LineSeg(50, -50, 50, 50, 1);
        LineSeg(-50, -50, -50, 50, 1);
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }

      // Базовая операция выдавливания
      IEntityPtr entityExtrusion(part->NewEntity(o3d_bossExtrusion), false/*AddRef*/);
      if (entityExtrusion)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс базовой операции выдавливания
        IBossExtrusionDefinitionPtr baseExtrusionDefinition(IUnknownPtr(entityExtrusion->GetDefinition(), false/*AddRef*/));
        if (baseExtrusionDefinition)
        {
          baseExtrusionDefinition->SetDirectionType(dtNormal);  // Направление выдавливания ( dtNormal  - прямое направление,
          // dtReverse - обратное направление, dtBoth - в обе стороны,
          // dtMiddlePlane - от средней плоскости )
// Изменить параметры выдавливания в одном направлении
          baseExtrusionDefinition->SetSideParam(true,    // Направление выдавливания ( TRUE - прямое направление, FALSE - обратное направление )
                                                etBlind, // Тип выдавливания ( etBlind - строго на глубину,
                                                // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                    // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на расстояние до поверхности,
                                                  // etUpToSurfaceFrom  - на расстояние за поверхность, etUpToNearSurface - до ближайшей поверхности )
                                                20,      // Глубина выдавливания
                                                30,      // Угол уклона 
                                                false); // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
          // Изменить параметры тонкой стенки элемента
          baseExtrusionDefinition->SetThinParam(true,   // Признак тонкостенной операции 
                                                dtBoth, // Направление построения тонкой стенки ( dtNormal - прямое направление,
                                                // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                // dtMiddlePlane - от средней плоскости )
                                                10,     // Толщина стенки в прямом направлении
                                                10);   // Толщина стенки в обратном направлении  
          baseExtrusionDefinition->SetSketch(entitySketch); // Эскиз операции выдавливания
          entityExtrusion->Create(); // Создать операцию выдавливания
        }
      }
    }

    // Плоскость через три вершины
    // Формирует массив объектов и возвращает указатель на его интерфейс - массив вершин компонента
    IEntityCollectionPtr entityCollection(part->EntityCollection(o3d_vertex), false/*AddRef*/);
    if ((bool)entityCollection && entityCollection->GetCount() > 2)
    {
      // Создадим плоскость, проходящюю через три вершины
      IEntityPtr entityPlane3Point(part->NewEntity(o3d_plane3Points), false/*AddRef*/);
      if (entityPlane3Point)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс плоскости, проходящей через три вершины
        IPlane3PointsDefinitionPtr plane3PointDefinition(IUnknownPtr(entityPlane3Point->GetDefinition(), false/*AddRef*/));
        if (plane3PointDefinition)
        {
          // Изменить указатель на интерфейс точки с указанным номером
          plane3PointDefinition->SetPoint(1,                                    // Номер точки (от 1 до 3)
                                          IEntityPtr(entityCollection->GetByIndex(0), false/*AddRef*/));  // Указатель на интерфейс точки
          plane3PointDefinition->SetPoint(2, IEntityPtr(entityCollection->GetByIndex(1), false/*AddRef*/));
          plane3PointDefinition->SetPoint(3, IEntityPtr(entityCollection->GetByIndex(2), false/*AddRef*/));
          entityPlane3Point->Create(); // Создать плоскость, проходящюю через три вершины
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Создание смещенной плоскости, оси по двум плоскостям и плоскости под углом к заданной
// ---
void ConstrElem(IPartPtr& part)
{
  // Создадим смещенную плоскость
  IEntityPtr entityPlaneOffset(part->NewEntity(o3d_planeOffset), false/*AddRef*/);
  if (entityPlaneOffset)
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    // Интерфейс свойств смещенной плоскости
    IPlaneOffsetDefinitionPtr planeOffsetDefinition(IUnknownPtr(entityPlaneOffset->GetDefinition(), false/*AddRef*/));
    if (planeOffsetDefinition)
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition->SetOffset(150); // Расстояние от базовой плоскости

      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane(part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/);

      basePlane->SetName(_bstr_t(_T("XOX")));         // Название для базовой плоскости

      basePlane->Update();                          // Обновить параметры базовой плоскости

      planeOffsetDefinition->SetPlane(basePlane); // Установим плоскость XOY базовой для плоскости

      planeOffsetDefinition->SetDirection(false); // Направление смещения от базовой плоскости ( TRUE - прямое направление, FALSE - обратное направление )
      entityPlaneOffset->SetName(_bstr_t(_T("Смещенная плоскость"))); // Имя для смещенной плоскости

      entityPlaneOffset->Create(); // Создать смещенную плоскость

      MessageT(_T("Изменим параметры смещенной плоскости"));
      planeOffsetDefinition->SetOffset(50); // Изменим расстояние до базовой плоскости
      // Возьмем другую базовую плоскость YOZ
      basePlane.Attach(part->GetDefaultEntity(o3d_planeYOZ));
      basePlane->SetName(_bstr_t(_T("YOZ")));   // Название для базовой плоскости
      basePlane->Update();                    // Обновить параметры базовой плоскости

      planeOffsetDefinition->SetPlane(basePlane); // Установим плоскость YOZ базовой для плоскости
      planeOffsetDefinition->SetDirection(true);  // Изменим направления смещения относительно базовой плоскости

      entityPlaneOffset->Update(); // Обновить параметры смещенной плоскости

      MessageT(_T("На пересечении плоскостей построим ось"));

      // Возьмем другую базовую плоскость XOY
      basePlane.Attach(part->GetDefaultEntity(o3d_planeXOY));
      basePlane->SetName(_bstr_t(_T("XOY"))); // Название для базовой плоскости
      basePlane->Update(); // Обновить параметры базовой плоскости

      // Ось на пересечении двух плоскостей
      IEntityPtr entityAxis2Planes(part->NewEntity(o3d_axis2Planes), false/*AddRef*/);
      if (entityAxis2Planes)
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        // Интерфейс вспомогательной оси, проходящей через две плоскости
        IAxis2PlanesDefinitionPtr axis2PlanesDefinition(IUnknownPtr(entityAxis2Planes->GetDefinition(), false/*AddRef*/));
        if (axis2PlanesDefinition)
        {
          axis2PlanesDefinition->SetPlane(1, entityPlaneOffset); // Первая базовая плоскость - смещенная плоскость
          axis2PlanesDefinition->SetPlane(2, basePlane);         // Вторая базовая плоскость - плоскость XOY
          entityAxis2Planes->SetName(_bstr_t(_T("Ось по двум плоскостям"))); // Имя вспомогательной оси
          entityAxis2Planes->Create();  // Создать ось, проходящюю через две плоскости 

          MessageT(_T("Поменяем одну из базовых плоскостей для построения оси"));

          // Возьмем другую базовую плоскость XOZ
          basePlane.Attach(part->GetDefaultEntity(o3d_planeXOZ));
          basePlane->SetName(_bstr_t(_T("XOZ"))); // Название для базовой плоскости
          basePlane->Update(); // Обновить параметры базовой плоскости

          axis2PlanesDefinition->SetPlane(2, basePlane); // Вторая базовая плоскость - плоскость XOZ
          entityAxis2Planes->Update(); // Обновить параметры вспомогательной оси

          MessageT(_T("Через смещенную плоскость и построенную ось\nпроведем плоскость под углом 45"));

          // Создадим плоскость под углом к другой плоскости
          IEntityPtr entityPlaneAngle(part->NewEntity(o3d_planeAngle), false/*AddRef*/);
          if (entityPlaneAngle)
          {
            // Получить указатель на интерфейс параметров объектов и элементов
            // Интерфейс плоскости под углом к другой плоскости
            IPlaneAngleDefinitionPtr planeAngleDefinition(IUnknownPtr(entityPlaneAngle->GetDefinition(), false/*AddRef*/));
            if (planeAngleDefinition)
            {
              planeAngleDefinition->SetAngle(45); // Угол наклона к базовой плоскости
              planeAngleDefinition->SetPlane(entityPlaneOffset); // Базовая плоскость - смещенная плоскость
              planeAngleDefinition->SetAxis(entityAxis2Planes);  // Базовая ось - ось, проходящей через две плоскости 
              entityPlaneAngle->SetName(_bstr_t(_T("Плоскость под углом к другой плоскости")));  // Имя вспомогательной плоскости
              entityPlaneAngle->Create();                          // Создать плоскость под углом к другой плоскости

              MessageT(_T("Изменим одну из базовых плоскостей"));

              planeAngleDefinition->SetPlane(basePlane); // Установим плоскость XOZ базовой для плоскости
              entityPlaneAngle->Update(); // Обновить параметры вспомогательной плоскости
            }
          }
        }
      }
    }
  }
}