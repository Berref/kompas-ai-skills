// ksTreeView.cpp : Implementation of CksTreeViewApp and DLL registration.

#include "stdafx.h"


#include "ksTreeView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CksTreeViewApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x583EF606, 0x355, 0x4170, { 0x9E, 0xA7, 0xEE, 0x3D, 0x62, 0xFD, 0x96, 0x81 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;

HHOOK hHook = NULL;

// Hook procedure for WH_GETMESSAGE hook type.
LRESULT CALLBACK GetMessageProc(int nCode, WPARAM wParam, LPARAM
                                lParam)
{
  // Switch the module state for the correct handle to be used.
  AFX_MANAGE_STATE(_afxModuleAddrThis);

  // If this is a keystrokes message, translate it in controls'
  // PreTranslateMessage().
  LPMSG lpMsg = (LPMSG) lParam;

  if( (nCode >= 0) &&
    PM_REMOVE == wParam &&
    AfxGetApp()->PreTranslateMessage(lpMsg))
  {
    lpMsg->message = WM_NULL;
    lpMsg->lParam = 0L;
    lpMsg->wParam = 0;
  }


  // Passes the hook information to the next hook procedure in
  // the current hook chain.
  return ::CallNextHookEx(hHook, nCode, wParam, lParam);
}


CksTreeViewApp::CksTreeViewApp()
  : hHook(  NULL )
{
}

// CksTreeViewApp::InitInstance - DLL initialization

BOOL CksTreeViewApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
    AfxEnableControlContainer();

		// TODO: Add your own module initialization code here.
    hook();
	}

	return bInit;
}



// CksTreeViewApp::ExitInstance - DLL termination

int CksTreeViewApp::ExitInstance()
{
	// TODO: Add your own module termination code here.
  unhook();
	return COleControlModule::ExitInstance();
}

void CksTreeViewApp::hook()
{
  hHook = ::SetWindowsHookEx(WH_GETMESSAGE, GetMessageProc, AfxGetInstanceHandle(), GetCurrentThreadId());
  ASSERT(hHook);
}


void CksTreeViewApp::unhook()
{
  if ( hHook )
    VERIFY( ::UnhookWindowsHookEx(hHook) );
  hHook = 0;
}


// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
