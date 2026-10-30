// Obj2DEvent.cpp : implementation file
//

#include "stdafx.h"
#include "eventCom.h"

#ifndef _OBJ2DEVENT_H
#include "Obj2DEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE* pModuleState;

extern BaseEvent* NewDocumentEvent( reference doc );

//-------------------------------------------------------------------------------
// Создать обработчик событий документа
// ---
BaseEvent* NewObj2DEvent( reference doc, int objType ) {
	Obj2DEvent* res = NULL;
	if ( doc ) {
		if ( !BaseEvent::FindEvents( ntObject2DNotify, doc, objType ) ) {
			NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
			res = new Obj2DEvent( doc, objType );
			if ( !res->Advise() ) { 
				delete res;
				res = NULL;
			}
		}
	}
	return res;
}


////////////////////////////////////////////////////////////////////////////////
//
// Obj2DEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
Obj2DEvent::Obj2DEvent( reference p, long objType ):
    BaseEvent( ntObject2DNotify, p, objType, p )
{
}


//-------------------------------------------------------------------------------
//
// ---
Obj2DEvent::~Obj2DEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN Obj2DEvent::GetUnknown(){
  m_xObject2DNotify.AddRef();
  return &m_xObject2DNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) Obj2DEvent::XObject2DNotify::Release()
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) Obj2DEvent::XObject2DNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
	return (ULONG)pThis->InternalAddRef();
}


//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP Obj2DEvent::XObject2DNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_IObject2DNotify) )
	{
		*ppvObj = this;
		AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}


//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
	return  notifyType >= koChangeActive && notifyType <= koPropertyChanged;
}


//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void Obj2DEvent::ShowEventName( LPCTSTR eventName, long objRef, bool showResult ) {
	if ( theApp.m_mes_OBJ_2DDOC ) {
		::_ShowEventName(eventName);
		if ( objRef )
  		ShowObjParam( objRef );
		if ( showResult ) {
			IObject2DNotifyResultPtr m_res( ksGetObject2DNotifyResult(refDoc) );
			long notifyType = m_res->GetNotifyType();
			if ( notifyType ) {
  			double angle = m_res->GetAngle();
				long copyObject = m_res->GetCopyObject();
				double sx, sy;
				m_res->GetScale( &sx, &sy );
				double x, y, x1, y1;
				m_res->GetSheetPoint( 0, &x, &y );
				m_res->GetSheetPoint( 1, &x1, &y1 );
				long copy = m_res->IsCopy();
				CString str;
        str.Format( _T("Object2DNotifyResult: GetNotifyType=%i,\nGetAngle=%f, GetCopyObject=%i,\nGetScale( %f, %f ),\nGetSheetPoint( 1, %f, %f ),\nGetSheetPoint( 0, %f, %f ),\nIsCopy=%i"), 
								notifyType,
								angle, 
								copyObject,               
								sx, sy,
								x1, y1,     
								x, y,
								copy );
				if ( copyObject )
          LightObj( copyObject, 1 );
				::MessageT( (LPTSTR) (LPCTSTR) str );
				if ( copyObject )
          LightObj( copyObject, 0 );
			}
		}
	}
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString Obj2DEvent::EventCaption() {
	CString res = _T("Obj2DEvent");
	res += GetDocumentParam( refDoc );
	return res;
}


/////////////////////////////////////////////////////////////////////////////
// Obj2DEvent message handlers
//-------------------------------------------------------------------------------
//koChangeActive    // Переключение активности объекта( вид, слой)
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::ChangeActive( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::ChangeActive") , objRef, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
//koBeginDelete     // Начало удаления сдвига, false - запрещает удаление
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginDelete( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::BeginDelete"), objRef, false );
  return !theApp.m_mes_OBJ_2DDOC || ::YesNoT(_T("Удалить объект?")) == 1;
}


//-------------------------------------------------------------------------------
//koDelete          // Удаление объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Delete( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::Delete"), objRef, false );
  if ( objRef && objRef == pThis->m_params.objType )
		pThis->Disconnect();
  return TRUE;
}


//-------------------------------------------------------------------------------
//koBeginMove       // Начало сдвига объекта, false - запрещает сдвиг
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginMove( long objRef ) {
  return !theApp.m_mes_OBJ_2DDOC || ::YesNoT( _T("Obj2DEvent::BeginMove : Разрешить сдвиг?") ) == 1;
}


//-------------------------------------------------------------------------------
//koMove            // Сдвиг объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Move( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::Move"), objRef, true );
  return TRUE;
}


//-------------------------------------------------------------------------------
//koBeginRotate     // Начало поворота объекта, false - запрещает поворот
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginRotate( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::BeginRotate"), objRef, false );
  return !theApp.m_mes_OBJ_2DDOC || ::YesNoT( _T("Повернуть объект?") ) == 1;
}


//-------------------------------------------------------------------------------
//koRotate          // Поворот объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Rotate( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::Rotate"), objRef, true );
  return TRUE;
}


//-------------------------------------------------------------------------------
//koBeginScale     // Начало масштабирования объекта, false - запрещает поворот
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginScale( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::BeginScale"), objRef, false );
  return !theApp.m_mes_OBJ_2DDOC || ::YesNoT( _T("Масштабировать объект?") ) == 1;
}


//-------------------------------------------------------------------------------
//koScale          // Масштабирование объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Scale( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::Scale"), objRef, true );
  return TRUE;
}


//-------------------------------------------------------------------------------
//koBeginTransform  // Начало трансформации объекта, false - запрещает трансформацию
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginTransform( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::BeginTransform"), objRef, false );
  return !theApp.m_mes_OBJ_2DDOC || ::YesNoT( _T("Разрешить трансформацию объекта") ) == 1;
}


//-------------------------------------------------------------------------------
//koTransform       // Трансформация объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Transform( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::Transform"), objRef, true );
  return TRUE;
}


long copyObj = 0;
//-------------------------------------------------------------------------------
//koBeginCopy       // Начало копирования объекта, false - запрещает копирование
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginCopy( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::BeginCopy"), objRef, false );
  copyObj = objRef;
  ::LightObj( copyObj, 1 );
  bool res = !theApp.m_mes_OBJ_2DDOC || ::YesNoT( _T("Копировать объект?")) == 1;
	if ( !res )
    ::LightObj( copyObj, 0 );
 
  return res;
}


//-------------------------------------------------------------------------------
//koCopy            // Копирование объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Copy( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  ::LightObj( objRef,  1 );
  pThis->ShowEventName(_T("Obj2DEvent::Copy"), objRef, true );
  ::LightObj( copyObj, 0 );
  ::LightObj( objRef,  0 );
  return TRUE;
}


//-------------------------------------------------------------------------------
//koBeginSymmetry   // Начало симметрии  объекта, false - запрещает симметрию
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginSymmetry( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::BeginSymmetry"), objRef, false );
  return !theApp.m_mes_OBJ_2DDOC || ::YesNoT( _T("Создать симметрию?")) == 1;
}


//-------------------------------------------------------------------------------
//koSymmetry        // Симметрия  объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Symmetry( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::Symmetry"), objRef, true );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало редактирования\создания объекта.false - запрещает процесс.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginProcess( long pType, long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::BeginProcess"), objRef, false );
  return !theApp.m_mes_OBJ_2DDOC || ::YesNoT( _T("Запустить процесс?")) == 1;
}


//-------------------------------------------------------------------------------
// Конец редактирования\создания объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::EndProcess( long pType ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::EndProcess"), 0, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Создание объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::CreateObject( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::CreateObject"), objRef, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Редактирование объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::UpdateObject( long objRef ) {
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::UpdateObject"), objRef, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Создание объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginDestroyObject( long objRef ) {
  METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::BeginDestroyObject"), objRef, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Редактирование объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::DestroyObject( long objRef ) {
  METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  pThis->ShowEventName(_T("Obj2DEvent::DestroyObject"), objRef, false );
  return TRUE;
}

//-------------------------------------------------------------------------------
// Начало изменения свойств объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginPropertyChanged( THIS_ long objRef )
{
  METHOD_PROLOGUE_EX_( Obj2DEvent, Object2DNotify )
  pThis->ShowEventName( _T( "Obj2DEvent::BeginSymmetry" ), objRef, false );
  return !theApp.m_mes_OBJ_2DDOC || ::YesNoT( _T( "Изменить объект?" ) ) == 1;
}

//-------------------------------------------------------------------------------
// Изменены свойства объета
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::PropertyChanged( THIS_ long objRef )
{
  METHOD_PROLOGUE_EX_( Obj2DEvent, Object2DNotify )
  pThis->ShowEventName( _T( "Obj2DEvent::PropertyChanged" ), objRef, false );
	return TRUE;
}


