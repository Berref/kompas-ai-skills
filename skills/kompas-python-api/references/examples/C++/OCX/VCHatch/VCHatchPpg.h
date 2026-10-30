#if !defined(AFX_VCHATCHPPG_H__B038EEC2_81C6_4543_A3E6_2979E37740C3__INCLUDED_)
#define AFX_VCHATCHPPG_H__B038EEC2_81C6_4543_A3E6_2979E37740C3__INCLUDED_
////////////////////////////////////////////////////////////////////////////////
//
// Пример создания ActiveX Control-а
// Диалог изменения параметров контрола - Параметры штриховки
// <VCHatchPpg.cpp>
//
////////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// VCHatchPpg.h : Declaration of the CVCHatchPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CVCHatchPropPage : See VCHatchPpg.cpp.cpp for implementation.

class CVCHatchPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CVCHatchPropPage)
	DECLARE_OLECREATE_EX(CVCHatchPropPage)

// Constructor
public:
	CVCHatchPropPage();

// Dialog Data
	//{{AFX_DATA(CVCHatchPropPage)
	enum { IDD = IDD_PROPPAGE_VCHATCH };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CVCHatchPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCHATCHPPG_H__B038EEC2_81C6_4543_A3E6_2979E37740C3__INCLUDED)
