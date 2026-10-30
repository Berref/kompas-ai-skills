#if !defined(AFX_VCHATCHCTL_H__A294F967_5D5A_41CF_9CA0_73F565ACBE13__INCLUDED_)
#define AFX_VCHATCHCTL_H__A294F967_5D5A_41CF_9CA0_73F565ACBE13__INCLUDED_
////////////////////////////////////////////////////////////////////////////////
//
// Пример создания ActiveX Control-а
// Класс контрола - Параметры штриховки
// <VCHatch.h>
//
////////////////////////////////////////////////////////////////////////////////
#include "MyDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// VCHatchCtl.h : Declaration of the CVCHatchCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CVCHatchCtrl : See VCHatchCtl.cpp for implementation.
/////////////////////////////////////////////////////////////////////////////
class CVCHatchCtrl : public COleControl
{
	DECLARE_DYNCREATE(CVCHatchCtrl)

  MyDialog m_MyDialog; // Диалог изменения параметров штриховки
  double   m_angle;    // Угол 
  double   m_step;     // Шаг
  BOOL     m_enable;   // Доступность контрола
// Constructor
public:
	CVCHatchCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVCHatchCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CVCHatchCtrl();

	DECLARE_OLECREATE_EX(CVCHatchCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CVCHatchCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CVCHatchCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CVCHatchCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CVCHatchCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CVCHatchCtrl)
	afx_msg double GetAngle();
	afx_msg void SetAngle(double newValue);
	afx_msg double GetStep();
	afx_msg void SetStep(double newValue);
	afx_msg BOOL GetEnable();
	afx_msg void SetEnable( BOOL enable );

	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
public:
// Event maps
	//{{AFX_EVENT(CVCHatchCtrl)
	void FireChangeAngle()
		{FireEvent(eventidChangeAngle,EVENT_PARAM(VTS_NONE));}
	void FireChangeStep()
		{FireEvent(eventidChangeStep,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CVCHatchCtrl)
	dispidAngle        = 1L,
	dispidStep         = 2L,
  dispidEnable       = 3L,
	eventidChangeAngle = 1L,
	eventidChangeStep  = 2L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCHATCHCTL_H__A294F967_5D5A_41CF_9CA0_73F565ACBE13__INCLUDED)
