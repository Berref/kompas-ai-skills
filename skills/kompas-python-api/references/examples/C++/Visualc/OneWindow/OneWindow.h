////////////////////////////////////////////////////////////////////////////////
//
// OneWindow.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_ONEWINDOW_H__93DB96D6_F762_4049_9780_5F90290F7412__INCLUDED_)
#define AFX_ONEWINDOW_H__93DB96D6_F762_4049_9780_5F90290F7412__INCLUDED_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

extern KompasObjectPtr kompas;
extern IApplicationPtr newKompasAPI;

//------------------------------------------------------------------------------
// Вспомогательные функции
// ---
// Загрузка строки из ресурсов
_bstr_t LoadStr( int strID );

#endif // !defined(AFX_ONEWINDOW_H__93DB96D6_F762_4049_9780_5F90290F7412__INCLUDED_)
