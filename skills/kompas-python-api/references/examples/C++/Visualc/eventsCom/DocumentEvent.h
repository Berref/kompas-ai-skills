// DocumentEvent.h : header file
//
#ifndef _DOCUMENTEVENT_H
#define _DOCUMENTEVENT_H

#ifndef _BASEEVENT_H
#include "baseEvent.h"
#endif


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//class StampEvent;

////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
class DocumentEvent : public BaseEvent
{
protected:
  //  StampEvent * m_stampEvent;
  //  BaseEvent  * m_objEvent;
  // Attributes
public:
  DocumentEvent(reference p);
  virtual ~DocumentEvent();

  // Operations
public:
  //  void SetStampEvent( StampEvent * stampEvent );
  //  void SetObjEvent  ( BaseEvent  * objEvent   );
  void      ShowEventName(LPCTSTR eventName);
  virtual   CString   EventCaption();
  // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(DocumentEvent)
    //}}AFX_VIRTUAL
  virtual   LPUNKNOWN GetUnknown();
  // Implementation

  BEGIN_INTERFACE_PART(DocumentFileNotify, IDocumentFileNotify)
    INIT_INTERFACE_PART(DocumentEvent, DocumentFileNotify)
    //Обрабатывается ли библиотекой событие с номером notifyType
    STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)(int notifyType);

  //kdBeginCloseDocument  -  Начало закрытия документа
  STDMETHOD_(VARIANT_BOOL, BeginCloseDocument)();

  //kdCloseDocument       -  Документ закрыт
  STDMETHOD_(VARIANT_BOOL, CloseDocument)();

  //kdBeginSaveDocument   -  Начало сохранения документа
  STDMETHOD_(VARIANT_BOOL, BeginSaveDocument)(LPSTR docName);

  //kdSaveDocument        -  Документ сохранен
  STDMETHOD_(VARIANT_BOOL, SaveDocument)();

  //kdActiveDocument        -  Документ активизирован
  STDMETHOD_(VARIANT_BOOL, Activate)();

  //kdDeactiveDocument     -  Документ деактивизирован.
  STDMETHOD_(VARIANT_BOOL, Deactivate)();

  //kdBeginSaveAsDocument  - Запрос имени документа для сохранения.
  STDMETHOD_(VARIANT_BOOL, BeginSaveAsDocument)();

  //kdDocumentFrameOpen    - Окно документа открылось.
  STDMETHOD_(VARIANT_BOOL, DocumentFrameOpen)(LPUNKNOWN v);

  //kdProcessActivate      - Активизация процесса
  STDMETHOD_(VARIANT_BOOL, ProcessActivate)(long Id);

  //kdProcessDeactivate    - Деактивизация процесса
  STDMETHOD_(VARIANT_BOOL, ProcessDeactivate)(long Id);

  //kdBeginProcess         - Начало процесса
  STDMETHOD_(VARIANT_BOOL, BeginProcess) (long Id);

  //kdEndProcess           - Завершение процесса
  STDMETHOD_(VARIANT_BOOL, EndProcess) (long Id, VARIANT_BOOL Success);

  //kdBeginAutoSaveDocument - Начало автосохранения документа
  STDMETHOD_(VARIANT_BOOL, BeginAutoSaveDocument) (LPSTR docName);
  //kdAutoSaveDocument     - Документ автосохранен.
  STDMETHOD_(VARIANT_BOOL, AutoSaveDocument) ();

  STDMETHOD_(VARIANT_BOOL, ActivateToolbarSet)(LPSTR oldToolbarSetId, LPSTR newToolbarSetId);
  END_INTERFACE_PART(DocumentFileNotify)

};

class Document2DEvent : public BaseEvent { // DocumentEvent {
  //  bool                      m_advise3D;     // true - сделан Advise
  //  NotifyConnectionParam     m_params3D;     // параметры подписки
  // Attributes
public:
  Document2DEvent(reference p);
  virtual ~Document2DEvent();

  // Operations
public:

  //virtual   bool      Advise(); // подписаться на получение событий
  //virtual   void      Unadvise();                                   // отписаться от получения событий
  virtual   void      ShowEventName(LPCTSTR eventName);
  virtual   CString   EventCaption();
  // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(DocumentEvent)
    //}}AFX_VIRTUAL
  virtual  LPUNKNOWN GetUnknown();
  BEGIN_INTERFACE_PART(Document2DNotify, IDocument2DNotify)
    INIT_INTERFACE_PART(Document2DEvent, Document2DNotify)
    // d2BeginRebuild - Начало перестроения модели
    STDMETHOD_(VARIANT_BOOL, BeginRebuild)();
  // d2Rebuild - Модель перестроена
  STDMETHOD_(VARIANT_BOOL, Rebuild)();
  // d2BeginChoiceMaterial - Начало выбора материала
  STDMETHOD_(VARIANT_BOOL, BeginChoiceMaterial)();
  // d2ChoiceMaterial - Закончен выбор материала
  STDMETHOD_(VARIANT_BOOL, ChoiceMaterial)(LPSTR material, double density);
  // d2BeginInsertFragment - Начало вставки фрагмента (до диалога выбора имени)
  STDMETHOD_(VARIANT_BOOL, BeginInsertFragment)();
  // d2LocalFragmentEdit - Редактирование локального фрагмента
  STDMETHOD_(VARIANT_BOOL, LocalFragmentEdit)(long pDoc, VARIANT_BOOL newFrw);
  //Обрабатывается ли библиотекой событие с номером notifyType
  STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)(int notifyType);
  // d2BeginChoiceProperty - Начало выбора свойства
  STDMETHOD_(VARIANT_BOOL, BeginChoiceProperty) (long objRef, double propID);
  // d2ChoiceProperty - Закончен выбор свойства
  STDMETHOD_(VARIANT_BOOL, ChoiceProperty) (long objRef, double propID);
  // d2BeginDeleteProperty - Начало удаления значения свойства
  STDMETHOD_(VARIANT_BOOL, BeginDeleteProperty) (long objRef, double propID);
  // d2DeleteProperty - Завершение удаления свойства
  STDMETHOD_(VARIANT_BOOL, DeleteProperty) (long objRef, double propID);
  END_INTERFACE_PART(Document2DNotify)


};

class Document3DEvent : public BaseEvent { // DocumentEvent {
  //  bool                      m_advise3D;     // true - сделан Advise
  //  NotifyConnectionParam     m_params3D;     // параметры подписки
  // Attributes
public:
  Document3DEvent(reference p, LPUNKNOWN doc = NULL);
  virtual ~Document3DEvent();

  // Operations
public:

  //virtual   bool      Advise(); // подписаться на получение событий
  //virtual   void      Unadvise();                                   // отписаться от получения событий
  virtual   void      ShowEventName(LPCTSTR eventName);
  virtual   CString   EventCaption();
  // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(DocumentEvent)
    //}}AFX_VIRTUAL
  virtual  LPUNKNOWN GetUnknown();
  BEGIN_INTERFACE_PART(Document3DNotify, IDocument3DNotify)
    INIT_INTERFACE_PART(Document3DEvent, Document3DNotify)

    // d3BeginRebuild - Начало перестроения модели
    STDMETHOD_(VARIANT_BOOL, BeginRebuild)(THIS_);
  // d3Rebuild      - Модель перестроена
  STDMETHOD_(VARIANT_BOOL, Rebuild)(THIS_);
  // d3BeginChoiceMaterial - Начало выбора материала
  STDMETHOD_(VARIANT_BOOL, BeginChoiceMaterial)(THIS_);
  // d3ChoiceMaterial - Закончен выбор материала
  STDMETHOD_(VARIANT_BOOL, ChoiceMaterial)(THIS_ LPSTR material, double density);
  // d3BeginChoiceMarking - Начало выбора обозначения
  STDMETHOD_(VARIANT_BOOL, BeginChoiceMarking)(THIS_);
  // d3ChoiceMarking - Закончен выбор обозначения
  STDMETHOD_(VARIANT_BOOL, ChoiceMarking)(THIS_ LPSTR marking);
  // d3BeginSetPartFromFile - Начало установки компонента в сборку (до диалога выбора имени)
  STDMETHOD_(VARIANT_BOOL, BeginSetPartFromFile)(THIS_);
  // d3BeginCreatePartFromFile - Начало создания компонента в сборке (до диалога выбора имени)
  STDMETHOD_(VARIANT_BOOL, BeginCreatePartFromFile)(THIS_ VARIANT_BOOL typeDoc, IEntity* plane);
  //Обрабатывается ли библиотекой событие с номером notifyType
  STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)(THIS_ int notifyType);
  // d3CreateEmbodiment - Добавлено новое исполнение
  STDMETHOD_(VARIANT_BOOL, CreateEmbodiment)(THIS_ LPSTR marking);
  // d3DeleteEmbodiment - Удалено исполнение
  STDMETHOD_(VARIANT_BOOL, DeleteEmbodiment)(THIS_ LPSTR marking);
  // d3ChangeCurrentEmbodiment - Исполение установлено текущим
  STDMETHOD_(VARIANT_BOOL, ChangeCurrentEmbodiment)(THIS_ LPSTR marking);
  // d3BeginChoiceProperty - Начало выбора свойства
  STDMETHOD_(VARIANT_BOOL, BeginChoiceProperty) (THIS_ IUnknown* obj, double propID);
  // d3ChoiceProperty - Закончен выбор свойства
  STDMETHOD_(VARIANT_BOOL, ChoiceProperty) (THIS_ IUnknown* obj, double propID);
  // d3BeginRollbackFeatures - Начало отката дерева модели
  STDMETHOD_(VARIANT_BOOL, BeginRollbackFeatures) (THIS_);
  // d3RollbackFeatures - Завершение отката дерева модели
  STDMETHOD_(VARIANT_BOOL, RollbackFeatures)  (THIS_);
  // d3BedinLoadCombinationChange - Начало переключения типа загрузки
  STDMETHOD_(VARIANT_BOOL, BedinLoadCombinationChange) (long index);
  // d3LoadCombinationChange - Завершение переключения типа загрузки
  STDMETHOD_(VARIANT_BOOL, LoadCombinationChange) (long index);
  // d3BeginDeleteMaterial - Начало удаления материала
  STDMETHOD_(VARIANT_BOOL, BeginDeleteMaterial)(THIS_);
  // d3DeleteMaterial - Материал удален
  STDMETHOD_(VARIANT_BOOL, DeleteMaterial)(THIS_);
  // d3BeginDeleteProperty - Начало удаления значения свойства
  STDMETHOD_(VARIANT_BOOL, BeginDeleteProperty) (THIS_ IUnknown* obj, double propID);
  // d3DeleteProperty - Завершение удаления свойства
  STDMETHOD_(VARIANT_BOOL, DeleteProperty) (THIS_ IUnknown* obj, double propID);

  END_INTERFACE_PART(Document3DNotify)


};


BaseEvent* NewDocumentEvent(reference doc);
BaseEvent* NewDocument2DEvent(reference doc);
BaseEvent* NewDocument3DEvent(reference doc);


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
