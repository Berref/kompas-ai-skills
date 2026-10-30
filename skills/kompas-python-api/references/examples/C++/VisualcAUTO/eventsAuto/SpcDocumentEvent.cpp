////////////////////////////////////////////////////////////////////////////////
//
// SpcDocumentEvent  - обработчик событий от документа спецификации
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _SPCDOCUMENTEVENT_H
#include "SpcDocumentEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  

////////////////////////////////////////////////////////////////////////////////
//
// SpcDocumentEvent  - обработчик событий от документа спецификации
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
SpcDocumentEvent::SpcDocumentEvent( LPUNKNOWN pObject, LPDISPATCH doc, bool selfAdvise /*true*/ )
: BaseEvent( pObject, DIID_ksSpcDocumentNotify, doc, -1, NULL, selfAdvise )
{
}


//-------------------------------------------------------------------------------
//
// ---
SpcDocumentEvent::~SpcDocumentEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(SpcDocumentEvent, BaseEvent)
  ON_EVENT (SpcDocumentEvent, (unsigned int)-1, sdDocumentBeginAdd,    DocumentBeginAdd,    VTS_NONE)
  ON_EVENT (SpcDocumentEvent, (unsigned int)-1, sdDocumentAdd,         DocumentAdd,         VTS_BSTR)
  ON_EVENT (SpcDocumentEvent, (unsigned int)-1, sdDocumentBeginRemove, DocumentBeginRemove, VTS_BSTR)
  ON_EVENT (SpcDocumentEvent, (unsigned int)-1, sdDocumentRemove,      DocumentRemove,      VTS_BSTR)
  ON_EVENT (SpcDocumentEvent, (unsigned int)-1, sdSpcStyleBeginChange, SpcStyleBeginChange, VTS_BSTR VTS_I4)
  ON_EVENT (SpcDocumentEvent, (unsigned int)-1, sdSpcStyleChange,      SpcStyleChange,      VTS_BSTR VTS_I4)
END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
// sdDocumentBeginAdd - Начало добавления документа сборочного чертежа
// ---
afx_msg VARIANT_BOOL SpcDocumentEvent::DocumentBeginAdd()
{
  if ( IsSelfAdvise() && theApp.m_mes_SPCDOC )
  {
    CString str( m_libName + " --> SpcDocumentEvent::DocumentBeginAdd" );
    str += "\nИмя документа = " + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// sdDocumentAdd - Добавление документа сборочного чертежа
// ---
afx_msg VARIANT_BOOL SpcDocumentEvent::DocumentAdd( LPCTSTR docName )
{
  if ( IsSelfAdvise() && theApp.m_mes_SPCDOC )
  {
    CString str( m_libName + " --> SpcDocumentEvent::DocumentAdd\ndocName = " + docName );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}
      

//-------------------------------------------------------------------------------
// sdDocumentBeginRemove - Начало удаления документа сборочного чертежа
// ---
afx_msg VARIANT_BOOL SpcDocumentEvent::DocumentBeginRemove( LPCTSTR docName)
{
  if ( IsSelfAdvise() && theApp.m_mes_SPCDOC )
  {
    CString str( m_libName + " --> SpcDocumentEvent::DocumentBeginRemove\ndocName =" + docName );
    str += "\nИмя документа = " + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// sdDocumentRemove - Удаление документа сборочного чертежа
// ---
afx_msg VARIANT_BOOL SpcDocumentEvent::DocumentRemove( LPCTSTR docName )
{
  if ( IsSelfAdvise() && theApp.m_mes_SPCDOC )
  {
    CString str( m_libName + " --> SpcDocumentEvent::DocumentRemove\ndocName =" + docName );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// sdSpcStyleBeginChange - Начало изменения стиля спецификации
// ---
afx_msg VARIANT_BOOL SpcDocumentEvent::SpcStyleBeginChange( LPCTSTR libName, long numb )
{
  if ( IsSelfAdvise() && theApp.m_mes_SPCDOC )
  {
    CString str;
    str.Format( _T("%s --> SpcDocumentEvent::SpcStyleBeginChange\nlibName = %s\nnumb = %i"), (LPCTSTR)m_libName, libName, numb );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true;
}


//-------------------------------------------------------------------------------
// sdSpcStyleChange - Стиль спецификации изменился
// ---
afx_msg VARIANT_BOOL SpcDocumentEvent::SpcStyleChange( LPCTSTR libName, long numb )
{
  if ( IsSelfAdvise() && theApp.m_mes_SPCDOC )
  {
    CString str;
    str.Format( _T("%s --> SpcDocumentEvent::SpcStyleChange\nlibName = %s\nnumb = %i"), m_libName, libName, numb );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


