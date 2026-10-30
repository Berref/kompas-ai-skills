# WriteSlide - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
#ifndef __OWL_WINDOW_H

#include <owl\window.h>

#endif

void WriteSlide_Example ( void ) {

char name[128];

double x, y;

int slideID;

// ввод имени файла для записи слайда

if ( SaveFile(*.rc, name ) ){

if ( Cursor( Укажите точку привязки слайда,&x,&y,NULL,NULL ) ) {

if ( ReadInt( Введите идентификатор слайда, 100, 0, 32000, &slideID ) ) {

if ( !WriteSlide ( name, slideID, x, y ) )

Error( Группа селектирования пуста );

ClearGroup( 0 );

}

}

}

}; /* DrawBitmap_Example */
