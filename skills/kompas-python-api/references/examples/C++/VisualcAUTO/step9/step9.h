// step9.h : main header file for the STEP9 DLL
//

#if !defined(AFX_STEP9_H__F92C2AE4_CDD0_11D4_872B_0050BADDB58C__INCLUDED_)
#define AFX_STEP9_H__F92C2AE4_CDD0_11D4_872B_0050BADDB58C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep9App
// See step9.cpp for the implementation of this class
//

class CStep9App : public CWinApp
{
public:
	CStep9App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStep9App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CStep9App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP9_H__F92C2AE4_CDD0_11D4_872B_0050BADDB58C__INCLUDED_)
