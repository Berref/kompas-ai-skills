////////////////////////////////////////////////////////////////////////////////
//
// cPropMen.cpp - Класс для работы с панелью свойств
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "cPropMen.h"
#include "..\IPropertyTree_Sample.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE * pModuleState;
extern HINSTANCE g_hInstance;


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage(LPCTSTR str, int flags)
{
  int res = 0;

  //  if ( str && str[0] )                    // строка передана
  //  {
  //    int enabse = ::IsEnableTaskAccess();  // проверка доступа
  //    if ( enabse )                         // если доступ к задаче разрешен
  //      ::EnableTaskAccess(0);              // запрещаем доступ
  //
  //    res = ::MessageBox( (HWND)::GetHWindow(), str, LoadStr(MENU_1), flags );
  //
  //    if ( enabse )                         // если доступ к задаче был запрещен
  //      ::EnableTaskAccess(1);              // разрешаем доступ к задаче
  //  }

  return res;
}


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage(int strId, int flags) {
  //  return ::LibMessage( ::LoadStr(strId), flags );
  return 0;
}


//------------------------------------------------------------------------------
// Вспомогательная функция, возвращающая информацию об ошибке
// ---
void DumpError(_com_error & e)
{
  _bstr_t bstrSource(e.Source());
  _bstr_t bstrDescription(e.Description());
  CString str;
  str.Format(_T("Error = %08lx"), e.Error());
  str += _T("\nMessage     :"); str += e.ErrorMessage();
  str += _T("\nSource      :"); str += (LPCTSTR)bstrSource;
  str += _T("\nDescription :"); str += (LPCTSTR)bstrDescription;
  ::LibMessage(str, MB_OK | MB_ICONERROR);
}


//----------------------------------------------------------------------------------------------
// Конструктор
// ---
PropertyManagerObject::PropertyManagerObject()
  : m_procParam(NULL)  // Параметры процесса
  , m_propTabs(NULL)  // Коллекция закладок
  , m_curentCollection(NULL)  // Коллекция контролов 
  , m_paramGrid(NULL)  // Грид для вывода дополнительных параметров элемента 
  , m_slideBox(NULL)  // Окно просмотра 
  , m_rowIndex(0)  // Индекс строки
  , m_posLiaderParam(NULL)
  , m_flagMode(0)
{
}


//----------------------------------------------------------------------------------------------
// Деструктор
// ---
PropertyManagerObject::~PropertyManagerObject()
{
  m_paramGrid = NULL;  // Грид для вывода дополнительных параметров элемента 
  m_slideBox = NULL;  // Окно просмотра 
  m_curentCollection = NULL;  // Коллекция контролов 
  m_propTabs = NULL;  // Коллекция закладок
  m_procParam = NULL;  // Параметры процесса
  m_posLiaderParam = NULL;
  m_rowIndex = 0;  // Индекс строки
}


//----------------------------------------------------------------------------------------------
// Инициализация параметров процесса
// ---
bool PropertyManagerObject::InitProcessParam()
{
  bool res = false;
  return res;
}


//----------------------------------------------------------------------------------------------
// Добавить параметр в грид
// ---
void PropertyManagerObject::AddStringToGrig(long paramID, LPCTSTR value)
{
  if (m_paramGrid)
  {
    m_paramGrid->CellText[m_rowIndex][1] = _bstr_t(value);
    m_paramGrid->CellText[m_rowIndex++][0] = _bstr_t(::LoadStr(paramID)); // Не переставлять так задумано
  }
}


//----------------------------------------------------------------------------------------------
// Перевод значения в строку
// ---
const char * DoubleToStr(double value)
{
  static char res[20];
  ::sprintf_s(res, "%g", value);
  return res;
}


//----------------------------------------------------------------------------------------------
// Добавить параметр в грид
// ---
void PropertyManagerObject::AddDoubleToGrig(long paramID, double value)
{
  if (m_paramGrid)
  {
    m_paramGrid->CellText[m_rowIndex][1] = _bstr_t(::DoubleToStr(value));  // Выводим значение
    m_paramGrid->CellText[m_rowIndex++][0] = _bstr_t(::LoadStr(paramID));  // Имя параметра
  }
}


//----------------------------------------------------------------------------------------------
// Создать закладку
// ---
bool PropertyManagerObject::CreateTab(long tabID, BOOL visible, BOOL active)
{
  bool res = false;

  if (tabID)
  {
    if (m_propTabs)
    {
      _bstr_t tmpBstr(::LoadStr(tabID));
      IPropertyTabPtr propTab = m_propTabs->Add(tmpBstr);

      if (propTab)
      {
        m_curentCollection = propTab->PropertyControls;
        propTab->Active = active;

        if (!visible)
          propTab->Visible = visible;

        res = true;
      }
    }
  }

  return res;
}


//----------------------------------------------------------------------------------------------
// Создать комбобокс
// ---
void PropertyManagerObject::InitPropertyControl(IPropertyControl * control, long ctrlID,
                                                UINT hint, UINT tips, BOOL enable,
                                                PropertyControlNameVisibility nameVisibility,
                                                BOOL visible)
{
  if (control)
  {
    _bstr_t tmpBstr(LoadStr(ctrlID));
    control->Name = tmpBstr;
    control->Id = ctrlID;
    tmpBstr = hint ? LoadStr(hint) : "";
    control->Hint = tmpBstr;
    tmpBstr = tips ? LoadStr(tips) : "";
    control->Tips = tmpBstr;
    control->Enable = enable;
    control->Visible = visible;
    control->NameVisibility = nameVisibility;
  }
}


//----------------------------------------------------------------------------------------------
// Создать едит вещественных значений
// ---
IPropertyEditPtr PropertyManagerObject::CreateEditReal(double minVal, double maxVal)
{
  IPropertyEditPtr realEdit(NULL);

  if (m_curentCollection)
  {
    realEdit = m_curentCollection->Add(ksControlEditReal);

    if (realEdit)
    {
      if (minVal != maxVal)
        realEdit->SetValueRange(_variant_t(minVal), _variant_t(maxVal));
    }
  }

  return realEdit;
}


//----------------------------------------------------------------------------------------------
// Создать комбобокс
// ---
IPropertyListPtr PropertyManagerObject::CreateList(double minVal, double maxVal)
{
  IPropertyListPtr realList(NULL);

  if (m_curentCollection)
  {
    realList = m_curentCollection->Add(ksControlListReal);

    if (realList)
    {
      if (minVal != maxVal)
        realList->SetValueRange(_variant_t(minVal), _variant_t(maxVal));
      realList->ReadOnly = TRUE;
    }
  }

  return realList;
}


//----------------------------------------------------------------------------------------------
// Добавление комбобокса строковых значений 
// ---
IPropertyListPtr PropertyManagerObject::CreateStringList(CString matVal)
{
  IPropertyListPtr realList(NULL);

  if (m_curentCollection)
  {
    realList = m_curentCollection->Add(ksControlListStr);

    if (realList)
    {
      realList->ReadOnly = TRUE;
    }
  }

  return realList;
}


//----------------------------------------------------------------------------------------------
// Создать сепаратор
// ---
IPropertySeparatorPtr PropertyManagerObject::CreateSeparator(SeparatorTypeEnum type)
{
  IPropertySeparatorPtr rSepar(NULL);

  if (m_curentCollection)
  {
    rSepar = m_curentCollection->Add(ksControlSeparator);

    if (rSepar)
      rSepar->SeparatorType = type;
  }

  return rSepar;
}


//----------------------------------------------------------------------------------------------
// Добавление CheckBox-а 
// ---
IPropertyCheckBoxPtr PropertyManagerObject::CreateCheckBox(bool checked)
{
  IPropertyCheckBoxPtr check(NULL);

  if (m_curentCollection)
  {
    check = m_curentCollection->Add(ksControlCheckBox);

    if (check)
      check->Value = _variant_t(checked);
  }

  return check;
}


//----------------------------------------------------------------------------------------------
// Добавление SpinEdit /*Голованов Е*/
// ---
IPropertySpinEditPtr PropertyManagerObject::CreateSpinList(double minVal, double maxVal)
{
  IPropertySpinEditPtr realList(NULL);

  if (m_curentCollection)
  {
    realList = m_curentCollection->Add(ksControlSpinInt);
    if (realList)
    {
      if (minVal != maxVal)
        realList->SetValueRange(_variant_t(minVal), _variant_t(maxVal));
      realList->ReadOnly = FALSE;
    }
  }

  return realList;
}


//----------------------------------------------------------------------------------------------
// Создать набор кнопок
// ---
IPropertyMultiButtonPtr PropertyManagerObject::CreateMultiButton(ButtonTypeEnum type)
{
  IPropertyMultiButtonPtr buttons(NULL);

  if (m_curentCollection)
  {
    buttons = m_curentCollection->Add(ksControlMultiButton);

    if (buttons)
    {
      buttons->ButtonsType = type;
      buttons->ResModule = (LONG_PTR)g_hInstance;
    }
  }

  return buttons;
}


//----------------------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
void PropertyManagerObject::AddButton(IPropertyMultiButtonPtr & buttons, long btnID,
                                      bool cheched, bool enable)
{
  AddButton2(buttons, btnID, btnID, cheched, enable);
}


//----------------------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
void PropertyManagerObject::AddButton2(IPropertyMultiButtonPtr & buttons, long btnID,
                                       long bmpID, bool cheched, bool enable)
{
  if (buttons)
  {
    buttons->AddButton(btnID, _variant_t(bmpID), -1);
    buttons->ButtonEnable[btnID] = enable;
    buttons->ButtonChecked[btnID] = cheched;
    _bstr_t tmpBstr(LoadStr(btnID));
    buttons->ButtonTips[btnID] = tmpBstr;
  }
}


//----------------------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
void PropertyManagerObject::EndProcess()
{
  ABaseEvent::TerminateEvents();
}


//----------------------------------------------------------------------------------------------
// Найти контрол
// ---
IPropertyControlPtr PropertyManagerObject::GetPropertyControl(int ctrlID)
{
  IPropertyControlPtr control(NULL);

  if (m_propTabs)
    for (long i = 0, c = m_propTabs->Count; i < c && control == NULL; i++)
    {
      IPropertyTabPtr tab(m_propTabs->Item[_variant_t(i)]);
      IPropertyControlsPtr ctrls(tab ? tab->PropertyControls : NULL);

      if (ctrls)
      {
        _bstr_t name(::LoadStr(ctrlID));
        control = ctrls->Item[_variant_t(name)];
      }
    }

  return control;
}


//----------------------------------------------------------------------------------------------
// Установить доступность контрола
// ---
void PropertyManagerObject::SetControlEnable(long ctrlID, bool enabled)
{
  IPropertyControlPtr control(GetPropertyControl(ctrlID));
  if (control)
    control->Enable = enabled;
}


//----------------------------------------------------------------------------------------------
// Создание пользовательского контрола
// ---
IPropertyUserControlPtr PropertyManagerObject::CreateUserControl(long ctrlID,
                                                                 long height,
                                                                 long width)
{
  IPropertyUserControlPtr userCtrl(NULL);

  if (m_curentCollection)
  {
    userCtrl = m_curentCollection->Add(ksControlUser);

    if (userCtrl)
    {
      //       userCtrl->NameVisibility = ksNameHorizontalVisible;
      //       _bstr_t conrolID( ::LoadStr(ctrlID + 2000) );
      //       userCtrl->SetOCXControl( conrolID );
      //       conrolID = ::LoadStr( ctrlID + 2001 )
      //       userCtrl->Name   = conrolID; 
      //       userCtrl->Height = height;
      //       userCtrl->Width  = width; 
      //        
      //       new APropertyUserControlEvent( userCtrl, ctrlID, *this );
    }
  }

  return userCtrl;
}


//-------------------------------------------------------------------------------
// Контрол удаляется нужно освободить указатель
// ---
void PropertyManagerObject::OnDestroyOCX(long ctrlID)
{
  //  if ( ctrlID == IDP_HATCH_PARAM )
  //    hatchCtrl = NULL;
}


////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
PropertyManagerEvent::PropertyManagerEvent(LPDISPATCH              manager,
                                           PropertyManagerObject & obj)
  : ABaseEvent(manager, DIID_ksPropertyManagerNotify)
  , m_obj(obj)
{
  Advise();
}


//-------------------------------------------------------------------------------
//
// ---
PropertyManagerEvent::~PropertyManagerEvent()
{
}


//-------------------------------------------------------------------------------
// Карта сообщений
// ---
BEGIN_EVENTSINK_MAP(PropertyManagerEvent, ABaseEvent)
  // 1 - prButtonClick        - Нажатие кнопки.
  ON_EVENT(PropertyManagerEvent, (unsigned int)-1, prButtonClick, ButtonClick, VTS_I4)
  // 2 - prChangeControlValue - Событие изменения значения контрола
  ON_EVENT(PropertyManagerEvent, (unsigned int)-1, prChangeControlValue, ChangeControlValue, VTS_DISPATCH)
  // 3 - prControlCommand     - Нажатие кнопки контрола
  ON_EVENT(PropertyManagerEvent, (unsigned int)-1, prControlCommand, ControlCommand, VTS_DISPATCH VTS_I4)
  // 4 - prButtonUpdate       - Обновление состояния кнопки 
  ON_EVENT(PropertyManagerEvent, (unsigned int)-1, prButtonUpdate, ButtonUpdate, VTS_I4 VTS_PI4 VTS_PBOOL)
  // 5 - prProcessActivate    - Активизация процесса
  ON_EVENT(PropertyManagerEvent, (unsigned int)-1, prProcessActivate, ProcessActivate, VTS_NONE)
  // 6 - prProcessDeactivate  - Деактивизация процесса                                                                  
  ON_EVENT(PropertyManagerEvent, (unsigned int)-1, prProcessDeactivate, ProcessDeactivate, VTS_NONE)
  // 7 - prCommandHelp - Вызов справки                                                                                  
  ON_EVENT(PropertyManagerEvent, (unsigned int)-1, prCommandHelp, CommandHelp, VTS_I4)
  // 12 - prUserMenuCommand     - Нажатие кнопки контрола
  ON_EVENT(PropertyManagerEvent, (unsigned int)-1, prUserMenuCommand, UserMenuCommand, VTS_DISPATCH VTS_I4)
END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
afx_msg BOOL PropertyManagerEvent::ChangeControlValue(LPDISPATCH  iCtrl)
{
  IPropertyControlPtr control(iCtrl);

  if (control)
  {
    _variant_t v = control->Value;
    long       ctrlID = control->Id;

    //    if ( m_obj.OnChangeControlValue(ctrlID, v) )
    //      m_obj.RedrawPhantom();  
  }
  return TRUE;
}


//-------------------------------------------------------------------------------
// Получение файла помощи
// ---
void OpenHelp(int Id)
{
  //  char libHlp[260] = "";
  //  if ( ::GetFullName( LIB_HELP, libHlp, 260 ) )
  //    ::ksOpenHelpFile( libHlp, HELP_CONTEXT, Id );
}


//-----------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
BOOL PropertyManagerEvent::ButtonClick(long buttonID)
{
  return m_obj.OnButtonClick(buttonID);
}


//-----------------------------------------------------------------------------
// prControlCommand Нажатие кнопки контрола
// ---
BOOL PropertyManagerEvent::ControlCommand(LPDISPATCH ctrl, long buttonID)
{
  return m_obj.OnButtonClick(buttonID);
}


//-----------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
// ---
BOOL PropertyManagerEvent::ButtonUpdate(long buttonID, long * check,
                                        VARIANT_BOOL * enable)
{
  return TRUE;
}


//-----------------------------------------------------------------------------
// prProcessActibate     - Начало процесса.
// ---
BOOL PropertyManagerEvent::ProcessActivate()
{
  return TRUE;
}


//-----------------------------------------------------------------------------
// prProcessDeactivate   - Завершение процесса.
// ---
BOOL PropertyManagerEvent::ProcessDeactivate()
{
  return TRUE;
}


//-------------------------------------------------------------------------------
//
// ---
BOOL PropertyManagerEvent::CommandHelp(long buttonID)
{
  //  if ( !m_obj.OnCommandHelp(buttonID) )
  //    OpenHelp( buttonID );

  return TRUE;
}

BOOL PropertyManagerEvent::UserMenuCommand(LPDISPATCH ctrl, long buttonID)
{
  IPropertyControlPtr control(ctrl);

  if (control)
  {
    long ctrlID = control->Id;
    m_obj.OnControlCommand(ctrlID, buttonID);
  }

  return TRUE;
}


