////////////////////////////////////////////////////////////////////////////////
//
// step1.cpp - Самая простая библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "step1.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStep1App
BEGIN_MESSAGE_MAP(CStep1App, CWinApp)
  //{{AFX_MSG_MAP(CStep1App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep1App construction
CStep1App::CStep1App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep1App object
CStep1App    theApp;
KompasObjectPtr kompas( NULL );

//-------------------------------------------------------------------------------
//
// ---
void GetKompas() {
  if ( !kompas ) {
    CString filename;
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) {
      filename.ReleaseBuffer( 255 );
      CString libname;

      #ifdef __LIGHT_VERSION__
        libname.LoadString( IDS_STRING5 );                // klAPI5.dll
      #else
        libname.LoadString( IDS_STRING4 );                // kAPI5.dll
      #endif

      filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
                        libname );

      HINSTANCE hAppAuto = LoadLibrary( filename );       // идентификатор kAPI5.dll
      if(  hAppAuto ) {
        typedef LPDISPATCH ( WINAPI *FCreateKompasObject )(); 
        FCreateKompasObject pCreateKompasObject = 
          (FCreateKompasObject)GetProcAddress( hAppAuto, "CreateKompasObject" );  
        if ( pCreateKompasObject ) 
          kompas = IDispatchPtr(pCreateKompasObject(), false); 
        FreeLibrary( hAppAuto );  
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Имя библиотеки
// ---
char * WINAPI  LIBRARYNAME() {
  return  "Самая простая библиотека на Visual C++";
}

//-------------------------------------------------------------------------------
// LIBRARYENTRY
// ---
void WINAPI LIBRARYENTRY( unsigned int comm ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  GetKompas();
  if ( kompas ) 
    kompas->ksMessage( _T("ПРИВЕТ !!!") );
}
