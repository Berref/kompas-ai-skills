////////////////////////////////////////////////////////////////////////////////
//
// Step4_API7_3D.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STEP4_API7_3D_H__242CCE6E_6B2F_44C7_8C74_1C396BDD13F2__INCLUDED_)
#define AFX_STEP4_API7_3D_H__242CCE6E_6B2F_44C7_8C74_1C396BDD13F2__INCLUDED_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

extern IApplicationPtr newKompasAPI;

//------------------------------------------------------------------------------
// Вспомогательные функции
// ---
// Загрузка строки из ресурсов
CString LoadStr     (int strID);

#endif // !defined(AFX_STEP4_API7_3D_H__242CCE6E_6B2F_44C7_8C74_1C396BDD13F2__INCLUDED_)
