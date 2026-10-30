#if !defined(AFX_SHDIAL_H__33AC19E1_DB15_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_SHDIAL_H__33AC19E1_DB15_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "studs3d.h"

#ifndef __PARMACRO_H
#include "parmacro.h"
#endif

// ShDial.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ShpeelDial dialog

class ShpeelDial : public CDialog
{
// Construction
public:
	ShpeelDial(Shpeel& _shpeel, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ShpeelDial)
	enum { IDD = SHPEEL_DIALOG };
	CComboBox	m_tMatt;
	CButton	m_cAttr;
	CParamList m_listParam;
	CComboBox	m_klass;
	CComboBox	m_type;
	CComboBox	m_gost;
	CButton	m_pitch;
	CStatic	m_showStatic;
	CComboBox	m_len;
	CComboBox	m_diam;
	int		m_perfGroup;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ShpeelDial)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	float p;              // шаг - вспомогательное поле
	float massa;          // масса - вспомогательное поле
	UINT bitMapId;        // идентификатор слайда
	Shpeel& shpeel;

  void CalcMassa() { massa =  shpeel.GetShpeelParam().f & ISPOLN
  															? shpeel.GetShpeelParam().m2 : shpeel.GetShpeelParam().m1;
                     massa *= (float)( !shpeel.GetShpeelParam().indexMassa
                     											? 1 : shpeel.GetShpeelParam().indexMassa == 1
																									? 0.356 : shpeel.GetShpeelParam().indexMassa == 3
																															? 0.97 : 1.08 ); }
  void ChoicePitch() { p = shpeel.GetShpeelParam().f & PITCH
  														? shpeel.GetShpeelParam().p2 : shpeel.GetShpeelParam().p1; }

	void ErrorDialog( int id );
	void FillDiametr();
	void FillLenght();
	void InitControls();
	void ViewParamShow();
	// Generated message map functions
	//{{AFX_MSG(ShpeelDial)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSelchangeGostCombo();
	afx_msg void OnSelchangeStudKlassCombo();
	afx_msg void OnStudSimplCheck();
	afx_msg void OnSelchangeStudTypeCombo();
	afx_msg void OnSelchangeDiam();
	afx_msg void OnSelchangeLen();
	afx_msg void OnPitch();
	afx_msg void OnPerformance1();
	afx_msg void OnPerformance2();
	afx_msg void OnHelpBut();
	afx_msg void OnSelchangeMatCombo();
	afx_msg void OnAttrCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHDIAL_H__33AC19E1_DB15_11D4_BF5E_0050BADBD5F5__INCLUDED_)
