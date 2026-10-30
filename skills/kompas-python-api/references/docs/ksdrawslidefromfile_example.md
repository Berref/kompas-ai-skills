# ksDrawSlideFromFile - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//фрагмент из файла .rc

1000 DIALOG 84, 66, 204, 133

EXSTYLE WS_EX_DLGMODALFRAME

STYLE DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU

CAPTION ""

FONT 8, "MS Sans Serif"

{

CONTROL "OK", IDOK, "BUTTON", BS_DEFPUSHBUTTON | WS_CHILD | WS_VISIBLE |

WS_TABSTOP, 8, 111, 50, 14

CONTROL "Cancel", IDCANCEL, "BUTTON", BS_PUSHBUTTON | WS_CHILD |

WS_VISIBLE | WS_TABSTOP, 72, 111, 50, 14

CONTROL "", IDD_SHOW, "static", SS_BLACKFRAME | WS_CHILD | WS_VISIBLE |

WS_BORDER, 7, 3, 105, 97

}

class TShowStatic;

//Описание класса, обслуживающего диалог

class TModDialog :public TDialog

{

public:

UINT IdSlide;

TShowStatic* Show;

TModDialog ( TWindow *ptParent );

UINT GetIdSlide( ) { return IdSlide; };

};

//Описание класса обслуживающего элемент вывода слайда

class TShowStatic : public TStatic {

public:

TShowStatic ( TModDialog * ptParent, int resourceId );

protected :

void EvPaint( );

DECLARE_RESPONSE_TABLE( TShowStatic );

};

DEFINE_RESPONSE_TABLE1( TShowStatic,TStatic )

EV_WM_PAINT,

END_RESPONSE_TABLE;

//--------------------------------------------------------------------------

\-----

//

//--------------------------------------------------------------------------

\-----

TShowStatic :: TShowStatic ( TModDialog *ptParent, int resourceId ):

TStatic( ptParent, resourceId ) {

SetBkgndColor( GetSysColor( COLOR_APPWORKSPACE ) );

}

//--------------------------------------------------------------------------

\-----

//

//--------------------------------------------------------------------------

\-----

void TShowStatic ::EvPaint( )

{

TStatic::EvPaint( );

TModDialog * d = TYPESAFE_DOWNCAST( Parent, TModDialog );

if ( d )

// DrawSlide ( ( void * ) HWindow, d->GetIdSlide( ) );

// DrawBitmap ( ( void * ) HWindow, d->GetIdSlide( ) );

//в файле "c:\\\libtest\\\1.rc" - находится отлаживаемый слайд

ksDrawSlideFromFile ( ( void * ) HWindow, "c:\\\libtest\\\1.rc" );

}

//--------------------------------------------------------------------------

\-----

//

//--------------------------------------------------------------------------

\-----

TModDialog :: TModDialog ( TWindow *ptParent )

: TDialog( ptParent, 1000, module ){

IdSlide = 100;

Show=new TShowStatic( this,IDD_SHOW );

}

//--------------------------------------------------------------------------

\-----

// Функция, вызывающая диалог с отрисовкой слайда или битмапа

//--------------------------------------------------------------------------

\-----

void TestShowDialog( ) {

TModDialog *pDialog;

pDialog = new TModDialog( GetWindowPtr( ( HWND )GetHWindow( ) ) );

pDialog->Execute( );

delete pDialog;

}

//файл 1.rc

100 RCDATA {

GB, 168, 158,

SC, 1,

LS, 0, 1,

LN, 69, 57, 69, 26,

LN, 69, 26, 74, 18,

LN, 74, 18, 101, 18,

LN, 101, 18, 105, 26,

LN, 105, 26, 105, 57,

LN, 74, 37, 101, 37,

AR1, 114, 57, 45, 74, 37, 69, 57,

AR1, 61, 57, 44, 105, 57, 101, 37,

AR1, 80, 28, 11, 69, 28, 74, 37,

AR1, 94, 28, 11, 101, 37, 105, 28,

LN, 69, 57, 69, 88,

LN, 69, 88, 74, 96,

LN, 74, 96, 101, 96,

LN, 101, 96, 105, 88,

LN, 105, 88, 105, 57,

LN, 74, 77, 101, 77,

AR1, 114, 57, 45, 69, 57, 74, 77,

AR1, 62, 57, 44, 103, 77, 105, 57,

AR1, 80, 86, 11, 74, 77, 69, 86,

AR1, 95, 86, 11, 106, 86, 100, 76,

SC, 0,

LS, 2, 1,

LN, 62, 57, 112, 57,

SC, 0,

TS, 0,

MA, 45, 112,

TX, "ГОСТ 15524-70\0"

MA, 37, 127,

TX, "Класс точности А\0"

MA, 37, 142,

TX, " гайки высокие\0"

END_SLIDE

}
