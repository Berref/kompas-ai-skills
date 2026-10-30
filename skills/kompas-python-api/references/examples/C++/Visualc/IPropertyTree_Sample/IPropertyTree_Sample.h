////////////////////////////////////////////////////////////////////////////////
//
// IPropertyTree_Sample.h - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_IPropertyTree_Sample_H__149EA995_A65C_41D4_8AA0_A7E3D00086C6__INCLUDED_)
#define AFX_IPropertyTree_Sample_H__149EA995_A65C_41D4_8AA0_A7E3D00086C6__INCLUDED_

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

#endif // !defined(AFX_IPropertyTree_Sample_H__149EA995_A65C_41D4_8AA0_A7E3D00086C6__INCLUDED_)
