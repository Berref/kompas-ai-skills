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

//---------------------------------------------------------------------------
// DocumentEvent - обработчик событий от документа (TEventsDispatcher)
// ---
class DocumentEvent : public TBaseEvent<IDocumentFileNotify, & IID_IDocumentFileNotify>
{

public:
  DocumentEvent( reference refDoc );

protected:

  // Обработчики событий
  //Обрабатывается ли библиотекой событие с номером notifyType
  virtual VARIANT_BOOL STDMETHODCALLTYPE IsNotifyProcess( int notifyType );

  // Начало закрытия документа
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginCloseDocument( void);
  // Документ закрыт
  virtual VARIANT_BOOL STDMETHODCALLTYPE CloseDocument( void );
  // Начало сохранения документа
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginSaveDocument( LPCSTR docName );
  // Документ сохранен
  virtual VARIANT_BOOL STDMETHODCALLTYPE SaveDocument( void );
  // Документ активизирован
  virtual VARIANT_BOOL STDMETHODCALLTYPE Activate( void );
  // Документ деактивизирован
  virtual VARIANT_BOOL STDMETHODCALLTYPE Deactivate( void );
  //kdBeginSaveAsDocument  - Запрос имени документа для сохранения.
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginSaveAsDocument();
  //kdDocumentFrameOpen    - Окно документа открылось.
  virtual VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameOpen( LPUNKNOWN v );
  //kdProcessActivate      - Активизация процесса
  virtual VARIANT_BOOL STDMETHODCALLTYPE ProcessActivate( long Id);
  //kdProcessDeactivate    - Деактивизация процесса
  virtual VARIANT_BOOL STDMETHODCALLTYPE ProcessDeactivate( long Id);

  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginProcess(long Id);

  virtual VARIANT_BOOL STDMETHODCALLTYPE EndProcess( long Id, VARIANT_BOOL Success);

  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginAutoSaveDocument( LPCSTR docName);

  virtual VARIANT_BOOL STDMETHODCALLTYPE AutoSaveDocument( void );
          virtual /* [helpstring] */ VARIANT_BOOL STDMETHODCALLTYPE ActivateToolbarSet(
            LPCSTR oldToolbarSetId,
            LPCSTR newToolbarSetId);
};

BaseEvent*  NewDocumentEvent( reference doc );

#endif
