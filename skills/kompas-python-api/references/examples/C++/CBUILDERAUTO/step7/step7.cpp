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

void WalkFromView       ( ksDocument2DPtr & doc );
void WalkFromMacro      ( ksDocument2DPtr & doc );
void WalkFromDoc        ();
void WalkViewDoc        ( ksDocument2DPtr & doc );
void WalkGroup          ( ksDocument2DPtr & doc );
void WalkLayer          ( ksDocument2DPtr & doc );
void WalkFromGroup      ( ksDocument2DPtr & doc );
void WalkFromDocWithAttr( ksDocument2DPtr & doc );
void WalkFromObjWithAttr( ksDocument2DPtr & doc );

char buf[128];

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
		if ( comm == 3 )
      ::WalkFromDoc(); //хождение по документам
    else {
      ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
      if ( (bool)doc && doc->reference ) {
        switch ( comm ) {
          case 1  : ::WalkFromView       ( doc ); break; // хождение по виду
          case 2  : ::WalkFromMacro      ( doc ); break; // хождение по макроэлементу
          case 4  : ::WalkViewDoc        ( doc ); break; // хождение по видам
          case 5  : ::WalkGroup          ( doc ); break; // хождение по именнованным и рабочим группам
          case 6  : ::WalkLayer          ( doc ); break; // хождение по слоям
          case 7  : ::WalkFromGroup      ( doc ); break; // хождение по группе
          case 8  : ::WalkFromDocWithAttr( doc ); break; // хождение по элементам документа с определенным атрибутом
          case 9  : ::WalkFromObjWithAttr( doc ); break; // хождение по атрибутам объекта
        }
      }
      else
        kompas->ksError(  TO_OLE(L"Документ не активизирован или \nне является листом/фрагментом") );
    }
    kompas.Unbind();
  }
}

//------------------------------------------------------------------------------
// подсветка объекта
// ---
static void UserLightObj( reference obj, char *c, int count, ksDocument2DPtr & doc ) {
  doc->ksLightObj( obj, 1 );
  ::sprintf(buf, c, count );
  kompas->ksMessage( TO_OLE(buf) );
  doc->ksLightObj( obj, 0 );
}

//------------------------------------------------------------------------------
// хождение по виду
// ---
void WalkFromView( ksDocument2DPtr &doc ) {
  //в текущем документе и виде создадим итератор для хождения по всем элементам
  reference obj;
  int count  = 0;
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  if ( iter->ksCreateIterator( ALL_OBJ, 0 ) ) {
    if ( doc->ksExistObj( obj = iter->ksMoveIterator(  TO_OLE(L"F") ) ) ){
      do {
        doc->ksLightObj( obj, 1 );
        count ++;
        ::sprintf( buf, "номер = %d", count );
        kompas->ksMessage( TO_OLE(buf) );
        doc->ksLightObj( obj, 0 );
      } while( doc->ksExistObj( obj = iter->ksMoveIterator(  TO_OLE(L"N") )) );
    }
    iter->ksDeleteIterator();
  }
}

//------------------------------------------------------------------------------
// хождение по макроэлементу
// ---
void WalkFromMacro( ksDocument2DPtr & doc ) {
  //в текущем документе и виде создадим итератор для хождения по макроэлементам
  reference obj, macro;
  char s[50], s1[50];
  int count  = 0, count1=0 ;
  ::strcpy(s,"номер маскро=%d");
  ::strcpy(s1,"номер объекта=%d");
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  if ( iter->ksCreateIterator( MACRO_OBJ, 0 ) ) {
    if ( doc->ksExistObj( macro = iter->ksMoveIterator(  TO_OLE(L"F") )) ){
      do {
        count ++;
        UserLightObj( macro, s, count, doc ); // подсветим макроэлемент
        ksIteratorPtr iter2( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ ); // создаем итератор для хождения по макроэлементу
        iter2->ksCreateIterator( ALL_OBJ, macro );
        if ( iter2->reference ) {
          if ( doc->ksExistObj( obj = iter2->ksMoveIterator(  TO_OLE(L"F") )) ){
            do {
              count1++;
              UserLightObj( obj, s1, count1, doc ); //подсветим объект в макро
            }  while ( doc->ksExistObj( obj = iter2->ksMoveIterator(  TO_OLE(L"N") )) );
          }
        }
      } while( doc->ksExistObj( macro = iter->ksMoveIterator(  TO_OLE(L"N") )) );
    }
    iter->ksDeleteIterator();
  }
}

//------------------------------------------------------------------------------
// хождение по документам
// ---
void WalkFromDoc() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->Document2D(), false/*AddRef*/ );
  if ( doc ) {
    reference pDoc;
    ksDocumentParamPtr docPar( (ksDocumentParam*)kompas->GetParamStruct(ko_DocumentParam), false/*AddRef*/ );
    if ( !docPar )
      return;
    ksSheetParPtr sheetPar( (ksSheetPar*)docPar->GetLayoutParam(), false/*AddRef*/ );
    if ( !sheetPar )
      return;
    ksStandartSheetPtr stSheet( (ksStandartSheet*)sheetPar->GetSheetParam(), false/*AddRef*/ );
    if ( !stSheet )
      return;

    docPar->Init();
    sheetPar->Init();
    stSheet->Init();

    docPar->comment =  TO_OLE(L"create document");
    docPar->author  =  TO_OLE(L"Misha");
    docPar->regime  = 0;
    docPar->type    = 1;
    sheetPar->layoutName =  TO_OLE(L"");
    sheetPar->shtType = 1;
    stSheet->format   = 3;
    stSheet->multiply = 1;
    stSheet->direct   = 0;

    docPar->fileName =  TO_OLE(L"a.cdw");
    doc->ksCreateDocument( docPar );
    docPar->fileName =  TO_OLE(L"b.cdw");
    doc->ksCreateDocument( docPar );
    docPar->fileName =  TO_OLE(L"c.cdw");
    doc->ksCreateDocument( docPar );

    int count=0;
    ksIterator * iter = (ksIterator*)kompas->GetIterator();
    if ( iter->ksCreateIterator( DOCUMENT_OBJ, 0 ) ) { //создаем итератор для хождения по документам
      pDoc = iter->ksMoveIterator(  TO_OLE(L"F") );
      if ( pDoc ){
        do {
          doc->reference = pDoc;
          if ( doc->ksSetObjParam( pDoc, 0, DOCUMENT_STATE )) { //активизируем документ pDoc
            count ++;
            ksViewParam * viewPar = (ksViewParam*)kompas->GetParamStruct(ko_ViewParam);
            if ( !viewPar )
              return;

            viewPar->Init();

            long number = count;
            viewPar->x = 10;
            viewPar->y = 20;
            viewPar->scale_ = 1;
            viewPar->angle  = 0;
            viewPar->color = RGB(10,20,10);
            viewPar->state = stACTIVE;
            viewPar->name  =  TO_OLE(L"user view");

            doc->ksCreateSheetView( viewPar, &number ); //создадим вид в документе
            doc->ksLayer( count ); // откроем слой
            switch ( count ) {
              case 1: doc->ksLineSeg( 20, 10, 40, 10, 1 );            break; //в первом документе создадим отрезок
              case 2: doc->ksCircle ( 50, 50, 20, 1 );                break; //во втором документе создадим окружность
              case 3: doc->ksArcByAngle( 50, 50, 20, 45, 135, 1, 1 ); break; //в третьем документе создадим  дугу
            }
            ::sprintf(buf, "документ %d ", count );
            kompas->ksMessage( TO_OLE(buf) );
          }
          pDoc = iter->ksMoveIterator(  TO_OLE(L"N") );
        } while ( pDoc );
      }
      iter->ksDeleteIterator();
    }
  }
}

//------------------------------------------------------------------------------
// хождение по видам
// ---
void WalkViewDoc( ksDocument2DPtr & doc ) {
  ksDocumentParamPtr docPar( (ksDocumentParam*)kompas->GetParamStruct(ko_DocumentParam), false/*AddRef*/ );
  if ( !(bool)docPar )
    return;
  ksSheetParPtr sheetPar( (ksSheetPar*)docPar->GetLayoutParam(), false/*AddRef*/ );
  if ( !(bool)sheetPar )
    return;
  ksStandartSheetPtr stSheet( (ksStandartSheet*)sheetPar->GetSheetParam(), false/*AddRef*/ );
  if ( !stSheet )
    return;

  docPar->Init();
  sheetPar->Init();
  stSheet->Init();

  docPar->comment =  TO_OLE(L"create document");
  docPar->author  =  TO_OLE(L"Misha");
  docPar->regime  = 0;
  docPar->type    = 1;
  sheetPar->layoutName =  TO_OLE(L"");
  sheetPar->shtType = 1;
  stSheet->format   = 3;
  stSheet->multiply = 1;
  stSheet->direct   = 0;

  docPar->fileName =  TO_OLE(L"a.cdw");
  doc->ksCreateDocument( docPar );

  //создадим 5 видов
  for( int i = 0; i < 5; i++ ) {
    ksViewParamPtr viewPar( (ksViewParam*)kompas->GetParamStruct(ko_ViewParam), false/*AddRef*/ );
    if ( !viewPar )
      return;

    viewPar->Init();

    long number     = 0;
    viewPar->x      = 10;
    viewPar->y      = 20;
    viewPar->scale_ = 1;
    viewPar->angle  = 0;
    viewPar->color  = RGB(10,20,10);
    viewPar->state  = stACTIVE;
    viewPar->name   =  TO_OLE(L"user view");

    doc->ksCreateSheetView( viewPar, &number); //создадим вид в документе
  }

  reference  pView;
  int count =0;
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  if ( iter->ksCreateIterator( VIEW_OBJ, 0 ) ) { //создадим итератор для навигации по видам в документе
    pView = iter->ksMoveIterator(  TO_OLE(L"F") );
    if ( pView ){
      do  {
        ksLtVariantPtr var( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
        if ( !var )
          return;

        var->Init();

        var->intVal = stCURRENT;
        if ( doc->ksSetObjParam( pView, var, VIEW_LAYER_STATE )) {
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
        pView = iter->ksMoveIterator(  TO_OLE(L"N") );
      } while ( pView );
    }
    iter->ksDeleteIterator();
  }
}

//------------------------------------------------------------------------------
// хождение по именнованным и рабочим группам
// ---
void WalkGroup( ksDocument2DPtr & doc ) {
  reference  pNameGrp;
  int count =0;
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  if ( iter->ksCreateIterator( NAME_GROUP_OBJ, 0 ) ) { //создадим итератор для движения по именнованным группам в документе
    pNameGrp = iter->ksMoveIterator(  TO_OLE(L"F") );
    if ( pNameGrp ){
      do  {
        doc->ksLightObj( pNameGrp, 1 );   //подсветим группу
        count ++;
        ::sprintf(buf,"номер = %d", count );
        kompas->ksMessage( TO_OLE(buf) );
        doc->ksLightObj( pNameGrp, 0 );   //снимем подсветку
      } while( (pNameGrp = iter->ksMoveIterator(  TO_OLE(L"N") )) != 0 );
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
  iter->ksCreateIterator( WORK_GROUP_OBJ, 0 ); //создадим итератор для движения по именнованным группам в документе
  if ( iter->reference ) {
    pWorkGrp = iter->ksMoveIterator(  TO_OLE(L"F") );
    if ( pWorkGrp ){
      do {
        doc->ksLightObj( pWorkGrp, 1 );   //подсветим группу
        count ++;
        ::sprintf(buf,"номер = %d", count );
        kompas->ksMessage( TO_OLE(buf) );
        doc->ksLightObj( pWorkGrp, 0 );   //снимем подсветку
      } while ( ( pWorkGrp = iter->ksMoveIterator(  TO_OLE(L"N") ) ) !=0 );
    }
  }
}

//------------------------------------------------------------------------------
// хождение по слоям
// ---
void WalkLayer( ksDocument2DPtr & doc ) {
  ksDocumentParamPtr docPar( (ksDocumentParam*)kompas->GetParamStruct(ko_DocumentParam), false/*AddRef*/ );
  if ( !docPar )
    return;
  ksSheetParPtr  sheetPar( (ksSheetPar*)docPar->GetLayoutParam(), false/*AddRef*/ );
  if ( !sheetPar )
    return;
  ksStandartSheetPtr stSheet( (ksStandartSheet*)sheetPar->GetSheetParam(), false/*AddRef*/ );
  if ( !stSheet )
    return;

  docPar->Init();
  sheetPar->Init();
  stSheet->Init();

  docPar->comment =  TO_OLE(L"create document");
  docPar->author  =  TO_OLE(L"Misha");
  docPar->regime  = 0;
  docPar->type    = 1;
  sheetPar->layoutName =  TO_OLE(L"");
  sheetPar->shtType    = 1;
  stSheet->format      = 3;
  stSheet->multiply    = 1;
  stSheet->direct      = 0;

  docPar->fileName     =  TO_OLE(L"a.cdw");
  doc->ksCreateDocument( docPar );

  //создадим 5 слоев

  for( int i = 0; i < 5; i++ ) {
    doc->ksLayer( i );
    doc->ksCircle( 30, 30, 5 + i * 10, 1 );
  }

  reference pLayer;
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  iter->ksCreateIterator( LAYER_OBJ, 0 ); //создаем итератор по слоям
  if ( iter->reference ) {
    pLayer = iter->ksMoveIterator( TO_OLE(L"F") );
    int count = 0;
    if ( pLayer ){
      do {
        doc->ksLightObj( pLayer, 1 );   //подсветим группу
        ::sprintf(buf,"слой = %d", count );
        kompas->ksMessage( TO_OLE(buf) );
        doc->ksLightObj( pLayer, 0 );   //снимем подсветку
        count ++;
      } while( (pLayer = iter->ksMoveIterator( TO_OLE(L"N") )) !=0 );
    }
  }
}

//------------------------------------------------------------------------------
// хождение по группе
// ---
void WalkFromGroup( ksDocument2DPtr & doc ) {
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
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  iter->ksCreateIterator( ALL_OBJ, pGrp ); //создать итератор для хождения по группе
  if ( iter->reference ) {
    obj = iter->ksMoveIterator(  TO_OLE(L"F") );
    int count = 0;
    if ( doc->ksExistObj(obj) ){
      do {
        doc->ksLightObj( obj, 1 );
        count ++;
        ::sprintf(buf,"номер = %d", count );
        kompas->ksMessage( TO_OLE(buf) );
        doc->ksLightObj( obj, 0 );
      } while( doc->ksExistObj ( obj = iter->ksMoveIterator(  TO_OLE(L"N") )) );
    }
  }
}

//------------------------------------------------------------------------------
// хождение по элементам документа с определенным атрибутом
// ---
void WalkFromDocWithAttr( ksDocument2DPtr & doc ) {
  ksAttributeObjectPtr attr( (ksAttributeObject*)kompas->GetAttributeObject(), false/*AddRef*/ );
  if ( !attr )
    return;

  reference pObj, pAttr;
  char buf[128];
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  iter->ksCreateAttrIterator( 0, 10, 0,0,0,0 ); //создадим итератор для поиска объектов по ключу 10
  if ( iter->reference ) {
    pAttr = iter->ksMoveAttrIterator(  TO_OLE(L"F"), &pObj );
    int count = 0;
    long rowsCount, columnsCount;
    if ( pAttr && doc->ksExistObj(pObj) ){
      do {
        doc->ksLightObj( pObj, 1 );
        count ++;
        //узнаем количество строк и колонок
        if(attr->ksGetAttrTabInfo( pAttr, &rowsCount, &columnsCount )) {
          ::sprintf(buf,"номер = %d rowsCount=%d columnsCount=%d", count,rowsCount,columnsCount );
          kompas->ksMessage( TO_OLE(buf) );
        }
        else
          kompas->ksMessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции

        doc->ksLightObj( pObj, 0 );

        pAttr = iter->ksMoveAttrIterator(  TO_OLE(L"N"), &pObj );
      } while( pAttr && doc->ksExistObj(pObj));
    }
  }
}

//------------------------------------------------------------------------------
// хождение по атрибутам объекта
// ---
void WalkFromObjWithAttr( ksDocument2DPtr & doc ) {
  double x, y;
  int j;
  reference pObj;
  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
  ksAttributeObjectPtr attr( (ksAttributeObject*)kompas->GetAttributeObject(), false/*AddRef*/ );
  if ( !info || !attr )
    return;

  info->Init();

  info->prompt =  TO_OLE(L"Укажите объект");
  do {
    j = doc->ksCursor( info, &x ,&y, 0 );
    if ( j ) {
      if( doc->ksExistObj(pObj = doc->ksFindObj( x, y, 1e6 )) ){
        int count = 0;
        char buf[128];
        long rowsCount, columnsCount;
        doc->ksLightObj( pObj, 1 );

        reference pAttr;
        ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
        if ( !iter )
          return;
        if ( iter->ksCreateAttrIterator( pObj, 10, 0,0,0,0 ) ) { //создадим итератор для поиска объектов по ключу 10
          pAttr = iter->ksMoveAttrIterator(  TO_OLE(L"F"), 0 );
          if ( pAttr ) {
            do {
              count ++;
              //узнаем количество строк и колонок
              if( attr->ksGetAttrTabInfo( pAttr, &rowsCount, &columnsCount ) ) {
                ::sprintf(buf,"номер = %d rowsCount=%d columnsCount=%d", count,rowsCount,columnsCount );
                kompas->ksMessage( TO_OLE(buf) );
              }
              else
                kompas->ksMessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
              pAttr = iter->ksMoveAttrIterator(  TO_OLE(L"N"), 0 );
            } while( pAttr );
          }
        }
        doc->ksLightObj( pObj, 0 );
      }
    }
  } while(j);
}



