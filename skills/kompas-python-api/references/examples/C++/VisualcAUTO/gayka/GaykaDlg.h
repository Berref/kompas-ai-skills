#if !defined(AFX_GAYKADLG_H__4D809923_D4F0_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_GAYKADLG_H__4D809923_D4F0_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GaykaDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// GaykaDlg dialog

class GaykaDlg : public CDialog
{
// Construction
public:
  GaykaDlg(Gayka5915& _gayka, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
  //{{AFX_DATA(GaykaDlg)
  enum { IDD = GAYKA_DIALOG };
  CComboBox  m_diam;
  CButton  m_key;
  CEdit  m_stepEdit;
  CEdit  m_angEdit;
  CButton  m_slimStep;
  CButton  m_simple;
  CButton  m_spcObj;
  CStatic  m_showStatic;
  CButton  m_perf1;
  float  m_stepHatch;
  float  m_angHatch;
  //}}AFX_DATA


// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(GaykaDlg)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:
  float massa;
  void CalcMassa();
  int bitMapId;
  Gayka5915& gayka;

  // Generated message map functions
  //{{AFX_MSG(GaykaDlg)
  virtual BOOL OnInitDialog();
  afx_msg void OnPaint();
  afx_msg void OnSpcobj();
  afx_msg void OnView();
  afx_msg void OnSecview();
  afx_msg void OnSideview();
  afx_msg void OnTopview();
  afx_msg void OnPerf1();
  afx_msg void OnPerf2();
  afx_msg void OnDrawaxis();
  afx_msg void OnSimple();
  afx_msg void OnSlimstep();
  afx_msg void OnChangeHAng();
  afx_msg void OnChangeHShag();
  afx_msg void OnAddkey();
  afx_msg void OnSelchangeDiam();
  afx_msg void OnHelpButton();
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
private:
  void SetHatchWindowEnable( bool enable );
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAYKADLG_H__4D809923_D4F0_11D4_BF5E_0050BADBD5F5__INCLUDED_)
