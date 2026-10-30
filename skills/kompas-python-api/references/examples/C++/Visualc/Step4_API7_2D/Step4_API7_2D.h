////////////////////////////////////////////////////////////////////////////////
//
// Step4_API7_2D.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STEP4_API7_2D_H__F33DE604_0367_4021_9225_18FF5DF7A9F3__INCLUDED_)
#define AFX_STEP4_API7_2D_H__F33DE604_0367_4021_9225_18FF5DF7A9F3__INCLUDED_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

extern ksAPI7::IApplicationPtr newKompasAPI;

//------------------------------------------------------------------------------
// Вспомогательные функции
// ---
// Загрузка строки из ресурсов
CString LoadStr     (int strID);

#endif // !defined(AFX_STEP4_API7_2D_H__F33DE604_0367_4021_9225_18FF5DF7A9F3__INCLUDED_)
