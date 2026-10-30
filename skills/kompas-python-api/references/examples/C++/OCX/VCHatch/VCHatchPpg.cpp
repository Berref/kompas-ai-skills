////////////////////////////////////////////////////////////////////////////////
//
// Пример создания ActiveX Control-а
// Диалог изменения параметров контрола - Параметры штриховки
// <VCHatchPpg.h>
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "VCHatch.h"
#include "VCHatchPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CVCHatchPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map
BEGIN_MESSAGE_MAP(CVCHatchPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CVCHatchPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CVCHatchPropPage, "VCHATCH.VCHatchPropPage.1",
	0xe09b5e22, 0x2edc, 0x47e3, 0xbb, 0x53, 0xeb, 0x7e, 0x12, 0xb1, 0x20, 0xcf)


/////////////////////////////////////////////////////////////////////////////
// CVCHatchPropPage::CVCHatchPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CVCHatchPropPage
BOOL CVCHatchPropPage::CVCHatchPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_VCHATCH_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CVCHatchPropPage::CVCHatchPropPage - Constructor
CVCHatchPropPage::CVCHatchPropPage() :
	COlePropertyPage(IDD, IDS_VCHATCH_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CVCHatchPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CVCHatchPropPage::DoDataExchange - Moves data between page and properties

void CVCHatchPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CVCHatchPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CVCHatchPropPage message handlers
