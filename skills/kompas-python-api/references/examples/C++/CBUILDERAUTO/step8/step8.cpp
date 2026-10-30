//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include <ldefin2d.h>
#include <ksConstants.h>

#ifdef __LIGHT_VERSION__
#include <Kl_TLB.h>
#else
#include <Ks_TLB.h>
#endif

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

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  return 1;
}
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch* far __export WINAPI CreateKompasObject();


KompasObjectPtr kompas;
extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return 100;
}

void ShowColumns        ( ksDynamicArrayPtr & pCol, bool fl );
void FuncAttrType       ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void DelTypeAttr        ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void ShowTypeAttr       ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void ChangeType         ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void NewAttr            ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void DelObjAttr         ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void ReadObjAttr        ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void ShowObjAttr        ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void ShowLib            ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void ShowType           ( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );
void WalkFromObjWithAttr( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr );

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
    ksDocument2DPtr doc( (ksDocument2D *)kompas->ActiveDocument2D(), false/*AddRef*/ );
    ksAttributeObjectPtr attr( (ksAttributeObject*)kompas->GetAttributeObject(), false/*AddRef*/ );
    if ( (bool)doc && doc->reference && (bool)attr ) {
      switch ( comm ) {
        case 1  : ::FuncAttrType( doc, attr );        break; // создать тип атрибута
        case 2  : ::DelTypeAttr( doc, attr );         break; // удалить  тип атрибута
        case 3  : ::ShowTypeAttr( doc, attr );        break; // получить  тип атрибута
        case 4  : ::ChangeType( doc, attr );          break; // заменить  тип атрибута
        case 5  : ::NewAttr( doc, attr );             break; // создать атрибут определенного типа
        case 6  : ::DelObjAttr( doc, attr );          break; // удалить атрибут
        case 7  : ::ReadObjAttr( doc, attr );         break; // считать атрибут
        case 8  : ::ShowObjAttr( doc, attr );         break; // просмотреть атрибут
        case 9  : ::ShowLib( doc, attr );             break; // просмотреть библиотеку
        case 10 : ::ShowType( doc, attr );            break; // просмотреть тип
        case 11 : ::WalkFromObjWithAttr( doc, attr ); break; // просмотреть атрибут
      }
    }
    kompas->Release();
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShowCol( ksColumnInfoParamPtr & par, int iCol, bool fl ) {
  char buf[128];
  char s[10];
  if ( fl )
    ::strcpy( s, "структура" );
  else
    s[0]='\0';

  //выдадим поля колонки не указатели
	::sprintf( buf, "%s i=%d header=%s type=%d def=%s flagEnum=%d", s, iCol, WideToAnsi(par->header),
             par->type, WideToAnsi(par->def), par->flagEnum ? 1 : 0 );
  kompas->ksMessage( TO_OLE(buf) );
  if( par->type == RECORD_ATTR_TYPE )  { // структура
    ksDynamicArrayPtr pCol( (ksDynamicArray*)par->GetColumns(), false/*AddRef*/ );
    if ( pCol ) {
      ::ShowColumns( pCol, true );
      pCol->ksDeleteArray();
    }
  }
  else {
    if ( par->flagEnum ) { //выдадим массив перечислений
      ksDynamicArrayPtr arr( (ksDynamicArray*)par->GetFieldEnum(), false/*AddRef*/ );
      int n1 = arr->ksGetArrayCount();
      kompas->ksMessage( TO_OLE(L"массив перечислений") );
      ksChar255Ptr str( (ksChar255*)kompas->GetParamStruct( ko_Char255 ), false/*AddRef*/ );
      for ( int i1 = 0; i1 < n1; i1++ ) {
        if ( arr->ksGetArrayItem( i1, str ) )
          kompas->ksMessage( str->str );
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShowColumns( ksDynamicArrayPtr & pCol, bool fl ) {
  ksColumnInfoParamPtr par( (ksColumnInfoParam*)kompas->GetParamStruct(ko_ColumnInfoParam), false/*AddRef*/ );
  if ( par ) {
    par->Init();
    int n = pCol->ksGetArrayCount();

    for ( int i = 0; i < n; i++ ) {
      if ( !pCol->ksGetArrayItem(i, par) )
        kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
      else
        ::ShowCol( par, i, fl );
    }
  }
}

//-------------------------------------------------------------------------------
// создание типа атрибута
// ---
void FuncAttrType( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  ksAttributeTypeParamPtr type( (ksAttributeTypeParam*)kompas->GetParamStruct(ko_AttributeType), false/*AddRef*/ );
  ksColumnInfoParamPtr    col ( (ksColumnInfoParam*)kompas->GetParamStruct(ko_ColumnInfoParam), false/*AddRef*/ );
  if ( (bool)type && (bool)col ) {
    type->Init();
    col->Init();
    type->header = TO_OLE(L"double_str_long"); // заголовoк-комментарий типа
    type->rowsCount = 1 ;              // кол-во строк в таблице
    type->flagVisible = true;          // видимый, невидимый   в таблице
    type->password = TO_OLE(L"");              // пароль, если не пустая строка  - защищает от несанкционированного изменения типа
    type->key1 = 10;
    type->key2 = 20;
    type->key3 = 30;
    type->key4 = 0;
    ksDynamicArrayPtr arr( (ksDynamicArray*)type->GetColumns(), false/*AddRef*/ );
    if ( arr ) {
      // первая колонка  структуры
      col->header = TO_OLE(L"double");                   // заголовoк-комментарий столбца
      col->type   = DOUBLE_ATTR_TYPE;            // тип данных в столбце - см.ниже
      col->key    = 0;                           // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def    = TO_OLE(L"123456789");                // значение по умолчанию
      col->flagEnum = false;                     // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // вторая колонка структуры
      col->header = TO_OLE(L"str");                       // заголовoк-комментарий столбца
      col->type   = STRING_ATTR_TYPE;            // тип данных в столбце - см.ниже
      col->key    = 0;                           // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def    = TO_OLE(L"string");                   // значение по умолчанию
      col->flagEnum = false;                     // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // третья колонка структуры
      col->header = TO_OLE(L"long");                     // заголовoк-комментарий столбца
      col->type   = LINT_ATTR_TYPE;              // тип данных в столбце - см.ниже
      col->key    = 0;                           // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def    = TO_OLE(L"1000000");                  // значение по умолчанию
      col->flagEnum = false;                     // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );
    }
    WideString nameFile;
    //запросить имя библиотеки
    nameFile = kompas->ksChoiceFile( TO_OLE(L"*.lat"), NULL, false );
    //создать тип атрибута
    double numbType = attr->ksCreateAttrType( type,   // информация о типе атрибута
                                              TO_OLE(nameFile) ); // имя библиотеки типов атрибутов
    if ( numbType > 1 )  {
      char buf[128];
      ::sprintf( buf, "numbType=%f ", numbType );
      kompas->ksMessage( TO_OLE(buf) );
    }
    else
      kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции

    //удалим  массив колонок
    arr->ksDeleteArray();
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DelTypeAttr( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  double numb;
  int j;
  WideString password;
  //запросить имя библиотеки
  WideString nameFile;
  nameFile = kompas->ksChoiceFile( TO_OLE(L"*.lat"), NULL, false );
  do {
    j = kompas->ksReadDouble( TO_OLE(L"Ввести номер типа атрибута"), 1000., 0, 1e12, &numb );
    if ( j ) {
      password = kompas->ksReadString( TO_OLE(L"Ввести пароль типа атрибута"), TO_OLE(L"") );
      if( !attr->ksDeleteAttrType(numb, TO_OLE(nameFile), TO_OLE(password) ) )
        kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
    }
  } while( j );
}

//--------------------------------------------------------------------------
// получить тип атрибута
//--------------------------------------------------------------------------
void ShowTypeAttr( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  double numb;
  //запросить имя библиотеки
  WideString nameFile;
  nameFile = kompas->ksChoiceFile( TO_OLE(L"*.lat"), NULL, false );

  ksAttributeTypeParamPtr type( (ksAttributeTypeParam*)kompas->GetParamStruct(ko_AttributeType), false/*AddRef*/ );
  if ( type ) {
    type->Init();
    char buf[128];

    do {
      numb = attr->ksChoiceAttrTypes( TO_OLE(nameFile) );
      if ( numb ) {
        if ( !attr->ksGetAttrType(numb, TO_OLE(nameFile), type) )
          kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
        else {
          ::sprintf( buf,"key1 = %d key2 =%d key3 = %d key4 =%d",
                     type->key1, type->key2, type->key3, type->key4 );
          kompas->ksMessage( TO_OLE(buf) );
          ::sprintf( buf,"header=%s rowsCount=%d flagVisible=%d password=%s",
										 WideToAnsi(type->header), type->rowsCount, type->flagVisible ? 1 : 0,
										 WideToAnsi(type->password) );
          kompas->ksMessage( TO_OLE(buf) );
          ksDynamicArrayPtr pCol( (ksDynamicArray*)type->GetColumns(), false/*AddRef*/ );
					if ( pCol ) {
            ::ShowColumns( pCol, false );
            pCol->ksDeleteArray();
          }
        }
      }
    } while( numb );
  }
}

//--------------------------------------------------------------------------
// заменить тип атрибута
//--------------------------------------------------------------------------
void ChangeType( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  double numb;
  WideString password;
  //запросить имя библиотеки
  WideString nameFile;
  nameFile = kompas->ksChoiceFile( TO_OLE(L"*.lat"), NULL, false );
  int j;

  ksAttributeTypeParamPtr type( (ksAttributeTypeParam*)kompas->GetParamStruct(ko_AttributeType), false/*AddRef*/ );
  if ( type ) {
    type->Init();
    do {
      j = kompas->ksReadDouble( TO_OLE(L"Ввести номер типа атрибута"), 1000., 0, 1e12, &numb );
      if ( j ) {
        password = kompas->ksReadString( TO_OLE(L"Ввести пароль типа атрибута"), TO_OLE(L"") );
        //считаем тип атрибута
        if ( !attr->ksGetAttrType(numb, TO_OLE(nameFile), type) )
          kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
        else {
          type->password = TO_OLE(password);
          ksDynamicArrayPtr arr( (ksDynamicArray*)type->GetColumns(), false/*AddRef*/ );
          ksColumnInfoParamPtr par1( (ksColumnInfoParam*)kompas->GetParamStruct(ko_ColumnInfoParam), false/*AddRef*/ );
          ksColumnInfoParamPtr parN( (ksColumnInfoParam*)kompas->GetParamStruct(ko_ColumnInfoParam), false/*AddRef*/ );
          if ( (bool)arr && (bool)par1 && (bool)parN ) {
            par1->Init();
            parN->Init();
            // число колонок
            int n = arr->ksGetArrayCount();
            //считаем первую колонку
            arr->ksGetArrayItem( 0, par1 );
            //считаем последнюю колонку
            arr->ksGetArrayItem( n - 1, parN );
            //заменим первую колонку
            arr->ksSetArrayItem( 0, parN );
            //заменим последнюю колонку
            arr->ksSetArrayItem( n - 1, par1 );

            //заменим  тип атрибута  на новый
            double numbType = attr->ksSetAttrType( numb, TO_OLE(nameFile), type, TO_OLE(password) );
            if ( numbType > 1 )  {
              char buf[128];
              ::sprintf( buf, "numbType=%f ", numbType );
              kompas->ksMessage( TO_OLE(buf) );
            }
            else
              kompas->ksMessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
            arr->ksDeleteArray();
          }
        }
      }
    } while( j );
  }
}


//----------------------------------------------------------------------------
//создадим атрибут типа,полученного из функции FuncTypeAttr
//----------------------------------------------------------------------------
void NewAttr( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  ksAttributeParamPtr attrPar( (ksAttributeParam*)kompas->GetParamStruct(ko_Attribute), false/*AddRef*/ );
  ksUserParamPtr      usPar  ( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
  ksDynamicArrayPtr   fVisibl( (ksDynamicArray*)kompas->GetDynamicArray(23), false/*AddRef*/ );
  ksDynamicArrayPtr   colKeys( (ksDynamicArray*)kompas->GetDynamicArray(23), false/*AddRef*/ );
  if ( (bool)attrPar && (bool)usPar && (bool)fVisibl && (bool)colKeys ) {
    attrPar->Init();
    usPar->Init();
    attrPar->SetValues( usPar );
    attrPar->SetColumnKeys( colKeys );
    attrPar->SetFlagVisible( fVisibl );
    attrPar->key1 = 1;
    attrPar->key2 = 10;
    attrPar->key3 = 100;
    attrPar->password = TO_OLE(L"111");

    ksLtVariantPtr item ( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
    if ( (bool)item && (bool)arr ) {
      usPar->SetUserArray( arr );
      item->Init();
      item->doubleVal = 987654321.0;
      arr->ksAddArrayItem( -1, item );
      item->Init();
      item->strVal = TO_OLE(L"qwerty");
      arr->ksAddArrayItem( -1, item );
      item->Init();
      item->longVal = 999991;
      arr->ksAddArrayItem( -1, item );

      item->Init();
      item->uCharVal = 1;
      fVisibl->ksAddArrayItem( -1, item );
      fVisibl->ksAddArrayItem( -1, item );
      fVisibl->ksAddArrayItem( -1, item );
    }

    ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
    if ( info ) {
      info->Init();
      info->prompt = TO_OLE(L"Укажите объект");
      double x, y;
      int j = doc->ksCursor( info, &x, &y, NULL );
      if ( j ) {
        long pObj = doc->ksFindObj( x, y, 1e6 );
        if( doc->ksExistObj(pObj) ) {
          doc->ksLightObj( pObj, 1 );
          //запросить имя библиотеки
          WideString nameFile;
          nameFile = kompas->ksChoiceFile( TO_OLE(L"*.lat"), NULL, false );
          double numb;
          j = kompas->ksReadDouble( TO_OLE(L"Ввести номер типа атрибута"), 1000., 0, 1e12, &numb );
          if( j ) {
            reference pAttr = attr->ksCreateAttr( pObj, attrPar, numb, TO_OLE(nameFile) );
            if( !pAttr )
              kompas->ksMessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
          }
          doc->ksLightObj( pObj, 0 );
        }
      }
    }
  }
}

//--------------------------------------------------------------------------
// удалить первый атрибут  у данного объекта
//---------------------------------------------------------------------------
void DelObjAttr( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
  if ( info ) {
    info->Init();
    info->prompt = TO_OLE(L"Укажите объект");
    double x, y;
    int j;
    do {
      j = doc->ksCursor( info, &x, &y, NULL );
      if ( j ) {
        long pObj = doc->ksFindObj( x, y, 1e6 );
        if ( doc->ksExistObj(pObj) ) {
          doc->ksLightObj( pObj, 1 );
          //создадим итератор для хождения по атрибутам объекта
          ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
          bool res = iter->ksCreateAttrIterator( pObj, 0, 0, 0, 0, 0 );
          if ( (bool)iter && (bool)res ) {
            //встали на первый атрибут
            long pAttr = iter->ksMoveAttrIterator( TO_OLE(L"F"), 0 );
            if ( pAttr ) {
              WideString password( kompas->ksReadString(TO_OLE(L"Ввести пароль типа атрибута"),
                                                        TO_OLE(L"") ) );
              if ( !attr->ksDeleteAttr(pObj, pAttr, TO_OLE(password)) )
                kompas->ksMessageBoxResult();
            }
            else
              kompas->ksMessage( TO_OLE(L"атрибут не найден") );
            doc->ksLightObj( pObj, 0 );
          }
        }
      }
    } while ( j );
  }
}

//--------------------------------------------------------------------------
// считать  атрибут  типа double_str_long
//---------------------------------------------------------------------------
void ReadObjAttr( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  bool res = false;
  ksUserParamPtr usPar( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
  if ( usPar ) {
    usPar->Init();
    ksLtVariantPtr  item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr ( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
    if ( (bool)item && (bool)arr ) {
      usPar->SetUserArray( arr );
      item->Init();
      item->doubleVal = 987654321.0;
      arr->ksAddArrayItem( -1, item );
      item->Init();
      item->strVal = TO_OLE(L"qwerty");
      arr->ksAddArrayItem( -1, item );
      item->Init();
      item->longVal = 999991;
      arr->ksAddArrayItem( -1, item );
      res = true;
    }
  }
  if ( res ) {
    ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
    if ( info ) {
      info->Init();
      info->prompt = TO_OLE(L"Укажите объект");
      double x, y;
      int j;
      do {
        j = doc->ksCursor( info, &x, &y, NULL );
        if ( j ) {
          long pObj = doc->ksFindObj( x, y, 1e6 );
          if ( doc->ksExistObj(pObj) ) {
            doc->ksLightObj( pObj, 1 );
            //создадим итератор для хождения по атрибутам объекта
            ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
            bool res = iter->ksCreateAttrIterator( pObj, 0, 0, 0, 0, 0 );
            if ( (bool)iter && (bool)res ) {
              //встали на первый атрибут
              long pAttr = iter->ksMoveAttrIterator( TO_OLE(L"F"), 0 );
              if ( pAttr ) {
                kompas->ksMessage( TO_OLE(L"тип и ключи атрибута") );
                long k1,k2,k3,k4;
                double numb;
                attr->ksGetAttrKeysInfo( pAttr, &k1, &k2, &k3, &k4, &numb );
                char buf[255];
                ::sprintf( buf, "k1=%d k2=%d k3=%d k4=%d numb=%f ", k1, k2, k3, k4, numb );
                kompas->ksMessage( TO_OLE(buf) );

                kompas->ksMessage( TO_OLE(L"строка атрибута") );
                attr->ksGetAttrRow( pAttr, 0, 0, 0, usPar );

                kompas->ksMessage( TO_OLE(L"заменим строку атрибута") );
                ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
                ksDynamicArrayPtr arr ( (ksDynamicArray*)usPar->GetUserArray(), false/*AddRef*/ );
                if ( (bool)item && (bool)arr ) {
                  item->Init();
                  item->doubleVal = numb;
                  arr->ksSetArrayItem( 0, item );
                  item->Init();
                  item->strVal = TO_OLE(L"1234567\nasdfgh\nzxcvb");
                  arr->ksSetArrayItem( 1, item );
                  item->Init();
                  item->longVal = 888881;
                  arr->ksSetArrayItem( 2, item );
                  attr->ksSetAttrRow( pAttr, 0, 0, 0, usPar, TO_OLE(L"111") );
                }
              }
              else
                kompas->ksMessage( TO_OLE(L"атрибут не найден") );
            }
            doc->ksLightObj( pObj, 0 );
          }
        }
      } while ( j );
    }
  }
}

//--------------------------------------------------------------------------
// просмотреть  атрибут
//---------------------------------------------------------------------------
void ShowObjAttr( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
  if ( info ) {
    info->Init();
    info->prompt = TO_OLE(L"Укажите объект");
    double x, y;
    int j;
    do {
      j = doc->ksCursor( info, &x, &y, NULL );
      if ( j ) {
        long pObj = doc->ksFindObj( x, y, 1e6 );
        if ( doc->ksExistObj(pObj) ) {
          doc->ksLightObj( pObj, 1 );
          attr->ksChoiceAttr( pObj );
          doc->ksLightObj( pObj, 0 );
        }
      }
    } while ( j );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShowLib( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  //запросить имя библиотеки
  WideString nameFile;
  nameFile = kompas->ksChoiceFile( TO_OLE(L"*.lat"), NULL, false );

  double numb = attr->ksChoiceAttrTypes( TO_OLE(nameFile) );
  if ( numb > 1 )  {
    char buf[128];
    ::sprintf( buf, "numbType = %f ",numb );
    kompas->ksMessage( TO_OLE(buf) );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShowType( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  //запросить имя библиотеки
  WideString nameFile;
  nameFile = kompas->ksChoiceFile( TO_OLE(L"*.lat"), NULL, false );
  WideString password;
  double numb;
  int j = kompas->ksReadDouble( TO_OLE(L"Ввести номер типа атрибута"), 1000., 0, 1e12, &numb );
  if ( j ) {
    password = kompas->ksReadString( TO_OLE(L"Ввести пароль типа атрибута"), TO_OLE(L"") );
    attr->ksViewEditAttrType( TO_OLE(nameFile), 2, numb, TO_OLE(password) );
  }
}

//---------------------------------------------------------------------------
// пройтись у объекта, по атрибутам  с ключом
// key1=10 и выдать количество  колонок и строк для данного атрибута
//---------------------------------------------------------------------------
void WalkFromObjWithAttr( ksDocument2DPtr & doc, ksAttributeObjectPtr & attr ) {
  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
  if ( info ) {
    info->Init();
    info->prompt = TO_OLE(L"Укажите объект");
    double x, y;
    int j;
    do {
      j = doc->ksCursor( info, &x, &y, NULL );
      if ( j ) {
        long pObj = doc->ksFindObj( x, y, 1e6 );
        if ( doc->ksExistObj(pObj) ) {
          //создадим итератор для движения по атрибутам с ключом 10
          ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
          bool res = iter->ksCreateAttrIterator( pObj, 0, 0, 0, 0, 0 );
          if ( (bool)iter && (bool)res ) {
            doc->ksLightObj( pObj, 1 );
            //встали на первый атрибут
            long pAttr = iter->ksMoveAttrIterator( TO_OLE(L"F"), 0 );
            if ( pAttr ) {
              do {
                attr->ksViewEditAttr( pAttr, 1, TO_OLE(L"") );
                pAttr = iter->ksMoveAttrIterator( TO_OLE(L"N"), 0 );
              } while( pAttr );
            }
            doc->ksLightObj( pObj, 0 );
          }
        }
      }
    } while ( j );
  }
}

