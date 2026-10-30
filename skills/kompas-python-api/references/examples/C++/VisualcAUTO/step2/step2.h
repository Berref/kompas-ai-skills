// step2.h : main header file for the STEP2 DLL
//

#if !defined(AFX_STEP2_H__7810CE26_CDBC_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_STEP2_H__7810CE26_CDBC_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep2App
// See step2.cpp for the implementation of this class
//

class CStep2App : public CWinApp
{
public:
  CStep2App();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CStep2App)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CStep2App)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP2_H__7810CE26_CDBC_11D4_BF5E_0050BADBD5F5__INCLUDED_)
