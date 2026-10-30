//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include <ldefin2d.h>
#include <ksConstants.h>

/*
#ifdef __LIGHT_VERSION__
#include <Kl_TLB.h>
#else
#include <Ks_TLB.h>
#endif
*/
#include "testform.h"

#ifdef _WIN64
 #define __TODO__ " TODO: "
 #define __WARN__ " warning: "
#else
#define __ANYTOSTR__(x) #x
#define __DEFTOSTR__(x) __ANYTOSTR__(x)
#define __TODO__ __FILE__ "("__DEFTOSTR__(__LINE__)") : TODO: "
#define __WARN__ __FILE__ "("__DEFTOSTR__(__LINE__)") : warning: "
#endif

#ifdef VARIANT_COPIES_BSTR
  inline wchar_t * TO_OLE(wchar_t *x) { return x; }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).c_bstr(); }
  inline wchar_t * TO_OLE(WideString & x) { return x.c_bstr(); }
#else
#pragma message(  __TODO__ "Рекомендуется добавить в настройки проекта определение VARIANT_COPIES_BSTR\n" )
// подробнее см http://sites.google.com/site/akxsolutions/articles/borland-c-dicom
	inline wchar_t * TO_OLE(wchar_t *x) { return WideString(x).Copy(); }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).Copy(); }
  inline wchar_t * TO_OLE(WideString & x) { return x.Copy(); }
#endif



//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

HINSTANCE hinstance;
#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  hinstance = hinst;
        return 1;
}

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch* far __export WINAPI CreateKompasObject();


KompasObjectPtr kompas;
extern "C" unsigned int __export __stdcall LIBRARYID()
{
	return 10;
}


void DrawTxtDB();
void DrawRectCallBack( ksDocument2DPtr & doc );
void DrawRectNULL    ( ksDocument2DPtr & doc );
void WriteSlideStep  ( ksDocument2DPtr & doc );
void TestShowDialog  ( ksDocument2DPtr & doc );
void WorkRelativePath();
void WorkSystemPath  ( ksDocument2DPtr & doc );

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
		switch ( comm ) {
      case 1  : ::DrawTxtDB(); break; // работа с БД
      case 3  : // ввод длинного целого
        long h1;
        if ( kompas->ksReadInt(  TO_OLE(L"Ввести индекс"), 10000, -100000l, 100000l, &h1) ) {
          char buf[20];
          ::sprintf( buf, "h = %ld", h1 );
          kompas->ksMessage( TO_OLE(buf) );
        }
        break;
      case 4  :   // выбор имени файла
        kompas->ksMessage( kompas->ksChoiceFile( TO_OLE(L"*.cdw"), NULL, true) );
        break;
      case 9  : ::WorkRelativePath(); break; // Работа с относительными путями файлов
      default : {
        ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
        if ( (bool)doc && doc->reference ) {
          switch ( comm ) {
            case 2  : // технические требования
              if ( kompas->ksYesNo( TO_OLE(L"Вызывать функцию CallBack?")) )
                DrawRectCallBack( doc );
              else
                DrawRectNULL( doc );
              break;
            case 6  : ::WriteSlideStep( doc ); break; // пример отрисовки слайда
            case 7  : ::TestShowDialog( doc ); break; // отрисовать слайд ( описание в файле step4_3.cpp )
            case 8  :
              kompas->ksEnableTaskAccess( 0 );        // запретили доступ к задаче
              for ( int i = 0; i < 10000; i++ ) {
                doc->ksLineSeg( 10, 10 + i, 20, 10 + i, 1 );
                if ( !(i % 100) ) {
                  // посылаем необрабатываемое сообщение своему приложению
                  // для выполнения процесса в фоновом режиме
                  ::PostThreadMessage( ::GetCurrentThreadId(), 0, 0, 0 );
                  kompas->ksPumpWaitingMessages();      // через каждые 100 отрезков обрабатываем очередь сообщений
                                                        // при этом Windows получает возможность выполнить свои
                                                        // действия, например переключиться на другую задачу
                }
              }
              kompas->ksEnableTaskAccess( 1 );          // разрешили доступ к задаче
              break;
            case 10 : ::WorkSystemPath( doc );   break; // Работа с системными каталогами
          }
        }
      }
		}
		kompas.Unbind();
  }
}

//------------------------------------------------------------------------------
// Работа с БД
// ---
void DrawTxtDB() {
  reference bd, r1, r2, r3;
  int i = 1;
  struct {
    double dr, l;
    int f;
  } b;
  char buf[128];
  ksDataBaseObjectPtr data( (ksDataBaseObject*)kompas->DataBaseObject(),               false/*AddRef*/ );
  ksUserParamPtr      par ( (ksUserParam*)     kompas->GetParamStruct(ko_UserParam),   false/*AddRef*/ );
  ksLtVariantPtr      item( (ksLtVariant*)     kompas->GetParamStruct(ko_LtVariant),   false/*AddRef*/ );
  ksDynamicArrayPtr   arr ( (ksDynamicArray*)  kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
  if ( !(bool)par || !(bool)item || !(bool)data )
    return;
  par->Init();
  par->SetUserArray( arr );
  item->Init();
  item->doubleVal = 0.0;
  arr->ksAddArrayItem( -1, item );
  arr->ksAddArrayItem( -1, item );

  item->Init();
  item->intVal = 0;
  arr->ksAddArrayItem( -1, item );

  WideString libName( kompas->ksChoiceFile(  TO_OLE(L"*.loa"),  TO_OLE(L""), 1 ) );
  if( !libName.IsEmpty() ) {
    bd = data->ksCreateDB(  TO_OLE(L"TXT_DB") ); //создать объект, обслуживающий базу данных
    if (data->ksConnectDB(bd, TO_OLE(libName) ) ){ //связать объект базы с определенной базой данных( для текстового файла - имя файла )
      r1 = data->ksRelation( bd ); //создать отношение - буфер для считывания информации из таблицы
        data->ksRDouble(  TO_OLE(L"dr") );//имена даются ключевым колонкам,
        data->ksRDouble(  TO_OLE(L"L")  ); //по ним в дальнейшем формируются условия выборки
        data->ksRInt(  TO_OLE(L"") );
      data->ksEndRelation();

      //установить запрос - отношение связывается с базой( указываем какие колонки
      //базы связать с переменными буфера )
      data->ksDoStatement( bd, r1, TO_OLE(L"1 2 3") ); //колонка dr - 1, L - 2, оставшаяся колонка -3
      while( i ) {
        i= data->ksReadRecord( bd, r1, par ); //считать очередную порцию информации и положть в структуру b
        if ( i ) {
            arr->ksGetArrayItem( 0, item );
            b.dr = item->doubleVal;
            arr->ksGetArrayItem( 1, item );
            b.l = item->doubleVal;
            arr->ksGetArrayItem( 2, item );
            b.f = item->intVal;
          ::sprintf( buf, "DR = %g\nL = %g\nF = %d", b.dr, b.l, b.f );
          kompas->ksMessage( TO_OLE(buf) );
        }
      }
      kompas->ksMessage( TO_OLE(L"end") );

      i = 1;

      arr->ksClearArray();
      item->Init();
        item->strVal = TO_OLE(L"");
        arr->ksAddArrayItem( -1, item );
      r2 = data->ksRelation( bd ); //создать отношение - буфер для считывания информации из таблицы
        data->ksRChar( TO_OLE(L""), 255, 0 );
      data->ksEndRelation();

      data->ksDoStatement( bd, r2, TO_OLE(L"2") );//установить запрос - отношение связывается с базой( указываем какие колонки
      while( i ) {
        i= data->ksReadRecord( bd, r2, par ); //считать очередную порцию информации и положть в структуру b
        if ( i ) {
          arr->ksGetArrayItem( 0, item );
          kompas->ksMessage( item->strVal );
        }
      }
      kompas->ksMessage( TO_OLE(L"end") );

      struct {
        double a, l;
      }con;
      i = 1;

      arr->ksClearArray();
      item->Init();
        item->doubleVal = 0;
        arr->ksAddArrayItem( -1, item );
        arr->ksAddArrayItem( -1, item );
      r3 = data->ksRelation( bd ); //создать отношение - буфер для считывания информации из таблицы
        data->ksRDouble( TO_OLE(L"") );
        data->ksRDouble( TO_OLE(L"L"));
      data->ksEndRelation();

      data->ksDoStatement( bd, r3,  TO_OLE(L"1 2") );//установить запрос - отношение связывается с базой( указываем какие колонки
      data->ksCondition( bd, r3, TO_OLE(L"L=100||L=150") );
      while( i ) {
        i= data->ksReadRecord( bd, r3, par ); //считать очередную порцию информации и положть в структуру b
        if ( i ) {
          arr->ksGetArrayItem( 0, item );
          con.a = item->doubleVal;
          arr->ksGetArrayItem( 1, item );
          con.l = item->doubleVal;
          ::sprintf( buf, "dr = %g\nL = %g", con.a, con.l );
          kompas->ksMessage( TO_OLE(buf) );
        }
      }
      kompas->ksMessage( TO_OLE(L"end") );
    }
    data->ksDeleteDB( bd ); //удалить обьект, обслуживающий базу данных
  }
}

ksDocument2DPtr docActive;
int type, flag=1;
//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
// ---
extern "C" int __export __stdcall CALLBACKPROCCURSOR( int comm, double* x, double* y, LPDISPATCH rInfo,
                               LPDISPATCH rPhan, int dynamic ) {

  kompas->ksMessage(  TO_OLE(L"пришли в курсор") );
  ksRequestInfoPtr info( (ksRequestInfo*)rInfo, true/*AddRef*/ );
  ksPhantomPtr     phan( (ksPhantom*)rPhan    , true/*AddRef*/ );
  if ( (bool)info && (bool)phan ) {
    ksType1Ptr t1( (ksType1*)phan->GetPhantomParam(), false/*AddRef*/ );
    switch ( comm ) {
      case 1  :
      case 2  : type = comm; break;
      case -1 : { // поставить в модель
          docActive->ksMoveObj( t1->gr, *x, *y );
          if ( ::fabs(t1->angle) > 0.001 )
            docActive->ksRotateObj( t1->gr, *x, *y, t1->angle );
          docActive->ksStoreTmpGroup( t1->gr );
          docActive->ksClearGroup( t1->gr, true );
        }
        break;
    }
// группа для фантома должна быть временная и обновляться при изменении вида отрисовки
    if ( t1->gr )
      docActive->ksDeleteObj( t1->gr );
    t1->gr = docActive->ksNewGroup( 1 );   // временная группа

    if ( (flag == 1 && comm == 1) || (flag == 2 && comm == 2) )
      type = 3;

// обновляется не только изображение но и меню для запроса
    switch ( type  ) {
      case 1:
        docActive->ksCircle( 0, 0, 20, 1 );
        info->commandsString = TO_OLE(L"!Квадрат !Треугольник ");
        flag = 1;
        break;
      case 2:
        docActive->ksLineSeg( -10, 0,  10,  0,  1 );
        docActive->ksLineSeg( 10,  0,  0,   20, 1 );
        docActive->ksLineSeg( 0,   20, -10, 0,  1 );
        info->commandsString = TO_OLE(L"!Окружность !Квадрат ");
        flag = 2;
        break;
      case 3:
        docActive->ksLineSeg( -10, 0,  10,  0,  1 );
        docActive->ksLineSeg( 10,  0,  10,  20, 1 );
        docActive->ksLineSeg( 10,  20, -10, 20, 1 );
        docActive->ksLineSeg( -10, 20, -10, 0,  1 );
        info->commandsString = TO_OLE(L"!Окружность !Треугольник ");
        flag = 0;
        break;
    }

    docActive->ksEndGroup();
  }
  return 1;
}

//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Placement
// ---
extern "C" int __export __stdcall CALLBACKPROCPLACEMENT( int comm, double* x, double* y, double* ang, LPDISPATCH rInfo,
                                  LPDISPATCH rPhan, int dynamic ) {
  kompas->ksMessage(  TO_OLE(L"пришли в пласемент") );
  ksRequestInfoPtr info( (ksRequestInfo*)rInfo, true/*AddRef*/ );
  ksPhantomPtr     phan( (ksPhantom*)rPhan, true/*AddRef*/ );
  if ( (bool)info && (bool)phan ) {
    ksType1Ptr t1( (ksType1*)phan->GetPhantomParam(), false/*AddRef*/ );
    switch ( comm ) {
      case 1:
      case 2: type = comm; break;
      case -1 : {                 // поставить в модель
        docActive->ksMoveObj( t1->gr, *x, *y );
// отлтчте от Cursor угол приходит в виде параметра функции
        if ( ::fabs(*ang) > 0.001 )
          docActive->ksRotateObj( t1->gr, *x, *y, *ang );
        docActive->ksStoreTmpGroup( t1->gr );    // поставить временную группу в вид
        docActive->ksClearGroup( t1->gr, true );
        break;
      }
    }

// группа для фантома должна быть временная и обновляться при изменении вида отрисовки
    if ( t1->gr )
      docActive->ksDeleteObj( t1->gr );
    t1->gr = docActive->ksNewGroup( 1 );   // временная группа

// обновляется не только изображение но и меню для запроса
    if ( (flag == 1 && comm == 1) || (flag == 2 && comm == 2) )
      type = 3;

    switch ( type ) {
      case 1:
        docActive->ksCircle( 0, 0, 20, 1 );
        info->commandsString = TO_OLE(L"!Квадрат !Треугольник ");
        flag = 1;
        break;
      case 2:
        docActive->ksLineSeg( -10,  0,  10,  0, 1 );
        docActive->ksLineSeg(  10,  0,   0, 20, 1 );
        docActive->ksLineSeg(   0, 20, -10,  0, 1 );
        info->commandsString = TO_OLE(L"!Окружность !Квадрат ");
        flag = 2;
        break;
      case 3:
        docActive->ksLineSeg( -10,  0,  10,  0, 1 );
        docActive->ksLineSeg(  10,  0,  10, 20, 1 );
        docActive->ksLineSeg(  10, 20, -10, 20, 1 );
        docActive->ksLineSeg( -10, 20, -10,  0, 1 );
        info->commandsString = TO_OLE(L"!Окружность !Треугольник ");
        flag = 0;
        break;
    }

    docActive->ksEndGroup();
  }

  return 1;
}

//------------------------------------------------------------------------------
// Функция обратной связи для placment
// ---
void DrawRectCallBack( ksDocument2DPtr & doc ) {
  docActive = doc;
  type      = 1;
  ksPhantomPtr phan( (ksPhantom*)kompas->GetParamStruct(ko_Phantom), false/*AddRef*/ );
  if ( phan ) {
    phan->Init();
    phan->phantom = 1;
    ksType1Ptr t1( (ksType1*)phan->GetPhantomParam(), false/*AddRef*/ );
    if ( t1 ) {
      t1->Init();
      t1->scale_ = 1;
      t1->gr = doc->ksNewGroup( 1 );   // временная группа
        doc->ksCircle( 0, 0, 20, 1 );
      doc->ksEndGroup();

      double x, y, ang;
      ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
      if ( info ) {
        info->Init();
        info->commandsString =  TO_OLE(L"!Квадрат !Треугольник");
        // указываем адрес обратной функции для Placement
        info->SetCallBackP(  TO_OLE(L"_CALLBACKPROCPLACEMENT"), (long)hinstance, 0 );
        doc->ksPlacement( info, &x, &y, &ang, phan );

        t1->gr = doc->ksNewGroup( 1 );   // временная группа
          doc->ksCircle( 0, 0, 20, 1 );
        doc->ksEndGroup();

        // указываем адрес обратной функции для Cursor
        info->SetCallBackC(  TO_OLE(L"CALLBACKPROCCURSOR"), (long)hinstance, 0 );
        doc->ksCursor( info, &x, &y, phan );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Функция обратной связи для placment
// ---
void DrawRectNULL( ksDocument2DPtr & doc ) {
  int type = 1, flag=1;
  int j = 1;
  ksPhantomPtr phan( (ksPhantom*)kompas->GetParamStruct(ko_Phantom), false/*AddRef*/ );
  if ( phan ) {
    phan->Init();
    phan->phantom = 1;
    ksType1Ptr t1( (ksType1*)phan->GetPhantomParam(), false/*AddRef*/ );
    if ( t1 ) {
      t1->Init();
      t1->scale_ = 1;
      t1->gr = 0;   // временная группа

      double x, y, ang;
      ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
      if ( info ) {
        info->Init();
        while ( j ) {

          if ( t1->gr )
            doc->ksDeleteObj( t1->gr );

          t1->gr = doc->ksNewGroup( 1 ); // временная группа
          if ( (flag == 1 && j == 1) || (flag == 2 && j == 2) )
            type = 3;

          switch ( type ) {
            case 1:
              doc->ksCircle( 0, 0, 20, 1 );
              info->commandsString = TO_OLE(L"!Квадрат !Треугольник ");
              flag = 1;
              break;
            case 2:
              doc->ksLineSeg( -10, 0,  10,  0,  1 );
              doc->ksLineSeg( 10,  0,  0,   20, 1 );
              doc->ksLineSeg( 0,   20, -10, 0,  1 );
              info->commandsString = TO_OLE(L"!Окружность !Квадрат ");
              flag = 2;
              break;
            case 3:
              doc->ksLineSeg( -10, 0,  10,  0,  1 );
              doc->ksLineSeg( 10,  0,  10,  20, 1 );
              doc->ksLineSeg( 10,  20, -10, 20, 1 );
              doc->ksLineSeg( -10, 20, -10, 0,  1 );
              info->commandsString = TO_OLE(L"!Окружность !Треугольник ");
              flag = 0;
              break;
          }

          doc->ksEndGroup();

          j = doc->ksPlacement( info, &x, &y, &ang, phan );
//        j = doc->ksCursor( info, &x, &y, phan );
          switch ( j ) {
            case 1:
            case 2: type = j; break;
            case -1: //поставить в модель
              doc->ksMoveObj( t1->gr, x, y );
              if ( ::fabs(t1->angle) > 0.001 )
                doc->ksRotateObj( t1->gr, x, y, ang /*t1->angle*/ );
              doc->ksStoreTmpGroup( t1->gr );    // поставить временную группу в вид
              doc->ksClearGroup( t1->gr, true );
              break;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Пример отрисовки слайда
// ---
void WriteSlideStep( ksDocument2DPtr & doc ) {
  //выберем файл для записи
  WideString name( kompas->ksSaveFile( TO_OLE(L"*.rc"), NULL, NULL, false) );
  if ( !name.IsEmpty() ) {
    ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
    if ( info ) {
      info->Init();
      info->commandsString =  TO_OLE(L"Укажите точку привязки слайда");
      // точка привязки слайда - верхний левый угол габаритного прямоугольника слайда
      double x, y;
      if ( doc->ksCursor(info, &x, &y, NULL) ) {
        long slideID;
        if ( kompas->ksReadInt( TO_OLE(L"Введите идентификатор слайда"), 100, 0, 32000, &slideID) ) {
          if ( !kompas->ksWriteSlide( TO_OLE(name), slideID, x,  y) )
            kompas->ksError(  TO_OLE(L"Группа селектирования пуста") );
          doc->ksClearGroup( 0, true );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// отрисовать слайд ( описание в файле step4_3.cpp )
// ---
void TestShowDialog( ksDocument2DPtr & doc ) {
  Application->Handle = (HWND)kompas->ksGetHWindow();
  // создаем диалог - хендл окна компаса не нужен, вижал сам разбирается
  TTestSlideDlg* dlg = new TTestSlideDlg( Application, doc );
  if ( dlg ) {
    kompas->ksEnableTaskAccess( 0 ); // закрыть доступ к компасу
    dlg->ShowModal();                // вывод диалога
    kompas->ksEnableTaskAccess( 1 ); // открыть доступ к компасу
    delete dlg;
  }
  Application->Handle = 0;
}

//------------------------------------------------------------------------------
// Работа с относительными путями файлов
// ---
void WorkRelativePath () {
  //имя задающего файла
  WideString mainName( kompas->ksChoiceFile( TO_OLE(L"*.*"),  TO_OLE(L"Все файлы (*.*)|*.*|"), true) );
  WideString fileName( kompas->ksChoiceFile( TO_OLE(L"*.*"),  TO_OLE(L"Все файлы (*.*)|*.*|"), true) );
  if ( !mainName.IsEmpty() && !fileName.IsEmpty() ) {
    // относительный путь
    WideString relName( kompas->ksGetRelativePathFromFullPath( TO_OLE(mainName),    // полный путь к задающему файлу
                                                               TO_OLE(fileName)) ); // полный путь к требуемому файлу

    WideString mess( L"Задающий файл : " );
    mess += mainName;
    mess +=  L" \n";
    mess +=  L"Полный путь : ";
    mess += fileName ;
    mess +=  L" \n";
    mess +=  L"Относительный путь : ";
    mess += relName ;
    kompas->ksMessage( TO_OLE(mess) );

    // полный путь
    WideString fullName( kompas->ksGetFullPathFromRelativePath( TO_OLE(mainName),   // полный путь к задающему файлу
                                                                TO_OLE(relName)) ); // относительный путь к требуемому файлу( без общей с задающим файлом части пути )
    mess =  L"Задающий файл : ";
    mess += mainName;
    mess += L" \n";
    mess += L"Относительный путь : ";
    mess += relName ;
    mess += L" \n";
    mess += L"Полный путь : ";
    mess += fullName;
    mess += L" \n";
    kompas->ksMessage( TO_OLE(mess) );
  }
}

//------------------------------------------------------------------------------
// Работа с системными каталогами
// ---
void WorkSystemPath( ksDocument2DPtr & doc ) {
  wchar_t * catalogName[] = { L"каталог системных файлов",
                              L"каталог библиотек"       ,
                              L"каталог временных файлов",
                              L"каталог конфигурации"   ,
                              L"INI-файл" };
  // сформировать  полный путь к заданному файлу
  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
  if ( info ) {
    info->Init();
    info->title =  TO_OLE(L"Каталоги файлов системы");
    info->commandsString =  TO_OLE(L"!Системные !Библиотеки !Временные !Конфигурация !INI-файл ");
    info->prompt =  TO_OLE(L"Выберите нужный каталог");
    int j;
    static wchar_t* buf = L"user.ttt";
    WideString fileName;
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
        fileName = kompas->ksGetFullPathFromSystemPath( TO_OLE(buf),    // относительный путь к файлу( без системного пути )
                                                        typeCatalog ); // путь установленного типа см. ksSystemPath
        WideString mess( L"Полный путь к файлу user.ttt \n" );
        mess +=  catalogName[j - 1];
        mess += L" :\n";
        mess += fileName ;
        kompas->ksMessage( TO_OLE(mess) );

        //относительный путь
        WideString relName( kompas->ksGetRelativePathFromSystemPath(TO_OLE(fileName),      // полный путь к файлу
                                                                    typeCatalog ) ); // путь установленного типа см. ksSystemPath
        mess = L"Относительный путь к файлу \n";
        mess += fileName;
        mess += L"\n";
        mess +=  catalogName[j -1];
        mess += L" :\n";
        mess += relName;
        kompas->ksMessage( TO_OLE(mess) );

      }
    } while ( j > 0 );
  }
}



