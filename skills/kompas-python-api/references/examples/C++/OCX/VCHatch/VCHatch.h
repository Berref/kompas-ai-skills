#if !defined(AFX_VCHATCH_H__189D0AA3_E82C_4F29_96DC_F8B6FB7BBF91__INCLUDED_)
#define AFX_VCHATCH_H__189D0AA3_E82C_4F29_96DC_F8B6FB7BBF91__INCLUDED_
////////////////////////////////////////////////////////////////////////////////
//
// Пример создания ActiveX Control-а
// Параметры штриховки
// <VCHatch.cpp>
//
////////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// VCHatch.h : main header file for VCHATCH.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVCHatchApp : See VCHatch.cpp for implementation.

class CVCHatchApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCHATCH_H__189D0AA3_E82C_4F29_96DC_F8B6FB7BBF91__INCLUDED)
