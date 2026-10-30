   // step11.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step11.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//  Note!
//
//    If this DLL is dynamically linked against the MFC
//    DLLs, any functions exported from this DLL which
//    call into MFC must have the AFX_MANAGE_STATE macro
//    added at the very beginning of the function.
//
//    For example:
//
//    extern "C" BOOL PASCAL EXPORT ExportedFunction()
//    {
//      AFX_MANAGE_STATE(AfxGetStaticModuleState());
//      // normal function body here
//    }
//
//    It is very important that this macro appear in each
//    function, prior to any calls into MFC.  This means that
//    it must appear as the first statement within the 
//    function, even before any object variable declarations
//    as their constructors may generate calls into the MFC
//    DLL.
//
//    Please see MFC Technical Notes 33 and 58 for additional
//    details.
//

/////////////////////////////////////////////////////////////////////////////
// CStep11App

BEGIN_MESSAGE_MAP(CStep11App, CWinApp)
  //{{AFX_MSG_MAP(CStep11App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep11App construction

CStep11App::CStep11App()
{
};

CStep11App step11App;
//CComModule _Module;

KompasObjectPtr kompas;

//------------------------------------------------------------------------------
// функция обратной связи
// 0 - плоскость, 1 - цилиндр, 2 - ось - состав collection
// ---
int WINAPI CALLBACKPROCCOMMANDWINDOW( int comm, LPDISPATCH rInfo ) {
  TCHAR buf[10];
  ::_itot_s( comm, buf, 10 );
  kompas->ksMessage(_T("Выполняется команда") );
  // заменяем заголовок окна в зависимости от выполненной команды
  // аналогично можно заменить и состав дерева команд
  ksRequestInfoPtr info( rInfo );
  if ( info ) {
    switch ( comm ) {
      case ID_COMMAND_1 : info->title = _T("1"); break;
      default : info->title = _T("2");
    }
  }
  // возвращаемый результат определяет, должна ли система продолжать
  // запрашивать команду :
  // TRUE - продолжать
  // FALSE - завержить работу с окном
  return comm == ID_COMMAND_2_2_1_3 ? FALSE : TRUE;
}

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDS_COMMANDWIN;
}


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
        libname.LoadString( IDS_STRING5 );  //klAPI5.dll
      #else
        libname.LoadString( IDS_STRING4 );  //kAPI5.dll
      #endif

      filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
                        libname );

      HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI5.dll
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
//
// ---
void WINAPI LIBRARYENTRY( unsigned int comm ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  GetKompas();
  ksDocument2DPtr doc( kompas->Document2D() );
   ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( kompas && doc && info ) {
    info->Init();

    info->menuId = ID_TREE_CONTENTS;

    info->title = _T("Дерево команд");

    HINSTANCE hInst = step11App.m_hInstance;
    info->SetCallBackCm( _T("CALLBACKPROCCOMMANDWINDOW"), PtrToLong(hInst), 0 );
    int command = doc->ksCommandWindow( info );
    TCHAR buf[10];
    ::_itot_s( command, buf, 10 );
    kompas->ksMessage(_T("Выбрана команда"));
  }
}
