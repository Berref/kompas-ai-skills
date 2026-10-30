//////////////////////////////////////////////////////////////////////////////// 
// 
// Step8_API7.cpp - Работа с атрибутами(API7)
// 
// 1.  Создать тип атрибута                      - FuncTypeAttr 
// 2.  Удалить тип атрибута                      - DelTypeAttr  
// 3.  Получить тип атрибута                     - ShowTypeAttr 
// 4.  Заменить тип атрибута                     - ChangeType  
// 5.  Создать атрибут определенного типа        - NewAttr  
// 6.  Удалить атрибут                           - DelObjAttr  
// 7.  Считать атрибут                           - ReadObjAttr  
// 8.  Просмотреть атрибут                       - ShowObjAttr   
// 9.  Просмотреть библиотеку                    - ShowLib   
// 10. Просмотреть тип                           - ShowType   
// 11. Просмотреть атрибут                       - WalkFromObjWithAttr   
// 12. Создать атрибут документа                 - CreateDocumentAttr  
// 13. Удалить атрибут документа                 - DeleteDocumentAttr
// 14. Просмотреть атрибут документа             - ShowDocumentAttr 
// 15. Создать атрибут 3D документа              - CreateDocument3DAttr 
// 16. Удалить атрибут 3D документа              - DeleteDocument3DAttr 
// 17. Просмотреть атрибут документа             - ShowDocument3DAttr 
// 18. Просмотреть атрибут объектов 3D документа - ShowObjects3DAttr 
// 
//////////////////////////////////////////////////////////////////////////////// 
#include "stdafx.h"
#include <afxdllx.h> 
#include "resource.h"
#include <vector>
#include <string>
#include <SafeArrayUtils.h>

#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#ifndef __LHEAD3D_H
#include "LHead3d.h"
#endif   

#ifndef __IUPTR_H
#include <iuptr.h>
#endif

#include <comdef.h>

#include "Step8_API7.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void FuncTypeAttr();
void DelTypeAttr();
void NewAttr();
void ShowTypeAttr();
void DelObjAttr();
void ReadObjAttr();
void ShowObjAttr();
void ShowLib();
void ShowType();
void WalkFromObjWithAttr();
void CreateDocumentAttr();
void DeleteDocumentAttr();
void ShowDocumentAttr();
void CreateDocument3DAttr();
void DeleteDocument3DAttr();
void ShowDocument3DAttr();
void ShowObjects3DAttr();

//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE Step8_API7DLL = { NULL, NULL };

//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}

//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void FuncTypeAttr();
void DelTypeAttr();
void ChangeType();
void NewAttr();
void ShowTypeAttr();
void DelObjAttr();
void ReadObjAttr();
void ShowObjAttr();
void ShowLib();
void ShowType();
void WalkFromObjWithAttr();
void CreateDocumentAttr();
void DeleteDocumentAttr();
void ShowDocumentAttr();
void CreateDocument3DAttr();
void DeleteDocument3DAttr();
void ShowDocument3DAttr();
void ShowObjects3DAttr();


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE Step8_API7_2DDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
ksAPI7::IApplicationPtr newKompasAPI(NULL);

void OnProcessDetach();                            // Отключение библиотеки



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
    TRACE0("STEP8_API7_2D.AWX Initializing!\n");

    AfxInitExtensionModule(Step8_API7DLL, hInstance);

    new CDynLinkLibrary(Step8_API7DLL);
  }
  else if (dwReason == DLL_PROCESS_DETACH)
  {
    TRACE0("STEP8_API7_2D.AWX Terminating!\n");
    OnProcessDetach();
    AfxTermExtensionModule(Step8_API7DLL);
  }
  return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI()
{
  if (!(ksAPI7::IApplication*)newKompasAPI)
  {
    CString filename;

    if (::GetModuleFileName(NULL, filename.GetBuffer(255), 255))
    {
      filename.ReleaseBuffer(255);
      CString libname;

      libname = LoadStr(IDR_API7);    // kAPI7.dll
      filename.Replace(filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)),
                       libname);

      HINSTANCE hAppAuto = LoadLibrary(filename); // идентификатор kAPI7.dll

      if (hAppAuto)
      {
        // Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH(WINAPI* FCreateKompasApplication)();

        FCreateKompasApplication pCreateKompasApplication =
          (FCreateKompasApplication)GetProcAddress(hAppAuto, "CreateKompasApplication");

        if (pCreateKompasApplication)
          newKompasAPI = IDispatchPtr(pCreateKompasApplication(), false /*AddRef*/); // Получаем интерфейс Application
        FreeLibrary(hAppAuto);
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY(unsigned int comm)
{
  if (!newKompasAPI)
    GetNewKompasAPI();

  ksAPI7::IKompasDocumentPtr doc = nullptr;
  if (newKompasAPI)
    doc = newKompasAPI->ActiveDocument;

  DocumentTypeEnum docType = doc ? doc->DocumentType : ksDocumentUnknown;

  switch (docType)
  {
    case ksDocumentUnknown:         // Нет документа (работаем с библиотекой атрибутов) 
    case ksDocumentDrawing:         // Чертеж.
    case ksDocumentFragment:        // Фрагмент.
    case ksDocumentSpecification:   // Спецификация.
    case ksDocumentTextual:         // Текстовый документ
    case ksDocumentPart:            // Деталь.
    case ksDocumentAssembly:        // Сборка.

      switch (comm)
      {
        case 1: FuncTypeAttr();        break; // Создать тип атрибута
        case 2: DelTypeAttr();         break; // Удалить тип атрибута
        case 3: ShowTypeAttr();        break; // Получить тип атрибута
        case 5: NewAttr();             break; // Создать атрибут определенного типа
        case 6: DelObjAttr();          break; // Удалить атрибут
        case 7: ReadObjAttr();         break; // Считать атрибут
        case 8: ShowObjAttr();         break; // Просмотреть атрибут
        case 9: ShowLib();             break; // Просмотреть библиотеку
        case 10: ShowType();            break; // Просмотреть тип
        case 11: WalkFromObjWithAttr(); break; // Просмотреть атрибут
        case 12: CreateDocumentAttr();  break; // Создать атрибут документа 
        case 13: DeleteDocumentAttr();  break; // Удалить атрибут документа
        case 14: ShowDocumentAttr();    break; // Просмотреть атрибут документа
        case 15: CreateDocument3DAttr(); break; // Создать атрибут 3D документа
        case 16: DeleteDocument3DAttr(); break; // Удалить атрибут 3D документа
        case 17: ShowDocument3DAttr();  break; // Просмотреть атрибут документа
        case 18: ShowObjects3DAttr();   break; // Просмотреть атрибут объектов 3D документа
      }
  }
}

//-------------------------------------------------------------------------------
// Функция для отображения колонки
// ---
void ShowColumn(ksAPI7::IColumnInfoPtr column, size_t i)
{
  if (column)
  {
    TCHAR buf[255];

    // Выдадим информацию о колонке
    _stprintf_s(buf, column->ColType == ksValueTypeRecord ?
                _T("RECORD, i = %d, header = %s,\ntype = %d, def = %s, listValue = %d") :
                _T("i = %ld, header = %s,\ntype = %ld, def = %s, listValue = %d"),
                i, column->Caption.GetBSTR(), column->ColType, column->DefValue, column->ListValue);
    MessageT(buf);

    for (size_t idx = 0, recCount = column->RecordColumnsCount; idx < recCount; idx++)
    {
      ksAPI7::IColumnInfoPtr recCol = column->GetRecordColumnInfo(idx);
      if (recCol)
        ShowColumn(recCol, idx);
    }
  }
}

enum documentType
{
  document3D,
  document2D,
  allDocuments
};

ksAPI7::ISelectionManagerPtr GetSelectionManager(documentType type)
{
  ksAPI7::ISelectionManagerPtr res = nullptr;

  if (!newKompasAPI)
    return res;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;

  if (doc)
  {
    ksAPI7::IKompasDocument2D1Ptr doc2D1(doc);

    if ((type == document2D || type == allDocuments) && doc2D1)
      res = doc2D1->SelectionManager;
    else if ((type == document3D || type == allDocuments))
    {
      ksAPI7::IKompasDocument3DPtr doc3D(doc);
      if (doc3D)
        res = doc3D->SelectionManager;
    }
  }

  return res;
}

ksAPI7::IChooseManagerPtr GetChooseManager(documentType type)
{
  ksAPI7::IChooseManagerPtr res = nullptr;

  if (!newKompasAPI)
    return res;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;

  if (doc)
  {
    ksAPI7::IKompasDocument2D1Ptr doc2D1(doc);

    if ((type == document2D || type == allDocuments) && doc2D1)
      res = doc2D1->ChooseManager;
    else if ((type == document3D || type == allDocuments))
    {
      ksAPI7::IKompasDocument3DPtr doc3D(doc);
      if (doc3D)
        res = doc3D->ChooseManager;
    }
  }

  return res;
}



//-------------------------------------------------------------------------------
// Создать тип атрибута
// ---
void FuncTypeAttr()
{
  TCHAR nameFile[255] = _T("");

  // Запросить имя библиотеки
  ksChoiceFileT(_T("*.lat"), nullptr, nameFile, 255, 0);
  ksAPI7::IAttrTypeMngPtr attrMng(newKompasAPI);

  if (!attrMng)  // если не выбрана библиотека 
    return;

  ksAPI7::IAttributeTypePtr attrType = attrMng->CreateAttrType(nameFile[0] ? _variant_t(nameFile) : _variant_t(newKompasAPI->ActiveDocument) );

  if (attrType)
  {
    attrType->TypeName = _T("int_struct_string");
    ksAPI7::IColumnInfoPtr columnInfo1 = attrType->AddColumn(0, ksValueTypeInteger, _T("int"));
    if (columnInfo1)
    {
      columnInfo1->Key = 0;
      columnInfo1->Caption = _T("int");
      columnInfo1->ColType = ksValueTypeInteger;
      columnInfo1->DefValue = _T("100");
      columnInfo1->ListValue = TRUE;

      _variant_t values;
      VariantInit(&values);

      PArray<_bstr_t> strArray;
      strArray.Add(new _bstr_t(L"100"));
      strArray.Add(new _bstr_t(L"200"));
      strArray.Add(new _bstr_t(L"300"));

      FillBSTRSafeArray(values, strArray);

      columnInfo1->Range = values;
    }

    ksAPI7::IColumnInfoPtr columnInfo2 = attrType->AddColumn(0, ksValueTypeRecord, _T("struct"));
    if (columnInfo2)
    {
      ksAPI7::IColumnInfoPtr structCol1 = columnInfo2->AddRecordColumn(0, ksValueTypeFloat, _T("double"));
      if (structCol1)
      {
        structCol1->Key = 0;
        structCol1->Caption = _T("double");
        structCol1->ColType = ksValueTypeFloat;
        structCol1->DefValue = _T("123456789");
        structCol1->ListValue = FALSE;
      }

      ksAPI7::IColumnInfoPtr structCol2 = columnInfo2->AddRecordColumn(0, ksValueTypeInteger, _T("long"));
      if (structCol2)
      {

        structCol2->Key = 0;
        structCol2->Caption = _T("long");
        structCol2->ColType = ksValueTypeInteger;
        structCol2->DefValue = _T("1000000");
        structCol2->ListValue = FALSE;
      }

      ksAPI7::IColumnInfoPtr structCol3 = columnInfo2->AddRecordColumn(0, ksValueTypeString, _T("TCHAR"));
      if (structCol3)
      {
        structCol3->Key = 0;
        structCol3->Caption = _T("TCHAR");
        structCol3->ColType = ksValueTypeString;
        structCol3->DefValue = _T("10");
        structCol3->ListValue = FALSE;
      }
    }

    ksAPI7::IColumnInfoPtr columnInfo3 = attrType->AddColumn(0, ksValueTypeRecord, _T("string"));
    if (columnInfo3)
    {
      columnInfo3->Key = 0;
      columnInfo3->Caption = _T("string");
      columnInfo3->ColType = ksValueTypeString;
      columnInfo3->DefValue = _T("text");
      columnInfo3->ListValue = FALSE;
    }

    attrType->RowsCount = 0;
    attrType->SetPassword(_T(""), _T(""));
    // key1, key2, key3 - Рекомендуется как код разработчика 
    // key4             - Системный код атрибута
    attrType->SetKeysInfo(10, 20, 30, 0);

    attrType->Update(_T(""));
  }
}


//-------------------------------------------------------------------------------
// Удалить тип атрибута
// ---
void DelTypeAttr()
{
  TCHAR nameFile[255] = _T("");
  // Запросить имя библиотеки
  ksChoiceFileT(_T("*.lat"), nullptr, nameFile, 255, 0);
  ksAPI7::IAttrTypeMngPtr attrMng(newKompasAPI);

  if (attrMng) // Если выбрана библиотека или есть документ
  {
    TCHAR password[255] = _T("");

    ksAPI7::IAttributeTypePtr attrType = attrMng->ChoiceAttrTypes(HandleToULong(GetHWindow()), nameFile[0] ? _variant_t(nameFile) : _variant_t(newKompasAPI->ActiveDocument));

    if (attrType && attrType->UniqueNumb > 1)
    {
      if (ReadStringT(_T("Ввести пароль типа атрибута"), password, 255))
      {
        if (!attrType->Delete(password))
          MessageBoxResult(); // Выдать сообщение об ошибке на экран
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Получить тип атрибута 
// ---
void ShowTypeAttr()
{
  TCHAR nameFile[255] = _T("");
  // Запросить имя библиотеки
  ksChoiceFileT(_T("*.lat"), NULL, nameFile, 255, 0);
  ksAPI7::IAttrTypeMngPtr attrMng(newKompasAPI);

  if (attrMng) // Если выбрана библиотека или есть документ 
  {
    ksAPI7::IAttributeTypePtr attrType = attrMng->ChoiceAttrTypes(HandleToULong(GetHWindow()), nameFile[0] ? _variant_t(nameFile) : _variant_t(newKompasAPI->ActiveDocument));

    if (attrType && attrType->UniqueNumb > 1)
    {
      long key1, key2, key3, key4 = 0;

      attrType->GetKeysInfo(&key1, &key2, &key3, &key4);

      TCHAR buf[500];
      _stprintf_s(buf, _T("key1 = %d, key2 = %d, key3 = %d, key4 = %d,\nheader = %s, rowsCount = %d"),
                  key1, key2, key3, key4, attrType->TypeName.GetBSTR(), attrType->RowsCount);
      MessageT(buf);

      for (size_t i = 0, colCount = attrType->ColumnsCount; i < colCount; i++)
      {
        ksAPI7::IColumnInfoPtr colInfo = attrType->GetColumnInfo(i);
        if (colInfo)
          ShowColumn(colInfo, i); // Функция для отображения колонки        
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Создание атрибута
// ---
void LibCreateAttr(_variant_t& objs)
{
  if (newKompasAPI)
  {
    TCHAR nameFile[255] = _T("");
    ksChoiceFileT(_T("*.lat"), NULL, nameFile, 255, 0);    // Запросить имя библиотеки

    ksAPI7::IKompasDocument1Ptr doc1(newKompasAPI->ActiveDocument);
    ksAPI7::IAttrTypeMngPtr attrMng(newKompasAPI);
    if (doc1 && attrMng)
    {
      ULONG hwnd = HandleToULong(GetHWindow());
      ksAPI7::IAttributeTypePtr attrType = attrMng->ChoiceAttrTypes(hwnd, nameFile[0] ? _variant_t(nameFile) : _variant_t(newKompasAPI->ActiveDocument));

      if (attrType)
      {
        ksAPI7::IAttributePtr attribute = doc1->CreateAttr(attrType->UniqueNumb, nameFile, objs);

        if (attribute)
        {
          attribute->SetPassword(_T(""), _T("111"));
          attribute->SetKeysInfo(_T("111"), 1, 10, 100, 0);
          attribute->ViewEdit(hwnd, _T("111"), FALSE);

          attrType->Update(_T("111"));
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Создать атрибут определенного типа
// ---
void NewAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocument1Ptr doc1 = newKompasAPI->ActiveDocument;
  if (!doc1)
  {
    MessageT(_T("Не возможно создать новый атрибут"));
    return;
  }

  ksAPI7::ISelectionManagerPtr selectionMng = GetSelectionManager(allDocuments);
  if (selectionMng)
    LibCreateAttr(selectionMng->SelectedObjects); // Создание атрибута
}


//-------------------------------------------------------------------------------
// Удалить атрибут
// ---
void DeleteAttributes(_variant_t& objs)
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocument1Ptr doc1(newKompasAPI->ActiveDocument);
  if (doc1)
  {
    _variant_t varAttributes = doc1->GetAttributes(0, 0, 0, 0, 0, objs);
    PArray<ksAPI7::IAttributePtr> attributes;
    FillObjects(varAttributes, attributes);

    for (size_t i = 0, count = attributes.Count(); i < count; i++)
    {
      ksAPI7::IAttributePtr attr(*attributes[i]);
      if (attr)
      {
        TCHAR password[255] = _T("");

        if (ReadStringT(_T("Ввести пароль типа атрибута"), password, 10))
        {
          // Удалить атрибут
          if (!attr->Delete(password, objs))
            MessageBoxResult(); // Выдать сообщение об ошибке на экран 
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Удалить атрибут
// ---
void DelObj2DAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::ISelectionManagerPtr selectionMng = GetSelectionManager(document2D);
  if (selectionMng)
    DeleteAttributes(selectionMng->SelectedObjects); // Удалить атрибут
}


//-------------------------------------------------------------------------------
// Удалить атрибут объекта 3D
// ---
void DelObj3DAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::ISelectionManagerPtr selectionMng = GetSelectionManager(document3D);
  if (selectionMng)
    DeleteAttributes(selectionMng->SelectedObjects); // Удалить атрибут
}


//-------------------------------------------------------------------------------
// Удалить атрибут
// ---
void DelObjAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;

  if (doc)
  {
    DocumentTypeEnum docType = doc->DocumentType; // тип документа

    switch (docType)
    {
      case ksDocumentDrawing:      // 1- Чертеж
      case ksDocumentFragment:     // 2- Фрагмент
        DelObj2DAttr();
        break;
      case ksDocumentPart:         // 4- Деталь
      case ksDocumentAssembly:     // 5- Сборка
        DelObj3DAttr();
        break;
    }
  }
}


//-------------------------------------------------------------------------------
// Считать атрибут
// ---
void ReadObjAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocument1Ptr doc1(newKompasAPI->ActiveDocument);
  if (doc1)
  {
    ksAPI7::ISelectionManagerPtr selectionMng = GetSelectionManager(document2D);

    if (selectionMng)
    {
      _variant_t varAttributes = doc1->GetAttributes(0, 0, 0, 0, 0, selectionMng->SelectedObjects);
      PArray<ksAPI7::IAttributePtr> attributes;
      FillObjects(varAttributes, attributes);

      for (size_t i = 0, count = attributes.Count(); i < count; i++)
      {
        ksAPI7::IAttributePtr attr(*attributes[i]);

        ksAPI7::IAttributeTypePtr attrType = attr ? attr->AttributeType : nullptr;
        if (attrType)
        {
          TCHAR buf[255];

          _variant_t varColsVisible = attr->GetFlagVisible();
          SArray<VARIANT_BOOL> colsVisible;
          CopyVariantToSArray(varColsVisible, colsVisible);

          long key1, key2, key3, key4;
          if (attrType->GetKeysInfo(&key1, &key2, &key3, &key4))
          {
            _stprintf_s(buf, _T("key1 = %d, key2 = %d, key3 = %d, key4 = %d, numbType = %f"), key1, key2, key3, key4, attrType->UniqueNumb);
            MessageT(buf);
          }

          size_t colsVisibleSize = colsVisible.Count();
          for (size_t i = 0, colCount = attrType->ColumnsCount; i < colCount; i++)
          {
            ksAPI7::IColumnInfoPtr colInfo = attrType->GetColumnInfo(i);
            if (colInfo)
            {
              bool flagVisible = false;
              if (i < colsVisibleSize)
                flagVisible = colsVisible[i];

              // Выдадим информацию о колонке                       
              _stprintf_s(buf, _T("i = %d, header = %s,\ntype = %d, def = %s, listValue = %d, visible = %d"),
                          i, colInfo->Caption.GetBSTR(), (long)colInfo->ColType, colInfo->DefValue, colInfo->ListValue, flagVisible);
              MessageT(buf);
            }
          }
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут
// ---
void ShowObj2DAttr()
{
  // Структура параметров запроса к системе
  RequestInfoT info;
  memset(&info, 0, sizeof(info));

  // Строка или идентификатор приглашения  
  info.prompt = _T("Укажите объект");

  // Координаты точки ввода  
  double x, y;

  // Интерактивный ввод точки или команды
  if (CursorExT(&info, &x, &y, NULL, NULL))
  {
    // Найти ближайший к заданной точке объект вида
    reference rObject = FindObj(x, y,  // Координаты точки
                                1e6); // Размер стороны квадрата-ловушки с центром в точке x,y
    if (rObject)
    {
      // Подсветить полученный объект
      LightObj(rObject, 1);
      ChoiceAttr(rObject); // Вывести диалог просмотра атрибутов объекта
      LightObj(rObject, 0);
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут 3D объекта
// ---
void ShowObj3DAttr()
{
  ksAPI7::ISelectionManagerPtr selectionMng = GetSelectionManager(document3D);
  if (selectionMng)
  {
    _variant_t selObjs = selectionMng->SelectedObjects;
    if (selObjs.vt == VT_DISPATCH)
    {
      PArray<ksAPI7::IFeature7Ptr> features7;
      FillObjects(selObjs, features7);

      if (features7.Count() > 0)
      {
        IUEnv<IFeature> feature3D((IFeature*)ksTransferInterface(*features7[0], ksAPI3DCom, 0));

        ksChoiceAttr3D(feature3D.GetI());
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут
// ---
void ShowObjAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;
  if (doc)
  {
    DocumentTypeEnum docType = doc->DocumentType; // тип документа

    switch (docType)
    {
      case ksDocumentDrawing:      // 1- Чертеж
      case ksDocumentFragment:     // 2- Фрагмент
        ShowObj2DAttr();
        break;
      case ksDocumentPart:         // 4- Деталь
      case ksDocumentAssembly:     // 5- Сборка
        ShowObj3DAttr();
        break;
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть библиотеку 
// ---
void ShowLib()
{
  ksAPI7::IAttrTypeMngPtr attrTypeMng(newKompasAPI);
  if (!attrTypeMng)
    return;

  TCHAR nameFile[255] = _T("");

  // Запросить имя библиотеки
  if (!ksChoiceFileT(_T("*.lat"), nullptr, nameFile, 255, 0))
    nameFile[0] = _T('\0'); // Если библиотека не задана, то типы атрибутов берутся из документа   

  // Выдать диалог для просмотра в библиотеке атрибутов списка типов атрибутов и выбора нужного типа
  ksAPI7::IAttributeTypePtr attrType = attrTypeMng->ChoiceAttrTypes(HandleToULong(GetHWindow()), nameFile[0] ? _variant_t(nameFile) : _variant_t(newKompasAPI->ActiveDocument));
  double numbType = attrType ? attrType->UniqueNumb : 0.0;

  if (numbType > 1)
  {
    TCHAR buf[255];
    _stprintf_s(buf, _T("numbType = %f"), numbType);
    MessageT(buf);
  }
}


//-------------------------------------------------------------------------------
// Просмотреть тип
// ---
void ShowType()
{
  ksAPI7::IAttrTypeMngPtr mng(newKompasAPI);

  if (!mng)
    return;

  TCHAR nameFile[255] = _T("");

  // Запросить имя библиотеки
  ksChoiceFileT(_T("*.lat"), NULL, nameFile, 255, 0);

  ksAPI7::IAttributeTypePtr attrType = mng->ChoiceAttrTypes(HandleToULong(GetHWindow()), nameFile[0] ? _variant_t(nameFile) : _variant_t(newKompasAPI->ActiveDocument));
  if (attrType && attrType->UniqueNumb > 1000)
  {
    TCHAR password[255] = _T("");
    if (ReadStringT(_T("Ввести пароль типа атрибута"), password, 255))
    {
      attrType->ViewEdit(HandleToULong(GetHWindow()), password, 2);
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут 3D объекта
// ---
void WalkFromObj3DWithAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocument1Ptr doc1(newKompasAPI->ActiveDocument);
  if (doc1)
  {
    ksAPI7::ISelectionManagerPtr selectionManager = GetSelectionManager(document3D);
    if (selectionManager)
    {
      _variant_t varAttributes = doc1->GetAttributes(0, 0, 0, 0, 0, selectionManager->SelectedObjects);
      PArray<ksAPI7::IAttributePtr> attributes;
      FillObjects(varAttributes, attributes);

      TCHAR buf[255];
      _stprintf_s(buf, _T("Количество атрибутов=%i"), attributes.Count());
      MessageT(buf);

      for (size_t i = 0, count = attributes.Count(); i < count; i++)
      {
        ksAPI7::IAttributePtr attr(*attributes[i]);
        if (attr)
        {
          TCHAR password[255] = _T("");
          if (ReadStringT(_T("Ввести пароль типа атрибута"), password, 255))
          {
            ksAPI7::IChooseManagerPtr chooseManager = GetChooseManager(document3D);
            if (chooseManager)
            {
              chooseManager->Choose(attr->Objects);

              attr->ViewEdit(HandleToULong(GetHWindow()), password, FALSE);

              if (YesNoT(_T("Удалить атрибут?")) == 1)
                attr->Delete(password, varAttributes);

              chooseManager->UnchooseAll();
            }
          }
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут
// ---
void WalkFromObj2DWithAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocument1Ptr doc1 = newKompasAPI->ActiveDocument;
  if (doc1)
  {
    ksAPI7::ISelectionManagerPtr selectionManager = GetSelectionManager(document2D);
    if (selectionManager)
    {
      _variant_t varAttributes = doc1->GetAttributes(10, 0, 0, 0, 0, selectionManager->SelectedObjects);
      PArray<ksAPI7::IAttributePtr> attributes;
      FillObjects(varAttributes, attributes);

      for (size_t i = 0, varCount = attributes.Count(); i < varCount; i++)
      {
        ksAPI7::IAttributePtr attr(*attributes[i]);
        if (attr)
          attr->ViewEdit(HandleToULong(GetHWindow()), _T(""), FALSE);
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут
// ---
void WalkFromObjWithAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;
  if (doc)
  {
    DocumentTypeEnum docType = doc->DocumentType; // тип документа

    switch (docType)
    {
      case ksDocumentDrawing:      // 1- Чертеж
      case ksDocumentFragment:     // 2- Фрагмент
        WalkFromObj2DWithAttr();
        break;
      case ksDocumentPart:         // 4- Деталь
      case ksDocumentAssembly:     // 5- Сборка
        WalkFromObj3DWithAttr();
        break;
    }
  }
}


//-------------------------------------------------------------------------------
// Создать атрибут документа
// ---
void CreateDocumentAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;
  if (doc)
  {
    _variant_t varDoc(doc, true);
    LibCreateAttr(varDoc);
  }
}


//-------------------------------------------------------------------------------
// Удалить атрибуты документа
// ---
void DeleteDocumentAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;
  if (doc)
  {
    _variant_t varDoc(doc, true);
    DeleteAttributes(varDoc);
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут документа
// ---
void ShowDocumentAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;
  if (doc)
    ChoiceAttr(doc->Reference);
}


//-------------------------------------------------------------------------------
// Создать атрибут документа
// ---
void CreateDocument3DAttr() // Создать атрибут 3D документа
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;
  DocumentTypeEnum docType = doc ? doc->DocumentType : ksDocumentUnknown;

  if (docType == ksDocumentPart || docType == ksDocumentAssembly)
  {
    _variant_t varDoc(doc, true);
    LibCreateAttr(varDoc);
  }
}


//-------------------------------------------------------------------------------
// Удалитьть атрибут 3D документа
// ---
void DeleteDocument3DAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;
  DocumentTypeEnum docType = doc ? doc->DocumentType : ksDocumentUnknown;

  if (docType == ksDocumentPart || docType == ksDocumentAssembly)
  {
    ksAPI7::IKompasDocument1Ptr doc1(doc);

    if (doc1)
    {
      _variant_t varDoc(doc, true);
      _variant_t varAttributes = doc1->GetAttributes(0, 0, 0, 0, 0, varDoc);
      PArray<ksAPI7::IAttributePtr> attributeColl;

      FillObjects(varAttributes, attributeColl);

      size_t attributesCount = attributeColl.Count();
      size_t delAttr = 0;

      TCHAR buf[255];
      _stprintf_s(buf, _T("Количество атрибутов=%i"), attributesCount);
      MessageT(buf);

      for (size_t i = 0; i < attributesCount; i++)
      {
        ksAPI7::IAttributePtr attr(*attributeColl[i]);
        if (attr)
        {
          TCHAR password[255] = _T("");
          if (ReadStringT(_T("Ввести пароль типа атрибута"), password, 255))
          {
            // Просмотр атрибутов
            attr->ViewEdit(HandleToULong(GetHWindow()), password, TRUE);

            // Удаление атрибутов
            if (YesNoT(_T("Удалить атрибут?")) == 1)
            {
              if (attr->Delete(password, varDoc))
                delAttr++;
            }
          }
        }
      }

      _stprintf_s(buf, _T("Осталось атрибутов=%i"), attributesCount - delAttr);
      MessageT(buf);
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут документа
// ---
void ShowDocument3DAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;

  if (doc && doc->DocumentType == ksDocumentPart || doc->DocumentType == ksDocumentAssembly)
  {
    ksChoiceAttr3D(nullptr);
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибуты документа и детали сборки
// ---
void ShowObjects3DAttr()
{
  if (!newKompasAPI)
    return;

  ksAPI7::IKompasDocumentPtr doc = newKompasAPI->ActiveDocument;
  DocumentTypeEnum docType = doc ? doc->DocumentType : ksDocumentUnknown;

  if (docType == ksDocumentAssembly || docType == ksDocumentPart)
  {
    IUEnv<IDocument3D> doc3D(ksGetActive3dDocument());
    if (doc3D)
    {
      // атрибуты документа
      IUEnv<IFeatureCollection> fColl(doc3D->FeatureCollection(0, 0, 0, 0, 0, o3d_unknown));
      if (fColl)
        ksChoiceAttr3D(fColl.GetI());                     // Просмотр атрибутов документа
    }
    if (docType == ksDocumentAssembly)
    {
      IUEnv<IPart> part0(doc3D->GetPart(0));              // Первая деталь
      if (part0)
      {
        IUEnv<IFeature> iFeatureP0(part0->GetFeature()); // Лист первой детали
        if (iFeatureP0)
        {
          // Листы элеменов детали
          IUEnv<IFeatureCollection> fCollP0(iFeatureP0->SubFeatureCollection(true, true));
          if (fCollP0)
            ksChoiceAttr3D(fCollP0.GetI());               // Просмотр атрибутов
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
  newKompasAPI = nullptr;
}

//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
CString LoadStr(int strID)
{
  TCHAR temp[_MAX_PATH];
  LoadString(Step8_API7DLL.hModule, strID, temp, _MAX_PATH);
  return temp;
}
