////////////////////////////////////////////////////////////////////////////////
//
// Пример создания ActiveX Control-а
// Параметры штриховки
// <VCHatch.h>
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "VCHatch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CVCHatchApp NEAR theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x2afd2eaf, 0xa5de, 0x4a3d, { 0x95, 0xba, 0xd2, 0xc1, 0xe4, 0x3c, 0x10, 0x88 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


////////////////////////////////////////////////////////////////////////////
// CVCHatchApp::InitInstance - DLL initialization
BOOL CVCHatchApp::InitInstance()
{
  AfxEnableControlContainer();

	BOOL bInit = COleControlModule::InitInstance();
	if (bInit)
	{
    // Подменяем имя приложения, чтобы в месседжах о ошибке выводилась нормальная строка 
    free((void*)m_pszAppName);
    m_pszAppName =_tcsdup(_T("Ошибка")); 
	}
	return bInit;
}

////////////////////////////////////////////////////////////////////////////
// CVCHatchApp::ExitInstance - DLL termination
int CVCHatchApp::ExitInstance()
{
	// TODO: Add your own module termination code here.
	return COleControlModule::ExitInstance();
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
