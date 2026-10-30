////////////////////////////////////////////////////////////////////////////////
//
// ConverterTst.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_CONVERTERTST_H__B4BA2B15_862A_4B2C_B925_DEE556C0FB30__INCLUDED_)
#define AFX_CONVERTERTST_H__B4BA2B15_862A_4B2C_B925_DEE556C0FB30__INCLUDED_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

//------------------------------------------------------------------------------
// Вспомогательные функции
// ---
// Загрузка строки из ресурсов
CString LoadStr   ( int strID );
int     LibMessage( char * str, int flags = MB_OK );
int     LibMessage( int  strId, int flags = MB_OK );

#endif // !defined(AFX_CONVERTERTST_H__B4BA2B15_862A_4B2C_B925_DEE556C0FB30__INCLUDED_)
