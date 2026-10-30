# Пример использования функции LibraryBmpBeginID

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
\--------------------------------------

// Получить начало диапазона иконок для команд библиотеки

// ---

unsigned int WINAPI LibraryBmpBeginID( unsigned int bmpSizeType )

{

int res = 0;

switch ( bmpSizeType )

{

case ksBmp1616: res = 1000; break;

case ksBmp2424: res = 2000; break;

}

return res;

}
