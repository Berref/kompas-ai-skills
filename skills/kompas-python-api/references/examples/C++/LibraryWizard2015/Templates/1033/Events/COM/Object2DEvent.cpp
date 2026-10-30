////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent - обработчик событий объектов 2D документа
//
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "Object2DEvent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CBaseEvent * NewDocumentEvent( reference doc );

//-------------------------------------------------------------------------------
// Создать обработчик событий документа
// ---
CBaseEvent * NewObj2DEvent( reference doc, int objType ) 
{
	CBaseEvent * res = NULL;
	if ( doc ) 
  {
    res = CBaseEvent::FindEvents( ntObject2DNotify, doc, objType );
		if ( !res ) 
    {
			NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
			res = new Obj2DEvent( doc, objType );

      if ( !res->Advise() ) 
      { 
				delete res;
				res = NULL;
			}
		}
	}

  return res;
}


////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent - обработчик событий объектов 2D документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
Obj2DEvent::Obj2DEvent( reference p, long objType )
 : CBaseEvent( ntObject2DNotify, p, objType, p )
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
LPUNKNOWN Obj2DEvent::GetUnknown()
{
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
	return  notifyType >= koChangeActive && notifyType <= koDestroyObject;
}


//-------------------------------------------------------------------------------
//koChangeActive    // Переключение активности объекта( вид, слой)
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::ChangeActive( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koBeginDelete     // Начало удаления сдвига, false - запрещает удаление
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginDelete( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koDelete          // Удаление объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Delete( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koBeginMove       // Начало сдвига объекта, false - запрещает сдвиг
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginMove( long objRef ) 
{
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koMove            // Сдвиг объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Move( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koBeginRotate     // Начало поворота объекта, false - запрещает поворот
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginRotate( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koRotate          // Поворот объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Rotate( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koBeginScale     // Начало масштабирования объекта, false - запрещает поворот
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginScale( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koScale          // Масштабирование объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Scale( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koBeginTransform  // Начало трансформации объекта, false - запрещает трансформацию
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginTransform( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koTransform       // Трансформация объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Transform( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koBeginCopy       // Начало копирования объекта, false - запрещает копирование
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginCopy( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koCopy            // Копирование объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Copy( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koBeginSymmetry   // Начало симметрии  объекта, false - запрещает симметрию
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginSymmetry( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
//koSymmetry        // Симметрия  объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::Symmetry( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
// Начало редактирования\создания объекта, false - запрещает процесс.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginProcess( long pType, long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
// Конец редактирования\создания объекта
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::EndProcess( long pType ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
// Создание объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::CreateObject( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
// Редактирование объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::UpdateObject( long objRef ) 
{
	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
// Создание объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::BeginDestroyObject( long objRef ) 
{
  METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}


//-------------------------------------------------------------------------------
// Редактирование объекта.
// ---
STDMETHODIMP_(VARIANT_BOOL) Obj2DEvent::XObject2DNotify::DestroyObject( long objRef ) 
{
  METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
  return VARIANT_TRUE;
}

