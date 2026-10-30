////////////////////////////////////////////////////////////////////////////////
//
// SpecificationEvent  - обработчик событий от спецификации
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h" 
#include "eventsAuto.h"

#ifndef _SPECIFICATIONEVENT_H
#include "SpecificationEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  

////////////////////////////////////////////////////////////////////////////////
//
// SpecificationEvent  - обработчик событий от спецификации
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
SpecificationEvent::SpecificationEvent( LPUNKNOWN pObject, LPDISPATCH doc, bool selfAdvise /*true*/ )
  : BaseEvent( pObject, DIID_ksSpecificationNotify, doc, -1, NULL, selfAdvise )
{  
}


//-------------------------------------------------------------------------------
//
// ---
SpecificationEvent::~SpecificationEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(SpecificationEvent, BaseEvent)
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssTuningSpcStyleBeginChange,   TuningSpcStyleBeginChange,   VTS_BSTR VTS_I4)      
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssTuningSpcStyleChange,        TuningSpcStyleChange,        VTS_BSTR VTS_I4 VTS_BOOL)     
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssChangeCurrentSpcDescription, ChangeCurrentSpcDescription, VTS_BSTR VTS_I4)    
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssSpcDescriptionAdd,           SpcDescriptionAdd,           VTS_BSTR VTS_I4)              
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssSpcDescriptionRemove,        SpcDescriptionRemove,        VTS_BSTR VTS_I4)           
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssSpcDescriptionBeginEdit,     SpcDescriptionBeginEdit,     VTS_BSTR VTS_I4)        
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssSpcDescriptionEdit,          SpcDescriptionEdit,          VTS_BSTR VTS_I4 VTS_BOOL)       
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssSynchronizationBegin,        SynchronizationBegin,        VTS_NONE)
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssSynchronization,             Synchronization,             VTS_NONE)
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssBeginCalcPositions,          BeginCalcPositions,          VTS_NONE)
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssCalcPositions,               CalcPositions,               VTS_NONE)
  ON_EVENT (SpecificationEvent, (unsigned int)-1, ssBeginCreateObject,           BeginCreateObject,           VTS_I4)
END_EVENTSINK_MAP() 


//-------------------------------------------------------------------------------
// ssTuningSpcStyleBeginChange - Начало изменения настроек спецификации
// ---
VARIANT_BOOL SpecificationEvent::TuningSpcStyleBeginChange( LPCTSTR libName, long numb )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpecificationEvent::TuningSpcStyleBeginChange\nlibName = %s\nnumb = %i"), (LPCTSTR)m_libName, libName, numb ); 
    str += "\nИмя документа = " + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true; 
}


//-------------------------------------------------------------------------------
// ssTuningSpcStyleChange - Настроейки спецификации изменились
// ---
VARIANT_BOOL SpecificationEvent::TuningSpcStyleChange( LPCTSTR libName, long numb, BOOL isOk )
{
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpecificationEvent::TuningSpcStyleChange\nlibName = %s\nnumb = %i\nisOk = %s"), (LPCTSTR)m_libName, libName, numb, isOk ? "TRUE" : "FALSE" );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;      
}


//-------------------------------------------------------------------------------
// ssChangeCurrentSpcDescription - Изменилось текущее описание спецификации
// ---
VARIANT_BOOL SpecificationEvent::ChangeCurrentSpcDescription( LPCTSTR libName, long numb )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpecificationEvent::ChangeCurrentSpcDescription\nlibName = %s\nnumb = %i"), (LPCTSTR)m_libName, libName, numb ); 
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true; 
}


//-------------------------------------------------------------------------------
// ssSpcDescriptionAdd - Добавилось описание спецификации
// ---
VARIANT_BOOL SpecificationEvent::SpcDescriptionAdd( LPCTSTR libName, long numb )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpecificationEvent::SpcDescriptionAdd\nlibName = %s\nnumb = %i"), (LPCTSTR)m_libName, libName, numb ); 
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// ssSpcDescriptionRemove - Удалилось описание спецификации
// ---
VARIANT_BOOL SpecificationEvent::SpcDescriptionRemove( LPCTSTR libName, long numb )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpecificationEvent::SpcDescriptionRemove\nlibName = %s\nnumb = %i"), (LPCTSTR)m_libName, libName, numb ); 
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// ssSpcDescriptionBeginEdit - Начало редактирования описания спецификации
// ---
VARIANT_BOOL SpecificationEvent::SpcDescriptionBeginEdit( LPCTSTR libName, long numb )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpecificationEvent::SpcDescriptionBeginEdit\nlibName = %s\nnumb = %i"), (LPCTSTR)m_libName, libName, numb ); 
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true; 
}


//-------------------------------------------------------------------------------
// ssSpcDescriptionEdit - Отредактировали описание спецификации
// ---
VARIANT_BOOL SpecificationEvent::SpcDescriptionEdit( LPCTSTR libName, long numb, BOOL isOk  )
{
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpecificationEvent::SpcDescriptionEdit\nlibName = %s\nnumb = %i\nisOk = %s"), (LPCTSTR)m_libName, libName, numb, isOk ? "TRUE" : "FALSE" );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true; 
}


//-------------------------------------------------------------------------------
// ssSynchronizationBegin - Начало синхронизации
// ---
VARIANT_BOOL SpecificationEvent::SynchronizationBegin()
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str( m_libName + _T(" --> SpecificationEvent::SynchronizationBegin") );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// ssSynchronization - Синхронизация проведена
// ---
VARIANT_BOOL SpecificationEvent::Synchronization()
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str( m_libName + " --> SpecificationEvent::Synchronization" );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// ssBeginCalcPositions - Начало  расчета позиций
// ---
VARIANT_BOOL SpecificationEvent::BeginCalcPositions()
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str( m_libName + " --> SpecificationEvent::BeginCalcPositions" );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// ssCalcPositions - Проведен расчет позиций 
// ---
VARIANT_BOOL SpecificationEvent::CalcPositions()
{ 
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str( m_libName + " --> SpecificationEvent::CalcPositions" );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// ssBeginCreateObject - Начало создания объекта спецификации (до диалога выбора раздела ) 
// ---
VARIANT_BOOL SpecificationEvent::BeginCreateObject( long typeObj )
{
  if ( IsSelfAdvise() && theApp.m_mes_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpecificationEvent::BeginCreateObject\ntypeObj = %i"), (LPCTSTR)m_libName, typeObj );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}
