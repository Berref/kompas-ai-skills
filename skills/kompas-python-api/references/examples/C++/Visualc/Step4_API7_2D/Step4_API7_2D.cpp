////////////////////////////////////////////////////////////////////////////////
//
// Step4_API7_2D.cpp - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <math.h>
#include <afxdllx.h>
#include <winspool.h>
#include "Step4_API7_2D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE Step4_API7_2DDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
ksAPI7::IApplicationPtr newKompasAPI( NULL );               

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
		TRACE0("STEP4_API7_2D.AWX Initializing!\n");

		AfxInitExtensionModule(Step4_API7_2DDLL, hInstance);

		new CDynLinkLibrary(Step4_API7_2DDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("STEP4_API7_2D.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(Step4_API7_2DDLL);
	}
	return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() 
{
  if ( !( ksAPI7::IApplication * )newKompasAPI ) 
  {
    CString filename;
    
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
    {
      filename.ReleaseBuffer( 255 );
      CString libname;
      
      libname = LoadStr( IDR_API7 );    // kAPI7.dll
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
          newKompasAPI = IDispatchPtr ( pCreateKompasApplication(), false /*AddRef*/); // Получаем интерфейс Application
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
// Описания используемых функций
// ---
void PrintSample();			    // Пример работы с интерфейсом задания на печать
void PrintSettingsSample(); // Пример работы с интерфейсом настроек принтера
void CreateAndSaveConfig(); // Создание и сохранение конфигурации
void LoadConfig();          // Загрузка конфигурации


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  switch ( comm )
  {
    case 1: 
    {
      PrintSample();
      break;
    }
    
    case 2: 
    {
      PrintSettingsSample();
      break;
    }
    
    case 3:
    {
      CreateAndSaveConfig();
      break;
    }
    
    case 4:
    {
      LoadConfig();
      break;
    }
  }
}


//-------------------------------------------------------------------------------
// Создать массив SAFEARRAY типа long
// ---
_variant_t NewSafeArrayLong( long * dv, int count )
{
  _variant_t res;
  SAFEARRAYBOUND sabNewArray;
	
  sabNewArray.cElements = count;
  sabNewArray.lLbound = 0;
	
  SAFEARRAY * pSafe = ::SafeArrayCreate( VT_I4, 1, &sabNewArray );
	
  if( pSafe )
  {
    for ( long i = 0; i < count; i++ )
    {
      HRESULT  hr = ::SafeArrayPutElement( pSafe, (long*)&i, (void*)&dv[i] );
			
      if ( FAILED(hr) ) 
        break;
    }
		
    V_VT(&res) = VT_ARRAY | VT_I4;
    V_ARRAY(&res) = pSafe;
  }
  return res;
}


//-------------------------------------------------------------------------------
// Рассчитать масштаб для вывода
// ---
void CalcScale( ksAPI7::IPrintJobPtr & print )
{
	if ( print )
	{
		double pageWidth, pageHeight;
		// Определяем габариты страницы устройства печати
		print->GetPageGabarites( &pageWidth, &pageHeight );

		long count = print->SheetsCount;

		for ( long i = 0; i < count; i++ )
		{
			// Получаем лист документа
			ksAPI7::IPrintJob_SheetPtr sheet( print->GetSheet(i) );

			if ( sheet )
			{
				double w, h;
				// Определяем габариты листа
				sheet->GetGabarites( &w, &h );

				// Вычисляем масштаб вывода
				if ( pageWidth > w )
					sheet->Scale = 1;
				else
					sheet->Scale = pageWidth/w;

				// Размещаем лист в начале страницы
				sheet->X = pageWidth * i;
			}
		}
	}
}


//------------------------------------------------------------------------------
// Полное имя файла
// ---
bool GetFullName( TCHAR * inName, TCHAR * outName, int outNameLen ) 
{
  bool     rez; // результат поиска файла name
  OFSTRUCT ofs;

  if ( ::GetModuleFileName(Step4_API7_2DDLL.hModule, outName, outNameLen) )
  {
    TCHAR * c = ::_tcsrchr( outName, _T('\\') );
    if( c )
    {
      *(c + 1) = _T('\0');
      ::_tcscat_s( outName, 255, inName );
      rez = ::OpenFile( _bstr_t(outName), &ofs, OF_EXIST ) != HFILE_ERROR;
      
      if ( !rez ) 
      {
        *(c + 1) = _T('\0');
        ::_tcscat_s( outName, 255, _T("Step4_API7_2D\\") );
        ::_tcscat_s( outName, 255, inName );
        rez = ::OpenFile( _bstr_t(outName), &ofs, OF_EXIST ) != HFILE_ERROR;
      }
    }
  }
  return rez;
}


//-------------------------------------------------------------------------------
// Пример работы с интерфейсом задания на печать
// ---
void PrintSample()
{
	GetNewKompasAPI();

	if ( newKompasAPI )
	{
		// Получаем интерфейс задания на печать
		ksAPI7::IPrintJobPtr print( newKompasAPI->PrintJob );
		
		if ( print )
		{
			_variant_t sheets;
			sheets.vt = VT_EMPTY;
			
			TCHAR fileName[_MAX_PATH] = _T("");
			GetFullName( _T("Чертеж.cdw"), fileName, _MAX_PATH );
			// Добавляем документ дважды (все листы)
			print->AddSheets( fileName, sheets, ksAllSheets );
			print->AddSheets( fileName, sheets, ksAllSheets );

			// Индексы удаляемых листов
			long index[4];
			index[0] = 0;
			index[1] = 1;
			index[2] = 4;
			index[3] = 5;
			_variant_t delIndex = NewSafeArrayLong( index, 4 );

			// Удаляем листы
			print->RemoveSheets( delIndex );

			// Рассчитываем масштаб
			CalcScale( print );

			// Выводим окно предварительного просмотра
			print->ShowPreviewWindow();
		}
	}
}


//-------------------------------------------------------------------------------
// Пример работы с интерфейсом настроек принтера
// ---
void PrintSettingsSample()
{
  GetNewKompasAPI();
  
  if ( newKompasAPI )
  {
    // Получаем интерфейс задания на печать
    ksAPI7::IPrintJobPtr print( newKompasAPI->PrintJob );
    
    if ( print )
    {
      _variant_t sheets;
      sheets.vt = VT_EMPTY;

      // Добавляем документ
      print->AddSheets( _T("Чертеж.cdw"), sheets, ksAllSheets );
      
      // Индексы удаляемых листов
      long index[3];
      index[0] = 1;
      index[1] = 2;
      index[2] = 3;
      _variant_t delIndex = NewSafeArrayLong( index, 3 );

      // Удаляем листы
      print->RemoveSheets( delIndex );
      
      // Получаем интерфейс настроек принтера
      ksAPI7::IPrintJob_PrinterSettingsPtr printSettings( print );
      
      if ( printSettings )
      {
        // Загружаем конфигурацию принтера
        if ( printSettings->LoadPrinterConfig(_T("Конфигурация.pdc")) )
        {
          // Получаем интерфейс листа документа
          ksAPI7::IPrintJob_SheetPtr sheet( print->GetSheet((long)0) );
          
          if ( sheet )
          {
            double w, h, scale;
            // Получаем габариты листа
            sheet->GetGabarites( &w, &h );
            // Получаем масштаб листа
            scale = sheet->Scale;
            // Подгоняем размер бумаги под размер листа
            printSettings->PaperWidth  = (long)floor(10 * w * scale);
            printSettings->PaperLength = (long)floor(10 * h * scale);
            // Выводим окно предварительного просмотра
            print->ShowPreviewWindow();
          }
        }
        else
          MessageT(_T("Ошибка при загрузке конфигурации") );
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Сравнить строки
// ---
bool EqualsStrings( LPCTSTR name1, LPCTSTR name2 )
{
  CString s1( name1 );
  s1.MakeLower();

  CString s2( name2 );
  s2.MakeLower();

  return !s1.Compare( s2 );
}


//-------------------------------------------------------------------------------
// Создание и сохранение конфигурации
// ---
void CreateAndSaveConfig()
{
  GetNewKompasAPI();

  if ( newKompasAPI )
  {
    // Получаем интерфейс задания на печать
    ksAPI7::IPrintJobPtr print( newKompasAPI->PrintJob );

    if ( print )
    {
      _variant_t sheets;
      sheets.vt = VT_EMPTY;

      // Добавляем документ
      print->AddSheets( _T("Чертеж2.cdw"), sheets, ksAllSheets );
      
      // Получаем интерфейс настроек принтера
      ksAPI7::IPrintJob_PrinterSettingsPtr printSettings( print );

      if ( printSettings )
      {
        DWORD needBufLen = 0;
        DWORD foundCount = 0;
        bool  hasPrinter = false;

        // Определяем размер буфера
        ::EnumPrinters( PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL/*all printers*/, 2, NULL, 0/*buffer length*/, &needBufLen, &foundCount );

        if ( needBufLen )
        {
          LPPRINTER_INFO_2 pBuff = (LPPRINTER_INFO_2)::malloc( needBufLen );
          LPCTSTR printerName;
          
          // Получаем структуру информации о принтерах
          if ( ::EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL/*all printers*/, 2, (LPBYTE)pBuff, needBufLen, &needBufLen, &foundCount) && foundCount )
          { 
            // Получаем первый принтер из списка
            printerName = pBuff->pPrinterName;
            // Этот принтер не позволяет задавать нестандартный размер бумаги, берем следующий
            if ( EqualsStrings(printerName, _T("Microsoft XPS Document Writer")) )
            {
              LPPRINTER_INFO_2 pPrintInfo = pBuff;
              ++pPrintInfo;
              printerName = pPrintInfo->pPrinterName;
            }
            // Задаем параметры печати
            printSettings->InitPrinterSettings( printerName, FALSE, 0/*пользовательский*/, 1500, 1000, 0 );
            // Сохраняем конфигурацию
            printSettings->SavePrinterConfig( _T("Конфигурация1.pdc") );
            // Меняем размер бумаги
            printSettings->PaperLength = 1600;
            printSettings->PaperWidth = 1900;
            // Сохраняем конфигурацию
            printSettings->SavePrinterConfig( _T("Конфигурация2.pdc") );
            // Меняем ориентацию бумаги
            BOOL isPortrait = printSettings->IsPortraitPage;
            printSettings->IsPortraitPage = !isPortrait;
            // Выводим окно предварительного просмотра
            print->ShowPreviewWindow();
          }
          ::free( pBuff );
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Загрузка конфигурации
// ---
void LoadConfig()
{
  GetNewKompasAPI();

  if ( newKompasAPI )
  {
    // Получаем интерфейс задания на печать
    ksAPI7::IPrintJobPtr print( newKompasAPI->PrintJob );

    if ( print )
    {
      _variant_t sheets;
      sheets.vt = VT_EMPTY;

      // Добавляем документ
      print->AddSheets( _T("Чертеж2.cdw"), sheets, ksAllSheets );

      // Получаем интерфейс настроек принтера
      ksAPI7::IPrintJob_PrinterSettingsPtr printSettings( print );

      if ( printSettings )
      {
        // Загружаем сохраненную конфигурацию
        if ( printSettings->LoadPrinterConfig(_T("Конфигурация1.pdc")) )
        {
          // Меняем размер бумаги
          printSettings->PaperLength = 1800;
          printSettings->PaperWidth = 1200;
          // Меняем ориентацию бумаги
          BOOL isPortrait = printSettings->IsPortraitPage;
          printSettings->IsPortraitPage = !isPortrait;
          // Сохраняем конфигурацию
          printSettings->SavePrinterConfig( _T("Конфигурация3.pdc") );
          // Выводим окно предварительного просмотра
          print->ShowPreviewWindow();
        }
      }
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


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
CString LoadStr( int strID ) 
{
	TCHAR temp[_MAX_PATH];
	LoadString( Step4_API7_2DDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


