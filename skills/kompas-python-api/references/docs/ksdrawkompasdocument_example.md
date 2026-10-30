# ksDrawKompasDocument - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
TWindow *st = new TWindow (GetWindowPtr( ( HWND )GetHWindow( ) ), 0 );

st->Attr.X =300;

st->Attr.Y =30;

st->Attr.W =170;

st->Attr.H =160;

st->Create( ); //создали окно, в котором хотим отрисовать слайд

ksDrawKompasDocument( ( void* ) st->HWindow, // несущее окно

"d:\\\0\\\fg1.frw" ); // полное имя файла документа

Message( "Слайд КОМПАС" );

delete st;
