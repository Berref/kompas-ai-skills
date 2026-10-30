// step11.h : main header file for the STEP11 DLL
//

#if !defined(AFX_STEP11_H__C0F5A304_D11C_11D4_872B_0050BADDB58C__INCLUDED_)
#define AFX_STEP11_H__C0F5A304_D11C_11D4_872B_0050BADDB58C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep11App
// See step11.cpp for the implementation of this class
//

class CStep11App : public CWinApp
{
public:
  CStep11App();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CStep11App)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CStep11App)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP11_H__C0F5A304_D11C_11D4_872B_0050BADDB58C__INCLUDED_)
