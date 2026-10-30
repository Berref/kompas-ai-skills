////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerObject - Класс для обслуживания панели свойств 
// PropertyManagerEvent  - Класс событий менеджера свойств 
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _CPROPMEN_H
#define _CPROPMEN_H

#ifndef _ABASEEVENT_H
#include "abaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>

//-------------------------------------------------------------------------------
// Функции для выдачи сообщений библиотеки
// ---
int LibMessage(int strId, int flags = 0); // Сообщение загружается из ресурсов
int LibMessage(const std::wstring & str, int flags = 0); // Сообщение передается строкой 

// Для перехвата COM исключений
void DumpError(_com_error & e);              // Вывод текста исключения 
void ShowError();                           // Вывод сообщений при самостоятельном анализе HRESULT 

/*
  Пример
  IApplicationPtr kompasNewApp;
  HRESULT _hr = get_Application( &kompasNewApp );
  if (FAILED(_hr))
    ShowError();
*/

/* Пример 2

Обработка исключений при вызове функций kAPI7.tli:
inline IKompasDocumentPtr IDocuments::GetItem ( const _variant_t & Index ) {
  struct IKompasDocument * _result;
  HRESULT _hr = get_Item(Index, &_result);
  if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
  return IKompasDocumentPtr(_result, false);
}
....
IKompasDocumentPtr kompasDocument;
....
try {
  kompasDocument = documents->Item[100000]; // Заведомое исключение
}
catch(_com_error &e)
{
  DumpError(e);
  return;
}
....
*/

//----------------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//
// Класс для обслуживания панели свойств 
//
// ctrlID используется как идентивикатор контрола и как идентификатор для загрузки 
// ресурсов контрола
//
////////////////////////////////////////////////////////////////////////////////
class PropertyManagerObject {
protected:
  int                             flagMode;         // Признак редактирования по дабл-клику
  ksAPI7::IProcessParamPtr        procParam;        // Параметры процесса          
  ksAPI7::IPropertyTabsPtr        propTabs;         // Закладки
  ksAPI7::IPropertyControlsPtr    curentCollection; // Контролы текущей закладки панели свойств 
  ksAPI7::IPropertyEditPtr        angleEdit;        //
  ksAPI7::IPropertyEditPtr        stepEdit;         //  
  ksAPI7::IPropertyControlPtr     hatchCtrl;        //  
  ksAPI7::IPropertyParamGridPtr   paramGrid;        // Грид для вывода дополнительных параметров элемента 
  ksAPI7::IPropertySlideBoxPtr    slideBox;         // Окно просмотра 
  long                            rowIndex;         // Индекс строки
public:

  PropertyManagerObject();
  virtual ~PropertyManagerObject();
  // Менеджер свойств ##################################################################
      // События     
      // prButtonClick - Нажатие кнопки.
  virtual bool OnButtonClick(long buttonID) { return false; }

  //prChangeControlValue - Изменение значения контрола
  virtual bool OnChangeControlValue( /*IPropertyControl* cntrl,*/ long ctrlID, const VARIANT & newVal) { return true; }

  // Инициализация параметров процесса 
  /*virtual*/ bool InitProcessParam(long toolBarID, SpecPropertyToolBarEnum toolBarType, long firstTabID = 0);

  // Добавление закладки
  bool CreateTab(long tabID, BOOL visible = TRUE, BOOL active = FALSE);
  // Редактирование объекта спецификации
  virtual void EditSpcObject() {};

  // Добавление комбобокса вещественных значений 
  ksAPI7::IPropertyListPtr               CreateList(double minVal = 0, double maxVal = 0);
  // Добавление сепаратора 
  ksAPI7::IPropertySeparatorPtr          CreateSeparator(SeparatorTypeEnum type);
  // Добавление CheckBox-а 
  ksAPI7::IPropertyCheckBoxPtr           CreateCheckBox(bool checked);
  // Добавление группы кнопок 
  ksAPI7::IPropertyMultiButtonPtr        CreateMultiButton(ButtonTypeEnum type);
  // Создать группу параметров штриховки
  virtual void                           CreatePropertyGroup() {};

  // Получить указатель на Control по его идентификатору (для изменения параметров контрола)
  ksAPI7::IPropertyControlPtr  GetPropertyControl(int ctrlID);

  // Добавление кнопки в группу
  void AddButton(ksAPI7::IPropertyMultiButtonPtr & buttons, long btnID, bool cheched = false, bool enable = true);
  // Добавление кнопки в группу
  void AddButton2(ksAPI7::IPropertyMultiButtonPtr & buttons, long btnID, long bmpID, bool cheched = false, bool enable = true);

  // Изменить состояние контрола
  void SetControlEnable(long ctrlID, bool enabled = true);

  // Накачка контрола общими параметрами
  void InitPropertyControl(ksAPI7::IPropertyControl * control, long ctrlID, UINT hint = 0, UINT tips = 0,
                           BOOL enable = TRUE, PropertyControlNameVisibility nameVisibility = ksNameAlwaysVisible,
                           BOOL visible = TRUE);

  // Виртуальная функция наполнения контролов элемента
  virtual void  ShowControls() {}
  // Перерисовать фантом
  virtual void  RedrawPhantom() {}
  // процесс создания эл-та
  virtual void  Draw1() {  };
  // ksPlacementChanged    -Изменено положения объекта
  virtual BOOL  PlacementChanged(double x, double y, double angle, BOOL dynamic) { return FALSE; };

  // Количество параметров выводимых в гриде 
  virtual int   ParamCount() { return 0; }
  // Заполнение грида параметров 
  virtual void  ShowParam() {}
  // Скрыть - показать закладку 
  //        void  SetTabVisible( long tabID, bool visible );
  // Функции для заполнения грида параметров        
  //        void  AddBSTRToGrig(   long paramID, _bstr_t& value ); // Добавление строкового значения
  //       void  AddStringToGrig( long paramID, CString& value ); // Добавление строкового значения
  void  AddStringToGrig(long paramID, LPCTSTR  value); // Добавление строкового значения
  void  AddDoubleToGrig(long paramID, double   value); // Добавление числового  значения

  // Признак наличия штриховки у объекта        
  virtual  bool IsHatchObject() { return false; }

  // Функции для вывода контрола параметров штриховки        
  virtual  void ShowHatchControl() { }

  // Завершить процесс редактирования
  virtual BOOL  EndProcess();
  virtual void  UnadviseEvents();
  // Менеджер свойств ##################################################################
  virtual reference  GetPreviewGroup() { return 0; }
  virtual  int  GetCommand() { return 0; } // Номер команды

};


////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обрабокчик событий от менеджера панели свойств
//
////////////////////////////////////////////////////////////////////////////////
class PropertyManagerEvent : public ABaseEvent
{

protected:
  PropertyManagerObject & obj;           // Указатель на подписанный объект
  // Attributes
public:
  PropertyManagerEvent(LPDISPATCH manager, PropertyManagerObject & _obj);
  virtual ~PropertyManagerEvent();

  // Operations
public:

  // prButtonClick        - Нажатие кнопки.  "Создался OCX контрол."
  afx_msg BOOL ButtonClick(long buttonID);

  // prChangeControlValue - "Удаляется OCX контрол."
  afx_msg BOOL ChangeControlValue(LPDISPATCH ctrl);

  // prControlCommand     - Нажатие кнопки контрола
  afx_msg BOOL ControlCommand(LPDISPATCH  ctrl, long buttonID);

  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  afx_msg BOOL ButtonUpdate(long buttonID, long * check, VARIANT_BOOL * _enable);

  // prProcessActivate    - Начало процесса  
  afx_msg BOOL ProcessActivate();

  // prProcessDeactivate  - Завершение процесса
  afx_msg BOOL ProcessDeactivate();

  // prCommandHelp        - Установка состояния кнопки спецпанели.
  afx_msg BOOL CommandHelp(long buttonID);

  DECLARE_EVENTSINK_MAP()
};


/*
////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обрабокчик событий от менеджера панели свойств
//
////////////////////////////////////////////////////////////////////////////////
class PropertyManagerEvent : public cBaseEvent
{
protected:
  PropertyManagerObject&  obj;           // Указатель на подписанный объект
  // Attributes
public:
  PropertyManagerEvent( LPUNKNOWN I, PropertyManagerObject& _obj );
  virtual ~PropertyManagerEvent();

// Operations
public:
  PropertyManagerObject& GetObj() { return obj; }
  virtual   LPUNKNOWN GetUnknown();

  BEGIN_INTERFACE_PART(PropertyManagerNotify, IPropertyManagerNotify)
    INIT_INTERFACE_PART(PropertyManagerEvent, PropertyManagerNotify)

    //Обрабатывается ли библиотекой событие с номером notifyType
    STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)( THIS_ int notifyType );

    //prButtonClick - Нажатие кнопки.
    STDMETHOD_(VARIANT_BOOL, ButtonClick)( THIS_ long buttonID);

    //prChangeControlValue - Изменение значения контрола
    STDMETHOD_(VARIANT_BOOL, ChangeControlValue)( THIS_ LPUNKNOWN  ctrl);

    //prControlCommand Нажатие кнопки контрола
    STDMETHOD_(VARIANT_BOOL, ControlCommand)( THIS_ LPUNKNOWN  ctrl, long buttonID );

    //prButtonUpdate        - Установка состояния кнопки спецпанели.
    STDMETHOD_(VARIANT_BOOL, ButtonUpdate)( THIS_ long buttonID, long* check, long* _enable);

    // prProcessActivate    - Начало процесса
    STDMETHOD_(VARIANT_BOOL, ProcessActivate) ( THIS_ );

    // prProcessActivate    - Завершение процесса
    STDMETHOD_(VARIANT_BOOL, ProcessDeactivate) ( THIS_ );

  END_INTERFACE_PART(PropertyManagerNotify)

};
*/
// Освободить интерфейсы
void App7NULL();
void OpenHelp(int Id);
/////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
// _2_ Process2DEvent - обработчик событий от процесса 2D
//
////////////////////////////////////////////////////////////////////////////////
class Process2DEvent : public ABaseEvent
{

protected:
  PropertyManagerObject & m_obj;           // Указатель на подписанный объект
  bool                m_ownObj;
  // Attributes
public:
  Process2DEvent(const ksAPI7::IProcess2DPtr & process, PropertyManagerObject & _obj, bool ownObj);
  virtual ~Process2DEvent();

  // Operations
public:

  // ksPlacementChanged   - Изменено положения объекта
  afx_msg BOOL PlacementChanged(double x, double y, double angle, BOOL dynamic);
  // ksStop               - Остановка процесса
  afx_msg BOOL Stop();
  // ksProcessActivate    - Начало процесса  
  afx_msg BOOL ProcessActivate();
  // ksProcessDeactivate  - Завершение процесса
  afx_msg BOOL ProcessDeactivate();
  // ksProcessDeactivate  - Завершение процесса
  afx_msg BOOL Run();
  // ksEndProcess         - Окончание процесса.
  afx_msg BOOL EndProcess();
  DECLARE_EVENTSINK_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
