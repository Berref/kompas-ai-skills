#if !defined(AFX_STDAFX_H__2BD6A50F_10CC_4DBA_BD0B_845CD03B6DCC__INCLUDED_)
#define AFX_STDAFX_H__2BD6A50F_10CC_4DBA_BD0B_845CD03B6DCC__INCLUDED_

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcmn.h>         // MFC support for Windows 95 Common Controls


#include <COMUTIL.H>
#include <comdef.h>
#pragma warning( disable : 4192 )
#pragma warning( disable : 4278 )

#import "ksConstants.tlb"   no_namespace named_guids
#import "ksConstants3D.tlb" no_namespace named_guids

#include "libtool.h"

#import "kAPI2D5COM.tlb"    no_namespace named_guids
#import "kAPI7.tlb" rename( "KompasAPI7", "ksAPI7" ) named_guids  /*no_namespace*/

#pragma warning( once : 4192 )
#pragma warning( once : 4278 ) 

#endif // !defined(AFX_STDAFX_H__2BD6A50F_10CC_4DBA_BD0B_845CD03B6DCC__INCLUDED_)
