////////////////////////////////////////////////////////////////////////////////
//
// OneWindow.cpp - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "OneWindow.h"
#include "events\ABaseEvent.h"
#include "LibObj.h"
#include <PArray.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern ABaseEvent * NewApplicationEvent();


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
AFX_EXTENSION_MODULE OneWindowDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
KompasObjectPtr kompas( NULL );
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
		TRACE0("ONEWINDOW.AWX Initializing!\n");

		AfxInitExtensionModule(OneWindowDLL, hInstance);

		new CDynLinkLibrary(OneWindowDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("ONEWINDOW.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(OneWindowDLL);
	}
	return 1;   // ok
}


//-------------------------------------------------------------------------------
//
// ---
void GetKompas() 
{
  if ( !(bool)kompas ) 
  {
    CString filename;
    
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
    {
      filename.ReleaseBuffer( 255 );
      CString libname;
      
      libname = (LPCTSTR)LoadStr( IDR_AUTO_LIB );  //kAPI5.dll
      
      filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
        libname );
      
      HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI5.dll
      if(  hAppAuto ) {
        typedef LPDISPATCH ( WINAPI * FCreateKompasObject )(); 
        FCreateKompasObject pCreateKompasObject = 
          (FCreateKompasObject)GetProcAddress( hAppAuto, "CreateKompasObject" );	
        if ( pCreateKompasObject ) 
          kompas = IDispatchPtr( pCreateKompasObject(), false/*AddRef*/ );
        if ( (bool)kompas && !(bool)newKompasAPI )
          newKompasAPI = kompas->ksGetApplication7();
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

#pragma warning( disable : 4786 )
//-----------------------------------------------------------------------------
//
// ---
IDocumentFramePtr GetActiveFrame( IKompasDocumentPtr & doc )
{
  IDocumentFramePtr res;
  if ( doc )
  {
    IDocumentFramesPtr frames( doc->DocumentFrames );
    if ( frames )
    {
      IDocumentFramePtr next;
      for ( long i = 0, count = frames->Count; i < count; i++ )
      {
        next = frames->Item[i];
        if ( (bool)next && next->Active )
        {
          res = next;
          break;
        }
      }
    }
  }
  return res;
}
#pragma warning( once : 4786 ) 

//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  GetKompas();
  if ( newKompasAPI )
  {
    IKompasDocument3DPtr doc3D( newKompasAPI->ActiveDocument );
    if ( doc3D )
    {
      IKompasDocumentPtr kompasDoc(doc3D);
      IDocumentFramePtr frame( GetActiveFrame(kompasDoc) );
      if ( frame )
      {
        LibObj * obj = FindOrCreateLibObj( frame, true );
        if ( obj )
        {
          switch ( comm )
          {
            case 1: 
            {
              obj->CreateForce();
              break;
            }
            case 4:
            {  
              obj->OnOfTree();
              break;
            } 
            case 5:
            {  
              obj->Refresh();
              break;
            } 
          }
        }
      } 
    }
  }
}


extern PArray<LibObj> m_libObjects;

//-------------------------------------------------------------------------------
// Завершение приложения
// ---
void OnProcessDetach()
{
  m_libObjects.Flush();

  ABaseEvent::TerminateEvents();
  ABaseEvent::DestroyList();

  newKompasAPI = nullptr;
  kompas = nullptr;
}

 
//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
int WINAPI LibInterfaceNotifyEntry( IDispatch * application ) 
{
  if ( !(bool)kompas )
    kompas = application;       // Получаем интерфейс Компаса
  if ( (bool)kompas && !(bool)newKompasAPI )
    newKompasAPI = kompas->ksGetApplication7();
  NewApplicationEvent();
  AdviseDocuments();
  return 0;
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
_bstr_t LoadStr( int strID ) 
{
  TCHAR temp[512];  
  ksConvertLangStrExT( OneWindowDLL.hModule, strID, temp, 512 );
	return temp;
}


