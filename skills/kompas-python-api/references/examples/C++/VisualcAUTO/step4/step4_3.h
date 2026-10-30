#if !defined(AFX_STEP4_3_H__9D6A16E1_D271_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_STEP4_3_H__9D6A16E1_D271_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// step4_3.h : header file
//
#include "resource.h"		// main symbols



/////////////////////////////////////////////////////////////////////////////
// TestShowDlg dialog

class TestShowDlg : public CDialog
{
// Construction
public:
	CString kompasDocName;
	UINT IdSlide;
	CString resurs;
	ksDocument2DPtr& doc;
	TestShowDlg( ksDocument2DPtr& _doc, CWnd* pParent = NULL );   // standard constructor

// Dialog Data
	//{{AFX_DATA(TestShowDlg)
	enum { IDD = IDD_TESTDIALOG };
	CStatic	m_ShowStatic;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TestShowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TestShowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP4_3_H__9D6A16E1_D271_11D4_BF5E_0050BADBD5F5__INCLUDED_)
