////////////////////////////////////////////////////////////////////////////////
//
// MacroObj.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STEP4_H__25D648C3_F539_4EDB_84BE_234A9686A8C2__INCLUDED_)
#define AFX_STEP4_H__25D648C3_F539_4EDB_84BE_234A9686A8C2__INCLUDED_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


//------------------------------------------------------------------------------
// Вспомогательные функции
// ---
// Полное имя файла
CString FullFileName( CString patch, CString fileName );
// Полное имя файла
bool    GetFullName ( char * inName, char * outName, int outNameLen );
// Проверить существование файла
bool    ExistFile   ( char * file );
// Загрузка строки из ресурсов
CString LoadStr     (int strID);

#endif // !defined(AFX_STEP4_H__25D648C3_F539_4EDB_84BE_234A9686A8C2__INCLUDED_)
