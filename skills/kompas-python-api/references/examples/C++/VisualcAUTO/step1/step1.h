// step1.h : main header file for the STEP1 DLL
//

#if !defined(AFX_STEP1_H__200000C4_CD17_11D4_87AE_0050BABDCDF3__INCLUDED_)
#define AFX_STEP1_H__200000C4_CD17_11D4_87AE_0050BABDCDF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep1App
// See step1.cpp for the implementation of this class
//

class CStep1App : public CWinApp
{
public:
  CStep1App();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CStep1App)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CStep1App)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP1_H__200000C4_CD17_11D4_87AE_0050BABDCDF3__INCLUDED_)
