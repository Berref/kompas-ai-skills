// ksTreeDlgPropPage.cpp : Implementation of the CksTreeDlgPropPage property page class.

#include "stdafx.h"
#include "ksTreeView.h"
#include "ksTreeDlgPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CksTreeDlgPropPage, COlePropertyPage)


// Message map
BEGIN_MESSAGE_MAP(CksTreeDlgPropPage, COlePropertyPage)
END_MESSAGE_MAP()


// Initialize class factory and guid
IMPLEMENT_OLECREATE_EX(CksTreeDlgPropPage, "KSTREEDLG.ksTreeDlgPropPage.1",
	0x30ac468f, 0x6896, 0x4c7c, 0xa4, 0x33, 0xfc, 0xeb, 0xb8, 0x68, 0x85, 0x9b)


// CksTreeDlgPropPage::CksTreeDlgPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CksTreeDlgPropPage
BOOL CksTreeDlgPropPage::CksTreeDlgPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_KSTREEDLG_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


// CksTreeDlgPropPage::CksTreeDlgPropPage - Constructor
CksTreeDlgPropPage::CksTreeDlgPropPage() :
	COlePropertyPage(IDD, IDS_KSTREEDLG_PPG_CAPTION)
{
}


// CksTreeDlgPropPage::DoDataExchange - Moves data between page and properties
void CksTreeDlgPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CksTreeDlgPropPage message handlers
