// slideWrk.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <math.h>
#include "slideWrk.h"

#ifndef __TESTMOVE_H
#include "testmove.h"
#endif

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
// CSlideWrkApp

BEGIN_MESSAGE_MAP(CSlideWrkApp, CWinApp)
  //{{AFX_MSG_MAP(CSlideWrkApp)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlideWrkApp construction

CSlideWrkApp::CSlideWrkApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSlideWrkApp object

CSlideWrkApp theApp;

//-------------------------------------------------------------------------------
//
// ---
char* WINAPI LIBRARYNAME(){
  return  "Тест слайд";
}

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_LIBID;
}

KompasObjectPtr kompas( NULL );

//-------------------------------------------------------------------------------
// Функция, вызывающая диалог с отрисовкой слайда или битмапа
//-------------------------------------------------------------------------------
void TestShowDialog() {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  kompas->ksEnableTaskAccess( 0 ); // закрыть доступ к компасу
  TestDlg *pDialog = new TestDlg();
  if ( pDialog ) {
    pDialog->DoModal();
    delete pDialog;
  }
  kompas->ksEnableTaskAccess( 1 ); // открыть доступ к компасу
}

void WriteSlideStep( ksDocument2DPtr& doc );
void DecomposeSlideStep( ksDocument2DPtr& doc );

void Symmetry( float x, float y, float x1, float y1, float x2, float y2,
               float *xc, float *yc );


//-------------------------------------------------------------------------------
//
// ---
void GetKompas() {
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


//-------------------------------------------------------------------------------
//
// ---
void WINAPI LIBRARYENTRY( unsigned int comm ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  GetKompas();
  if ( kompas ) {
    ksDocument2DPtr doc( kompas->ActiveDocument2D() );
    if ( doc && doc->reference ) {
      switch ( comm ) {
        case 1 : MoveSlide();               break; // сдвинуть слайд  
        case 2 : WriteSlideStep( doc );      break; // записать слайд
        case 3 : TestShowDialog();          break; // отрисовать слайд
        case 4 : DecomposeSlideStep( doc ); break; // разбить слайд
      }
    }
  }
}

/////////////////////////////////////////////////////////////////////////////
// TestDlg dialog


TestDlg::TestDlg(CWnd* pParent /*=NULL*/)
  : CDialog(TestDlg::IDD, pParent)
{
  //{{AFX_DATA_INIT(TestDlg)
    // NOTE: the ClassWizard will add member initialization here
  //}}AFX_DATA_INIT
  IdSlide  = 100;
}


void TestDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(TestDlg)
  DDX_Control(pDX, IDC_SHOW_STATIC, m_show);
  //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TestDlg, CDialog)
  //{{AFX_MSG_MAP(TestDlg)
  ON_WM_PAINT()
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TestDlg message handlers

void TestDlg::OnPaint() 
{
  CPaintDC dc(this); // device context for painting

  TCHAR fName[_MAX_PATH];
  ::GetModuleFileName( theApp.m_hInstance, fName, 255 );
  TCHAR *c = ::_tcsrchr( fName, _T('\\'));
  if ( c )
    *(c + 1) = '\0';
  ::_tcscat_s( fName, 255, _T("1.rc") );

  kompas->ksDrawSlideFromFile( (long)m_show.m_hWnd, fName );
  
  // Do not call CDialog::OnPaint() for painting messages
}


//-------------------------------------------------------------------------------
//
// ---
void WriteSlideStep( ksDocument2DPtr& doc ) {
  CString name( (LPCTSTR)kompas->ksSaveFile(_T("*.rc"), _T(""),  _T(""), false) );
  if ( !name.IsEmpty() ) {
    ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
    if ( info ) {
      info->Init();
      info->commandsString = _T("Укажите точку привязки слайда");

      double x, y;
      if ( doc->ksCursor(info, &x, &y, NULL) ) {
        long slideID;
        if ( kompas->ksReadInt( _T("Введите идентификатор слайда"), 100, 0, 32000, &slideID ) ) {
          if ( !kompas->ksWriteSlide((LPCTSTR)name, slideID, x, y) )
            kompas->ksError( _T("Группа селектирования пуста") );
          doc->ksClearGroup( 0, true );
        }
      }
    }
  }
}


static double cx1, cy1, cx2, cy2;
static int flag;

ksDocument2DPtr docAct( NULL );

//-------------------------------------------------------------------------------
//
// ---
static void DrawRamka() {
  if( ::fabs(cy1 - cy2) > 0 ) {
    docAct->ksLineSeg( cx1, cy1, cx1, cy2, 1 );
    docAct->ksLineSeg( cx2, cy1, cx2, cy2, 1 );
  }
  if( ::fabs(cx1 - cx2) > 0 ) {
    docAct->ksLineSeg( cx1, cy1, cx2, cy1, 1 );
    docAct->ksLineSeg( cx1, cy2, cx2, cy2, 1 );
  }
}

//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
// ---
int WINAPI CALLBACKPROCCURSOR( int comm, double* x, double*y, LPDISPATCH rInfo,
                               LPDISPATCH rPhan, int dynamic ) {
  ksRequestInfoPtr info( rInfo );
  ksPhantomPtr     phan( rPhan );
  if ( info && phan ) {
    phan->phantom = 1;
    ksType1Ptr t1( phan->GetPhantomParam() );
    if( !dynamic ) { //фиксация
      if ( !flag ) {//фиксируется 1 точка
        flag++;
        cx1 = *x; cy1= *y;
        info->commandsString = _T("Укажите вторую точку окна");
      }
      else {
        flag++;
        cx2 = *x; cy2 = *y;
        return 0;
      }
    }
    else {
      if ( flag > 0 ) {
        cx2 = *x; cy2 = *y;
        t1->xBase = cx2; 
        t1->yBase = cy2;
        
        if ( docAct->ksExistObj(t1->gr) )
          docAct->ksDeleteObj( t1->gr );

        t1->gr = docAct->ksNewGroup(1); // временная группа
          DrawRamka();
        docAct->ksEndGroup();
      }
    }
  }
  return 1;
}


//-------------------------------------------------------------------------------
//
// ---
void DecomposeSlideStep( ksDocument2DPtr & doc ) {
  docAct = doc;
  ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  ksPhantomPtr     phan( kompas->GetParamStruct(ko_Phantom)     );
  ksIteratorPtr    iter( kompas->GetIterator()                  );
  if ( info && phan && iter ) {
    phan->Init();
    info->Init();
    info->commandsString = _T("Укажите первую точку окна");
    info->dynamic = 1;
    info->SetCallBackC( _T("CALLBACKPROCCURSOR"), PtrToLong(theApp.m_hInstance), 0 );
    phan->phantom = 1;
    ksType1Ptr t1( phan->GetPhantomParam() );
    if ( t1 ) {
      t1->Init();
      t1->scale_ = 1;
      t1->gr = doc->ksNewGroup(1);
      doc->ksEndGroup();

      flag = 0;
      double x, y;
      doc->ksCursor( info, &x, &y, phan );
      
      if ( doc->ksExistObj(t1->gr) ) 
        doc->ksDeleteObj( t1->gr );

      if ( flag == 2 ) {
        doc->ksClearGroup( 0, true );
        if ( doc->ksSelectGroup(0, 1, cx1, cy1, cx2, cy2) ) {
          if ( iter->ksCreateIterator(SELECT_GROUP_OBJ, 0) ) {
            t1->gr = doc->ksNewGroup(1);
            doc->ksEndGroup();
            reference rObj;
            reference gr;
            if ( doc->ksExistObj(rObj = iter->ksMoveIterator(_T("F"))) ) {
              do {
                gr = doc->ksDecomposeObj(rObj, 0, 0.2, false );
                doc->ksAddObjGroup( t1->gr, gr );
                doc->ksClearGroup( gr, false );
                doc->ksDeleteObj( gr );
              } while( doc->ksExistObj(rObj = iter->ksMoveIterator(_T("N"))) );
            }

            info->Init();
            t1->xBase = cx1;
            t1->yBase = cy1;
            info->commandsString = _T("Укажите базовую точку группы");
            if ( doc->ksCursor(info, &x, &y, phan) ) {
              doc->ksMtr( x - cx1, y - cy1, 0, 1, 1 );
              doc->ksTransformObj( t1->gr );
              doc->ksDeleteMtr();
              doc->ksStoreTmpGroup( t1->gr );
            }

            doc->ksClearGroup( t1->gr, true );
            doc->ksDeleteObj( t1->gr ); 
          }
          doc->ksClearGroup( 0, true );
        }
        else
          kompas->ksError( _T("Ошибка") );
      }
    }
  }
}

