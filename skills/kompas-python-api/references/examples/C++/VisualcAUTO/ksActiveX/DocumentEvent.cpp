#include "stdafx.h"
#include "DocumentEvent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  

#define CM_SYSTEMCONTROLSTOP            3406 // help остановить команду "Перейти под управление системы"

DocumentEvent::DocumentEvent( LPDISPATCH doc) : KSBaseEvent( doc, DIID_ksDocumentFileNotify, doc )
{
}

DocumentEvent::~DocumentEvent()
{
}

//********************************************************************
BEGIN_EVENTSINK_MAP(DocumentEvent, KSBaseEvent)
  ON_EVENT(DocumentEvent, (unsigned int)-1, kdBeginCloseDocument,  BeginCloseDocument,  VTS_NONE)
  ON_EVENT(DocumentEvent, (unsigned int)-1, kdCloseDocument,       CloseDocument,       VTS_NONE)
  ON_EVENT(DocumentEvent, (unsigned int)-1, kdBeginSaveDocument,   BeginSaveDocument,   VTS_BSTR)
  ON_EVENT(DocumentEvent, (unsigned int)-1, kdSaveDocument,        SaveDocument,        VTS_NONE)
  ON_EVENT(DocumentEvent, (unsigned int)-1, kdActiveDocument,      Activate,            VTS_NONE)
  ON_EVENT(DocumentEvent, (unsigned int)-1, kdDeactiveDocument,    Deactivate,          VTS_NONE)
  ON_EVENT(DocumentEvent, (unsigned int)-1, kdBeginSaveAsDocument, BeginSaveAsDocument, VTS_NONE)
END_EVENTSINK_MAP()

//********************************************************************
afx_msg VARIANT_BOOL DocumentEvent::BeginCloseDocument()
{
  kompas->ksSystemControlStop();
//  ::PostMessage( (HWND)kompas->ksGetHWindow(), WM_COMMAND, CM_SYSTEMCONTROLSTOP, 0 ); 
  return false;
}

afx_msg VARIANT_BOOL DocumentEvent::CloseDocument()
{
//  ::MessageBox(NULL, "Closing document", "", MB_OK);
  KSBaseEvent::TerminateEvents( GUID_NULL, NULL, m_doc );
  return true;
}

afx_msg VARIANT_BOOL DocumentEvent::BeginSaveDocument(LPCTSTR fileName)
{
  return true;
}

afx_msg VARIANT_BOOL DocumentEvent::SaveDocument()
{
//  ::MessageBox(NULL, "Document saved", "", MB_OK);
  return true;
}

afx_msg VARIANT_BOOL DocumentEvent::Activate()
{
  return true;
}

afx_msg VARIANT_BOOL DocumentEvent::Deactivate()
{
  return true;
}

afx_msg VARIANT_BOOL DocumentEvent::BeginSaveAsDocument()
{
  return true;
}
