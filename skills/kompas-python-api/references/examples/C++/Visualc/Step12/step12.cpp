////////////////////////////////////////////////////////////////////////////////
//
// step12.cpp - Пример создания пользовательской панели свойств
// 
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h> 

#include "resource.h"

#ifndef  _CPROPMEN_H
#include "cPropMen.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE StepDLL = { NULL, NULL };

IApplicationPtr newKompasAPI;                                // Компас Application 7     
IPropertyManagerPtr propMng;                                 // Менежер панели свойств 
IPropertySlideBoxPtr slideBox;                               // Окно в котором будет отрисовываться текущий документ 

PropertyManagerLayout g_Layout = pmAlignRight;/*pmFloating*/ // Положение панели
CRect g_Rect( 20, 20, 270, 320 );                            // Размер

void ClosePropertyManager( bool mes );                       // Удаление пользовательской панели  
void CreateAndSubscriptionPropertyManager( bool mes );       // Создание пользовательской панели

// Функции создания подписок на события Компаса
extern cBaseEvent* NewApplicationEvent();
extern cBaseEvent* NewDocumentEvent( reference doc );
extern cBaseEvent* NewDocument2DEvent( reference doc );
extern cBaseEvent* NewDocument3DEvent( reference doc );
extern cBaseEvent* NewObj2DEvent( reference doc, int objType );
extern cBaseEvent* NewObj3DEvent( reference doc, int objType, LPUNKNOWN iObj = NULL );
extern cBaseEvent* NewSpcDocEvent( reference doc );
extern cBaseEvent* NewSpcObjectEvent( reference doc, int objType );
extern cBaseEvent* NewSpecificationEvent( reference doc );
extern cBaseEvent* NewStampEvent( reference doc );
void AdviseDoc( long pDoc );

//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
  UNREFERENCED_PARAMETER( lpReserved );

  if ( dwReason == DLL_PROCESS_ATTACH )
  {
    TRACE0( "DLL Initializing!" );
 
    if ( !AfxInitExtensionModule( StepDLL, hInstance ) )
      return 0;

    new CDynLinkLibrary( StepDLL );
  }
  else if ( dwReason == DLL_PROCESS_DETACH )
  {
    // Отписка событий 
    ABaseEvent::TerminateEvents();
    cBaseEvent::TerminateEvents();
    // Удаление панели
    ClosePropertyManager( false/* mes*/ );
    // Удаление списка событий
    ABaseEvent::DestroyList();
    cBaseEvent::DestroyList();

    newKompasAPI = NULL;
    TRACE0( "DLL Terminating!" );
    AfxTermExtensionModule( StepDLL );
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() {
	if ( !( IApplication* )newKompasAPI ) {
		CString filename;
		if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) {
			filename.ReleaseBuffer( 255 );
			CString libname;

      #ifdef __LIGHT_VERSION__
        libname.LoadString( IDS_API7LT );  // klAPI7.dll
      #else
        libname.LoadString( IDS_API7 );    // kAPI7.dll
      #endif

			filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind(_T('\\')) + 1)), 
												libname );

			HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI7.dll
			if(  hAppAuto ) {
				// Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH ( WINAPI *FCreateKompasApplication )(); 
				 
        FCreateKompasApplication pCreateKompasApplication = 
					(FCreateKompasApplication)GetProcAddress( hAppAuto, "CreateKompasApplication" );	
				if ( pCreateKompasApplication )
					newKompasAPI = IDispatchPtr( pCreateKompasApplication(), false/*AddRef*/ ); 
				FreeLibrary( hAppAuto );  
			}
		}
	}
}


//----------------------------------------------------------------------------------------------
// Зогрузить строку из ресурсов
//---
TCHAR * LoadStr( int ID ) {
  static TCHAR buf[255];
  ksConvertLangStrExT( StepDLL.hModule, ID, buf, 255 );
  return buf;
}


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( LPCTSTR str, int flags = MB_OK ) {
  int res = 0;

  if ( str && str[0] ) {                  // строка передана
    int enabse = ::IsEnableTaskAccess();  // проверка доступа
    if ( enabse )                         // если доступ к задаче разрешен
      ::EnableTaskAccess(0);              // запрещаем доступ

    //                         текст сообщения  заголовок          параметры
    res = MessageBox( (HWND) GetHWindow(), str, LoadStr(IDR_LIB), flags );

    if ( enabse )                         // если доступ к задаче был запрещен
      ::EnableTaskAccess(1);              // разрешаем доступ к задаче
  }

  return res;
}


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( int strId, int flags = MB_OK ) {
  return ::LibMessage( LoadStr(strId), flags );
}


//-------------------------------------------------------------------------------
// Определить имя библиотеки
// ---
int WINAPI LIBRARYID()
{
  return IDR_LIB;
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  // Выдача сообщения пользователю
 	::GetNewKompasAPI(); // Захват интерфейса приложения КОМПАС
  if ( newKompasAPI ) 
  {
    switch ( comm ) 
    {       

			case 1 : // Создать закладку и подписаться
        CreateAndSubscriptionPropertyManager( true );
				break;
			case 2 : // Отписаться
        ClosePropertyManager( true );
        // Запоминаем положение панели и гасим ее
				break;
    }
  }
}


//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
int WINAPI LibInterfaceNotifyEntry( IDispatch *application ) 
{
  newKompasAPI = application;                           // Получаем интерфейс Компаса
 // CreateAndSubscriptionPropertyManager( false/*mes*/);  // Создание панели библиотеки 
  return 0;
}


//-------------------------------------------------------------------------------
// Использовать новое API
// ---
int WINAPI LibIsOnApplication7() 
{
  return 1;
}


//-----------------------------------------------------------------------------
// Создать закладку и подписаться
// ---
void CreateAndSubscriptionPropertyManager( bool mes ){
  if ( propMng == NULL ) {
    NewApplicationEvent();   
    propMng = newKompasAPI->CreatePropertyManager( TRUE/*FALSE*/ );
    propMng->Layout = g_Layout;
    propMng->Caption = _T("Панель из библиотеки");
    propMng->SetGabaritRect( g_Rect.left, g_Rect.top, g_Rect.right, g_Rect.bottom );
    propMng->SpecToolbar = pnEnterEscCreateSaveSearchHelp;
    new PropertyManagerEvent( propMng );                 // Подписываемся на события процесса 
    IPropertyTabPtr tab( propMng->PropertyTabs->Add(_T("Закладка из библиотеки")) );
    
    // Получаем коллекцию контролов
    IPropertyControlsPtr collection = tab->PropertyControls;
    reference docRef = ::ksGetCurrentDocument(0);
    AdviseDoc( docRef );
    // Добавсляем окно просмотра
    slideBox = collection->Add( ksControlSlideBox );            
    slideBox->SlideType      = ksKompasDocument;             // Отрисовываем группу
    slideBox->DrawingSlide   = docRef;                       // Передаем reference группы 
    slideBox->Value              = docRef != 0;
    slideBox->CheckBoxVisibility = docRef != 0;
    slideBox->Hint           = _T("Hint для слайда");
    slideBox->Tips           = _T("Tips для слайда");
    slideBox->Id             = 10000;
    slideBox->Name           = _T("Окно просмотра");
    slideBox->NameVisibility = ksNameHorizontalVisible;

    IPropertyEditPtr edit = collection->Add( ksControlEditInt );
    edit->Name = _T("IPropertyEdit");
    edit->Id = 100100;

    propMng->ShowTabs();
    propMng->Caption = _T("Панель из библиотеки1");
//    propMng->ShowTabs();
//    propMng->UpdateTabs();

  }
  else {
    propMng->Visible = true; // Если панель была скрыта пользователем по крестику востановим ее
    if( mes ) {
      LibMessage( _T("Панель уже загружена") );
    }
  }
}
 

//-----------------------------------------------------------------------------
// Остановить работу с панелью свойствт  и отписаться
// ---
void  ClosePropertyManager( bool mes ){
  if ( propMng ) {
  
    g_Layout = propMng->Layout;
    propMng->GetGabaritRect( &g_Rect.left, &g_Rect.top, &g_Rect.right, &g_Rect.bottom );
    ABaseEvent::TerminateEvents(DIID_ksPropertyManagerNotify);
    propMng->HideTabs();
    slideBox = NULL; 
    propMng = NULL;

  }
  else {
    if( mes )
      LibMessage( _T("Панель уже выгружена") );
  }
}


//-----------------------------------------------------------------------------
// Обновление скна
// ---
void UpdateSlideBox() 
{
  if ( slideBox )
    slideBox->UpdateParam();
}


//-----------------------------------------------------------------------------
// Обновление скна
// ---
void UpdateSlideBox( reference docRef ) 
{
  if ( slideBox ) {
    slideBox->DrawingSlide       = docRef;
    slideBox->Value              = docRef != 0;
    slideBox->CheckBoxVisibility = docRef != 0;
    slideBox->UpdateParam();
  }
}


//-------------------------------------------------------------------------------
// Получить идентификаторы инструментальных и компактных панелей
// ---
int WINAPI LibToolBarId( int barType, // Тип запрашиваемой панелей ( 0 - компактная панель, 1 - простая инструментальная панель ) 
                         int index )  // Индекс панели
{
	if ( !barType )
    return !index ? 2000 : -1;
	else 
		return -1; 
}


//-------------------------------------------------------------------------------
// Подписка на события документа
// ---
void AdviseDoc( long pDoc ) {

	if ( !pDoc )
		pDoc = ::ksGetCurrentDocument( 0 );
	else
    ::SetObjParam(pDoc, NULL, 0, DOCUMENT_STATE);

	if ( pDoc ) {
		int docType = ::ksGetDocumentType( pDoc );
		if ( NewDocumentEvent( pDoc ) ) {
			switch( docType ) {
		  	case lt_DocSheetStandart :
			  case lt_DocSheetUser     :
					NewStampEvent( pDoc ); 
			  case lt_DocFragment      :
					NewDocument2DEvent( pDoc );
				  NewObj2DEvent( pDoc, ALL_OBJ );
				  break;
			  case lt_DocPart3D :
			  case lt_DocAssemble3D : {
  		    NewDocument3DEvent(pDoc);
				  NewObj3DEvent( pDoc, o3d_unknown, NULL ); // На все
					break;
				}
				case lt_DocSpc:
				case lt_DocSpcUser: {
					NewSpcDocEvent( pDoc );
					NewStampEvent( pDoc ); 
					break;
				}	
				case lt_DocTxtStandart   :
				case lt_DocTxtUser       : 
					NewStampEvent( pDoc );
					break;
      }    

			switch ( docType ) {
		    case lt_DocSheetStandart:
				case lt_DocSheetUser:
				case lt_DocSpc:
        case lt_DocSpcUser:
				case lt_DocAssemble3D: {
          NewSpecificationEvent( pDoc );
					NewSpcObjectEvent( pDoc, SPC_BASE_OBJECT /*На базовые объекты*/ );
				}
			}
		}
	}
}

