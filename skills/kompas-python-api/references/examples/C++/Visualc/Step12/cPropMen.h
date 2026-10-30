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

//-------------------------------------------------------------------------------
// Функции для выдачи сообщений библиотеки
// ---
int LibMessage( int     strId, int flags ); // Сообщение загружается из ресурсов
int LibMessage( LPCTSTR str,   int flags ); // Сообщение передается строкой 
 
// Для перехвата COM исключений
void DumpError(_com_error& e);              // Вывод текста исключения 
void ShowError();                           // Вывод сообщений при самостоятельном анализе HRESULT 

////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обрабокчик событий от менеджера панели свойств
//
////////////////////////////////////////////////////////////////////////////////
class PropertyManagerEvent : public ABaseEvent
{

protected:
  // Attributes
public:
	PropertyManagerEvent( LPDISPATCH manager );           
  virtual ~PropertyManagerEvent();

// Operations
public:

  // prButtonClick        - Нажатие кнопки.  "Создался OCX контрол."
  afx_msg BOOL ButtonClick( long buttonID );
  
  // prChangeControlValue - "Удаляется OCX контрол."
  afx_msg BOOL ChangeControlValue( LPDISPATCH ctrl );

  // prControlCommand     - Нажатие кнопки контрола
  afx_msg BOOL ControlCommand( LPDISPATCH  ctrl, long buttonID );

  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  afx_msg BOOL ButtonUpdate ( long buttonID, long* check, VARIANT_BOOL* _enable);

// prProcessActivate    - Начало процесса	
  afx_msg BOOL ProcessActivate();

// prProcessDeactivate  - Завершение процесса
  afx_msg BOOL ProcessDeactivate();

// prCommandHelp        - Установка состояния кнопки спецпанели.
  afx_msg BOOL CommandHelp( long buttonID );

  DECLARE_EVENTSINK_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
