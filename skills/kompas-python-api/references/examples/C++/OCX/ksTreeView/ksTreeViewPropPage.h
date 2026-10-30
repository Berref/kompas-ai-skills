#pragma once

// ksTreeViewPropPage.h : Declaration of the CksTreeViewPropPage property page class.


// CksTreeViewPropPage : See ksTreeViewPropPage.cpp for implementation.

class CksTreeViewPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CksTreeViewPropPage)
	DECLARE_OLECREATE_EX(CksTreeViewPropPage)

// Constructor
public:
	CksTreeViewPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_KSTREEVIEW };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

