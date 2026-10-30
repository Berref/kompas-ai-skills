 // Obj3DEvent.cpp : implementation file
//

#include "stdafx.h"
#include "eventCom.h"

#ifndef _OBJ3DEVENT_H
#include "Obj3DEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE* pModuleState;

extern BaseEvent* NewDocumentEvent( reference doc );

//-------------------------------------------------------------------------------
// Найти контейнер для 3D объекта
// ---
LPUNKNOWN GetContainer( reference doc, int objType, LPUNKNOWN iObj ) {
  IUnknownPtr container( NULL );
  if ( iObj ) {
		switch ( objType ) {

		  case 0: { // тип не известен
        IPartPtr iPart( iObj );
        if ( iPart ) {
          BOOL stadart = iPart->GetStandardComponent();
          if ( stadart )
            MessageT( _T("TRUE") );
          else
            MessageT( _T("FALSE") );
          container = iPart->GetPart( pTop_Part );
        }
        else {
          IEntityPtr iEntity( iObj );
	  			if ( iEntity )
            container = iEntity->GetParent();
        }
        break;
		  }

		  case o3d_part: {
        IPartPtr iPart( iObj );
        if ( iPart ) {
          container = iPart->GetPart( pTop_Part );
          BOOL stadart = iPart->GetStandardComponent();
          if ( stadart )
            MessageT( _T("TRUE") );
          else
            MessageT( _T("FALSE") );
        } 
			  break;
			}

			case o3d_feature: {
        IFeaturePtr iFeature( iObj );
				if ( iFeature ) { 
          IUnknownPtr obj( iFeature->GetObject(), false/*AddRef*/ );
					if ( obj ) 
						container = GetContainer( 0, 0, obj );
				}
				break;
			} 

      default: {
        IEntityPtr iEntity( iObj );
				if ( iEntity )
          container = iEntity->GetParent();
			}
		}
  }
  if ( container == NULL ) {
		if ( doc ) {
			IDocument3DPtr doc3D( ksGet3dDocumentFromReference(doc), false/*AddRef*/ );
		  if ( doc3D ) 
			  container = doc3D->GetPart( pTop_Part );
		}
  }
	return container;	 
}

//-------------------------------------------------------------------------------
// Создать обработчик событий 3D документа
// ---
BaseEvent* NewObj3DEvent( reference doc, int objType, LPUNKNOWN iObj ) {
  Obj3DEvent* res = NULL;
	if ( doc ) {
		int typeObj = iObj ? 0 : objType; 
		if ( !BaseEvent::FindEvents( ntObject3DNotify, doc, typeObj, iObj ) ) {
			IUnknownPtr container = GetContainer( doc, objType, iObj );
			if ( container ) {
				NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
  			res = new Obj3DEvent( container, typeObj, iObj, doc );
	  		if ( !res->Advise() ) { 
		  		delete res;
			  	res = NULL;
				}
			}
		}
	}
	return res;	
}



////////////////////////////////////////////////////////////////////////////////
//
// Obj3DEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
Obj3DEvent::Obj3DEvent( LPUNKNOWN iContainer, long objType, LPUNKNOWN iObj, reference doc ):
    BaseEvent( ntObject3DNotify, iContainer, objType, iObj, doc )
{
}


//-------------------------------------------------------------------------------
//
// ---
Obj3DEvent::~Obj3DEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN Obj3DEvent::GetUnknown(){
  m_xObject3DNotify.AddRef();
  return &m_xObject3DNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) Obj3DEvent::XObject3DNotify::Release()
{
	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) Obj3DEvent::XObject3DNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
	return (ULONG)pThis->InternalAddRef();
}


//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP Obj3DEvent::XObject3DNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_IObject3DNotify) )
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
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
	return  notifyType >= o3BeginDelete && notifyType <= o3LoadStateChange;
}

//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void Obj3DEvent::ShowEventName( LPCTSTR eventName, LPUNKNOWN obj, bool showResult ) {
	if ( theApp.m_mes_OBJ_3DDOC ) {
		if ( obj ) { 
   		IDocument3DPtr doc3D( ksGet3dDocumentFromReference(refDoc), false/*AddRef*/ );
      if ( doc3D ) {
        IChooseMngPtr mng( doc3D->GetChooseMng(), false/*AddRef*/ );
				if ( mng ) {
					mng->Choose( obj );
    		  ::_ShowEventName(eventName);
					mng->UnChoose( obj );

        }
      }
		}
		else
		  ::_ShowEventName(eventName);
		IPartPtr iPart ( IUnknownPtr(GetContainer( refDoc, 0, obj ), false/*AddRef*/) );
		if ( iPart ) {
			CString str;
			TCHAR buf[50];
			IObject3DNotifyResultPtr iObj3DRes ( iPart->GetObject3DNotifyResult(), false/*AddRef*/ );
			if ( iObj3DRes ) {
				int type = iObj3DRes->GetNotifyType();
        if ( type ) {
				  _stprintf_s( buf, _T("NotifyType=%i"), type );
				  str += buf;
					IFeatureCollectionPtr fCol( IUnknownPtr(iObj3DRes->GetFeatureCollection(), false/*AddRef*/) );
				  if ( fCol ) {
					  _stprintf_s( buf, _T("\nFeatureCollection::Count=%i"), fCol->GetCount() );
					  str += buf;
					}
				  IPlacementPtr placement( IUnknownPtr(iObj3DRes->GetPlacement( ), false/*AddRef*/) );
					if ( placement ) {
            double x, y, z;
            placement->GetOrigin( &x, &y, &z );
					  _stprintf_s( buf, _T("\nx=%g, y=%g, z=%g"), x, y, z );
					  str += buf;

					}
				}
			}
		}
	}
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString Obj3DEvent::EventCaption() {
	CString res = _T("Obj3DEvent");
	res += GetDocumentParam( refDoc );
	return res;
}



/////////////////////////////////////////////////////////////////////////////
// Obj3DEvent message handlers
//-------------------------------------------------------------------------------
// Начало удаления объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::BeginDelete( LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::BeginDelete"), obj, false );
  return !theApp.m_mes_OBJ_3DDOC || ::YesNoT( _T("EventCom::Obj3DEvent::BeginDelete : Удалять?") ) == 1;
}


//-------------------------------------------------------------------------------
// Oбъекты удалены
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::Delete( LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  IDocument3DPtr pDocument( ksGetActive3dDocument(), false/*AddRef*/ );
 
  if ( pDocument )
  {
    IFeatureCollectionPtr pFeatures ( obj );
    reference nDocument = ksGetReferenceFrom3dDocument(pDocument); //для удаления ссылки
 
    for (int i = 0; i < pFeatures->GetCount(); i++ )
    {
      IFeaturePtr pFeature( pFeatures->GetByIndex(i), false/*Addref*/ );
 
      if ( (pFeature != NULL) && (pFeature->GetType() == o3d_part) )
      {
        IPartPtr pPart ( IUnknownPtr(pFeature->GetObject(), false) );
        if ( pPart )
          _bstr_t pCaption ( pPart->GetFileName() );            //вот в этом месте выдается сообщение о неправильном ESP
      }
    }
  }
 
	if ( pThis->m_params.iObj && obj ) {
    pThis->Disconnect();
  }
  return TRUE;
}


//-------------------------------------------------------------------------------
// Oбъект исключен/включен в расчет
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::Excluded( LPUNKNOWN obj, VARIANT_BOOL excluded ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::Excluded"), obj, false );
  if ( excluded )
	  ::MessageT(_T("Объект исключен из расчета"));
	else
	  ::MessageT(_T("Объект включен в расчет"));
  return TRUE;
}


//-------------------------------------------------------------------------------
// Oбъект скрыт/показан
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::Hidden( LPUNKNOWN obj, VARIANT_BOOL _hidden ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::Hidden"), obj, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало изменения свойств объета
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::BeginPropertyChanged( LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::BeginPropertyChanged"), obj, false );
  return !theApp.m_mes_OBJ_3DDOC || ::YesNoT( _T("Изменить значение?") ) == 1;
}


//-------------------------------------------------------------------------------
// Изменены свойства объета
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::PropertyChanged( LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::PropertyChanged"), obj, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало изменения положения объета
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::BeginPlacementChanged( LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::BeginPlacementChanged"), obj, false );
  return !theApp.m_mes_OBJ_3DDOC || ::YesNoT( _T("Изменить положение объекта?") ) == 1;
}


//-------------------------------------------------------------------------------
// Изменено положения объета
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::PlacementChanged( LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::PlacementChanged"), obj, true );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало редактирования\создания объекта.false - запрещает процесс.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::BeginProcess( long pType, LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::BeginProcess"), obj, false );
  return !theApp.m_mes_OBJ_3DDOC || ::YesNoT( _T("Запустить процесс?") ) == 1;;
}


//-------------------------------------------------------------------------------
// Конец редактирования\создания объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::EndProcess( long pType ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::EndProcess"), NULL, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Создание объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::CreateObject( LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::CreateObject"), obj, false );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Редактирование объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::UpdateObject( LPUNKNOWN obj ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::UpdateObject"), obj, false );
  return TRUE;
}

//-------------------------------------------------------------------------------
// Начало изменения типа загрузки
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::BeginLoadStateChange( IUnknown *obj, long loadState ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::BeginLoadStateChange"), obj, false );
  return TRUE;
}

//-------------------------------------------------------------------------------
// Завершение изменения типа загрузки
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj3DEvent::XObject3DNotify::LoadStateChange( IUnknown *obj, long loadState ) {
 	METHOD_PROLOGUE_EX_(Obj3DEvent, Object3DNotify)
  pThis->ShowEventName( _T("Obj3DEvent::LoadStateChange"), obj, false );
  return TRUE;
}



