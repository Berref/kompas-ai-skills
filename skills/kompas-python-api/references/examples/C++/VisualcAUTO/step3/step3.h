// step3.h : main header file for the STEP3 DLL
//

#if !defined(AFX_STEP3_H__26A716C5_D0F0_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_STEP3_H__26A716C5_D0F0_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep3App
// See step3.cpp for the implementation of this class
//

class CStep3App : public CWinApp
{
public:
  CStep3App();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CStep3App)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CStep3App)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP3_H__26A716C5_D0F0_11D4_BF5E_0050BADBD5F5__INCLUDED_)
