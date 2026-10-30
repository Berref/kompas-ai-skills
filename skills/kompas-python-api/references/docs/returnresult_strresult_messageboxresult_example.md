# ReturnResult, StrResult, MessageBoxResult - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ReturnResult _Example ( void ) {

char s[80];

LineSeg ( 0, 0, 0, 0, 1 ); /* совпадающие узлы отрезка */

if ( ReturnResult ( ) ) {

/* выдать сообщение в специальном окне */

MessageBoxResult( );

};

Circle ( 10, 10, 0, 1 ); /* нулевой радиус окружности */

if ( ReturnResult ( ) ) {

StrResult( s, 80 );

Error( s );

}:

}; /* ReturnResult */
