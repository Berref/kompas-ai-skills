# ksDrawKompasGroup - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//текущим документом должен быть графический документ

if ( ksGetCurrentDocument( 1 ) ) {

TWindow *st = new TWindow ( GetWindowPtr( ( HWND )GetHWindow( ) ), 0 );

st->Attr.X =300;

st->Attr.Y =30;

st->Attr.W =170;

st->Attr.H =160;

st->Create( ); //создали окно, в котором хотим отрисовать группу

//создаем группу с изображением прямоугольника

reference gr = NewGroup( 1 );

Mtr( 20, 15, 45, 1 );

LineSeg( -10, 0, 10, 0, 1 );

LineSeg( 10, 0, 10, 20, 1 );

LineSeg( 10, 20, -10, 20, 1 );

LineSeg( -10, 20, -10, 0, 1 );

DeleteMtr( );

EndGroup( );

//отрисовываем группу в окне st

ksDrawKompasGroup ( ( void * )st->HWindow, // несущее окно

gr ); //группа

//для красоты рисуем рамочку по периметру окна

TClientDC dc(*st );

HPEN hPen = ( HPEN ) ::SelectObject( dc, ::CreatePen( PS_SOLID,2,RGB( 0,0,255 ) ) );

dc.MoveTo( 0, 0 );

dc.LineTo( 170, 0 );

dc.LineTo( 170, 160 );

dc.LineTo( 0, 160 );

dc.LineTo( 0, 0 );

::DeleteObject( ::SelectObject( dc, hPen ) );

Message( "смотри" );

delete st;

}

else

Error ( "Графический документ не активен" );
