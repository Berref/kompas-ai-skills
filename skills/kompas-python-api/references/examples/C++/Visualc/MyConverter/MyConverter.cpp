////////////////////////////////////////////////////////////////////////////////
//
// LibConverter.cpp - Пример конвертера на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "MyConverter.h"
#include "KompasConverter.h"
#include "LibConverter.h"


#include <atlBase.h>
#include <STATREG.H>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
AFX_EXTENSION_MODULE LibConverterDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
IApplicationPtr newKompasAPI( NULL );               

void        OnProcessDetach();                            // Отключение библиотеки
extern void ConverterDestroy();



//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
  g_hInstance = hInstance;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("LibConverter.AWX Initializing!\n");

		AfxInitExtensionModule(LibConverterDLL, hInstance);

		new CDynLinkLibrary(LibConverterDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("LibConverter.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(LibConverterDLL);
	}
	return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() 
{
	if ( !( IApplication * )newKompasAPI ) 
  {
		CString filename;
	
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
    {
			filename.ReleaseBuffer( 255 );
			CString libname;

      libname = _LoadStr( IDR_API7 );    // kAPI7.dll
			filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
												libname );

			HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI7.dll
		
      if(  hAppAuto ) 
      {
				// Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH ( WINAPI * FCreateKompasApplication )(); 
				 
        FCreateKompasApplication pCreateKompasApplication = 
					(FCreateKompasApplication)GetProcAddress( hAppAuto, "CreateKompasApplication" );	
				
        if ( pCreateKompasApplication )
					newKompasAPI = IDispatchPtr( pCreateKompasApplication(), false/*AddRef*/ ); // Получаем интерфейс Application
				FreeLibrary( hAppAuto );  
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  // Передаём команду меню в конвертер
  // comm = 1 - "Сохранение текущего файла"
  // comm = 2 - "Открыть файл"
  GetLibConverter().ExecuteCommand( comm );
}


//-------------------------------------------------------------------------------
// Завершение приложения
// ---
void OnProcessDetach()
{
  ConverterDestroy();
  newKompasAPI = NULL;
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса без конвертации
// ---
CString _LoadStr( int strID ) 
{
	TCHAR temp[_MAX_PATH];
	LoadString( LibConverterDLL.hModule, strID, temp, _MAX_PATH );
	return temp;
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса c конвертации
// ---
CString LoadStr( int strID ) 
{
	TCHAR temp[_MAX_PATH];
	ksConvertLangStrExT( LibConverterDLL.hModule, strID, temp, _MAX_PATH );
	return temp;
}


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( LPCTSTR str, int flags ) 
{
  int res = 0;

  if ( str && str[0] ) {                  // строка передана
    int enabse = ::IsEnableTaskAccess();  // проверка доступа
    if ( enabse )                         // если доступ к задаче разрешен
      ::EnableTaskAccess(0);              // запрещаем доступ

    //                         текст сообщения  заголовок          параметры
    res = MessageBox( (HWND) GetHWindow(), str, LoadStr(LIBRARYID()), flags );

    if ( enabse )                         // если доступ к задаче был запрещен
      ::EnableTaskAccess(1);              // разрешаем доступ к задаче
  }

  return res;
}


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( int strId, int flags ) 
{
  return ::LibMessage( LoadStr(strId), flags );
}

//------------------------------------------------------------------------------
// Находит в строке расширение файла и возвращает его
// ---
CString FindExt( LPCTSTR filename )                    
{
  TCHAR temp[_MAX_PATH] = _T("");
  CString buf( filename );
  int lenght = buf.GetLength();
  int pos = buf.ReverseFind(_T('.'));
  if ( pos >= 0 )
  {
    _tcscpy_s (temp, buf.Right( lenght - pos - 1 ));
  }
  return temp;
}

//-------------------------------------------------------------------------------
// Регистрация конвертера в реестре
// ---
// #define CONVERTERS_PATH "Software\\ASCON\\KOMPAS-3D\\Converters\\LibConverter"
// При использовании экспортных функций API Компаса библиотека может регистрироваться c с помощью 
// утилиты regsvr32 только в каталоге Bin Компаса т.к. для ее загрузки должна быть видна библиотека kApi2d5.dll
// Если используется автоматизация и не требуется наличия библиотек Компаса то регистрация выполняется
// --- 
STDAPI RegisterServer( bool _register )
{
  HRESULT hr = NOERROR;  
  TCHAR szModulePath[MAX_PATH];

  // Obtain the path to this module's executable file for later use.
  GetModuleFileName( LibConverterDLL.hModule, szModulePath,
                     sizeof(szModulePath)/sizeof(TCHAR) );

  ATL::CRegObject regObj;
  // Нужно обязательно добавить даже если в .rgs нет '%MODULE%'
  regObj.AddReplacement( _bstr_t(_T("Module")), _bstr_t(szModulePath) );
  
  hr = _register ? regObj.ResourceRegister(   _bstr_t(szModulePath), IDR_LibConverterRgs, _bstr_t(_T("REGISTRY")) ):
                   regObj.ResourceUnregister( _bstr_t(szModulePath), IDR_LibConverterRgs, _bstr_t(_T("REGISTRY")) );
                   
  return hr;
}


//-------------------------------------------------------------------------------
// Регистрация конвертера в реестре
// ---
STDAPI DllRegisterServer() 
{
  TRACE0("DllRegisterServer\n");
  return RegisterServer( TRUE );
}


//-------------------------------------------------------------------------------
// Разрегистрация AddIns
// ---
STDAPI DllUnregisterServer() 
{
  TRACE0("DllUnregisterServer\n");
  return RegisterServer( FALSE );
}      


//-------------------------------------------------------------------------------
// Получить интерфейс конвертации.
// ---
LPKOMPASCONVERTER WINAPI GetIKompasConverter()
{
  TRACE0("GetIKompasConverter\n");
  return (LPKOMPASCONVERTER) (GetLibConverter().GetKompasConverter())->GetInterface( &IID_IKompasConverter );
}

