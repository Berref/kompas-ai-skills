////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _DOCUMENTFRAMEEVENT_H
#include "DocumentFrameEvent.h"
#endif

#ifndef _DOCUMENTEVENT_H
#include "DocumentEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  

////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
DocumentEvent::DocumentEvent( LPDISPATCH doc, bool selfAdvise /*true*/ )
  : BaseEvent( doc, DIID_ksDocumentFileNotify, doc, -1, NULL, selfAdvise )
{
}


//-------------------------------------------------------------------------------
//
// ---
DocumentEvent::~DocumentEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(DocumentEvent, BaseEvent)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdBeginCloseDocument,    BeginCloseDocument,    VTS_NONE)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdCloseDocument,         CloseDocument,         VTS_NONE)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdBeginSaveDocument,     BeginSaveDocument,     VTS_BSTR)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdSaveDocument,          SaveDocument,          VTS_NONE)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdActiveDocument,        Activate,              VTS_NONE)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdDeactiveDocument,      Deactivate,            VTS_NONE)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdBeginSaveAsDocument,   BeginSaveAsDocument,   VTS_NONE)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdDocumentFrameOpen,     DocumentFrameOpen,     VTS_DISPATCH)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdProcessActivate,       ProcessActivate,       VTS_I4)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdProcessDeactivate,     ProcessDeactivate,     VTS_I4)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdBeginProcess,          BeginProcess,          VTS_I4)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdEndProcess,            EndProcess,            VTS_I4 VTS_BOOL)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdBeginAutoSaveDocument, BeginAutoSaveDocument, VTS_BSTR)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdAutoSaveDocument,      AutoSaveDocument,      VTS_NONE)

END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// kdBeginCloseDocument - Начало закрытия документа
// ---
afx_msg VARIANT_BOOL DocumentEvent::BeginCloseDocument()
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str( m_libName + " --> DocumentEvent::BeginCloseDocument" );
    str += "\nИмя документа = " + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}


//-----------------------------------------------------------------------------
// kdCloseDocument - Документ закрыт
// ---
afx_msg VARIANT_BOOL DocumentEvent::CloseDocument()
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str( m_libName + " --> DocumentEvent::CloseDocument" );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  TerminateEvents( GUID_NULL, m_doc );
  return true;
}


//-----------------------------------------------------------------------------
// kdBeginSaveDocument - Начало сохранения документа
// ---
afx_msg VARIANT_BOOL DocumentEvent::BeginSaveDocument( LPCTSTR fileName )
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str( m_libName + " --> DocumentEvent::BeginSaveDocument\nfileName = " + fileName );
    str += "\nИмя документа = " + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}


//-----------------------------------------------------------------------------
// kdSaveDocument - Документ сохранен
// ---
afx_msg VARIANT_BOOL DocumentEvent::SaveDocument()
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str( m_libName + " --> DocumentEvent::SaveDocument" );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}


//-----------------------------------------------------------------------------
// kdActiveDocument - Документ активизирован.
// ---
afx_msg VARIANT_BOOL DocumentEvent::Activate()
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str( m_libName + " --> DocumentEvent::Activate" );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}


//-----------------------------------------------------------------------------
// kdDeactiveDocument - Документ деактивизирован.
// ---
afx_msg VARIANT_BOOL DocumentEvent::Deactivate()
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str( m_libName + " --> DocumentEvent::Deactivate" );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}


//-----------------------------------------------------------------------------
// kdBeginSaveAsDocument - Начало сохранения документа c другим именем (до диалога выбора имени)
// ---
afx_msg VARIANT_BOOL DocumentEvent::BeginSaveAsDocument()
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str( m_libName + " --> DocumentEvent::BeginSaveAsDocument\n"
                 "Да - Сохранить чертеж\n" 
                 "Нет - запустить стандартный диалог сохранения файла\n"
                 "Отмена - не сохранять файл"  );
    int comm = kompas->ksYesNo( str.GetBuffer(0) );
    switch ( comm ) 
    {
      case 1: 
      {
        if( m_doc )
        { 
          ksDocument2DPtr doc2D;
          m_doc->QueryInterface( DIID_ksDocument2D, (LPVOID*)&doc2D );
          if( doc2D ) 
          {
            switch( kompas->ksGetDocumentType( doc2D->reference ) ) 
            {
              case lt_DocFragment:   
                 res = !doc2D->ksSaveDocument( "C:\\1.frw" );
                break;
              case lt_DocSheetStandart:
                case lt_DocSheetUser:
                res = !doc2D->ksSaveDocument( "C:\\1.cdw" );
                break;
            }
          }
          else
          {
            ksDocument3DPtr doc3D;
            m_doc->QueryInterface( DIID_ksDocument3D, (LPVOID*)&doc3D );
            if( doc3D ) 
            {  
              if( doc3D->IsDetail() )
                res = !doc3D->SaveAs( "C:\\1.m3d" ); 
              else
                res = !doc3D->SaveAs( "C:\\1.a3d" );
            }
            else
            {
              ksSpcDocumentPtr docSpc( m_doc );
              m_doc->QueryInterface( DIID_ksSpcDocument, (LPVOID*)&docSpc );
              if( docSpc ) 
              {   
                res = !docSpc->ksSaveDocument( "C:\\1.spw" );
              }
              else
              {
                ksDocumentTxtPtr docTxt( m_doc );
                m_doc->QueryInterface( DIID_ksDocumentTxt, (LPVOID*)&docTxt );
                if( docTxt ) 
                {   
                  res = !docTxt->ksSaveDocument( "C:\\1.kdw" );
                }
              }
            }
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

//-------------------------------------------------------------------------------
// kdDocumentFrameOpen - Окно документа открылось
// ---
VARIANT_BOOL DocumentEvent::DocumentFrameOpen( LPDISPATCH v ) {
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str( m_libName + " --> DocumentEvent::DocumentFrameOpen" );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }

  if( !BaseEvent::FindEvent( DIID_ksDocumentFrameNotify, (LPDISPATCH)m_pContainer ) )
  { 
    if ( v ) 
    {
      DocumentFrameEvent * frmEvent = new DocumentFrameEvent( v, (LPDISPATCH)m_pContainer ); 
      frmEvent->Advise();                                               
    }
  }
  return true;
}

//-------------------------------------------------------------------------------
// kdProcessActivate      - Активизация процесса
// ---
VARIANT_BOOL DocumentEvent::ProcessActivate( long Id )
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str;
    str.Format(_T("%s --> DocumentEvent::ProcessActivate\nId = %i"), (LPCTSTR)m_libName, Id);
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// kdProcessDeactivate    - Деактивизация процесса
// ---
VARIANT_BOOL DocumentEvent::ProcessDeactivate( long Id )
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str;
    str.Format( _T( "%s --> DocumentEvent::ProcessDeactivate\nId = %i" ), (LPCTSTR)m_libName, Id );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// kdBeginProcess         - Начало процесса
// ---
VARIANT_BOOL DocumentEvent::BeginProcess( long Id )
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str;
    str.Format( _T( "%s --> DocumentEvent::BeginProcess\nId = %i" ), (LPCTSTR)m_libName, Id );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// kdEndProcess           - Завершение процесса
// ---
VARIANT_BOOL DocumentEvent::EndProcess( long Id, VARIANT_BOOL Success )
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str;
    str.Format( _T( "%s --> DocumentEvent::EndProcess\nId = %i" ), (LPCTSTR)m_libName, Id );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// kdBeginAutoSaveDocument - Начало автосохранения документа
// ---
VARIANT_BOOL DocumentEvent::BeginAutoSaveDocument( LPCTSTR docName )
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str;
    str.Format( _T( "%s --> DocumentEvent::BeginAutoSaveDocument\ndocName = %s" ), (LPCTSTR)m_libName, (LPCTSTR)docName );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// kdAutoSaveDocument     - Документ автосохранен
// ---
VARIANT_BOOL DocumentEvent::AutoSaveDocument()
{
  if ( IsSelfAdvise() && theApp.m_mes_DOC )
  {
    CString str;
    str.Format( _T( "%s --> DocumentEvent::AutoSaveDocument" ), (LPCTSTR)m_libName );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}
