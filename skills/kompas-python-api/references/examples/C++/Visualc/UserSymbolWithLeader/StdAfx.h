#if !defined(AFX_STDAFX_H__B5FD1F19_6C41_4BFF_9824_D8D7E665E790__INCLUDED_)
#define AFX_STDAFX_H__B5FD1F19_6C41_4BFF_9824_D8D7E665E790__INCLUDED_

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

#import "ksConstants.tlb"   no_namespace named_guids
#import "ksConstants3D.tlb" no_namespace named_guids

#include <libtool.h>
//#import "kApi5.tlb"         no_namespace named_guids rename( "ksFragmentLibrary", "ksIFragmentLibrary" )
#import "kAPI7.tlb"           no_namespace named_guids rename( "KompasAPI7", "ksAPI7" )

#pragma warning( once : 4192 ) 

#endif // !defined(AFX_STDAFX_H__B5FD1F19_6C41_4BFF_9824_D8D7E665E790__INCLUDED_)
