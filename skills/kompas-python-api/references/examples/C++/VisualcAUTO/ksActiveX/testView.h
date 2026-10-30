// testView.h : interface of the CTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTVIEW_H__CA87F1B9_49D7_4455_A048_4DD6A633649E__INCLUDED_)
#define AFX_TESTVIEW_H__CA87F1B9_49D7_4455_A048_4DD6A633649E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//{{AFX_INCLUDES()
#include <kgaxCtrl.h>
//}}AFX_INCLUDES

//#include <kgax.h>

class CTestView : public CView
{
protected: // create from serialization only
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// Attributes
public:
	CTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
CKGAXCtrl m_KompasCtrl;

// Generated message map functions
protected:
	//{{AFX_MSG(CTestView)
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnAppAbout();
  afx_msg void OnDestroy();
  afx_msg void OnFileOpen();
  afx_msg void OnFileNew();
	afx_msg void OnFileReload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	afx_msg void OnKgMouseDownKgaxctrl(short nButton, short nShiftState, long x, long y, BOOL FAR* proceed);
 	afx_msg void OnKgKeyDownKgaxctrl(long FAR * nButton, short nShiftState );
 	afx_msg void OnKgKeyUpKgaxctrl(long FAR * nButton, short nShiftState );
 	afx_msg void OnKgKeyPressKgaxctrl(long FAR * nButton );
  
	DECLARE_EVENTSINK_MAP()

	void Command2D( ksDocument2DPtr pDoc );
  void Command3D( ksDocument3DPtr pDoc );
};

#ifndef _DEBUG  // debug version in testView.cpp
inline CTestDoc* CTestView::GetDocument()
   { return (CTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW_H__CA87F1B9_49D7_4455_A048_4DD6A633649E__INCLUDED_)
