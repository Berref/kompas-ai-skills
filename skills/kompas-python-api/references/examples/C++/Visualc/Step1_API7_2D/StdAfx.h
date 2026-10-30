#if !defined(AFX_STDAFX_H__7C1BADB2_B1A3_46BD_B4DA_2A7D8616C80D__INCLUDED_)
#define AFX_STDAFX_H__7C1BADB2_B1A3_46BD_B4DA_2A7D8616C80D__INCLUDED_

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcmn.h>         // MFC support for Windows 95 Common Controls

#include <AFXDISP.H>
#include <COMUTIL.H>
#include <comdef.h>
#pragma warning( disable : 4192 )
#pragma warning( disable : 4278 )

#import "ksConstants.tlb"   no_namespace named_guids
#import "ksConstants3D.tlb" no_namespace named_guids

#include <libtool.h>
#import "kAPI7.tlb"      rename( "KompasAPI7", "ksAPI7" ) named_guids
#pragma warning( once : 4192 ) 
#pragma warning( once : 4278 )


#endif // !defined(AFX_STDAFX_H__7C1BADB2_B1A3_46BD_B4DA_2A7D8616C80D__INCLUDED_)
