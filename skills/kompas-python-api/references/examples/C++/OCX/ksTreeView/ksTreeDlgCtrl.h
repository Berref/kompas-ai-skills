#pragma once

#include "ksTreeViewidl.h"
#include "mfcdual.h"

#include "ksTreeViewCtrl.h"


//-----------------------------------------------------------------------------
// ToolBar с загрузкой из внешнего модуля 
// ---
class CExternalToolBar : public CToolBar
{
  DECLARE_DYNCREATE(CExternalToolBar)

protected:
  HINSTANCE    m_hInstance;
  bool         m_loaded;
  CToolTipCtrl m_ToolTip;

public:
  CExternalToolBar() 
    : m_hInstance ( NULL )
    , m_loaded ( false )
  {
  }

  ~CExternalToolBar(); 
 
  BOOL            LoadToolBar    ( const VARIANT FAR& ResModule, const VARIANT FAR& ToolbarId );
  afx_msg BOOL    OnToolTipNotify( UINT id, NMHDR * pNMHDR, LRESULT * pResult                 );
  virtual LRESULT WindowProc     ( UINT nMsg, WPARAM wParam, LPARAM lParam                    );

  DECLARE_MESSAGE_MAP()
};


//-----------------------------------------------------------------------------
// 
// ---
class CksTreeDlg : public COleControl
{
	DECLARE_DYNCREATE(CksTreeDlg)

protected:
  CExternalToolBar            m_ToolBar;
  CksTreeView                 m_TreeView;

// Constructor
public:
	CksTreeDlg();

// Overrides
public:
	virtual void DoPropExchange ( CPropExchange* pPX );
	virtual void OnResetState   ();
  virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
  virtual BOOL OnCmdMsg       (UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

  afx_msg int  OnCreate       ( LPCREATESTRUCT lpCreateStruct );
  afx_msg void OnSize         ( UINT nType, int cx, int cy );

  afx_msg void OnToolBarCommand( UINT id );
  afx_msg void OnUpdateToolBarCommand( CCmdUI * );

// Implementation
protected:
	~CksTreeDlg();

	DECLARE_OLECREATE_EX(CksTreeDlg)    // Class factory and guid
	DECLARE_OLETYPELIB  (CksTreeDlg)    // GetTypeInfo
	DECLARE_PROPPAGEIDS (CksTreeDlg)    // Property page IDs
	DECLARE_OLECTLTYPE  (CksTreeDlg)		// Type name and misc status

  // IksTreeDlg
  LPDISPATCH GetTreeView();
  BOOL       LoadToolBar( const VARIANT FAR& ResModule, const VARIANT FAR& ToolbarId );

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_EVENT_MAP()
  DECLARE_INTERFACE_MAP()

  // Добавляем описание интерфейса IksTreeDlg
  BEGIN_DUAL_INTERFACE_PART( ksTreeDlg, IksTreeDlg )
    STDMETHOD(get_TreeView   )( THIS_ IksTreeView **Tree );
    STDMETHOD(LoadToolBar    )( THIS_ VARIANT ResModule, VARIANT ToolbarId, VARIANT_BOOL *Result);
  END_DUAL_INTERFACE_PART( ksTreeDlg )

  DECLARE_DUAL_ERRORINFO()

  virtual LPUNKNOWN  GetInterfaceHook(const void*);
// Dispatch and event IDs
protected:
	enum {
    DISPID_ToolBarCommand = 1, 
    DISPID_ButtinUpdate   = 2, 
	};

public:
  void  FireToolBarCommand      ( long Id );
  void  FireUpdateToolBarCommand( CCmdUI * pCmdUI );

};

