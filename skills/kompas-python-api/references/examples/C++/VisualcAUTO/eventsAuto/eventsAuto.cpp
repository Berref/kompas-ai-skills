////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h" 
#include "eventsAuto.h"  

#ifndef _APPLICATIONEVENT_H
#include "ApplicationEvent.h"
#endif

#ifndef _DOCUMENTEVENT_H
#include "DocumentEvent.h"
#endif

#ifndef _OBJECT2DEVENT_H
#include "Object2DEvent.h"
#endif

#ifndef _OBJECT3DEVENT_H
#include "Object3DEvent.h"
#endif

#ifndef _SELECTMNGEVENT_H
#include "SelectMngEvent.h"
#endif

#ifndef _STAMPEVENT_H
#include "StampEvent.h"
#endif

#ifndef _SPECIFICATIONEVENT_H
#include "SpecificationEvent.h"
#endif

#ifndef _SPCOBJECTEVENT_H
#include "SpcObjectEvent.h"
#endif

#ifndef _SPCDOCUMENTEVENT_H
#include "SpcDocumentEvent.h"
#endif

#ifndef _DOCUMENT3DEVENT_H
#include "Document3DEvent.h"
#endif

#ifndef _DOCUMENT2DEVENT_H
#include "Document2DEvent.h"
#endif

#ifndef _DLGCONFIG_H
#include "DlgConfig.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CeventsAutoApp, CWinApp)
  //{{AFX_MSG_MAP(CeventsAutoApp)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()


//-------------------------------------------------------------------------------
// 
// ---
CeventsAutoApp::CeventsAutoApp() :
  m_auto(false),
  m_mes_2DDOC(true),
  m_mes_3DDOC(true),
  m_mes_APP(true),
  m_mes_DOC(true),
  m_mes_OBJ_2DDOC(true),
  m_mes_OBJ_3DDOC(true),
  m_mes_OBJ_SPC(true),
  m_mes_SELECT(true),
  m_mes_SPC(true),
  m_mes_SPCDOC(true),
  m_mes_STAMP(true)
{
}


//-------------------------------------------------------------------------------
// 
// ---
int CeventsAutoApp::ExitInstance()
{
  m_iniFile.Reset();
  m_iniFile.SetValueI("Настройки теста EventAuto", "Автоподписка при загрузке                            ", m_auto);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий 2D документа          ", m_mes_2DDOC);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий 3D документа          ", m_mes_3DDOC);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий Компаса               ", m_mes_APP);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий документов            ", m_mes_DOC);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий объекта 2D документа  ", m_mes_OBJ_2DDOC);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий объекта 3D документа  ", m_mes_OBJ_3DDOC);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий объекта спецификации  ", m_mes_OBJ_SPC);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий селектирования        ", m_mes_SELECT);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий спецификации          ", m_mes_SPC);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий документа спецификации", m_mes_SPCDOC);
  m_iniFile.SetValueI("Настройки теста EventAuto", "Выдавать сообщения для событий штампа                ", m_mes_STAMP);
  m_iniFile.WriteFile();

  BaseEvent::TerminateEvents();
  return CWinApp::ExitInstance();
}


//-------------------------------------------------------------------------------
// 
// ---
BOOL CeventsAutoApp::InitInstance()
{
  TCHAR fileName[256];
  ::_tcscpy_s(fileName, _T("c:\\EventAuto.ini"));
  if (::GetModuleFileName(theApp.m_hInstance, fileName, 256))
  {
    TCHAR* buf = ::_tcsrchr(fileName, _T('\\'));
    if (buf)
    {
      *(buf + 1) = '\0';
      ::_tcscat_s(fileName, _T("EventAuto.ini"));
    }
  }
  m_iniFile.SetPath(fileName);
  m_iniFile.ReadFile();
  m_auto = m_iniFile.GetValueB("Настройки теста EventAuto", "Автоподписка при загрузке                            ", false);
  m_mes_2DDOC = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий 2D документа          ", true);
  m_mes_3DDOC = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий 3D документа          ", true);
  m_mes_APP = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий Компаса               ", true);
  m_mes_DOC = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий документов            ", true);
  m_mes_OBJ_2DDOC = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий объекта 2D документа  ", true);
  m_mes_OBJ_3DDOC = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий объекта 3D документа  ", true);
  m_mes_OBJ_SPC = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий объекта спецификации  ", true);
  m_mes_SELECT = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий селектирования        ", true);
  m_mes_SPC = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий спецификации          ", true);
  m_mes_SPCDOC = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий документа спецификации", true);
  m_mes_STAMP = m_iniFile.GetValueB("Настройки теста EventAuto", "Выдавать сообщения для событий штампа                ", true);

  return CWinApp::InitInstance();
}


//-------------------------------------------------------------------------------
// 
// ---
void CeventsAutoApp::ConfigDlg()
{
  DlgConfig dlg;

  dlg.m_auto = m_auto;
  dlg.m_mes_2DDOC = m_mes_2DDOC;
  dlg.m_mes_3DDOC = m_mes_3DDOC;
  dlg.m_mes_APP = m_mes_APP;
  dlg.m_mes_DOC = m_mes_DOC;
  dlg.m_mes_OBJ_2DDOC = m_mes_OBJ_2DDOC;
  dlg.m_mes_OBJ_3DDOC = m_mes_OBJ_3DDOC;
  dlg.m_mes_OBJ_SPC = m_mes_OBJ_SPC;
  dlg.m_mes_SELECT = m_mes_SELECT;
  dlg.m_mes_SPC = m_mes_SPC;
  dlg.m_mes_SPCDOC = m_mes_SPCDOC;
  dlg.m_mes_STAMP = m_mes_STAMP;

  dlg.DoModal();

  m_auto = !!dlg.m_auto;
  m_mes_2DDOC = !!dlg.m_mes_2DDOC;
  m_mes_3DDOC = !!dlg.m_mes_3DDOC;
  m_mes_APP = !!dlg.m_mes_APP;
  m_mes_DOC = !!dlg.m_mes_DOC;
  m_mes_OBJ_2DDOC = !!dlg.m_mes_OBJ_2DDOC;
  m_mes_OBJ_3DDOC = !!dlg.m_mes_OBJ_3DDOC;
  m_mes_OBJ_SPC = !!dlg.m_mes_OBJ_SPC;
  m_mes_SELECT = !!dlg.m_mes_SELECT;
  m_mes_SPC = !!dlg.m_mes_SPC;
  m_mes_SPCDOC = !!dlg.m_mes_SPCDOC;
  m_mes_STAMP = !!dlg.m_mes_STAMP;
}


//-------------------------------------------------------------------------------
// 
// ---
CeventsAutoApp theApp; // Создание глобального объекта приложение 


//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIB;
}


//-------------------------------------------------------------------------------
// 
// ---
KompasObjectPtr kompas;


//-------------------------------------------------------------------------------
//
// ---
void GetKompas()
{
  if (!(bool)kompas)
  {
    CString filename;
    if (::GetModuleFileName(NULL, filename.GetBuffer(255), 255))
    {
      filename.ReleaseBuffer(255);
      CString libname;

      libname.LoadString(IDS_DLL_NAME);  // kAPI5.dll / klAPI5.dll


      filename.Replace(filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)),
                       libname);

      // Идентификатор appauto.dll
      HINSTANCE hAppAuto = ::LoadLibrary(filename);
      if (hAppAuto)
      {
        typedef LPDISPATCH(WINAPI* FCreateKompasObject)();
        FCreateKompasObject pCreateKompasObject =
          (FCreateKompasObject)::GetProcAddress(hAppAuto, "CreateKompasObject");
        if (pCreateKompasObject)
          kompas = IDispatchPtr(pCreateKompasObject(), false);
        ::FreeLibrary(hAppAuto);
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Выбор 2D объекта для подписки
// ---
bool Request2DObject(long& objType)
{
  objType = -1;
  ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
  ksRequestInfoPtr info(kompas->GetParamStruct(ko_RequestInfo));
  if (info != NULL && doc2D != NULL)
  {
    info->Init();

    info->menuId = IDM_REQUEST_OBJECT_2D;
    info->title = "Укажите объект";

    double x, y;
    long command = doc2D->ksCursor(info, &x, &y, NULL);
    if (command)
    {
      if (command == -1)
      {
        reference refObject = doc2D->ksFindObj(x, y, 1000);
        if (doc2D->ksExistObj(refObject))
        {
          objType = refObject; // Объект
          return true;
        }
      }
      else
      {
        objType = --command; // Номер объекта
        return true;
      }
    }
  }
  return false; // Отмена
}


//-------------------------------------------------------------------------------
// Выбор объекта для подписки
// ---
bool Request3DObject(ksFeaturePtr& obj3D,
                     long& objType)
{
  obj3D = NULL;
  objType = o3d_unknown;
  bool res = false;
  ksDocument3DPtr doc3D(kompas->ActiveDocument3D());
  ksEntityPtr entity = doc3D ? doc3D->UserSelectEntity(NULL, "", "Укажите объект", 0, NULL) : NULL;
  if (entity)
  {
    objType = entity->type;
    if (objType == o3d_face || objType == o3d_edge || objType == o3d_vertex)
    {
      int resYesNo = kompas->ksYesNo("Данный тип не поддерживается\nДа - Подписаться на Part\nНет - Подписаться на Feature\nОтмена - не подписываться");
      switch (resYesNo)
      {
        case 1:
          objType = o3d_part;
          obj3D = entity->GetParent();
          res = true;
          break;
        case 0:
          objType = o3d_feature;
          obj3D = entity->GetFeature();
          res = true;
          break;
      }
    }
  }
  return res;
}


//-------------------------------------------------------------------------------
//
// ---
void WINAPI LIBRARYENTRY(unsigned int comm)
{
  // По умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  ::GetKompas(); // Захват интерфейса приложения КОМПАС
  if (kompas)
  {
    switch (comm)
    {

      //-------------------------------------------------------------------------------

            // События приложения
      case 1: // Подписаться
      {
        if (!BaseEvent::FindEvent(DIID_ksKompasObjectNotify))
        {
          ApplicationEvent* aplEvent = new ApplicationEvent(kompas);  // Обработчик событий приложения КОМПАС
          aplEvent->Advise();                                            // Подписка на события приложения КОМПАС
        }
        else
          kompas->ksError("На события приложения Компас уже подписались");
        break;
      }
      case 2: // Отписаться
      {
        BaseEvent::TerminateEvents(DIID_ksKompasObjectNotify);
        break;
      }

      //-------------------------------------------------------------------------------

            // События документов
      case 3: // Подписаться
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc)
        {
          if (!BaseEvent::FindEvent(DIID_ksDocumentFileNotify, doc))
            AdviseDoc(doc, docType, false,
                      false,
                      false,
                      false,
                      false,
                      false);
        }
        else
          kompas->ksError("Нет активного документа");
        break;
      }
      case 4: // Отписаться от всех событий документа
      {
        if (kompas)
        {
          IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
          if (doc)
            BaseEvent::TerminateEvents(GUID_NULL, doc);
          else
            kompas->ksError("Нет активного документа");
        }
        break;
      }

      //-------------------------------------------------------------------------------

            // События объекта 2D документа
      case 5: // Подписаться
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        long docType = kompas->ksGetDocumentType(0);
        if (doc2D)
        {
          long objType;
          if (Request2DObject(objType))
            AdviseDoc(doc2D, docType, false,
                      true,
                      false,
                      false,
                      false,
                      false, objType);
        }
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }
      case 6: // Отписаться
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        long docType = kompas->ksGetDocumentType(0);
        if (doc2D)
        {
          long objType;
          if (Request2DObject(objType))
            BaseEvent::TerminateEvents(DIID_ksObject2DNotify, doc2D, objType);
        }
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }
      case 7: // Отписаться от всех событий объектов 2D
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        if (doc2D)
          BaseEvent::TerminateEvents(DIID_ksObject2DNotify, doc2D);
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }
      case 8: // Подписаться на события вида по номеру
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        if (doc2D)
        {
          long view = 0;
          if (kompas->ksReadInt("Введите номер вида", 0, 0, 254, &view))
          {
            reference refView = doc2D->ksGetViewReference(view);
            if (refView)
            {
              if (!BaseEvent::FindEvent(DIID_ksObject2DNotify, doc2D, refView))
              {
                IUnknownPtr objNotify(doc2D ? doc2D->GetObject2DNotify(refView) : NULL);
                if (objNotify)
                {
                  Object2DEvent* objEvent = new Object2DEvent(objNotify, doc2D, refView, doc2D->GetObject2DNotifyResult());
                  objEvent->Advise();
                }
              }
              else
                kompas->ksError("На события объекта 2D документа уже подписались");
            }
            else
              kompas->ksError("Вид с таким номером не существует");
          }
        }
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }
      case 9: // Отписаться от событий для вида по номеру
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        if (doc2D)
        {
          long view = 0;
          if (kompas->ksReadInt("Введите номер вида", 0, 0, 254, &view))
          {
            reference refView = doc2D->ksGetViewReference(view);
            if (refView)
              BaseEvent::TerminateEvents(DIID_ksObject2DNotify, doc2D, refView);
            else
              kompas->ksError("Вид с таким номером не существует");
          }
        }
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }
      case 10: // Подписаться на события слоя по номеру
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        if (doc2D)
        {
          long layer = 0;
          if (kompas->ksReadInt("Введите номер слоя", 0, 0, 254, &layer))
          {
            reference refLayer = doc2D->ksGetLayerReference(layer);
            if (refLayer)
              BaseEvent::TerminateEvents(DIID_ksObject2DNotify, doc2D, refLayer);
            else
              kompas->ksError("Слой с таким номером не существует");
          }
        }
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }
      case 11: // Отписаться от событий для слоя по номеру
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        if (doc2D)
        {
          long layer = 0;
          if (kompas->ksReadInt("Введите номер слоя", 0, 0, 254, &layer))
          {
            reference refLayer = doc2D->ksGetLayerReference(layer);
            if (refLayer)
            {
              if (!BaseEvent::FindEvent(DIID_ksObject2DNotify, doc2D, refLayer))
              {
                IUnknownPtr objNotify(doc2D ? doc2D->GetObject2DNotify(refLayer) : NULL);
                if (objNotify)
                {
                  Object2DEvent* objEvent = new Object2DEvent(objNotify, doc2D, refLayer, doc2D->GetObject2DNotifyResult());
                  objEvent->Advise();
                }
              }
              else
                kompas->ksError("На события объекта 2D документа уже подписались");
            }
            else
              kompas->ksError("Слой с таким номером не существует");
          }
        }
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }

      //-------------------------------------------------------------------------------

            // События селектирования  
      case 12: // Подписаться 
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            (docType == lt_DocPart3D ||
             docType == lt_DocAssemble3D ||
             docType == lt_DocSheetStandart ||
             docType == lt_DocSheetUser ||
             docType == lt_DocFragment))
          AdviseDoc(doc, docType, true,
                    false,
                    false,
                    false,
                    false,
                    false);
        else
          kompas->ksError("Нет активного 2D или 3D документа");
        break;
      }
      case 13: // Отписаться
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            (docType == lt_DocPart3D ||
             docType == lt_DocAssemble3D ||
             docType == lt_DocSheetStandart ||
             docType == lt_DocSheetUser ||
             docType == lt_DocFragment))
          BaseEvent::TerminateEvents(DIID_ksSelectionMngNotify, doc);
        else
          kompas->ksError("Нет активного 2D или 3D документа");
        break;
      }

      //-------------------------------------------------------------------------------

            // События редактирования штампа
      case 14: // Подписаться 
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            docType != lt_DocPart3D &&
            docType != lt_DocAssemble3D)
          AdviseDoc(doc, docType, false,
                    false,
                    true,
                    false,
                    false,
                    false);
        else
          kompas->ksError("Нет активного 2D, текстового документа или документа спецификации");
        break;
      }
      case 15: // Отписаться
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            docType != lt_DocPart3D &&
            docType != lt_DocAssemble3D)
          BaseEvent::TerminateEvents(DIID_ksStampNotify, doc);
        else
          kompas->ksError("Нет активного 2D, текстового документа или документа спецификации");
        break;
      }

      //-------------------------------------------------------------------------------

            // События объектов 3D документа

            // Подписаться
      case 16: // Указать объект в модели 
      {
        ksDocument3DPtr doc3D(kompas->ActiveDocument3D());
        long docType = kompas->ksGetDocumentType(0);
        if (doc3D)
          AdviseDoc(doc3D, docType, false,
                    true,
                    false,
                    false,
                    false,
                    false);
        else
          kompas->ksError("Нет активного 3D документа");
        break;
      }

      // Отписаться
      case 17: // Указать объект в модели 
      {
        ksDocument3DPtr doc3D(kompas->ActiveDocument3D());
        long docType = kompas->ksGetDocumentType(0);
        if (doc3D)
        {
          ksFeaturePtr obj3D;
          long objType;
          if (Request3DObject(obj3D, objType))
            BaseEvent::TerminateEvents(DIID_ksObject3DNotify, doc3D, objType, obj3D);
        }
        else
          kompas->ksError("Нет активного 3D документа");
        break;
      }

      case 18: // Отписаться от всех объектов 3D документа
      {
        ksDocument3DPtr doc3D(kompas->ActiveDocument3D());
        if (doc3D)
          BaseEvent::TerminateEvents(DIID_ksObject3DNotify, doc3D);
        else
          kompas->ksError("Нет активного 3D документа");
        break;
      }

      //-------------------------------------------------------------------------------

            // Cобытия спецификации 
      case 19: // Подписаться 
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            docType != lt_DocTxtStandart &&
            docType != lt_DocTxtUser)
          AdviseDoc(doc, docType, false,
                    false,
                    false,
                    false,
                    true,
                    false);
        else
          kompas->ksError("Нет активного 2D, 3D документа или документа спецификации");
        break;
      }
      case 20: // Отписаться
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            docType != lt_DocTxtStandart &&
            docType != lt_DocTxtUser)
          BaseEvent::TerminateEvents(DIID_ksSpecificationNotify, doc);
        else
          kompas->ksError("Нет активного 2D, 3D документа или документа спецификации");
        break;
      }

      //-------------------------------------------------------------------------------

            // События объекта спецификации

            // Подписаться
      case 21: // Текущий объект
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        // Документ не должен быть текстовым ( 2D, 3D документ или документ спецификации )
        if (doc != NULL &&
            docType != lt_DocTxtStandart &&
            docType != lt_DocTxtUser)
          AdviseDoc(doc, docType, false,
                    false,
                    false,
                    false,
                    false,
                    true);
        else
          kompas->ksError("Нет активного 2D, 3D документа или документа спецификации");
        break;
      }
      case 22: // Все объекты
      case SPC_BASE_OBJECT + 350: // Базовый объект
      case SPC_COMMENT + 350: // Комментарий
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        // Документ не должен быть текстовым ( 2D, 3D документ или документ спецификации )
        if (doc != NULL &&
            docType != lt_DocTxtStandart &&
            docType != lt_DocTxtUser)
        {
          long objType = comm == 22 ? 0 : comm - 350;
          AdviseDoc(doc, docType, false,
                    false,
                    false,
                    false,
                    false,
                    true, objType);
        }
        else
          kompas->ksError("Нет активного 2D, 3D документа или документа спецификации");
        break;
      }
      // Отписаться    
      case 23: // Текущий объект
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        // Документ не должен быть текстовым ( 2D, 3D документ или документ спецификации )
        if (doc != NULL &&
            docType != lt_DocTxtStandart &&
            docType != lt_DocTxtUser)
        {
          ksSpecificationPtr specification;
          switch (docType)
          {
            case lt_DocSheetStandart: // Чертеж стандартный
            case lt_DocSheetUser:     // Чертеж нестандартный
            case lt_DocFragment:      // Фрагмент
            {
              ksDocument2DPtr doc2D(doc); // Интерфейс документа
              specification = doc2D->GetSpecification();
              break;
            }
            case lt_DocPart3D:     // 3d-документ модель
            case lt_DocAssemble3D: // 3d-документ сборка
            {
              ksDocument3DPtr doc3D(doc); // Интерфейс документа
              specification = doc3D->GetSpecification();
              break;
            }
            case lt_DocSpc:     // Спецификация
            case lt_DocSpcUser: // Спецификация нестандартный формат
            {
              ksSpcDocumentPtr spcDoc(doc); // Интерфейс документа
              specification = spcDoc->GetSpecification();
              break;
            }
          }
          if (specification)
          {
            reference refSpcObj = specification->ksGetCurrentSpcObject();
            if (!refSpcObj)
              kompas->ksError("Нет текущего объекта спецификации");
            else
              BaseEvent::TerminateEvents(DIID_ksSpcObjectNotify, doc, refSpcObj);
          }
        }
        else
          kompas->ksError("Нет активного 2D, 3D документа или документа спецификации");
        break;
      }
      case 24: // Все объекты
      case SPC_BASE_OBJECT + 400: // Базовый объект
      case SPC_COMMENT + 400: // Комментарий
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            docType != lt_DocTxtStandart &&
            docType != lt_DocTxtUser)
        {
          long objType = comm == 22 ? 0 : comm - 350;
          BaseEvent::TerminateEvents(DIID_ksSpcObjectNotify, doc, objType);
        }
        else
          kompas->ksError("Нет активного 2D, 3D документа или документа спецификации");
        break;
      }
      case 25: // Отписаться от всех объектов спецификации
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            docType != lt_DocTxtStandart &&
            docType != lt_DocTxtUser)
          BaseEvent::TerminateEvents(DIID_ksSpcObjectNotify, doc);
        else
          kompas->ksError("Нет активного 2D, 3D документа или документа спецификации");
        break;
      }

      //-------------------------------------------------------------------------------

            // События 3D документа
      case 26: // Подписаться
      {
        ksDocument3DPtr doc3D(kompas->ActiveDocument3D());
        long docType = kompas->ksGetDocumentType(0);
        if (doc3D)
          AdviseDoc(doc3D, docType, false,
                    false,
                    false,
                    true,
                    false,
                    false);
        else
          kompas->ksError("Нет активного 3D документа");
        break;
      }
      case 27: // Отписаться
      {
        ksDocument3DPtr doc3D(kompas->ActiveDocument3D());
        if (doc3D)
          BaseEvent::TerminateEvents(DIID_ksDocument3DNotify, doc3D);
        else
          kompas->ksError("Нет активного 3D документа");
        break;
      }

      //-------------------------------------------------------------------------------

            // События документа спецификации
      case 28: // Подписаться
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            (docType == lt_DocSpcUser ||
             docType == lt_DocSpc))
          AdviseDoc(doc, docType, false,
                    false,
                    false,
                    true,
                    false,
                    false);
        else
          kompas->ksError("Нет активного документа спецификации");
        break;
      }
      case 29: // Отписаться
      {
        IDispatchPtr doc(kompas->ksGetDocumentByReference(0));
        long docType = kompas->ksGetDocumentType(0);
        if (doc != NULL &&
            (docType == lt_DocSpcUser ||
             docType == lt_DocSpc))
          BaseEvent::TerminateEvents(DIID_ksSpcDocumentNotify, doc);
        else
          kompas->ksError("Нет активного документа спецификации");
        break;
      }

      //-------------------------------------------------------------------------------

            // События 2D документа
      case 30: // Подписаться
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        long docType = kompas->ksGetDocumentType(0);
        if (doc2D)
          AdviseDoc(doc2D, docType, false,
                    false,
                    false,
                    true,
                    false,
                    false);
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }
      case 31: // Отписаться
      {
        ksDocument2DPtr doc2D(kompas->ActiveDocument2D());
        if (doc2D)
          BaseEvent::TerminateEvents(DIID_ksDocument2DNotify, doc2D);
        else
          kompas->ksError("Нет активного 2D документа");
        break;
      }

      //-------------------------------------------------------------------------------

      case 32: // Отписаться от всех событий
      {
        BaseEvent::TerminateEvents();
        break;
      }

      //-------------------------------------------------------------------------------

      case 33: // Конфигурация
      {
        theApp.ConfigDlg();
        break;
      }

      case 34: // Подписанные события
      {
        BaseEvent::ListEvents();
        break;
      }


      //-------------------------------------------------------------------------------

      default:
      {
        // События объекта 3D документа
        // Подписаться
        if (comm >= o3d_unknown + 50 && comm <= o3d_feature + 50)
        {
          ksDocument3DPtr doc3D(kompas->ActiveDocument3D());
          long docType = kompas->ksGetDocumentType(0);
          if (doc3D)
          {
            long objType = comm - 50;
            AdviseDoc(doc3D, docType, false,
                      true,
                      false,
                      false,
                      false,
                      false, objType);
          }
        }
        else
          kompas->ksError("Нет активного 3D документа");
        break;
      }

      // Отписаться
      if (comm >= o3d_unknown + 200 && comm <= o3d_feature + 200)
      {
        if (comm >= o3d_unknown + 50 && comm <= o3d_feature + 50)
        {
          ksDocument3DPtr doc3D(kompas->ActiveDocument3D());
          long docType = kompas->ksGetDocumentType(0);
          if (doc3D)
          {
            long objType = comm - 50;
            BaseEvent::TerminateEvents(DIID_ksObject3DNotify, doc3D, objType);
          }
        }
        else
          kompas->ksError("Нет активного 3D документа");
        break;
      }
    }
  }
}


//-------------------------------------------------------------------------------
// 
// ---
void AdviseDocuments()
{
  if (kompas)
  {
    // Интерфейс итератора
    ksIteratorPtr iter = kompas->GetIterator();

    // Создаем итератор для хождения по документам
    if (iter != NULL && iter->ksCreateIterator(ALL_DOCUMENTS, 0))
    {
      reference refDoc = iter->ksMoveIterator("F"); // Первый документ
      while (refDoc)
      {
        // Подписка на события документа
        AdviseDoc(kompas->ksGetDocumentByReference(refDoc),
                  kompas->ksGetDocumentType(refDoc));

        // Cледующий документ
        refDoc = iter->ksMoveIterator("N");
      }

      // Удалить итератор
      iter->ksDeleteIterator();
    }
  }
}


//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
bool WINAPI LibInterfaceNotifyEntry(IDispatch* application)
{
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  if (theApp.m_auto)
  {
    // Захват интерфейса приложения КОМПАС
    if (kompas == NULL && application)
    {
      kompas = application;
      kompas.AddRef();
    }

    if (kompas)
    {
      // Обработчик событий приложения КОМПАС
      ApplicationEvent* aplEvent = new ApplicationEvent(kompas);
      // Подписка на события приложения КОМПАС
      aplEvent->Advise();

      AdviseDocuments();
    }
  }

  return false;
}


//-----------------------------------------------------------------------------
// Подписка на события документа
// ---
void AdviseDoc(LPDISPATCH doc, long docType,
               bool fSelectMng /*true*/,
               bool fObject /*true*/,
               bool fStamp /*true*/,
               bool fDocument/*true*/,
               bool fSpecification/*true*/,
               bool fSpcObject/*true*/,
               long objType/*-1*/)
{
  if (!doc)
    return;
  // События документа, необходимы для своевременной отписки
  if (!BaseEvent::FindEvent(DIID_ksDocumentFileNotify, doc))
  {
    bool fFileDoc = !fSelectMng && !fObject && !fStamp && !fDocument && !fSpecification && !fSpcObject;

    // Обработчик событий от документа
    DocumentEvent* docEvent = new DocumentEvent(doc, fFileDoc);
    // Подписка на события документа
    int advise = docEvent->Advise();

    // Неудачная подписка на события документа
    if (!advise)
      return;
  }
  else
    kompas->ksError("На события документа уже подписались");

  switch (docType)
  {
    case lt_DocSheetStandart: // 1 - чертеж стандартный
    case lt_DocSheetUser: // 2 - чертеж нестандартный
    case lt_DocFragment: // 3 - фрагмент
    {
      ksDocument2DPtr doc2D(doc); // Интерфейс документа

      // Документ 2D
      if (fDocument)
      {
        if (!BaseEvent::FindEvent(DIID_ksDocument2DNotify, doc2D))
        {
          IUnknownPtr doc2DNotify = doc2D->GetDocument2DNotify();
          if (doc2DNotify)
          {
            Document2DEvent* document2DEvent = new Document2DEvent(doc2DNotify, doc2D);
            document2DEvent->Advise();
          }
        }
        else
          kompas->ksError("На события 3D документа уже подписались");
      }

      // Спецификация в 2D документе
      if (fSpecification)
      {
        if (!BaseEvent::FindEvent(DIID_ksSpecificationNotify, doc2D))
        {
          ksSpecificationPtr specification = doc2D->GetSpecification();
          if (specification)
          {
            SpecificationEvent* specificationEvent = new SpecificationEvent(specification, doc2D);
            specificationEvent->Advise();
          }
        }
        else
          kompas->ksError("На события спецификации уже подписались");
      }

      // Объект спецификации
      if (fSpcObject)
      {
        ksSpecificationPtr specification = doc2D ? doc2D->GetSpecification() : NULL;
        if (specification)
        {
          reference refSpcObj = specification->ksGetCurrentSpcObject();
          if (!refSpcObj)
            kompas->ksError("Нет текущего объекта спецификации");
          else
          {
            if (!BaseEvent::FindEvent(DIID_ksSpcObjectNotify, doc2D, refSpcObj))
            {
              IUnknownPtr objNotify(specification ? specification->GetSpcObjectNotify(refSpcObj) : NULL);
              if (objNotify)
              {
                SpcObjectEvent* objEvent = new SpcObjectEvent(objNotify, doc2D, refSpcObj);
                objEvent->Advise();
              }
            }
            else
              kompas->ksError("На события объекта спецификации (2D) уже подписались");
          }
        }
      }

      // Селектирование
      if (fSelectMng)
      {
        if (!BaseEvent::FindEvent(DIID_ksSelectionMngNotify, doc2D))
        {
          IUnknownPtr selMsg(doc2D ? doc2D->GetSelectionMngNotify() : NULL);
          if (selMsg)
          {
            SelectMngEvent* selEvent = new SelectMngEvent(selMsg, doc2D);
            selEvent->Advise();
          }
        }
        else
          kompas->ksError("На события селектирования уже подписались");
      }

      // Штамп
      if (fStamp && docType != lt_DocFragment)
      {
        if (!BaseEvent::FindEvent(DIID_ksStampNotify, doc2D))
        {
          ksStampPtr stamp(doc2D->GetStamp());
          if (stamp)
          {
            StampEvent* stampEvent = new StampEvent(stamp, doc2D);
            stampEvent->Advise();
          }
        }
        else
          kompas->ksError("На события редактирования штампа уже подписались");
      }

      // Объект 2D документа
      if (fObject && objType >= 0) // Тип приходит всегда
      {
        if (!BaseEvent::FindEvent(DIID_ksObject2DNotify, doc2D, objType))
        {
          IUnknownPtr objNotify(doc2D ? doc2D->GetObject2DNotify(objType) : NULL);
          if (objNotify)
          {
            Object2DEvent* objEvent = new Object2DEvent(objNotify, doc2D, objType, doc2D->GetObject2DNotifyResult());
            objEvent->Advise();
          }
        }
        else
          kompas->ksError("На события объекта 2D документа уже подписались");
      }
      break;
    }
    case lt_DocPart3D: // 5 - 3d-документ модель
    case lt_DocAssemble3D: // 6 - 3d-документ сборка
    {
      ksDocument3DPtr doc3D(doc); // Интерфейс документа

      // Документ 3D
      if (fDocument)
      {
        if (!BaseEvent::FindEvent(DIID_ksDocument3DNotify, doc3D))
        {
          IUnknownPtr doc3DNotify = doc3D->GetDocument3DNotify();
          if (doc3DNotify)
          {
            Document3DEvent* document3DEvent = new Document3DEvent(doc3DNotify, doc3D);
            document3DEvent->Advise();
          }
        }
        else
          kompas->ksError("На события 3D документа уже подписались");
      }

      // Спецификация в 3D документе
      if (fSpecification)
      {
        if (!BaseEvent::FindEvent(DIID_ksSpecificationNotify, doc3D))
        {
          ksSpecificationPtr specification = doc3D->GetSpecification();
          if (specification)
          {
            SpecificationEvent* specificationEvent = new SpecificationEvent(specification, doc3D);
            specificationEvent->Advise();
          }
        }
        else
          kompas->ksError("На события спецификации уже подписались");
      }

      // Объект спецификации
      if (fSpcObject)
      {
        ksSpecificationPtr specification = doc3D ? doc3D->GetSpecification() : NULL;
        if (specification)
        {
          reference refSpcObj = specification->ksGetCurrentSpcObject();
          if (!refSpcObj)
            kompas->ksError("Нет текущего объекта спецификации");
          else
          {
            if (!BaseEvent::FindEvent(DIID_ksSpcObjectNotify, doc3D, refSpcObj))
            {
              IUnknownPtr objNotify(specification ? specification->GetSpcObjectNotify(refSpcObj) : NULL);
              if (objNotify)
              {
                SpcObjectEvent* objEvent = new SpcObjectEvent(objNotify, doc3D, refSpcObj);
                objEvent->Advise();
              }
            }
            else
              kompas->ksError("На события объекта спецификации (3D) уже подписались");
          }
        }
      }

      // Селектирование
      if (fSelectMng)
      {
        if (!BaseEvent::FindEvent(DIID_ksSelectionMngNotify, doc3D))
        {
          ksSelectionMngPtr selMng(doc3D ? doc3D->GetSelectionMng() : NULL);
          if (selMng)
          {
            SelectMngEvent* selEvent = new SelectMngEvent(selMng, doc3D);
            selEvent->Advise();
          }
        }
        else
          kompas->ksError("На события селектирования уже подписались");
      }

      // Объект 3D документа
      if (fObject)
      {
        if (objType >= 0)
        {
          if (!BaseEvent::FindEvent(DIID_ksObject3DNotify, doc3D, objType))
          {
            ksPartPtr containerPart = doc3D->GetPart(pTop_Part);
            IUnknownPtr objNotify(containerPart ? containerPart->GetObject3DNotify(objType, NULL) : NULL);
            if (objNotify)
            {
              Object3DEvent* objEvent = new Object3DEvent(objNotify, doc3D, objType, NULL, containerPart->GetObject3DNotifyResult());
              objEvent->Advise();
            }
          }
          else
            kompas->ksError("На события объекта 3D документа уже подписались");
        }
        else
        {
          ksFeaturePtr obj3D;
          if (Request3DObject(obj3D, objType))
          {
            if (!BaseEvent::FindEvent(DIID_ksObject3DNotify, doc3D, objType, obj3D))
            {
              ksPartPtr containerPart;
              switch (objType)
              {
                case o3d_part:
                {
                  ksPartPtr objPart(obj3D);
                  if (objPart)
                    containerPart = objPart->GetPart(pTop_Part);
                  break;
                }

                case o3d_feature:
                {
                  ksFeaturePtr objFeature(obj3D);
                  if (objFeature)
                  {
                    IDispatchPtr obj = objFeature->GetObject();
                    if (obj)
                    {
                      ksEntityPtr objEntity(obj);
                      if (objEntity)
                        containerPart = objEntity->GetParent();
                      else
                      {
                        ksPartPtr objPart(obj);
                        if (objPart)
                          containerPart = objPart->GetPart(pTop_Part);
                      }
                    }
                  }
                  break;
                }

                default:
                {
                  ksEntityPtr objEntity(obj3D);
                  if (objEntity)
                    containerPart = objEntity->GetParent();
                  break;
                }
              }
              if (containerPart == NULL)
                containerPart = doc3D->GetPart(pTop_Part);

              IUnknownPtr objNotify(containerPart ? containerPart->GetObject3DNotify(objType, obj3D) : NULL);
              if (objNotify)
              {
                Object3DEvent* objEvent = new Object3DEvent(objNotify, doc3D, objType, obj3D, containerPart->GetObject3DNotifyResult());
                objEvent->Advise();
              }
            }
            else
              kompas->ksError("На события объекта 3D документа уже подписались");
          }
        }
      }
      break;
    }
    case lt_DocTxtStandart: // 7 - текстовый документ стандартный
    case lt_DocTxtUser: // 8 - текстовый документ нестандартный
    {
      ksDocumentTxtPtr docTxt(doc); // Интерфейс документа

      // Штамп
      if (fStamp)
      {
        if (!BaseEvent::FindEvent(DIID_ksStampNotify, docTxt))
        {
          ksStampPtr stamp(docTxt->GetStamp());
          if (stamp)
          {
            StampEvent* stampEvent = new StampEvent(stamp, docTxt);
            stampEvent->Advise();
          }
        }
        else
          kompas->ksError("На события редактирования штампа уже подписались");
      }

      break;
    }
    case lt_DocSpcUser: // 9 - спецификация нестандартный формат
    case lt_DocSpc: // 4 - спецификация
    {
      ksSpcDocumentPtr spcDoc(doc); // Интерфейс документа

      // Документ спецификации
      if (fDocument)
      {
        if (!BaseEvent::FindEvent(DIID_ksSpcDocumentNotify, spcDoc))
        {
          IUnknownPtr spcDocNotify = spcDoc->GetSpcDocumentNotify();
          if (spcDocNotify)
          {
            SpcDocumentEvent* spcDocumentEvent = new SpcDocumentEvent(spcDocNotify, spcDoc);
            spcDocumentEvent->Advise();
          }
        }
        else
          kompas->ksError("На события документа спецификации уже подписались");
      }

      // Спецификация в документе спецификации
      if (fSpecification)
      {
        if (!BaseEvent::FindEvent(DIID_ksSpecificationNotify, spcDoc))
        {
          ksSpecificationPtr specification = spcDoc->GetSpecification();
          if (specification)
          {
            SpecificationEvent* specificationEvent = new SpecificationEvent(specification, spcDoc);
            specificationEvent->Advise();
          }
        }
        else
          kompas->ksError("На события спецификации уже подписались");
      }

      // Объект документа спецификации
      if (fSpcObject)
      {
        ksSpecificationPtr specification = spcDoc ? spcDoc->GetSpecification() : NULL;
        if (specification)
        {
          if (objType == -1)
          {
            reference refSpcObj = specification->ksGetCurrentSpcObject();
            if (!refSpcObj)
              kompas->ksError("Нет текущего объекта спецификации");
            else
              objType = refSpcObj;
          }
          if (objType != -1)
          {
            if (!BaseEvent::FindEvent(DIID_ksSpcObjectNotify, spcDoc, objType))
            {
              IUnknownPtr objNotify(specification ? specification->GetSpcObjectNotify(objType) : NULL);
              if (objNotify)
              {
                SpcObjectEvent* objEvent = new SpcObjectEvent(objNotify, spcDoc, objType);
                objEvent->Advise();
              }
            }
            else
              kompas->ksError("На события объекта спецификации (Spc) уже подписались");
          }
        }
      }

      // Штамп
      if (fStamp)
      {
        if (!BaseEvent::FindEvent(DIID_ksStampNotify, spcDoc))
        {
          ksStampPtr stamp(spcDoc->GetStamp());
          if (stamp)
          {
            StampEvent* stampEvent = new StampEvent(stamp, spcDoc);
            stampEvent->Advise();
          }
        }
        else
          kompas->ksError("На события редактирования штампа уже подписались");
      }

      break;
    }
  }
}


