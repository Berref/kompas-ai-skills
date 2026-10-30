// step10.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h" 
#include "step10.h"

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
// CStep10App

BEGIN_MESSAGE_MAP(CStep10App, CWinApp)
  //{{AFX_MSG_MAP(CStep10App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep10App construction

CStep10App::CStep10App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep10App object

CStep10App theApp;
//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDS_LIBSPC;
}


void TypeAttrBolt();
void CreateDet( ksDocument2DPtr& doc );
void CreateStandart( ksDocument2DPtr& doc );
void DecomposeSpc();
void ShowSpc();

reference  EditSpcObjDet( reference geom, ksDocument2DPtr& doc, ksSpecificationPtr& spc );
void DrawPosLeader( reference spcObj, ksDocument2DPtr& doc, ksSpecificationPtr& spc );
reference EditStandartSpcObj ( BOLT & tmp,  reference geom, ksDocument2DPtr & doc, ksSpecificationPtr & spc, reference spcObj );

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
    if ( comm == 2 || comm == 3 ) {
      ksDocument2DPtr docActive( kompas->ActiveDocument2D() );
      if ( !docActive ) 
        return;

      if ( docActive ) {
        switch ( comm ) {
        case 2  : ::CreateDet( docActive );      break; //создать объект спецификации деталь
        case 3  : ::CreateStandart( docActive ); break; //создать стандартный объект
        }
      }
      else
        kompas->ksError( _T("Документ не активизирован или \nне является листом/фрагментом") );
    }

    switch ( comm ) {
      case 1  : ::TypeAttrBolt(); break; // создадим  тип атрибута болта
      case 4  : ::DecomposeSpc(); break; // kонвертировать спецификацию во фрагмент
      case 5  : ::ShowSpc();      break; // просмотреть спецификацию
    }
  }
}

//-------------------------------------------------------------------------------
//создадим  тип атрибута болта
// ---
void TypeAttrBolt() {
  ksAttributeObjectPtr    attr( kompas->GetAttributeObject() );
  ksAttributeTypeParamPtr type( kompas->GetParamStruct(ko_AttributeType) );
  ksColumnInfoParamPtr    col ( kompas->GetParamStruct(ko_ColumnInfoParam) );
  if ( type && col && attr ) {
    type->Init();
    col->Init(); 
    type->header = _T("Болт111");    // заголовoк-комментарий типа
    type->rowsCount = 1;             // кол-во строк в таблице
    type->flagVisible = true;        // видимый, невидимый   в таблице
    type->password = _T("");         // пароль, если не пустая строка  - защищает от несанкционированного изменения типа
    type->key1 = 10;
    type->key2 = 20;
    type->key3 = 30;
    type->key4 = 0;
    ksDynamicArrayPtr arr( type->GetColumns() );
    if ( arr ) {
      //  колонка 1 "Имя элем."
      col->header   = _T("Имя элем.");  // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 1;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      =_T("Болт");        // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      //  колонка 2 "Исполнение"
      col->header   = _T("Исполнение"); // заголовoк-комментарий столбца
      col->type     = UINT_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      = 3;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("1");          // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 3 "Резьба"
      col->header = _T("Резьба");       // заголовoк-комментарий столбца
      col->type   = STRING_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key    = 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def    = _T("M");            // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 4 "Диаметр"
      col->header   = _T("Диаметр");    // заголовoк-комментарий столбца
      col->type     = UINT_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      = 3;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("12");         // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 5 "разделитель"
      col->header   = _T("");             // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      = 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("x");            // значение по умолчанию
      col->flagEnum = false;              // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 6 "Шаг"
      col->header   = _T("Шаг");           // заголовoк-комментарий столбца
      col->type     = FLOAT_ATTR_TYPE;     // тип данных в столбце - см.ниже
      col->key      = 3;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("1.25");          // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 7 "Поле допуска"
      col->header   = _T("Поле допуска");  // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;    // тип данных в столбце - см.ниже
      col->key      = 3;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("-6g");           // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 8 "разделитель"
      col->header   = _T("");              // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;    // тип данных в столбце - см.ниже
      col->key      = 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("x");             // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 9 "Длина"
      col->header  = _T("Длина");          // заголовoк-комментарий столбца
      col->type    = UINT_ATTR_TYPE;       // тип данных в столбце - см.ниже
      col->key     = 3;                    // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def     = _T("60");             // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 10 "Кл. прочности"
      col->header   = _T("Кл. прочности"); // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;    // тип данных в столбце - см.ниже
      col->key      = 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("58");            // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 11 "Материал"
      col->header   = _T("Материал");      // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;    // тип данных в столбце - см.ниже
      col->key      = 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T(".35Х");          // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 12 "Покрытие"
      col->header   = _T("Покрытие");      // заголовoк-комментарий столбца
      col->type     =  STRING_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      =  0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T(".16");           // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 13 "ГОСТ"
      col->header   = _T("ГОСТ");          // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;    // тип данных в столбце - см.ниже
      col->key      = 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("ГОСТ");          // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 14 "Номер"
      col->header   = _T("Номер");         // заголовoк-комментарий столбца
      col->type     = UINT_ATTR_TYPE;      // тип данных в столбце - см.ниже
      col->key      = 2;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("7808");          // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 15 "разделитель"
      col->header   = _T("");              // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;    // тип данных в столбце - см.ниже
      col->key      = 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("-");             // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 16 "Год"
      col->header   = _T("Год");           // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;    // тип данных в столбце - см.ниже
      col->key      = 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = _T("70");            // значение по умолчанию
      col->flagEnum = false;               // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );
    }
    CString nameFile;
    //запросить имя библиотеки
    nameFile = (LPCTSTR)kompas->ksChoiceFile( _T("*.lat"), _T(""), false );
    if ( !nameFile.IsEmpty() ) {
      //создать тип атрибута
      double  numbType = attr->ksCreateAttrType( type,       // информация о типе атрибута
                                                 (LPCTSTR)nameFile ); // имя библиотеки типов атрибутов
      if ( numbType > 1 )  {
        TCHAR buf[128];
        ::_stprintf_s( buf, _T("numbType=%f "),numbType );
        kompas->ksMessage( buf );
      }
      else
        kompas->ksMessageBoxResult(); // проверяем результат работы нашей функции
    }
    arr->ksDeleteArray(); //удалим  массив колонок
  }
}

//-------------------------------------------------------------------------------
//создать объект спецификации деталь
// ---
void CreateDet( ksDocument2DPtr & doc ) {
  ksSpecificationPtr spc( doc->GetSpecification() );
  if ( spc ) {
    //создать модельную группу   1
    reference gr = doc->ksNewGroup(0);
      doc->ksLineSeg ( 20, 30, 70, 30, 2 );
      doc->ksLineSeg ( 70, 30, 70, 80, 2 );
      doc->ksLineSeg ( 70, 80, 20, 80, 2 );
      doc->ksLineSeg ( 20, 80, 20, 30, 2 );
    doc->ksEndGroup();

    //создать  объект спецификации
    reference spcObj = EditSpcObjDet( gr, doc, spc );
    if ( spcObj )
      DrawPosLeader( spcObj, doc, spc );
  }
}

//-------------------------------------------------------------------------------
//создать стандартный объект
// ---
void CreateStandart( ksDocument2DPtr& doc ) {
  ksSpecificationPtr spc( doc->GetSpecification() );
  if ( spc ) {
    BOLT tmp;
    tmp.gost = 7808;
    tmp.f=0;  tmp.p = 1; 
  //  tmp.s=27; tmp.h=11; tmp.D=30.1;
    tmp.L=55; tmp.l1=49; tmp.b=46;  tmp.h2=10;  tmp.klass=1; /*klass=B*/
    tmp.d2=22.5;  tmp.k    = 2;
    tmp.dr = 20;
    //создать  объект спецификации
    reference spcObj = EditStandartSpcObj( tmp, 0, doc, spc, 0 );
    if ( spcObj )
      DrawPosLeader( spcObj, doc, spc );
  }
}

//-------------------------------------------------------------------------------
//просмотреть спецификацию
// ---
void ShowSpc() {
  ksDocument2DPtr doc( kompas->Document2D() );
  ksSpcDocumentPtr  spc( kompas->SpcActiveDocument() );
  if ( doc && spc && spc->reference ) {
    ksSpecificationPtr specification( spc->GetSpecification() );
    ksIteratorPtr iter( kompas->GetIterator() );
    iter->ksCreateSpcIterator( _T(""), 0, 0 );
    if ( iter->reference && specification ) {
      long obj = iter->ksMoveIterator( _T("F") );
      if ( obj ) {
        do {
          //узнаем количество колонок у базового объекта спецификации
          int count = specification->ksGetSpcTableColumn( _T(""), 0, 0 );
          
          TCHAR buf[128];
          ::_stprintf_s( buf, _T("Кол-во колонок = %i"), count );
          kompas->ksMessage( buf );
      
          // пройдем по всем колонкам
          for ( int i = 1; i <= count; i++ ) {
            //для текущего номера определим тип колонки, номер исполнения и блок
            ksSpcColumnParamPtr spcColPar( kompas->GetParamStruct(ko_SpcColumnParam) );
            if ( specification->ksGetSpcColumnType( obj,          //объект спецификации
                                                    i,      // номер колонки, начиная с 1
                                                    spcColPar ))
            {
              //возьмем текст
              long columnType = spcColPar->columnType;
              long ispoln = spcColPar->ispoln;
              long blok = spcColPar->block;
              TCHAR buf[255];
              buf[0] = _T('\0');
              ::_tcscpy_s( buf, specification->ksGetSpcObjectColumnText( obj, columnType, ispoln, blok ) );
              kompas->ksMessage( buf );
              //по типу колонки, номеру исполнения и блоку определим номер колонки
              int colNumb = specification->ksGetSpcColumnNumb( obj,         //объект спецификации
                                                               spcColPar->columnType,
                                                               spcColPar->ispoln,
                                                               spcColPar->block );
              ::_stprintf_s ( buf, _T("i = %d colNumb =%d"), i, colNumb );
              kompas->ksMessage( buf );
            }
          }
        } while ( obj = iter->ksMoveIterator( _T("N") ) );
      }
    }  
  }
  else 
    kompas->ksError( _T("Спецификация должна быть текущей") );
}

//-------------------------------------------------------------------------------
//просмотреть спецификацию
// ---
void DecomposeSpc() {
  ksSpcDocumentPtr spc( kompas->SpcActiveDocument() );
  ksDocument2DPtr doc( kompas->Document2D() );
  if ( spc && doc ) {
    //берем текущий документ спецификацию
    reference pDoc = spc->reference;
    if ( pDoc == 0 )
      return;
    //найдем количество листов спецификации
    int pageCount = spc->ksGetSpcDocumentPagesCount();
    //найдем габариры одного листа спецификации
    ksRectParamPtr spcGabarit( kompas->GetParamStruct(ko_RectParam) );
    if ( !spcGabarit )
      return;
    doc->ksGetObjGabaritRect( pDoc, spcGabarit );

    //создадим фрагмент  
    ksDocumentParamPtr docPar( kompas->GetParamStruct(ko_DocumentParam) );
    if ( !docPar )
      return;
    docPar->Init();
    docPar->regime = 0;
    docPar->type = 3;
    doc->ksCreateDocument( docPar );
    for ( int i = 0; i < pageCount; i++ ) {
      //получили временную группу i-го листа спецификации
      reference  group =  doc->ksDecomposeObj( pDoc,        //указатель на объект
                                               0,  //уровень разбиения 0- отрезки,дуги,тексты,точки:1-отрезки,тексты,точки; 2-отрезки, дуги, тексты
                                               0.4, //стрелка прогиба
                                               i+1);  // 0 - разбиение объекта в СК вида 1- в СК листа
      if ( group ) {
        int column=i%3;
        ksMathPointParamPtr mathBop( spcGabarit->GetpBot() );
        ksMathPointParamPtr mathTop( spcGabarit->GetpTop() );
        if ( !mathBop || !mathTop )
          return;
        double x = ( mathTop->x - mathBop->x + 5 ) * column;
        int row = i/3;
        double y = ( mathTop->y - mathBop->y + 5 ) * row;
        //сдвинули группу
        doc->ksMoveObj( group, x, -y );
        //поставили в модель
        doc->ksStoreTmpGroup( group );  //указатель группы
        doc->ksClearGroup( group, 1 );
        doc->ksDeleteObj( group );
      }
    }
    TCHAR buf[128];
    ::_stprintf_s( buf, _T("Декомпозировано %d листов СП"), pageCount );
    kompas->ksMessage( buf );
  }
  else
    kompas->ksError( _T("Спецификация должна быть текущей") );
}

//-----------------------------------------------------------------------------------------------
//  создадим объект спецификации для раздела "Детали"
//-----------------------------------------------------------------------------------------------
reference  EditSpcObjDet( reference geom, ksDocument2DPtr& doc, ksSpecificationPtr& spc )
{
  reference spcObj = 0;
  //если редактируем макро объект , то войдем в режим редактирования объекта
  if ( doc->ksEditMacroMode( ) ) {
    //найдем объкт спецификации по геометрии
    spcObj = spc->ksGetSpcObjForGeom( _T("graphic.lyt"), //имя библиотеки типов 
                                   1,         //   номер типа спецификации
                                   0,         //для макро редактирования
                                   1, 1 );
    //ввойдем в режим редактирования                               
    if ( !spc->ksSpcObjectEdit( spcObj ) )
      spcObj  = 0;
  }

  //если объекта нет, ввойдем в режим создания объекта спецификации
  if( spcObj || spc->ksSpcObjectCreate( _T("graphic.lyt"), //имя библиотеки типов 
                                   1,         //   номер типа спецификации
                                   20,  0,    //номер раздела и подраздела
                                   0,0 )) {    //тип атрибута

    ksUserParamPtr par( kompas->GetParamStruct(ko_UserParam) );
     ksLtVariantPtr item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr arr( kompas->GetDynamicArray(LTVARIANT_ARR) );
    if ( !par || !item || !arr )
      return 0;
    par->Init();
    par->SetUserArray( arr );
    item->Init();
    item->strVal = _T("Втулка");
    arr->ksAddArrayItem( -1, item );
    //наименование
    spc->ksSpcChangeValue( 5/*номер колонки*/ , 1, par, STRING_ATTR_TYPE  );

    //подключим геометрию
    if ( geom )
      spc->ksSpcIncludeReference( geom, 1 );

    spcObj = spc->ksSpcObjectEnd( );
    //если объект спецификации создан дадим возможность пользователю на него посмотреть и 
    //отредактировать  функцию нужно запускать вне Cursor и Placement
    if ( spcObj && spc->ksEditWindowSpcObject( spcObj ) )
      return spcObj;
  }
  return 0;
}

//----------------------------------------------------------------------------------------------
// отрисовать позиционную линию выноски
// уже проверено , что объект спецификации есть
// Функцию нужно запускать вне Cursor и Placement
//----------------------------------------------------------------------------------------------
void DrawPosLeader( reference spcObj, ksDocument2DPtr& doc, ksSpecificationPtr& spc ) {
  ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  info->Init();
  bool flag = false;
  reference posLeater = 0;
  double x1, y1;
  do {
    
    info->menuId = MENU_POS_LEADER;
    info->prompt = _T("Укажите позиционную линию выноски");

    int j1 = doc->ksCursor( info, &x1, &y1, 0 );
    switch ( j1 ) {
      case 1: //Создать новую линию выноски
        posLeater = doc->ksCreateViewObject( POSLEADER_OBJ );
        flag = false;
        break;
      case 2: //Подключить существующую
        info->prompt = _T("Укажите линию выноски");
        if ( doc->ksCursor( info, &x1, &y1, 0 ) ) 
        {
          posLeater = doc->ksFindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
          if ( !(posLeater && doc->ksGetObjParam( posLeater, 0, 0) == POSLEADER_OBJ )) 
          {
            posLeater = 0;
            flag = true;
          }
          else
            flag = false;
          break;
        }
        else
          flag = false;
        break;
      case -1:
        posLeater = doc->ksFindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
        if ( !(posLeater && doc->ksGetObjParam( posLeater, 0, 0) == POSLEADER_OBJ )) 
        {
          kompas->ksError( _T("Ошибка! Объект не позиционная линия выноски!") );
          posLeater = 0;
          flag = true;
        }
        else
          flag = false;
      break;
    }
  }  while( flag );
  
  //линия выноски есть, подключим ее к объекту спецификации 
  if ( posLeater  ) {
    //ввойдем в режим редактирования объекта спецификации
    if ( spc->ksSpcObjectEdit( spcObj ) ) {
      //подключим линию выноски
      spc->ksSpcIncludeReference( posLeater, true );
      //закроем объект спецификации
      spc->ksSpcObjectEnd();
    }
  }
}

//-----------------------------------------------------------------------------------------------
//  создадим объект спецификации для раздела "Стандартные изделия"
//-----------------------------------------------------------------------------------------------
reference EditStandartSpcObj ( BOLT &tmp,  reference geom, ksDocument2DPtr& doc, ksSpecificationPtr& spc, reference spcObj ) {
  //reference spcObj = 0;
  //если редактируем макро объект , то ввойдем в режим редактирования объекта
  if ( doc->ksEditMacroMode( ) ) {
    //найдем объкт спецификации по геометрии
    spcObj = spc->ksGetSpcObjForGeom( _T("graphic.lyt"), //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   0,         //для макро редактирования
                                   1, 1 );
    //ввойдем в режим редактирования
    if ( !spc->ksSpcObjectEdit( spcObj ) )
      spcObj  = 0;
  }

  if ( spcObj || spc->ksSpcObjectCreate( _T("graphic.lyt"), //имя библиотеки типов
                                         1,         //   номер типа спецификации
                                         25,  0,    //номер раздела и подраздела определены в стиле спецификации
                                         313277777065.0 , 0 ))  //тип атрибута определен в библиотеке типов атрибутов spc.lat
  {
    int uBuf;
    ksUserParamPtr par( kompas->GetParamStruct(ko_UserParam) );
     ksLtVariantPtr item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr arr( kompas->GetDynamicArray(LTVARIANT_ARR) );
    if ( !par || !item || !arr )
      return 0;
    par->Init();
    par->SetUserArray( arr );
    item->Init();
    item->strVal = _T("Болт111");
    arr->ksAddArrayItem( -1, item );

    spc->ksSpcChangeValue( 5/*номер колонки*/ , 1, par, STRING_ATTR_TYPE  );
    //исполнение
    if( !(tmp.f & ISPOLN) ) //если исполнения нет
      spc->ksSpcVisible( SPC_NAME, 2, 0 ); //выключим исполнение
    else {
      uBuf = 2;
      spc->ksSpcVisible( SPC_NAME, 2, 1 );
      arr->ksClearArray();
      item->Init();
      item->intVal = uBuf;
      arr->ksAddArrayItem( -1, item );
      spc->ksSpcChangeValue( SPC_NAME , 2, par, UINT_ATTR_TYPE  );
    }

    //изменим диаметр
    arr->ksClearArray();
     item->Init();
     item->doubleVal = 40;
    arr->ksAddArrayItem( -1, item );
    spc->ksSpcChangeValue( SPC_NAME , 4, par, DOUBLE_ATTR_TYPE  );

   //отследим мелкий шаг
   if( !(tmp.f & PITCH) ){//выключить шаг и его разделитель
     spc->ksSpcVisible( SPC_NAME, 5, 0 );
     spc->ksSpcVisible( SPC_NAME, 6, 0 );   //шаг
   }
   else {
     spc->ksSpcVisible( SPC_NAME, 5, 1 );
     spc->ksSpcVisible( SPC_NAME, 6, 1 );   //шаг
      arr->ksClearArray();
     item->Init();
     item->floatVal = tmp.p;
     arr->ksAddArrayItem( -1, item );
     spc->ksSpcChangeValue( SPC_NAME , 6, par, FLOAT_ATTR_TYPE  );
   }

   // выключим поле допуска
   spc->ksSpcVisible( SPC_NAME, 7, 0 );

   //изменим длину
    arr->ksClearArray();
   item->Init();
   item->intVal = (int)tmp.L;
   arr->ksAddArrayItem( -1, item );
   spc->ksSpcChangeValue( SPC_NAME , 9, par, UINT_ATTR_TYPE );

   // выключим класс прочности
   spc->ksSpcVisible( SPC_NAME, 10, 0 );

   // выключим материал
   spc->ksSpcVisible( SPC_NAME, 11, 0 );

   // выключим покрытие
   spc->ksSpcVisible( SPC_NAME, 12, 0 );

   //изменим ГОСТ
    arr->ksClearArray();
   item->Init();
   item->floatVal = tmp.gost;
   arr->ksAddArrayItem( -1, item );
   spc->ksSpcChangeValue( SPC_NAME , 14, par, UINT_ATTR_TYPE );

   //подключим геометрию
   if ( geom )
     spc->ksSpcIncludeReference( geom, 1 );

   spcObj = spc->ksSpcObjectEnd( );
   //если объект спецификации создан дадим возможность пользователю на него посмотреть и 
   //отредактировать.  Функцию нужно запускать вне Cursor и Placement
   if ( spcObj )
     if ( spc->ksEditWindowSpcObject( spcObj ) )
       return spcObj;
 }
 return 0;
}
