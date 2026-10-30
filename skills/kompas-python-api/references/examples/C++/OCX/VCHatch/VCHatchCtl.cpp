#include "stdafx.h"
#include "VCHatch.h"
#include "VCHatchCtl.h"
#include "VCHatchPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CVCHatchCtrl, COleControl)

/////////////////////////////////////////////////////////////////////////////
// Message map
BEGIN_MESSAGE_MAP(CVCHatchCtrl, COleControl)
	//{{AFX_MSG_MAP(CVCHatchCtrl)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map
BEGIN_DISPATCH_MAP(CVCHatchCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CVCHatchCtrl)
	DISP_PROPERTY_EX(CVCHatchCtrl, "Angle",  GetAngle,  SetAngle,  VT_R8   )
	DISP_PROPERTY_EX(CVCHatchCtrl, "Step",   GetStep,   SetStep,   VT_R8   )
	DISP_PROPERTY_EX(CVCHatchCtrl, "Enable", GetEnable, SetEnable, VT_BOOL )
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CVCHatchCtrl, COleControl)
	//{{AFX_EVENT_MAP(CVCHatchCtrl)
	EVENT_CUSTOM( "ChangeAngle", FireChangeAngle, VTS_NONE )
	EVENT_CUSTOM( "ChangeStep",  FireChangeStep,  VTS_NONE )
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CVCHatchCtrl, 1)
	PROPPAGEID(CVCHatchPropPage::guid)

END_PROPPAGEIDS(CVCHatchCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CVCHatchCtrl, "VCHATCH.VCHatchCtrl.1",
	0xffed03f1, 0x481a, 0x4acd, 0xa3, 0x9e, 0xc5, 0xd4, 0xa8, 0x82, 0x82, 0x36)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CVCHatchCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DVCHatch =
		{ 0x3ffe9799, 0xdf8d, 0x4936, { 0x98, 0xc, 0xbe, 0xa2, 0x89, 0x64, 0xa3, 0xa7 } };
const IID BASED_CODE IID_DVCHatchEvents =
		{ 0x26776524, 0xf601, 0x42ce, { 0xa4, 0x9e, 0x90, 0xcf, 0x80, 0x41, 0x11, 0xa5 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwVCHatchOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CVCHatchCtrl, IDS_VCHATCH, _dwVCHatchOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CVCHatchCtrl::CVCHatchCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CVCHatchCtrl

BOOL CVCHatchCtrl::CVCHatchCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_VCHATCH,
			IDB_VCHATCH,
			afxRegApartmentThreading,
			_dwVCHatchOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CVCHatchCtrl::CVCHatchCtrl - Constructor
#pragma warning(disable:4355) // warning C4355: 'this' : used in base member initializer list
CVCHatchCtrl::CVCHatchCtrl() :
  m_angle(45),
  m_step(2),
  m_enable(true),
  m_MyDialog( *this, m_angle, m_step, m_enable )
{
	InitializeIIDs(&IID_DVCHatch, &IID_DVCHatchEvents);

	// TODO: Initialize your control's instance data here.
}
#pragma warning(default:4355) //warning C4355: 'this' : used in base member initializer list

/////////////////////////////////////////////////////////////////////////////
// CVCHatchCtrl::~CVCHatchCtrl - Destructor

CVCHatchCtrl::~CVCHatchCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CVCHatchCtrl::OnDraw - Drawing function

void CVCHatchCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
  if(m_MyDialog.m_hWnd)
    m_MyDialog.MoveWindow(rcBounds, TRUE);
}


/////////////////////////////////////////////////////////////////////////////
// CVCHatchCtrl::DoPropExchange - Persistence support

void CVCHatchCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CVCHatchCtrl::OnResetState - Reset control to default state

void CVCHatchCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CVCHatchCtrl message handlers

double CVCHatchCtrl::GetAngle() 
{
	// TODO: Add your property handler here

	return m_angle;
}

void CVCHatchCtrl::SetAngle(double newValue) 
{
	
  m_angle = newValue;
	SetModifiedFlag();
}

double CVCHatchCtrl::GetStep() 
{
	return m_step;
}

void CVCHatchCtrl::SetStep(double newValue) 
{
  m_step = newValue;

	SetModifiedFlag();
}

BOOL CVCHatchCtrl::GetEnable() 
{
	return m_enable;
}

void CVCHatchCtrl::SetEnable(BOOL enable ) 
{
  m_enable = enable;
  if(m_MyDialog.m_hWnd) 
    m_MyDialog.SetEnable( enable );
 	SetModifiedFlag();
}

int CVCHatchCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
    m_MyDialog.Create(IDD_MYDIALOG, this);
    return 0;

	
	return 0;
}

void CVCHatchCtrl::OnSetFocus(CWnd* pOldWnd) 
{
	COleControl::OnSetFocus(pOldWnd);
	m_MyDialog.SetFocus();
}
