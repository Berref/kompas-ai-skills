# ksInitFilePreviewFunc - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//------------------------------------------------------------------------------

// функция обратной связи для отображения в окне предварительного просмотра

// файлов не документов КОМПАС

// ---

int far __export pascal MyPreviewFunc( HWND HWindow, // дескриптор окна просмотра

char * fileName ){ // файл, который нужно показать в окне просмотра

if ( fileName ) {

char *c = strrchr( fileName, '.' );

if ( c && strcmp( c, ".cdw" ) && strcmp( c, ".frw" ) && strcmp( c, ".spw" ) && strcmp( c, ".kdw" ) ) {

//если не документ КОМПАС отобразим имя файла

c = strrchr( fileName, '\\\' );

if ( c ) {

TRect rect;

::GetClientRect( HWindow, &rect );

TWindow *staticW = new TWindow( HWindow );

TDC *dc = new TClientDC(*staticW );

dc->TextOut( 40, ( rect.bottom - rect.top )*0.5-10, c1, strlen( c1 ) );

delete dc;

delete staticW;

return 1;

}

}

}

return 0;

}

//------------------------------------------------------------------------------

//

// ---

extern "C" void far __export __pascal LibraryEntry( unsigned int com ){

switch ( com ) {

case 1: {

//установим адрес нашей функции просмотра

ksInitFilePreviewFunc( MyPreviewFunc );

char fileName[250];

//выберем файл

if( ( ksChoiceFile( 0,"Все файлы (*.* )|*.*|", fileName, 250, 1 ) ) != 0 )

Message( fileName );

// обнулим адрес

ksInitFilePreviewFunc( 0 );

// выберем файл

if( ( ksChoiceFile( 0,"Все файлы (*.* )|*.*|", fileName, 250, 1 ) ) != 0 )

Message( fileName );

break;

}

}

}
