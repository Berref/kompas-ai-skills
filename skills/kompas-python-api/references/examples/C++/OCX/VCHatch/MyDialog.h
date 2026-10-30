#if !defined(AFX_MYDIALOG_H__6929F091_9AB8_4A92_935B_CA7941FA2D09__INCLUDED_)
#define AFX_MYDIALOG_H__6929F091_9AB8_4A92_935B_CA7941FA2D09__INCLUDED_
////////////////////////////////////////////////////////////////////////////////
//
// Пример создания ActiveX Control-а
// Диалог - Параметры штриховки
// <VCHatch.h>
// CVCHatchCtrl    - Редактор параметров штриховки
//
////////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CVCHatchCtrl;

/////////////////////////////////////////////////////////////////////////////
//
// MyDialog dialog
//
/////////////////////////////////////////////////////////////////////////////
class MyDialog : public CDialog
{
// Construction
public:
	MyDialog(CVCHatchCtrl &ctrl, double &ang, double &step, BOOL& enable, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(MyDialog)
	enum { IDD = IDD_MYDIALOG };
	CStatic	m_TextStep;
	CStatic	m_TextAngle;
	CEdit m_step;
	CEdit m_angle;
	//}}AFX_DATA
  double & m_dAngle;
  double & m_dStep;
  BOOL   & m_enable;
  CVCHatchCtrl & m_ctrl;
  BOOL    focusInEdit;  
// Overrides
	// ClassWizard generated virtual function overrides
  void SetEnable( BOOL enable );
	//{{AFX_VIRTUAL(MyDialog)
	public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(MyDialog)
  afx_msg UINT OnGetDlgCode();
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusAngle();
	afx_msg void OnKillfocusStep();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDIALOG_H__6929F091_9AB8_4A92_935B_CA7941FA2D09__INCLUDED_)
