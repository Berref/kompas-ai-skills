////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent  - обработчик событий от менеджера селектирования документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _SELECTMNGEVENT_H
#include "SelectMngEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent  - обработчик событий от менеджера селектирования документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
SelectMngEvent::SelectMngEvent( LPUNKNOWN pObject, LPDISPATCH doc, bool selfAdvise /*true*/ )
: BaseEvent( pObject, DIID_ksSelectionMngNotify, doc, -1, NULL, selfAdvise )
{
}


//-------------------------------------------------------------------------------
//
// ---
SelectMngEvent::~SelectMngEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(SelectMngEvent, BaseEvent)
  ON_EVENT (SelectMngEvent, (unsigned int)-1, ksmSelect,      Select,      VTS_VARIANT)
  ON_EVENT (SelectMngEvent, (unsigned int)-1, ksmUnselect,    Unselect,    VTS_VARIANT)
  ON_EVENT (SelectMngEvent, (unsigned int)-1, ksmUnselectAll, UnselectAll, VTS_NONE)
END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
// ksmSelect      - Объект селектирован
// ---
VARIANT_BOOL SelectMngEvent::Select( LPVARIANT obj ) 
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SELECT )
  {
    CString str;
    str.Format( _T("%s --> SelectMngEvent::Select\nobj = %i"), (LPCTSTR)m_libName, obj );
    str += "\nИмя документа = " + GetDocName();
    //kompas->ksMessag( (LPCTSTR)str );
    ksDocument3DPtr doc3D( kompas->ActiveDocument3D() );
    if ( doc3D )
    {
      ksSelectionMngPtr sm( doc3D->GetSelectionMng() );
      if ( sm )
      {
        for ( long i = 0, count = sm->GetCount(); i < count; i++ )
        {
          long type = sm->GetObjectType(i);
          if ( type == o3d_entity )
          {
            ksEntityPtr obj( sm->GetObjectByIndex(i) );
            ASSERT(obj);
          }
        }
      }
    }
  }
  return true;
}


//-------------------------------------------------------------------------------
// ksmUnselect    - Объект расселектирован
// ---
VARIANT_BOOL SelectMngEvent::Unselect( LPVARIANT obj )
{
  if ( IsSelfAdvise() && theApp.m_mes_SELECT )
  {
    CString str;
    str.Format( _T("%s --> SelectMngEvent::Unselect\nobj = %i"), (LPCTSTR)m_libName, obj );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// ksmUnselectAll - Все объекты расселектированы
// ---
VARIANT_BOOL SelectMngEvent::UnselectAll() 
{
  if ( IsSelfAdvise() && theApp.m_mes_SELECT )
  {
    CString str( m_libName + _T(" --> SelectMngEvent::UnselectAll") );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}