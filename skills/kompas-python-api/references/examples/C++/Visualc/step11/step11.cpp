//////////////////////////////////////////////////////////////////////////////// 
// 
// step11.cpp - Пример запроса командного окна
// 
//////////////////////////////////////////////////////////////////////////////// 
#include "stdafx.h"
#include <afxdllx.h> 
#include "resource.h"

#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#ifndef __LDEFIN2D_H
#include <ldefin2d.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE StepDLL = { NULL, NULL };


//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
  UNREFERENCED_PARAMETER( lpReserved );

  if ( dwReason == DLL_PROCESS_ATTACH )
  {
    TRACE0( "DLL Initializing!" );
 
    if ( !AfxInitExtensionModule( StepDLL, hInstance ) )
      return 0;

    new CDynLinkLibrary( StepDLL );
  }
  else if ( dwReason == DLL_PROCESS_DETACH )
  {
    TRACE0( "DLL Terminating!" );
    AfxTermExtensionModule( StepDLL );
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//------------------------------------------------------------------------------
// Функция обратной связи
// ---
int WINAPI CallBackCommand( int command, RequestInfoT *info  ) 
{
  TCHAR buf[255];
  _stprintf_s( buf, _T("Выполняется команда %d"), command );
  MessageT( buf );

  // Заменяем заголовок окна в зависимости от выполненной команды
  // аналогично можно заменить и состав дерева команд
  _stprintf_s( buf, _T("Последняя выбранная команда %d"), command );
  info->title = buf;
 
  // Возвращаемый результат определяет, должна ли система продолжать запрашивать команду :
  // ( TRUE - продолжать, FALSE - завержить работу с окном )
  return command == ID_COMMAND_3 ? FALSE : TRUE;
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  // Обращаемся к системе с запросом на создание окна с деревом команд.
  // Если в качестве функции обратного вызова задан NULL, 
  // то управление из CommandWindow возвращается немедленно, 
  // как только пользователь выберет команду в дереве команд.
  // Прт этом возвращается идентификатор выбранной команды.
  // В противном случае управление вернется, если пользователь закроет окно
  // или функция обратного вызова вернет FALSE, при этом возвращается -1.
  
  // Структура параметров запроса к системе
  RequestInfoT info;
  memset( &info, 0, sizeof( info ) );
  info.commands = ( LPTSTR )ID_TREE_CONTENTS;  // Идентификатор меню с составом дерева команд
  info.title    = _T("Дерево команд");             // Заголовка окна команд
  info.callBack = CallBackCommand;             // Функции обратного вызова
 
  // Создание меню в диалоговом окне
  int command = CommandWindowT( &info );
  TCHAR buf[255];
  _stprintf_s( buf, _T("Результат выполнения ф-ии CommandWindow %d"), command );
  MessageT( buf );
}
