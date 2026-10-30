// ksTreeViewPropPage.cpp : Implementation of the CksTreeViewPropPage property page class.

#include "stdafx.h"
#include "ksTreeView.h"
#include "ksTreeViewPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CksTreeViewPropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CksTreeViewPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CksTreeViewPropPage, "KSTREEVIEW.ksTreeViewPropPage.1",
	0xc12694d4, 0xb7fc, 0x4c8f, 0x99, 0x67, 0x9, 0x73, 0xcc, 0x8d, 0x33, 0xc6)



// CksTreeViewPropPage::CksTreeViewPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CksTreeViewPropPage

BOOL CksTreeViewPropPage::CksTreeViewPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_KSTREEVIEW_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CksTreeViewPropPage::CksTreeViewPropPage - Constructor

CksTreeViewPropPage::CksTreeViewPropPage() :
	COlePropertyPage(IDD, IDS_KSTREEVIEW_PPG_CAPTION)
{
}



// CksTreeViewPropPage::DoDataExchange - Moves data between page and properties

void CksTreeViewPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CksTreeViewPropPage message handlers
