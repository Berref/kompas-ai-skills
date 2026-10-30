# DrawBitmap, DrawSlide - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
#ifndef __OWL_WINDOW_H

#include <owl\window.h>

#endif

void DrawBitmap_Example ( void ) {

// Пример файла ресурсов

//

//Описание слайда

100 RCDATA {

SC, 0,

LS, 2, 1,

LN, 12, 59, 179, 59,

END_SLIDE

}

200 BITMAP 1.bmp

extern TModule *module ;

TWindow *st = new TWindow ( GetWindowPtr( ( HWND )GetHWindow( ) ), 0 );

st->Attr.X =300;

st->Attr.Y =30;

st->Attr.W =170;

st->Attr.H =160;

st->Create( ); //создаем окно для отрисовки слайда

DrawBitmap ( ( void* ) st->HWindow, 100 );

DrawSlide ( ( void* ) st->HWindow, 200 );

Message( Вывод слайда );

delete st;

}; /* DrawBitmap_Example */
