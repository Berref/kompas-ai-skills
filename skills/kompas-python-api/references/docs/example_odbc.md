# Пример использования утилиты

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//--------------------------------------------------------------------------------

// Интерфейс связи с вспомогательным контроллером

// ---

_COM_SMARTPTR_TYPEDEF(IWow32Util, __uuidof(IWow32Util));

IWow32UtilPtr wow32Util;

//--------------------------------------------------------------------------------

// Соединение в вспомогательному Win32 приложению (exe) для получения доступа

// к 32 разрядным драйверам для которых не найдены 64 разрядные аналоги

// ---

IWow32UtilPtr GetWow32Util()

{

if ( !(bool)wow32Util )

{

try

{

wow32Util.CreateInstance( _T("Wow32Util.Application") );

}

catch ( _com_error & )

{

}

}

return wow32Util;

}

//-----------------------------------------------------------------------------

// Создание интерфейса во внешнем 32 разрядном приложении

//---

IDispatchPtr CreateWow32Interface( LPCTSTR ClassID )

{

IDispatchPtr res;

IWow32UtilPtr util( GetWow32Util() );

if ( util )

{

try

{

_bstr_t id( ClassID );

util->CreateWow32Interface( id, &res );

}

catch (_com_error&)

{

//AR todo ComErrorMessage

}

}

return res;

}

//-----------------------------------------------------------------------------

// Создание интерфейса во внешнем 32 разрядном приложении

//---

#pragma comment( lib, "rpcrt4.lib" )

_LIBFUNC(IDispatchPtr) CreateWow32Interface( const CLSID& rclsid )

{

_TUCHAR * str = NULL;

if ( RPC_S_OK != UuidToString((UUID *)&rclsid, &str) || !str )

return NULL;

_bstr_t classId( "{" );

classId += str;

classId += _T("}");

IDispatchPtr res( CreateWow32Interface(classId) );

RpcStringFree( &str );

return res;

}

#define JET_OLED_PROVIDER _T("Provider=Microsoft.Jet.OLEDB.4.0")

#define ACE_OLED_PROVIDER _T("Provider=Microsoft.ACE.OLEDB.12.0")

static bool usesJET_OLED_PROVIDER = false;

static bool usesWOW32_PROVIDER = false;

//-----------------------------------------------------------------------------

/// Создать подключение к БД

/**

param fullFileName - Полный путь + имя файла

param forWrite - Для записи

*/

// ---

ado::_ConnectionPtr ExcelDataBaseADO::OpenConnection( LPCTSTR fullFileName, bool forWrite )

{

ado::_ConnectionPtr pConnection;

try

{

// Создадим соединение

#ifdef _WIN64

if ( usesWOW32_PROVIDER )

pConnection = CreateWow32Interface( __uuidof( ado::Connection ) );

else

#endif

pConnection.CreateInstance(__uuidof( ado::Connection ));

// Открываем соединение с БД( если файл excel не существует то он создасться)

if ( pConnection )

{

CString connName = usesJET_OLED_PROVIDER ? JET_OLED_PROVIDER : ACE_OLED_PROVIDER;

connName += _T(";Data Source=");

connName += fullFileName;

connName += _T(";Extended Properties="Excel 8.0;HDR=NO;");

if ( !forWrite )

connName += _T("IMEX=1;");

connName += _T(""");

pConnection->Open( (LPCTSTR)connName, _T(""), _T(""), 0 );

}

}

#ifdef _DEBUG

catch ( _com_error & er )

{

if ( usesJET_OLED_PROVIDER && usesWOW32_PROVIDER )

::ComErrorMessage( er );

pConnection = NULL;

}

#else

catch ( _com_error& )

{

pConnection = NULL;

}

#endif

if ( !(bool)pConnection && !usesJET_OLED_PROVIDER )

{

usesJET_OLED_PROVIDER = true;

pConnection = OpenConnection( fullFileName, forWrite );

usesJET_OLED_PROVIDER = false;

#ifdef _WIN64

if ( !(bool)pConnection && !usesWOW32_PROVIDER )

{

usesWOW32_PROVIDER = true;

pConnection = OpenConnection( fullFileName, forWrite );

// usesWOW32_PROVIDER = false;

}

#endif

}

return pConnection;

}

Получение интерфейса Recordset также требуется делать через CreateWow32Interface

#ifdef _WIN64

if ( usesWOW32_PROVIDER )

rset = CreateWow32Interface(_T("ADODB.Recordset"));

else

#endif

rset.CreateInstance(_T("ADODB.Recordset"));
