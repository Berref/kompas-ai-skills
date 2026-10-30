// step7.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step7.h"

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
// CStep7App

BEGIN_MESSAGE_MAP(CStep7App, CWinApp)
  //{{AFX_MSG_MAP(CStep7App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep7App construction

CStep7App::CStep7App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep7App object

CStep7App theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_ITERFORDOC;
}

void WalkFromView( ksDocument2DPtr& doc );
void WalkFromMacro( ksDocument2DPtr& doc );
void WalkFromDoc();
void WalkViewDoc( ksDocument2DPtr& doc );
void WalkGroup( ksDocument2DPtr& doc );
void WalkLayer( ksDocument2DPtr& doc );
void WalkFromGroup( ksDocument2DPtr& doc );
void WalkFromDocWithAttr( ksDocument2DPtr& doc );
void WalkFromObjWithAttr( ksDocument2DPtr& doc );

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
    if ( comm == 3 || comm == 4 ) {
      ksDocument2DPtr doc( kompas->Document2D() );
      if ( doc ) {
        switch ( comm ) {
           case 3  : ::WalkFromDoc();              break; //хождение по документам
           case 4  : ::WalkViewDoc( doc );         break; //хождение по видам
        }
      }
    }
    else {
      ksDocument2DPtr doc( kompas->ActiveDocument2D() );
      if ( doc && doc->reference ) {
        switch ( comm ) {
         case 1  : ::WalkFromView( doc );        break; //хождение по виду
        case 2  : ::WalkFromMacro( doc );       break; //хождение по макроэлементу
        case 5  : ::WalkGroup( doc );           break; //хождение по именнованным и рабочим группам
        case 6  : ::WalkLayer( doc );           break; //хождение по слоям
        case 7  : ::WalkFromGroup( doc );       break; //хождение по группе
        case 8  : ::WalkFromDocWithAttr( doc ); break; //хождение по элементам документа с определенным атрибутом
        case 9  : ::WalkFromObjWithAttr( doc ); break; //хождение по атрибутам объекта
        }
      }
      else
        kompas->ksError( _T("Документ не активизирован или \nне является листом/фрагментом") );
    }
  }
}

static void UserLightObj( reference obj, TCHAR *c, int count, ksDocument2DPtr& doc ) {
  TCHAR buf[128];
  doc->ksLightObj( obj, 1 );
  ::_stprintf_s(buf, c, count );
  kompas->ksMessage( buf );
  doc->ksLightObj( obj, 0 );
}

//-------------------------------------------------------------------------------
//
// ---
void WalkFromView( ksDocument2DPtr& doc ) {
  //в текущем документе и виде создадим итератор для хождения по всем элементам
  reference obj;
  int count  = 0;
  TCHAR buf[128];
  ksIteratorPtr iter( kompas->GetIterator() );
  if ( !iter )
    return;
  if ( iter->ksCreateIterator( ALL_OBJ, 0 ) ) {
    if ( doc->ksExistObj( obj = iter->ksMoveIterator( _T("F") )) ){
      do {
        doc->ksLightObj( obj, 1 );
        count ++;
        ::_stprintf_s( buf, _T("номер = %d"), count );
        kompas->ksMessage( buf );
        doc->ksLightObj( obj, 0 );
      } while( doc->ksExistObj ( obj = iter->ksMoveIterator( _T("N") )) );
    }
    iter->ksDeleteIterator();
  }
}

//-------------------------------------------------------------------------------
//
// ---
void WalkFromMacro( ksDocument2DPtr& doc ) {
  //в текущем документе и виде создадим итератор для хождения по макроэлементам
  reference obj, macro;
  TCHAR s[50],s1[50];
  int count  = 0, count1=0 ;
  ::_tcscpy_s( s,  _T("номер макро=%d")   );
  ::_tcscpy_s( s1, _T("номер объекта=%d") );
  ksIteratorPtr iter( kompas->GetIterator() );
  if ( !iter )
    return;
  if ( iter->ksCreateIterator( MACRO_OBJ, 0 ) ) {
    if ( doc->ksExistObj( macro = iter->ksMoveIterator( _T("F") )) ){
      do {
        count ++;
        UserLightObj( macro, s, count, doc ); // подсветим макроэлемент
        ksIteratorPtr iter2( kompas->GetIterator() ); // создаем итератор для хождения по макроэлементу
        iter2->ksCreateIterator( ALL_OBJ, macro );
        if ( iter2->reference ) {
          if ( doc->ksExistObj( obj = iter2->ksMoveIterator( _T("F") )) ){
            do {
              count1++;
              UserLightObj( obj, s1, count1, doc ); //подсветим объект в макро
            }  while ( doc->ksExistObj ( obj = iter2->ksMoveIterator( _T("N") )) );
          }
        }
      } while( doc->ksExistObj ( macro = iter->ksMoveIterator( _T("N") )) );
    }
    iter->ksDeleteIterator();
  }
  if ( !count )
    kompas->ksError( _T("Макроэлементы в документе отсутствуют") );
}

//-------------------------------------------------------------------------------
//
// ---
void WalkFromDoc() {
  ksDocument2DPtr doc( kompas->Document2D() );
  ksDocumentParamPtr docPar ( kompas->GetParamStruct(ko_DocumentParam) );
  TCHAR buf[128];
  if ( docPar && doc ) {
    docPar->Init();
    docPar->type = lt_DocSheetStandart;
    
    ksSheetParPtr sheetPar( docPar->GetLayoutParam() );
    if ( !sheetPar ) 
      return;
    sheetPar->Init();
    sheetPar->shtType = 1;
    sheetPar->layoutName = _T("");

    ksStandartSheetPtr stSheet( sheetPar->GetSheetParam() );
    if ( !stSheet ) 
      return;
    stSheet->Init();

    docPar->comment      = _T("create document");
    docPar->author       = _T("Misha");
    docPar->regime       = 0;
    sheetPar->layoutName = _T("");
    sheetPar->shtType    = 1;
    stSheet->format      = 3;
    stSheet->multiply    = 1;
    stSheet->direct      = 0;

    docPar->fileName     = _T("a.cdw");
    doc->ksCreateDocument( docPar );
    docPar->fileName     = _T("b.cdw");
    doc = kompas->Document2D();
    doc->ksCreateDocument( docPar );
    docPar->fileName     = _T("c.cdw");
    doc = kompas->Document2D();
    doc->ksCreateDocument( docPar );

    int count=0;
    ksIteratorPtr iter( kompas->GetIterator() );
    if ( !iter )
      return;
    if ( iter->ksCreateIterator( DOCUMENT_OBJ, 0 ) ) { //создаем итератор для хождения по документам
      reference pDoc = iter->ksMoveIterator( _T("F") );
      if ( pDoc ){
        
        ksViewParamPtr viewPar( kompas->GetParamStruct(ko_ViewParam) );
        if ( !viewPar )
          return;

        do {
          doc = kompas->ksGetDocumentByReference( pDoc );
          if ( doc->ksSetObjParam( pDoc, 0, DOCUMENT_STATE ) ) { //активизируем документ pDoc
            count ++;

            viewPar->Init();

            long number     = count;
            viewPar->x      = 10;
            viewPar->y      = 20;
            viewPar->scale_ = 1;
            viewPar->angle  = 0;
            viewPar->color  = RGB(10,20,10);
            viewPar->state  = stACTIVE;
            viewPar->name   = _T("user view");

            doc->ksCreateSheetView( viewPar, &number ); //создадим вид в документе
            doc->ksLayer( count ); // откроем слой
            switch ( count ) {
              case 1: doc->ksLineSeg   ( 20, 10, 40, 10, 1 );         break; //в первом документе создадим отрезок
              case 2: doc->ksCircle    ( 50, 50, 20, 1 );             break; //во втором документе создадим окружность
              case 3: doc->ksArcByAngle( 50, 50, 20, 45, 135, 1, 1 ); break; //в третьем документе создадим  дугу
            }
            ::_stprintf_s(buf, _T("документ %d"), count );
            kompas->ksMessage( buf );
          }
          pDoc = iter->ksMoveIterator( _T("N") );
        } while ( pDoc );
      }
      iter->ksDeleteIterator();
    }
  }
}

// создать документ
static void CreateDocument( ksDocument2DPtr& doc ) {
  ksDocumentParamPtr docPar ( kompas->GetParamStruct(ko_DocumentParam) );
  if ( !docPar || !doc ) 
    return;
  docPar->Init();
  docPar->type = lt_DocSheetStandart;
  
  ksSheetParPtr sheetPar( docPar->GetLayoutParam() );
  if ( !sheetPar ) 
    return;
  sheetPar->Init();
  sheetPar->shtType    = 1;
  sheetPar->layoutName = _T("");

  ksStandartSheetPtr stSheet( sheetPar->GetSheetParam() );
  if ( !stSheet ) 
    return;
  stSheet->Init();

  docPar->comment   = _T("create document");
  docPar->author    = _T("Misha");
  docPar->regime    = 0;
  stSheet->format   = 3;
  stSheet->multiply = 1;
  stSheet->direct   = 0;

  docPar->fileName  = _T("a.cdw");
  doc->ksCreateDocument( docPar );
}


//-------------------------------------------------------------------------------
//
// ---
void WalkViewDoc( ksDocument2DPtr & doc ) {
   CreateDocument( doc ); // создать документ

  //создадим 5 видов
  for( int i = 0; i < 5; i++ ) 
  {
    ksViewParamPtr viewPar( kompas->GetParamStruct(ko_ViewParam) );
    if ( !viewPar )
      return;

    viewPar->Init();

    long number = 0;
    viewPar->x = 10;
    viewPar->y = 20;
    viewPar->scale_ = 1;
    viewPar->angle  = 0;
    viewPar->color  = RGB(10,20,10);
    viewPar->state  = stACTIVE;
    viewPar->name   = _T("user view");

    doc->ksCreateSheetView( viewPar, &number ); //создадим вид в документе
  }

  reference  pView;
  int count = 0;
  ksIteratorPtr iter( kompas->GetIterator() );
  if ( !iter )
    return;
  if ( iter->ksCreateIterator( VIEW_OBJ, 0 ) ) { //создадим итератор для навигации по видам в документе
    pView = iter->ksMoveIterator( _T("F") );
    if ( pView ){
      do  {
        ksLtVariantPtr var( kompas->GetParamStruct(ko_LtVariant) );
        if ( !var ) 
          return;
           
        var->Init();

        var->intVal = stCURRENT;
        if ( doc->ksSetObjParam( pView, var, VIEW_LAYER_STATE )) 
        {
          switch (count) {
            case 1: doc->ksLineSeg( 20, 20, 40, 20, 1 ); break;
            case 2: doc->ksCircle( 40, 20, 30, 1 );      break;
            case 3: doc->ksArcByAngle( 50, 50, 20, 45, 135, 1, 1 ); break;
            case 4:
              doc->ksMtr(40,0,0,1,1);
              doc->ksLineSeg( 10, 10, 30, 30, 1 );
              doc->ksLineSeg( 30, 30, 60, 10, 1 );
              doc->ksLineSeg( 60, 10, 10, 10, 1 );
              doc->ksDeleteMtr();
            break;
            case 5:
              doc->ksCircle( 30, 30, 20, 1 );
              doc->ksCircle( 30, 30, 10, 1 );
              doc->ksHatch( 0, 45, 2, 0, 0, 0);
                doc->ksCircle( 30, 30, 20, 1 );
                doc->ksCircle( 30, 30, 10, 1 );
              doc->ksEndObj();
            break;
          }
        }
        count++;
        pView = iter->ksMoveIterator ( _T("N") );
      } while ( pView );
    }
    iter->ksDeleteIterator();
  }
}

//-------------------------------------------------------------------------------
//
// ---
void WalkGroup( ksDocument2DPtr& doc ) {
  reference  pNameGrp;
  int count =0;
  TCHAR buf[128];
  ksIteratorPtr iter( kompas->GetIterator() );
  if ( !iter )
    return;
  if ( iter->ksCreateIterator( NAME_GROUP_OBJ, 0 ) ) { //создадим итератор для движения по именнованным группам в документе
    pNameGrp = iter->ksMoveIterator( _T("F") );
    if ( pNameGrp ){
      do  {
        doc->ksLightObj( pNameGrp, 1 );   //подсветим группу
        count ++;
        ::_stprintf_s(buf, _T("номер = %d"), count );
        kompas->ksMessage( buf );
        doc->ksLightObj( pNameGrp, 0 );   //снимем подсветку
      } while( (pNameGrp = iter->ksMoveIterator( _T("N") ))!=0 );
    }
    iter->ksDeleteIterator();
  }
  //все именнованные группы ложатся в массив рабочих групп
  doc->ksNewGroup(0);
    doc->ksCircle( 30, 30, 20, 1 );
    doc->ksCircle( 30, 30, 10, 1 );
    doc->ksHatch( 0, 45, 2, 0, 0, 0);
      doc->ksCircle( 30, 30, 20, 1 );
      doc->ksCircle( 30, 30, 10, 1 );
    doc->ksEndObj();
  doc->ksEndGroup();

  //создать итератор по рабочим группам
  count = 0;
  reference pWorkGrp;
  if ( iter->ksCreateIterator( WORK_GROUP_OBJ, 0 ) ) { //создадим итератор для движения по именнованным группам в документе
    pWorkGrp = iter->ksMoveIterator( _T("F") );
    if ( pWorkGrp ){
      do {
        doc->ksLightObj( pWorkGrp, 1 );   //подсветим группу
        count ++;
        ::_stprintf_s(buf, _T("номер = %d"), count );
        kompas->ksMessage( buf );
        doc->ksLightObj( pWorkGrp, 0 );   //снимем подсветку
      } while ( ( pWorkGrp = iter->ksMoveIterator( _T("N") ) )!=0  );
    }
    iter->ksDeleteIterator();
  }
}

//-------------------------------------------------------------------------------
//
// ---
void WalkLayer( ksDocument2DPtr& doc ) {
  TCHAR buf[128];
// НМА K6   CreateDocument( doc ); // создать документ

  //создадим 5 слоев
  for( int i = 0; i < 5; i++ ) {
    doc->ksLayer( i );
    doc->ksCircle( 30, 30, 5 + i * 10, 1 );
  }

  reference pLayer;
  ksIteratorPtr iter( kompas->GetIterator() );
  if ( !iter )
    return;
  if ( iter->ksCreateIterator( LAYER_OBJ, 0 ) ) { //создаем итератор по слоям
    pLayer = iter->ksMoveIterator( _T("F") );
    int count = 0;
    if ( pLayer ){
      do {
        doc->ksLightObj( pLayer, 1 );   //подсветим группу
        ::_stprintf_s(buf, _T("слой = %d"), count );
        kompas->ksMessage( buf );
        doc->ksLightObj( pLayer, 0 );   //снимем подсветку
        count ++;
      } while( (pLayer = iter->ksMoveIterator( _T("N") )) !=0 );
    }
    iter->ksDeleteIterator();
  }
}

//-------------------------------------------------------------------------------
//
// ---
void WalkFromGroup( ksDocument2DPtr& doc ) {
  TCHAR buf[128];
  doc->ksMtr( 20, 10, 0, 1, 1 );
  reference pGrp = doc->ksNewGroup(0);
    doc->ksLineSeg( 10, 50, 50, 50, 1 );
    doc->ksLineSeg( 10, 10, 50, 10, 1 );
    doc->ksLineSeg( 10, 10, 10, 50, 1 );
    doc->ksLineSeg( 50, 10, 50, 50, 1 );
    doc->ksCircle( 30, 30, 20, 1 );
    doc->ksCircle( 30, 30, 10, 1 );
    doc->ksHatch( 0, 45, 2, 0, 0, 0);
      doc->ksCircle( 30, 30, 20, 1 );
      doc->ksCircle( 30, 30, 10, 1 );
    doc->ksEndObj();
  doc->ksEndGroup();
  doc->ksDeleteMtr();
  
  reference obj;
  ksIteratorPtr iter( kompas->GetIterator() );
  if ( !iter )
    return;
  if ( iter->ksCreateIterator( ALL_OBJ, pGrp ) ) { //создать итератор для хождения по группе
    obj = iter->ksMoveIterator( _T("F") );
    int count = 0;
    if ( doc->ksExistObj(obj) ){
      do {
        doc->ksLightObj( obj, 1 );
        count ++;
        ::_stprintf_s(buf, _T("номер = %d"), count );
        kompas->ksMessage( buf );
        doc->ksLightObj( obj, 0 );
      } while( doc->ksExistObj ( obj = iter->ksMoveIterator( _T("N") )) );
    }
    iter->ksDeleteIterator();
  }
}

//-------------------------------------------------------------------------------
//хождение по элементам документа с определенным атрибутом
// ---
void WalkFromDocWithAttr( ksDocument2DPtr& doc ) {
  
  ksAttributeObjectPtr attr( kompas->GetAttributeObject() );
  if ( !attr )
    return;

  reference pObj, pAttr;
  TCHAR buf[128];
  ksIteratorPtr iter( kompas->GetIterator() );
  if ( !iter )
    return;
  if ( iter->ksCreateAttrIterator( 0, 10, 0,0,0,0 ) ) { //создадим итератор для поиска объектов по ключу 10
    pAttr = iter->ksMoveAttrIterator( _T("F"), &pObj );
    int count = 0;
    long rowsCount, columnsCount;
    if ( pAttr && doc->ksExistObj(pObj) ){
      do {
        doc->ksLightObj( pObj, 1 );
        count ++;
        //узнаем количество строк и колонок
        if(attr->ksGetAttrTabInfo( pAttr, &rowsCount, &columnsCount )) {
          ::_stprintf_s(buf, _T("номер = %d rowsCount=%d columnsCount=%d"), count,rowsCount,columnsCount );
          kompas->ksMessage( buf );
        }
        else
          kompas->ksMessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции

        doc->ksLightObj( pObj, 0 );

        pAttr = iter->ksMoveAttrIterator( _T("N"), &pObj );
      } while( pAttr && doc->ksExistObj(pObj));
    }
    iter->ksDeleteIterator();
  }
}

//-------------------------------------------------------------------------------
//хождение по атрибутам объекта
// ---
void WalkFromObjWithAttr( ksDocument2DPtr& doc ) {
  double x, y;
  int j;
  reference pObj;
   ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  ksAttributeObjectPtr attr( kompas->GetAttributeObject() );
  if ( !info || !attr ) 
    return;

  info->Init();

  info->prompt = _T("Укажите объект");
  do {
    j = doc->ksCursor( info, &x ,&y, 0 );
    if ( j ) {
      if( doc->ksExistObj(pObj = doc->ksFindObj( x, y, 1e6 )) ){
        int count = 0;
        TCHAR buf[128];
        long rowsCount, columnsCount;
        doc->ksLightObj( pObj, 1 );

        reference pAttr;
        ksIteratorPtr iter( kompas->GetIterator() );
        if ( !iter )
          return;
        if ( iter->ksCreateAttrIterator( pObj, 10, 0, 0, 0, 0 ) ) { //создадим итератор для поиска объектов по ключу 10
          pAttr = iter->ksMoveAttrIterator( _T("F"), 0 );
          if ( pAttr ) {//doc->ksExistObj(pAttr) ){
            do {
              count ++;
              //узнаем количество строк и колонок
              if( attr->ksGetAttrTabInfo ( pAttr, &rowsCount, &columnsCount ) ) {
                ::_stprintf_s(buf, _T("номер = %d rowsCount=%d columnsCount=%d"), count,rowsCount,columnsCount );
                kompas->ksMessage( buf );
              }
              else
                kompas->ksMessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
              pAttr = iter->ksMoveAttrIterator( _T("N"), 0 );
            } while( pAttr );
          }
           iter->ksDeleteIterator();
        }
        doc->ksLightObj( pObj, 0 );
      }
    }
  } while(j);
}
