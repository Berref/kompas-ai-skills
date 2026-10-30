#if !defined(AFX_STDAFX_H__94A92CED_89BC_4CB9_9942_294619972CA3__INCLUDED_)
#define AFX_STDAFX_H__94A92CED_89BC_4CB9_9942_294619972CA3__INCLUDED_

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcmn.h>         // MFC support for Windows 95 Common Controls

#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


#include <COMUTIL.H>
#include <comdef.h>
#pragma warning( disable : 4192 )
#pragma warning( disable : 4278 )

#import "ksConstants.tlb"   no_namespace named_guids
#import "ksConstants3D.tlb" no_namespace named_guids

#include <libtool.h>

#import "kAPI2D5COM.tlb"    no_namespace named_guids
#import "kAPI3D5COM.tlb"    no_namespace named_guids 

#include <LHead3d.h>
#import "kAPI7.tlb"         no_namespace named_guids

#pragma warning( once : 4192 )
#pragma warning( once : 4278 ) 

#include "Resource.h"

#endif // !defined(AFX_STDAFX_H__94A92CED_89BC_4CB9_9942_294619972CA3__INCLUDED_)
