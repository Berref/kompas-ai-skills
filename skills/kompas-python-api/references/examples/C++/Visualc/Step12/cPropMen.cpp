////////////////////////////////////////////////////////////////////////////////
//
// Класс для работы с панелью свойств
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "resource.h"
#include "cPropMen.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern int LibMessage( LPCTSTR str, int flags = MB_OK );
extern void ClosePropertyManager( bool mes );                       // Удаление пользовательской панели

////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
PropertyManagerEvent::PropertyManagerEvent( LPDISPATCH manager ):
  ABaseEvent( manager, DIID_ksPropertyManagerNotify )
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
  ON_EVENT (PropertyManagerEvent, (unsigned int)-1,  prButtonClick,        ButtonClick,        VTS_I4 )
  // 2 - prChangeControlValue - Событие изменения значения контрола
  ON_EVENT (PropertyManagerEvent, (unsigned int)-1,  prChangeControlValue, ChangeControlValue, VTS_DISPATCH )
  // 3 - prControlCommand     - Нажатие кнопки контрола
  ON_EVENT (PropertyManagerEvent, (unsigned int)-1,  prControlCommand,     ControlCommand,     VTS_DISPATCH VTS_I4 )
  // 4 - prButtonUpdate       - Обновление состояния кнопки 
  ON_EVENT (PropertyManagerEvent, (unsigned int)-1, prButtonUpdate,        ButtonUpdate,       VTS_I4 VTS_PI4 VTS_PBOOL )
  // 5 - prProcessActivate    - Активизация процесса
  ON_EVENT (PropertyManagerEvent, (unsigned int)-1, prProcessActivate,     ProcessActivate,    VTS_NONE )  
  // 6 - prProcessDeactivate  - Деактивизация процесса
  ON_EVENT (PropertyManagerEvent, (unsigned int)-1, prProcessDeactivate,   ProcessDeactivate,  VTS_NONE )  
  // 7 - prCommandHelp - Вызов справки
  ON_EVENT ( PropertyManagerEvent, (unsigned int)-1, prCommandHelp,        CommandHelp,        VTS_I4  )
//    // 8 - prSelectItem - Селектирование элемента в списке
//    ON_EVENT ( PropertyManagerEvent, (unsigned int)-1, prSelectItem,         SelectItem
//    // 9 - prCheckItem - Выбор элемента в списке
//    ON_EVENT ( PropertyManagerEvent, (unsigned int)-1, prCheckItem,          CheckItem
END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
afx_msg BOOL PropertyManagerEvent::ChangeControlValue(LPDISPATCH  iCtrl)
{
  LibMessage( _T("PropertyManagerEvent::ChangeControlValue") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Получение файла помощи
// ---
void OpenHelp( int Id ) 
{
//  char gaykaHlp[260] = "";
//  if ( GetFullName( LIB_HELP, gaykaHlp, 260 ) )
//    ksOpenHelpFile( gaykaHlp, HELP_CONTEXT,  Id );
}


//-----------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
afx_msg BOOL PropertyManagerEvent::ButtonClick(long buttonID)
{
  if ( buttonID == pbHelp ) 
    OpenHelp( 1 );
  if ( buttonID == pbEnter || buttonID == pbEsc )
    ClosePropertyManager( false );
  return TRUE;
}

//-----------------------------------------------------------------------------
// prControlCommand Нажатие кнопки контрола
// ---
afx_msg BOOL PropertyManagerEvent::ControlCommand(LPDISPATCH ctrl, long buttonID ) {
  LibMessage( _T("PropertyManagerEvent::ControlCommand") );
  return TRUE;
}


//-----------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
// ---
afx_msg BOOL PropertyManagerEvent::ButtonUpdate( long buttonID, long* check, VARIANT_BOOL* _enable) {
  if ( check )
    *check = false;
  if ( _enable )
    *_enable = TRUE; 
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


//-----------------------------------------------------------------------------
//
// ---
afx_msg BOOL PropertyManagerEvent::CommandHelp( long buttonID )
{
  OpenHelp( 1 ); 
  return TRUE;
}


