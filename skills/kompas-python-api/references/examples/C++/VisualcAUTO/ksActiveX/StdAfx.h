// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__AA46C440_9CF3_4BD4_ADFA_ED8A14505050__INCLUDED_)
#define AFX_STDAFX_H__AA46C440_9CF3_4BD4_ADFA_ED8A14505050__INCLUDED_

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

#pragma warning( disable : 4278 )
#define KSCONSTANTS3D_TLB	"libid:2CAF168C-7961-4B90-9DA2-701419BEEFE3"
#define KSCONSTANTS_TLB		"libid:75C9F5D0-B5B8-4526-8681-9903C567D2ED"
#define KAPI5_TLB			    "libid:0422828C-F174-495E-AC5D-D31014DBBE87"
#define KAPI7_TLB			    "libid:69AC2981-37C0-4379-84FD-5DD2F3C0A520"
#define KGAX_OCX			    "progid:KGAX.KGAXCtrl.1"

//#import "kapi5.tlb" no_namespace, named_guids
//#import "kgax.ocx" no_namespace, named_guids
#import KSCONSTANTS_TLB   no_namespace named_guids
#import KSCONSTANTS3D_TLB no_namespace named_guids
#import KAPI5_TLB         no_namespace named_guids
#import KAPI7_TLB         no_namespace named_guids
#import KGAX_OCX          no_namespace named_guids

#pragma warning( once : 4278 ) 

#include <ldefin2d.h>			// MFC support for Windows Common Controls

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__AA46C440_9CF3_4BD4_ADFA_ED8A14505050__INCLUDED_)
