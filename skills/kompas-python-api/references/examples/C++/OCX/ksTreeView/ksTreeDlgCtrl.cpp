// ksTreeDlgCtrl.cpp : Implementation of the CksTreeDlgCtrl ActiveX Control class.

#include "stdafx.h"
#include "ksTreeView.h"
#include "ksTreeDlgCtrl.h"
#include "ksTreeDlgPropPage.h"
#include "ResourceModuleChanger.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//-----------------------------------------------------------------------------
//
// ---
bool IsInt( VARTYPE vt )
{
  return vt == VT_I4 || vt == VT_INT || vt == VT_UINT || vt == VT_UI4;
}


//-------------------------------------------------------------------------------
// 
// ---
HINSTANCE GetResModule( const VARIANT FAR& valResModule, bool & loaded ) 
{
  
  HINSTANCE resModule = NULL; 
  
  loaded              = false; 
  VARIANT varTemp;
  VariantInit( &varTemp );


  // Пришёл Long или LongLong в x64
  if ( IsInt( valResModule.vt ) )
  {
    resModule = (HINSTANCE)(size_t)valResModule.lVal;
#ifdef _WIN64
    ASSERT(FALSE); // модуль обрезался если в реестре включен параметр HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Session Manager\Memory Management\AllocationPreference = 0x100000
#endif
  }
  else if ( VariantChangeType( &varTemp, (VARIANT*)&valResModule, 0, VT_I8) == NOERROR ) 
    resModule = (HINSTANCE)(size_t)varTemp.llVal;
  else if ( VariantChangeType( &varTemp, (VARIANT*)&valResModule, 0, VT_BSTR) == NOERROR ) 
  {
    CString module (varTemp.bstrVal);
    resModule = ::LoadLibrary( module );
    loaded    = true; 
  }


  VariantClear( &varTemp );

  return resModule;
}


//-------------------------------------------------------------------------------
// 
// ---
IMPLEMENT_DYNCREATE(CExternalToolBar, CToolBar)

// Message map
//-------------------------------------------------------------------------------
// 
// ---
BEGIN_MESSAGE_MAP(CExternalToolBar, CToolBar)

 ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnToolTipNotify)
 ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnToolTipNotify)

END_MESSAGE_MAP()


//-------------------------------------------------------------------------------
// 
// ---
CExternalToolBar::~CExternalToolBar()
{
  if ( m_loaded && m_hInstance )
    FreeLibrary( m_hInstance );
}


//-----------------------------------------------------------------------------
// Notification handler for tooltips - determine which tooltip
// string resource to be displayed.
// ---
BOOL CExternalToolBar::OnToolTipNotify( UINT id, NMHDR * pNMHDR, LRESULT * pResult )
{
  TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*) pNMHDR;
  TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*) pNMHDR;

  UINT btnID = static_cast<UINT>(pNMHDR->idFrom);

  if (btnID)
  {

    *pResult = 0;
    RESOURCE_MODULE_CHANGE( m_hInstance );

    CString str;
    if ( str.LoadString( btnID ) )
    {

#ifndef _UNICODE
      if (pNMHDR->code == TTN_NEEDTEXTA)
        lstrcpyn(pTTTA->szText, str, _countof(pTTTA->szText));
      else
        _mbstowcsz(pTTTW->szText, str, _countof(pTTTW->szText));
#else
      if (pNMHDR->code == TTN_NEEDTEXTA)
        _wcstombsz(pTTTA->szText, str, _countof(pTTTA->szText));
      else
        lstrcpyn(pTTTW->szText, str, _countof(pTTTW->szText));
#endif
      return TRUE;
    }
  }

  return FALSE;
}


//-------------------------------------------------------------------------------
// 
// ---
BOOL CExternalToolBar::LoadToolBar( const VARIANT FAR& ResModule, const VARIANT FAR & ToolbarId )
{
  BOOL res = FALSE;
  if ( m_loaded && m_hInstance )
  {
    FreeLibrary( m_hInstance );
    m_loaded = false;
  }  
  m_hInstance = GetResModule( ResModule, m_loaded );

//  if ( !m_hInstance )
//    m_hInstance = AfxGetInstanceHandle();
    
  if ( m_hInstance )
  {
    RESOURCE_MODULE_CHANGE( m_hInstance );
    // идентификатор битмапа в ресурсе VT_I4, LONG
    if ( ToolbarId.vt == VT_BSTR )
    {
      CString resId( ToolbarId.bstrVal );
      res = CToolBar::LoadToolBar( (LPCTSTR) resId );
    }
    else 
    {
      VARIANT tmpVar;
      VariantInit( &tmpVar );
      if ( VariantChangeType( &tmpVar, (VARIANT*)&ToolbarId, 0, VT_I4) == NOERROR )
        res = CToolBar::LoadToolBar( tmpVar.lVal );
      VariantClear( &tmpVar );
    }
  }
  return res;
}


//-------------------------------------------------------------------------------
// 
// ---
LRESULT CExternalToolBar::WindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam)
{
  // special case for TTN_NEEDTEXTA and TTN_NEEDTEXTW
  if(nMsg == WM_NOTIFY)
  {
    NMHDR* pNMHDR = (NMHDR*)lParam;
    if (pNMHDR->code == TTN_NEEDTEXTA || pNMHDR->code == TTN_NEEDTEXTW)
    {
      TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
      TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
      LRESULT lResult = NULL;

      if (pNMHDR->code == TTN_NEEDTEXTA)
      {
        if (pTTTA->hinst == 0 && (!pTTTA->lpszText || !*pTTTA->lpszText))
        {
          // not handled by owner, so let bar itself handle it
          // lResult = CWnd::WindowProc(nMsg, wParam, lParam);
          OnToolTipNotify( 0, pNMHDR, &lResult );
          return lResult;
        }
      } else if (pNMHDR->code == TTN_NEEDTEXTW)
      {
        if (pTTTW->hinst == 0 && (!pTTTW->lpszText || !*pTTTW->lpszText))
        {
          // not handled by owner, so let bar itself handle it
          // lResult = CWnd::WindowProc(nMsg, wParam, lParam);
          OnToolTipNotify( 0, pNMHDR, &lResult );
          return lResult;
        }
      }
    }
  }
  return CToolBar::WindowProc( nMsg, wParam, lParam);
}


//-------------------------------------------------------------------------------
// 
// ---
IMPLEMENT_DYNCREATE(CksTreeDlg, COleControl)


//-------------------------------------------------------------------------------
// Message map
// ---
BEGIN_MESSAGE_MAP(CksTreeDlg, COleControl)
  ON_WM_CREATE()
 // ON_WM_SETFOCUS()
  ON_WM_SIZE()

	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)

  ON_COMMAND_RANGE          ( ksTVGN_IDCM_MIN, ksTVGN_IDCM_MAX, OnToolBarCommand )
  ON_UPDATE_COMMAND_UI_RANGE( ksTVGN_IDCM_MIN, ksTVGN_IDCM_MAX, OnUpdateToolBarCommand )

END_MESSAGE_MAP()


//-------------------------------------------------------------------------------
// Dispatch map
// ---
BEGIN_DISPATCH_MAP(CksTreeDlg, COleControl)
  DISP_PROPERTY_EX_ID   ( CksTreeDlg, "TreeView",    1, GetTreeView,   SetNotSupported, VT_DISPATCH )
  DISP_FUNCTION_ID      ( CksTreeDlg, "LoadToolBar", 2, LoadToolBar,                    VT_BOOL, VTS_VARIANT VTS_VARIANT )
END_DISPATCH_MAP()


//-------------------------------------------------------------------------------
// Event map
// ---
BEGIN_EVENT_MAP(CksTreeDlg, COleControl)
END_EVENT_MAP()

//-------------------------------------------------------------------------------
// 
// ---
BEGIN_INTERFACE_MAP(CksTreeDlg, COleControl)
  INTERFACE_PART(CksTreeDlg, IID_IksTreeDlg, ksTreeDlg)

  DUAL_ERRORINFO_PART(CksTreeDlg)
END_INTERFACE_MAP()


//-------------------------------------------------------------------------------
// Property pages
// TODO: Add more property pages as needed.  Remember to increase the count!
// ---
BEGIN_PROPPAGEIDS(CksTreeDlg, 1)
	PROPPAGEID(CksTreeDlgPropPage::guid)
END_PROPPAGEIDS(CksTreeDlg)


//-------------------------------------------------------------------------------
// Initialize class factory and guid
// ---
IMPLEMENT_OLECREATE_EX(CksTreeDlg, "KSTREEDLG.ksTreeDlgCtrl.1",
	0x5c78f9ea, 0x7618, 0x43eb, 0x93, 0x4e, 0x42, 0xd2, 0xa6, 0xb5, 0xd0, 0x22)

//-------------------------------------------------------------------------------
// Type library ID and version
// ---
IMPLEMENT_OLETYPELIB(CksTreeDlg, _tlid, _wVerMajor, _wVerMinor)


//-------------------------------------------------------------------------------
// Control type information
// ---
static const DWORD BASED_CODE _dwksTreeDlgOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

//-------------------------------------------------------------------------------
//
// ---
IMPLEMENT_OLECTLTYPE(CksTreeDlg, IDS_KSTREEDLG, _dwksTreeDlgOleMisc)



//-------------------------------------------------------------------------------
// CksTreeDlgCtrl::CksTreeDlgCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CksTreeDlgCtrl
// ---
BOOL CksTreeDlg::CksTreeDlgFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_KSTREEDLG,
			IDB_KSTREEDLG,
			afxRegApartmentThreading,
			_dwksTreeDlgOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



//-------------------------------------------------------------------------------
// Constructor
// ---
CksTreeDlg::CksTreeDlg()
{
	InitializeIIDs(&IID_IksTreeDlg, &DIID__DksTreeDlgEvents);
}


//-------------------------------------------------------------------------------
// Destructor
// ---
CksTreeDlg::~CksTreeDlg()
{
}


//-------------------------------------------------------------------------------
// Лечим COleControl::GetInterfaceHook который рассчитан на диспинтерфейс а у нас дуальный
// ---
LPUNKNOWN CksTreeDlg::GetInterfaceHook(const void* piid)
{
  ASSERT_POINTER(piid, IID);

  // Лечим COleControl::GetInterfaceHook который рассчитан на диспинтерфейс а у нас дуальный
  // if (m_piidPrimary != NULL && _AfxIsEqualGUID(*m_piidPrimary, *(IID*)piid))
  // {
  //   return GetInterface((void*)&IID_IDispatch);
  // }

  if (IsEqualGUID(IID_IPointerInactive, *(IID*)piid) &&
    (GetControlFlags() & pointerInactive))
  {
    return &m_xPointerInactive;
  }

  return NULL;
}


//-------------------------------------------------------------------------------
// CksTreeDlgCtrl::DoPropExchange - Persistence support
// ---
void CksTreeDlg::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


//-------------------------------------------------------------------------------
// CksTreeDlgCtrl::OnResetState - Reset control to default state
// ---
void CksTreeDlg::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


//-----------------------------------------------------------------------------
/// 
// ---
int CksTreeDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  AFX_MANAGE_STATE(_afxModuleAddrThis);

  if (COleControl::OnCreate(lpCreateStruct) == -1)
    return -1;

  // Create the style
  DWORD dwTreeStyle = WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES | TVS_DISABLEDRAGDROP;
  DWORD dwTBStyle   = WS_CHILD   | WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS | CBRS_FLYBY| CBRS_SIZE_DYNAMIC;
  //  WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS;

  if ( m_ToolBar.CreateEx( this, TBSTYLE_FLAT, dwTBStyle, CRect(0,0,0,0), IDC_TOOLBAR_CTRL ) &&
    m_TreeView.Create( _T(""), _T(""), dwTreeStyle, CRect(0,0,0,0), this,IDC_TREE_VIEW_CTRL ) ) 
  {
    m_ToolBar.ModifyStyle( 0, TBSTYLE_TOOLTIPS );

    m_ToolBar.SetBarStyle( m_ToolBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY );
    //m_ToolBar.SetBarStyle( m_ToolBar.GetBarStyle () & ~(CBRS_GRIPPER | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT) );

    return 0;
  }
  return -1;
}


//----------------------------------------------------------------------------- 
// Изменение стиля диалога перед созданием
// ---
BOOL CksTreeDlg::PreCreateWindow(CREATESTRUCT& cs)
{
//  cs.style &= ~WS_TABSTOP;
  cs.style |= (WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
  cs.dwExStyle &= ~WS_EX_CLIENTEDGE;

  return COleControl::PreCreateWindow(cs);
}


//-----------------------------------------------------------------------------
/// 
// ---
void CksTreeDlg::OnSize(UINT nType, int cx, int cy) 
{
  COleControl::OnSize(nType, cx, cy);

  CSize sizeTB(0, 0);

  if ( ::IsWindow(m_ToolBar.m_hWnd) )
  {
    CToolBarCtrl & toolBar = m_ToolBar.GetToolBarCtrl();

    if ( toolBar.GetButtonCount() == 0 )
      m_ToolBar.ShowWindow( SW_HIDE );
    else
    {
      sizeTB = m_ToolBar.CalcFixedLayout( FALSE, TRUE );
      m_ToolBar.ShowWindow( SW_SHOW );
      m_ToolBar.MoveWindow( CRect(0, 0, cx, sizeTB.cy), TRUE );
    }
  }

  if ( ::IsWindow(m_TreeView.m_hWnd) )
    m_TreeView.MoveWindow(CRect(0, sizeTB.cy, cx, cy), TRUE);
}


//-----------------------------------------------------------------------------
/// 
// ---
BOOL CksTreeDlg::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
  BOOL res = COleControl::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);

  static bool bDisable = false;

  if ( !bDisable && ::IsWindow(m_ToolBar.m_hWnd) )
  {
    CToolBarCtrl & toolBar = m_ToolBar.GetToolBarCtrl();
    if ( toolBar.GetButtonCount() )
    {
      bDisable = true;		
      m_ToolBar.OnUpdateCmdUI((CFrameWnd*)this, FALSE);
      bDisable = false;
    }
  }

  return res;
}


//-----------------------------------------------------------------------------
/// 
// ---
afx_msg void CksTreeDlg::OnToolBarCommand( UINT id )
{
  FireToolBarCommand( id );
}


//-------------------------------------------------------------------------------
// UpdateToolBarCommand
// ---
afx_msg void CksTreeDlg::OnUpdateToolBarCommand( CCmdUI * pCmdUI)
{
  FireUpdateToolBarCommand( pCmdUI );
}


// FireEvents
//-------------------------------------------------------------------------------
// FireMenuCommand
// ---
void CksTreeDlg::FireToolBarCommand(long Id)
{ 
  ExternalAddRef();   // "Insurance" addref -- keeps control alive.
  FireEvent(DISPID_ToolBarCommand,EVENT_PARAM(VTS_I4), Id);
  ExternalRelease();
}


//-------------------------------------------------------------------------------
// FireMenuCommand
// ---
void CksTreeDlg::FireUpdateToolBarCommand(CCmdUI * pCmdUI )
{ 
  ExternalAddRef();   // "Insurance" addref -- keeps control alive.

  long         cmId    = pCmdUI->m_nID;
  BOOL         Enable  = VARIANT_TRUE;
  long         checked = 0;

  FireEvent(DISPID_ButtinUpdate,EVENT_PARAM(VTS_I4 VTS_PBOOL VTS_PI4), cmId, &Enable, &checked );

  pCmdUI->Enable( Enable );
  pCmdUI->SetCheck( checked );

  ExternalRelease();
}


// IksTreeDlg
//-----------------------------------------------------------------------------
/// 
// ---
LPDISPATCH CksTreeDlg::GetTreeView()
{
  return m_TreeView.GetIDispatch( TRUE );
}


//-----------------------------------------------------------------------------
/// 
// ---
BOOL CksTreeDlg::LoadToolBar( const VARIANT FAR& ResModule, const VARIANT FAR& ToolbarId )
{
  return m_ToolBar.LoadToolBar( ResModule, ToolbarId );
}


////////////////////////////////////////////////////////////////////////////////
//
// Реализация дуального интерфейса IApplication (COM)
//
////////////////////////////////////////////////////////////////////////////////
// Реализация стандартных методов IDispatch 
DELEGATE_DUAL_INTERFACE(CksTreeDlg, ksTreeDlg)

//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( ksTreeDlg, get_TreeView, IksTreeView **Tree ) 
  RETURN_DUAL_INTERFACE( Tree, IID_IksTreeView, GetTreeView )
END_DUAL_METHOD


//-------------------------------------------------------------------------------
/// 
// ---
BEGIN_DUAL_METHOD_3( ksTreeDlg, LoadToolBar, VARIANT ResModule, VARIANT ToolbarId, VARIANT_BOOL *Result ) 
  if ( Result )
  {
    *Result = pThis->LoadToolBar( ResModule, ToolbarId );
    return S_OK;
  }
  else
    return E_INVALIDARG;
END_DUAL_METHOD


//-----------------------------------------------------------------------------
/// Реализация ISupportErrorInfo 
// ---
IMPLEMENT_DUAL_ERRORINFO( CksTreeDlg, IID_IksTreeDlg )