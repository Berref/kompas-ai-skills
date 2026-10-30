////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent.cpp
// SelectMngEvent - обработчик событий от приложения (COM)
//
////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#ifndef _SELECTMNGEVENT_H
#include "SelectMngEvent.h"
#endif

#include <ksConstants.h>

#ifndef _LTOOL3D_H
#include <ltool3d.h>
#endif

extern int LibMessage( char* str, int flags  = MB_OK );
//-------------------------------------------------------------------------------
//
// ---
SelectMngEvent::SelectMngEvent( reference refDoc ) :
  TBaseEvent<ISelectionMngNotify, & IID_ISelectionMngNotify>( ntSelectionMngNotify, refDoc ),
  m_refDoc( refDoc )
{
}

//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
VARIANT_BOOL STDMETHODCALLTYPE SelectMngEvent::IsNotifyProcess( int notifyType )
{
	return  notifyType >= ksmSelect && notifyType <= ksmUnselectAll;
}

//-------------------------------------------------------------------------------
// Объект селектирован
// ---
VARIANT_BOOL STDMETHODCALLTYPE SelectMngEvent::Select( VARIANT obj )
{
  if ( obj.vt == VT_I4 )
  {
    MoveObj( obj.lVal, 30, 0 );
  }
  else if ( obj.vt == VT_UNKNOWN )
  {
    LPDOCUMENT3D doc = ksGet3dDocumentFromReference( m_refDoc );
    if ( doc )
    {
      int type = type = doc->GetObjectType( obj.punkVal );
      AnsiString str( "type = " );
      str += type;
      ::LibMessage( str.c_str() );
      doc->Release();
    }
  }

  ::LibMessage( "SelectMngEvent - Объект селектирован\n" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Объект расселектирован
// ---
VARIANT_BOOL STDMETHODCALLTYPE SelectMngEvent::Unselect( VARIANT obj )
{
  int type = -1;
  if ( obj.vt == VT_I4 )
  {
    MoveObj( obj.lVal, -30, 0 );
  }
  else if ( obj.vt == VT_UNKNOWN )
  {
    LPDOCUMENT3D doc = ksGet3dDocumentFromReference( m_refDoc );
    if ( doc )
    {
      type = doc->GetObjectType( obj.punkVal );
      AnsiString str( "type = " );
      str += type;
      ::LibMessage( str.c_str() );
      doc->Release();
    }
  }

  ::LibMessage( "SelectMngEvent - Объект расселектирован\n" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Все объекты расселектированы
// ---
VARIANT_BOOL STDMETHODCALLTYPE SelectMngEvent::UnselectAll( void )
{
  ::LibMessage( "SelectMngEvent - Все объекты расселектированы" );
  return TRUE;
}
