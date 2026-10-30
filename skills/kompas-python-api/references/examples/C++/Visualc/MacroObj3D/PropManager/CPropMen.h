////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerObject - Класс для обслуживания панели свойств 
// PropertyManagerEvent  - Класс событий менеджера свойств 
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _CPROPMEN_H
#define _CPROPMEN_H

#include "..\events\ABaseEvent.h"
#include "..\MacroObj.h"

#include "..\events\CBaseEvent.h"

#ifndef _APPLICATIONEVENT_H
#include "..\events\ApplicationEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//-------------------------------------------------------------------------------
// Функции для выдачи сообщений библиотеки
// ---
int LibMessage( int     strId, int flags ); // Сообщение загружается из ресурсов
int LibMessage( LPCTSTR str,   int flags ); // Сообщение передается строкой 
 
// Для перехвата COM исключений
void DumpError(_com_error& e);              // Вывод текста исключения 

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
// ctrlID используется как идентификатор контрола и как идентификатор для загрузки 
// ресурсов контрола
//
////////////////////////////////////////////////////////////////////////////////
class PropertyManagerObject {
protected:
  int                          m_flagMode;         // Признак редактирования по дабл-клику
  ksAPI7::IProcessParamPtr     m_procParam;        // Параметры процесса          
// АВВ К10   IPropertyManagerPtr  m_propMng;       // Менеджер панели свойств
  ksAPI7::IPropertyTabsPtr     m_propTabs;         // Закладки
  ksAPI7::IPropertyControlsPtr m_curentCollection; // Контролы текущей закладки панели свойств 
  ksAPI7::IPropertyGridPtr     m_paramGrid;        // Грид для вывода дополнительных параметров элемента 
  ksAPI7::IPropertySlideBoxPtr m_slideBox;         // Окно просмотра 
  long                         m_rowIndex;         // Индекс строки
// АВВ К10   IProcessParamPtr   m_posLiaderParam;  // Параметры процесса указания линии выноски
public:
  long                 m_objectIndex;              // Индекс объекта 
public:
          
           PropertyManagerObject();
  virtual ~PropertyManagerObject();
// Панель свойств ##################################################################
  // События     
  // prButtonClick - Нажатие кнопки.
  virtual BOOL ButtonClick(long buttonID)                                         { return FALSE; }
  // prChangeControlValue - Изменение значения контрола
  virtual bool OnChangeControlValue(long ctrlID, const VARIANT & newVal)          { return true;  }
  // prControlCommand Нажатие кнопки контрола
  virtual BOOL ControlCommand(LPDISPATCH ctrl, long buttonID)                     { return FALSE; }
  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  virtual BOOL ButtonUpdate(long buttonID, long * check, VARIANT_BOOL  * _enable) { return FALSE; }
  // Событие создания ActiveX Control-a
  virtual void OnCreateOCX         ( long ctrlID, LPDISPATCH control )            {}
  // Событие удаления ActiveX Control-a 
  virtual void OnDestroyOCX        ( long ctrlID )                                {}
  // Накачка контекстной панели параметрами
  virtual BOOL FillContextPanel(LPDISPATCH ContextPanel)                          { return FALSE; }
  // Получение типа контекстного меню
  virtual BOOL GetContextMenuType(long LX, long LY, long * ContextMenuType)       { return FALSE; };

  // prProcessDeactivate  - Завершение процесса
  virtual BOOL ProcessDeactivate()                                                { return FALSE; }
  // prProcessActivate    - Начало процесса  
  virtual BOOL ProcessActivate()                                                  { return FALSE; }
  // prProcessRun    - Начало процесса  
  virtual BOOL ProcessRun()                                                       { return FALSE; }
  // ksPlacementChanged     Изменение положения.
  virtual BOOL PlacementChanged(LPDISPATCH object)                                { return FALSE; }
  // ksFilterProc         - Фильтрация объектов
  virtual BOOL FilterProc      (LPDISPATCH object)                                { return FALSE; }

  virtual void EndProcess      (); // Завершить процесс редактирования

  // prCommandHelp - Вызов справки
  BOOL CommandHelp(long ID );

  // Инициализация параметров процесса 
  bool                            InitProcessParam  ();

protected:
  virtual long                    GetFirstTabID     () { return 0; }
  virtual SpecPropertyToolBarEnum GetSpecToolBarType() { return pnEnterEscHelp; }

  // Добавление закладки
  bool CreateTab(long tabID, BOOL visible = TRUE, BOOL active = FALSE);

  // Добавление едита вещественных значений 
  ksAPI7::IPropertyEditPtr                CreateEditReal(double minVal = 0, double maxVal = 0);
  // Добавление комбобокса вещественных значений 
  ksAPI7::IPropertyListPtr                CreateList(double minVal = 0, double maxVal = 0);
  // Добавление комбобокса строковых значений 
  ksAPI7::IPropertyListPtr                CreateStringList(CString matVal = "");
  // Добавление сепаратора                                                        
  virtual ksAPI7::IPropertySeparatorPtr   CreateSeparator(SeparatorTypeEnum type);
  // Добавление CheckBox-а                                                        
  virtual ksAPI7::IPropertyCheckBoxPtr    CreateCheckBox(bool checked);
  // Добавление SpinEdit 
  virtual ksAPI7::IPropertySpinEditPtr    CreateSpinList(double minVal = 0, double maxVal = 0); // Голованов Е
  // Добавление контрола
	ksAPI7::IPropertyControlPtr             CreateControl( ControlTypeEnum conType );
  // Создать ActiveX Control пользователя
  virtual ksAPI7::IPropertyUserControlPtr CreateUserControl(long ctrlID, long height, long width);

  // Получить указатель на Control по его идентификатору (для изменения параметров контрола)
  virtual ksAPI7::IPropertyControlPtr GetPropertyControl(long ctrlID);

  // Изменить состояние контрола.
  void SetControlEnable(long ctrlID, bool enabled = true);

  // Накачка контрола общими параметрами
  void InitPropertyControl(ksAPI7::IPropertyControl * control, long ctrlID, UINT hint = 0,
                           UINT tips = 0, BOOL enable = TRUE,
                           PropertyControlNameVisibility nameVisibility = ksNameAlwaysVisible,
                           BOOL visible = TRUE);

  virtual void  ShowControls()  {}  // Виртуальная функция наполнения контролов элемента
  virtual void  RedrawPhantom() {}  // Перерисовать фантом

  virtual int   ParamCount() { return 0; }  // Количество параметров выводимых в гриде 
  virtual void  ShowParam () {}             // Заполнение грида параметров 

          virtual void  AddStringToGrig(long paramID, LPCTSTR  value); // Добавление строкового значения
          virtual void  AddDoubleToGrig(long paramID, double   value); // Добавление числового  значения

// Панель свойств ##################################################################
  virtual reference GetPreviewGroup() { return 0; }



};


////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обработчик событий от менеджера панели свойств
//
////////////////////////////////////////////////////////////////////////////////
class PropertyManagerEvent : public ABaseEvent
{
protected:
  PropertyManagerObject & m_obj; // Указатель на подписанный объект

public:
	PropertyManagerEvent( LPDISPATCH manager, PropertyManagerObject & obj );
  virtual ~PropertyManagerEvent();

public:
  // prButtonClick        - Нажатие кнопки.  "Создался OCX контрол."
  afx_msg BOOL ButtonClick       ( long buttonID );
  // prChangeControlValue - "Удаляется OCX контрол."
  afx_msg BOOL ChangeControlValue( LPDISPATCH ctrl );
  // prControlCommand     - Нажатие кнопки контрола
  afx_msg BOOL ControlCommand    ( LPDISPATCH  ctrl, long buttonID );
  // prButtonUpdate        -Установка состояния кнопки спецпанели.
  afx_msg BOOL ButtonUpdate      ( long buttonID, long * check, VARIANT_BOOL * _enable );
  // prProcessActivate    - Начало процесса	
  afx_msg BOOL ProcessActivate   ();
  // prProcessDeactivate  - Завершение процесса
  afx_msg BOOL ProcessDeactivate ();
  // prFillContextPanel  -  Накачка контекстной панели 
  afx_msg BOOL FillContextPanel  (LPDISPATCH ContextPanel);
  // prGetContextMenuType  - Получения типа контекстного меню 
  afx_msg BOOL GetContextMenuType(long LX, long LY, long * ContextMenuType);
  // prCommandHelp        - Установка состояния кнопки спецпанели.
  afx_msg BOOL CommandHelp       ( long buttonID );

  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
// _2_ Process3DEvent - обработчик событий от процесса 3D
//
////////////////////////////////////////////////////////////////////////////////
class Process3DEvent : public ABaseEvent
{

protected:
	PropertyManagerObject& m_obj;           // Указатель на подписанный объект
	bool              m_copyProc;
	// Attributes
public:
	Process3DEvent(const ksAPI7::IProcess3DPtr& process, PropertyManagerObject& _obj, bool copyProc = false);
	virtual ~Process3DEvent();

	// Operations
public:

	// ksExecuteCommand     - Выполнить команду меню.
	afx_msg BOOL ExecuteCommand(long command);
  // ksFilterProc         - Фильтрация объектов
	afx_msg BOOL FilterProc(LPDISPATCH object);
  // ksPlacementChanged   - Изменено положения объекта
  afx_msg BOOL PlacementChanged(LPDISPATCH object);
  // ksStop               - Остановка процесса
  afx_msg BOOL Stop();
  // ksEndProcess         - Окончание процесса.
	afx_msg BOOL EndProcess();
  // ksCreateTakeObject   - Создание объекта в подпроцессе
  afx_msg BOOL CreateTakeObject(LPUNKNOWN Object);
  // ksProcessActivate    - Начало процесса  
  afx_msg BOOL ProcessActivate();
  // ksProcessDeactivate  - Завершение процесса
  afx_msg BOOL ProcessDeactivate();
  // ksProcessActivate    - Начало процесса  
  afx_msg BOOL ProcessRun();

	DECLARE_EVENTSINK_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
