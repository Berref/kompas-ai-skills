#if !defined(AFX_STDAFX_H__DBCAAEE2_2376_4357_B3EF_C8FB54ED5626__INCLUDED_)
#define AFX_STDAFX_H__DBCAAEE2_2376_4357_B3EF_C8FB54ED5626__INCLUDED_

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
#pragma warning( disable : 4192 )
#pragma warning( disable : 4278 )

#import <ksConstants.tlb>   no_namespace named_guids
#import <ksConstants3D.tlb> no_namespace named_guids

#include <libtool.h>

#import <kAPI2D5COM.tlb>    no_namespace named_guids
#import <kAPI3D5COM.tlb>    no_namespace named_guids 

#include <LHead3d.h>
#import <kAPI7.tlb>       rename( "KompasAPI7", "ksAPI7" ) named_guids

#pragma warning( once : 4192 )
#pragma warning( once : 4278 ) 

#endif // !defined(AFX_STDAFX_H__DBCAAEE2_2376_4357_B3EF_C8FB54ED5626__INCLUDED_)
