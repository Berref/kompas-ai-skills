// step2a.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step2a.h"

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
// CStep2aApp

BEGIN_MESSAGE_MAP(CStep2aApp, CWinApp)
  //{{AFX_MSG_MAP(CStep2aApp)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep2aApp construction

CStep2aApp::CStep2aApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep2aApp object

CStep2aApp theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDS_LIBID;
}

KompasObjectPtr kompas;

void PointIndefiniteArray();
void TextIndefiniteArray();
void StrIndefiniteArray();
void AttrIndefiniteArray();
void PolyLineArray();
void RectArray();

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
  if ( kompas ) {
    switch ( comm ) {
    case 1  : ::StrIndefiniteArray();     break; // массив строк
    case 2  : ::PointIndefiniteArray();   break; // массив математических точек
    case 3  : ::TextIndefiniteArray();    break; // массив строк объекта "текст"
    case 4  : ::AttrIndefiniteArray();    break; // массив колонок типа атрибута
    case 5  : ::PolyLineArray();          break; // массив полилиний
    case 6  : ::RectArray();              break; // массив габаритных прямоугольников
    }
  }
}

//--------------------------------------------------------------------------
//  массив предназначен для создания и получения параетров параграфа текста,
//  состоящего из   нескольких строк, которые в свою очередь
//  состоят из компонент, с разными параметрами
//  ( с наклоном, с утолщением, спецзнаки и т. д.)
//--------------------------------------------------------------------------
void TextIndefiniteArray() {
  TCHAR buf[128];
  ksTextLineParamPtr par ( kompas->GetParamStruct(ko_TextLineParam) );
  ksTextItemParamPtr par1( kompas->GetParamStruct(ko_TextItemParam) );
  // создали массив строк текста
  ksDynamicArrayPtr  p   ( kompas->GetDynamicArray(TEXT_LINE_ARR)   );
  if ( par && par1 && p ) {
    par->Init();
    par1->Init();
    // массив компонент строки текста
    ksDynamicArrayPtr p1( par->GetTextItemArr() );
    if ( p1 ) {
      ksTextItemFontPtr font( par1->GetItemFont() );
      if ( font ) {
        // создаем первую строку текста
        font->height = 10;   // высота текста
        font->ksu    = 1;       // сужение текста
        font->color  = 1000;  // цвет
        font->bitVector = 1; // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
        par1->s = _T("1 компонента 1 строка");
        // добавили 1-ю компоненту  в массив компонент
        p1->ksAddArrayItem( -1, par1 );

        font->height    = 20;   // высота текста
        font->ksu       = 2;    // сужение текста
        font->color     = 2000; // цвет
        font->bitVector = 2;    // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
        par1->s         = _T("2 компонента 1 строка");
        // добавили 2-ю компоненту  в массив компонент
        p1->ksAddArrayItem( -1, par1 );
        par->style = 1;

        // 1-я строка текста состоит из двух компонент добавим строку текста в
        // массив строк текста
        p->ksAddArrayItem( -1, par );

        // очистили массив компонент, чтобы использовать для создания второй
        // строки текста
        p1->ksClearArray();

        // создаем вторую строку текста
        font->height    = 30;    // высота текста
        font->ksu       = 3;     // сужение текста
        font->color     = 3000;  // цвет
        font->bitVector = 3;     // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
        par1->s         = _T("1 компонента 2 строка");
        // добавили 1-ю компоненту  в массив компонент
        p1->ksAddArrayItem( -1, par1 );

        font->height    = 40;   // высота текста
        font->ksu       = 4;    // сужение текста
        font->color     = 4000; // цвет
        font->bitVector = 4;    // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
        par1->s         = _T("2 компонента 2 строка");
        // добавили 2-ю компоненту  в массив компонент
        p1->ksAddArrayItem( -1, par1 );

        par->style      = 2;

        // 2-я строка текста состоит из двух компонент добавим строку текста в
        // массив строк текста     }
        p->ksAddArrayItem( -1, par );

        kompas->ksMessageBoxResult();

        int n = p->ksGetArrayCount();
        ::_stprintf_s( buf, _T("n = %d"), n );
        kompas->ksMessage( buf );
        // просмотрим массив строк текста
        for ( int i = 0; i < n; i++ ) {  // цикл по строкам текста
          p->ksGetArrayItem( i, par );
          ::_stprintf_s( buf, _T("i = %d: style = %d,"), i, par->style );
          kompas->ksMessage( buf );

          int n1 = p1->ksGetArrayCount();
          for ( int j = 0; j < n1; j++ ) {  // цикл по компонентам строки текста
            p1->ksGetArrayItem( j, par1 );
            ::_stprintf_s( buf, _T("j = %d:  h = %5.1f, s = %s"), j, font->height, (LPCTSTR)par1->s );
            kompas->ksMessage( buf );
          }
        }

        kompas->ksMessageBoxResult(); // проверяем результат работы нашей функции

        // заменим вторую компоненту у первой строки
        p->ksGetArrayItem( 0, par );
        font->height    = 50;   // высота текста
        font->ksu       = 1;    // сужение текста
        font->color     = 1000; // цвет
        font->bitVector = 1;    // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
        par1->s = _T("2 комп. 1 стр.");
        p1->ksSetArrayItem( 1, par1 );
        par->style = 3;
        p->ksSetArrayItem( 0, par );

        // заменим первую компоненту у второй строки
        p->ksGetArrayItem( 1, par );
        font->height    = 60;   // высота текста
        font->ksu       = 1;    // сужение текста
        font->color     = 1000; // цвет
        font->bitVector = 1;    // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
        par1->s = _T("1 комп. 2 стр.");
        p1->ksSetArrayItem( 0, par1 );
        par->style = 4;
        p->ksSetArrayItem( 1, par );

        n = p->ksGetArrayCount();
        // просмотрим массив строк текста
        for ( int i = 0; i < n; i++ ) // цикл по строкам текста
        {
          p->ksGetArrayItem( i, par );
          ::_stprintf_s( buf, _T("i = %d: style = %d"), i, par->style );
          kompas->ksMessage( buf );

          int n1 = p1->ksGetArrayCount();
          for ( int j = 0; j < n1; j++ ) // цикл по компонентам строки текста
          {  
            p1->ksGetArrayItem( j, par1 );
            ::_stprintf_s( buf, _T("j = %d:  h = %5.1f, s = %s"), j, font->height, (LPCTSTR)par1->s );
            kompas->ksMessage( buf );
          }
        }

        kompas->ksMessageBoxResult(); // проверяем результат работы нашей функции

        p1->ksDeleteArray();
        p->ksDeleteArray();
      }
    }
  }  
}


//--------------------------------------------------------------------------
//  массив предназначен для хранения математических точек типа  MathPointParam
//--------------------------------------------------------------------------
void PointIndefiniteArray() {
  TCHAR buf[128];
  ksMathPointParamPtr par( kompas->GetParamStruct(ko_MathPointParam) );
  // создать массив
  ksDynamicArrayPtr   p  ( kompas->GetDynamicArray(POINT_ARR) );
  if ( p && par ) {
    // наполнить массив
    par->Init();
    par->x = 10;
    par->y = 10;
    p->ksAddArrayItem( -1, par );
    par->x = 20;
    par->y = 20;
    p->ksAddArrayItem( -1, par );
    par->x = 30;
    par->y = 30;
    p->ksAddArrayItem( -1, par );

    kompas->ksMessageBoxResult();

    // просмотрим массив
    int n = p->ksGetArrayCount();
    ::_stprintf_s( buf, _T("n = %d"), n );
    kompas->ksMessage( buf );

    for ( int i = 0; i < n; i++ ) {
      p->ksGetArrayItem( i, par );
      ::_stprintf_s( buf, _T("i = %d:  x = %5.1f, y = %5.1f"), i, par->x, par->y );
      kompas->ksMessage( buf );
    }

    // заменим параметры 1-го элемента
    par->x = 50;
    par->y = 50;
    p->ksSetArrayItem( 1, par );

    // заменим параметры 0-го элемента
    par->x = 60;
    par->y = 60;
    p->ksSetArrayItem( 0, par );

    // просмотрим массив
    n = p->ksGetArrayCount();
    for ( int i = 0; i < n; i++ ) {
      p->ksGetArrayItem( i, par );
      ::_stprintf_s( buf, _T("i = %d:  x = %5.1f, y = %5.1f"), i, par->x, par->y );
      kompas->ksMessage( buf );
    }

    kompas->ksMessageBoxResult();

    p->ksDeleteArray();
  }
}

//--------------------------------------------------------------------------
//  массив предназначен для хранения строк
//--------------------------------------------------------------------------
void StrIndefiniteArray() {
  TCHAR buf[128];
  // создать массив
  ksChar255Ptr      charS( kompas->GetParamStruct(ko_Char255) );
  ksDynamicArrayPtr p    ( kompas->GetDynamicArray(CHAR_STR_ARR) );
  if ( p && charS ) {
    charS->Init();
    // наполним массив
    charS->str = _T("12345");
    p->ksAddArrayItem( -1, charS );
    charS->str = _T("67890");
    p->ksAddArrayItem( -1, charS );
    charS->str = _T("qwerty");
    p->ksAddArrayItem( -1, charS );

    kompas->ksMessageBoxResult();

    // просмотрим массив
    int n = p->ksGetArrayCount();
    ::_stprintf_s( buf, _T("n = %d"), n );
    kompas->ksMessage( buf );

    for ( int i = 0; i < n; i++ ) {
      p->ksGetArrayItem( i, charS );
      kompas->ksMessage( charS->str );
    }

    // исключить из массива эл 1
    p->ksExcludeArrayItem( 1 );
    n = p->ksGetArrayCount();

    // просмотрим массив
    for ( int i = 0; i < n; i++ ) {
      p->ksGetArrayItem( i, charS );
      kompas->ksMessage( charS->str );
    }

    kompas->ksMessageBoxResult();

    p->ksDeleteArray();
  }
}

//-------------------------------------------------------------------------------
// 
// ---
static void ShowColumns( ksDynamicArrayPtr& pCol, bool fl ) {
  ksColumnInfoParamPtr par( kompas->GetParamStruct(ko_ColumnInfoParam) );
  if ( par ) {
    par->Init();
    
    TCHAR buf[128];
    TCHAR s[10];
    if ( fl )
      ::_tcscpy_s( s, _T("структура") );
    else
      s[0]='\0';

    int n = pCol->ksGetArrayCount();

    for ( int i = 0; i < n; i++ ) {
      if ( !pCol->ksGetArrayItem(i, par) )
        kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
      else {
        //выдадим поля колонки не указатели
        ::_stprintf_s( buf, _T("%s i=%d header=%s type=%d def=%s flagEnum=%d"), s, i, (LPCTSTR)par->header,
                   par->type, (LPCTSTR)par->def, par->flagEnum );
        kompas->ksMessage( buf );
        if ( par->type == RECORD_ATTR_TYPE )  
        { // структура
          ksDynamicArrayPtr pCol( par->GetColumns() );
          if ( pCol ) 
          {
            ::ShowColumns( pCol, true );
            pCol->ksDeleteArray();
          }
        }
        else {
          if ( par->flagEnum ) { // выдадим массив перечислений
            ksDynamicArrayPtr fEnum( par->GetFieldEnum() );
            if ( fEnum ) {
              int n1 = fEnum->ksGetArrayCount();
              kompas->ksMessage( _T("массив перечислений") );
              ksChar255Ptr charS( kompas->GetParamStruct(ko_Char255) );
              for ( int i1 = 0; i1 < n1; i1++ ) 
                if ( !fEnum->ksGetArrayItem( i1, charS) )
                  kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
                else 
                  kompas->ksMessage( charS->str );
            }
          }
        }
      }
    }
  }
}

//--------------------------------------------------------------------------
//  массив предназначен для создания и получения типа атрибута,
//  который может состоять из нескольких колонок
//---------------------------------------------------------------------------
void AttrIndefiniteArray(){
/*
 создадим массив из 3 колонок
 первая колонка описывает  int с перечисленными значениями ( 100, 200, 300 )
 вторая колонка - запись соответствует структуре
 struct {
   double ;// умолчательное значение 123456789
   long   ;// умолчательное значение 1000000
   char   ;// умолчательное значение 10
 }
 третья колонка строка символов умолчательное значение "text"
*/
  ksColumnInfoParamPtr parCol1  ( kompas->GetParamStruct(ko_ColumnInfoParam) );
  ksColumnInfoParamPtr parCol2  ( kompas->GetParamStruct(ko_ColumnInfoParam) );
  ksColumnInfoParamPtr parCol3  ( kompas->GetParamStruct(ko_ColumnInfoParam) );
  ksColumnInfoParamPtr parStruct( kompas->GetParamStruct(ko_ColumnInfoParam) );
  ksDynamicArrayPtr    pCol     ( kompas->GetDynamicArray(ATTR_COLUMN_ARR)   );
  ksChar255Ptr         charS    ( kompas->GetParamStruct(ko_Char255)         );
  if ( parCol1 && parCol2   && parCol3
               && parStruct && charS && pCol ) 
  {
    // первая колонка
    parCol1->Init();
    parCol1->header   = _T("int");     // заголовoк-комментарий столбца
    parCol1->type     = INT_ATTR_TYPE; // тип данных в столбце - см.ниже
    parCol1->key      = 0;             // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    parCol1->def      = _T("100");     // значение по умолчанию
    parCol1->flagEnum = true;          // флаг включающий режим, когда значение поля атрибута будет заполнятся из массива перечисленных значений

    ksDynamicArrayPtr pEnum( kompas->GetDynamicArray(CHAR_STR_ARR) );
    if ( pEnum ) {
      //заполним массив перечисленных значений для первой колонки
      charS->Init();
      charS->str = _T("100");
      pEnum->ksAddArrayItem( -1, charS );
      charS->str = _T("200");
      pEnum->ksAddArrayItem( -1, charS );
      charS->str = _T("300");
      pEnum->ksAddArrayItem( -1, charS );

      parCol1->SetFieldEnum( pEnum );      // массив неопределенной длины перечислений (строки)
    }

    pCol->ksAddArrayItem( -1, parCol1 );

    // вторая колонка
    parCol2->Init();
    parCol2->header   = _T("struct");     // заголовoк-комментарий столбца
    parCol2->type     = RECORD_ATTR_TYPE; // тип данных в столбце - см.ниже
    parCol2->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    parCol2->def      = _T("\0");         // значение по умолчанию
    parCol2->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута будет заполнятся из массива перечисленных значений
    
    ksDynamicArrayPtr pStruct( kompas->GetDynamicArray(ATTR_COLUMN_ARR) );
    if ( pStruct ) {
      // заполним массив солонок для структуры
      // первая колонка  структуры
      parStruct->Init();
      parStruct->header = _T("double");     // заголовoк-комментарий столбца
      parStruct->type   = DOUBLE_ATTR_TYPE; // тип данных в столбце - см.ниже
      parStruct->def    = _T("123456789");  // значение по умолчанию
      pStruct->ksAddArrayItem( -1, parStruct );

      // вторая колонка структуры
      parStruct->Init();
      parStruct->header = _T("long ");    // заголовoк-комментарий столбца
      parStruct->type   = LINT_ATTR_TYPE; // тип данных в столбце - см.ниже
      parStruct->def    = _T("1000000");  // значение по умолчанию
      pStruct->ksAddArrayItem( -1, parStruct );

      // третья колонка структуры
      parStruct->Init();
      parStruct->header = _T("char");      // заголовoк-комментарий столбца
      parStruct->type   = CHAR_ATTR_TYPE;  // тип данных в столбце - см.ниже
      parStruct->def    = _T("10");        // значение по умолчанию
      pStruct->ksAddArrayItem( -1, parStruct );

      parCol2->SetColumns( pStruct );      // массив неопределенной длины информации о колонках для записи
    }

    pCol->ksAddArrayItem( -1, parCol2 );

    // третья  колонка
    parCol3->Init();
    parCol3->header = _T("string");        // заголовoк-комментарий столбца
    parCol3->type   = STRING_ATTR_TYPE;    // тип данных в столбце - см.ниже
    parCol3->key    = 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    parCol3->def    = _T("text");          // значение по умолчанию

    pCol->ksAddArrayItem( -1, parCol3 );

    kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции

    // просмотрим массив колонок
    ::ShowColumns( pCol, false ); // функция пользователя

    kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции

    // поменяем  колонки местами 2->1 1->3 3->2
    pCol->ksSetArrayItem( 0, parCol2 );
    pCol->ksSetArrayItem( 2, parCol1 );
    pCol->ksSetArrayItem( 1, parCol3 );

    // просмотрим массив колонок
    ::ShowColumns( pCol, false ); // функция пользователя

    kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
  
    pStruct->ksDeleteArray();
    pEnum->ksDeleteArray();
    pCol->ksDeleteArray();
  }
}

//-------------------------------------------------------------------------------
// массив полилиний это массив массивов математических точек
//-------------------------------------------------------------------------------
void PolyLineArray() {
  TCHAR buf[128];
  ksMathPointParamPtr par( kompas->GetParamStruct(ko_MathPointParam) );
  //создадим массив точек
  ksDynamicArrayPtr arrPoint( kompas->GetDynamicArray(POINT_ARR) );
  //создадим массив полилиний
  ksDynamicArrayPtr arrPoly( kompas->GetDynamicArray(POLYLINE_ARR) );
  if ( par && arrPoint &&arrPoly ) {
    //наполним массив точек
    par->x = 10;
    par->y = 10;
    arrPoint->ksAddArrayItem( -1, par );
    par->x = 100;
    par->y = 100;
    arrPoint->ksAddArrayItem( -1, par );
    par->x = 1000;
    par->y = 1000;
    arrPoint->ksAddArrayItem( -1, par );
    //добавим массив точек в массив полилиний
    arrPoly->ksAddArrayItem( -1, arrPoint );
    kompas->ksMessageBoxResult();

    //наполним массив точек
    arrPoint->ksClearArray();
    par->x = 20;
    par->y = 20;
    arrPoint->ksAddArrayItem( -1, par );
    par->x = 200;
    par->y = 200;
    arrPoint->ksAddArrayItem( -1, par );
    par->x = 2000;
    par->y = 2000;
    arrPoint->ksAddArrayItem( -1, par );
    //добавим массив точек в массив полилиний
    arrPoly->ksAddArrayItem( -1, arrPoint );
    kompas->ksMessageBoxResult();

    //наполним массив точек
    arrPoint->ksClearArray();
    par->x = 30;
    par->y = 30;
    arrPoint->ksAddArrayItem( -1, par );
    par->x = 300;
    par->y = 300;
    arrPoint->ksAddArrayItem( -1, par );
    par->x = 3000;
    par->y = 3000;
    arrPoint->ksAddArrayItem( -1, par );
    //добавим массив точек в массив полилиний
    arrPoly->ksAddArrayItem( -1, arrPoint );
    kompas->ksMessageBoxResult();

    int count = arrPoly->ksGetArrayCount();
    ::_stprintf_s( buf, _T("n=%d"), count );
    kompas->ksMessage( buf );

    arrPoly->ksGetArrayItem( 1, arrPoint );
    //просмоьрим 2-ой элемент массива полилиний
    count = arrPoint->ksGetArrayCount();
    for ( int i = 0; i < count; i++ ) {
      arrPoint->ksGetArrayItem( i, par );
      ::_stprintf_s( buf, _T("i=%d, x=%g, y=%g"), i, par->x, par->y );
      kompas->ksMessage( buf );
    }

    //заменим у 2 -го элемента массива полилиний 2-ой элемент
    par->x = 50;
    par->y = 50;
    arrPoint->ksSetArrayItem( 1, par );
    par->x = 500;
    par->y = 500;
    arrPoint->ksSetArrayItem( 0, par );
    arrPoly->ksSetArrayItem( 1, arrPoint );

    count = arrPoly->ksGetArrayCount();
    for ( int i = 0; i < count; i++ )
    {
      arrPoly->ksGetArrayItem( i, arrPoint );
      int n = arrPoint->ksGetArrayCount();
      for ( int j = 0; j < n; j++ ) {
        arrPoint->ksGetArrayItem( j, par );
        ::_stprintf_s( buf, _T("i=%d, j=%d, x=%g, y=%g"), i, j, par->x, par->y );
        kompas->ksMessage( buf );
      }
    }
    kompas->ksMessageBoxResult();
    arrPoint->ksDeleteArray();
    arrPoly->ksDeleteArray();
  }
}

//--------------------------------------------------------------------------------
// массив неопределенной длины габаритных прямоугольников-(структура RectParam)
//--------------------------------------------------------------------------------
void RectArray() {
  ksRectParamPtr      par ( kompas->GetParamStruct(ko_RectParam) ); // параметры прямоугольника
  ksDynamicArrayPtr   arr ( kompas->GetDynamicArray(RECT_ARR) );    // создать массив
  ksMathPointParamPtr pBot( kompas->GetParamStruct(ko_MathPointParam) );
  ksMathPointParamPtr pTop( kompas->GetParamStruct(ko_MathPointParam) );
  if ( arr && par && pBot && pTop ) {
    //наполнить массив
    pTop->x = 10;
    pTop->y = 10;
    par->SetpTop( pTop );
    pBot->x = 20;
    pBot->y = -10;
    par->SetpBot( pBot );
    arr->ksAddArrayItem( -1, par );

    pTop->x = 20;
    pTop->y = 50;
    par->SetpTop( pTop );
    pBot->x = 50;
    pBot->y = 10;
    par->SetpBot( pBot );
    arr->ksAddArrayItem( -1, par );

    pTop->x = 20;
    pTop->y = 150;
    par->SetpTop( pTop );
    pBot->x = 50;
    pBot->y = 110;
    par->SetpBot( pBot );
    arr->ksAddArrayItem( -1, par );
    kompas->ksMessageBoxResult();

    //просмотреть массив
    int n = arr->ksGetArrayCount();

    TCHAR buf[255];
    ::_stprintf_s( buf, _T("n = %d"), n );
    kompas->ksMessage( buf );

    for ( int i = 0; i < n; i++ ) {
      arr->ksGetArrayItem( i, par );
      pBot = par->GetpBot();
      pTop = par->GetpTop();
      ::_stprintf_s( buf, _T("i=%d, x1=%5.1f, y1=%5.1f,\nx2=%5.1f, y2=%5.1f"), i, 
                 pTop->x, pTop->y, pBot->x, pBot->y );
      kompas->ksMessage( buf );
    }

    //редактируем массив
    pTop->x = -20;
    pTop->y = -50;
    par->SetpTop( pTop );
    pBot->x = 20;
    pBot->y = -10;
    par->SetpBot( pBot );
    arr->ksSetArrayItem( 1, par );

    pTop->x = 0;
    pTop->y = 0;
    par->SetpTop( pTop );
    pBot->x = 10;
    pBot->y =-20;
    par->SetpBot( pBot );
    arr->ksSetArrayItem( 0, par );

    pTop->x = 5;
    pTop->y = 5;
    par->SetpTop( pTop );
    pBot->x = 25;
    pBot->y = 0;
    par->SetpBot( pBot );
    arr->ksAddArrayItem( -1, par );

    //просмотрим массив
    n = arr->ksGetArrayCount();
    for ( int i = 0; i < n; i++ ) {
      arr->ksGetArrayItem( i, par );
      pBot = par->GetpBot();
      pTop = par->GetpTop();
      ::_stprintf_s( buf, _T("i=%d, x1=%5.1f, y1=%5.1f,\nx2=%5.1f, y2=%5.1f"), i, 
                     pTop->x, pTop->y, pBot->x, pBot->y );
      kompas->ksMessage( buf );
    }
    kompas->ksMessageBoxResult();

    //удалить массив
    arr->ksDeleteArray();
  }
}
