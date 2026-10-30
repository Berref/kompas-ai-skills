//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include <windows.h>
#include <stdio.h>

#include <ldefin2d.h>
#include <ksConstants.h>

#ifdef __LIGHT_VERSION__
#include <Kl_TLB.h>
#else
#include <Ks_TLB.h>
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


//------------------------------------------------------------------------------
//
// ---
#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  return 1;
}

//------------------------------------------------------------------------------
//
// ---
extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return 100;
}

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch* far __export WINAPI CreateKompasObject();

KompasObjectPtr kompas;

void StrIndefiniteArray();
void PointIndefiniteArray();
void TextIndefiniteArray();
void AttrIndefiniteArray();
void PolyLineArray();
void RectArray();

extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
		switch ( comm ) {
     case 1: // массив строк
       StrIndefiniteArray();
       break;
     case 2: // массив точек
       PointIndefiniteArray();
       break;
     case 3: // массив строк объекта "текст"
       TextIndefiniteArray();
       break;
     case 4: // массив колонок типа атрибута
       AttrIndefiniteArray();
       break;
     case 5: // массив полилиний
       PolyLineArray();
       break;
     case 6: // массив габаритных прямоугольников
       RectArray();
        break;
    }
    kompas.Unbind();
  }
}

//------------------------------------------------------------------------------
//
// ---
void StrIndefiniteArray() {
  //  создать массив
  ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( CHAR_STR_ARR ), false/*AddRef*/ );
  ksChar255Ptr      charBuf( (ksChar255*)kompas->GetParamStruct( ko_Char255 ), false/*AddRef*/ );
  if ( (bool)arr && (bool)charBuf ) {
    charBuf->str = TO_OLE(L"12345");
    // наполним массив
    arr->ksAddArrayItem( -1, charBuf );

    charBuf->str = TO_OLE(L"67890");
    arr->ksAddArrayItem( -1, charBuf );

    charBuf->str = TO_OLE(L"qwerty");
    arr->ksAddArrayItem( -1, charBuf );

    kompas->ksMessageBoxResult();

    // просмотрим массив
    int n = arr->ksGetArrayCount();

    char buf[128];
    sprintf( buf, " n = %d ", n );
    kompas->ksMessage( TO_OLE(buf) );

    for( int i = 0; i < n; i++ ) {
      arr->ksGetArrayItem( i, charBuf );
      kompas->ksMessage( charBuf->str );
    }

    // исключить из массива эл 1
    arr->ksExcludeArrayItem( 1 );
    n = arr->ksGetArrayCount();

    // просмотрим массив
    for ( int i = 0; i < n; i++ ) {
      arr->ksGetArrayItem( i, charBuf );
      kompas->ksMessage( charBuf->str );
    }

    kompas->ksMessageBoxResult();
    arr->ksDeleteArray();
  }
}

//------------------------------------------------------------------------------
//
// ---
void PointIndefiniteArray() {
  ksMathPointParamPtr mathPar( (ksMathPointParam*)kompas->GetParamStruct( ko_MathPointParam ), false/*AddRef*/ );
  ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( POINT_ARR ), false/*AddRef*/ );
  if ( (bool)mathPar && (bool)arr ) {
    mathPar->x = 10;
    mathPar->y = 10;
    arr->ksAddArrayItem( -1, mathPar );

    mathPar->x = 20;
    mathPar->y = 20;
    arr->ksAddArrayItem( -1, mathPar );

    mathPar->x = 30;
    mathPar->y = 30;
    arr->ksAddArrayItem( -1, mathPar );

    kompas->ksMessageBoxResult();

    // просмотрим массив
    int n = arr->ksGetArrayCount();
    char buf[128];
    ::sprintf( buf, " n = %d ", n );
    kompas->ksMessage( TO_OLE(buf) );

    for( int i = 0; i < n; i++ ) {
      arr->ksGetArrayItem( i, mathPar );
      sprintf( buf, "i = %d  x = %5.1f y = %5.1f ", i, mathPar->x, mathPar->y );
      kompas->ksMessage( TO_OLE(buf) );
    }

    // заменим параметры 1-го элемента
    mathPar->x = 50;
    mathPar->y = 50;
    arr->ksSetArrayItem( 1, mathPar );

    // заменим параметры 0-го элемента
    mathPar->x = 60;
    mathPar->y = 60;
    arr->ksSetArrayItem( 0, mathPar );

    // просмотрим массив
    n = arr->ksGetArrayCount();
    for( int i = 0; i < n; i++ ) {
      arr->ksGetArrayItem( i, mathPar );
      ::sprintf( buf, "i = %d  x = %5.1f y = %5.1f ", i, mathPar->x, mathPar->y );
      kompas->ksMessage( TO_OLE(buf) );
    }

    arr->ksDeleteArray();
  }

  kompas->ksMessageBoxResult();
}

//--------------------------------------------------------------------------
//  массив предназначен для создания и получения параетров параграфа текста,
//  состоящего из   нескольких строк, которые в свою очередь
//  состоят из компонент, с разными параметрами
//  ( с наклоном, с утолщением, спецзнаки и т. д.)
//--------------------------------------------------------------------------
void TextIndefiniteArray() {
  ksTextItemParamPtr itemPar( (ksTextItemParam*)kompas->GetParamStruct( ko_TextItemParam ), false/*AddRef*/ );
  ksTextLineParamPtr linePar( (ksTextLineParam*)kompas->GetParamStruct( ko_TextLineParam ), false/*AddRef*/ );

  if ( (bool)itemPar && (bool)linePar ) {
    itemPar->Init();
    linePar->Init();
    linePar->style = 1;
    ksDynamicArrayPtr itemArr( (ksDynamicArray*)linePar->GetTextItemArr(), false/*AddRef*/ );
    ksTextItemFontPtr font( (ksTextItemFont*)itemPar->GetItemFont(), false/*AddRef*/ );
    if ( (bool)font && (bool)itemArr ) {
      font->height    = 10;   // высота текста
      font->ksu       = 1;    // сужение текста
      font->color     = 1000; // цвет
      font->bitVector = 1;    // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
      itemPar->s      = TO_OLE(L"1 компонента 1 строка");
      itemArr->ksAddArrayItem( -1, itemPar );

      font->height    = 20;   // высота текста
      font->ksu       = 2;    // сужение текста
      font->color     = 2000; // цвет
      font->bitVector = 2;    // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
      itemPar->s      = TO_OLE(L"2 компонента 1 строка");
      itemArr->ksAddArrayItem( -1, itemPar );

      // создали массив строк текста
      ksDynamicArrayPtr lineArr( (ksDynamicArray*)kompas->GetDynamicArray( TEXT_LINE_ARR ), false/*AddRef*/ );
      if ( lineArr ) {
        // добавили 1-ю строку
        lineArr->ksAddArrayItem( -1, linePar );

        // очистили массив компонент, чтобы использовать для создания второй строки текста
        itemArr->ksClearArray();

        // создаем вторую строку текста
        font->height    = 30;   // высота текста
        font->ksu       = 3;    // сужение текста
        font->color     = 3000; // цвет
        font->bitVector = 3;    // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
        itemPar->s      = TO_OLE(L"1 компонента 2 строка");
        itemArr->ksAddArrayItem( -1, itemPar );

        font->height    = 40;   // высота текста
        font->ksu       = 4;    // сужение текста
        font->color     = 4000; // цвет
        font->bitVector = 4;    // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
        itemPar->s      = TO_OLE(L"2 компонента 2 строка");
        itemArr->ksAddArrayItem( -1, itemPar );

        linePar->style = 1;
        // добавили 2-ю строку
        lineArr->ksAddArrayItem( -1, linePar );

        // проверяем результат работы нашей функции
        kompas->ksMessageBoxResult();

        int n = lineArr->ksGetArrayCount();
        char buf[128];
        ::sprintf( buf, "n = %d ", n );
        kompas->ksMessage( TO_OLE(buf) );

        // просмотрим массив строк текста
        for ( int i = 0; i < n; i++ ) { // цикл по строкам текста
          lineArr->ksGetArrayItem( i, linePar );
          ::sprintf( buf, "i = %d style = %d   ", i, linePar->style );
          kompas->ksMessage( TO_OLE(buf) );
          itemArr.Bind( (ksDynamicArray*)linePar->GetTextItemArr(), false/*AddRef*/);
          if ( itemArr ) {
            int n1 = itemArr->ksGetArrayCount();
            for ( int j = 0; j < n1; j++ ) { // цикл по компонентам строки текста
              itemArr->ksGetArrayItem( j, itemPar );
              font.Bind( (ksTextItemFont*)itemPar->GetItemFont(), false/*AddRef*/ );
              ::sprintf( buf, "j = %d h = %5.1f  s = %s ", j, font->height, AnsiString(itemPar->s).c_str() );
              kompas->ksMessage( TO_OLE(buf) );
            }
          }
        }

        lineArr->ksDeleteArray();
      }

      itemArr->ksDeleteArray();
    }
  }

  kompas->ksMessageBoxResult(); // проверяем результат работы нашей функции
}

//----------------------------------------------------------------------------
//
static void ShowColumns( ksDynamicArrayPtr & array, BOOL fl ) {
  if ( array ) {
    ksColumnInfoParamPtr par( (ksColumnInfoParam*)kompas->GetParamStruct( ko_ColumnInfoParam ), false/*AddRef*/ );
    if ( par ) {
      par->Init();
      char buf[128];
      char s[10];

      if ( fl )
        strcpy( s, "структура" );
      else
        s[0] = '\0';

      ksDynamicArrayPtr columnArr( (ksDynamicArray*)par->GetColumns(), false/*AddRef*/ );
      ksDynamicArrayPtr fieldEnum( (ksDynamicArray*)par->GetFieldEnum(), false/*AddRef*/ );
      if ( (bool)columnArr && (bool)fieldEnum ) {
        int n = array->ksGetArrayCount();
        for ( int i = 0; i < n; i++ ) {
          if ( !array->ksGetArrayItem(i, par) )
            kompas->ksMessageBoxResult();         // проверяем результат работы нашей функции
          else {
            //  выдадим поля колонки не указатели
            sprintf( buf, "%s i = %d header = %s type = %d def = %s flagEnum = %d", s, i, par->header,
                     par->type, par->def, par->flagEnum ? 1 : 0 );
            kompas->ksMessage( TO_OLE(buf) );
            if( par->type == RECORD_ATTR_TYPE )   //  структура
            {
              ksDynamicArrayPtr columns( (ksDynamicArray*)par->GetColumns(), false/*AddRef*/);
              ShowColumns( columns, true );
            }
            else
            {
              if ( par->flagEnum )  {             // выдадим массив перечислений
                ksDynamicArrayPtr fEnum( (ksDynamicArray*)par->GetFieldEnum(), false/*AddRef*/);
                int n1 = fEnum->ksGetArrayCount();
                kompas->ksMessage( TO_OLE(L"массив перечислений") );
                ksChar255Ptr charBuf( (ksChar255*)kompas->GetParamStruct( ko_Char255 ), false/*AddRef*/ );
                if ( charBuf ) {
                  for ( int i1 = 0; i1 < n1; i1++ ) {
                    if( !fEnum->ksGetArrayItem(i1, charBuf) )
                      kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
                    else
                      kompas->ksMessage( charBuf->str );
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}


//------------------------------------------------------------------------------
//  массив предназначен для создания и получения типа атрибута,
//  который может состоять из нескольких колонок
// ---
void AttrIndefiniteArray() {
  if ( kompas ) {
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

    ksDynamicArrayPtr pCol   ( (ksDynamicArray*)kompas->GetDynamicArray( ATTR_COLUMN_ARR ), false/*AddRef*/ );
    ksDynamicArrayPtr pStruct( (ksDynamicArray*)kompas->GetDynamicArray( ATTR_COLUMN_ARR ), false/*AddRef*/ );
    ksDynamicArrayPtr pEnum  ( (ksDynamicArray*)kompas->GetDynamicArray( CHAR_STR_ARR    ), false/*AddRef*/ );

    ksColumnInfoParamPtr parCol1( (ksColumnInfoParam*)kompas->GetParamStruct( ko_ColumnInfoParam ), false/*AddRef*/ );
    if ( (bool)pCol && (bool)pStruct && (bool)pEnum && (bool)parCol1 ) {
      parCol1->Init();
      // первая колонка
      parCol1->header   = TO_OLE(L"int");        // заголовoк-комментарий столбца
      parCol1->type     = INT_ATTR_TYPE; // тип данных в столбце - см.ниже
      parCol1->key      = 0;             // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      parCol1->def      = TO_OLE(L"100");        // значение по умолчанию
      parCol1->flagEnum = 1;             // флаг включающий режим, когда значение поля атрибута
                                         // будет заполнятся из массива перечисленных значений 1 и 0 отключон
                                         // флаг включающий режим, когда значение поля атрибута
                                         // будет заполнятся из массива перечисленных значений 1 и 0 отключон
      parCol1->SetFieldEnum( pEnum );    // массив неопределенной длины перечислений (строки)
      parCol1->SetColumns( 0 );          // массив неопределенной длины информации о колонках для записи

      ksChar255Ptr charBuf( (ksChar255*)kompas->GetParamStruct( ko_Char255 ), false/*AddRef*/ );
      if ( charBuf ) {
        charBuf->str = TO_OLE(L"100");
        pEnum->ksAddArrayItem( -1, charBuf );

        charBuf->str = TO_OLE(L"200");
        pEnum->ksAddArrayItem( -1, charBuf );

        charBuf->str = TO_OLE(L"300");
        pEnum->ksAddArrayItem( -1, charBuf );

        pCol->ksAddArrayItem( -1, parCol1 );

        ksColumnInfoParamPtr parCol2( (ksColumnInfoParam*)kompas->GetParamStruct( ko_ColumnInfoParam ), false/*AddRef*/ );
        if ( parCol2 ) { // вторая колонка
          parCol2->header   = TO_OLE(L"struct"); // заголовoк-комментарий столбца
          parCol2->type     = RECORD_ATTR_TYPE;  // тип данных в столбце - см.ниже
          parCol2->key      = 0;                 // дополнительный признак, который позволит отличить две переменные с одинаковым типом
          parCol2->def      = TO_OLE(L"\0");     // значение по умолчанию
          parCol2->flagEnum = 0;
          parCol2->SetFieldEnum( 0 );           // массив неопределенной длины перечислений (строки)
          parCol2->SetColumns( pStruct );       // массив неопределенной длины информации о колонках для записи

          ksColumnInfoParamPtr parStruct( (ksColumnInfoParam*)kompas->GetParamStruct( ko_ColumnInfoParam ), false/*AddRef*/);
          if ( parStruct ) {
            // заполним массив солонок для структуры
            // первая колонка  структуры
            parStruct->header   = TO_OLE(L"double"); // заголовoк-комментарий столбца
            parStruct->type     = DOUBLE_ATTR_TYPE;  // тип данных в столбце - см.ниже
            parStruct->key      = 0;                 // дополнительный признак, который позволит отличить две переменные с одинаковым типом
            parStruct->def      = TO_OLE(L"123456789");     // значение по умолчанию
            parStruct->flagEnum = 0;                 // флаг включающий режим, когда значение поля атрибута
                                                     // будет заполнятся из массива перечисленных значений 1 и 0 отключон
            parStruct->SetFieldEnum( 0 );            // массив неопределенной длины перечислений (строки)
            parStruct->SetColumns( 0 );              // массив неопределенной длины информации о колонках для записи

            pStruct->ksAddArrayItem( -1, parStruct );

            // вторая колонка структуры
            parStruct->header   = TO_OLE(L"long");// заголовoк-комментарий столбца
            parStruct->type     = LINT_ATTR_TYPE; // тип данных в столбце - см.ниже
            parStruct->key      = 0;              // дополнительный признак, который позволит отличить две переменные с одинаковым типом
            parStruct->def      = TO_OLE(L"1000000");     // значение по умолчанию
            parStruct->flagEnum = 0;              // флаг включающий режим, когда значение поля атрибута
                                                  // будет заполнятся из массива перечисленных значений 1 и 0 отключон
            parStruct->SetFieldEnum( 0 );         // массив неопределенной длины перечислений (строки)
            parStruct->SetColumns( 0 );           // массив неопределенной длины информации о колонках для записи

            pStruct->ksAddArrayItem( -1, parStruct );

            // третья колонка структуры
            parStruct->header   = TO_OLE(L"char");// заголовoк-комментарий столбца
            parStruct->type     = CHAR_ATTR_TYPE; // тип данных в столбце - см.ниже
            parStruct->key      = 0;              // дополнительный признак, который позволит отличить две переменные с одинаковым типом
            parStruct->def      = TO_OLE(L"10");  // значение по умолчанию
            parStruct->flagEnum = 0;              // флаг включающий режим, когда значение поля атрибута
                                                  // будет заполнятся из массива перечисленных значений 1 и 0 отключон
            parStruct->SetFieldEnum( 0 );         // массив неопределенной длины перечислений (строки)
            parStruct->SetColumns( 0 );           // массив неопределенной длины информации о колонках для записи

            pStruct->ksAddArrayItem( -1, parStruct );


            pCol->ksAddArrayItem( -1, parCol2 );

            ksColumnInfoParamPtr parCol3( (ksColumnInfoParam*)kompas->GetParamStruct( ko_ColumnInfoParam ), false/*AddRef*/ );
            if ( parCol3 ) {
              // третья  колонка
              parCol3->header   = TO_OLE(L"string");// заголовoк-комментарий столбца
              parCol3->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
              parCol3->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
              parCol3->def      = TO_OLE(L"text");  // значение по умолчанию
              parCol3->flagEnum = 0;                // флаг включающий режим, когда значение поля атрибута
                                                    // будет заполнятся из массива перечисленных значений 1 и 0 отключон
              parStruct->SetFieldEnum( 0 );         // массив неопределенной длины перечислений (строки)
              parStruct->SetColumns( 0 );           // массив неопределенной длины информации о колонках для записи

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
              ShowColumns( pCol, FALSE );    // функция пользователя
            }
          }
        }
      }

      pCol->ksDeleteArray();
      pStruct->ksDeleteArray();
      pEnum->ksDeleteArray();

      kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
    }
  }
}

//------------------------------------------------------------------------------
//
// ---
void PolyLineArray() {
  if ( kompas ) {
    // создадим массив полилиний
    ksDynamicArrayPtr pPoly( (ksDynamicArray*)kompas->GetDynamicArray( POLYLINE_ARR ), false/*AddRef*/ );
    if ( pPoly ) {
      ksMathPointParamPtr par( (ksMathPointParam*)kompas->GetParamStruct( ko_MathPointParam ), false/*AddRef*/ );
      if ( par ) {
        par->x = 10;
        par->y = 10;

        // создадим массив точек
        ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( POINT_ARR ), false/*AddRef*/ );
        if ( arr ) {
          arr->ksAddArrayItem( -1, par );

          par->x = 100;
          par->y = 100;
          arr->ksAddArrayItem( -1, par );

          par->x = 1000;
          par->y = 1000;
          arr->ksAddArrayItem( -1, par );

          // добавим массив точек в массив полилиний
          pPoly->ksAddArrayItem( -1, arr );

          kompas->ksMessageBoxResult();

          // наполним массив точек
          arr->ksClearArray();
          par->x = 20;
          par->y = 20;
          arr->ksAddArrayItem( -1, par );

          par->x = 200;
          par->y = 200;

          arr->ksAddArrayItem( -1, par );

          par->x = 2000;
          par->y = 2000;

          arr->ksAddArrayItem( -1, par );

          // добавим массив точек в массив полилиний
          pPoly->ksAddArrayItem( -1, arr );

          kompas->ksMessageBoxResult();

          // наполним массив точек
          arr->ksClearArray();
          par->x = 30;
          par->y = 30;
          arr->ksAddArrayItem( -1, par );

          par->x = 300;
          par->y = 300;
          arr->ksAddArrayItem( -1, par );

          par->x = 3000;
          par->y = 3000;

          arr->ksAddArrayItem( -1, par );

          // добавим массив точек в массив полилиний
          pPoly->ksAddArrayItem( -1, arr );

          kompas->ksMessageBoxResult();

          char buf[128];
          ::sprintf( buf, "n = %i", pPoly->ksGetArrayCount() );
          kompas->ksMessage( TO_OLE(buf) );
          pPoly->ksGetArrayItem( 1, arr );
          // просмоьрим 2-ой элемент массива полилиний
          int n = arr->ksGetArrayCount();
          for ( int i = 0; i < n; i++ ) {
            arr->ksGetArrayItem( i, par );
            ::sprintf( buf, "i = %d  x = %5.1f y = %5.1f", i, par->x, par->y );
            kompas->ksMessage( TO_OLE(buf) );
          }

          // заменим у 2 -го элемента массива полилиний 2-ой элемент
          par->x = 50;
          par->y = 50;
          arr->ksSetArrayItem( 1, par );

          par->x = 500;
          par->y = 500;
          arr->ksSetArrayItem( 0, par );

          pPoly->ksSetArrayItem( 1, arr );
          n = pPoly->ksGetArrayCount();

          // создадим массив точек
          ksDynamicArrayPtr arr2( (ksDynamicArray*)kompas->GetDynamicArray( POINT_ARR ), false/*AddRef*/ );
          if ( arr2 ) {
            // просмотрим массив полилиний
            for ( int i = 0; i < n; i++ ) {
              pPoly->ksGetArrayItem( i, arr2 );
              for( int j = 0; j < arr2->ksGetArrayCount(); j++ ) {
                arr2->ksGetArrayItem( j, par );
                ::sprintf( buf, "j = %d  x = %5.1f y = %5.1f ", j, par->x, par->y );
                kompas->ksMessage( TO_OLE(buf) );
              }
            }

            arr2->ksDeleteArray();
          }

          kompas->ksMessageBoxResult();
          // удалим массивы
          arr->ksDeleteArray();
          pPoly->ksDeleteArray();
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
//
// ---
void RectArray() {
  if ( kompas ) {
    // создать массив
    ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( RECT_ARR ), false/*AddRef*/ );
    if ( arr ) {
      ksRectParamPtr par( (ksRectParam*)kompas->GetParamStruct( ko_RectParam ), false/*AddRef*/ );
      ksMathPointParamPtr mathPar( (ksMathPointParam*)kompas->GetParamStruct( ko_MathPointParam ), false/*AddRef*/ );
      if ( (bool)par && (bool)mathPar ) {
        mathPar->x = 10;
        mathPar->y = 10;
        par->SetpTop( mathPar );

        mathPar->x = 20;
        mathPar->y = -10;
        par->SetpBot( mathPar );

        // наполнить массив
        arr->ksAddArrayItem( -1, par );

        mathPar->x = 20;
        mathPar->y = 50;
        par->SetpTop( mathPar );

        mathPar->x = 50;
        mathPar->y = 10;
        par->SetpBot( mathPar );
        arr->ksAddArrayItem( -1, par );

        mathPar->x = 20;
        mathPar->y = 150;
        par->SetpTop( mathPar );

        mathPar->x = 50;
        mathPar->y = 110;
        par->SetpBot( mathPar );
        arr->ksAddArrayItem( -1, par );

        kompas->ksMessageBoxResult();
        // просмотреть массив
        int n = arr->ksGetArrayCount();
        char buf[128];
        ::sprintf( buf, "n = %d", n );
        kompas->ksMessage( TO_OLE(buf) );
        ksMathPointParamPtr mathPar2( (ksMathPointParam*)kompas->GetParamStruct( ko_MathPointParam ), false/*AddRef*/ );
        if ( mathPar2 ) {
          for ( int i = 0; i < n; i++ ) {
            arr->ksGetArrayItem( i, par );
            mathPar.Bind( (ksMathPointParam*)par->GetpTop(), false/*AddRef*/ );
            mathPar2.Bind( (ksMathPointParam*)par->GetpBot(), false/*AddRef*/ );
            ::sprintf( buf, "i = %d  x1 = %5.1f y1 = %5.1f \n      x2 = %5.1f y2 = %5.1f ", i, mathPar->x, mathPar->y,
                       mathPar2->x, mathPar2->y );
            kompas->ksMessage( TO_OLE(buf) );
          }

          // редактируем массив
          mathPar->x  = -20;
          mathPar->y  = -50;
          par->SetpTop( mathPar );

          mathPar->x = 20;
          mathPar->y = -10;
          par->SetpBot( mathPar );
          arr->ksSetArrayItem( 0, par );

          mathPar->x  = 0;
          mathPar->y  = 0;
          par->SetpTop( mathPar );

          mathPar->x = 10;
          mathPar->y = -20;
          par->SetpBot( mathPar );
          arr->ksSetArrayItem( 1, par );

          mathPar->x  = 5;
          mathPar->y  = 5;
          par->SetpTop( mathPar );

          mathPar->x = 25;
          mathPar->y = 0;
          par->SetpBot( mathPar );
          arr->ksAddArrayItem( -1, par );
          // просмотрим массив
          int n = arr->ksGetArrayCount();

          for ( int i = 0; i < n; i++ ) {
            arr->ksGetArrayItem( i, par );
            mathPar  = (ksMathPointParam*)par->GetpTop();
            mathPar2 = (ksMathPointParam*)par->GetpBot();
            ::sprintf( buf, "i = %d  x1 = %5.1f y1 = %5.1f \n  x2 = %5.1f y2 = %5.1f ", i, mathPar->x, mathPar->y,
                       mathPar2->x, mathPar2->y );

            kompas->ksMessage( TO_OLE(buf) );
          }

          kompas->ksMessageBoxResult();
          // удалить массив
          arr->ksDeleteArray();
        }
      }
    }
  }
}

