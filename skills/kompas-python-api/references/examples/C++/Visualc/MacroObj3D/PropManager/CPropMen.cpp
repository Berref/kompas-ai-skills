////////////////////////////////////////////////////////////////////////////////
//
// cPropMen.cpp - Класс для работы с панелью свойств
//
////////////////////////////////////////////////////////////////////////////////
#include "StdAfx.h"

#include "cPropMen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE* pModuleState;
extern HINSTANCE g_hInstance;
extern ksAPI7::IApplicationPtr appl;

CRect g_Rect( 20, 20, 270, 320 ); // Размер

//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( LPCTSTR str, int flags ) 
{
  int res = 0;
  
  if ( str && str[0] )                    // строка передана    
  {                  
    int enabse = ::IsEnableTaskAccess();  // проверка доступа
    if ( enabse )                         // если доступ к задаче разрешен
      ::EnableTaskAccess(0);              // запрещаем доступ
    
    //                         текст сообщения  заголовок          параметры
    res = MessageBox( (HWND) GetHWindow(), str, LoadStr(IDR_LIBID), flags );
    
    if ( enabse )                         // если доступ к задаче был запрещен
      ::EnableTaskAccess(1);              // разрешаем доступ к задаче
  }
  return res;
}


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( int strId, int flags ) {
  return ::LibMessage( LoadStr(strId), flags );
}


//------------------------------------------------------------------------------
// Вспомогательная функция, возвращающая информацию об ошибке
// ---
void DumpError(_com_error& e)
{
  _bstr_t bstrSource(e.Source());
  _bstr_t bstrDescription(e.Description());
  CString str;
  str.Format(_T("Error = %08lx"),   e.Error());
  str += _T("\nMessage     :"); str += e.ErrorMessage();
  str += _T("\nSource      :"); str += (LPCTSTR)bstrSource;
  str += _T("\nDescription :"); str += (LPCTSTR)bstrDescription;
  ::LibMessage( str, MB_OK | MB_ICONERROR);  
}

//-------------------------------------------------------------------------------
// Получение файла помощи
// ---
void OpenHelp(int Id)
{

}


//----------------------------------------------------------------------------------------------
// Перевод значения в строку
// ---
const TCHAR * DoubleToStr(double value)
{
  static TCHAR res[20];
  ::_stprintf_s(res, _T("%g"), value);
  return res;
}


//----------------------------------------------------------------------------------------------
// Конструктор
// ---
PropertyManagerObject::PropertyManagerObject() 
  : m_rowIndex         ( 0    )  // Индекс строки
  , m_flagMode         ( 0    )
  , m_objectIndex      ( 0    )
{
}

//----------------------------------------------------------------------------------------------
// Деструктор
// ---
PropertyManagerObject::~PropertyManagerObject() 
{  
  m_paramGrid        = NULL;  // Грид для вывода дополнительных параметров элемента 
  m_slideBox         = NULL;  // Окно просмотра 
  m_curentCollection = NULL;  // Коллекция контролов 
  m_propTabs         = NULL;  // Коллекция закладок
  m_procParam        = NULL;  // Параметры процесса
  m_rowIndex         =    0;  // Индекс строки
} 

//----------------------------------------------------------------------------------------------
// Установить параметры Сontrol'а
// ---
void PropertyManagerObject::InitPropertyControl(ksAPI7::IPropertyControl * control, long ctrlID,
                                                UINT hint, UINT tips, BOOL enable,
                                                PropertyControlNameVisibility nameVisibility, BOOL visible)
{
  if (control)
  {
    _bstr_t tmpBstr(LoadStr(ctrlID));
    control->Name = tmpBstr;
    control->Id = ctrlID;
    tmpBstr = hint ? LoadStr(hint) : _T("");
    control->Hint = tmpBstr;
    tmpBstr = tips ? LoadStr(tips) : _T("");
    control->Tips = tmpBstr;
    control->Enable = enable;
    control->Visible = visible;
    control->NameVisibility = nameVisibility;
  }
}

//-------------------------------------------------------------------------------
// Создать Сontrol заданного типа
// ---
ksAPI7::IPropertyControlPtr PropertyManagerObject::CreateControl(ControlTypeEnum conType)
{
  ksAPI7::IPropertyControlPtr control(NULL);
  if (m_curentCollection)
  {
    control = m_curentCollection->Add(conType);
  }
  return control;
}


//----------------------------------------------------------------------------------------------
// Найти контрол
// ---
ksAPI7::IPropertyControlPtr PropertyManagerObject::GetPropertyControl(long ctrlID)
{
  ksAPI7::IPropertyControlPtr control(NULL);
  ksAPI7::IPropertyTabsPtr tabs( /*m_propMng ? m_propMng->PropertyTabs :*/ m_procParam ? m_procParam->PropertyTabs : NULL);
  if (tabs)
    for (long i = 0, c = tabs->Count; i < c && control == NULL; i++)
    {
      ksAPI7::IPropertyTabPtr tab(tabs->Item[_variant_t(i)]);
      ksAPI7::IPropertyControlsPtr ctrls(tab ? tab->PropertyControls : NULL);

      if (ctrls)
      {
        _bstr_t name(::LoadStr(ctrlID));
        control = ctrls->Item[_variant_t(name)];
      }
    }

  return control;
}


//----------------------------------------------------------------------------------------------
// Создание пользовательского контрола
// ---
ksAPI7::IPropertyUserControlPtr PropertyManagerObject::CreateUserControl(long ctrlID,
                                                                         long height,
                                                                         long width)
{
  ksAPI7::IPropertyUserControlPtr userCtrl(NULL);

  if (m_curentCollection)
  {
    userCtrl = m_curentCollection->Add(ksControlUser);

    if (userCtrl)
    {

    }
  }
  return userCtrl;
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
      ksAPI7::IPropertyTabPtr propTab = m_propTabs->Add(tmpBstr);

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
ksAPI7::IPropertyListPtr PropertyManagerObject::CreateList(double minVal, double maxVal)
{
  ksAPI7::IPropertyListPtr realList(NULL);

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
// Создать едит вещественных значений
// ---
ksAPI7::IPropertyEditPtr PropertyManagerObject::CreateEditReal(double minVal, double maxVal)
{
  ksAPI7::IPropertyEditPtr realEdit(NULL);

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
// Добавление SpinEdit /*Голованов Е*/
// ---
ksAPI7::IPropertySpinEditPtr PropertyManagerObject::CreateSpinList(double minVal, double maxVal)
{
  ksAPI7::IPropertySpinEditPtr realList(NULL);

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
// Создать сепаратор
// ---
ksAPI7::IPropertySeparatorPtr PropertyManagerObject::CreateSeparator(SeparatorTypeEnum type)
{
  ksAPI7::IPropertySeparatorPtr rSepar(NULL);

  if (m_curentCollection)
  {
    rSepar = m_curentCollection->Add(ksControlSeparator);

    if (rSepar)
      rSepar->SeparatorType = type;
  }

  return rSepar;
}


//----------------------------------------------------------------------------------------------
// Добавление комбобокса строковых значений 
// ---
ksAPI7::IPropertyListPtr PropertyManagerObject::CreateStringList(CString matVal)
{
  ksAPI7::IPropertyListPtr realList(NULL);

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
// Добавление CheckBox-а 
// ---
ksAPI7::IPropertyCheckBoxPtr PropertyManagerObject::CreateCheckBox(bool checked)
{
  ksAPI7::IPropertyCheckBoxPtr check(NULL);

  if (m_curentCollection)
  {
    check = m_curentCollection->Add(ksControlCheckBox);

    if (check)
      check->Value = _variant_t(checked);
  }

  return check;
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

//------------------------------------------------------------------------------
// Инициализация параметров процесса 
// ---
bool PropertyManagerObject::InitProcessParam()
{
  bool res = true;
  if ( m_procParam == NULL )
  {
    res = false;
    // Подписываемся на события приложения
    NewApplicationEvent();

    // Создаем панель свойств
    m_procParam = appl->CreateProcessParam();
    m_procParam->AutoReduce = false;
    m_procParam->Caption = _bstr_t(LoadStr(IDS_CAPTION));
    m_procParam->SpecToolbar = pnEnterEscHelp;
    m_procParam->EnableUndoRedo = true;
    // Подписываемся на события панели свойств 
    new PropertyManagerEvent(m_procParam, *this);

    ksAPI7::IPropertyTabsPtr tabs(m_procParam->PropertyTabs);
    if (tabs)
    {
      //Добавляем закладку
      ksAPI7::IPropertyTabPtr tab(tabs->Add(_bstr_t(LoadStr(IDS_TAB_NAME))));
      if (tab)
      {
        // Получаем коллекцию контролов
        m_curentCollection = tab->PropertyControls;
        ShowControls();
        res = true;
      }
    }
  }

  return res;
}

// Завершить процесс редактирования
void PropertyManagerObject::EndProcess()
{
  // Отписываемся от событий
  ABaseEvent::TerminateEvents(GUID_NULL, m_procParam);
}


//-------------------------------------------------------------------------------
//
// ---
BOOL PropertyManagerObject::CommandHelp(long buttonID)
{
  OpenHelp(0);

  return TRUE;
}

////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
PropertyManagerEvent::PropertyManagerEvent( LPDISPATCH              manager, 
                                            PropertyManagerObject & obj )
  : ABaseEvent( manager, ksAPI7::DIID_ksPropertyManagerNotify )
  , m_obj( obj )
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
BEGIN_EVENTSINK_MAP( PropertyManagerEvent, ABaseEvent )
  // 1 - prButtonClick        - Нажатие кнопки.
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prButtonClick,        ButtonClick,        VTS_I4                   )
  // 2 - prChangeControlValue - Событие изменения значения контрола
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prChangeControlValue, ChangeControlValue, VTS_DISPATCH             )
  // 3 - prControlCommand     - Нажатие кнопки контрола
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prControlCommand,     ControlCommand,     VTS_DISPATCH VTS_I4      )
  // 4 - prButtonUpdate       - Обновление состояния кнопки 
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prButtonUpdate,       ButtonUpdate,       VTS_I4 VTS_PI4 VTS_PBOOL )
  // 5 - prProcessActivate    - Активизация процесса
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prProcessActivate,    ProcessActivate,    VTS_NONE                 )  
  // 6 - prProcessDeactivate  - Деактивизация процесса                                                                  
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prProcessDeactivate,  ProcessDeactivate,  VTS_NONE                 )  
  // 7 - prCommandHelp - Вызов справки                                                                                  
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prCommandHelp,        CommandHelp,        VTS_I4                   )
  // 8 - prGetContextMenuType  - Получения типа контекстного меню
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prGetContextMenuType, GetContextMenuType, VTS_I4 VTS_I4 VTS_PI4    )
  // 9 - prFillContextPanel  -  Накачка контекстной панели 
  ON_EVENT( PropertyManagerEvent, (unsigned int)-1, prFillContextPanel,   FillContextPanel,   VTS_DISPATCH             )        

END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
afx_msg BOOL PropertyManagerEvent::ChangeControlValue( LPDISPATCH  iCtrl )
{
  ksAPI7::IPropertyControlPtr control(iCtrl);

  if (control)
  {
    _variant_t v = control->Value;
    long       ctrlID = control->Id;
    m_obj.OnChangeControlValue(ctrlID, v);
  }
  return TRUE;
}


//-----------------------------------------------------------------------------
//
// ---
void ExecuteLibCommand( int command )
{
  if ( ::ReturnResult() )
    ::MessageBoxResult();
  
  ksAPI7::ILibraryManagerPtr      manager( appl  ? appl->LibraryManager                       : NULL );
  ksAPI7::IProceduresLibrariesPtr coll   ( manager ? manager->ProceduresLibraries                 : NULL );
  ksAPI7::IProceduresLibraryPtr   lib    ( coll    ? coll->Item[_variant_t(::LoadStr( IDR_LIBID ))]: NULL );
  
  if ( lib )
    lib->Execute( command, NULL, TRUE/*post*/ );
}


//-----------------------------------------------------------------------------
// prControlCommand     - Нажатие кнопки контрола
// ---
BOOL PropertyManagerEvent::ControlCommand(LPDISPATCH ctrl, long buttonID)
{

  return m_obj.ControlCommand(ctrl, buttonID);
}


//-----------------------------------------------------------------------------
// prButtonUpdate        -Установка состояния кнопки спецпанели.
// ---
BOOL PropertyManagerEvent::ButtonUpdate(long buttonID, long * check,
                                        VARIANT_BOOL * enable) {

  return m_obj.ButtonUpdate(buttonID, check, enable);
}


//------------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
BOOL PropertyManagerEvent::ButtonClick(long buttonID)
{
  return m_obj.ButtonClick(buttonID);
}

//-------------------------------------------------------------------------------
//prCommandHelp   - Установка состояния кнопки спецпанели
// ---
BOOL PropertyManagerEvent::CommandHelp(long buttonID)
{
  return m_obj.CommandHelp(buttonID);
}


//-----------------------------------------------------------------------------
// prProcessActivate     - Начало процесса.
// ---
BOOL PropertyManagerEvent::ProcessActivate() 
{
  return m_obj.ProcessActivate();
}


//-----------------------------------------------------------------------------
// prProcessDeactivate   - Завершение процесса.
// ---
BOOL PropertyManagerEvent::ProcessDeactivate() 
{
  return m_obj.ProcessDeactivate();
}


//-----------------------------------------------------------------------------
// prFillContextPanel  -  Накачка контекстной панели 
// ---
BOOL PropertyManagerEvent::FillContextPanel(LPDISPATCH ContextPanel)
{
  
  return m_obj.FillContextPanel(ContextPanel);

}


//-----------------------------------------------------------------------------
// prGetContextMenuType  - Получения типа контекстного меню 
// ---
BOOL PropertyManagerEvent::GetContextMenuType(long LX, long LY, long * ContextMenuType)
{

  return m_obj.GetContextMenuType(LX, LY, ContextMenuType);

}


////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обработчик событий от процесса 3D
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
Process3DEvent::Process3DEvent(const ksAPI7::IProcess3DPtr& process,
  PropertyManagerObject& _obj, bool copyProc) : ABaseEvent(process, ksAPI7::DIID_ksProcess3DNotify)
  ,m_obj(_obj)
{
  Advise();
}


//----------------------------------
// Деструктор
// ---
Process3DEvent::~Process3DEvent()
{
}


//-------------------------------------------------------------------------------
// Карта сообщений
// ---
BEGIN_EVENTSINK_MAP(Process3DEvent, ABaseEvent)
  // 1 -- ksExecuteCommand - Выполнить команду меню
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DExecuteCommand  , ExecuteCommand   , VTS_I4)
  // 2 -- prFilterProc - Фильтрация объектов
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DFilterObjects   , FilterProc       , VTS_DISPATCH)
  // 3 -- prPlacementChanged - Изменено положения объекта
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DPlacementChanged, PlacementChanged , VTS_DISPATCH)
  // 4 -- prEndProcess     -Остановка процесса
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DStop            , Stop             , VTS_NONE)
  // 5 -- prProcessActivate    - Начало процесса
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DRun             , ProcessRun  , VTS_NONE)
  // 6 -- prProcessActivate    - Начало процесса
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DActivate        , ProcessActivate  , VTS_NONE)
  // 7 -- prProcessDeactivate   - Завершение процесса
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DDeactivate      , ProcessDeactivate, VTS_NONE)
  // 8 -- prEndProcess    -Окончание процесса.
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DEndProcess      , EndProcess       , VTS_NONE)
  // 9 -- prCreateTakeObject    -Создание объекта в подпроцессе
  ON_EVENT(Process3DEvent, (unsigned int)-1, ksProcess3DCreateTakeObject, CreateTakeObject , VTS_UNKNOWN)
END_EVENTSINK_MAP()


//-----------------------------------------------
// ksExecuteCommand - Выполнить команду меню.
// ---
BOOL Process3DEvent::ExecuteCommand( long command )
{
  return m_obj.ButtonClick( command );
}


//---------------------------------------------------------------
// ksFilterProc    -Фильтрация объектов
// ---
BOOL Process3DEvent::FilterProc(LPDISPATCH object)
{
  return m_obj.FilterProc( object );
}


//----------------------------------------------------------------
// ksCreateTakeObject    -Создание объекта в подпроцессе
// ---
BOOL Process3DEvent::CreateTakeObject(LPUNKNOWN object)
{
  return FALSE;
}


//-----------------------------------------
// ksProcessActivate    - Начало процесса  
// ---
BOOL Process3DEvent::ProcessActivate()
{
  return m_obj.ProcessActivate();
}

//-----------------------------------------
// ksProcessRun    - Начало процесса  
// ---
BOOL Process3DEvent::ProcessRun()
{
  return m_obj.ProcessRun();
}


//--------------------------------------------
// ksProcessDeactivate   - Завершение процесса
// ---
BOOL Process3DEvent::ProcessDeactivate()
{
  return m_obj.ProcessDeactivate();
}


//--------------------------------------
// ksStop     -Остановка процесса
// ---
BOOL Process3DEvent::Stop()
{
  return TRUE;
}


//---------------------------------------------------------
// ksPlacementChanged    -Изменено положения объекта
// ---
BOOL Process3DEvent::PlacementChanged(LPDISPATCH object)
{
  return m_obj.PlacementChanged( object );
}


//--------------------------------------
// ksEndProcess    -Окончание процесса.
// ---
BOOL Process3DEvent::EndProcess()
{
  // Завершение процесса
  m_obj.EndProcess();
  // Отписка от получения событий
  Unadvise();
  delete &m_obj;
  return TRUE;
}

