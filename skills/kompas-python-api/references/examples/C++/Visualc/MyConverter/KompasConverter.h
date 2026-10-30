////////////////////////////////////////////////////////////////////////////////
//
// KompasConverter - стандартный интерфейс КОМПАС для библиотек импорта / экспорта
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __KOMPASCONVERTER_H
#define __KOMPASCONVERTER_H

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "AFXWIN.H"

#include "mfcdual.h"

#include <ConvertLibIntDual.h>
#include "MyConverterDual.h"

//////////////////////////////////////////////////////////////////////////
//
// KompasConverter - стандартный интерфейс КОМПАС для библиотек импорта / экспорта
//
//////////////////////////////////////////////////////////////////////////
class KompasConverter : public CCmdTarget
{
  DECLARE_DYNAMIC(KompasConverter)

public:
                     KompasConverter();
            virtual ~KompasConverter();

protected :
            virtual BOOL       GetDispatchIID        ( IID * pIID );
            virtual void       OnFinalRelease        ();
    afx_msg virtual IUnknown * ConverterParameters   ( long command );
    afx_msg virtual BOOL       GetCanUnLoadLibrary   ();
    afx_msg virtual BSTR       GetFilter             ( long docType, BOOL saveAs, long * command );
    afx_msg virtual long       Convert               ( LPCTSTR inputFile, LPCTSTR outfile, long command, BOOL showParam );    
    afx_msg virtual BOOL       VisualEditConvertParam( OLE_HANDLE parentHwnd, long command );    


  DECLARE_OLETYPELIB   ( KompasConverter )
	DECLARE_MESSAGE_MAP  ()
	DECLARE_DISPATCH_MAP ()
	DECLARE_INTERFACE_MAP()
  BEGIN_DUAL_INTERFACE_PART( KompasConverter, IKompasConverter )

  STDMETHOD(ConverterParameters   ) ( THIS_ long, IUnknown **  val );
  STDMETHOD(get_CanUnloadLibrary  ) ( THIS_ VARIANT_BOOL *             );
  STDMETHOD(GetFilter             ) ( THIS_ long docType, VARIANT_BOOL, long *, BSTR * result );
  STDMETHOD(Convert               ) ( THIS_ BSTR, BSTR, long, VARIANT_BOOL, long *   );
  STDMETHOD(VisualEditConvertParam) ( THIS_ OLE_HANDLE, long, VARIANT_BOOL *         );
  
  // Описание дуальных методов для интерфейса ISpecificationDocument
  END_DUAL_INTERFACE_PART(KompasConverter)
};



#endif // __KOMPASCONVERTER_H
