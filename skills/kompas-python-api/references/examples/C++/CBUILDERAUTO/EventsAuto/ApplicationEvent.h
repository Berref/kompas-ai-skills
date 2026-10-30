////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent.h
// ApplicationEvent - обрабокчик событий от приложения (Auto)
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONEVENT_H
#define _APPLICATIONEVENT_H

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
// ApplicationEvent - обрабокчик событий от приложения (TEventsDispatcher)
// ---
class ApplicationEvent : public BaseEvent
{
public:
  ApplicationEvent( LPUNKNOWN pContainer ) : BaseEvent(pContainer, DIID_ksKompasObjectNotify) {}
  virtual ~ApplicationEvent(){}

protected:
  virtual HRESULT InvokeEvent(DISPID id, BOOL & resEvent, TVariant * params);

  // Обработчики событий
  // Документ создан
  BOOL CreateDocument( LPDISPATCH newDoc, long docType );
  // Начало открытия документа
  BOOL BeginOpenDocument( BSTR fileName );
  // Документ открыт
  BOOL OpenDocument( LPDISPATCH newDoc, long docType );
  // Переключение на другой активный документ
  BOOL ChangeActiveDocument( LPDISPATCH newDoc, long docType );
  // Закрытие приложения
  BOOL ApplicationDestroy();
  // Начало создания документа(до диалога выбора типа)
  BOOL BeginCreate( long docType );
  // koBeginOpenFile - Начало открытия документа(до диалога выбора имени)
  BOOL BeginOpenFile();
  // koBeginCloseAllDocument - Закрытие всех файлов
  BOOL BeginCloseAllDocument();

};
#endif

