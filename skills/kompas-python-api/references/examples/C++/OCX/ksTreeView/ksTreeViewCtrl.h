#pragma once

// ksTreeViewCtrl.h : Declaration of the CksTreeViewCtrl ActiveX Control class.
#include <afxcview.h>
#include "ksTreeViewidl.h"
#include "mfcdual.h"

//-----------------------------------------------------------------------------
// Дерево с загрузкой из файла
// ---
class CLoadedTreeView : public CTreeView
{
protected:
  bool m_readOnly; 

public:
  CLoadedTreeView() : m_readOnly( false ) 
  {
  }
 
  BOOL LoadFromFile( LPCTSTR fileName );
  BOOL SaveToFile  ( LPCTSTR fileName );

  BOOL GetItemsArray(       VARIANT & Items );
  BOOL SetItemsArray( const VARIANT & Items );

  BOOL GetReadOnly() { return m_readOnly; }
  void SetReadOnly( BOOL readOnly ) { m_readOnly = !!readOnly; }

protected:
  int       GetIndentLevel( HTREEITEM hItem );
  HTREEITEM GetNextItem   ( HTREEITEM hItem );

  BOOL GetItemsArray(       CStringList & Items );
  BOOL SetItemsArray( const CStringList & Items );

};


// CksTreeViewCtrl : See ksTreeViewCtrl.cpp for implementation.
class CksTreeView : public COleControl
{
	DECLARE_DYNCREATE(CksTreeView)

// Constructor
public:
	CksTreeView();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
	~CksTreeView();

	DECLARE_OLECREATE_EX(CksTreeView)   // Class factory and guid
	DECLARE_OLETYPELIB  (CksTreeView)   // GetTypeInfo
	DECLARE_PROPPAGEIDS (CksTreeView)   // Property page IDs
	DECLARE_OLECTLTYPE  (CksTreeView)		// Type name and misc status

	// Subclassed control support
  virtual BOOL PreCreateWindow     (CREATESTRUCT& cs);
  virtual BOOL PreTranslateMessage ( MSG* pMsg );

  BOOL         IsSubclassedControl ();
	LRESULT      OnOcmCommand        (WPARAM wParam, LPARAM lParam);


  afx_msg int  OnCreate            (LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnDestroy           ();
  afx_msg void OnContextMenuCommand( UINT id );
          void ShowContextMenu     ( CPoint & point);
  afx_msg void OnUpdateContextMenuCommand( CCmdUI * );


  afx_msg void OnBeginLabelEdit    ( NMHDR * pNMHDR, LRESULT * pResult );
  afx_msg void OnEndLabelEdit      ( NMHDR * pNMHDR, LRESULT * pResult );
  afx_msg BOOL OnSelChangedEx      ( NMHDR * pNMHDR, LRESULT * pResult );
  afx_msg void OnItemExpand        ( NMHDR * pNMHDR, LRESULT * pResult );
  afx_msg BOOL OnItemClick         ( NMHDR * pNMHDR, LRESULT * pResult );
  afx_msg void OnRClick            ( NMHDR * pNMHDR, LRESULT * pResult );


	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_EVENT_MAP()
  DECLARE_INTERFACE_MAP()

  // IksTreeView
  afx_msg OLE_HANDLE   GetHandle     ();
  afx_msg HTREEITEM_ID AddItem       ( HTREEITEM_ID PatentItemID, LPCTSTR ItemText, long nImage, long nSelectImage, HTREEITEM_ID hInsertAfter );
  afx_msg void         SetContextMenu( OLE_HANDLE Val );
  afx_msg void         SetImageList  ( OLE_HANDLE Val, long NImageListType );
  afx_msg HTREEITEM_ID GetNextItem   ( HTREEITEM_ID HItem, ksTreeViewNextItemEnum NCode );
  afx_msg BOOL         LoadFromFile  ( LPCTSTR FileName );
  afx_msg BOOL         SaveToFile    ( LPCTSTR FileName );
  afx_msg VARIANT      GetItems      ();
  afx_msg void         SetItems      ( const VARIANT FAR& items );
  afx_msg BOOL         GetReadOnly   ();
  afx_msg void         SetReadOnly   ( BOOL val );


  // Добавляем описание интерфейса IksTreeView
  BEGIN_DUAL_INTERFACE_PART( ksTreeView, IksTreeView )
    STDMETHOD(get_Handle    )( THIS_ OLE_HANDLE * ItemId );
    STDMETHOD(AddItem       )( THIS_ HTREEITEM_ID PatentItemID, BSTR ItemText, long nImage, long nSelectImage, HTREEITEM_ID hInsertAfter, HTREEITEM_ID *ItemId );
    STDMETHOD(SetContextMenu)( THIS_ OLE_HANDLE Val );
    STDMETHOD(SetImageList  )( THIS_ OLE_HANDLE Val, long NImageListType );
    STDMETHOD(GetNextItem   )( THIS_ HTREEITEM_ID HItem, ksTreeViewNextItemEnum NCode, HTREEITEM_ID *NextItemId );
    STDMETHOD(LoadFromFile  )( THIS_ BSTR FileName, VARIANT_BOOL *Result );
    STDMETHOD(SaveToFile    )( THIS_ BSTR FileName, VARIANT_BOOL *Result );
    STDMETHOD(get_Items     )( THIS_ VARIANT *Items );
    STDMETHOD(put_Items     )( THIS_ VARIANT Items  );
    STDMETHOD(get_ReadOnly  )( THIS_ VARIANT_BOOL *pVal );
    STDMETHOD(put_ReadOnly  )( THIS_ VARIANT_BOOL Val );

  END_DUAL_INTERFACE_PART( ksTreeView )

  virtual LPUNKNOWN  GetInterfaceHook(const void*);

  DECLARE_DUAL_ERRORINFO()
  

  LRESULT FireBeginLebelEdit();
  LRESULT FireEndLebelEdit  ( LPTSTR NewString, int cchTextMax );
  void    FireMenuCommand   (long Id);
  void    FireNodeEvent     ( DISPID dispid, HTREEITEM_ID nodeId ); 
  void    FireUpdateContextMenuCommand( CCmdUI * pCmdUI );

// Dispatch and event IDs
public:
	enum {
    DISPID_BeginLabelEdit = 1,
    DISPID_EndLabelEdit   = 2,
    DISPID_ItemCollapse   = 3,
    DISPID_ItemExpand     = 4,
    DISPID_ItemClick      = 5,
    DISPID_MenuCommand    = 7,
    DISPID_MenuUpdate     = 8, 
	};

protected:
  CLoadedTreeView m_treeView;
  HMENU           m_hMenu;    // Не владеет
};

