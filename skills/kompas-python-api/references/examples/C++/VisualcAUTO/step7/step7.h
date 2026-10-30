// step7.h : main header file for the STEP7 DLL
//

#if !defined(AFX_STEP7_H__C2A199A4_D2AE_11D4_872B_0050BADDB58C__INCLUDED_)
#define AFX_STEP7_H__C2A199A4_D2AE_11D4_872B_0050BADDB58C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep7App
// See step7.cpp for the implementation of this class
//

class CStep7App : public CWinApp
{
public:
	CStep7App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStep7App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CStep7App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP7_H__C2A199A4_D2AE_11D4_872B_0050BADDB58C__INCLUDED_)
