////////////////////////////////////////////////////////////////////////////////
//
// UserSymbolWithLeader.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_USERSYMBOLWITHLEADER_H__011ABA6D_327B_49B0_B5CB_423BA9670329__INCLUDED_)
#define AFX_USERSYMBOLWITHLEADER_H__011ABA6D_327B_49B0_B5CB_423BA9670329__INCLUDED_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

// extern KompasObjectPtr kompas;
extern IApplicationPtr newKompasAPI;

//------------------------------------------------------------------------------
// Вспомогательные функции
// ---
// Загрузка строки из ресурсов
CString LoadStr     (int strID);

#endif // !defined(AFX_USERSYMBOLWITHLEADER_H__011ABA6D_327B_49B0_B5CB_423BA9670329__INCLUDED_)
