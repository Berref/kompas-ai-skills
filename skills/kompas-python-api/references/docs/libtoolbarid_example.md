# Пример использования функции LibToolBarId

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//-----------------------------------------------------------------------------

// Получить идентификаторы панелей

// barType == 0 - компактная панель 1 - простая панель

// index - индекс панели

// ---

extern "C" int WINAPI __export LibToolBarId( int barType, int index ){

if ( !barType )

{

// Компактная панель "Крепежные элементы"

return !index ? COMPACT_BAR_CONSTR : -1;

}

#ifndef __LIGHT_VERSION__

else

{

switch( index )

{

case 0: return BAR_CONSTRUCT; // Панель "Конструктивные элементы"

case 1: return BAR_PROFILE; // Панель "Профили"

}

}

#endif

return -1;

}
