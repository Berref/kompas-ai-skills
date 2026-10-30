// vcprjDlg.h : header file
//

#if !defined(AFX_VCPRJDLG_H__3876F927_6893_11D5_94AD_FC019B4CD066__INCLUDED_)
#define AFX_VCPRJDLG_H__3876F927_6893_11D5_94AD_FC019B4CD066__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVcprjDlg dialog

class CVcprjDlg : public CDialog
{
// Construction
public:
	CVcprjDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVcprjDlg)
	enum { IDD = IDD_VCPRJ_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVcprjDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVcprjDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGraphicLoad();
	afx_msg void OnQuitUnload();
	afx_msg void OnQuitWOUnload();
	afx_msg void OnLoadFile();
	afx_msg void OnNewFile();
	afx_msg void OnExecuteCommand();
	afx_msg void OnUnloadGraphic();
	afx_msg void OnLoadLibrary();
	afx_msg void OnRunLibraryCommand();
	afx_msg void OnUnloadLibrary();
	afx_msg void OnSaveFile();
	afx_msg void OnCloseFile();
	afx_msg void OnGraphicLoad2();
	afx_msg void OnVisible();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedCheck1();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCPRJDLG_H__3876F927_6893_11D5_94AD_FC019B4CD066__INCLUDED_)
