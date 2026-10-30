#if !defined(AFX_STDAFX_H__2BB1853E_7290_4B00_8B3B_E3CBB555200F__INCLUDED_)
#define AFX_STDAFX_H__2BB1853E_7290_4B00_8B3B_E3CBB555200F__INCLUDED_

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcmn.h>         // MFC support for Windows 95 Common Controls

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#include <COMUTIL.H>
#include <comdef.h>
#include <AFXCTL.H>

#pragma warning( disable : 4192 )
#pragma warning( disable : 4146 )
#pragma warning( disable : 4278 )

#import "ksConstants.tlb"   no_namespace named_guids
#import "ksConstants3D.tlb" no_namespace named_guids

#import "kAPI2D5COM.tlb"    no_namespace named_guids
#import "kAPI3D5COM.tlb"    no_namespace named_guids

#include <libtool.h>
#include <LHead3d.h>
#import "kAPI5.tlb"         no_namespace named_guids rename( "ksFragmentLibrary", "ksIFragmentLibrary" )
#import "kAPI7.tlb"         no_namespace named_guids

#pragma warning( once : 4146 ) 
#pragma warning( once : 4192 ) 
#pragma warning( once : 4278 )

#endif // !defined(AFX_STDAFX_H__2BB1853E_7290_4B00_8B3B_E3CBB555200F__INCLUDED_)
