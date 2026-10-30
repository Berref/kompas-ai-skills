////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent.h
// ApplicationEvent - обрабокчик событий от приложения (COM)
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _APPLICATIONEVENT_H
#define _APPLICATIONEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif  

//---------------------------------------------------------------------------
// ApplicationEvent - обрабокчик событий от приложения (TEventsDispatcher)
// ---
class ApplicationEvent : public TBaseEvent<IKompasObjectNotify, & IID_IKompasObjectNotify>
{
public:
  ApplicationEvent();

protected:
  // Обработчики событий
  // Обрабатывает ли интерфейс событие notifyType?
  virtual VARIANT_BOOL STDMETHODCALLTYPE IsNotifyProcess( int notifyType );
  // Документ создан
  virtual VARIANT_BOOL STDMETHODCALLTYPE CreateDocument( long pDoc, int docType );
  // Начало открытия документа
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginOpenDocument( LPCSTR docName );
  // Документ открыт
  virtual VARIANT_BOOL STDMETHODCALLTYPE OpenDocument( long pDoc, int docType);
  // Переключение на другой активный документ
  virtual VARIANT_BOOL STDMETHODCALLTYPE ChangeActiveDocument( long pDoc, int docType);
  // Закрытие приложения
  virtual VARIANT_BOOL STDMETHODCALLTYPE ApplicationDestroy( void );
  //koBeginCreate - Процесс создания файла
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginCreate( long type );
  //koBeginOpenFile - Процесс открытия файла
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginOpenFile(void);
  //koBeginCloseAllDocument - Закрытие всех файлов
  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginCloseAllDocument(void);

  virtual VARIANT_BOOL STDMETHODCALLTYPE KeyDown( long __RPC_FAR *key,
                                                  long flags,
                                                  VARIANT_BOOL sysKey);

  virtual VARIANT_BOOL STDMETHODCALLTYPE KeyUp( long __RPC_FAR *key,
                                                long flags,
                                                VARIANT_BOOL sysKey);

  virtual VARIANT_BOOL STDMETHODCALLTYPE KeyPress( long __RPC_FAR *key,
                                                   VARIANT_BOOL sysKey);

  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginRequestFiles(  long requestID, VARIANT __RPC_FAR *files );

  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginChoiceMaterial( long MaterialPropertyId );

  virtual VARIANT_BOOL STDMETHODCALLTYPE ChoiceMaterial( long MaterialPropertyId, LPCSTR material, double density);

  virtual VARIANT_BOOL STDMETHODCALLTYPE IsNeedConvertToSavePrevious(
			long pDoc,
			int docType,
			long saveVersion,
			LPUNKNOWN saveToPreviusParam,
			VARIANT_BOOL *needConvert);

  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginConvertToSavePrevious(
			long pDoc,
			int docType,
			long saveVersion,
			LPUNKNOWN saveToPreviusParam);

  virtual  VARIANT_BOOL STDMETHODCALLTYPE EndConvertToSavePrevious(
			long pDoc,
			int docType,
			long saveVersion,
			LPUNKNOWN saveToPreviusParam);

  virtual VARIANT_BOOL STDMETHODCALLTYPE ChangeTheme( long newTheme );

  virtual VARIANT_BOOL STDMETHODCALLTYPE BeginDragOpenFiles( VARIANT *filesList, VARIANT_BOOL insert, VARIANT_BOOL *filesListChanged);

};
#endif

