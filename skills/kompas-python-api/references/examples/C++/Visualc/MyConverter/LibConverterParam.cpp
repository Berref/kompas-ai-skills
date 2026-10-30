////////////////////////////////////////////////////////////////////////////////
//
// LibConverterParam.cpp - Пример параметров конвертера на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "LibConverterParam.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const int LibVerMajor = 1;
const int LibVerMinor = 0;

////////////////////////////////////////////////////////////////////////////////
//
// LibConverterParam
//
////////////////////////////////////////////////////////////////////////////////

IMPLEMENT_OLETYPELIB   ( LibConverterParam, LIBID_CONVERTLIBINTERFACES, LibVerMajor, LibVerMinor )
IMPLEMENT_DYNAMIC      ( LibConverterParam, CCmdTarget )
DELEGATE_DUAL_INTERFACE( LibConverterParam, LibConverterParam ) // Реализация стандартных методов IDispatch 


//-------------------------------------------------------------------------------
// Конструктор
// ---
LibConverterParam::LibConverterParam()
{
  EnableAutomation();
  EnableTypeLib   ();
}


//-------------------------------------------------------------------------------
// Деструктор
// ---
LibConverterParam::~LibConverterParam()
{
}


//-------------------------------------------------------------------------------
// Возвращает GUID интерфейса параметров
// ---
BOOL LibConverterParam::GetDispatchIID( IID * pIID )
{
   *pIID = IID_ILibConverterParam;
   return TRUE;
}


//-------------------------------------------------------------------------------
//
// ---
void LibConverterParam::OnFinalRelease()
{
  TRACE0( "LibConverterParam::OnFinalRelease()" );
  ::GetLibConverter().InterfaceParamNull();
  CCmdTarget::OnFinalRelease();
}


//-------------------------------------------------------------------------------
// Карта сообщений
// --- 
BEGIN_MESSAGE_MAP( LibConverterParam, CCmdTarget )
END_MESSAGE_MAP()


//-------------------------------------------------------------------------------
// Карта дисп. интерфейса
// --- 
BEGIN_DISPATCH_MAP( LibConverterParam, CCmdTarget )
  DISP_PROPERTY_EX_ID( LibConverterParam, "SaveLineStyle",    1, GetSaveLineStyle, SetSaveLineStyle, VT_BOOL )
END_DISPATCH_MAP()

//-------------------------------------------------------------------------------
// Карта дисп. интерфейса
// --- 
BEGIN_INTERFACE_MAP( LibConverterParam, CCmdTarget )
	INTERFACE_PART( LibConverterParam, IID_ILibConverterParam, LibConverterParam )
END_INTERFACE_MAP()


//-------------------------------------------------------------------------------
// проверить можно ли выгрузить библиотеку из памяти
// ---
BOOL LibConverterParam::GetSaveLineStyle()
{
  return !!::GetLibConverter().GetSaveLineStyle();
}


//-------------------------------------------------------------------------------
// проверить можно ли выгрузить библиотеку из памяти
// ---
void LibConverterParam::SetSaveLineStyle( BOOL val)
{
  ::GetLibConverter().SetSaveLineStyle( !!val );
}

//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( LibConverterParam, get_SaveLineStyle, VARIANT_BOOL * pVal )
  CALL_GET_METHOD( pVal, GetSaveLineStyle )                
END_DUAL_METHOD


//-------------------------------------------------------------------------------
//
// ---
BEGIN_DUAL_METHOD( LibConverterParam, put_SaveLineStyle, VARIANT_BOOL val )
  CALL_SET_METHOD( val, SaveLineStyle )                
END_DUAL_METHOD

