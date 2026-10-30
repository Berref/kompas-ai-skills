// mfcdual.h: Helpful macros for adding dual interface support to
//            MFC applications

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.





/////////////////////////////////////////////////////////////////////
// BEGIN_DUAL_INTERFACE_PART is just like BEGIN_INTERFACE_PART,
// except that it also adds the IDispatch methods to your class
// declaration.
#define BEGIN_DUAL_INTERFACE_PART(localClass, baseClass) \
	BEGIN_INTERFACE_PART(localClass, baseClass) \
	   STDMETHOD(GetTypeInfoCount)(UINT FAR* pctinfo); \
	   STDMETHOD(GetTypeInfo)(UINT itinfo, LCID lcid, ITypeInfo FAR* FAR* pptinfo); \
	   STDMETHOD(GetIDsOfNames)(REFIID riid, OLECHAR FAR* FAR* rgszNames, UINT cNames, LCID lcid, DISPID FAR* rgdispid); \
	   STDMETHOD(Invoke)(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS FAR* pdispparams, VARIANT FAR* pvarResult, EXCEPINFO FAR* pexcepinfo, UINT FAR* puArgErr); \

/////////////////////////////////////////////////////////////////////
// END_DUAL_INTERFACE_PART is just like END_INTERFACE_PART. It
// is only added for symmetry...
#define END_DUAL_INTERFACE_PART(localClass) \
	END_INTERFACE_PART(localClass) \



/////////////////////////////////////////////////////////////////////
// DELEGATE_DUAL_INTERFACE expands to define the standard IDispatch
// methods for a dual interface, delegating back to the default
// MFC implementation
#define DELEGATE_DUAL_INTERFACE(objectClass, dualClass) \
	STDMETHODIMP_(ULONG) objectClass::X##dualClass::AddRef() \
	{ \
		METHOD_PROLOGUE(objectClass, dualClass) \
		return pThis->ExternalAddRef(); \
	} \
	STDMETHODIMP_(ULONG) objectClass::X##dualClass::Release() \
	{ \
		METHOD_PROLOGUE(objectClass, dualClass) \
		return pThis->ExternalRelease(); \
	} \
	STDMETHODIMP objectClass::X##dualClass::QueryInterface( \
		REFIID iid, LPVOID* ppvObj) \
	{ \
		METHOD_PROLOGUE(objectClass, dualClass) \
		return pThis->ExternalQueryInterface(&iid, ppvObj); \
	} \
	STDMETHODIMP objectClass::X##dualClass::GetTypeInfoCount( \
		UINT FAR* pctinfo) \
	{ \
		METHOD_PROLOGUE(objectClass, dualClass) \
		LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE); \
		ASSERT(lpDispatch != NULL); \
		return lpDispatch->GetTypeInfoCount(pctinfo); \
	} \
	STDMETHODIMP objectClass::X##dualClass::GetTypeInfo( \
		UINT itinfo, LCID lcid, ITypeInfo FAR* FAR* pptinfo) \
	{ \
		METHOD_PROLOGUE(objectClass, dualClass) \
		LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE); \
		ASSERT(lpDispatch != NULL); \
		return lpDispatch->GetTypeInfo(itinfo, lcid, pptinfo); \
	} \
	STDMETHODIMP objectClass::X##dualClass::GetIDsOfNames( \
		REFIID riid, OLECHAR FAR* FAR* rgszNames, UINT cNames, \
		LCID lcid, DISPID FAR* rgdispid) \
	{ \
		METHOD_PROLOGUE(objectClass, dualClass) \
		LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE); \
		ASSERT(lpDispatch != NULL); \
		return lpDispatch->GetIDsOfNames(riid, rgszNames, cNames, \
										 lcid, rgdispid); \
	} \
	STDMETHODIMP objectClass::X##dualClass::Invoke( \
		DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags, \
		DISPPARAMS FAR* pdispparams, VARIANT FAR* pvarResult, \
		EXCEPINFO FAR* pexcepinfo, UINT FAR* puArgErr) \
	{ \
		METHOD_PROLOGUE(objectClass, dualClass) \
		LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE); \
		ASSERT(lpDispatch != NULL); \
		return lpDispatch->Invoke(dispidMember, riid, lcid, \
								  wFlags, pdispparams, pvarResult, \
								  pexcepinfo, puArgErr); \
	} \



/////////////////////////////////////////////////////////////////////
// TRY_DUAL and CATCH_ALL_DUAL are used to provide exception handling
// for your dual interface methods. CATCH_ALL_DUAL takes care of
// returning the appropriate error code.

#define TRY_DUAL(iidSource) \
	HRESULT _hr = S_OK; \
	REFIID  _riidSource = iidSource; \
	TRY \

#define CATCH_ALL_DUAL \
	CATCH(COleException, e) \
	{ \
		_hr = e->m_sc; \
	} \
	AND_CATCH_ALL(e) \
	{ \
		AFX_MANAGE_STATE(pThis->m_pModuleState); \
		_hr = DualHandleException(_riidSource, e); \
	} \
	END_CATCH_ALL \
	return _hr; \

/////////////////////////////////////////////////////////////////////
// DualHandleException is a helper function used to set the system's
// error object, so that container applications that call through
// VTBLs can retrieve rich error information
HRESULT DualHandleException(REFIID riidSource, const CException* pAnyException);

/////////////////////////////////////////////////////////////////////
// DECLARE_DUAL_ERRORINFO expands to declare the ISupportErrorInfo
// support class. It works together with DUAL_ERRORINFO_PART and
// IMPLEMENT_DUAL_ERRORINFO defined below.
#define DECLARE_DUAL_ERRORINFO() \
	BEGIN_INTERFACE_PART(SupportErrorInfo, ISupportErrorInfo) \
		STDMETHOD(InterfaceSupportsErrorInfo)(THIS_ REFIID riid); \
	END_INTERFACE_PART(SupportErrorInfo) \

/////////////////////////////////////////////////////////////////////
// DUAL_ERRORINFO_PART adds the appropriate entry to the interface map
// for ISupportErrorInfo, if you used DECLARE_DUAL_ERRORINFO.
#define DUAL_ERRORINFO_PART(objectClass) \
	INTERFACE_PART(objectClass, IID_ISupportErrorInfo, SupportErrorInfo) \

/////////////////////////////////////////////////////////////////////
// IMPLEMENT_DUAL_ERRORINFO expands to an implementation of
// ISupportErrorInfo which matches the declaration in
// DECLARE_DUAL_ERRORINFO.
#define IMPLEMENT_DUAL_ERRORINFO(objectClass, riidSource) \
	STDMETHODIMP_(ULONG) objectClass::XSupportErrorInfo::AddRef() \
	{ \
		METHOD_PROLOGUE(objectClass, SupportErrorInfo) \
		return pThis->ExternalAddRef(); \
	} \
	STDMETHODIMP_(ULONG) objectClass::XSupportErrorInfo::Release() \
	{ \
		METHOD_PROLOGUE(objectClass, SupportErrorInfo) \
		return pThis->ExternalRelease(); \
	} \
	STDMETHODIMP objectClass::XSupportErrorInfo::QueryInterface( \
		REFIID iid, LPVOID* ppvObj) \
	{ \
		METHOD_PROLOGUE(objectClass, SupportErrorInfo) \
		return pThis->ExternalQueryInterface(&iid, ppvObj); \
	} \
	STDMETHODIMP objectClass::XSupportErrorInfo::InterfaceSupportsErrorInfo( \
		REFIID iid) \
	{ \
		METHOD_PROLOGUE(objectClass, SupportErrorInfo) \
		return (iid == riidSource) ? S_OK : S_FALSE; \
	}



//-------------------------------------------------------------------------------
// Вызывает метод дуального интерфейса и возвращает полученный дуальный интерфейс
// ---
#define RETURN_DUAL_INTERFACE(arg, dualIID, func)                   \
  if ( arg ) {                                                      \
		LPDISPATCH lpDisp = pThis->func();                              \
    if ( lpDisp ) {                                                 \
		  HRESULT hRes = lpDisp->QueryInterface(dualIID, (LPVOID*)arg); \
		  lpDisp->Release();                                            \
      return hRes;                                                  \
    }                                                               \
    else {                                                          \
      *arg = NULL;                                                  \
      return S_OK;                                                  \
    }                                                               \
  }                                                                 \
  else                                                              \
    return E_INVALIDARG;


//-------------------------------------------------------------------------------
// Вызов метода возврашающего какое-то значение (свойство get) в дуальном интерфейсе
// ---
#define CALL_GET_METHOD( arg, func ) \
  if ( arg ) {                       \
    *arg = pThis->func();            \
    return S_OK;                     \
  }                                  \
  else                               \
    return E_INVALIDARG;                      


//-------------------------------------------------------------------------------
// Вызов метода изменяющего какое-то значение (свойство put) в дуальном интерфейсе
// ---
#define CALL_SET_METHOD( arg, func ) \
    pThis->Set##func( arg );         \
    return S_OK;


//-------------------------------------------------------------------------------
// Вызов метода GetNewEnum возврашающего LPUNKNOWN в дуальном интерфейсе
// ---
#define CALL_GET_NEW_ENUM(arg)                                           \
  if ( arg )                                                             \
  {                                                                      \
		*arg = pThis->GetNewEnum();                                          \
    return S_OK;                                                         \
  }                                                                      \
  else                                                                   \
    return E_INVALIDARG;


//-------------------------------------------------------------------------------
// Вызывает метод GetItem в дуальном интерфейсе и возвращает полученный дуальный интерфейс
// ---
#define CALL_GET_ITEM(arg, dualIID, inputIndex,func)                     \
  if ( arg )                                                        \
  {                                                                 \
		LPDISPATCH lpDisp = pThis->##func ( inputIndex );               \
    if ( lpDisp )                                                   \
    {                                                               \
		  HRESULT hRes = lpDisp->QueryInterface(dualIID, (LPVOID*)arg); \
		  lpDisp->Release();                                            \
      return hRes;                                                  \
    }                                                               \
    else                                                            \
    {                                                               \
      *arg = NULL;                                                  \
      return S_OK;                                                  \
    }                                                               \
  }                                                                 \
  else                                                              \
    return E_INVALIDARG;


//-------------------------------------------------------------------------------
// Вызов метода изменяющего какое-то значение (свойство put) в дуальном интерфейсе
// В качестве параметра передается строка BSTR
// ---
#define CALL_SET_METHOD_WITH_BSTR( arg, func ) \
  if ( arg )                                   \
  {                                            \
    CString str( arg );                        \
    pThis->Set##func( str );                   \
    return S_OK;                               \
  }                                            \
  else                                         \
    return E_INVALIDARG;


//-------------------------------------------------------------------------------
//
// ---
#define METHOD_PROLOGUE_TRY_DUAL( className )           \
  {                                                     \
 	  METHOD_PROLOGUE( className, className )             \
 	  TRY_DUAL( IID_I##className )                        \
 	  {



//-------------------------------------------------------------------------------
// Начало метода дуального интерфейса
// ---
#define BEGIN_DUAL_METHOD_0( className, methodName )         \
  STDMETHODIMP className::X##className::methodName()  \
  METHOD_PROLOGUE_TRY_DUAL( className )

#define BEGIN_DUAL_METHOD( className, methodName, parameter )           \
  STDMETHODIMP className::X##className::methodName( parameter )  \
  METHOD_PROLOGUE_TRY_DUAL( className )


#define BEGIN_DUAL_METHOD_2( className, methodName, parameter1, parameter2 )         \
  STDMETHODIMP className::X##className::methodName( parameter1, parameter2 )  \
  METHOD_PROLOGUE_TRY_DUAL( className )


//-------------------------------------------------------------------------------
// Конец метода дуального интерфейса
// ---
#define END_DUAL_METHOD      \
 	  }                        \
 	  CATCH_ALL_DUAL           \
  }


