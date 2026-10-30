#pragma once

// ksTreeDlgPropPage.h : Declaration of the CksTreeDlgPropPage property page class.


// CksTreeDlgPropPage : See ksTreeDlgPropPage.cpp for implementation.

class CksTreeDlgPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CksTreeDlgPropPage)
	DECLARE_OLECREATE_EX(CksTreeDlgPropPage)

// Constructor
public:
	CksTreeDlgPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_KSTREEDLG };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

