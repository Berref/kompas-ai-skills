// step4.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step4.h"

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
// CStep4App

BEGIN_MESSAGE_MAP(CStep4App, CWinApp)
  //{{AFX_MSG_MAP(CStep4App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CStep4App construction

CStep4App::CStep4App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep4App object

CStep4App theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_LIBID;
}

KompasObjectPtr kompas;

void DrawTxtDB();
void DrawRectCallBack( ksDocument2DPtr& doc );
void DrawRectNULL( ksDocument2DPtr& doc );
void WriteSlideStep( ksDocument2DPtr& doc );
void TestShowDialog( ksDocument2DPtr& doc );
void WorkRelativePath ();
void WorkSystemPath( ksDocument2DPtr& doc );

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
          kompas = pCreateKompasObject();
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
  if ( kompas ) {
    switch ( comm ) {
      case 1  : ::DrawTxtDB();      break; // работа с БД
      case 3  : {                                     // ввод длинного целого
          long h1;
          if ( kompas->ksReadInt(_T("Ввести индекс"), 10000, -100000l, 100000l, &h1) ) { 
            TCHAR buf[20];
            ::_stprintf_s( buf, _T("h = %ld"), h1 );
            kompas->ksMessage( buf );
          }
          else 
            kompas->ksMessage( _T("отказ") );
        }
        break; 
      case 4  : {  // выбор имени файла
          CString name( (LPCTSTR)kompas->ksChoiceFile(_T("*.cdw"), _T(""), true) );
          if ( !name.IsEmpty() ) 
            kompas->ksMessage( (LPCTSTR)name );
          else 
            kompas->ksMessage( _T("отказ") );
        }
        break; 
      case 9  : ::WorkRelativePath();         break; // Работа с относительными путями файлов
      default :
        ksDocument2DPtr doc( kompas->ActiveDocument2D() );
        if ( doc && doc->reference ) {
          switch ( comm ) {
            case 2  : {
                if ( kompas->ksYesNo(_T("Вызывать функцию CallBack?")) )
                  DrawRectCallBack( doc );
                else
                  DrawRectNULL( doc );
              }
              break; // технические требования
            case 6  : ::WriteSlideStep( doc );      break; // пример отрисовки слайда 
            case 7  : ::TestShowDialog( doc );      break; // отрисовать слайд ( описание в файле step4_3.cpp )
            case 8  : {
                kompas->ksEnableTaskAccess( 0 ); //запретили доступ к задаче
                for ( int i = 0; i < 10000; i++ ) {
                  doc->ksLineSeg( 10, 10 + i, 20, 10 + i, 1 );
                  if ( !(i % 100) ) {
                    // посылаем необрабатываемое сообщение своему приложению
                    // для выполнения процесса в фоновом режиме
                    ::PostThreadMessage( ::GetCurrentThreadId(), 0, 0, 0 );
                    kompas->ksPumpWaitingMessages(); // через каждые 100 отрезков обрабатываем очередь сообщений
                                                    // при этом Windows получает возможность выполнить свои
                                                    // действия, например переключиться на другую задачу
                  }
                }
                kompas->ksEnableTaskAccess( 1 ); //разрешили доступ к задаче
              }
              break; 
            case 10 : ::WorkSystemPath( doc );     break; // Работа с системными каталогами
          }
        }
    }
  }
}


//-------------------------------------------------------------------------------
//
// ---
void DrawTxtDB() {


  reference bd, r1, r2, r3;
  int i = 1;
  struct {
    double dr, l;
    int f;
  } b;
  TCHAR buf[128];
  ksDataBaseObjectPtr data( kompas->DataBaseObject() );
  ksUserParamPtr par( kompas->GetParamStruct(ko_UserParam) );
  ksLtVariantPtr item( kompas->GetParamStruct(ko_LtVariant) );
  ksDynamicArrayPtr arr( kompas->GetDynamicArray(LTVARIANT_ARR) );
  if ( !par || !item || !data ) 
    return;
  par->Init();
  par->SetUserArray( arr );
  item->Init();
    item->doubleVal = 0;
    arr->ksAddArrayItem( -1, item );
  item->Init();
    item->doubleVal = 0;
    arr->ksAddArrayItem( -1, item );
  item->Init();
    item->intVal = 0;
    arr->ksAddArrayItem( -1, item );

  TCHAR libName[255];
  ::_tcscpy_s( libName, kompas->ksChoiceFile( _T("*.loa"),_T("Базы данных(*.loa)|*.loa|Все файлы (*.*)|*.*|"), 1 ) );
  if( libName ) { 
    bd = data->ksCreateDB(_T("TXT_DB")); //создать объект, обслуживающий базу данных
    if (data->ksConnectDB(  bd, libName) ){ //связать объект базы с определенной базой данных( для текстового файла - имя файла )
      r1 = data->ksRelation( bd ); //создать отношение - буфер для считывания информации из таблицы
        data->ksRDouble( _T("dr") );//имена даются ключевым колонкам,
        data->ksRDouble( _T("L") ); //по ним в дальнейшем формируются условия выборки
        data->ksRInt( _T(""));
      data->ksEndRelation();

      //установить запрос - отношение связывается с базой( указываем какие колонки
      //базы связать с переменными буфера )
      data->ksDoStatement( bd, r1, _T("1 2 3") ); //колонка dr - 1, L - 2, оставшаяся колонка -3
      while( i ) {
        i= data->ksReadRecord( bd, r1, par ); //считать очередную порцию информации и положть в структуру b
        if ( i ) {
            arr->ksGetArrayItem( 0, item );
            b.dr = item->doubleVal;
            arr->ksGetArrayItem( 1, item );
            b.l = item->doubleVal;
            arr->ksGetArrayItem( 2, item );
            b.f = item->intVal;
          ::_stprintf_s( buf, _T("DR = %g\nL = %g\nF = %d"), b.dr, b.l, b.f );//item.GetDoubleVal(), item1.GetDoubleVal(), item2.GetIntVal());
          kompas->ksMessage( buf);
        }
      }
      kompas->ksMessage( _T("end") );

      i = 1;
/*      par.Init();
      par.SetUserArray( arr );*/
      arr->ksClearArray();
      item->Init();
        item->strVal = _T("");
        arr->ksAddArrayItem( -1, item );
      r2 = data->ksRelation( bd ); //создать отношение - буфер для считывания информации из таблицы
         data->ksRChar( _T(""), 255, 0 );
      data->ksEndRelation();

      data->ksDoStatement( bd, r2, _T("2") );//установить запрос - отношение связывается с базой( указываем какие колонки
      while( i ) {
        i= data->ksReadRecord( bd, r2, par ); //считать очередную порцию информации и положть в структуру b
        if ( i ) {
           arr->ksGetArrayItem( 0, item );
          ::_stprintf_s( buf, _T("L = %s"), (LPCTSTR)item->strVal );
          kompas->ksMessage( buf );
          //kompas->ksMessage( item.GetStrVal() );
        }
      }
      kompas->ksMessage( _T("end") );

      struct {
        double a, l;
      }con;
      i = 1;

      arr->ksClearArray();
      item->Init();
        item->doubleVal = 0;
        arr->ksAddArrayItem( -1, item );
      item->Init();
        item->doubleVal = 0;
        arr->ksAddArrayItem( -1, item );
      r3 = data->ksRelation( bd ); //создать отношение - буфер для считывания информации из таблицы
         data->ksRDouble(_T(""));
        data->ksRDouble(_T("L"));
      data->ksEndRelation();

      data->ksDoStatement( bd, r3, _T("1 2") );//установить запрос - отношение связывается с базой( указываем какие колонки
      data->ksCondition( bd, r3, _T("L=100||L=150") );
      while( i ) {
        i= data->ksReadRecord( bd, r3, par ); //считать очередную порцию информации и положть в структуру b
        if ( i ) {
           arr->ksGetArrayItem( 0, item );
          con.a = item->doubleVal;
          arr->ksGetArrayItem( 1, item );
          con.l = item->doubleVal;
          ::_stprintf_s( buf, _T("dr = %g\nL = %g"), con.a, con.l );
          kompas->ksMessage( buf );
        }
      }
      kompas->ksMessage( _T("end") );
    }
    data->ksDeleteDB( bd ); //удалить обьект, обслуживающий базу данных
  }
}

//-------------------------------------------------------------------------------
//
// ---
void WriteSlideStep( ksDocument2DPtr& doc ) {
  //выберем файл для записи
  CString name( (LPCTSTR)kompas->ksSaveFile(_T("*.rc"), _T(""), _T(""), false) );
  if ( !name.IsEmpty() ) {
    ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
    if ( info ) {
      info->Init();
      info->commandsString = _T("Укажите точку привязки слайда");
      // точка привязки слайда - верхний левый угол габаритного прямоугольника слайда
      double x, y;
      if ( doc->ksCursor(info, &x, &y, NULL) ) {
        long slideID;
        if ( kompas->ksReadInt(_T("Введите идентификатор слайда"), 100, 0, 32000, &slideID) ) {
          if ( !kompas->ksWriteSlide((LPCTSTR)name, slideID, x,  y) )
            kompas->ksError( _T("Группа селектирования пуста") );
          doc->ksClearGroup( 0, true );
        }
      }
    }
  }
}

//---------------------------------------------------------------------------------
// Работа с относительными путями файлов
//----------------------------------------------------------------------------------
void  WorkRelativePath() {
  //имя задающего файла
  CString mainName( (LPCTSTR)kompas->ksChoiceFile(_T("*.*"), _T("Все файлы (*.*)|*.*|"), true) );
  CString fileName( (LPCTSTR)kompas->ksChoiceFile(_T("*.*"), _T("Все файлы (*.*)|*.*|"), true) );
  if ( !mainName.IsEmpty() && !fileName.IsEmpty() ) {
    // относительный путь
    CString relName( (LPCTSTR)kompas->ksGetRelativePathFromFullPath((LPCTSTR)mainName,    // полный путь к задающему файлу
                                                                     (LPCTSTR)fileName) ); // полный путь к требуемому файлу

    CString mess( _T("Задающий файл : ") );
    mess += mainName;
    mess += _T(" \n");
    mess += _T("Полный путь : ");
    mess += fileName ;
    mess += _T(" \n");
    mess += _T("Относительный путь : ");
    mess += relName ;
    kompas->ksMessage( (LPCTSTR)mess );

    // полный путь
    CString fullName( (LPCTSTR)kompas->ksGetFullPathFromRelativePath((LPCTSTR)mainName,   // полный путь к задающему файлу
                                                                     (LPCTSTR)relName) ); // относительный путь к требуемому файлу( без общей с задающим файлом части пути )
    mess = _T("Задающий файл : ");
    mess +=  mainName;
    mess += _T(" \n");
    mess += _T("Относительный путь : ");
    mess += relName ;
    mess += _T(" \n");
    mess += _T("Полный путь : ");
    mess += fullName;
    mess += _T(" \n");
    kompas->ksMessage( (LPCTSTR)mess );
  }
}

//---------------------------------------------------------------------------------
// Работа с системными каталогами
//----------------------------------------------------------------------------------
void  WorkSystemPath( ksDocument2DPtr& doc ) {
  TCHAR * catalogName[] = { _T("каталог системных файлов"), 
                            _T("каталог библиотек")       ,
                            _T("каталог временных файлов"), 
                            _T("каталог конфигурации")    ,
                            _T("INI-файл") };
  // сформировать  полный путь к заданному файлу
  ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( info ) {
    info->Init();
    info->title = _T("Каталоги файлов системы");
    info->commandsString = _T("!Системные !Библиотеки !Временные !Конфигурация !INI-файл");
    info->prompt = _T("Выберите нужный каталог");
    int j;
    static TCHAR* buf = _T("user.ttt");
    CString fileName;
    int typeCatalog;
    do {
      j = doc->ksCommandWindow( info );
      if ( j > 0 ) {
        switch ( j ) {
          case 1 : typeCatalog = sptSYSTEM_FILES; break; // Относительно каталога системных файлов
          case 2 : typeCatalog = sptLIBS_FILES  ; break; // Относительно каталога файлов библиотек
          case 3 : typeCatalog = sptTEMP_FILES  ; break; // Относительно каталога сохранения временных файлов
          case 4 : typeCatalog = sptCONFIG_FILES; break; // Относительно каталога сохранения конфигурации системы
          case 5 : typeCatalog = sptINI_FILE    ; break; // Относительно полного имени INI-файла системы
        }
        //полный путь
        fileName = (LPCTSTR)kompas->ksGetFullPathFromSystemPath( buf,           // относительный путь к файлу( без системного пути )
                                                                 typeCatalog ); // путь установленного типа см. ksSystemPath
        CString mess( _T("Полный путь к файлу user.ttt \n") );
        mess +=  catalogName[j - 1];
        mess += _T(" :\n");
        mess += fileName ;
        kompas->ksMessage( (LPCTSTR)mess );

        //относительный путь
        CString relName( (LPCTSTR)kompas->ksGetRelativePathFromSystemPath((LPCTSTR)fileName,       // полный путь к файлу
                                                                                 typeCatalog) ); // путь установленного типа см. ksSystemPath
        mess = _T("Относительный путь к файлу \n");
        mess += fileName;  
        mess += _T("\n");
        mess +=  catalogName[j -1];
        mess += _T(" :\n");
        mess += relName;
        kompas->ksMessage( (LPCTSTR)mess );
         
      }
    } while ( j > 0 );
  }
}
