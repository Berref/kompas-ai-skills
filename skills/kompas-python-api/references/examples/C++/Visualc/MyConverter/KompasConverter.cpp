////////////////////////////////////////////////////////////////////////////////
//
// KompasConverter.cpp - реализация стандартного интерфейса КОМПАС для библиотек импорта / экспорта
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "MyConverter.h"
#include "KompasConverter.h"
#include "LibConverter.h"
#include "LibConverterParam.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const int LibVerMajor = 1;
const int LibVerMinor = 0;

////////////////////////////////////////////////////////////////////////////////
//
// KompasConverter
//
////////////////////////////////////////////////////////////////////////////////

IMPLEMENT_OLETYPELIB   ( KompasConverter, LIBID_CONVERTLIBINTERFACES, LibVerMajor, LibVerMinor )
IMPLEMENT_DYNAMIC      ( KompasConverter, CCmdTarget )
DELEGATE_DUAL_INTERFACE( KompasConverter, KompasConverter ) // Реализация стандартных методов IDispatch 


//-------------------------------------------------------------------------------
// Конструктор
// ---
KompasConverter::KompasConverter()
{
  EnableAutomation();
  EnableTypeLib   ();
}


//-------------------------------------------------------------------------------
// Деструктор
// ---
KompasConverter::~KompasConverter()
{
}


//-------------------------------------------------------------------------------
// 
// ---
BOOL KompasConverter::GetDispatchIID( IID * pIID )
{
   *pIID = IID_IKompasConverter;
   return TRUE;
}


//-------------------------------------------------------------------------------
// 
// ---
void KompasConverter::OnFinalRelease()
{
  TRACE0( "KompasConverter::OnFinalRelease()" );
  ::GetLibConverter().InterfaceNull();
  CCmdTarget::OnFinalRelease();
}


//-------------------------------------------------------------------------------
// Карта сообщений
// --- 
BEGIN_MESSAGE_MAP( KompasConverter, CCmdTarget )
END_MESSAGE_MAP()


//-------------------------------------------------------------------------------
// Карта дисп. интерфейса
// --- 
BEGIN_DISPATCH_MAP( KompasConverter, CCmdTarget )
  DISP_FUNCTION_ID   (KompasConverter, "ConverterParameters",    1, ConverterParameters,   VT_UNKNOWN, VTS_I4 )
  DISP_PROPERTY_EX_ID(KompasConverter, "CanUnLoadLibrary",       2, GetCanUnLoadLibrary, SetNotSupported, VT_BOOL)
  DISP_FUNCTION_ID   (KompasConverter, "GetFilter",              3, GetFilter,             VT_BSTR,    VTS_I4 VTS_BOOL VTS_PI4 )
  DISP_FUNCTION_ID   (KompasConverter, "Convert",                4, Convert,               VT_I4,      VTS_BSTR VTS_BSTR VTS_I4 VTS_BOOL )
  DISP_FUNCTION_ID   (KompasConverter, "VisualEditConvertParam", 5, VisualEditConvertParam,VT_BOOL,    VTS_HANDLE VTS_I4)
END_DISPATCH_MAP()

BEGIN_INTERFACE_MAP( KompasConverter, CCmdTarget )
	INTERFACE_PART( KompasConverter, IID_IKompasConverter, KompasConverter )
END_INTERFACE_MAP()


//-------------------------------------------------------------------------------
// Получить указатель на интерфейс параметров экспорта
// ---
IUnknown *  KompasConverter::ConverterParameters( long command )
{
  IUnknown * pUnk = NULL; 
  LibConverterParam * myconv = ::GetLibConverter().GetConvertParam( command );
  if ( myconv ) 
  {
    pUnk = myconv->GetInterface( &IID_IUnknown );
  }

  return pUnk;
}


//-------------------------------------------------------------------------------
// проверить можно ли выгрузить библиотеку из памяти
// ---
BOOL KompasConverter::GetCanUnLoadLibrary()
{
  return ::GetLibConverter().GetCanUnLoadLibrary();
}


//-------------------------------------------------------------------------------
// Конвертировать
// ---
long KompasConverter::Convert( LPCTSTR inputFile, LPCTSTR outfile,  long command, BOOL showParam )    
                      
{
  return ::GetLibConverter().Convert( inputFile, outfile, command, showParam );
}


//-------------------------------------------------------------------------------
// Получить фильтр и номер команды по типу документа
// ---
BSTR KompasConverter::GetFilter( long docType, BOOL saveAs, long * command )
{
  return ::GetLibConverter().GetFilter( docType, saveAs, command );
}


//-------------------------------------------------------------------------------
// Запустить визуальное редактирование параметров
// ---
BOOL KompasConverter::VisualEditConvertParam( OLE_HANDLE parentHwnd, long command )    
{
  return ::GetLibConverter().VisualEditConvertParam( parentHwnd, command );
}


//-------------------------------------------------------------------------------
// Конвертировать
// ---
STDMETHODIMP KompasConverter::XKompasConverter::Convert( BSTR source, BSTR destination, 
                                                         long command,
                                                         VARIANT_BOOL showParam,
                                                         long * PVal )
METHOD_PROLOGUE_TRY_DUAL( KompasConverter )
  if ( PVal )
  {
    CString strSource( source );
    CString strDestination( destination );
    *PVal = pThis->Convert( strSource, strDestination, command, showParam );
    return S_OK;
  }
  else
    return E_INVALIDARG;
END_DUAL_METHOD

//-------------------------------------------------------------------------------
// Получить фильтр и номер команды по типу документа
// ---
STDMETHODIMP KompasConverter::XKompasConverter::GetFilter( long         docType, 
                                                           VARIANT_BOOL saveAs, 
                                                           long *       command, 
                                                           BSTR *       result )
METHOD_PROLOGUE_TRY_DUAL( KompasConverter )
  if ( result ) {     
    *result = pThis->GetFilter( docType, saveAs, command );
    return S_OK;         
  }                      
  else                   
    return E_INVALIDARG;                      
END_DUAL_METHOD


//-------------------------------------------------------------------------------
// Получить Указатель на интерфейс параметров конвертора
// ---
STDMETHODIMP KompasConverter::XKompasConverter::ConverterParameters( long command, 
                                                                     IUnknown ** result)
METHOD_PROLOGUE_TRY_DUAL( KompasConverter )
  if ( result ) {     
    *result = pThis->ConverterParameters( command );
    return S_OK;         
  }                      
  else                   
    return E_INVALIDARG;                      
END_DUAL_METHOD


//-------------------------------------------------------------------------------
// Запустить визуальное редактирование параметров
// ---
STDMETHODIMP KompasConverter::XKompasConverter::VisualEditConvertParam( OLE_HANDLE parentHwnd,
                                                                        long command,
                                                                        VARIANT_BOOL * PVal )
METHOD_PROLOGUE_TRY_DUAL( KompasConverter )
  if ( PVal ) {
    *PVal = pThis->VisualEditConvertParam( parentHwnd, command );
    return S_OK;
  }
  else
    return E_INVALIDARG;
END_DUAL_METHOD




//-------------------------------------------------------------------------------
// проверить можно ли выгрузить библиотеку из памяти
// ---
BEGIN_DUAL_METHOD( KompasConverter, get_CanUnloadLibrary, VARIANT_BOOL * pVal )
  CALL_GET_METHOD( pVal, GetCanUnLoadLibrary )                
END_DUAL_METHOD
