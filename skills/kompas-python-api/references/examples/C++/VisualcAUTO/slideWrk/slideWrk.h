// slideWrk.h : main header file for the SLIDEWRK DLL
//

#if !defined(AFX_SLIDEWRK_H__2057C6C5_D825_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_SLIDEWRK_H__2057C6C5_D825_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSlideWrkApp
// See slideWrk.cpp for the implementation of this class
//

class CSlideWrkApp : public CWinApp
{
public:
  CSlideWrkApp();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CSlideWrkApp)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CSlideWrkApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// TestDlg dialog

class TestDlg : public CDialog
{
// Construction
public:
  TestDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
  //{{AFX_DATA(TestDlg)
  enum { IDD = IDD_DIALOG1 };
  CStatic  m_show;
  //}}AFX_DATA


// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(TestDlg)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:
  UINT IdSlide;

  // Generated message map functions
  //{{AFX_MSG(TestDlg)
  afx_msg void OnPaint();
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDEWRK_H__2057C6C5_D825_11D4_BF5E_0050BADBD5F5__INCLUDED_)
