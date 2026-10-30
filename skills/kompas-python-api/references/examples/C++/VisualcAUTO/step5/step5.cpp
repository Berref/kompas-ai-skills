// step5.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <math.h>
#include "step5.h"

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
// CStep5App

BEGIN_MESSAGE_MAP(CStep5App, CWinApp)
  //{{AFX_MSG_MAP(CStep5App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep5App construction

CStep5App::CStep5App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep5App object

CStep5App theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDS_LIBEDIT;
}

void DrawTransform( ksDocument2DPtr& doc );
void DrawCopy( ksDocument2DPtr& doc );
void DrawSymmetry( ksDocument2DPtr& doc );
void EditTolerance( ksDocument2DPtr& doc );
void EditTable( ksDocument2DPtr& doc );
void EditStamp( ksDocument2DPtr& doc );
void GetTextTT( ksDocument2DPtr& doc );
void ShowInsertFragment( ksDocument2DPtr& doc );
void ShowInsertFragment1( ksDocument2DPtr& doc );
void EditFragmentLibrary( ksDocument2DPtr& doc );
void ChangeTechnicalDemand( ksDocument2DPtr& doc );

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
    if ( doc && doc->reference ) {
      switch ( comm ) {
      case 1  : ::DrawTransform( doc );         break; //трансформация объекта по матрице
      case 2  : ::DrawCopy( doc );              break; //копирование объекта
      case 3  : ::DrawSymmetry( doc );          break; //симметрия объекта
      case 4  : ::EditTolerance( doc );         break; //просмотр допуска формы
      case 6  : ::EditTable( doc );             break; //просмотр таблицы
      case 8  : ::EditStamp( doc );             break; //взять тексты граф и редактировать штамп
      case 9  : ::GetTextTT( doc );             break; //получить текст ТТ
      case 10 : ::ChangeTechnicalDemand( doc ); break; //редактирование TT
      case 11 : ::ShowInsertFragment( doc );    break; //вставка фрагмента
      case 12 : ::EditFragmentLibrary( doc );   break; //работа с библиотекой фрагментов
      case 13 : ::ShowInsertFragment1( doc );   break; //вставка фрагмента россыпью
      }
    }
    else
      kompas->ksError( _T("Документ не активизирован или \nне является листом/фрагментом") );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawTransform( ksDocument2DPtr& doc ) {
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
  
  kompas->ksMessage(_T("создали матрицу 20, 20, 45, 2") );

  doc->ksMtr(20, 20, 45, 2, 2 );
  doc->ksTransformObj( ref );
  doc->ksDeleteMtr();

  kompas->ksMessageBoxResult();
  kompas->ksMessage(_T("вернем обратно"));

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

//-------------------------------------------------------------------------------
//
// ---
void DrawCopy( ksDocument2DPtr& doc ) {
  ksViewParamPtr par( kompas->GetParamStruct( ko_ViewParam ) );

  if ( par ) {
    par->Init();
    par->x = 20;
    par->y = 60;
    par->scale_ = 1;
    par->color  = RGB(10,20,10);
    par->state  = stACTIVE;
    par->name   = _T("user view");

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
    doc->ksCopyObj( v, 20, 60, 40, 80, 1, 0  );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawSymmetry( ksDocument2DPtr& doc ) {
  reference grp = doc->ksNewGroup( 0 );
    doc->ksLineSeg( 20, 10, 20, 30, 1 );
    doc->ksLineSeg( 20, 30, 40, 30, 1 );
    doc->ksLineSeg( 40, 30, 40, 10, 1 );
    doc->ksLineSeg( 40, 10, 20, 10, 1 );
  doc->ksEndGroup();

  doc->ksSymmetryObj(grp, 40, 10, 40, 20, _T("1")  );
}

//-------------------------------------------------------------------------------
//
// ---
void EditTolerance( ksDocument2DPtr& doc ) {
  // редактирование допуска формы
  reference pObj;

   ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( !info ) 
    return;
  double x, y;
  info->prompt = _T("Укажите допуск формы");
  int j = doc->ksCursor( info, &x ,&y, 0 );
  if ( j ) {
    if( doc->ksExistObj( pObj = doc->ksFindObj( x, y, 1000000. )) ){
      //узнаем тип объекта
      int type = doc->ksGetObjParam( pObj,0,0);   //указатель на графический объект
      if ( type == TOLERANCE_OBJ ) {
        long numb;
        TCHAR buf[128];
        //открыть допуск формы для редактирования
        doc->ksOpenTolerance( pObj );

        ksToleranceParamPtr par( kompas->GetParamStruct(ko_ToleranceParam) );
        //параметры допуска формы
        doc->ksGetObjParam(  pObj,   //указатель на графический объект
                    par,  //указатель на структуру параметров
                    ALLPARAM ); //тип считывания параметров

        ::_stprintf_s( buf, _T("базовая точка=%d стиль=%d расположение-%s\nx=%5.1f y=%5.1f  "),
                         par->tBase, par->style, par->type ? _T("вертикальное"):_T("горизонтальное"), par->x, par->y );
        kompas->ksMessage(buf);

        ksTextLineParamPtr par1( kompas->GetParamStruct(ko_TextLineParam) );

        if ( !par1 )
          return;
        
        par1->Init();
        
        //в цикле будем брать все существующие ячейки
        while ( doc->ksGetToleranceColumnText( &numb, par1 )!=0 ) {
          ::_stprintf_s( buf, _T("numb =%d\nstyle=%d"), numb, par1->style );
          kompas->ksMessage(buf);

          ksDynamicArrayPtr arrpTextItem( par1->GetTextItemArr() );
          ksTextItemParamPtr item( kompas->GetParamStruct(ko_TextItemParam) );

          if ( !item || !arrpTextItem )
            return;
          
          item->Init();

          for ( int j = 0, count = arrpTextItem->ksGetArrayCount(); j < count; j++ ) 
          {
            arrpTextItem->ksGetArrayItem( j, item );
            ksTextItemFontPtr  textItemFont( item->GetItemFont() );
            if ( !item->type )
              ::_stprintf_s( buf, _T("компонента=%d h=%5.1f\ns=%s\n fontName=%s\nбитвектор =%d "), j, textItemFont->height, 
                                       (LPCTSTR)item->s, (LPCTSTR)textItemFont->fontName, textItemFont->bitVector );
            else
              ::_stprintf_s( buf, _T("компонента=%d тип = %d номер спецзнака=%d"), j, item->type, item->iSNumb );
            item->s = _T("Допуск формы");
            kompas->ksMessage(buf);
          }
          arrpTextItem->ksClearArray();
          arrpTextItem->ksAddArrayItem( -1, item );
          doc->ksSetToleranceColumnText( numb, par1 );
          arrpTextItem->ksDeleteArray();  //очистим массив компонент
        }
        //заменим параметры
        par->x += 10;
        par->y += par->y + 10;
        doc->ksSetObjParam( pObj,       // указатель на графический объект
                            par,        // указатель на структуру параметров
                            ALLPARAM ); // тип считывания параметров
        doc->ksEndObj(); // закрыли объект "допуск формы"
      }
      else
        kompas->ksError( _T("это не допуск формы") );
    }
    else
      kompas->ksError( _T("нет объекта") );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void EditTable( ksDocument2DPtr& doc ) {
  // редактирование таблицы
  reference pObj;

   ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( !info ) 
    return;
  double x, y;
  info->prompt = _T("Укажите таблицу");
  // взять таблицу на чертеже
  int j = doc->ksCursor( info, &x ,&y, 0 );
  if ( j ) {
    if( doc->ksExistObj( pObj = doc->ksFindObj( x, y, 100000 )) )
    {
      //узнаем тип объекта
      int type = doc->ksGetObjParam( pObj, 0, 0 );   //указатель на графический объект
      //проверить полученный объкет  - таблица
      if ( type == TABLE_OBJ ) {
        long numb;
        //reference p;
        TCHAR buf[128];
        //открыть таблицу для редактирования
        doc->ksOpenTable( pObj );

        ksTextParamPtr par( kompas->GetParamStruct(ko_TextParam) );
        if ( !par )
          return;
        par->Init();
        //в цикле будем брать все существующие ячейки
        while (( doc->ksGetTableColumnText( &numb, par ))!=0) 
        {
          ::_stprintf_s( buf, _T("numb = %d"), numb );
          kompas->ksMessage(buf);


          ksDynamicArrayPtr arrpLineText( par->GetTextLineArr() );
          ksTextLineParamPtr itemLineText( kompas->GetParamStruct(ko_TextLineParam) );
          if ( !itemLineText )
            return;
          itemLineText->Init();

          for(int i = 0, count = arrpLineText->ksGetArrayCount(); i < count; i++ ) {
            arrpLineText->ksGetArrayItem( i, itemLineText );
            ::_stprintf_s( buf, _T("i = %d style = %d"), i, itemLineText->style );
            kompas->ksMessage(buf);

            ksDynamicArrayPtr arrpTextItem( itemLineText->GetTextItemArr() );
            ksTextItemParamPtr item( kompas->GetParamStruct(ko_TextItemParam) );
            if ( !item || !arrpTextItem )
              return;
            item->Init();
          
            for ( int j=0, count2 = arrpTextItem->ksGetArrayCount(); j < count2; j++) {
              arrpTextItem->ksGetArrayItem( j, item );
              ksTextItemFontPtr textItemFont( item->GetItemFont() );

              if ( !item->type )
                ::_stprintf_s( buf, _T("компонента=%d h=%5.1f\ns=%s\n fontName=%s\nбитвектор =%d"),j, textItemFont->height, 
                               (LPCTSTR)item->s, (LPCTSTR)textItemFont->fontName, textItemFont->bitVector );
              else
                ::_stprintf_s( buf, _T("компонента=%d тип = %d номер спецзнака=%d"),j, item->type, item->iSNumb );
              kompas->ksMessage(buf);
            }
            arrpTextItem->ksDeleteArray();  //очистим массив компонент
          }
          //очистим массив текстовых строк
          arrpLineText->ksDeleteArray();
        } // while ((ksGetTableColumnText( &numb, &par ))!=0) {

        //берем ячейку 2
        doc->ksColumnNumber( 2 );
        doc->ksText( 0, 0, 0, 5, 1 ,0, _T("вторая ячейка") );

        doc->ksDivideTableItem( 3, 1, 2 );
        doc->ksColumnNumber( 4 );
        doc->ksText( 0, 0, 0, 5, 1 ,0, _T("4") );

        doc->ksEndObj();//закрыли объект "таблица"
      }
      else
        kompas->ksError( _T("это не таблица") );
    }
    else
      kompas->ksError( _T("нет объекта") );
  }
}


//-------------------------------------------------------------------------------
//
// ---
void EditStamp( ksDocument2DPtr& doc ) {

  ksStampPtr stamp( doc->GetStamp() );
  
  if ( stamp && stamp->ksOpenStamp() ) {

      stamp->ksColumnNumber(1);

      ksTextLineParamPtr TLP(kompas->GetParamStruct(ko_TextLineParam));
      TLP->Init();
 

      ksDynamicArrayPtr TIArr(TLP->GetTextItemArr());

      ksTextItemParamPtr TItem(kompas->GetParamStruct(ko_TextItemParam));
      TItem->Init();
 

      ksTextItemFontPtr fnt(TItem->GetItemFont());
      fnt->Init();
      fnt->bitVector = NEW_LINE;


// Первая строка

      TItem->type = 0;
      TItem->s = _T("Строка1");
      TIArr->ksAddArrayItem(-1, TItem);
      stamp->ksTextLine(TLP);
      TIArr->ksClearArray();
 

// Вторая строка

      TItem->s = _T("Строка2");
      TIArr->ksAddArrayItem(-1, TItem);
      stamp->ksTextLine(TLP);
      stamp->ksCloseStamp();
  }
}


//-------------------------------------------------------------------------------
//
// ---
  void EditStamp1( ksDocument2DPtr& doc ) {
    ksStampPtr stamp( doc->GetStamp() );
    if ( stamp && stamp->ksOpenStamp() ) {
      long numb;
      //в цикле будем брать все существующие графы
      ksDynamicArrayPtr arr( stamp->ksGetStampColumnText( &numb ) );
      while ( numb && arr ) {
        TCHAR buf[128];
        ::_stprintf_s( buf, _T("numb =%d"), numb );
        kompas->ksMessage(buf);
  
         ksDynamicArrayPtr arrpLineText( kompas->GetDynamicArray(TEXT_LINE_ARR) );
        ksTextLineParamPtr itemLineText( kompas->GetParamStruct(ko_TextLineParam) );
        if ( !itemLineText )
           return;
        itemLineText->Init();
  
        for(int i = 0, count = arr->ksGetArrayCount(); i < count; i++ ) {
          arr->ksGetArrayItem( i, itemLineText );
          ::_stprintf_s( buf, _T("i =%d style=%d"), i, itemLineText->style );
          kompas->ksMessage(buf);
  
          ksDynamicArrayPtr arrpTextItem( itemLineText->GetTextItemArr() );
          ksTextItemParamPtr item( kompas->GetParamStruct(ko_TextItemParam) );
  
          if ( !item || !arrpTextItem )
            return;
          item->Init();
            
          for ( int j = 0, count2 = arrpTextItem->ksGetArrayCount(); j < count2; j++) 
          {
            arrpTextItem->ksGetArrayItem( j, item );
            ksTextItemFontPtr textItemFont( item->GetItemFont() );
            ::_stprintf_s( buf, _T("компонента=%d h=%5.1f\ns=%s\nfontName=%s "),j, textItemFont->height, (LPCTSTR)item->s,
                                                                                   (LPCTSTR)textItemFont->fontName );
            kompas->ksMessage(buf);
          }
          arrpTextItem->ksDeleteArray();  //очистим массив компонент
        }
        //очистим массив текстовых строк
        arrpLineText->ksDeleteArray();
  
        arr->ksDeleteArray();
        arr = stamp->ksGetStampColumnText( &numb );
      }
      //заменим  графу 2
      doc->ksColumnNumber( 2 );
      ksTextItemParamPtr item( kompas->GetParamStruct(ko_TextItemParam) );
      if ( !item ) {
        stamp->ksCloseStamp();
        return;
      }
      item->Init();
      ksTextItemFontPtr itemFont( item->GetItemFont() );
      if ( item && itemFont ) {
         itemFont->SetBitVectorValue( NEW_LINE, true );
        item->s = _T("графа 2");
        doc->ksTextLine( item );
      }
      stamp->ksCloseStamp();
    }
    else
      kompas->ksError ( _T("Штамп не найден") );
  }
 
//-------------------------------------------------------------------------------
//
// ---
void GetTextTT( ksDocument2DPtr& doc ) {
  //получим указатель на технические трбования
  reference pTT = doc->ksGetReferenceDocumentPart( 1 );
  ksTechnicalDemandParamPtr technicalDemandParam( kompas->GetParamStruct(ko_TechnicalDemandParam) );
  if ( pTT && technicalDemandParam ) {
    technicalDemandParam->Init();
    //получим параметры описания ТТ
    doc->ksGetObjParam( pTT, technicalDemandParam, TECHNICAL_DEMAND_PAR );
    TCHAR buf[128];
    ksDynamicArrayPtr pGab( technicalDemandParam->GetPGab() );
    int count = pGab->ksGetArrayCount();
    ::_stprintf_s( buf, _T("стиль =%d число страниц  TT =%d"), technicalDemandParam->style, count );
    kompas->ksMessage(buf);

    // создадим массив текстовых строк
    ksDynamicArrayPtr pTextLine( kompas->GetDynamicArray(TEXT_LINE_ARR) );
    //пройдемся по листам ТТ и получим текст
    for( int i = 0; i < count; i++ ) {
      doc->ksGetObjParam( pTT, pTextLine, i );
      ksTextLineParamPtr itemLineText( kompas->GetParamStruct(ko_TextLineParam) );
      if ( !itemLineText )
        return;
      itemLineText->Init();

      //      TextLineParam par2;
      for( int i1 = 0, count1 = pTextLine->ksGetArrayCount(); i1 < count1; i1++ ) {
        pTextLine->ksGetArrayItem( i1, itemLineText );
        ::_stprintf_s( buf, _T("компонента = %d style = %d"), i1, itemLineText->style );
        kompas->ksMessage(buf);

        ksDynamicArrayPtr arrpTextItem( itemLineText->GetTextItemArr() );
        ksTextItemParamPtr item( kompas->GetParamStruct(ko_TextItemParam) );

        if ( !item || !arrpTextItem )
          return;
        item->Init();

        for ( int j = 0, count2 = arrpTextItem->ksGetArrayCount(); j < count2; j++ ) 
        {
          arrpTextItem->ksGetArrayItem( j, item );
          ksTextItemFontPtr textItemFont( item->GetItemFont() );
          ::_stprintf_s( buf, _T("компонента=%d h=%5.1f\ns=%s\n fontName=%s"), j, textItemFont->height,
                         (LPCTSTR)item->s, (LPCTSTR)textItemFont->fontName );
          kompas->ksMessage(buf);
        }
        arrpTextItem->ksDeleteArray(); //очистим массив компонент
      }
    }
    pTextLine->ksDeleteArray(); //очистим массив текстовых строк
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShowInsertFragment( ksDocument2DPtr& doc ) {
  TCHAR libName[250];
  libName[0] = _T('\0');
  long res;
  //выберем  библиотеку фрагментов
  ::_tcscpy_s( libName, kompas->ksChoiceFile( _T("*.lfr"), _T("Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|"), 1 ) );
  if ( ::_tcsclen(libName) ) { 
    TCHAR buf[250]; 
    do {
      //выбрать фрагмент в библиотеке фрагментов
      ksFragmentPtr fr( doc->GetFragment() );
// ABB K6    ksFragmentLibrary
      ksFragmentLibraryPtr frLib( kompas->GetFragmentLibrary() ); 
      if  ( !fr && !frLib )
        return;
      ::_tcscpy_s( buf, frLib->ksChoiceFragmentFromLib( libName, &res ) );
      if ( buf && res == 3 ) { // res = 3 - выбран фрагмент
        // выделим имя вставки 
        TCHAR * insertName = ::_tcsrchr( buf, _T('|') );
        if ( insertName ) {
          double x, y;
          //подготовим структуры фанома и запросов для Placement
          ksPhantomPtr rub( kompas->GetParamStruct( ko_Phantom ) );
          rub->phantom = 1;
          ksType1Ptr type1( rub->GetPhantomParam() );
          if ( !rub || !type1 )
            return;

          type1->Init(); rub->Init(); 

          type1->scale_ = 1;
          rub->phantom = 1;

          reference pDefFrg;
          // создадим описание  всавки фрагментов
          pDefFrg = fr->ksFragmentDefinition( buf,          // имя файла фрагмента
                                              insertName+1, // имя вставки
                                              1 );          // тип вставки -действителен для внешнего фрагмента
                                                            // 0- взять в документ, 1-внешней ссылкой

          if( pDefFrg ) 
          {
            //во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов 
            type1->gr = doc->ksNewGroup(1);
   
            ksPlacementParamPtr par( kompas->GetParamStruct( ko_PlacementParam ) );
            if ( !par )
              return; 
            par->Init();
            par->scale_ = 1;
            reference  p = fr->ksInsertFragment( pDefFrg,              // Указатель определения  фрагмента
                                                 0,                    //тип размещения по слоям 0 - на свои слои 1- в текущий слой
                                                 par );                //параметры привязки

            doc->ksEndGroup();
            int j;
            do {
              type1->angle = 0;
              double ang = type1->angle;
                 if ( (j = doc->ksPlacement( NULL, &x, &y, &ang, rub ))!=0 ) {
                type1->angle = ang;
                doc->ksCopyObj( p,                  // указатель на графический объект
                          0,0,     // базовая точка объекта
                          x, y,     // точка куда копировать
                          1, type1->angle );// масштаб и угол поворота а градусах
              }
            } while ( j ); 
            doc->ksDeleteObj( type1->gr );
          }
          else
            kompas->ksError( _T("Ошибка создания описания вставки фрагмента") );
        }
        else
          kompas->ksError( _T("Имя вставки не определено") );
      }
    } while( res );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShowInsertFragment1( ksDocument2DPtr& doc ) {
  TCHAR frwName[250];
  ksFragmentPtr fr( doc->GetFragment() );
  if ( !fr )
    return;
  //выберем  фрагмент
  ::_tcscpy_s( frwName, kompas->ksChoiceFile( _T("*.frw"),_T("фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|"), 1 ) );
  if( frwName ) { 
    double x, y;
    //подготовим структуры фанома и запросов для Placement
    ksPhantomPtr rub( kompas->GetParamStruct( ko_Phantom ) );
    rub->phantom = 1;
    ksType1Ptr type1( rub->GetPhantomParam() );
    if ( !rub || !type1 )
      return;
    type1->Init(); rub->Init(); 

    type1->scale_ = 1;
    rub->phantom  = 1;

    //во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
    ksPlacementParamPtr par( kompas->GetParamStruct( ko_PlacementParam ) );
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
      type1->gr = fr->ksReadFragmentToGroup( frwName,        // имя фрагмента
                                             0,          //тип размещения по слоям 0 - на свои слои 1- в текущий слой
                                             par );     //параметры привязки
      if ( type1->gr ) {
        double ang = type1->angle;
        if ( (j = doc->ksPlacement( NULL, &x, &y, &ang, rub ))!=0 ) {
          //сдвигаем группу
          doc->ksMoveObj( type1->gr, x, y );
          //поворачиваем группу
          if( ::fabs(ang) > 0.001 )
             doc->ksRotateObj( type1->gr, x, y, ang );
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

//-------------------------------------------------------------------------------
//
// ---
void EditFragmentLibrary( ksDocument2DPtr& doc ) {
  TCHAR libName[250];
  TCHAR buf [250];
  //выберем  библиотеку фрагментов
  ::_tcscpy_s( libName, kompas->ksChoiceFile( _T("*.lfr"), _T("Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|"), 1 ) );
  if( libName ) { 
    ksRequestInfoPtr info( kompas->GetParamStruct( ko_RequestInfo ) );
    ksFragmentPtr fr( doc->GetFragment() );

    ksFragmentLibraryPtr  frLib( kompas->GetFragmentLibrary() ); 
    if  ( !info || !fr || !frLib)
      return;
    info->Init();

    info->commandsString = _T("!Новый_фрагмент !Редактировать_фрагмент !Удалить_фрагмент");
    int j;
    int typeEdit;
    CString nameFrg;
    do {
      j = doc->ksCommandWindow( info );
      switch ( j ) {
        case 1:  //!Новый_фрагмент
          ::_tcscpy_s( buf, kompas->ksReadString( _T("Введите имя нового фрагмента"), _T("") ) );
          if ( buf ) {
            nameFrg = libName;
            if ( buf[0] != '|' )
              nameFrg += "|";
            nameFrg += buf;
            typeEdit = 2; //запустить на редактирование
          }
          else
            typeEdit = 0;
          break;
        case 2 : //Редактировать_фрагмент
        case 3 : //Удалить_фрагмент
          //выберем имя файла фрагмента
          long res;
          ::_tcscpy_s( buf, frLib->ksChoiceFragmentFromLib( libName, &res ) );
          if ( res && buf && (j == 2 || j == 3) ) {
            nameFrg = buf;
            typeEdit = j; // 2- запустить на редактирование, 3-удалить ;
          }
          else
            typeEdit = 0;
          break;
      }

      if ( j > 0 && typeEdit ) {
        if ( frLib->ksFragmentLibraryOperation( (LPCTSTR)nameFrg, typeEdit ) ) {
          if ( typeEdit == 2 ) {
             frLib->ksFragmentLibraryOperation( (LPCTSTR)nameFrg, 4 /*минимизировать окно библиотекаря*/ );
            
            ksDocument2DPtr frw( kompas->ActiveDocument2D() );
            //редактируем фрагмент из библиотеки
            frw->ksText( 0, 100,     //точка привязки текста
                  0,            //угол наклона текста
                  5,            //высота текста
                  1,            //сужение текста
                  0,            //свойства строки, которые задаются вкл.-выкл.
                  _T("Редактируем фрагмент из библиотеки")  );   //строка символов

            frw->ksLineSeg ( 0, 100, 110, 100, 1 );
            //редактируем фрагмент в интерактивном режиме 
            //после выбора в меню "Сервис" команды "Закончить редактирование фрагмента", 
            //возвращаемся в библиотеку
            kompas->ksSystemControlStart( _T("Закончить редактирование фрагмента") );
            frLib->ksFragmentLibraryOperation( (LPCTSTR)nameFrg, 0 /*закрыть c сохранением*/ );
          }
        }  
        else
          kompas->ksMessageBoxResult();
      }

    } while ( j != -1 );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ChangeTechnicalDemand( ksDocument2DPtr& doc ) {
  long ref = doc->ksGetReferenceDocumentPart( 1 );
  ksTechnicalDemandParamPtr par( kompas->GetParamStruct(ko_TechnicalDemandParam) );
  if ( doc->ksGetObjParam( ref, par, TECHNICAL_DEMAND_PAR ) ) {
    TCHAR buf[128];
    ::_stprintf_s( buf, _T("число строк TT =%d"), par->strCount);
    kompas->ksMessage(buf);
  
    doc->ksOpenTechnicalDemand( par->GetPGab(), par->style );

    ksTextLineParamPtr parLine( kompas->GetParamStruct(ko_TextLineParam) );
    if ( parLine ) {
      parLine->Init();
      for( int i = 0, c = par->strCount; i < c; i++ ) {
        doc->ksGetObjParam( ref, parLine, TT_FIRST_STR+i );
        ksTextItemParamPtr parItem( kompas->GetParamStruct(ko_TextItemParam) );
        ksDynamicArrayPtr arr( parLine->GetTextItemArr() );
        if ( parItem && arr ) {
          parItem->Init();
          for ( int j = 0, count1 = arr->ksGetArrayCount(); j < count1; j++ ) {
            arr->ksGetArrayItem( j, parItem );
            ::_tcscpy_s( buf, parItem->s );
            ::_tcscat_s( buf, _T("!!!") );
            parItem->s = buf;  
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

