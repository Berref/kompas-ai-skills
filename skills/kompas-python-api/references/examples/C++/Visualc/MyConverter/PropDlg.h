///////////////////////////////////////////////////////////////////////////////
//
// PropDlg.h - класс окна диалога параметров конвертации
//
///////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_PROPDLG_H__D13D7939_54D9_4CEC_8768_E3B506D1427E__INCLUDED_)
#define AFX_PROPDLG_H__D13D7939_54D9_4CEC_8768_E3B506D1427E__INCLUDED_

// Идентификаторы основных ресурсов 
#include "resource.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////////////////////////////////////////////
//
// Класс окна диалога параметров конвертации
//
///////////////////////////////////////////////////////////////////////////////
class PropDlg : public CDialog
{
// Construction
public:
	PropDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PropDlg)
	enum { IDD = IDD_PARAMDLG };
	CButton	m_LinesStyle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PropDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PropDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnLines();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPDLG_H__D13D7939_54D9_4CEC_8768_E3B506D1427E__INCLUDED_)
