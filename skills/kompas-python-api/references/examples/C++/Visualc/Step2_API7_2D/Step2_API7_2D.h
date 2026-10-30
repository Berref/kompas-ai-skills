////////////////////////////////////////////////////////////////////////////////
//
// Step2_API7_2D.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STEP2_API7_2D_H__37948C83_1171_406C_AB22_B4302404E3AB__INCLUDED_)
#define AFX_STEP2_API7_2D_H__37948C83_1171_406C_AB22_B4302404E3AB__INCLUDED_

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

#endif // !defined(AFX_STEP2_API7_2D_H__37948C83_1171_406C_AB22_B4302404E3AB__INCLUDED_)
