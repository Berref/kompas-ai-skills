#ifndef __PARMACRO_H
#define __PARMACRO_H

#include "stdafx.h"
#include <afxtempl.h>

enum parMacroItemType {  pmFloat, pmInt, pmChar };

//-------------------------------------------------------------------------------
//
// ---
class  ParMacroItem {
public :
	void*						 v;
	parMacroItemType type;
	int							 columnId;
	ParMacroItem() : v( NULL ), type( pmFloat ), columnId( 0 ) {}
	ParMacroItem( void * _v,  parMacroItemType _type, int  _columnId ) : v( _v ),
																																			type( _type ),
																																			columnId( _columnId ) {}
	LPCTSTR GetString();
};

//-------------------------------------------------------------------------------
//
// ---
class ParMacroListWiew : public CListCtrl {
protected :
CArray<ParMacroItem,ParMacroItem> arrItem;

public :
  ParMacroListWiew() : CListCtrl() {}
  void AddParItem( void* v, parMacroItemType par, int columnId );
  void SetupWiew();
  void Show();
  void Flush();
};

typedef ParMacroListWiew CParamList;

#endif
