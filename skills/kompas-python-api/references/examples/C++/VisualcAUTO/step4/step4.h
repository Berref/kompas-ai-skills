// step4.h : main header file for the STEP4 DLL
//

#if !defined(AFX_STEP4_H__126AF305_D1E2_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_STEP4_H__126AF305_D1E2_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep4App
// See step4.cpp for the implementation of this class
//

class CStep4App : public CWinApp
{
public:
	CStep4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStep4App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CStep4App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP4_H__126AF305_D1E2_11D4_BF5E_0050BADBD5F5__INCLUDED_)
