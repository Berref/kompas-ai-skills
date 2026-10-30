// ksTreeViewCtrl.cpp : Implementation of the CksTreeView ActiveX Control class.

#include "stdafx.h"
#include "ksTreeView.h"
#include "ksTreeViewCtrl.h"
#include "ksTreeViewPropPage.h"
#include <sarray.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//-------------------------------------------------------------------------------
// Переложить элементы из strArray в safeArray
// ---
void FillBSTRSafeArray( VARIANT & safeArray, const CStringList & strArray )
{
  // для случая пустого массива строк
  long count = static_cast<long>(strArray.GetCount());
  if ( count )
  {

    SAFEARRAY * sa = SafeArrayCreateVector( VT_BSTR, 0, count );
    if( sa )
    {
      for ( long i = 0; i < count; i++ ) {
        _bstr_t bstr( strArray.GetAt( strArray.FindIndex(i) ) ); 
        SafeArrayPutElement( sa, &i, (void *)(BSTR)bstr );
      }
      V_VT(&safeArray) = VT_ARRAY | VT_BSTR;
      V_ARRAY(&safeArray) = sa;
    }
  }
} 

//-------------------------------------------------------------------------------
// Переложить элементы из safeArray  strArray 
// ---
void FillStrArray( const VARIANT FAR & safeArray, CStringList & strArray )
{
  strArray.RemoveAll();
  if ( safeArray.vt == VT_BSTR )  // Прислали одну строку
  {
    CString str( safeArray.bstrVal );
    strArray.AddHead( str );
  }
  else if ( safeArray.vt == (VT_ARRAY | VT_BSTR) && safeArray.parray )
  {
    // Прислали непустой массив строк
    int count = safeArray.parray->rgsabound[0].cElements - safeArray.parray->rgsabound[0].lLbound;
    if ( safeArray.parray->cDims == 1 && count ) 
    {
      HRESULT hr;
      BSTR HUGEP *pvar = NULL;
      hr = ::SafeArrayAccessData( safeArray.parray, (void HUGEP* FAR*)&pvar );
      if ( !FAILED(hr) && pvar ) {

        // Добавляем комментарии в коллекцию
        for ( int i = 0; i < count; i++ ) {
          CString str( pvar[i] );
          strArray.AddHead( str );
        }

        hr = ::SafeArrayUnaccessData( safeArray.parray );
      }
    }
  }
}

//-------------------------------------------------------------------------------------------------
// 
// ---
int CLoadedTreeView::GetIndentLevel(HTREEITEM hItem)
{
  int iIndent = 0;
  if ( hItem )
  {
    CTreeCtrl & m_treeCtrl = GetTreeCtrl();
    while( (hItem = m_treeCtrl.GetParentItem(hItem))!= NULL) iIndent++;
  }
  return iIndent;
}


//-------------------------------------------------------------------------------------------------
// 
// ---
HTREEITEM CLoadedTreeView::GetNextItem(HTREEITEM hItem)
{
  HTREEITEM hti = NULL;
  CTreeCtrl & m_treeCtrl = GetTreeCtrl();
  if( m_treeCtrl.ItemHasChildren(hItem))
    hti = m_treeCtrl.GetChildItem(hItem);
  else 
  {
    while ( (hti=m_treeCtrl.GetNextSiblingItem(hItem))== NULL)
    {
      if ((hItem =m_treeCtrl.GetParentItem(hItem))==NULL) return NULL;
    }
  }
  return hti;
} 


//-------------------------------------------------------------------------------------------------
// 
// ---
BOOL CLoadedTreeView::SaveToFile( LPCTSTR fileName ) 
{
  BOOL res = FALSE;
  CStdioFile file;
  
  if ( file.Open( fileName, CFile::modeCreate| CFile::modeWrite | CFile::typeText ) )
  {
    CStringList strings;
    GetItemsArray( strings );

    POSITION nexpos = strings.GetHeadPosition();
    while ( nexpos )
    {
      file.WriteString( strings.GetNext(nexpos) );
      file.WriteString( _T("\r\n") );
    }
    file.Close();
    res = TRUE;
  }
  return res;
}


//-------------------------------------------------------------------------------------------------
// 
// ---
BOOL CLoadedTreeView::LoadFromFile( LPCTSTR fileName ) 
{
  BOOL res = FALSE;
  CStdioFile file;
  if ( file.Open( fileName, CFile::modeRead ) )
  {
    CStringList strings;
    CString     nextString;

    while ( file.ReadString(nextString) ) 
      strings.AddHead(nextString);
    file.Close();
    
    res = SetItemsArray( strings );
  }
  return res;
}


//-------------------------------------------------------------------------------------------------
// 
// ---
int RemoveIndent( CString & text )
{
  int res = 0;
  int len = text.GetLength();
  if ( len > 0 )
  {
    while ( res < len && text[res] == _T('\t') )
      res++;
    
    if ( res )
      text.Delete(0, res);
  }
  return res;
}


//-------------------------------------------------------------------------------------------------
// 
// ---
BOOL CLoadedTreeView::SetItemsArray( const CStringList & strings ) 
{
  CTreeCtrl & m_treeCtrl = GetTreeCtrl();
  m_treeCtrl.DeleteAllItems();

  POSITION nexpos = strings.GetHeadPosition();
  CString nextString;

  HTREEITEM hti = NULL;
  uint indent;

  SArray<HTREEITEM> parents;
  while ( nexpos )
  {
    nextString = strings.GetNext(nexpos);

    indent = RemoveIndent( nextString );

    if ( !nextString.IsEmpty() )
    {
      while ( indent >= parents.Count() )
        parents.Add( 0 );


      HTREEITEM parent = indent > 0 ? parents[indent-1] : NULL;

      parents[indent] = m_treeCtrl.InsertItem( nextString, 0, 0, parent );
    }
  }
  return TRUE;
}


//-------------------------------------------------------------------------------------------------
// 
// ---
BOOL CLoadedTreeView::GetItemsArray( CStringList & Items )
{
  CTreeCtrl & m_treeCtrl = GetTreeCtrl();

  HTREEITEM hti = m_treeCtrl.GetRootItem();
  while(hti)
  {
    CString nextText;
    int indent = GetIndentLevel(hti);
    while(indent--)
      nextText += '\t';
    
    nextText += m_treeCtrl.GetItemText(hti);

    hti= GetNextItem(hti);
  }
  return TRUE;
}


//-------------------------------------------------------------------------------------------------
// 
// ---
BOOL CLoadedTreeView::GetItemsArray( VARIANT & Items )
{
  BOOL res = FALSE;
  CStringList strings;
  if ( GetItemsArray( strings ) && strings.GetCount() )
  {
    FillBSTRSafeArray( Items, strings );
    res = TRUE;
  }
  return res;
}


//-------------------------------------------------------------------------------------------------
// 
// ---
BOOL CLoadedTreeView::SetItemsArray( const VARIANT & Items )
{
  BOOL res = FALSE;
  CStringList strings;
  FillStrArray( Items, strings );
  return SetItemsArray( strings );
}


IMPLEMENT_DYNCREATE(CksTreeView, COleControl)

//-------------------------------------------------------------------------------------------------
// Message map
// ---
BEGIN_MESSAGE_MAP(CksTreeView, COleControl)
  ON_WM_CREATE()
  ON_WM_DESTROY()

	ON_MESSAGE(OCM_COMMAND, &CksTreeView::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)

  ON_COMMAND_RANGE          ( ksTVGN_IDM_MIN, ksTVGN_IDM_MAX, OnContextMenuCommand )
  ON_UPDATE_COMMAND_UI_RANGE( ksTVGN_IDM_MIN, ksTVGN_IDM_MAX, OnUpdateContextMenuCommand )

  ON_NOTIFY_REFLECT   ( TVN_BEGINLABELEDIT, &CksTreeView::OnBeginLabelEdit)
  ON_NOTIFY_REFLECT   ( TVN_ENDLABELEDIT,   &CksTreeView::OnEndLabelEdit  )
  ON_NOTIFY_REFLECT_EX( TVN_SELCHANGED,     &CksTreeView::OnSelChangedEx  )
  ON_NOTIFY_REFLECT   ( TVN_ITEMEXPANDED,   &CksTreeView::OnItemExpand    )
  ON_NOTIFY_REFLECT   ( NM_RCLICK,          &CksTreeView::OnRClick        )

END_MESSAGE_MAP()


// Идентификатор листа дерева typedef __int64 HTREEITEM_ID
#define VT_HTREEITEM_ID   VT_I8 
#define VTS_HTREEITEM_ID  VTS_I8

//-------------------------------------------------------------------------------------------------
// Dispatch map
// ---
BEGIN_DISPATCH_MAP(CksTreeView, COleControl)
  DISP_PROPERTY_EX_ID( CksTreeView, "Handle",         1, GetHandle,      SetNotSupported, VT_HANDLE )
  DISP_FUNCTION_ID   ( CksTreeView, "AddItem",        2, AddItem,                         VT_HTREEITEM_ID, VTS_HTREEITEM_ID VTS_BSTR )
  DISP_FUNCTION_ID   ( CksTreeView, "SetContextMenu", 3, SetContextMenu,                  VT_EMPTY,  VTS_HANDLE)
  DISP_FUNCTION_ID   ( CksTreeView, "SetImageList",   4, SetImageList,                    VT_EMPTY,  VTS_HANDLE VTS_I4)
  DISP_FUNCTION_ID   ( CksTreeView, "GetNextItem",    5, GetNextItem,                     VT_HTREEITEM_ID, VTS_HTREEITEM_ID VTS_I4)
  DISP_FUNCTION_ID   ( CksTreeView, "LoadFromFile",   6, LoadFromFile,                    VT_BOOL, VTS_BSTR)
  DISP_FUNCTION_ID   ( CksTreeView, "LoadFromFile",   7, SaveToFile,                      VT_BOOL, VTS_BSTR)
  DISP_PROPERTY_EX_ID( CksTreeView, "Items",          8, GetItems,       SetItems,        VT_VARIANT)
  DISP_PROPERTY_EX_ID( CksTreeView, "ReadOnly",       9, GetReadOnly,    SetReadOnly,     VT_BOOL)
END_DISPATCH_MAP()


// Event map
BEGIN_EVENT_MAP(CksTreeView, COleControl)
  EVENT_STOCK_CLICK()
  EVENT_STOCK_DBLCLICK() 
  EVENT_STOCK_KEYDOWN()
  EVENT_STOCK_KEYPRESS()
  EVENT_STOCK_KEYUP() 
  EVENT_STOCK_MOUSEDOWN()
  EVENT_STOCK_MOUSEMOVE()
  EVENT_STOCK_MOUSEUP()

  EVENT_STOCK_READYSTATECHANGE()
END_EVENT_MAP()

BEGIN_INTERFACE_MAP(CksTreeView, COleControl)
  INTERFACE_PART(CksTreeView, IID_IksTreeView, ksTreeView)
 
  DUAL_ERRORINFO_PART(CksTreeView)
END_INTERFACE_MAP()


// Property pages
// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CksTreeView, 1)
	PROPPAGEID(CksTreeViewPropPage::guid)
END_PROPPAGEIDS(CksTreeView)


// Initialize class factory and guid
IMPLEMENT_OLECREATE_EX(CksTreeView, "KSTREEVIEW.ksTreeViewCtrl.1",
	0x241f4962, 0x136b, 0x4589, 0xbb, 0xa4, 0xf2, 0x3f, 0x2a, 0x8d, 0x58, 0xd)

// Type library ID and version
IMPLEMENT_OLETYPELIB(CksTreeView, _tlid, _wVerMajor, _wVerMinor)

// Control type information
static const DWORD BASED_CODE _dwksTreeViewOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CksTreeView, IDS_KSTREEVIEW, _dwksTreeViewOleMisc)


//-------------------------------------------------------------------------------------------------
// Adds or removes system registry entries for CksTreeView
// ---
BOOL CksTreeView::CksTreeViewFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_KSTREEVIEW,
			IDB_KSTREEVIEW,
			afxRegApartmentThreading,
			_dwksTreeViewOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


//-------------------------------------------------------------------------------------------------
// Constructor
// ---
CksTreeView::CksTreeView()
  : m_hMenu( 0 )
{
	InitializeIIDs(&IID_IksTreeView, &DIID__DksTreeViewEvents);
	// TODO: Initialize your control's instance data here.
}



//-------------------------------------------------------------------------------------------------
// Destructor
// ---
CksTreeView::~CksTreeView()
{
	// TODO: Cleanup your control's instance data here.
}

//-------------------------------------------------------------------------------
// Лечим COleControl::GetInterfaceHook который рассчитан на диспинтерфейс а у нас дуальный
// ---
LPUNKNOWN CksTreeView::GetInterfaceHook(const void* piid)
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


//-------------------------------------------------------------------------------------------------
// Drawing function
// ---
void CksTreeView::OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
}


//-------------------------------------------------------------------------------------------------
// Persistence support
// ---
void CksTreeView::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
}


//-------------------------------------------------------------------------------------------------
// Reset control to default state
// ---
void CksTreeView::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
	// TODO: Reset any other control state here.
}


//-------------------------------------------------------------------------------------------------
// Modify parameters for CreateWindowEx
// ---
BOOL CksTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("SysTreeView32");
	return COleControl::PreCreateWindow(cs);
}


//-------------------------------------------------------------------------------------------------
// This is a subclassed control
// ---
BOOL CksTreeView::IsSubclassedControl()
{
	return TRUE;
}


//-------------------------------------------------------------------------------------------------
// CksTreeViewCtrl::OnOcmCommand - Handle command messages
// ---
LRESULT CksTreeView::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

  return 0;
}


//-------------------------------------------------------------------------------------------------
// CksTreeView message handlers
// ---
int CksTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  if (COleControl::OnCreate(lpCreateStruct) == -1)
    return -1;

  // TODO: Add your specialized creation code here

  // Setup embedded member   
  m_treeView.m_hWnd = m_hWnd;	

  // Set style of the CTreeCtrl
  LONG oldStyle = GetWindowLong(m_treeView.m_hWnd, GWL_STYLE);
  LONG newStyle = oldStyle |TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_EDITLABELS; 
  SetWindowLong(m_treeView.m_hWnd, GWL_STYLE, newStyle); 

#ifdef _DEBUG
  // Add some sample data
  CTreeCtrl &treeCtrl = m_treeView.GetTreeCtrl();

  HTREEITEM hRootItem;

  hRootItem = treeCtrl.InsertItem( _T("Root") );
  treeCtrl.InsertItem( _T("One"),   hRootItem);
  treeCtrl.InsertItem( _T("Two"),   hRootItem);
  treeCtrl.InsertItem( _T("Three"), hRootItem);
#endif

  return 0;
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg void CksTreeView::OnDestroy() 
{
  COleControl::OnDestroy();
  // TODO: Add your message handler code here
  m_treeView.m_hWnd = NULL;	
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg void CksTreeView::ShowContextMenu( CPoint & point )
{
  if (point.x == -1 && point.y == -1)
    point = (CPoint) GetMessagePos();

  ScreenToClient(&point);

  CTreeCtrl & tree = m_treeView.GetTreeCtrl();
  UINT uFlags;
  HTREEITEM htItem = tree.HitTest( point, &uFlags );

  if( htItem == NULL || !(uFlags & (TVHT_ONITEM | TVHT_ONITEMINDENT | TVHT_ONITEMRIGHT) ) )
    return;


  HTREEITEM selectedItem = tree.GetSelectedItem();
  if ( selectedItem != htItem )
    tree.SelectItem(htItem);
  else
    FireNodeEvent( DISPID_ItemClick, (HTREEITEM_ID)htItem);

  ClientToScreen(&point);
//    int id = TrackPopupMenu(m_hMenu, TPM_LEFTALIGN | TPM_RIGHTBUTTON | TPM_RETURNCMD, point.x, point.y, 0, m_hWnd, NULL);
//    if ( id )
//      FireMenuCommand( id );

  if ( m_hMenu && ::IsMenu( m_hMenu ) )
  {
    ::TrackPopupMenu( m_hMenu, TPM_LEFTALIGN, point.x, point.y, 0, m_hWnd, NULL );
    RedrawWindow( NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_FRAME | RDW_ALLCHILDREN );
  }
}


//-----------------------------------------------------------------------------
/// 
// ---
void CksTreeView::OnContextMenuCommand ( UINT id )
{
  FireMenuCommand( id );
}


//-------------------------------------------------------------------------------
// UpdateContextMenuCommand
// ---
afx_msg void CksTreeView::OnUpdateContextMenuCommand( CCmdUI * pCmdUI)
{
  FireUpdateContextMenuCommand( pCmdUI );
}


//-------------------------------------------------------------------------------
//
// ---
afx_msg void CksTreeView::OnBeginLabelEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
  TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
  *pResult = m_treeView.GetReadOnly() ? 1 : FireBeginLebelEdit();
}


//-------------------------------------------------------------------------------
// 
// ---
afx_msg void CksTreeView::OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
  TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
 
  *pResult = FireEndLebelEdit( pTVDispInfo->item.pszText, pTVDispInfo->item.cchTextMax );
  if ( !*pResult )
    m_treeView.GetTreeCtrl().SetItemText( pTVDispInfo->item.hItem, pTVDispInfo->item.pszText );
}


//-------------------------------------------------------------------------------
// 
// ---
afx_msg BOOL CksTreeView::OnSelChangedEx( NMHDR * pNMHDR, LRESULT * pResult )
{
  NM_TREEVIEW * pNMTreeView = (NM_TREEVIEW *)pNMHDR;
  FireNodeEvent( DISPID_ItemClick, (HTREEITEM_ID)pNMTreeView->itemNew.hItem );
  return TRUE;
}


//-------------------------------------------------------------------------------
// 
// ---
afx_msg void CksTreeView::OnItemExpand( NMHDR * pNMHDR, LRESULT * pResult )
{
  NM_TREEVIEW * pNMTreeView = (NM_TREEVIEW *)pNMHDR;
  FireNodeEvent( pNMTreeView->action == TVE_COLLAPSE ? DISPID_ItemCollapse : DISPID_ItemExpand , (HTREEITEM_ID)pNMTreeView->itemNew.hItem );
}


//-------------------------------------------------------------------------------
// 
// ---
afx_msg void CksTreeView::OnRClick( NMHDR * pNMHDR, LRESULT * pResult )
{
  CPoint p;
  GetCursorPos(&p);
  ShowContextMenu( p );
}


//-------------------------------------------------------------------------------
/// Возвращает HWND окна
// ---
BOOL CksTreeView::PreTranslateMessage( MSG* pMsg )
{
  BOOL ret = COleControl::PreTranslateMessage( pMsg );
  if ( !ret && pMsg && !m_treeView.GetReadOnly() ) 
  {
    if ( pMsg->message == WM_KEYDOWN ) 
    {

      TRACE( "WM_KEYDOWN %d\n", pMsg->wParam );
      HWND focusWnd = ::GetFocus();
      if ( focusWnd == m_hWnd || ::IsChild( m_hWnd, focusWnd ) ) 
      {
        switch ( pMsg->wParam ) 
        {
          case  VK_ESCAPE :  // подтверждение ввода имени
          {
            if ( m_treeView.GetTreeCtrl().GetEditControl() )
              ret = !!SendMessage( TVM_ENDEDITLABELNOW, TRUE, 0 );
            else
              ret = 0;
            break ;
          }
          case  VK_RETURN :  // подтверждение ввода имени
            ret = !!SendMessage( TVM_ENDEDITLABELNOW, FALSE, 0 );
            break ;
          case  VK_F2 : // запуск ввода имени
          { 
            HTREEITEM hSelected = m_treeView.GetTreeCtrl().GetSelectedItem();
            if ( hSelected ) 
            {
              SendMessage( TVM_EDITLABEL, 0, (LPARAM)hSelected );
              ret = TRUE;
            }
            break;
          }
        }
      }
    }
  }
  return ret;
}


// FireEvents
//-------------------------------------------------------------------------------
/// BeginLebelEdit
// ---
LRESULT CksTreeView::FireBeginLebelEdit()
{
  short c  = 0;
  ExternalAddRef();   // "Insurance" addref -- keeps control alive.
  FireEvent( DISPID_BeginLabelEdit, EVENT_PARAM(VTS_PI2), &c );
  ExternalRelease();
  return c; 
}


//-------------------------------------------------------------------------------
/// FireEndLebelEdit
// ---
LRESULT CksTreeView::FireEndLebelEdit( LPTSTR NewString, int cchTextMax )
{
  ExternalAddRef();   // "Insurance" addref -- keeps control alive.

  const CStringW str(NewString);
  BSTR bstr = NewString ? str.AllocSysString() : NULL;
  short c;
  FireEvent( DISPID_EndLabelEdit, EVENT_PARAM(VTS_PI2 VTS_PBSTR), &c, &bstr );

  _bstr_t newStr(bstr);
  if ( !c && newStr.length() )
    _tcsncpy_s( NewString, cchTextMax, newStr, newStr.length() );   

  ::SysFreeString(bstr);

  ExternalRelease();
  return c; 
}


//-------------------------------------------------------------------------------
// FireMenuCommand
// ---
void CksTreeView::FireMenuCommand(long Id)
{ 
  ExternalAddRef();   // "Insurance" addref -- keeps control alive.
  FireEvent(DISPID_MenuCommand,EVENT_PARAM(VTS_I4), Id);
  ExternalRelease();
}


//-------------------------------------------------------------------------------
// FireMenuCommand
// ---
void CksTreeView::FireNodeEvent( DISPID dispid, HTREEITEM_ID nodeId )
{ 
  ExternalAddRef();   // "Insurance" addref -- keeps control alive.
  FireEvent(dispid, EVENT_PARAM(VTS_HTREEITEM_ID), nodeId);
  ExternalRelease();
}


//-------------------------------------------------------------------------------
// FireMenuCommand
// ---
void CksTreeView::FireUpdateContextMenuCommand(CCmdUI * pCmdUI )
{ 
  ExternalAddRef();   // "Insurance" addref -- keeps control alive.

  long         cmId    = pCmdUI->m_nID;
  BOOL         Enable  = VARIANT_TRUE;
  long         checked = 0;

  FireEvent(DISPID_MenuUpdate,EVENT_PARAM(VTS_I4 VTS_PBOOL VTS_PI4), cmId, &Enable, &checked );

  pCmdUI->Enable( Enable );
  pCmdUI->SetCheck( checked );

  ExternalRelease();
}


// IksTreeView
//-------------------------------------------------------------------------------
/// Возвращает HWND окна
// ---
afx_msg OLE_HANDLE CksTreeView::GetHandle()
{
  return (OLE_HANDLE)(size_t)m_hWnd;
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg HTREEITEM_ID CksTreeView::AddItem( HTREEITEM_ID PatentItemID, LPCTSTR ItemText, long nImage, long nSelectImage, HTREEITEM_ID hInsertAfter )
{
  HTREEITEM_ID res = 0;
  if ( ::IsWindow(m_treeView.m_hWnd) )
  {
    CTreeCtrl &treeCtrl = m_treeView.GetTreeCtrl();
    res = (HTREEITEM_ID)treeCtrl.InsertItem( ItemText, nImage, nSelectImage, (HTREEITEM)(void*)PatentItemID, (HTREEITEM)(void*)hInsertAfter );
  }
  return res;
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg void CksTreeView::SetContextMenu( OLE_HANDLE val )
{
  m_hMenu = (HMENU)(size_t)val;
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg void CksTreeView::SetImageList( OLE_HANDLE Val, long NImageListType )
{
  if ( Val && ::IsWindow(m_treeView.m_hWnd) )
  {
    CTreeCtrl &treeCtrl = m_treeView.GetTreeCtrl();
    CImageList * imageList = CImageList::FromHandle( (HIMAGELIST)(size_t)Val );
    if ( imageList )
      treeCtrl.SetImageList( imageList, NImageListType );
  }
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg HTREEITEM_ID CksTreeView::GetNextItem( HTREEITEM_ID HItem, ksTreeViewNextItemEnum NCode )
{
  HTREEITEM_ID res = 0;
  if ( ::IsWindow(m_treeView.m_hWnd) )
  {
    CTreeCtrl &treeCtrl = m_treeView.GetTreeCtrl();
    res = (HTREEITEM_ID)treeCtrl.GetNextItem( (HTREEITEM)(void*)HItem, NCode );
  }
  return res;
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg BOOL CksTreeView::LoadFromFile( LPCTSTR FileName )
{
  return m_treeView.LoadFromFile( FileName );
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg BOOL CksTreeView::SaveToFile( LPCTSTR FileName )
{
  return m_treeView.SaveToFile( FileName );
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg VARIANT CksTreeView::GetItems()
{
  VARIANT res;
  VariantInit(&res);
  m_treeView.GetItemsArray(res);
  return res;
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg void CksTreeView::SetItems( const VARIANT FAR& items )
{
  m_treeView.SetItemsArray( items );
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg BOOL CksTreeView::GetReadOnly()
{
  return m_treeView.GetReadOnly();
}


//-------------------------------------------------------------------------------------------------
//
// ---
afx_msg void CksTreeView::SetReadOnly( BOOL val )
{
  m_treeView.SetReadOnly( val );
}


////////////////////////////////////////////////////////////////////////////////
//
// Реализация дуального интерфейса IApplication (COM)
//
////////////////////////////////////////////////////////////////////////////////
// Реализация стандартных методов IDispatch 
DELEGATE_DUAL_INTERFACE(CksTreeView, ksTreeView)

//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( ksTreeView, get_Handle, OLE_HANDLE * Result ) 
  CALL_GET_METHOD(Result, GetHandle)
END_DUAL_METHOD


//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD_6( ksTreeView, AddItem, HTREEITEM_ID PatentItemID, BSTR ItemText, long nImage, long nSelectImage, HTREEITEM_ID hInsertAfter, HTREEITEM_ID *ItemId ) 
  if ( ItemId )
  {
    *ItemId = pThis->AddItem( PatentItemID, CString(ItemText), nImage, nSelectImage, hInsertAfter );
    return S_OK;
  }
  else
    return E_INVALIDARG;
END_DUAL_METHOD

//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( ksTreeView, SetContextMenu, OLE_HANDLE Val ) 
  CALL_SET_METHOD(Val, ContextMenu )
END_DUAL_METHOD

//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD_2( ksTreeView, SetImageList, OLE_HANDLE Val, long NImageListType ) 
  pThis->SetImageList( Val,  NImageListType );
  return S_OK;
END_DUAL_METHOD

//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD_3( ksTreeView, GetNextItem, HTREEITEM_ID HItem, ksTreeViewNextItemEnum NCode, HTREEITEM_ID *NextItemId ) 
  if ( NextItemId )
  {
    *NextItemId = pThis->GetNextItem( HItem,  NCode );
    return S_OK;
  }
  else
    return E_INVALIDARG;
END_DUAL_METHOD


//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD_2( ksTreeView, LoadFromFile, BSTR FileName, VARIANT_BOOL *Result ) 
  if ( Result )
  {
    *Result = pThis->LoadFromFile( CString(FileName) );
    return S_OK;
  }
  else
    return E_INVALIDARG;
END_DUAL_METHOD


//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD_2( ksTreeView, SaveToFile, BSTR FileName, VARIANT_BOOL *Result ) 
  if ( Result )
  {
    *Result = pThis->SaveToFile( CString(FileName) );
    return S_OK;
  }
  else
    return E_INVALIDARG;
END_DUAL_METHOD


//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( ksTreeView, get_Items, VARIANT * Result ) 
  CALL_GET_METHOD(Result, GetItems)
END_DUAL_METHOD


//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( ksTreeView, put_Items, VARIANT Items ) 
  CALL_SET_METHOD(Items, Items)
END_DUAL_METHOD

//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( ksTreeView, get_ReadOnly, VARIANT_BOOL * Result ) 
  CALL_GET_METHOD(Result, GetReadOnly)
END_DUAL_METHOD


//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( ksTreeView, put_ReadOnly, VARIANT_BOOL Val ) 
  CALL_SET_METHOD(Val, ReadOnly)
END_DUAL_METHOD


//-----------------------------------------------------------------------------
/// Реализация ISupportErrorInfo 
IMPLEMENT_DUAL_ERRORINFO( CksTreeView, IID_IksTreeView )