#if !defined(AFX_STDAFX_H__D9BCCDE7_5A1F_4FD4_87C5_2E95A817E87C__INCLUDED_)
#define AFX_STDAFX_H__D9BCCDE7_5A1F_4FD4_87C5_2E95A817E87C__INCLUDED_

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcmn.h>         // MFC support for Windows 95 Common Controls

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT


#include <afxctl.h>         // MFC support for OLE Controls

#pragma warning( disable : 4192 )
#pragma warning( disable : 4278 )

#import "ksConstants.tlb"   no_namespace named_guids
#import "ksConstants3D.tlb" no_namespace named_guids

#include <libtool.h>
#import "kAPI7.tlb"         no_namespace named_guids

#pragma warning( once : 4192 )
#pragma warning( once : 4278 ) 

#endif // !defined(AFX_STDAFX_H__D9BCCDE7_5A1F_4FD4_87C5_2E95A817E87C__INCLUDED_)
