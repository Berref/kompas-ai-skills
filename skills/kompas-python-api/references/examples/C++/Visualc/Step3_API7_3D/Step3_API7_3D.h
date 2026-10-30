////////////////////////////////////////////////////////////////////////////////
//
// Step3_API7_3D.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STEP3_API7_3D_H__9E5F4CEB_A885_48DA_8255_E9988302D606__INCLUDED_)
#define AFX_STEP3_API7_3D_H__9E5F4CEB_A885_48DA_8255_E9988302D606__INCLUDED_

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

#endif // !defined(AFX_STEP3_API7_3D_H__9E5F4CEB_A885_48DA_8255_E9988302D606__INCLUDED_)
