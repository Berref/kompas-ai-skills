////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerObject - Класс для обслуживания панели свойств 
// PropertyManagerEvent  - Класс событий менеджера свойств 
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _CPROPMEN_H
#define _CPROPMEN_H

#include "..\events\ABaseEvent.h"
#include "..\OneWindow.h"
#include <afxcview.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "parray.h"


//-------------------------------------------------------------------------------
// Функции для выдачи сообщений библиотеки
// ---
int LibMessage(int     strId, int flags); // Сообщение загружается из ресурсов
int LibMessage(LPCTSTR str, int flags); // Сообщение передается строкой 

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
  int                  m_flagMode;         // Признак редактирования по дабл-клику
  IProcessParamPtr     m_procParam;        // Параметры процесса          
  IPropertyTabsPtr     m_propTabs;         // Закладки
  IPropertyControlsPtr m_curentCollection; // Контролы текущей закладки панели свойств 
  IPropertyGridPtr     m_paramGrid;        // Грид для вывода дополнительных параметров элемента 
  IPropertySlideBoxPtr m_slideBox;         // Окно просмотра 
  long                 m_rowIndex;         // Индекс строки
  IProcessParamPtr     m_posLiaderParam;   // Параметры процесса указания линии выноски
public:

  PropertyManagerObject();
  virtual ~PropertyManagerObject();
  // Панель свойств ##################################################################
    // События     
    // prButtonClick - Нажатие кнопки.
  virtual bool OnButtonClick(long buttonID) { return true; }
  //prChangeControlValue - Изменение значения контрола                                     
  virtual bool OnChangeControlValue(long ctrlID, const VARIANT& newVal) { return true; }
  //prControlCommand Нажатие кнопки контрола                                               
  virtual bool OnControlCommand(long ctrlID, long buttonID) { return true; }
  //prButtonUpdate        - Установка состояния кнопки спецпанели.
  virtual bool OnButtonUpdate(long buttonID, long* check, VARIANT_BOOL* _enable) { return true; }
  // prCommandHelp - Вызов справки
  virtual bool OnCommandHelp(long ID) { return false; }
  // Событие создания ActiveX Control-a
  virtual void OnCreateOCX(long ctrlID, LPDISPATCH control) {}
  // Событие удаления ActiveX Control-a 
  virtual void OnDestroyOCX(long ctrlID);

  // Инициализация параметров процесса 
  virtual bool                    InitProcessParam(long toolBarID, SpecPropertyToolBarEnum toolBarType, long firstTabID);
  virtual long                    GetFirstTabID() { return 0; }
  virtual SpecPropertyToolBarEnum GetSpecToolBarType() { return pnEnterEscHelp; }
  void                    EndProcess(); // Завершить процесс редактирования

  // Добавление закладки
  bool CreateTab(long tabID, BOOL visible = TRUE, BOOL active = FALSE);

  // Добавление едита вещественных значений 
  IPropertyEditPtr        CreateEditReal(double minVal = 0, double maxVal = 0);
  // Добавление комбобокса вещественных значений 
  IPropertyListPtr        CreateList(double minVal = 0, double maxVal = 0);
  // Добавление комбобокса строковых значений 
  IPropertyListPtr        CreateStringList(CString matVal = "");
  // Добавление сепаратора 
  IPropertySeparatorPtr   CreateSeparator(SeparatorTypeEnum type);
  // Добавление CheckBox-а 
  IPropertyCheckBoxPtr    CreateCheckBox(bool checked);
  // Добавление SpinEdit 
  IPropertySpinEditPtr    CreateSpinList(double minVal = 0, double maxVal = 0); // Голованов Е
  // Добавление группы кнопок 
  IPropertyMultiButtonPtr CreateMultiButton(ButtonTypeEnum type);
  // Создать ActiveX Control пользователя
  IPropertyUserControlPtr CreateUserControl(long ctrlID, long height, long width);

  // Получить указатель на Control по его идентификатору (для изменения параметров контрола)
  IPropertyControlPtr GetPropertyControl(int ctrlID);

  // Добавление кнопки в группу
  void AddButton(IPropertyMultiButtonPtr& buttons, long btnID,
    bool cheched = false, bool enable = true);
  // Добавление кнопки в группу
  void AddButton2(IPropertyMultiButtonPtr& buttons, long btnID,
    long bmpID, bool cheched = false, bool enable = true);

  // Изменить состояние контрола
  void SetControlEnable(long ctrlID, bool enabled = true);

  // Накачка контрола общими параметрами
  void InitPropertyControl(IPropertyControl* control, long ctrlID, UINT hint = 0,
    UINT tips = 0, BOOL enable = TRUE,
    PropertyControlNameVisibility nameVisibility = ksNameAlwaysVisible,
    BOOL visible = TRUE);

  virtual void  ShowControls() {}  // Виртуальная функция наполнения контролов элемента
  virtual void  RedrawPhantom() {}  // Перерисовать фантом

  virtual int   ParamCount() { return 0; }  // Количество параметров выводимых в гриде 
  virtual void  ShowParam() {}             // Заполнение грида параметров 

  void  AddStringToGrig(long paramID, LPCTSTR  value); // Добавление строкового значения
  void  AddDoubleToGrig(long paramID, double   value); // Добавление числового  значения

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
  PropertyManagerObject& m_obj; // Указатель на подписанный объект

public:
  PropertyManagerEvent(LPDISPATCH manager, PropertyManagerObject& obj);
  virtual ~PropertyManagerEvent();

public:
  // prButtonClick        - Нажатие кнопки.  "Создался OCX контрол."
  afx_msg BOOL ButtonClick(long buttonID);
  // prChangeControlValue - "Удаляется OCX контрол."
  afx_msg BOOL ChangeControlValue(LPDISPATCH ctrl);
  // prControlCommand     - Нажатие кнопки контрола
  afx_msg BOOL ControlCommand(LPDISPATCH  ctrl, long buttonID);
  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  afx_msg BOOL ButtonUpdate(long buttonID, long* check, VARIANT_BOOL* _enable);
  // prProcessActivate    - Начало процесса 
  afx_msg BOOL ProcessActivate();
  // prProcessDeactivate  - Завершение процесса
  afx_msg BOOL ProcessDeactivate();
  // prCommandHelp        - Установка состояния кнопки спецпанели.
  afx_msg BOOL CommandHelp(long buttonID);
  // prUserMenuCommand    - Нажатие кнопки пользовательского меню
  afx_msg BOOL UserMenuCommand(LPDISPATCH  ctrl, long buttonID);

  DECLARE_EVENTSINK_MAP()
};


//-----------------------------------------------------------------------------
//
// ---
class ATreeViewEventCallBack
{
public:
  virtual void OnBeginTextEdit(IPropertyTreeNodePtr node) {}
  virtual void OnEndTextEdit(IPropertyTreeNodePtr node) {}
  virtual void OnExpandOrCollapse(IPropertyTreeNodePtr Node, bool collapse) {}
  virtual void OnSelectNodes(const VARIANT& Nodes) {}
  virtual void OnUnselectNodes(const VARIANT& Nodes) {}
  virtual void OnMenuCommand(long Id) {}
  virtual void OnContextMenuRequest(IPropertyTreeNodePtr node) {}
  // АВВ К11   virtual void NodeCheck       ( struct INode * Node );

};

//-----------------------------------------------------------------------------
// ATreeViewEvent  - обработчик событий от ocx дерева
// ---
class ATreeViewEvent : public ABaseEvent
{
  ATreeViewEventCallBack& m_obj;
public:
  ATreeViewEvent(IPropertyTreePtr& tree, ATreeViewEventCallBack& obj);
  virtual ~ATreeViewEvent();

protected:
  afx_msg void Collapse(LPDISPATCH Node);
  afx_msg void Expand(LPDISPATCH Node);
  afx_msg void NodeDblClick(LPDISPATCH Node);
  afx_msg void BeginTextEdit(LPDISPATCH Node);
  afx_msg void EndTextEdit(LPDISPATCH Node);
  afx_msg void SelectNodes(const VARIANT& Nodes);
  afx_msg void UnSelectNodes(const VARIANT& Nodes);
  afx_msg void OnContextMenuRequest(LPDISPATCH Node);
  // АВВ К11   afx_msg void NodeCheck       ( struct INode * Node );

  DECLARE_EVENTSINK_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
