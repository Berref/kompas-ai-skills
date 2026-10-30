// step5.h : main header file for the STEP5 DLL
//

#if !defined(AFX_STEP5_H__E07D1F64_D1B1_11D4_872B_0050BADDB58C__INCLUDED_)
#define AFX_STEP5_H__E07D1F64_D1B1_11D4_872B_0050BADDB58C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep5App
// See step5.cpp for the implementation of this class
//

class CStep5App : public CWinApp
{
public:
	CStep5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStep5App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CStep5App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP5_H__E07D1F64_D1B1_11D4_872B_0050BADDB58C__INCLUDED_)
