// step8.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step8.h"

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
// CStep8App

BEGIN_MESSAGE_MAP(CStep8App, CWinApp)
  //{{AFX_MSG_MAP(CStep8App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep8App construction

CStep8App::CStep8App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep8App object

CStep8App theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDS_LYBID;
}

void ShowColumns( ksDynamicArrayPtr& pCol, bool fl );
void FuncAttrType( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void DelTypeAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void ShowTypeAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void ChangeType( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void NewAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void DelObjAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void ReadObjAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void ShowObjAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void ShowLib( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void ShowType( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );
void WalkFromObjWithAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr );

KompasObjectPtr kompas;

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
    ksDocument2DPtr doc( kompas->ActiveDocument2D() );
    ksAttributeObjectPtr attr( kompas->GetAttributeObject() );
    if ( doc && doc->reference && attr ) {
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
  }
}


//-------------------------------------------------------------------------------
//
// ---
void ShowCol( ksColumnInfoParamPtr & par, int iCol, bool fl ) {
  TCHAR buf[128];
  TCHAR s[10];
  if ( fl )
    ::_tcscpy_s( s, _T("структура") );
  else
    s[0]='\0';

  //выдадим поля колонки не указатели
  ::_stprintf_s( buf, _T("%s i=%d header=%s type=%d def=%s flagEnum=%d"), s, iCol, (LPCTSTR)par->header,
                                                                        par->type, (LPCTSTR)par->def, par->flagEnum );
  kompas->ksMessage( buf );
  if( par->type == RECORD_ATTR_TYPE )  { // структура
    ksDynamicArrayPtr pCol( par->GetColumns() );
    if ( pCol ) {
      ::ShowColumns( pCol, true );
      pCol->ksDeleteArray();
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShowColumns( ksDynamicArrayPtr& pCol, bool fl ) {
  ksColumnInfoParamPtr par( kompas->GetParamStruct(ko_ColumnInfoParam) );
  if ( par ) {
    par->Init();
    int n = pCol->ksGetArrayCount();

    for ( int i = 0; i < n; i++ ) {
      if ( !pCol->ksGetArrayItem(i, par) )
        kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
      else
        ::ShowCol(par,i, fl );
    }
  }
}

//-------------------------------------------------------------------------------
// создание типа атрибута
// ---
void FuncAttrType( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  ksAttributeTypeParamPtr type( kompas->GetParamStruct(ko_AttributeType)   );
  ksColumnInfoParamPtr    col ( kompas->GetParamStruct(ko_ColumnInfoParam) );
  if ( type && col ) {
    type->Init();
    col->Init();
    type->header      = _T("double_str_long"); // заголовoк-комментарий типа
    type->rowsCount   = 1;                      // кол-во строк в таблице
    type->flagVisible = true;                  // видимый, невидимый   в таблице
    type->password    = _T("");                // пароль, если не пустая строка  - защищает от несанкционированного изменения типа
    type->key1        = 10;
    type->key2        = 20;
    type->key3        = 30;
    type->key4        = 0;
    ksDynamicArrayPtr arr( type->GetColumns() );
    if ( arr ) {
       // первая колонка  структуры
      col->header   = _T("double");     // заголовoк-комментарий столбца
      col->type     = DOUBLE_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("123456789");  // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // вторая колонка структуры
      col->header   = _T("str");          // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      = 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("string");       // значение по умолчанию
      col->flagEnum = false;              // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // третья колонка структуры
      col->header    = _T("long");        // заголовoк-комментарий столбца
      col->type      = LINT_ATTR_TYPE;    // тип данных в столбце - см.ниже
      col->key       = 0;                 // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def       = _T("1000000");     // значение по умолчанию
      col->flagEnum  = false;             // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );
    }
    CString nameFile;
    //запросить имя библиотеки
    nameFile = (LPCTSTR)kompas->ksChoiceFile( _T("*.lat"), _T(""), false );
    //создать тип атрибута
    double numbType = attr->ksCreateAttrType( type,                // информация о типе атрибута
                                              (LPCTSTR)nameFile ); // имя библиотеки типов атрибутов
    if ( numbType > 1 )  {
      TCHAR buf[128];
      ::_stprintf_s( buf, _T("numbType=%f "), numbType );
      kompas->ksMessage( buf );
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
void DelTypeAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  double numb;
  int j;
  CString password;
  //запросить имя библиотеки
  CString nameFile;
  nameFile = (LPCTSTR)kompas->ksChoiceFile( _T("*.lat"), _T(""), false );
  do {
    j = kompas->ksReadDouble( _T("Ввести номер типа атрибута"), 1000., 0, 1e12, &numb );
    if ( j ) {
      password = (LPCTSTR)kompas->ksReadString( _T("Ввести пароль типа атрибута"), _T("") );
      if ( !attr->ksDeleteAttrType( numb, (LPCTSTR)nameFile, (LPCTSTR)password ) )
        kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
    }
  } while( j );
}

//--------------------------------------------------------------------------
// получить тип атрибута
//--------------------------------------------------------------------------
void ShowTypeAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  double numb;
  //запросить имя библиотеки
  CString nameFile;
  nameFile = (LPCTSTR)kompas->ksChoiceFile( _T("*.lat"), _T(""), false );

  ksAttributeTypeParamPtr type( kompas->GetParamStruct(ko_AttributeType) );
  if ( type ) {
    type->Init();
    TCHAR buf[128];

    do {
      numb = attr->ksChoiceAttrTypes( (LPCTSTR)nameFile );
      if ( numb ) {
        if ( !attr->ksGetAttrType(numb, (LPCTSTR)nameFile, type) )
          kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
        else {
          ::_stprintf_s( buf, _T("key1 = %d key2 =%d key3 = %d key4 =%d"),
                            type->key1, type->key2, type->key3, type->key4 );
          kompas->ksMessage( buf );
          ::_stprintf_s( buf, _T("header=%s rowsCount=%d flagVisible=%d password=%s"),
                           (LPCTSTR)type->header, type->rowsCount, type->flagVisible, 
                           (LPCTSTR)type->password );
          kompas->ksMessage( buf );
          ksDynamicArrayPtr pCol( type->GetColumns() );
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
void ChangeType( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  double numb;
  CString password;
  //запросить имя библиотеки
  CString nameFile;
  nameFile = (LPCTSTR)kompas->ksChoiceFile( _T("*.lat"), _T(""), false );
  int j;

  ksAttributeTypeParamPtr type( kompas->GetParamStruct(ko_AttributeType)   );
  if ( type ) {
    type->Init();
    do {
      j = kompas->ksReadDouble( _T("Ввести номер типа атрибута"), 1000., 0, 1e12, &numb );
      if ( j ) {
        password = (LPCTSTR)kompas->ksReadString( _T("Ввести пароль типа атрибута"), _T("") );
        //считаем тип атрибута
        if ( !attr->ksGetAttrType(numb, (LPCTSTR)nameFile, type) )
          kompas->ksMessageBoxResult();  // проверяем результат работы нашей функции
        else {
          type->password = (LPCTSTR)password;
          ksDynamicArrayPtr arr( type->GetColumns() );
          ksColumnInfoParamPtr par1( kompas->GetParamStruct(ko_ColumnInfoParam) );
          ksColumnInfoParamPtr parN( kompas->GetParamStruct(ko_ColumnInfoParam) );
          if ( arr && par1 && parN ) {
            par1->Init();
            parN->Init();
            // число колонок
            int n = arr->ksGetArrayCount();
            //считаем первую колонку
            arr->ksGetArrayItem( 0, par1 );
            //считаем последнюю колонку
            arr->ksGetArrayItem( n-1, parN );
            //заменим первую колонку
            arr->ksSetArrayItem( 0, parN );
            //заменим последнюю колонку
            arr->ksSetArrayItem( n-1, par1 );

            //заменим  тип атрибута  на новый
            double numbType = attr->ksSetAttrType( numb, (LPCTSTR)nameFile, type, (LPCTSTR)password );
            if ( numbType > 1 )  {
              TCHAR buf[128];
              ::_stprintf_s( buf, _T("numbType=%f "), numbType );
              kompas->ksMessage( buf );
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
void NewAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  ksAttributeParamPtr attrPar( kompas->GetParamStruct(ko_Attribute)   );
  ksUserParamPtr      usPar  ( kompas->GetParamStruct(ko_UserParam) ); 
  ksDynamicArrayPtr   fVisibl( kompas->GetDynamicArray(23) );
  ksDynamicArrayPtr   colKeys( kompas->GetDynamicArray(23) );
  if ( attrPar && usPar && fVisibl 
        && colKeys ) {
    attrPar->Init();
    usPar->Init();
    attrPar->SetValues( usPar );
    attrPar->SetColumnKeys( colKeys );
    attrPar->SetFlagVisible( fVisibl );
    attrPar->key1 = 1;
    attrPar->key2 = 10;
    attrPar->key3 = 100;
    attrPar->password = _T("111");

    ksLtVariantPtr item ( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr arr( kompas->GetDynamicArray(23) );
    if ( item && arr ) {
      usPar->SetUserArray( arr );
      item->Init();
      item->doubleVal = 987654321.0;
      arr->ksAddArrayItem( -1, item );
      item->Init();
      item->strVal = _T("qwerty");
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

    ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
    if ( info ) {
      info->Init();
      info->prompt = _T("Укажите объект");
      double x, y;
      int j = doc->ksCursor( info, &x, &y, NULL );
      if ( j ) {
        reference pObj = doc->ksFindObj( x, y, doc->ksGetCursorLimit() );
        if( doc->ksExistObj(pObj) ) {
          doc->ksLightObj( pObj, 1 );
          //запросить имя библиотеки
          CString nameFile;
          nameFile = (LPCTSTR)kompas->ksChoiceFile( _T("*.lat"), _T(""), false );
          double numb;
          j = kompas->ksReadDouble( _T("Ввести номер типа атрибута"), 1000., 0, 1e12, &numb );
          if( j ) {
            reference pAttr = attr->ksCreateAttr( pObj, attrPar, numb, (LPCTSTR)nameFile );
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
void DelObjAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( info ) {
    info->Init();
    info->prompt = _T("Укажите объект");
    double x, y;
    int j;
    do {
      j = doc->ksCursor( info, &x, &y, NULL );
      if ( j ) {
        reference pObj = doc->ksFindObj( x, y, doc->ksGetCursorLimit() );
        if ( doc->ksExistObj(pObj) ) {
          doc->ksLightObj( pObj, 1 );
          //создадим итератор для хождения по атрибутам объекта
          ksIteratorPtr iter( kompas->GetIterator() );
          if ( iter && iter->ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) ) {
            //встали на первый атрибут
            reference pAttr = iter->ksMoveAttrIterator( _T("F"), 0 );  
            if ( pAttr ) {
              CString password( (LPCTSTR)kompas->ksReadString(_T("Ввести пароль типа атрибута"), _T("") ) );
              if ( !attr->ksDeleteAttr(pObj, pAttr, (LPCTSTR)password) ) 
                kompas->ksMessageBoxResult();
            }
            else 
              kompas->ksMessage( _T("атрибут не найден") );
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
void ReadObjAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  bool res = false;
  ksUserParamPtr usPar( kompas->GetParamStruct(ko_UserParam) ); 
  if ( usPar ) {
    usPar->Init();
    ksLtVariantPtr item ( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr arr( kompas->GetDynamicArray(23) );
    if ( item && arr ) {
      usPar->SetUserArray( arr );
      item->Init();
      item->doubleVal = 987654321.0;
      arr->ksAddArrayItem( -1, item );
      item->Init();
      item->strVal = _T("qwerty");
      arr->ksAddArrayItem( -1, item );
      item->Init();
      item->longVal = 999991;
      arr->ksAddArrayItem( -1, item );
      res = true;
    }
  }
  if ( res ) {
    ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
    if ( info ) {
      info->Init();
      info->prompt = _T("Укажите объект");
      double x, y;
      int j;
      do {
        j = doc->ksCursor( info, &x, &y, NULL );
        if ( j ) {
          reference pObj = doc->ksFindObj( x, y, doc->ksGetCursorLimit() );
          if ( doc->ksExistObj(pObj) ) {
            doc->ksLightObj( pObj, 1 );
            //создадим итератор для хождения по атрибутам объекта
            ksIteratorPtr iter( kompas->GetIterator() );
            if ( iter && iter->ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) ) {
              //встали на первый атрибут
              reference pAttr = iter->ksMoveAttrIterator( _T("F"), 0 );  
              if ( pAttr ) {
                kompas->ksMessage( _T("тип и ключи атрибута") );
                long k1,k2,k3,k4;
                double numb;
                attr->ksGetAttrKeysInfo( pAttr, &k1, &k2, &k3, &k4, &numb );
                TCHAR buf[255];
                ::_stprintf_s( buf, _T("k1=%d k2=%d k3=%d k4=%d numb=%f "), k1, k2, k3, k4, numb );
                kompas->ksMessage( buf );

                kompas->ksMessage( _T("строка атрибута") );
                attr->ksGetAttrRow( pAttr, 0, 0, 0, usPar );

                kompas->ksMessage( _T("заменим строку атрибута") );
                ksLtVariantPtr item ( kompas->GetParamStruct(ko_LtVariant) );
                ksDynamicArrayPtr arr( usPar->GetUserArray() );
                if ( item && arr ) {
                  item->Init();
                  item->doubleVal = numb;
                  arr->ksSetArrayItem( 0, item );
                  item->Init();
                  item->strVal = _T("1234567\nasdfgh\nzxcvb");
                  arr->ksSetArrayItem( 1, item );
                  item->Init();
                  item->longVal = 888881;
                  arr->ksSetArrayItem( 2, item );
                  attr->ksSetAttrRow( pAttr, 0, 0, 0, usPar, _T("111") );
                }
              }
              else 
                kompas->ksMessage( _T("атрибут не найден") );
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
void ShowObjAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( info ) {
    info->Init();
    info->prompt = _T("Укажите объект");
    double x, y;
    int j;
    do {
      j = doc->ksCursor( info, &x, &y, NULL );
      if ( j ) {
        reference pObj = doc->ksFindObj( x, y, 1e6 );
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
void ShowLib( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  //запросить имя библиотеки
  CString nameFile;
  nameFile = (LPCTSTR)kompas->ksChoiceFile( _T("*.lat"), _T(""), false );

  double numb = attr->ksChoiceAttrTypes( (LPCTSTR)nameFile );
  if ( numb > 1 )  {
    TCHAR buf[128];
    ::_stprintf_s( buf, _T("numbType = %f "), numb );
    kompas->ksMessage( buf );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShowType( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  //запросить имя библиотеки
  CString nameFile;
  nameFile = (LPCTSTR)kompas->ksChoiceFile( _T("*.lat"), _T(""), false );
  CString password;
  double numb;
  int j = kompas->ksReadDouble( _T("Ввести номер типа атрибута"), 1000., 0, 1e12, &numb );
  if ( j ) {
    password = (LPCTSTR)kompas->ksReadString( _T("Ввести пароль типа атрибута"), _T("") );
    attr->ksViewEditAttrType( (LPCTSTR)nameFile, 2, numb, (LPCTSTR)password );
  }
}

//---------------------------------------------------------------------------
// пройтись у объекта, по атрибутам  с ключом
// key1=10 и выдать количество  колонок и строк для данного атрибута
//---------------------------------------------------------------------------
void WalkFromObjWithAttr( ksDocument2DPtr& doc, ksAttributeObjectPtr& attr ) {
  ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( info ) {
    info->Init();
    info->prompt =  _T("Укажите объект");
    double x, y;
    int j;
    do {
      j = doc->ksCursor( info, &x, &y, NULL );
      if ( j ) {
        reference pObj = doc->ksFindObj( x, y, doc->ksGetCursorLimit() );
        if ( doc->ksExistObj(pObj) ) {
          //создадим итератор для движения по атрибутам с ключом 10
          ksIteratorPtr iter( kompas->GetIterator() );
          if ( iter && iter->ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) ) 
          {
            doc->ksLightObj( pObj, 1 );
            //встали на первый атрибут
            reference pAttr = iter->ksMoveAttrIterator( _T("F"), 0 );  
            if ( pAttr ) {
              do {
                attr->ksViewEditAttr( pAttr, 1, _T("") );
                pAttr = iter->ksMoveAttrIterator( _T("N"), 0 );
              } while( pAttr );
            }
            doc->ksLightObj( pObj, 0 );
          }
        }
      }
    } while ( j );
  }
}
