// step1.h : main header file for the STEP1 DLL
//

#if !defined(AFX_STEP1_H__200000C4_CD17_11D4_87AE_0050BABDCDF3__INCLUDED_)
#define AFX_STEP1_H__200000C4_CD17_11D4_87AE_0050BABDCDF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

//#include <iostream> 
//using namespace std;

#ifndef CIniFile_H
#include "iniFile.h"
#endif


#include "resource.h"		// main symbols


/////////////////////////////////////////////////////////////////////////////
// CStep1App
// See step1.cpp for the implementation of this class
//

class CEventComApp : public CWinApp
{
public:
	CEventComApp();
//КВН K6   virtual BOOL InitInstance();
	virtual int ExitInstance();
	void     ConfigDlg();

	CIniFile m_iniFile;
  bool     m_auto;
 	bool     m_mes_2DDOC;
 	bool     m_mes_3DDOC;
	bool     m_mes_APP;
	bool     m_mes_DOC;
	bool     m_mes_OBJ_2DDOC;
	bool     m_mes_OBJ_3DDOC;
	bool	   m_mes_OBJ_SPC;
	bool	   m_mes_SELECT;
	bool	   m_mes_SPC;
	bool	   m_mes_SPCDOC;
	bool	   m_mes_STAMP;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEventComApp)
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CEventComApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

// Объект приложение
extern CEventComApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP1_H__200000C4_CD17_11D4_87AE_0050BABDCDF3__INCLUDED_)
