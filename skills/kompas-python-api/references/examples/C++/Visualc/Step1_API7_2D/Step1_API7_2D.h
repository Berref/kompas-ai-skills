////////////////////////////////////////////////////////////////////////////////
//
// DocCollection.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_DOCCOLLECTION_H__337F062A_1C86_44FE_90FC_52774C42868A__INCLUDED_)
#define AFX_DOCCOLLECTION_H__337F062A_1C86_44FE_90FC_52774C42868A__INCLUDED_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
// AAA K10 #include <LibToolA/SelfText.h>
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

#endif // !defined(AFX_DOCCOLLECTION_H__337F062A_1C86_44FE_90FC_52774C42868A__INCLUDED_)
