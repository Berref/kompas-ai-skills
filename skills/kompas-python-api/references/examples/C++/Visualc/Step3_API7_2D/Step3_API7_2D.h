////////////////////////////////////////////////////////////////////////////////
//
// Step3_API7_2D.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_STEP3_API7_2D_H__1B767A05_DCC6_44BE_8C1C_569870582E45__INCLUDED_)
#define AFX_STEP3_API7_2D_H__1B767A05_DCC6_44BE_8C1C_569870582E45__INCLUDED_

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

#endif // !defined(AFX_STEP3_API7_2D_H__1B767A05_DCC6_44BE_8C1C_569870582E45__INCLUDED_)
