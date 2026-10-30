//////////////////////////////////////////////////////////////////////////////// 
// 
// step3d2.cpp - Работа с компонентой
// 
// 1.  Создание документа                                            - CreateDocument3D 
// 2.  Итератор по документам                                        - DocIterator 
// 3.  Использование массива элементов                               - UseEntityCollection 
// 4.  Взять/изменить имя компоненты                                 - GetSetPartName 
// 5.  Фиксирование и установка стандартного объекта                 - FixAndStandartComponent 
// 6.  Получить и заменить параметры цвета компоненты                - GetSetColorProperty 
// 7.  Взять и поменять внешние переменные компоненты                - GetSetArrayVariable 
// 8.  Получить и изменить место расположения детали в сборке        - GetSetPlacmentComponent 
// 9.  Получить интерфейс ksEntity объекта создаваемого системой 
//     по умолчанию и поменять параметры                             - GetSetEntity 
// 10. Создать эскиз                                                 - CreateSketch 
// 11. Формирует массив объектов( здесь эскизов ) и возвращает его 
//     интерфейс ksEntityCollection( IEntityCollection )             - GetArraySketch 
// 12. Установить и получить параметры пользователя в компоненте     - GetSetUserParamComponent 
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
// Ресурсы ( имя библиотеки, состав меню, слайд ) находятся в <res\step3d2.rc2> , идентификаторы в <step3d2.rh> 
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void CreateDocument3D();
void DocIterator();
void UseEntityCollection();
void GetSetPartName(IDocument3DPtr& pDocument3d);
void FixAndStandartComponent(IDocument3DPtr& pDocument3d);
void GetSetColorProperty(IDocument3DPtr& pDocument3d);
void GetSetArrayVariable(IDocument3DPtr& pDocument3d);
void GetSetPlacmentComponent(IDocument3DPtr& pDocument3d);
void GetSetEntity(IDocument3DPtr& pDocument3d);
void CreateSketch(IDocument3DPtr& pDocument3d);
void GetArraySketch(IDocument3DPtr& pDocument3d);
void GetSetUserParamComponent(IDocument3DPtr& pDocument3d);


//------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY(UINT comm)
{
  switch (comm)
  {
    case 10:  CreateDocument3D();     break;  // Создание документа
    case 11:  DocIterator();          break;  // Итератор по документам
    case 12:  UseEntityCollection();  break;  // Использование массива элементов
    default:
    {
      IDocument3DPtr document3d(ksGetActive3dDocument(), false /*Addref*/); // Получить указатель на активный документ трехмерной модели
      if (document3d)
      {
        switch (comm)
        {
          case 1: GetSetPartName(document3d); break; // Взять/изменить имя компоненты
          case 2: FixAndStandartComponent(document3d); break; // Фиксирование и установка стандартного объекта
          case 3: GetSetColorProperty(document3d); break; // Получить и заменить параметры цвета компоненты
          case 4: GetSetArrayVariable(document3d); break; // Взять и поменять внешние переменные компоненты
          case 5: GetSetPlacmentComponent(document3d); break; // Получить и изменить место расположения детали в сборке
          case 6: GetSetEntity(document3d); break; // Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
          case 7: CreateSketch(document3d); break; // Создать эскиз
          case 8: GetArraySketch(document3d); break; // Формирует массив объектов( здесь эскизов ) и возвращает его интерфейс ksEntityCollection( IEntityCollection )
          case 9: GetSetUserParamComponent(document3d); break; // Установить и получить параметры пользователя в компоненте
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
  }
}


//-------------------------------------------------------------------------------
// Создание документа 3D
// ---
void CreateDocument3D()
{
  // Получить указатель на объект документа трехмерной модели
  IDocument3DPtr pDocument3d(ksGet3dDocument(), false/*AddRef*/);
  if (pDocument3d)
  {
    if (pDocument3d->Create(false,   // Признак режима редактирования документа ( TRUE - невидимый режим, FALSE - видимый режим )
                            true)) // Тип документа ( TRUE - деталь, FALSE - сборка ) 
    {
      pDocument3d->SetAuthor(_bstr_t(_T("Автор")));                // Автор документа
      pDocument3d->SetComment(_bstr_t(_T("Пример документа 3D"))); // Комментарии к документу
      pDocument3d->UpdateDocumentParam();                              // Обновить параметры документа
      pDocument3d->SaveAs(_bstr_t(_T("C:\\Example.m3d")));           // Сохранить документ
      MessageT(_T("Сохраним документ под другим именем"));
      pDocument3d->SaveAs(_bstr_t(_T("C:\\Example2.m3d")));        // Сохранить документ под другим именем

      TCHAR buf[255];

      // Автор документа
      CString author = pDocument3d->GetAuthor();
      _stprintf_s(buf, _T("Автор документа: %s"), author);
      MessageT(buf);

      // Комментарий к документу
      CString comment = pDocument3d->GetComment();
      _stprintf_s(buf, _T("Комментарий к документу: %s"), comment);
      MessageT(buf);

      // Имя файла
      CString fileName = pDocument3d->GetFileName();
      _stprintf_s(buf, _T("Имя файла: %s"), fileName);
      MessageT(buf);

      pDocument3d->Close(); // Закроем документ
    }
  }
}


//-------------------------------------------------------------------------------
// Открытие группы документов и создание итератора по ним
// ---
void DocIterator()
{
  // Динамический массив строк для имен файлов 
  reference rArDocFileName = CreateArray(CHAR_STR_ARR_T, 0);

  if (ksChoiceFilesT(_T("*.m3d"), _T("Документы ( *.m3d )|*.m3d|Сборки ( *.a3d )|*a3d|Все файлы ( *.* )|*.*|"), rArDocFileName, 1))
  {
    TCHAR buf[255];

    // Откроем все файлы указанные пользователем
    int docCount = GetArrayCount(rArDocFileName);
    for (int i = 0; i < docCount; i++)
    {
      if (GetArrayItem(rArDocFileName, i, buf, 255))
      {
        // Получить указатель на объект документа трехмерной модели
        IDocument3DPtr pDocument3d(ksGet3dDocument(), false /*AddRef*/);
        if (pDocument3d)
          // Открыть на редактирование документ-модель ( деталь или сборку )
          pDocument3d->Open(_bstr_t(buf), // Имя файла открываемого документа
                            false);        // Признак режима редактирования документа
        // ( TRUE – невидимый режим, FALSE - видимый режим )
      }
    }

    // Сообщаем количество открытых файлов    
    _stprintf_s(buf, _T("Открыто %d файлов"), docCount);
    MessageT(buf);

    // Итератор по 3D документам
    reference rIterator = CreateIterator(D3_DOCUMENT_OBJ, 0);
    if (rIterator)
    {
      reference rDocument = MoveIterator(rIterator, 'F'); // Смещаем итератор на первый элемент
      while (rDocument > 0)
      {
        IDocument3DPtr pDocument3d(ksGet3dDocumentFromReference(rDocument), false/*AddRef*/);
        if (pDocument3d)
        {
          // Автор документа
          CString author = pDocument3d->GetAuthor();
          _stprintf_s(buf, _T("Автор документа: %s"), author);
          MessageT(buf);

          // Комментарий к документу
          CString comment = pDocument3d->GetComment();
          _stprintf_s(buf, _T("Комментарий к документу: %s"), comment);
          MessageT(buf);

          // Имя файла
          CString fileName = pDocument3d->GetFileName();
          _stprintf_s(buf, _T("Имя файла: %s"), fileName);
          MessageT(buf);

          // Тип документа
          _stprintf_s(buf, _T("Тип документа: %s"), pDocument3d->IsDetail() ? _T("Деталь") : _T("Сборка"));
          MessageT(buf);

        }
        rDocument = MoveIterator(rIterator, 'N'); // Смещаем итератор на следующую позицию
      }
      DeleteIterator(rIterator); // Удалить итератор
    }
  }
}


//-------------------------------------------------------------------------------
// Использование массива элементов
// ---
void UseEntityCollection()
{
  IDocument3DPtr pDocument3d(ksGetActive3dDocument(), false/*AddRef*/); // Получить указатель на активный документ трехмерной модели
  if (pDocument3d)
  {
    // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
    // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
    IPartPtr part(pDocument3d->GetPart(pTop_Part), false/*AddRef*/);
    if (part)
    {
      TCHAR buf[255];

      // Формирует массив объектов и возвращает указатель на его интерфейс - массив поверхностей компонента
      IEntityCollectionPtr entityCollection(part->EntityCollection(o3d_face), false/*AddRef*/);
      if (entityCollection)
      {
        int countAllFace = entityCollection->GetCount(); // Объщее количество поверхностей
        int countPlane = 0;                               // Количество плоских поверхностей
        int countCone = 0;                               // Количество конических поверхностей
        for (int i = 0; i < countAllFace; i++)
        {
          IEntityPtr entityFace(entityCollection->GetByIndex(i), false/*AddRef*/); // Получить поверхность
          IColorParamPtr colorParam(entityFace->ColorParam(), false/*AddRef*/);       // Цвет поверхности

          // Получить указатель на интерфейс параметров объектов и элементов
          // Интерфейс свойств поверхности
          IFaceDefinitionPtr faceDefinition(IUnknownPtr(entityFace->GetDefinition(), false/*AddRef*/));
          if (faceDefinition)
          {
            if (faceDefinition->IsCone() ||    // Коническая плоскость 
                faceDefinition->IsCylinder()) // Цилиндрическая плоскость
            {
              colorParam->SetColor(RGB(255, 255, 0));
              countCone++; // Считаем количество конических поверхностей
            }

            if (faceDefinition->IsPlanar()) // Плоская плоскость 
            {
              colorParam->SetColor(RGB(0, 255, 255));
              countPlane++; // Считаем количество плоских поверхностей
            }
            entityFace->Update(); // Обновить параметры поверхности
          }
        }

        if (countAllFace == 0)
          MessageT(_T("Не найдено ни одной поверхности"));
        else
        {
          _stprintf_s(buf, _T("Найдено %i коничечких и %i плоских объектов"), countCone, countPlane);
          MessageT(buf);
        }
      }

      // Формирует массив объектов и возвращает указатель на его интерфейс - массив граней компонента
      IEntityCollectionPtr entityCollection2(part->EntityCollection(o3d_edge), false/*AddRef*/);
      if (entityCollection2)
      {
        int countAllEdge = entityCollection2->GetCount(); // Объщее количество ребер
        int countRectilinear = 0;                             // Количество прямых ребер
        int countCurvilinear = 0;                             // Количество криволинейных ребер
        for (int i = 0; i < countAllEdge; i++)
        {
          IEntityPtr entityEdge(entityCollection2->GetByIndex(i), false/*AddRef*/); // Получить ребро
          if (entityEdge)
          {
            // Получить указатель на интерфейс параметров объектов и элементов
            // Интерфейс свойств ребера
            IEdgeDefinitionPtr edgeDefinition(IUnknownPtr(entityEdge->GetDefinition(), false/*AddRef*/));
            if (edgeDefinition)
            {
              if (edgeDefinition->IsStraight())
                countRectilinear++; // Количество прямых ребер
              else
                countCurvilinear++; // Количество криволинейных ребер
            }
          }
        }

        if (countAllEdge == 0)
          MessageT(_T("Не найдено ни одного ребра"));
        else
        {
          _stprintf_s(buf, _T("Найдено %i прямых и %i криволинейных ребер"), countRectilinear, countCurvilinear);
          MessageT(buf);
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Взять/изменить имя детали или подсборки в составе сборки
// ---
void GetSetPartName(IDocument3DPtr& pDocument3d)
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(pTop_Part), false/*AddRef*/);
  if (part)
  {
    TCHAR buf[255];

    // Получить имя детали или подсборки в составе сборки
    CString str = part->GetName();
    _stprintf_s(buf, _T("Имя компоненты %s"), str);
    MessageT(buf);

    // Сменить имя детали или подсборки в составе сборки
    part->SetName(_bstr_t(_T("Новое имя компоненты")));
    part->Update(); // Обновить параметры компоненты
  }
}


//-------------------------------------------------------------------------------
// Фиксирование и установка стандартного объекта
// ---
void FixAndStandartComponent(IDocument3DPtr& pDocument3d)
{
  if (pDocument3d->IsDetail()) // Определить, является ли модель деталью
  {
    ErrorT(_T("Текущий документ должен быть сборкой"));
    return;
  }

  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(0), false/*AddRef*/); // Первая деталь в сборке
  if (part)
  {
    // Получить состояние фиксации компонента ( Если компонент зафиксирован, то нельзя изменить его местоположение )
    int fixedComponent = part->GetFixedComponent();
    MessageT(fixedComponent ? _T("Компонент зафиксирован") : _T("Компонент не зафиксирован"));

    // Получить состояние стандартного компонента ( Не имеет Дерева построения )
    int standardComponent = part->GetStandardComponent();
    MessageT(standardComponent ? _T("Компонент стандартный") : _T("Компонент нестандартный"));

    // Изменить состояние фиксации компонента ( Если компонент зафиксирован, то нельзя изменить его местоположение )
    part->SetFixedComponent(!fixedComponent);
    // Изменить состояние стандартного компонента ( Не имеет Дерева построения )
    part->SetStandardComponent(!standardComponent);
  }
}


//-------------------------------------------------------------------------------
// Взять/изменить параметры цвета компоненты
// ---
void GetSetColorProperty(IDocument3DPtr& pDocument3d)
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(pTop_Part), false/*AddRef*/);
  if (part)
  {
    TCHAR buf[255];

    // Первый вариант  
    // Параметры цвета компонента
    IColorParamPtr colorParam(part->ColorParam(), false/*AddRef*/);
    if (colorParam)
    {
      _stprintf_s(buf, _T("Цвет = %d, общий цвет = %g,\nдиффузия = %g, зеркальность = %g,\nблеск = %g, прозрачность = %g,\nизлучение = %g"),
                  colorParam->GetColor(), colorParam->GetAmbient(),
                  colorParam->GetDiffuse(), colorParam->GetSpecularity(),
                  colorParam->GetShininess(), colorParam->GetTransparency(),
                  colorParam->GetEmission());
      MessageT(buf);

      // Изменение параметров цвета компонента
      colorParam->SetColor(5421504);
      colorParam->SetTransparency(0.5);
      colorParam->SetAmbient(0.1);
      colorParam->SetDiffuse(0.1);

      part->Update(); // Обновить параметры компоненты

      _stprintf_s(buf, _T("Цвет = %d, общий цвет = %g,\nдиффузия = %g, зеркальность = %g,\nблеск = %g, прозрачность = %g,\nизлучение = %g"),
                  colorParam->GetColor(), colorParam->GetAmbient(),
                  colorParam->GetDiffuse(), colorParam->GetSpecularity(),
                  colorParam->GetShininess(), colorParam->GetTransparency(),
                  colorParam->GetEmission());
      MessageT(buf);
    }

    // Второй вариант
    COLORREF color;      // Цвет
    double ambient,      // Общий цвет
      diffuse,      // Диффузия
      specularity,  // Зеркальность  
      shininess,    // Блеск
      transparency, // Прозрачность
      emission;     // Излучение  

    // Возвращает параметры цвета и визуальных свойств компонента 
    part->GetAdvancedColor(&color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission);
    _stprintf_s(buf, _T("Цвет = %d, общий цвет = %g,\nдиффузия = %g, зеркальность = %g,\nблеск = %g, прозрачность = %g,\nизлучение = %g"),
                color, ambient,
                diffuse, specularity,
                shininess, transparency,
                emission);
    MessageT(buf);

    // Изменение параметров цвета компонента
    color = 9421504;
    transparency = 0.5;
    ambient = 0.1;
    diffuse = 0.1;

    // Устанавливает параметры цвета и визуальных свойств компонента
    part->SetAdvancedColor(color, ambient, diffuse, specularity, shininess, transparency, emission);

    part->Update(); // Обновить параметры компоненты

    // Возвращает параметры цвета и визуальных свойств компонента 
    part->GetAdvancedColor(&color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission);
    _stprintf_s(buf, _T("Цвет = %d, общий цвет = %g,\nдиффузия = %g, зеркальность = %g,\nблеск = %g, прозрачность = %g,\nизлучение = %g"),
                color, ambient,
                diffuse, specularity,
                shininess, transparency,
                emission);
    MessageT(buf);
  }
}


//-------------------------------------------------------------------------------
// Взять/изменить внешние переменные компоненты
// ---
void GetSetArrayVariable(IDocument3DPtr& pDocument3d)
{
  if (pDocument3d->IsDetail()) // Определить, является ли модель деталью
  {
    ErrorT(_T("Текущий документ должен быть сборкой"));
    return;
  }

  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(0), false/*AddRef*/); // Первая деталь в сборке
  if (part)
  {
    // Работа с массивом внешних переменных
    IVariableCollectionPtr variableCollection(part->VariableCollection(), false/*AddRef*/);
    if (variableCollection)
    {
      // Количество внешних переменных в массиве
      int count = variableCollection->GetCount();
      for (int i = 0; i < count; i++)
      {
        // Получить переменную
        IVariablePtr variable(variableCollection->GetByIndex(i), false/*AddRef*/);
        if (variable)
        {
          if (i == 0)
          {
            // Сменить комментарий переменной
            variable->SetNote(_bstr_t(_T("Новое значение")));
            double d = 0;
            // Ввод переменной пользователем
            ReadDoubleT(_T("Введи переменную"), 10, 0, 100, &d);
            // Сменить значение переменной 
            variable->SetValue(d);
          }

          TCHAR buf[255];
          CString name(variable->GetName()); // Имя переменной
          CString note(variable->GetNote()); // Комментарий переменной
          _stprintf_s(buf, _T("Номер переменной : %d\nИмя переменной : %s\nЗначение переменной : %g\nКомментарий : %s"),
                      i, name, variable->GetValue(), note);
          MessageT(buf);
        }
      }
      // Перестраивает модель в соответствии с новыми значениями внешних переменных
      part->RebuildModel();
    }
  }
}


//-------------------------------------------------------------------------------
// Получить и изменить место расположения детали в сборке
// ---
void GetSetPlacmentComponent(IDocument3DPtr& pDocument3d)
{
  if (pDocument3d->IsDetail()) // Определить, является ли модель деталью
  {
    ErrorT(_T("Текущий документ должен быть сборкой"));
    return;
  }

  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(0), false/*AddRef*/); // Первая деталь в сборке
  if (part)
  {
    IPlacementPtr placement(part->GetPlacement(), false/*AddRef*/); // Получить указатель на интерфейс местоположения компонента
    if (placement)
    {
      double x, y, z;
      placement->GetOrigin(&x, &y, &z); // Получить координаты начала локальной системы координат

      TCHAR buf[255];
      _stprintf_s(buf, _T("x = %g\ny = %g\nz = %g"), x, y, z);
      MessageT(buf);
      placement->SetOrigin(20, 20, 20); // Изменить координаты начала локальной системы координат
      part->UpdatePlacement();            // Изменяет местоположение компонента, заданное методом SetPlacement
      part->Update();                     // Изменить свойства компонента (используя ранее установленные свойства)
    }
  }
}


//-------------------------------------------------------------------------------
// Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
// ---
void GetSetEntity(IDocument3DPtr& pDocument3d)
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(pTop_Part), false/*AddRef*/);
  if (part)
  {
    IEntityPtr entityPlane(part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/); // Получить указатель на интерфейс объекта,
    // создаваемого системой по умолчанию - плоскость XOY
    if (entityPlane)
    {
      CString name(entityPlane->GetName());   // Имя элемента трехмерной модели
      MessageT((LPTSTR)(LPCTSTR)name);

      entityPlane->SetName(_bstr_t(_T("Plane"))); // Установить новое имя элемента трехмерной модели
      entityPlane->Update(); // Изменить свойства объекта (используя ранее установленные свойства)
    }
  }
}


//-------------------------------------------------------------------------------
// Создание эскиза
// ---
void CreateSketch(IDocument3DPtr& pDocument3d)
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(pTop_Part), false/*AddRef*/);
  if (part)
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
        sketchDefinition->SetAngle(45);               // Угол поворота эскиза

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
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Формирует массив объектов ( эскизов ) и возвращает его интерфейс IEntityCollection
// ---
void GetArraySketch(IDocument3DPtr& pDocument3d)
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(pTop_Part), false/*AddRef*/);
  if (part)
  {
    // Формирует массив объектов и возвращает указатель на его интерфейс - массив эскизов компонента
    IEntityCollectionPtr entityCollection(part->EntityCollection(o3d_sketch), false/*AddRef*/);
    if (entityCollection)
    {
      // Получить количество элементов в массиве
      int count = entityCollection->GetCount();
      for (int i = 0; i < count; i++)
      {
        IEntityPtr currentEntity(entityCollection->GetByIndex(i), false/*AddRef*/); // Получить эскиз
        CString  name(currentEntity->GetName()); // Имя эскиза
        MessageT((LPTSTR)(LPCTSTR)name);
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Установить и получить параметры пользователя в компоненте
// ---
void GetSetUserParamComponent(IDocument3DPtr& pDocument3d)
{
  if (pDocument3d->IsDetail()) // Определить, является ли модель деталью
  {
    ErrorT(_T("Текущий документ должен быть сборкой"));
    return;
  }

  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  IPartPtr part(pDocument3d->GetPart(0), false/*AddRef*/); // Первая деталь в сборке
  if (part)
  {
    // Пользовательская структура
    struct UserParam
    {
      double d1;
      double d2;
      int    i1;
      int    i2;
    } param;

    param.d1 = 12.12;
    param.d2 = 21.21;
    param.i1 = 888;
    param.i2 = 999;

    // Установить параметры компонента, указанные пользователем
    part->SetUserParam(&param, sizeof(param), 0, 0, -1);
    part->Update(); // Изменить свойства компонента (используя ранее установленные свойства) 

    TCHAR buf[255];
    _stprintf_s(buf, _T("Размер пользовательской структуры %d"), part->GetUserParamSize()); // Размер пользовательской структуры
    MessageT(buf);

    part->GetUserParam(&param, sizeof(param)); // Возвращает пользовательские параметры, записанные в компоненте
    _stprintf_s(buf, _T("Переменные пользовательского массива\nd1 = %g\nd2 = %g\ni1 = %d\ni2 = %d"),
                param.d1, param.d2, param.i1, param.i2);
    MessageT(buf);
  }
}

