// vcprj.h : main header file for the VCPRJ application
//

#if !defined(AFX_VCPRJ_H__3876F925_6893_11D5_94AD_FC019B4CD066__INCLUDED_)
#define AFX_VCPRJ_H__3876F925_6893_11D5_94AD_FC019B4CD066__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVcprjApp:
// See vcprj.cpp for the implementation of this class
//

class CVcprjApp : public CWinApp
{
public:
	CVcprjApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVcprjApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVcprjApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCPRJ_H__3876F925_6893_11D5_94AD_FC019B4CD066__INCLUDED_)
