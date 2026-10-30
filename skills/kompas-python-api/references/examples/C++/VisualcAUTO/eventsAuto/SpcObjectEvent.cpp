////////////////////////////////////////////////////////////////////////////////
//
// SpcObjectEvent - обработчик событий объектов документа спецификации
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"
/*
#ifndef __LDEFIN2D_H
#include <ldefin2d.h>
#endif
*/
#ifndef _SPCOBJECTEVENT_H
#include "SpcObjectEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////////
//
// SpcObjectEvent - обработчик событий объектов документа спецификации
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
SpcObjectEvent::SpcObjectEvent( LPUNKNOWN object, 
                                LPDISPATCH doc, 
                                long objType, 
                                bool selfAdvise /*true*/ )
  : BaseEvent( object, DIID_ksSpcObjectNotify, doc, objType, NULL, selfAdvise )
{
}


//-------------------------------------------------------------------------------
//
// ---
SpcObjectEvent::~SpcObjectEvent()
{
}
      

//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(SpcObjectEvent, BaseEvent)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soBeginDelete,      BeginDelete,      VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soDelete,           Delete,           VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soCellDblClick,     CellDblClick,     VTS_I4 VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soCellBeginEdit,    CellBeginEdit,    VTS_I4 VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soChangeCurrent,    ChangeCurrent,    VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soDocumentBeginAdd, DocumentBeginAdd, VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soDocumentAdd,      DocumentAdd,      VTS_I4 VTS_BSTR)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soDocumentRemove,   DocumentRemove,   VTS_I4 VTS_BSTR)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soBeginGeomChange,  BeginGeomChange,  VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soGeomChange,       GeomChange,       VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soBeginProcess,     BeginProcess,     VTS_I4 VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soEndProcess,       EndProcess,       VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soCreateObject,     CreateObject,     VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soUpdateObject,     UpdateObject,     VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soBeginCopy,        BeginCopy,        VTS_I4)
  ON_EVENT (SpcObjectEvent, (unsigned int)-1, soCopy,             Copy,             VTS_I4)
END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
// koBeginDelete - Попытка удаления объекта
// ---
VARIANT_BOOL SpcObjectEvent::BeginDelete( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::BeginDelete\nobjRef = %i"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true;
}


//-------------------------------------------------------------------------------
// koDelete - Объект удален
// ---
VARIANT_BOOL SpcObjectEvent::Delete( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::Delete\nobjRef = %i"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  // Если удаляется объект удаляем и подписку на его события
  // Либо тип объекта : 0, SPC_BASE_OBJECT, SPC_COMMENT, либо указатель на объект
  if ( objRef && objRef == m_objType )
    delete this; 
  return true;
}
       

//-------------------------------------------------------------------------------
// soCellDblClick - Двойной клик в ячейке 
// ---
VARIANT_BOOL SpcObjectEvent::CellDblClick(long objRef, long number)
{ 
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::CellDblClick\nobjRef = %i\nnumber = %i"), (LPCTSTR)m_libName, objRef, number );
    str += _T("\nИмя документа = ") + GetDocName(); 
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true;  
}


//-------------------------------------------------------------------------------
// soCellBeginEdit - Начало редактирования в ячейке   
// ---
VARIANT_BOOL SpcObjectEvent::CellBeginEdit(long objRef, long number) 
{ 
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::CellBeginEdit\nobjRef = %i\nnumber = %i"), (LPCTSTR)m_libName, objRef, number );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true;
}


//------------------------------------------------------------------------------- 
// soChangeCurrent - Изменился текущий объект  
// ---
VARIANT_BOOL SpcObjectEvent::ChangeCurrent( long objRef )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::ChangeCurrent\nobjRef = %i"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;  
}


//-------------------------------------------------------------------------------
// soDocumentBeginAdd - Начало добавления документа
// ---
VARIANT_BOOL SpcObjectEvent::DocumentBeginAdd( long objRef )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::DocumentBeginAdd\nobjRef = %i"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true;
}


//-------------------------------------------------------------------------------
// soDocumentAdd - Добавление документа в объекте СП   
// ---
VARIANT_BOOL SpcObjectEvent::DocumentAdd( long objRef, LPCTSTR docName ) 
{ 
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::DocumentAdd\nobjRef = %i\ndocName = %s"), (LPCTSTR)m_libName, objRef, docName );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true; 
}


//-------------------------------------------------------------------------------
// soDocumentRemove - Удаление документа из объекта СП  
// ---
VARIANT_BOOL SpcObjectEvent::DocumentRemove( long objRef, LPCTSTR docName )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::DocumentRemove\nobjRef = %i\ndocName = %s"), (LPCTSTR)m_libName, objRef, docName );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// soBeginGeomChange - Начало измения геометрии объекта СП
// ---
VARIANT_BOOL SpcObjectEvent::BeginGeomChange( long objRef )
{ 
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::BeginGeomChange\nobjRef = %i"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true;
}


//-------------------------------------------------------------------------------
// soGeomChange - Геометрия объекта СП изменилась    
// ---
VARIANT_BOOL SpcObjectEvent::GeomChange( long objRef ) 
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::GeomChange\nobjRef = %i"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;  
}


//-------------------------------------------------------------------------------
// koBeginProcess - Начало редактирования\создания объекта
// ---
VARIANT_BOOL SpcObjectEvent::BeginProcess( long pType, long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::BeginProcess\npType = %i\nobjRef = %i"), (LPCTSTR)m_libName, pType, objRef ); 
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str ); 
  }
  return true;  
}
       

//-------------------------------------------------------------------------------
// koEndProcess - Конец редактирования\создания объекта
// ---
VARIANT_BOOL SpcObjectEvent::EndProcess( long pType )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::EndProcess\npType = %i"), (LPCTSTR)m_libName, pType );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true; 
}


//-------------------------------------------------------------------------------
// koCreate - Создание объектов
// ---
VARIANT_BOOL SpcObjectEvent::CreateObject( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::CreateObject\nobjRef = %i"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true; 
}

    
//-------------------------------------------------------------------------------
// koUpdateObject - Редактирование объекта
// ---
VARIANT_BOOL SpcObjectEvent::UpdateObject( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T("%s --> SpcObjectEvent::UpdateObject\nobjRef = %i"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }   
  return true;
}

//-------------------------------------------------------------------------------
// soBeginCopy - Начало копирования объекта
// ---
VARIANT_BOOL SpcObjectEvent::BeginCopy( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T( "%s --> SpcObjectEvent::BeginCopy\nobjRef = %i" ), (LPCTSTR)m_libName, objRef );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// soCopy - Копирование объекта
// ---
VARIANT_BOOL SpcObjectEvent::Copy( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_SPC )
  {
    CString str;
    str.Format( _T( "%s --> SpcObjectEvent::Copy\nobjRef = %i" ), (LPCTSTR)m_libName, objRef );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

