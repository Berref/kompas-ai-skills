// step3a.h : main header file for the STEP3A DLL
//

#if !defined(AFX_STEP3A_H__A4918C65_D1A8_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_STEP3A_H__A4918C65_D1A8_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep3aApp
// See step3a.cpp for the implementation of this class
//

class CStep3aApp : public CWinApp
{
public:
  CStep3aApp();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CStep3aApp)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CStep3aApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP3A_H__A4918C65_D1A8_11D4_BF5E_0050BADBD5F5__INCLUDED_)
