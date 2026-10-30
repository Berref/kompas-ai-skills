// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__3876F929_6893_11D5_94AD_FC019B4CD066__INCLUDED_)
#define AFX_STDAFX_H__3876F929_6893_11D5_94AD_FC019B4CD066__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


//-------------------------------------------------------------------------------
// kAPI5.tlb
// ---
#pragma warning( disable : 4278 )
#import "ksConstants.tlb" no_namespace
#import "ksConstants3D.tlb" no_namespace  
#import "kAPI5.tlb" no_namespace named_guids
#import "kAPI7.tlb" no_namespace named_guids
#pragma warning( once : 4278 )

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__3876F929_6893_11D5_94AD_FC019B4CD066__INCLUDED_)
