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

void DrawTransform        ( ksDocument2DPtr & doc );
void DrawCopy             ( ksDocument2DPtr & doc );
void DrawSymmetry         ( ksDocument2DPtr & doc );
void EditTolerance        ( ksDocument2DPtr & doc );
void EditTable            ( ksDocument2DPtr & doc );
void EditStamp            ( ksDocument2DPtr & doc );
void GetTextTT            ( ksDocument2DPtr & doc );
void ShowInsertFragment   ( ksDocument2DPtr & doc );
void ShowInsertFragment1  ( ksDocument2DPtr & doc );
void EditFragmentLibrary  ( ksDocument2DPtr & doc );
void ChangeTechnicalDemand( ksDocument2DPtr & doc );

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
    ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
    if ( (bool)doc && doc->reference ) {
      switch ( comm ) {
        case 1  : ::DrawTransform        ( doc ); break; // трансформация объекта по матрице
        case 2  : ::DrawCopy             ( doc ); break; // копирование объекта
        case 3  : ::DrawSymmetry         ( doc ); break; // симметрия объекта
        case 4  : ::EditTolerance        ( doc ); break; // просмотр допуска формы
        case 5  : ::EditTable            ( doc ); break; // просмотр таблицы
        case 6  : ::EditStamp            ( doc ); break; // взять тексты граф и редактировать штамп
        case 7  : ::GetTextTT            ( doc ); break; // получить текст ТТ
        case 8  : ::ChangeTechnicalDemand( doc ); break; // редактирование TT
        case 9  : ::ShowInsertFragment   ( doc ); break; // вставка фрагмента
        case 10 : ::EditFragmentLibrary  ( doc ); break; // работа с библиотекой фрагментов
        case 11 : ::ShowInsertFragment1  ( doc ); break; // вставка фрагмента россыпью
      }
    }
    else
      kompas->ksError( TO_OLE(L"Документ не активизирован или \nне является листом/фрагментом") );
    kompas.Unbind();
  }
}

//------------------------------------------------------------------------------
// трансформация объекта по матрице
// ---
void DrawTransform( ksDocument2DPtr & doc ) {
  //трансформация  рабочей группы
  doc->ksMtr( -30, -30, 0, 1, 1 );
  reference ref = doc->ksNewGroup(0);
  doc->ksLineSeg( 30, 30, 60, 30, 1);
  doc->ksLineSeg( 60, 30, 60, 60, 1);
  doc->ksLineSeg( 60, 60, 30, 60, 1);
  doc->ksLineSeg( 30, 60, 30, 30, 1);
  doc->ksHatch( 0, 45, 2, 0, 0, 0 );
    doc->ksLineSeg( 30, 30, 60, 30, 1);
    doc->ksLineSeg( 60, 30, 60, 60, 1);
    doc->ksLineSeg( 60, 60, 30, 60, 1);
    doc->ksLineSeg( 30, 60, 30, 30, 1);
  doc->ksEndObj();
  doc->ksEndGroup();
  doc->ksDeleteMtr();

  kompas->ksMessage( TO_OLE(L"Cоздали матрицу 20, 20, 45, 2") );

  doc->ksMtr(20, 20, 45, 2, 2 );
  doc->ksTransformObj( ref );
  doc->ksDeleteMtr();

  kompas->ksMessageBoxResult();
  kompas->ksMessage( TO_OLE(L"Вернем обратно") );

  doc->ksMtr(-20, -20, 0, 1, 1 );
  doc->ksTransformObj( ref );
  doc->ksDeleteMtr();

  doc->ksMtr(0, 0, 0, 0.5, 0.5 );
  doc->ksTransformObj( ref );
  doc->ksDeleteMtr();

  doc->ksMtr(0, 0, -45, 1, 1 );
  doc->ksTransformObj( ref );
  doc->ksDeleteMtr();

  kompas->ksMessageBoxResult();
}

//------------------------------------------------------------------------------
// копирование объекта
// ---
void DrawCopy( ksDocument2DPtr & doc ) {
  ksViewParamPtr par( (ksViewParam*)kompas->GetParamStruct( ko_ViewParam ), false/*AddRef*/ );
  if ( par ) {
    par->Init();
    par->x      = 20;
    par->y      = 60;
    par->scale_ = 1;
    par->color  = RGB(10,20,10);
    par->state  = stACTIVE;
    par->name   = TO_OLE(L"user view");

    long number = 5;
    //создали вид
    reference v = doc->ksCreateSheetView( par, &number);
    //создали слой
    doc->ksLayer( 5 );

    doc->ksLineSeg( 20, 10, 20, 30, 1 );
    doc->ksLineSeg( 20, 30, 40, 30, 1 );
    doc->ksLineSeg( 40, 30, 40, 10, 1 );
    doc->ksLineSeg( 40, 10, 20, 10, 1 );

    //копируем вид ( для вида точки задаются в листовых координатах )
    doc->ksCopyObj( v, 20, 60, 40, 80, 1, 0 );
  }
}

//------------------------------------------------------------------------------
// симметрия объекта
// ---
void DrawSymmetry( ksDocument2DPtr & doc ) {
  reference grp = doc->ksNewGroup( 0 );
    doc->ksLineSeg( 20, 10, 20, 30, 1 );
    doc->ksLineSeg( 20, 30, 40, 30, 1 );
    doc->ksLineSeg( 40, 30, 40, 10, 1 );
    doc->ksLineSeg( 40, 10, 20, 10, 1 );
  doc->ksEndGroup();

  doc->ksSymmetryObj( grp, 40, 10, 40, 20, TO_OLE(L"1") );
}

//------------------------------------------------------------------------------
// просмотр допуска формы
// ---
void EditTolerance( ksDocument2DPtr & doc ) {
  // редактирование допуска формы
  reference pObj;

  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
  if ( !info )
    return;
  double x, y;
  info->prompt = TO_OLE(L"Укажите допуск формы");
  int j = doc->ksCursor( info, &x ,&y, 0 );
  if ( j ) {
    if( doc->ksExistObj( pObj = doc->ksFindObj( x, y, 1000000. )) ){
      //узнаем тип объекта
      int type = doc->ksGetObjParam( pObj, 0, 0 );   //указатель на графический объект
      if ( type == TOLERANCE_OBJ ) {
        long numb;
        char buf[128];
        //открыть допуск формы для редактирования
        doc->ksOpenTolerance( pObj );

        ksToleranceParamPtr par( (ksToleranceParam*)kompas->GetParamStruct(ko_ToleranceParam), false/*AddRef*/ );
        //параметры допуска формы
        doc->ksGetObjParam( pObj,       // указатель на графический объект
                            par,        // указатель на структуру параметров
                            ALLPARAM ); // тип считывания параметров

        ::sprintf( buf, "базовая точка=%d стиль=%d расположение-%s\nx=%5.1f y=%5.1f  ",
                          par->tBase, par->style, par->type ? "вертикальное":"горизонтальное", par->x, par->y );
        kompas->ksMessage( TO_OLE(buf) );

        ksTextLineParamPtr par1( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
        if ( !par1 )
          return;
        par1->Init();
        //в цикле будем брать все существующие ячейки
        while ( doc->ksGetToleranceColumnText( &numb, par1 ) != 0 ) {
          ::sprintf( buf, "numb =%d\nstyle=%d", numb, par1->style );
          kompas->ksMessage( TO_OLE(buf) );

          ksDynamicArrayPtr arrpTextItem( (ksDynamicArray*)par1->GetTextItemArr(), false/*AddRef*/ );
          ksTextItemParamPtr item( (ksTextItemParam *)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );

          if ( !(bool)item || !(bool)arrpTextItem )
            return;
          item->Init();

          for ( int j = 0, count = arrpTextItem->ksGetArrayCount(); j < count; j++) {
            arrpTextItem->ksGetArrayItem( j, item );
            ksTextItemFontPtr textItemFont( (ksTextItemFont*)item->GetItemFont(), false/*AddRef*/ );
            if ( !item->type )
              ::sprintf( buf, "компонента=%d h=%5.1f\ns=%s\n fontName=%s\nбитвектор =%d ",j, textItemFont->height,
												 WideToAnsi(item->s), WideToAnsi(textItemFont->fontName), textItemFont->bitVector );
            else
              ::sprintf( buf, "компонента=%d тип = %d номер спецзнака=%d ", j, item->type, item->iSNumb );
            item->s = TO_OLE(L"Допуск формы");
            kompas->ksMessage( TO_OLE(buf) );
          }
          arrpTextItem->ksClearArray();
          arrpTextItem->ksAddArrayItem( -1, item );
          doc->ksSetToleranceColumnText( numb, par1 );
          arrpTextItem->ksDeleteArray();  //очистим массив компонент
        }
        //заменим параметры
        par->x += 10;
        par->y += 10;
        doc->ksSetObjParam(  pObj,   //указатель на графический объект
                      par,  //указатель на структуру параметров
                      ALLPARAM ); //тип считывания параметров
        doc->ksEndObj();//закрыли объект "допуск формы"
      }
      else
        kompas->ksError( TO_OLE(L"это не допуск формы") );
    }
    else
      kompas->ksError( TO_OLE(L"нет объекта") );
  }
}

//------------------------------------------------------------------------------
// просмотр таблицы
// ---
void EditTable( ksDocument2DPtr & doc ) {
  // редактирование таблицы
  reference pObj;

  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
  if ( !info )
    return;
  double x, y;
  info->prompt = TO_OLE(L"Укажите таблицу");
  // взять таблицу на чертеже
  int j = doc->ksCursor( info, &x ,&y, 0 );
  if ( j ) {
    if( doc->ksExistObj( pObj = doc->ksFindObj( x, y, 100000 )) ){
      //узнаем тип объекта
      int type = doc->ksGetObjParam( pObj, 0, 0 );   //указатель на графический объект
      //проверить полученный объкет  - таблица
      if ( type == TABLE_OBJ ) {
        long numb;
        //reference p;
        char buf[128];
        //открыть таблицу для редактирования
        doc->ksOpenTable( pObj );

        ksTextParamPtr par( (ksTextParam*)kompas->GetParamStruct(ko_TextParam), false/*AddRef*/ );
        if ( !par )
          return;
        par->Init();
        //в цикле будем брать все существующие ячейки
        while (( doc->ksGetTableColumnText( &numb, par )) !=0 ) {
          ::sprintf( buf, "numb =%d   ", numb );
          kompas->ksMessage( TO_OLE(buf) );

          ksDynamicArrayPtr arrpLineText( (ksDynamicArray*)par->GetTextLineArr(), false/*AddRef*/ );
          ksTextLineParamPtr itemLineText( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
          if ( !(bool)itemLineText )
            return;
          itemLineText->Init();

					for( int i = 0, count = arrpLineText->ksGetArrayCount(); i < count; i++ ) {
            arrpLineText->ksGetArrayItem( i, itemLineText );
            ::sprintf( buf, "i =%d style=%d   ", i, itemLineText->style );
            kompas->ksMessage( TO_OLE(buf) );

            ksDynamicArray * arrpTextItem = (ksDynamicArray*)itemLineText->GetTextItemArr();
            ksTextItemParam * item = (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam);

            if ( !item || !arrpTextItem )
              return;
            item->Init();

            for ( int j=0, count2 = arrpTextItem->ksGetArrayCount(); j < count2; j++) {
              arrpTextItem->ksGetArrayItem( j, item );
              ksTextItemFontPtr textItemFont( (ksTextItemFont*)item->GetItemFont(), false/*AddRef*/ );

              if ( !item->type )
                ::sprintf( buf, "компонента=%d h=%5.1f\ns=%s\n fontName=%s\nбитвектор =%d ",j, textItemFont->height,
												 WideToAnsi(item->s), WideToAnsi(textItemFont->fontName), textItemFont->bitVector );
              else
                ::sprintf( buf, "компонента=%d тип = %d номер спецзнака=%d ",j, item->type, item->iSNumb );
              kompas->ksMessage( TO_OLE(buf) );
            }
            arrpTextItem->ksDeleteArray();  //очистим массив компонент
          }
          //очистим массив текстовых строк
          arrpLineText->ksDeleteArray();
        }

        //берем ячейку 2
        doc->ksColumnNumber( 2 );
        doc->ksText( 0, 0, 0, 5, 1 ,0, TO_OLE(L"вторая ячейка") );

        doc->ksDivideTableItem( 3, 1, 2 );
        doc->ksColumnNumber( 4 );
        doc->ksText( 0, 0, 0, 5, 1 ,0, TO_OLE(L"4") );

        doc->ksEndObj();//закрыли объект "таблица"
      }
      else
        kompas->ksError( TO_OLE(L"это не таблица") );
    }
    else
      kompas->ksError( TO_OLE(L"нет объекта") );
  }
}

//------------------------------------------------------------------------------
// взять тексты граф и редактировать штамп
// ---
void EditStamp( ksDocument2DPtr & doc ) {
  ksStampPtr stamp( (ksStamp*)doc->GetStamp(), false/*AddRef*/ );
  if ( (bool)stamp && stamp->ksOpenStamp() ) {
    long numb;
    //в цикле будем брать все существующие графы
    ksDynamicArrayPtr arr( (ksDynamicArray*)stamp->ksGetStampColumnText( &numb ), false/*AddRef*/ );
    while ( numb && (bool)arr ) {
      char buf[128];
      ::sprintf( buf, "numb =%d   ", numb );
      kompas->ksMessage( TO_OLE(buf) );

      ksDynamicArrayPtr arrpLineText( (ksDynamicArray*)kompas->GetDynamicArray(TEXT_LINE_ARR), false/*AddRef*/ );
      ksTextLineParamPtr itemLineText( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
      if ( !itemLineText )
        return;
      itemLineText->Init();

      for(int i = 0, count = arr->ksGetArrayCount(); i < count; i++ ) {
        arr->ksGetArrayItem( i, itemLineText );
        ::sprintf( buf, "i =%d style=%d", i, itemLineText->style );
        kompas->ksMessage( TO_OLE(buf) );

        ksDynamicArrayPtr arrpTextItem( (ksDynamicArray*)itemLineText->GetTextItemArr(), false/*AddRef*/ );
        ksTextItemParamPtr item( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );

        if ( !(bool)item || !(bool)arrpTextItem )
          return;
        item->Init();

        for ( int j = 0, count2 = arrpTextItem->ksGetArrayCount(); j < count2; j++ ) {
          arrpTextItem->ksGetArrayItem( j, item );
          ksTextItemFontPtr textItemFont( (ksTextItemFont*)item->GetItemFont(), false/*AddRef*/ );
					::sprintf( buf, "компонента=%d h=%5.1f\ns=%s\nfontName=%s ", j, textItemFont->height, WideToAnsi(item->s),
										 WideToAnsi(textItemFont->fontName) );
          kompas->ksMessage( TO_OLE(buf) );
        }
        arrpTextItem->ksDeleteArray();  //очистим массив компонент
      }
      //очистим массив текстовых строк
      arrpLineText->ksDeleteArray();

      arr->ksDeleteArray();
      arr.Bind( (ksDynamicArray*)stamp->ksGetStampColumnText( &numb ), false/*AddRef*/ );
    }
    //заменим  графу 2
    doc->ksColumnNumber( 2 );
    ksTextItemParamPtr item( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
    if ( !item ) {
      stamp->ksCloseStamp();
      return;
    }
    item->Init();
    ksTextItemFontPtr itemFont( (ksTextItemFont*)item->GetItemFont(), false/*AddRef*/ );
    if ( itemFont ) {
      itemFont->SetBitVectorValue( NEW_LINE, true );
      item->s = TO_OLE(L"графа 2");
      doc->ksTextLine( item );
    }
    stamp->ksCloseStamp();
  }
  else
    kompas->ksError( TO_OLE(L"Штамп не найден") );
}

//------------------------------------------------------------------------------
// получить текст ТТ
// ---
void GetTextTT( ksDocument2DPtr & doc ) {
  //получим указатель на технические трбования
  reference pTT = doc->ksGetReferenceDocumentPart( 1 );
  ksTechnicalDemandParamPtr technicalDemandParam( (ksTechnicalDemandParam*)kompas->GetParamStruct(ko_TechnicalDemandParam), false/*AddRef*/ );
  if ( (bool)pTT && (bool)technicalDemandParam ) {
    technicalDemandParam->Init();
    //получим параметры описания ТТ
    doc->ksGetObjParam( pTT, technicalDemandParam, TECHNICAL_DEMAND_PAR );
    char buf[128];
    ksDynamicArrayPtr pGab( (ksDynamicArray*)technicalDemandParam->GetPGab(), false/*AddRef*/ );
    int count = pGab->ksGetArrayCount();
    ::sprintf( buf, "стиль =%d число страниц  TT =%d", technicalDemandParam->style, count );
    kompas->ksMessage( TO_OLE(buf) );

    // создадим массив текстовых строк
    ksDynamicArrayPtr pTextLine( (ksDynamicArray*)kompas->GetDynamicArray(TEXT_LINE_ARR), false/*AddRef*/ );
    //пройдемся по листам ТТ и получим текст
    for( int i = 0; i < count; i++ ) {
      doc->ksGetObjParam( pTT, pTextLine, i );
      ksTextLineParamPtr itemLineText( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
      if ( !(bool)itemLineText )
        return;
      itemLineText->Init();

      for( int i1 = 0, count1 = pTextLine->ksGetArrayCount(); i1 < count1; i1++ ) {
        pTextLine->ksGetArrayItem( i1, itemLineText );
        ::sprintf( buf, "компонента =%d style=%d   ", i1, itemLineText->style );
        kompas->ksMessage( TO_OLE(buf) );

        ksDynamicArrayPtr arrpTextItem( (ksDynamicArray*)itemLineText->GetTextItemArr(), false/*AddRef*/ );
        ksTextItemParamPtr item( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );

        if ( !(bool)item || !(bool)arrpTextItem )
          return;
        item->Init();

        for ( int j = 0, count2 = arrpTextItem->ksGetArrayCount(); j< count2; j++ ) {
          arrpTextItem->ksGetArrayItem( j, item );
          ksTextItemFontPtr textItemFont( (ksTextItemFont*)item->GetItemFont(), false/*AddRef*/ );
					::sprintf( buf, "компонента=%d h=%5.1f\ns=%s\n fontName=%s ", j, textItemFont->height,
										 WideToAnsi(item->s), WideToAnsi(textItemFont->fontName) );
          kompas->ksMessage( TO_OLE(buf) );
        }
        arrpTextItem->ksDeleteArray(); //очистим массив компонент
      }
    }
    pTextLine->ksDeleteArray(); //очистим массив текстовых строк
  }
}

//------------------------------------------------------------------------------
// вставка фрагмента
// ---
void ShowInsertFragment( ksDocument2DPtr & doc ) {
  char libName[250];
  long res;
  //выберем  библиотеку фрагментов
	::sprintf( libName, "%s", WideToAnsi(kompas->ksChoiceFile( TO_OLE(L"*.lfr"), TO_OLE(L"Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|"), 1 )) );
  if( libName ) {
    char buf[250];
    do {
      //выбрать фрагмент в библиотеке фрагментов
      ksFragmentPtr fr( (ksFragment*)doc->GetFragment(), false/*AddRef*/ );
      if  ( !fr )
        return;
      ksFragmentLibraryPtr frLib( (ksFragmentLibrary *)kompas->GetFragmentLibrary(), false/*AddRef*/ );
      if ( !frLib )
        return ;
			::sprintf( buf, "%s", WideToAnsi(frLib->ksChoiceFragmentFromLib( TO_OLE(libName), &res )) );
      if ( *buf && res ) {
        //выделим имя вставки
        char * insertName = ::strrchr( buf, '|' );
        if ( insertName ) {
          double x, y;
          //подготовим структуры фанома и запросов для Placement
          ksPhantomPtr rub( (ksPhantom*)kompas->GetParamStruct( ko_Phantom ), false/*AddRef*/ );
          ksType1Ptr type1( (ksType1*)rub->GetPhantomParam(), false/*AddRef*/ );
          if ( !(bool)rub || !(bool)type1 )
            return;

          type1->Init(); rub->Init();
          type1->scale_ = 1;
          rub->phantom  = 1;

          reference pDefFrg;
          // создадим описание  всавки фрагментов
          pDefFrg = fr->ksFragmentDefinition( TO_OLE(buf),                  // имя файла фрагмента
                                              TO_OLE(L"Вставка фрагмента"), // имя вставки
                                              1 );                          // тип вставки -действителен для внешнего фрагмента
                                                                            // 0- взять в документ, 1-внешней ссылкой

          if( pDefFrg ) {
           //во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
            type1->gr = doc->ksNewGroup(1);

              ksPlacementParamPtr par( (ksPlacementParam*)kompas->GetParamStruct( ko_PlacementParam ), false/*AddRef*/ );
              if ( !par )
                return;
              par->Init();
              par->scale_ = 1;
              reference  p = fr->ksInsertFragment( pDefFrg,              // Указатель определения  фрагмента
                            0,                    //тип размещения по слоям 0 - на свои слои 1- в текущий слой
                            par );               //параметры привязки

            doc->ksEndGroup();
            int j;
            do {
              type1->angle = 0;
              double ang   = 0;
              if ( (j = doc->ksPlacement( NULL, &x, &y, &ang, rub ))!=0 ) {
                doc->ksCopyObj( p,                 // указатель на графический объект
                                0,0,               // базовая точка объекта
                                x, y,              // точка куда копировать
                                1, type1->angle ); // масштаб и угол поворота а градусах
              }
            } while ( j );
            doc->ksDeleteObj( type1->gr );
          }
          else
            kompas->ksError( TO_OLE(L"Ошибка создания описания вставки фрагмента") );
        }
        else
          kompas->ksError( TO_OLE(L"Имя вставки не определено") );
      }
    } while( res );
  }
}

//------------------------------------------------------------------------------
// вставка фрагмента россыпью
// ---
void ShowInsertFragment1( ksDocument2DPtr & doc ) {
  char frwName[250];
  ksFragmentPtr fr( (ksFragment*)doc->GetFragment(), false/*AddRef*/ );
  if ( !fr )
    return;
  //выберем  фрагмент
	::sprintf( frwName, "%s", WideToAnsi(kompas->ksChoiceFile( TO_OLE(L"*.frw"), TO_OLE(L"фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|"), 1 )) );
  if( frwName ) {
		double x, y;
    //подготовим структуры фанома и запросов для Placement
    ksPhantomPtr rub( (ksPhantom*)kompas->GetParamStruct( ko_Phantom ), false/*AddRef*/ );
    ksType1Ptr type1( (ksType1*)rub->GetPhantomParam(), false/*AddRef*/ );
    if ( !(bool)rub || !(bool)type1 )
      return;
		type1->Init(); rub->Init();

    type1->scale_ = 1;
    rub->phantom  = 1;

    //во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
    ksPlacementParamPtr par( (ksPlacementParam*)kompas->GetParamStruct( ko_PlacementParam ), false/*AddRef*/ );
    if ( !par )
      return;
    par->Init();
    par->scale_ = 1;

    int j;
    do {
      //если нужно вставить несколько фрагментов, группу лучше порождать новую,
      //так как вместе с геометрией могут придти атрибуты, объекты спецификации, стили,
      //которые связаны с геометрией. При простом копировании группы эта связь будет
      //потеряна.
      type1->gr = fr->ksReadFragmentToGroup( TO_OLE(frwName),  // имя фрагмента
                                             0,          //тип размещения по слоям 0 - на свои слои 1- в текущий слой
                                             par );     //параметры привязки
      if ( type1->gr ) {
        double ang = type1->angle;
        if ((j = doc->ksPlacement( NULL, &x, &y, &ang, rub ))!=0 ) {
          //сдвигаем группу
          doc->ksMoveObj( type1->gr, x, y );
          //ставим группу в модель
          doc->ksStoreTmpGroup( type1->gr );
          doc->ksClearGroup( type1->gr, true );
          doc->ksDeleteObj( type1->gr );
        }
      }
      else {
        if ( type1->gr )
          doc->ksDeleteObj( type1->gr );
        j = 0;
      }
    } while ( j );
  }
}

//------------------------------------------------------------------------------
// работа с библиотекой фрагментов
// ---
void EditFragmentLibrary( ksDocument2DPtr & doc ) {
  char libName[250];
  char buf [250];
  //выберем  библиотеку фрагментов
	::sprintf( libName, "%s", WideToAnsi(kompas->ksChoiceFile( TO_OLE(L"*.lfr"), TO_OLE(L"Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|"), 1 )) );

  if( libName ) {
    ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct( ko_RequestInfo ), false/*AddRef*/ );
    ksFragmentPtr fr( (ksFragment*)doc->GetFragment(), false/*AddRef*/ );
    if ( !(bool)info || !(bool)fr )
			return;
    info->Init();

    info->commandsString = TO_OLE(L"!Новый_фрагмент !Редактировать_фрагмент !Удалить_фрагмент ");
    int j;
    int typeEdit;
//    CString /*string*/
    char * nameFrg;
    ksFragmentLibraryPtr frLib( (ksFragmentLibrary *) kompas->GetFragmentLibrary(), false/*AddRef*/ );
    if ( !frLib )
      return ;

    do {
      j = doc->ksCommandWindow( info );
      switch ( j ) {
        case 1:  //!Новый_фрагмент
					::sprintf( buf, "%s", WideToAnsi(kompas->ksReadString( TO_OLE(L"Введите имя нового фрагмента"), TO_OLE(L"") )) );
          if ( buf ) {
            nameFrg = libName;
            if ( buf[0] != '|' )
//              nameFrg += "|";
            ::strcat ( nameFrg , buf );
            typeEdit = 2; //запустить на редактирование
					}
          else
            typeEdit = 0;
          break;
        case 2 : //Редактировать_фрагмент
        case 3 : {//Удалить_фрагмент
          //выберем имя файла фрагмента
          long res;

					::sprintf( buf, "%s", WideToAnsi(frLib->ksChoiceFragmentFromLib( TO_OLE(libName), &res )) );
          if ( res && buf && (j == 2 || j == 3) ) {
            nameFrg = buf;
            typeEdit = j; // 2- запустить на редактирование, 3-удалить ;
          }
          else
            typeEdit = 0;
          break;
        }
      }

      if ( j > 0 && typeEdit ) {
        if ( frLib->ksFragmentLibraryOperation( TO_OLE(nameFrg), typeEdit ) ) {
          if ( typeEdit == 2 ) {
             frLib->ksFragmentLibraryOperation( TO_OLE(nameFrg), 4 /*минимизировать окно библиотекаря*/ );
            //редактируем фрагмент из библиотеки
            doc->ksText( 0, 100, // точка привязки текста
                  0,             // угол наклона текста
                  5,             // высота текста
                  1,             // сужение текста
                  0,             // свойства строки, которые задаются вкл.-выкл.
                  TO_OLE(L"Редактируем фрагмент из библиотеки") );   //строка символов

            doc->ksLineSeg ( 0, 100, 110, 100, 1 );
            //редактируем фрагмент в интерактивном режиме
            //после выбора в меню "Сервис" команды "Закончить редактирование фрагмента",
            //возвращаемся в библиотеку
            kompas->ksSystemControlStart( TO_OLE(L"Закончить редактирование фрагмента") );
            frLib->ksFragmentLibraryOperation( TO_OLE(nameFrg), 0 /*закрыть c сохранением*/ );
          }
        }
        else
          kompas->ksMessageBoxResult();
      }
    } while ( j != -1 );
  }
}

//------------------------------------------------------------------------------
// редактирование TT
// ---
void ChangeTechnicalDemand( ksDocument2DPtr & doc ) {
  long ref = doc->ksGetReferenceDocumentPart( 1 );
  ksTechnicalDemandParamPtr par( (ksTechnicalDemandParam*)kompas->GetParamStruct(ko_TechnicalDemandParam), false/*AddRef*/ );
  if ( doc->ksGetObjParam( ref, par, TECHNICAL_DEMAND_PAR ) ) {
    char buf[128];
    ::sprintf( buf, "число строк TT =%d", par->strCount );
    kompas->ksMessage( TO_OLE(buf) );

    doc->ksOpenTechnicalDemand( par->GetPGab(), par->style );

    ksTextLineParamPtr parLine( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
    if ( parLine ) {
      parLine->Init();
      for( int i = 0, count = par->strCount; i < count; i++ ) {
        doc->ksGetObjParam( ref, parLine, TT_FIRST_STR+i );
        ksTextItemParamPtr parItem( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
        ksDynamicArrayPtr arr( (ksDynamicArray*)parLine->GetTextItemArr(), false/*AddRef*/ );
        if ( (bool)parItem && (bool)arr ) {
          parItem->Init();
          for ( int j = 0, count1 = arr->ksGetArrayCount(); j < count1; j++ ) {
            arr->ksGetArrayItem( j, parItem );
						::sprintf( buf, "%s", WideToAnsi( parItem->s ) );
            ::strcat( buf, "!!!" );
            parItem->s = TO_OLE(buf);
            arr->ksSetArrayItem( j, parItem );
            kompas->ksMessage( parItem->s );
					}
        }
				doc->ksSetObjParam( ref, parLine, TT_FIRST_STR + i );
      }
    }
    doc->ksCloseTechnicalDemand();
  }
}

