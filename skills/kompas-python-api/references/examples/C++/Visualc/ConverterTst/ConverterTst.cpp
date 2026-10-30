////////////////////////////////////////////////////////////////////////////////
//
// ConverterTst.cpp - Библиотека для проверки конвертера LibConverter
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "ConverterTst.h"
#include "AtlBase.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE ConverterTstDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;

IApplicationPtr newKompasAPI( NULL );               

void OnProcessDetach();                            // Отключение библиотеки


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
		TRACE0("CONVERTERTST.AWX Initializing!\n");

		AfxInitExtensionModule(ConverterTstDLL, hInstance);

		new CDynLinkLibrary(ConverterTstDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("CONVERTERTST.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(ConverterTstDLL);
	}
	return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API7 Kompas
// ---
void GetNewKompasAPI() 
{
	if ( !( IApplication *)newKompasAPI ) 
  {
		CString filename;
	
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
    {
			filename.ReleaseBuffer( 255 );
			
      CString libname = LoadStr( IDR_API7 );    // kAPI7.dll
			
      filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind(_T('\\')) + 1)), 
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


void TestConverter(); // Пример вызова функции конвертации файла для внешнего конвертора

//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  switch ( comm )
  {
    case 1: // Конвертировать файл
    {
      // Пример вызова функции конвертации файла для внешнего конвертора
      TestConverter();
      break;
    }
  }
}


//-------------------------------------------------------------------------------
// Завершение приложения
// ---
void OnProcessDetach()
{
  newKompasAPI = NULL;
}

// Путь к конвертеру в реестре
#define CONVERTERS_PATH _T("SOFTWARE\\ASCON\\KOMPAS-3D\\Converters\\MyLibConverter")
#define MAX_BUFFER       256 


//-------------------------------------------------------------------------------
// Функция тестирования ковертера LibConverter
// ---
void TestConverter()
{
  int err = 0;
  // Получаем доступ к API7 Kompas
  GetNewKompasAPI();
  // Если получили
  if ( newKompasAPI )
  {
    CRegKey key;
    // Проверяем, зарегистрирован ли наш конвертер
    if ( key.Open( HKEY_LOCAL_MACHINE, CONVERTERS_PATH, KEY_READ ) == ERROR_SUCCESS )
    {
      TCHAR path[MAX_BUFFER];
      DWORD cbPath = MAX_BUFFER; 
      // Получаем путь к конвертеру
      if ( key.QueryMultiStringValue( _T("Path"), path, &cbPath ) == ERROR_SUCCESS )
      {
        // Получаем интерфейс конвертера
        IConverterPtr LibConverter( newKompasAPI->GetConverter( _bstr_t(path) ) );
        if ( LibConverter )
        {
          // Получаем интерфейс параметров конвертера
          ILibConverterParamPtr myConvParam( LibConverter->ConverterParameters( 0/*command*/) );
          if ( myConvParam )
          {
            // Сообщение "Сохранять стиль линий?"
            int okStyle = YesNoT( (LPTSTR)(LPCTSTR)LoadStr(IDS_STYLE_DOC) );
            // Передаём параметр Сохранять стиль линий в конвертер
            myConvParam->PutSaveLineStyle( !!okStyle );
          }
          // Вызываем метод конвертировать
          int res = LibConverter->Convert( _T("c:\\1.cdw"), _T("c:\\1.mycdw"), libConv_Exp_cdw, FALSE/*showParam*/ );
          if ( !res )
            err = IDS_ERR_CONVERT; // "Ошибка конвертации файла"
          else
            LibMessage( IDS_CONVERT_SUCCESS ); // "Конвертация файла завершена"
        }
        else
          err = IDS_NO_GET_CONVERTER_INTERFACE; // "Не удалось получить интерфейс конвертера."
      }
      else
        err = IDS_NO_GET_CONVERTER; // "Конвертер не зарегистрирован"
    }
    else
      err = IDS_NO_GET_CONVERTER; // "Конвертер не зарегистрирован"
  }
  else
    err = IDS_NO_GET_NEW_API; // "Ошибка получения интерфейса API7"
  if ( err )
    // Вывод сообщения
    LibMessage( err );
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
CString LoadStr( int strID ) 
{
	TCHAR temp[_MAX_PATH];
	LoadString( ConverterTstDLL.hModule, strID, temp, _MAX_PATH ); 
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

