// step3D1.h : main header file for the STEP3D1 DLL
//

#if !defined(AFX_STEP3D1_H__4ACADCA7_DA4E_11D4_87AE_0050BABDCDF3__INCLUDED_)
#define AFX_STEP3D1_H__4ACADCA7_DA4E_11D4_87AE_0050BABDCDF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep3D1App
// See step3D1.cpp for the implementation of this class
//

class CStep3D1App : public CWinApp
{
public:
  CStep3D1App();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CStep3D1App)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CStep3D1App)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP3D1_H__4ACADCA7_DA4E_11D4_87AE_0050BABDCDF3__INCLUDED_)
