////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent.h
// Object2DEvent - обрабокчик событий от приложения (COM)
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _OBJECT2DEVENT_H
#define _OBJECT2DEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif  

//---------------------------------------------------------------------------
// Object2DEvent - обработчик событий от приложения (TEventsDispatcher)
// ---
class Object2DEvent : public TBaseEvent<IObject2DNotify, & IID_IObject2DNotify>
{
  reference m_refDoc;
//  IObject2DNotifyResult * m_pObject2DNotifyResult;

public:
  Object2DEvent( reference refDoc, long objType );
  ~Object2DEvent();

protected:
  void GetResultParam( String title );
  //Обрабатывается ли библиотекой событие с номером notifyType
  virtual VARIANT_BOOL STDMETHODCALLTYPE IsNotifyProcess( int notifyType );
  // Обработчики событий
  virtual VARIANT_BOOL STDMETHODCALLTYPE ChangeActive( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginDelete( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE Delete( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginEdit( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE EditObject( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginMove( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE Move( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginRotate( long obgRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE Rotate( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginScale( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE Scale( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginTransform( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE Transform( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginCopy( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE Copy( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginSymmetry( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE Symmetry( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginProcess( long pType, long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE EndProcess( long pType );
  virtual VARIANT_BOOL STDMETHODCALLTYPE CreateObject( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE UpdateObject( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginDestroyObject( long objRef );
  virtual VARIANT_BOOL STDMETHODCALLTYPE DestroyObject( long objRef );
};
#endif

