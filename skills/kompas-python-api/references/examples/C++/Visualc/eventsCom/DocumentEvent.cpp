////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventCom.h"

#ifndef _DOCUMENTEVENT_H
#include "DocumentEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE* pModuleState;

extern BaseEvent* NewDocumentFrameEvent(reference doc, LPUNKNOWN iObj);

//-------------------------------------------------------------------------------
// Создать обработчик событий документа
// ---
BaseEvent* NewDocumentEvent(reference doc) {
  DocumentEvent* res = NULL;
  if (doc) {
    if (!BaseEvent::FindEvents(ntDocumentFileNotify, doc)) {
      res = new DocumentEvent(doc);
      if (!res->Advise()) {
        delete res;
        res = NULL;
      }
    }
  }
  return res;
}

//-------------------------------------------------------------------------------
// Создать обработчик событий 3D документа
// ---
BaseEvent* NewDocument3DEvent(reference doc) {
  Document3DEvent* res = NULL;
  if (doc) {
    if (!BaseEvent::FindEvents(ntDocument3DNotify, doc)) {
      IDocument3DPtr doc3D(ksGet3dDocumentFromReference(doc), false);
      if (doc3D) {
        NewDocumentEvent(doc); // чтобы при закрытии документа отписаться
        res = new Document3DEvent(doc, doc3D);
        if (!res->Advise()) {
          delete res;
          res = NULL;
        }
      }
    }
  }
  return res;
}

//-------------------------------------------------------------------------------
// Создать обработчик событий 2D документа
// ---
BaseEvent* NewDocument2DEvent(reference doc) {
  Document2DEvent* res = NULL;
  if (doc) {
    if (!BaseEvent::FindEvents(ntDocument2DNotify, doc)) {
      NewDocumentEvent(doc); // чтобы при закрытии документа отписаться
      res = new Document2DEvent(doc);
      if (!res->Advise()) {
        delete res;
        res = NULL;
      }
    }
  }
  return res;
}

////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
DocumentEvent::DocumentEvent(reference p) :
  BaseEvent(ntDocumentFileNotify, p, 0, p)
{
}


//-------------------------------------------------------------------------------
//
// ---
DocumentEvent::~DocumentEvent()
{

}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN DocumentEvent::GetUnknown() {
  m_xDocumentFileNotify.AddRef();
  return &m_xDocumentFileNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) DocumentEvent::XDocumentFileNotify::Release()
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) DocumentEvent::XDocumentFileNotify::AddRef()
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    return (ULONG)pThis->InternalAddRef();
}


//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP DocumentEvent::XDocumentFileNotify::QueryInterface(
  REFIID iid, LPVOID* ppvObj)
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)

    ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

  if (IsEqualIID(iid, IID_IUnknown) ||
      IsEqualIID(iid, IID_IDocumentFileNotify))
  {
    *ppvObj = this;
    AddRef();
    return S_OK;
  }

  return E_NOINTERFACE;
}


//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::IsNotifyProcess(int notifyType)
{
  //  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
  return  notifyType >= kdBeginCloseDocument && notifyType <= kdDocumentFrameOpen;
}


//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void DocumentEvent::ShowEventName(LPCTSTR eventName) {
  if (theApp.m_mes_DOC) {
    CString res = eventName;
    res += GetDocumentParam(refDoc);
    ::_ShowEventName((LPTSTR)(LPCTSTR)res);
  }
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString DocumentEvent::EventCaption() {
  CString res = _T("DocumentEvent");
  res += GetDocumentParam(refDoc);
  return res;
}


/////////////////////////////////////////////////////////////////////////////
// DocumentEvent message handlers
//-----------------------------------------------------------------------------
//kdBeginCloseDocument - Начало закрытия документа.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::BeginCloseDocument() {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::BeginCloseDocument"));

  return !theApp.m_mes_DOC || ::YesNoT(_T("Закрыть документ?")) == 1;
}


//-----------------------------------------------------------------------------
//kdCloseDocument - Документ закрыт.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::CloseDocument() {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::CloseDocument"));
  reference doc = pThis->GetDocReference();
  if (doc)
    TerminateEvents(0, doc);
  else
    pThis->Disconnect();
  return true;
}


//-----------------------------------------------------------------------------
//kdBeginSaveDocument - Начало сохранения документа.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::BeginSaveDocument(LPSTR docName) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::BeginSaveDocument"));
  return !theApp.m_mes_DOC || ::YesNoT(_T("Сохранить документ?")) == 1;
}


//-----------------------------------------------------------------------------
//kdSaveDocument - Документ сохранен.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::SaveDocument() {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::SaveDocument"));
  return true;
}


//-----------------------------------------------------------------------------
//kdActiveDocument - Документ активизирован.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::Activate() {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::Activate"));
  return true;
}


//-----------------------------------------------------------------------------
//kdDeactiveDocument - Документ деактивизирован.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::Deactivate() {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::Deactivate"));
  return true;
}

//-----------------------------------------------------------------------------
//kdBeginSaveAsDocument - Процесс сохранения файла с новым именем.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::BeginSaveAsDocument() {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    //  pThis->ShowEventName( "DocumentEvent::BeginSaveAsDocument");
    bool res = !theApp.m_mes_DOC;
  if (!res) {
    int com = YesNoT(_T("DocumentEvent::BeginSaveAsDocument\n ")
                     _T("Да - Сохранить чертеж\n")
                     _T("Нет - запустить стандартный диалог сохранения файла\n")
                     _T("Отмена - не сохранять файл"));
    switch (com) {
      case 1: {
        int type = ksGetDocumentType(pThis->refDoc);
        switch (type) {
          case lt_DocTxtStandart:             //               7- текстовый документ стандартный
          case lt_DocTxtUser: {                //               8- текстовый документ нестандартный
            TextDocumentParamT docParam;
            GetObjParam(pThis->refDoc, &docParam, sizeof(docParam), ALLPARAM_T);
            if (!docParam.fileName[0])
              res = !::SaveDocumentExT(0, _T("C:\\1.kdw"), 0);
            else
              res = !::SaveDocumentExT(0, NULL, 0);
            break;
          }
          default: {
            DocumentParamT docParam;
            GetObjParam(pThis->refDoc, &docParam, sizeof(docParam), ALLPARAM_T);
            if (!docParam.fileName[0]) {
              switch (type) {
                case lt_DocFragment:           //               3- фрагмент
                  res = !::SaveDocumentExT(0, _T("C:\\1.frw"), 0);
                  break;
                case lt_DocSheetStandart:
                case lt_DocSheetUser:
                  res = !::SaveDocumentExT(0, _T("C:\\1.cdw"), 0);
                  break;
                case lt_DocSpc:                //               4- спецификация
                case lt_DocSpcUser:
                  res = !::SaveDocumentExT(0, _T("C:\\1.spw"), 0);
                  break;
                case lt_DocPart3D:                  //          5- 3d-документ модель
                  res = !::SaveDocumentExT(0, _T("C:\\1.m3d"), 0);
                  break;
                case lt_DocAssemble3D:                  //      6- 3d-документ сборка
                  res = !::SaveDocumentExT(0, _T("C:\\1.a3d"), 0);
                  break;

              }
            }
            else
              res = !::SaveDocumentExT(0, NULL, 0);
          }
        }
      }
      case 0:
        res = true;
        break;
      case -1:
        res = false;
    }
  }
  return res;
}

//-----------------------------------------------------------------------------
//kdDocumentFrameOpen    - Окно документа открылось.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::DocumentFrameOpen(LPUNKNOWN v) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    NewDocumentFrameEvent(pThis->refDoc, v);
  pThis->ShowEventName(_T("DocumentEvent::DocumentFrameOpen"));
  return true;
}

//-----------------------------------------------------------------------------
// kdProcessActivate      - Активизация процесса
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::ProcessActivate(long Id) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::ProcessActivate"));
  return true;
}

//-----------------------------------------------------------------------------
// kdProcessDeactivate    - Деактивизация процесса
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::ProcessDeactivate(long Id) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::ProcessDeactivate"));
  return true;
}


//-----------------------------------------------------------------------------
// kdBeginProcess - Начало процесса.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::BeginProcess(long Id) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::BeginProcess"));
  return true;
}


//-----------------------------------------------------------------------------
// kdEndProcess - Завершение процесса
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::EndProcess(long Id, VARIANT_BOOL Success) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::EndProcess"));
  return true;
}

//-----------------------------------------------------------------------------
// kdBeginAutoSaveDocument - Начало автосохранения документа.
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::BeginAutoSaveDocument(LPSTR docName)
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::BeginAutoSaveDocument"));
  return !theApp.m_mes_DOC || ::YesNoT(_T("Автосохранить документ?")) == 1;
}

//-----------------------------------------------------------------------------
// kdAutoSaveDocument - Документ автосохранен
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::AutoSaveDocument()
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("DocumentEvent::AutoSaveDocument"));
  return true;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentEvent::XDocumentFileNotify::ActivateToolbarSet(LPSTR oldToolbarSetId, LPSTR newToolbarSetId) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    return true;
}

////////////////////////////////////////////////////////////////////////////////
//
// Document2DEvent  - обработчик событий от 2D документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
Document2DEvent::Document2DEvent(reference p) :
  BaseEvent(ntDocument2DNotify, p, 0, p)
{
}


//-------------------------------------------------------------------------------
//
// ---
Document2DEvent::~Document2DEvent()
{

}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN Document2DEvent::GetUnknown() {
  m_xDocument2DNotify.AddRef();
  return &m_xDocument2DNotify;
}


//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) Document2DEvent::XDocument2DNotify::Release()
{
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) Document2DEvent::XDocument2DNotify::AddRef()
{
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP Document2DEvent::XDocument2DNotify::QueryInterface(
  REFIID iid, LPVOID* ppvObj)
{
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)

    ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

  if (IsEqualIID(iid, IID_IUnknown) ||
      IsEqualIID(iid, IID_IDocument2DNotify))
  {
    *ppvObj = this;
    AddRef();
    return S_OK;
  }

  return E_NOINTERFACE;
}


//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::IsNotifyProcess(int notifyType)
{
  //  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
  return  notifyType >= d2BeginRebuild && notifyType <= d2DeleteProperty;
}


//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void Document2DEvent::ShowEventName(LPCTSTR eventName) {
  if (theApp.m_mes_2DDOC) {
    CString str = eventName;
    if (refDoc)
      str += GetDocumentParam(refDoc);
    ::_ShowEventName(str);
  }
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString Document2DEvent::EventCaption() {
  CString res = _T("Document2DEvent");
  res += GetDocumentParam(refDoc);
  return res;
}

//-----------------------------------------------------------------------------
// d2BeginRebuild - Начало перестроения 2D документа.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::BeginRebuild() {
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::BeginRebuild"));
  return !theApp.m_mes_2DDOC || ::YesNoT(_T("Перестроить документ?")) == 1;
}

//-----------------------------------------------------------------------------
// d2Rebuild - Завершение перестроения 2D документа.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::Rebuild() {
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::Rebuild"));
  return true;
}

//-----------------------------------------------------------------------------
// d2BeginChoiceMaterial - Изменение материала.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::BeginChoiceMaterial() {
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::BeginChoiceMaterial"));
  return !theApp.m_mes_2DDOC || ::YesNoT(_T("Измененить материал?")) == 1;
}

//-----------------------------------------------------------------------------
// dChoiceMaterial - Изменение материала.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::ChoiceMaterial(LPSTR material, double density) {
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::ChoiceMaterial"));
  return true;
}

//-----------------------------------------------------------------------------
// d2BeginInsertFragment - Изменение материала.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::BeginInsertFragment() {
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::BeginInsertFragment"));
  return !theApp.m_mes_2DDOC || ::YesNoT(_T("Запустить всавку фрагментов?")) == 1;
}

//-----------------------------------------------------------------------------
// d2LocalFragmentEdit - Редактирование локального фрагмента.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::LocalFragmentEdit(long pDoc, VARIANT_BOOL newFrw)
{
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::BeginInsertFragment"));
  return !theApp.m_mes_2DDOC || ::YesNoT(_T("Редактировать локальный фрагмент?")) == 1;
}


//-----------------------------------------------------------------------------
// d2BeginChoiceProperty - Начало выбора свойства
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::BeginChoiceProperty(long objRef, double propID)
{
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::BeginChoiceProperty"));
  return !theApp.m_mes_2DDOC || ::YesNoT(_T("Выбрать свойство?")) == 1;
}


//-----------------------------------------------------------------------------
// d2ChoiceProperty - Закончен выбор свойства
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::ChoiceProperty(long objRef, double propID) {
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::ChoiceProperty"));
  return true;
}

//-----------------------------------------------------------------------------
// d2BeginDeleteProperty - Начало удаления значения свойства
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::BeginDeleteProperty(long objRef, double propID)
{
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::BeginChoiceProperty"));
  return !theApp.m_mes_2DDOC || ::YesNoT(_T("Выбрать свойство?")) == 1;
}


//-----------------------------------------------------------------------------
// d2DeleteProperty - Завершение удаления свойства
// ---
STDMETHODIMP_(VARIANT_BOOL) Document2DEvent::XDocument2DNotify::DeleteProperty(long objRef, double propID)
{
  METHOD_PROLOGUE_EX_(Document2DEvent, Document2DNotify)
    pThis->ShowEventName(_T("Document2DEvent::DeleteProperty"));
  return true;
}


////////////////////////////////////////////////////////////////////////////////
//
// Document3DEvent  - обработчик событий от 3D документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
Document3DEvent::Document3DEvent(reference p, LPUNKNOWN doc) :
  BaseEvent(ntDocument3DNotify, doc, 0, 0, p)
{
}


//-------------------------------------------------------------------------------
//
// ---
Document3DEvent::~Document3DEvent()
{

}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN Document3DEvent::GetUnknown() {
  m_xDocument3DNotify.AddRef();
  return &m_xDocument3DNotify;
}


//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) Document3DEvent::XDocument3DNotify::Release()
{
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) Document3DEvent::XDocument3DNotify::AddRef()
{
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP Document3DEvent::XDocument3DNotify::QueryInterface(
  REFIID iid, LPVOID* ppvObj)
{
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)

    ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

  if (IsEqualIID(iid, IID_IUnknown) ||
      IsEqualIID(iid, IID_IDocument3DNotify))
  {
    *ppvObj = this;
    AddRef();
    return S_OK;
  }

  return E_NOINTERFACE;
}

//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::IsNotifyProcess(int notifyType)
{
  //  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
  return  notifyType >= d3BeginRebuild && notifyType <= d3DeleteProperty;
}


//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void Document3DEvent::ShowEventName(LPCTSTR eventName) {
  if (theApp.m_mes_3DDOC) {
    CString str = eventName;
    if (refDoc)
      str += GetDocumentParam(refDoc);
    ::_ShowEventName(str);
  }
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString Document3DEvent::EventCaption() {
  CString res = _T("Document3DEvent");
  res += GetDocumentParam(refDoc);
  return res;
}


//-----------------------------------------------------------------------------
// d3BeginRebuild - Начало перестроения модели.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginRebuild() {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginRebuild"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Перестроить модель?")) == 1;
}

//-----------------------------------------------------------------------------
// d3Rebuild - Завершение перестроения модели.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::Rebuild() {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::Rebuild"));
  return true;
}

//-----------------------------------------------------------------------------
// d3BeginChoiceMaterial - Изменение материала.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginChoiceMaterial() {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginChoiceMaterial"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Измененить материал?")) == 1;
}

//-----------------------------------------------------------------------------
// d3ChoiceMaterial - Изменение материала.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::ChoiceMaterial(LPSTR material, double density) {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::ChoiceMaterial"));
  return true;
}

//-----------------------------------------------------------------------------
// d3BeginChoiceMarking - Изменение обозначения.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginChoiceMarking() {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginChoiceMarking"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Измененить обозначение?")) == 1;
}

//-----------------------------------------------------------------------------
// d3ChoiceMarking - Изменение обозначения.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::ChoiceMarking(LPSTR marking) {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::ChoiceMarking"));
  return true;
}

//-----------------------------------------------------------------------------
// d3BeginCreatePartFromFile - Запуск процесса вставки детали в сборку.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginSetPartFromFile() {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginSetPartFromFile"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Запустить диалог выбора файла для вставки?")) == 1;
}


//-----------------------------------------------------------------------------
// d3BeginCreatePartFromFile - Запуск процесса вставки детали в сборку.
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginCreatePartFromFile(VARIANT_BOOL typeDoc, IEntity* plane) {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginCreatePartFromFile"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Создать деталь в сборке?")) == 1;
}


//-----------------------------------------------------------------------------
// 
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::CreateEmbodiment(LPSTR marking)
{
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::CreateEmbodiment"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Создать исполнение?")) == 1;
}


//-----------------------------------------------------------------------------
// 
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::DeleteEmbodiment(LPSTR marking)
{
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::DeleteEmbodiment"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Удалить исполнение?")) == 1;
}


//-----------------------------------------------------------------------------
// 
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::ChangeCurrentEmbodiment(LPSTR marking)
{
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::ChangeCurrentEmbodiment"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Изменить текущее исполнение?")) == 1;
}

STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginChoiceProperty(IUnknown* obj, double propID)
{
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginChoiceProperty"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Выбрать свойство?")) == 1;
}


STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::ChoiceProperty(IUnknown* obj, double propID)
{
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::ChoiceProperty"));
  return true;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginRollbackFeatures() {
  METHOD_PROLOGUE_EX_(Document3DEvent, Document3DNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginRollbackFeatures"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Начало отката дерева модели?")) == 1;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::RollbackFeatures() {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("Document3DEvent::RollbackFeatures"));
  return true;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BedinLoadCombinationChange(long index) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("Document3DEvent::BedinLoadCombinationChange"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Завершить переключение типа загрузки?")) == 1;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::LoadCombinationChange(long index) {
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("Document3DEvent::LoadCombinationChange"));
  return true;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginDeleteProperty(IUnknown* obj, double propID)
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginDeleteProperty"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Удалить свойство?")) == 1;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::DeleteProperty(IUnknown* obj, double propID)
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("Document3DEvent::DeleteProperty"));
  return true;
}

//-----------------------------------------------------------------------------
//  
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::BeginDeleteMaterial()
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("Document3DEvent::BeginDeleteMaterial"));
  return !theApp.m_mes_3DDOC || ::YesNoT(_T("Удалить материал?")) == 1;
}

//-----------------------------------------------------------------------------
// 
// ---
STDMETHODIMP_(VARIANT_BOOL) Document3DEvent::XDocument3DNotify::DeleteMaterial()
{
  METHOD_PROLOGUE_EX_(DocumentEvent, DocumentFileNotify)
    pThis->ShowEventName(_T("Document3DEvent::DeleteMaterial"));
  return true;
}

