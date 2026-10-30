////////////////////////////////////////////////////////////////////////////////
//
// LibConverterParam.h - Пример интерфейса для параметров конвертера
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _LibConverterPARAM_H
#define _LibConverterPARAM_H

#include "KompasConverter.h"
#include "LibConverter.h"
//////////////////////////////////////////////////////////////////////////
//
// LibConverterParam - Пример интерфейса для параметров конвертера
//
//////////////////////////////////////////////////////////////////////////
class LibConverterParam : public CCmdTarget
{
  DECLARE_DYNAMIC(LibConverterParam)

public:
                     LibConverterParam();
            virtual ~LibConverterParam();

protected :
            virtual BOOL                 GetDispatchIID        ( IID * pIID );
            virtual void                 OnFinalRelease        ();
    afx_msg virtual BOOL                 GetSaveLineStyle      ();
    afx_msg virtual void                 SetSaveLineStyle      ( BOOL val );

  DECLARE_OLETYPELIB   ( LibConverterParam )
	DECLARE_MESSAGE_MAP  ()
	DECLARE_DISPATCH_MAP ()
	DECLARE_INTERFACE_MAP()
  BEGIN_DUAL_INTERFACE_PART( LibConverterParam, ILibConverterParam )
  STDMETHOD(get_SaveLineStyle) ( THIS_ VARIANT_BOOL * pVal );
  STDMETHOD(put_SaveLineStyle) ( THIS_ VARIANT_BOOL val );
  

  // Описание дуальных методов для интерфейса ISpecificationDocument
  END_DUAL_INTERFACE_PART(LibConverterParam)
};

#endif 
