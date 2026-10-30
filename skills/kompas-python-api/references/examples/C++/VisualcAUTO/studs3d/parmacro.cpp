#include "stdafx.h"

#ifndef __PARMACRO_H
#include "parmacro.h"
#endif

static TCHAR bufStr[255];

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
LPCTSTR ParMacroItem::GetString() {
  switch ( type ) {
    case  pmFloat :
      ::_stprintf_s( bufStr, _T("%g"), * (float*)v );
      break;
    case  pmInt :
      ::_stprintf_s( bufStr, _T("%d"), * (int*)v );
      break;
    case  pmChar :
      ::_tcscpy_s( bufStr, ( LPCTSTR )v );
      break;
  }
  return bufStr;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
void ParMacroListWiew::AddParItem( void* v, parMacroItemType par, int columnId ) {
  arrItem.Add( ParMacroItem(v, par, columnId) );
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
void ParMacroListWiew::SetupWiew() {
  UINT count = arrItem.GetSize(); 
  if ( count ) {
    CRect r;
    GetClientRect( &r );
    int width = (r.Width() - 2) / count; 

    for ( UINT i = 0; i < count; i++ ) {
      CString buf;
      buf.LoadString( arrItem[i].columnId );
      InsertColumn( i, buf, LVCFMT_LEFT, width );
    }
    InsertItem( 0, _T("") );  
  }

  Show();
  ShowScrollBar( SB_BOTH, false );
}


//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
void ParMacroListWiew::Flush() {
  UINT count = arrItem.GetSize(); 

  if ( count ) {
    DeleteAllItems();
    for ( int i = count - 1; i >= 0; i-- )
      DeleteColumn( i );
  }
  arrItem.RemoveAll(); 
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
void ParMacroListWiew::Show() {
  UINT count = arrItem.GetSize(); 
  if ( count ) 
    for ( UINT i = 0; i < count; i++ ) 
      SetItemText( 0, i, arrItem[i].GetString() );
}


