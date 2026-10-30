////////////////////////////////////////////////////////////////////////////////
//
// Класс для работы с панелью свойств
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "resource.h"

#ifndef __CPAR_H
#include "CPar.h"
#endif

#include <COMUTIL.H>
#include <comdef.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE * pModuleState;

extern ksAPI7::IApplicationPtr newKompasAPI;


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage(const std::wstring & str, int flags) {
  int res = 0;

  if (!str.empty() && newKompasAPI)                    // строка передана    
    //                         текст сообщения  заголовок          параметры
    res = newKompasAPI->MessageBoxEx(str.c_str(), LoadStr(ID_LIBID), flags);

  return res;
}


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage(int strId, int flags)
{
  return ::LibMessage(LoadStr(strId), flags);
}


//------------------------------------------------------------------------------
// Вспомогательная функция, возвращающая информацию об ошибке
// ---
void DumpError(_com_error & e)
{
  CString str;
  str.Format(LoadStr(IDS_COM_ERROR), e.Error(),
             e.ErrorMessage(),
             e.Source(),
             e.Description());
  LibMessage(str.GetString(), MB_OK | MB_ICONERROR);
}


/*
//------------------------------------------------------------------------------
// Вспомогательная функция, возвращающая информацию об ошибке
// ---
void ShowError()
{
  IErrorInfoPtr ef;
  GetErrorInfo( NULL, &ef );
  BSTR                bstrDescription;
  ef->GetDescription( &bstrDescription );
  USES_CONVERSION;
  LibMessage( OLE2T(bstrDescription), MB_OK | MB_ICONERROR );
}
*/


//-------------------------------------------------------------------------------
// Освободить Application
// ---
void App7NULL() {
  ABaseEvent::DestroyList(); // Удалить список подписчиков
  if (newKompasAPI)
    newKompasAPI = nullptr;     // Освободить Компас
}

//----------------------------------------------------------------------------------------------
// Конструктор
// ---
PropertyManagerObject::PropertyManagerObject()
  : procParam()  // Параметры процесса
  , propTabs()  // Коллекция закладок
  , curentCollection()  // Коллекция контролов 
  , angleEdit()  // Контрол - параметры штриховки
  , stepEdit()  // Контрол - параметры штриховки
  , paramGrid()  // Грид для вывода дополнительных параметров элемента 
  , slideBox()  // Окно просмотра 
  , rowIndex(0) // Индекс строки
  , flagMode(0)
{
}

//----------------------------------------------------------------------------------------------
// Деструктор
// ---
PropertyManagerObject::~PropertyManagerObject()
{
  angleEdit = nullptr;  // Контрол - параметры штриховки
  stepEdit = nullptr;  // Контрол - параметры штриховки
  paramGrid = nullptr;  // Грид для вывода дополнительных параметров элемента 
  slideBox = nullptr;  // Окно просмотра 
  curentCollection = nullptr;  // Коллекция контролов 
  propTabs = nullptr;  // Коллекция закладок
  procParam = nullptr;  // Параметры процесса
  rowIndex = 0;  // Индекс строки
}

//----------------------------------------------------------------------------------------------
// Инициализация параметров процесса
// ---
bool PropertyManagerObject::InitProcessParam(long toolBarID, SpecPropertyToolBarEnum toolBarType, long firstTabID)
{
  bool res = false;
  if (newKompasAPI) {
    try {

      procParam = newKompasAPI->CreateProcessParam();                 // Получаем параметры процесса
      if (procParam) {
        new PropertyManagerEvent(procParam, *this);                 // Подписываемся на события процесса
        // Получаем интерфейс панели свойств
        procParam->SpecToolbar = toolBarType;                         // Тип кнопок на панели свойств
        _bstr_t tmpBstr(::LoadStr(toolBarID));
        procParam->Caption = tmpBstr;                              // Устанавливаем заголовок панели свойств
        procParam->AutoReduce = !flagMode;                            // Автосоздание объекта

        if (flagMode) {
          procParam->DefaultControlFix = ksAllFix;
        }

        // Получаем коллекцию закладок панели свойств
        propTabs = procParam->PropertyTabs;

        // Создаем закладку параметров элемента
        if (firstTabID) {
          CreateTab(firstTabID, TRUE, TRUE);
          // Наполнение закладки контролами для вывода параметров элемента
          ShowControls();
          // Создать окно просмотра
          // Отрисовка группы в окне просмотра
          reference gr = GetPreviewGroup();
          if (gr)
          {
            CreatePropertyGroup();
            slideBox = curentCollection->Add(ksControlSlideBox);
            slideBox->SlideType = ksGroup;                       // Отрисовываем группу
            slideBox->DrawingSlide = _variant_t(gr);                // Передаем reference группы
            slideBox->Hint = ::LoadStr(IDS_HINT_SLIDEBOX);
            slideBox->Tips = ::LoadStr(IDS_TIPS_SLIDEBOX);
            slideBox->Id = 10000;
            slideBox->Name = ::LoadStr(IDS_SLIDEBOX);
            slideBox->NameVisibility = ksNameHorizontalVisible;
          }
        }

        int  paramCount = ParamCount();                               // Нужно ли выводить грид?
        if (paramCount || IsHatchObject()) {
          CreateTab(IDP_ELEMENT_PARAM);                             // Грид будем создавать на новой закладке
          if (IsHatchObject()) {
            ShowHatchControl();
          }

          if (paramCount) {
            // Создание грида
            paramGrid = curentCollection->Add(ksControlParamGrid);
            if (paramGrid) {
              paramGrid->InitColumn(0, ::LoadStr(IDS_PARAM_CAPTION), "", FALSE);
              paramGrid->InitColumn(1, ::LoadStr(IDS_VALUE_CAPTION), "", FALSE);
              paramGrid->ColumnCount = 2;
              paramGrid->RowCount = paramCount + 1;           // Количество отображаемых строк в гриде
              // paramGrid->AutoSizeColumns = TRUE;                     // Автоматически изменять ширину колонок
              paramGrid->Hint = ::LoadStr(IDS_HINT_GRID);
              paramGrid->Tips = ::LoadStr(IDS_TIPS_GRID);
              paramGrid->Id = 10001;
              paramGrid->Name = ::LoadStr(IDP_ELEMENT_PARAM);
              paramGrid->NameVisibility = ksNameHorizontalVisible;
              // Выводим надписи
              rowIndex = 0;                                           // Индекс строки

              //AddStringToGrig(IDS_PARAM_CAPTION, ::LoadStr(IDS_VALUE_CAPTION));
              ShowParam();                                            // Вывод параметров в гриде
              // paramGrid->Height = rowIndex * 20;
              paramGrid->RowCount = rowIndex;
            }
          }
        }
        res = true;
      }
    }

    // Перехват исключений
    catch (_com_error & e)
    {
      DumpError(e);                            // Вывод сообщений о ошибке
    }

    catch (TCHAR * mes) {
      LibMessage(mes, MB_ICONERROR | MB_OK); // Вывод сообщений о ошибке
    }
  }
  return res;
}


//----------------------------------------------------------------------------------------------
// Добавить параметр в грид
// ---
void PropertyManagerObject::AddStringToGrig(long paramID, LPCTSTR value) {
  if (paramGrid) {
    paramGrid->CellValue[rowIndex][1] = _bstr_t(value);
    paramGrid->CellValue[rowIndex++][0] = _bstr_t(LoadStr(paramID)); // Не переставлять так задумано
  }
}

//----------------------------------------------------------------------------------------------
// Перевод значения в строку
// ---
const char * DoubleToStr(double value)
{
  static char res[20];
  sprintf_s(res, "%g", value);
  return res;
}

//----------------------------------------------------------------------------------------------
// Добавить параметр в грид
// ---
void PropertyManagerObject::AddDoubleToGrig(long paramID, double value) {
  if (paramGrid) {
    paramGrid->CellValue[rowIndex][1] = _bstr_t(DoubleToStr(value));  // Выводим значение
    paramGrid->CellValue[rowIndex++][0] = _bstr_t(LoadStr(paramID));  // Имя параметра
  }
}

//----------------------------------------------------------------------------------------------
// Создать закладку
// ---
bool PropertyManagerObject::CreateTab(long tabID, BOOL visible, BOOL active)
{
  bool res = false;
  if (tabID) {
    if (propTabs) {
      _bstr_t tmpBstr(LoadStr(tabID));
      ksAPI7::IPropertyTabPtr propTab = propTabs->Add(tmpBstr);
      if (propTab) {
        curentCollection = propTab->PropertyControls;
        if (!visible)
          propTab->Visible = visible;
        propTab->Image = tabID;
        propTab->ResModule = (LONG_PTR)StepDLL.hModule;
        propTab->Active = active;
        res = true;
      }
    }
  }
  return res;
}

//----------------------------------------------------------------------------------------------
// Создать комбобокс
// ---
void  PropertyManagerObject::InitPropertyControl(ksAPI7::IPropertyControl * control, long ctrlID, UINT hint, UINT tips,
                                                 BOOL enable, PropertyControlNameVisibility nameVisibility,
                                                 BOOL visible) {
  if (control) {
    _bstr_t tmpBstr(::LoadStr(ctrlID));
    control->Name = tmpBstr;
    control->Id = ctrlID;
    tmpBstr = hint ? ::LoadStr(hint) : _T("");
    control->Hint = tmpBstr;
    tmpBstr = tips ? ::LoadStr(tips) : _T("");
    control->Tips = tmpBstr;
    control->Enable = enable;
    control->Visible = visible;
    control->NameVisibility = nameVisibility;
  }
}

//----------------------------------------------------------------------------------------------
// Создать комбобокс
// ---
ksAPI7::IPropertyListPtr PropertyManagerObject::CreateList(double minVal, double maxVal)
{

  ksAPI7::IPropertyListPtr realList(NULL);
  if (curentCollection) {
    realList = curentCollection->Add(ksControlListReal);
    if (realList) {
      if (minVal != maxVal)
        realList->SetValueRange(_variant_t(minVal), _variant_t(maxVal));
      realList->ReadOnly = TRUE;
    }
  }

  return realList;
}

//----------------------------------------------------------------------------------------------
// Создать сепаратор
// ---
ksAPI7::IPropertySeparatorPtr PropertyManagerObject::CreateSeparator(SeparatorTypeEnum type) {
  ksAPI7::IPropertySeparatorPtr rSepar(NULL);
  if (curentCollection) {
    rSepar = curentCollection->Add(ksControlSeparator);
    if (rSepar) {
      rSepar->SeparatorType = type;
    }
  }
  return rSepar;
}

//----------------------------------------------------------------------------------------------
// Добавление CheckBox-а 
// ---
ksAPI7::IPropertyCheckBoxPtr PropertyManagerObject::CreateCheckBox(bool checked) {
  ksAPI7::IPropertyCheckBoxPtr check(NULL);
  if (curentCollection) {
    check = curentCollection->Add(ksControlCheckBox);
    if (check) {
      check->Value = _variant_t(checked);
    }
  }
  return check;
}

//----------------------------------------------------------------------------------------------
// Создать набор кнопок
// ---
ksAPI7::IPropertyMultiButtonPtr PropertyManagerObject::CreateMultiButton(ButtonTypeEnum type)
{
  ksAPI7::IPropertyMultiButtonPtr buttons(NULL);
  if (curentCollection) {
    buttons = curentCollection->Add(ksControlMultiButton);
    if (buttons) {
      buttons->ButtonsType = type;
      //buttons->ResModule   = (LONG_PTR)StepDLL.hModule;
    }
  }
  return buttons;
}

//--------------------------------------------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
void PropertyManagerObject::AddButton(ksAPI7::IPropertyMultiButtonPtr & buttons, long btnID, bool cheched, bool enable)
{
  AddButton2(buttons, btnID, btnID, cheched, enable);
}

//----------------------------------------------------------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
void PropertyManagerObject::AddButton2(ksAPI7::IPropertyMultiButtonPtr & buttons, long btnID, long bmpID, bool cheched, bool enable)
{
  if (buttons) {
    buttons->AddButton(btnID, _variant_t(bmpID), -1);
    buttons->ButtonEnable[btnID] = enable;
    buttons->ButtonChecked[btnID] = cheched;
    _bstr_t tmpBstr(LoadStr(btnID));
    //           buttons->ButtonHint   [ btnID ] = tmpBstr;
    buttons->ButtonTips[btnID] = tmpBstr;
    buttons->ButtonIconFont[btnID] = GetLibraryIconFont();
  }
}

//----------------------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
BOOL PropertyManagerObject::EndProcess()
{
  UnadviseEvents();
  return TRUE;
}

void PropertyManagerObject::UnadviseEvents()
{
  ABaseEvent::TerminateEvents(stepEdit);
  ABaseEvent::TerminateEvents(angleEdit);
  ABaseEvent::TerminateEvents(procParam);
}


//----------------------------------------------------------------------------------------------
// Найти контрол
// ---
ksAPI7::IPropertyControlPtr PropertyManagerObject::GetPropertyControl(int ctrlID)
{
  ksAPI7::IPropertyControlPtr control(NULL);
  if (propTabs)
  {
    for (long i = 0, c = propTabs->Count; i < c && control == NULL; i++)
    {
      ksAPI7::IPropertyTabPtr tab(propTabs->Item[_variant_t(i)]);
      ksAPI7::IPropertyControlsPtr ctrls(tab ? tab->PropertyControls : NULL);
      if (ctrls)
      {
        _bstr_t name(LoadStr(ctrlID));
        control = ctrls->Item[_variant_t(name)];
      }
    }
  }
  return control;
}


//----------------------------------------------------------------------------------------------
// Установить доступность контрола
// ---
void PropertyManagerObject::SetControlEnable(long ctrlID, bool enabled)
{
  ksAPI7::IPropertyControlPtr control(GetPropertyControl(ctrlID));
  if (control)
    control->Enable = enabled;
}

////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
PropertyManagerEvent::PropertyManagerEvent(LPDISPATCH manager, PropertyManagerObject & _obj) :
  ABaseEvent(manager, ksAPI7::DIID_ksPropertyManagerNotify)
  , obj(_obj)
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
END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
afx_msg BOOL PropertyManagerEvent::ChangeControlValue(LPDISPATCH  iCtrl)
{
  ksAPI7::IPropertyControlPtr control(iCtrl);
  if (control) {
    _variant_t v = control->Value;
    long       ctrlID = control->Id;
    if (obj.OnChangeControlValue(ctrlID, v)) {
      obj.Draw1();
      obj.RedrawPhantom();
    }
  }
  return TRUE;
}




//-----------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
afx_msg BOOL PropertyManagerEvent::ButtonClick(long buttonID)
{
  if (buttonID == pbHelp)
    OpenHelp(obj.GetCommand());
  else
    if (obj.OnButtonClick(buttonID))
      obj.RedrawPhantom();
  return TRUE;
}

//-----------------------------------------------------------------------------
// prControlCommand Нажатие кнопки контрола
// ---
afx_msg BOOL PropertyManagerEvent::ControlCommand(LPDISPATCH ctrl, long buttonID) {
  if (obj.OnButtonClick(buttonID))
    obj.RedrawPhantom();
  return TRUE;
}


//-----------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
// ---
afx_msg BOOL PropertyManagerEvent::ButtonUpdate(long buttonID, long * check, VARIANT_BOOL * _enable) {
  return TRUE;
}

//-----------------------------------------------------------------------------
// prProcessActibate     - Начало процесса.
// ---
afx_msg BOOL PropertyManagerEvent::ProcessActivate() {
  return TRUE;
}

//-----------------------------------------------------------------------------
// prProcessDeactivate   - Завершение процесса.
// ---
afx_msg BOOL PropertyManagerEvent::ProcessDeactivate() {
  return TRUE;
}


afx_msg BOOL PropertyManagerEvent::CommandHelp(long buttonID)
{
  OpenHelp(obj.GetCommand()); // buttonID );
  return TRUE;
}



////////////////////////////////////////////////////////////////////////////////
//
// Process2DEvent - обработчик событий от процесса 2D
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
Process2DEvent::Process2DEvent(const ksAPI7::IProcess2DPtr & process, PropertyManagerObject & _obj, bool ownObj)
  : ABaseEvent(process, ksAPI7::DIID_ksProcess2DNotify)
  , m_obj(_obj)
  , m_ownObj(ownObj)
{
  Advise();
}


//----------------------------------
// Деструктор
// ---
Process2DEvent::~Process2DEvent()
{
  if (m_ownObj)
    delete & m_obj;
}


//-------------------------------------------------------------------------------------
// ksPlacementChanged    -Изменено положения объекта
// ---
BOOL Process2DEvent::PlacementChanged(double x, double y, double angle, BOOL dynamic)
{
  m_obj.PlacementChanged(x, y, angle, dynamic);
  return true;
}


//--------------------------------------
// ksStop     -Остановка процесса
// ---
BOOL Process2DEvent::Stop()
{
  return TRUE;
}


//-----------------------------------------
// ksProcessActivate    - Начало процесса  
// ---
BOOL Process2DEvent::ProcessActivate()
{
  return TRUE;
}


//--------------------------------------------
// ksProcessDeactivate   - Завершение процесса
// ---
BOOL Process2DEvent::ProcessDeactivate()
{
  return TRUE;
}


//--------------------------------------
// ksStop     -Запуск процесса
// ---
BOOL Process2DEvent::Run()
{
  return TRUE;
}


//--------------------------------------
// ksEndProcess    -Окончание процесса.
// ---
BOOL Process2DEvent::EndProcess()
{
  // Завершение процесса
  if (m_obj.EndProcess())
    // Отписка от получения событий
    Disconnect();
  return TRUE;
}


//--------------------------------------------------------------------------------------------------------------------------
// Карта сообщений
// ---
BEGIN_EVENTSINK_MAP(Process2DEvent, ABaseEvent)
  ON_EVENT(Process2DEvent, (unsigned int)-1, ksProcess2DPlacementChanged, PlacementChanged, VTS_R8 VTS_R8 VTS_R8 VTS_BOOL)
  ON_EVENT(Process2DEvent, (unsigned int)-1, ksProcess2DStop, Stop, VTS_NONE)
  ON_EVENT(Process2DEvent, (unsigned int)-1, ksProcess2DActivate, ProcessActivate, VTS_NONE)
  ON_EVENT(Process2DEvent, (unsigned int)-1, ksProcess2DDeactivate, ProcessDeactivate, VTS_NONE)
  ON_EVENT(Process2DEvent, (unsigned int)-1, ksProcess2DRun, ProcessActivate, VTS_NONE)
  ON_EVENT(Process2DEvent, (unsigned int)-1, ksProcess2DEndProcess, EndProcess, VTS_NONE)
END_EVENTSINK_MAP()

