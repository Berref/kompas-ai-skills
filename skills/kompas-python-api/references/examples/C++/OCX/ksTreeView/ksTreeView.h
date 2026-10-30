#pragma once

// ksTreeView.h : main header file for ksTreeView.DLL

#if !defined( __AFXCTL_H__ )
#error "include 'afxctl.h' before including this file"
#endif

#include "resource.h"       // main symbols


// CksTreeViewApp : See ksTreeView.cpp for implementation.

class CksTreeViewApp : public COleControlModule
{
public:

  CksTreeViewApp();

	BOOL InitInstance();
	int ExitInstance();

  void hook();
  void unhook();

  HHOOK hHook;
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

