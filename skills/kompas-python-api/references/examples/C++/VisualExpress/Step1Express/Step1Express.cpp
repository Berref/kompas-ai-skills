// Step1Expres.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
//#include "Step1Expres.h"


//-------------------------------------------------------------------------------
// Определить имя библиотеки
// ---
char * WINAPI LIBRARYNAME()
{
  return "Самая простая библиотекана Visual C++ Express";
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  // Выдача сообщения пользователю
  MessageT( _T("ПРИВЕТ!!!") );
}