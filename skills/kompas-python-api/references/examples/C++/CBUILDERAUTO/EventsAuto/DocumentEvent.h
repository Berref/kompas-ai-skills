////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent.h
// DocumentEvent - обработчик событий от документа (Auto)
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _DOCUMENTEVENT_H
#define _DOCUMENTEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#ifdef __LIGHT_VERSION__
  #ifndef __KL_TLB_H
  #include <kl_tlb.h>
  #endif
#else
  #ifndef __KS_TLB_H
  #include <ks_tlb.h>
  #endif
#endif


//---------------------------------------------------------------------------
// DocumentEvent - обработчик событий от документа (TEventsDispatcher)
// ---
class DocumentEvent : public BaseEvent
{
public:
  DocumentEvent( LPUNKNOWN pContainer ): BaseEvent(pContainer, DIID_ksDocumentFileNotify) {}
  ~DocumentEvent(){}

protected:
  virtual HRESULT InvokeEvent(DISPID id, BOOL & resEvent, TVariant * params);

  // Обработчики событий
  // Начало закрытия документа.
  BOOL BeginCloseDocument();
  // Документ закрыт.
  BOOL CloseDocument();
  // Начало сохранения документа.
  BOOL BeginSaveDocument( BSTR fileName );
  // Документ сохранен.
  BOOL SaveDocument();
  // Документ активизирован.
  BOOL Activate();
  // Документ деактивизирован.
  BOOL Deactivate();
};

DocumentEvent* NewDocumentEvent( IUnknown* docPtr );
#endif
