# Пример инсталляции шрифта хот-точек в Компас

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
class FontInstaller

{

HANDLE m_hFont = {};

public:

FontInstaller( HINSTANCE module, LPWSTR lpName );

~FontInstaller();

};

//------------------------------------------------------------------------------

///

// ---

FontInstaller::FontInstaller( HINSTANCE module, LPWSTR lpName )

{

PRECONDITION( module );

HRSRC hrc = ::FindResource( module, lpName, RT_RCDATA );

PRECONDITION( hrc );

DWORD dwrclen = ::SizeofResource( module, hrc );

PRECONDITION( dwrclen );

HGLOBAL hrcglobal = ::LoadResource( module, hrc );

PRECONDITION( hrcglobal );

void * pvrc = ::LockResource( hrcglobal );

PRECONDITION( pvrc );

DWORD fontsCount = 0;

m_hFont = ::AddFontMemResourceEx( pvrc, dwrclen, 0, &fontsCount );

PRECONDITION( m_hFont && fontsCount == 1 );

}

//------------------------------------------------------------------------------

///

// ---

FontInstaller::~FontInstaller()

{

::RemoveFontMemResourceEx( m_hFont );

}

////////////////////////////////////////////////////////////////////////////////

//

// Класс устанавливает хот-точечный шрифт.

//

////////////////////////////////////////////////////////////////////////////////

class HotPointsFontInstaller : public FontInstaller

{

public:

HotPointsFontInstaller()

: FontInstaller( module, MAKEINTRESOURCE( HOT_POINTS_FONT ) ){};

};

Библиотека по первому требованию должна зарегистрировать шрифт и разрегистрировать его при отключении библиотеки.
