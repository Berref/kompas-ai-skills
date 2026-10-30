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


void WorkContour     ( ksDocument2DPtr & doc );
void TDemWork        ( ksDocument2DPtr & doc );
void TableWork       ( ksDocument2DPtr & doc );
void DrawViewPointer ( ksDocument2DPtr & doc );
void WorkStamp       ( ksDocument2DPtr & doc );
void WorkTolerance   ( ksDocument2DPtr & doc );
void DrawEquidistant ( ksDocument2DPtr & doc );
void DrawEllipse     ( ksDocument2DPtr & doc );
void DrawPolyline    ( ksDocument2DPtr & doc );
void DrawNurbs       ( ksDocument2DPtr & doc );
void DrawInsFragment1( ksDocument2DPtr & doc );
void DrawInsFragment2( ksDocument2DPtr & doc );
void DrawSpecRough   ( ksDocument2DPtr & doc );

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
    ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
    switch ( comm ) {
      case 1: //контур
        WorkContour( doc );
        break;
      case 2: //технические требования
        TDemWork( doc );
        break;
      case 3: //стрелка вида
        DrawViewPointer( doc );
        break;
      case 4: //работа со штампом
        WorkStamp( doc );
        break;
      case 5: //таблица
        TableWork( doc );
        break;
      case 6: //эквидистанта
        DrawEquidistant( doc );
        break;
      case 7: //эллипс
        DrawEllipse( doc );
        break;
      case 8: //полилиния
        DrawPolyline( doc );
        break;
      case 9: //nurbs
        DrawNurbs( doc );
        break;
      case 10: //допуск формы
        WorkTolerance( doc );
        break;
      case 11: //одинаковая шероховатость
        DrawSpecRough( doc );
        break;
      case 12: //вставка фрагмента внешней ссылкой
        DrawInsFragment1( doc );
        break;
      case 13: //вставка локального фрагмента
        DrawInsFragment2( doc  );
        break;
    }
    kompas->Release();
  }
}

//------------------------------------------------------------------------------
// Построить контур
// ---
void WorkContour( ksDocument2DPtr & doc ) {
  if( (bool)doc && doc->ksContour( 1 ) ) {
    doc->ksLineSeg( 20, 30, 50, 30, 1 );
    doc->ksArcByPoint( 50, 20, 10, 50, 30, 50, 10, -1, 1 );
    // вложенный контур
    doc->ksContour( 2 );
      doc->ksLineSeg( 50, 10, 20, 10, 1 );
      doc->ksArcByPoint( 20, 20, 10, 20, 10, 20, 30, -1, 1 );
    doc->ksEndObj();

    reference _contour = doc->ksEndObj();

    doc->ksLightObj( _contour, 1 );
    kompas->ksMessage( TO_OLE(L"контур") );
    doc->ksLightObj( _contour, 1 );
    reference g = doc->ksNewGroup( 0 );
    doc->ksEndGroup();
    doc->ksAddObjGroup( g, _contour );
    doc->ksMoveObj( g, 10, 10 );
    kompas->ksMessage( TO_OLE(L"сдвинули группу") );
  }
}

//------------------------------------------------------------------------------
// заполнение технических требований
// ---
void TDemWork( ksDocument2DPtr & doc ) {
  if ( doc ) {
    ksDynamicArrayPtr pGab( (ksDynamicArray*)kompas->GetDynamicArray( RECT_ARR ), false/*AddRef*/ );
    // поместим тех требования в двух габаритных окнах
    ksRectParamPtr par( (ksRectParam*)kompas->GetParamStruct( ko_RectParam ), false/*AddRef*/ );
    ksMathPointParamPtr mathPar( (ksMathPointParam*)kompas->GetParamStruct( ko_MathPointParam ), false/*AddRef*/ );
    if ( (bool)par && (bool)mathPar && (bool)pGab )
      mathPar->x = 230;
      mathPar->y = 65;
      par->SetpBot( mathPar );

      mathPar->x = 415;
      mathPar->y = 80;
      par->SetpTop( mathPar );

      pGab->ksAddArrayItem( -1, par );

      mathPar->x = 45;
      mathPar->y = 15;
      par->SetpBot( mathPar );

      mathPar->x = 230;
      mathPar->y = 60;
      par->SetpTop( mathPar );

      pGab->ksAddArrayItem( -1, par );

    reference p;
    if ( doc->ksOpenTechnicalDemand(pGab, 0) ) {
      ksTextItemParamPtr item( (ksTextItemParam*)kompas->GetParamStruct( ko_TextItemParam ), false/*AddRef*/ );
      if ( item ) {
        item->Init();
        ksTextItemFontPtr font( (ksTextItemFont*)item->GetItemFont(), false/*AddRef*/ );
        font->SetBitVectorValue( NEW_LINE, true );
        item->s = TO_OLE(L"1111111");
        doc->ksTextLine( item );

        item->s = TO_OLE(L"2222222");
        doc->ksTextLine( item );

        item->s = TO_OLE(L"3333333");
        doc->ksTextLine( item );

        item->s = TO_OLE(L"4444444");
        doc->ksTextLine( item );

        item->s = TO_OLE(L"5555555");
        doc->ksTextLine( item );

        item->s = TO_OLE(L"6666666");
        doc->ksTextLine( item );
      }

      p = doc->ksCloseTechnicalDemand();
    }

    kompas->ksMessage( TO_OLE(L"Удалим ТТ") );
    doc->ksDeleteObj( p );
  }
}

//------------------------------------------------------------------------------
// Создание таблицы
// ---
void TableWork( ksDocument2DPtr & doc ) {
  if ( doc ) {
    doc->ksTable();
      doc->ksLineSeg( 50, 50, 90, 50, 1 );
      doc->ksLineSeg( 50, 40, 90, 40, 1 );
      doc->ksLineSeg( 50, 30, 90, 30, 1 );
      doc->ksLineSeg( 50, 50, 50, 30, 1 );
      doc->ksLineSeg( 70, 50, 70, 30, 1 );
      doc->ksLineSeg( 90, 50, 90, 30, 1 );
      doc->ksText( 52, 48, 0, 5, 1, 0, TO_OLE(L"1") );
      doc->ksText( 72, 48, 0, 5, 1, 0, TO_OLE(L"2") );
      doc->ksText( 52, 38, 0, 5, 1, 0, TO_OLE(L"3") );
      doc->ksText( 72, 38, 0, 5, 1, 0, TO_OLE(L"4") );
    doc->ksEndObj();
  }
}

//------------------------------------------------------------------------------
// Создание стрелки вида
// ---
void DrawViewPointer( ksDocument2DPtr & doc ) {
  if ( doc ) {
    ksViewPointerParamPtr par( (ksViewPointerParam*)kompas->GetParamStruct( ko_ViewPointerParam ), false/*AddRef*/ );
    if ( par ) {
      par->x1 = 55;
      par->y1 = 50; // координаты вершины( острия) стрелки
      par->x2 = 40;
      par->y2 = 50; // координаты конечной точки стрелки
      par->xt = 40;
      par->yt = 52; // координаты текста
      par->type = 0; // тип задания текста - строка

      par->str = TO_OLE(L"B");    // надпись

      reference  p = doc->ksViewPointer( par ); //параметры "стрелки вида"
      if ( doc->ksExistObj(p) )
        doc->ksLightObj( p, 1 );
    }
  }
}


//------------------------------------------------------------------------------
// заполнение основной надписи
// ---
void WorkStamp( ksDocument2DPtr & doc ) {
  ksStampPtr stamp( (ksStamp*)doc->GetStamp(), false/*AddRef*/ );
  if ( stamp ) {
    if ( stamp->ksOpenStamp() ) {
      stamp->ksColumnNumber( 2 );

      ksTextItemParamPtr itemParam( (ksTextItemParam*)kompas->GetParamStruct( ko_TextItemParam ), false/*AddRef*/ );
      if ( itemParam ) {
        itemParam->Init();

        ksTextItemFontPtr itemFont( (ksTextItemFont*)itemParam->GetItemFont(), false/*AddRef*/ );
        if ( itemFont ) {
          itemFont->SetBitVectorValue( NEW_LINE, true );
          itemParam->s = TO_OLE(L"1111111");
          doc->ksTextLine( itemParam );
        }
      }

      stamp->ksCloseStamp();
    }
  }
}

//------------------------------------------------------------------------------
// Допуск формы
// ---
void WorkTolerance( ksDocument2DPtr & doc ) {
  ksToleranceParamPtr par( (ksToleranceParam*)kompas->GetParamStruct( ko_ToleranceParam ), false/*AddRef*/ );
  ksMathPointParamPtr parPoint( (ksMathPointParam*)kompas->GetParamStruct( ko_MathPointParam ), false/*AddRef*/ );

  if ( (bool)par && (bool)parPoint ) {

    par->Init();
    parPoint->Init();

    ksToleranceBranchPtr tolBran( (ksToleranceBranch*)kompas->GetParamStruct( ko_ToleranceBranch ), false/*AddRef*/ );
    if ( tolBran ) {
      tolBran->Init();
      ksDynamicArrayPtr arr( (ksDynamicArray*)tolBran->GetpMathPoint(), false/*AddRef*/ );
      ksDynamicArrayPtr branArr( (ksDynamicArray*)par->GetBranchArr(), false/*AddRef*/ );
      if ( (bool)arr && (bool)branArr ) {

        // заполняем параметры 1-ой ноги
        parPoint->x = 40;
        parPoint->y = 10;
        arr->ksAddArrayItem( -1, parPoint );
        tolBran->arrowType = 2;
        tolBran->tCorner   = 1;
        branArr->ksAddArrayItem( -1, tolBran );

        // заполняем параметры 2-ой ноги
        arr->ksClearArray();
        parPoint->x = 100;
        parPoint->y = 50;
        arr->ksAddArrayItem( -1, parPoint );
        parPoint->x = 100;
        parPoint->y = 10;
        arr->ksAddArrayItem( -1, parPoint );
        tolBran->arrowType = 1;
        tolBran->tCorner   = 5;
        branArr->ksAddArrayItem( -1, tolBran );

        par->x = 40;
        par->y = 40;
        par->type = 0;

        // допуск формы составной объект
        if ( doc->ksTolerance(par) ) {
          ksTextItemParamPtr itemParam( (ksTextItemParam*)kompas->GetParamStruct( ko_TextItemParam ), false/*AddRef*/ );
          if ( itemParam ) {
            itemParam->Init();

            ksTextItemFontPtr itemFont( (ksTextItemFont*)itemParam->GetItemFont(), false/*AddRef*/ );
            if ( itemFont ) {
              doc->ksColumnNumber( 1 );
              itemFont->SetBitVectorValue( SPECIAL_SYMBOL, true );
              itemParam->type   = SPECIAL;
              itemParam->iSNumb = 26;
              doc->ksTextLine( itemParam );

              itemParam->Init();
              doc->ksColumnNumber( 2 );
              itemFont->SetBitVectorValue( NEW_LINE, true );
              itemParam->s = TO_OLE(L"111");
              doc->ksTextLine( itemParam );

              doc->ksColumnNumber( 3 );
              itemFont->SetBitVectorValue( NEW_LINE, true );
              itemParam->s = TO_OLE(L"222");
              doc->ksTextLine( itemParam );

              itemParam->Init();
              doc->ksColumnNumber( 11 );
              itemFont->SetBitVectorValue( SPECIAL_SYMBOL, true );
              itemParam->type   = SPECIAL;
              itemParam->iSNumb = 23;
              doc->ksTextLine( itemParam );

              itemParam->Init();
              doc->ksColumnNumber( 12 );
              itemFont->SetBitVectorValue( NEW_LINE, true );
              itemParam->s = TO_OLE(L"333");
              doc->ksTextLine( itemParam );
              doc->ksColumnNumber( 13 );
              itemFont->SetBitVectorValue( NEW_LINE, true );
              itemParam->s = TO_OLE(L"444");
              doc->ksTextLine( itemParam );
            }
          }
        }
        reference p = doc->ksEndObj(); //вернется указатель на допуск формы
        doc->ksLightObj( p, 1 );

        arr->ksDeleteArray();
        branArr->ksDeleteArray();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Построить эквидистанту
// ---
void DrawEquidistant( ksDocument2DPtr & doc ) {
  ksEquidistantParamPtr par( (ksEquidistantParam*)kompas->GetParamStruct(ko_EquidParam), false/*AddRef*/ );
  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );

  if ( (bool)par && (bool)info ) {
    par->side   = 2;    // признак, с какой стороны строить эквидистанту
                        // 0-слева по направлению, 1-справа по направлению, 2-с двух сторон
    par->cutMode = 0;   // тип обхода углов контура
                        // 0-обход срезом, 1- обход дугой
    par->degState = 0;  // флаг разрешения вырожденных сегментов эквидистанты
                        // 0-вырожденные сегменты запрещены, 1-вырожденные сегменты разрешены
    par->radRight = 5;  // радиус эквидистанты
    par->radLeft  = 3;  // радиус эквидистанты
    par->style    = 1;  // тип линии
    info->commandsString = TO_OLE(L"Укажите объект");
    double x, y;
    // найдем объект
    int j;
    reference p1;
    do {
      j = doc->ksCursor( info, &x ,&y, NULL );
      if ( j ) {
        par->geoObj = doc->ksFindObj(x, y, 1e6);
        if ( doc->ksExistObj(par->get_geoObj()) ) {
          if ( (p1 = doc->ksEquidistant(par)) != 0 ) { // параметры эквидистанты

            doc->ksLightObj( p1, 1 );
            kompas->ksMessage( TO_OLE(L"эквидистанта") );
            doc->ksLightObj( p1, 0 );
          }
          else
            kompas->ksMessageBoxResult();
        }
        else
          kompas->ksError( TO_OLE(L"объект не найден") );
      }
    } while( j );
  }
}

//------------------------------------------------------------------------------
//  Создать эллипс
// ---
void DrawEllipse( ksDocument2DPtr & doc ) {
  ksEllipseParamPtr par( (ksEllipseParam*)kompas->GetParamStruct(ko_EllipseParam), false/*AddRef*/ );
  if ( par ) {
    par->Init();
    par->xc = 50;
    par->yc = 40;
    par->A  = 20;
    par->B  = 10;
    par->style = 1;
    reference p = doc->ksEllipse( par );
    doc->ksLightObj( p, 1 );
    kompas->ksMessage( TO_OLE(L"эллипс") );
    doc->ksLightObj( p, 0 );
  }
}

//------------------------------------------------------------------------------
// Создание полилинии
// ---
void DrawPolyline( ksDocument2DPtr & doc ) {
  //пример создания полилинии одной функцией
  ksPolylineParamPtr par( (ksPolylineParam*)kompas->GetParamStruct(ko_PolylineParam), false/*AddRef*/ );
  ksMathPointParamPtr pr( (ksMathPointParam*)kompas->GetParamStruct(ko_MathPointParam), false/*AddRef*/ );

  if ( (bool)par && (bool)pr ) {
    par->Init();
    pr->Init();

    ksDynamicArrayPtr arr( (ksDynamicArray*)par->GetpMathPoint(), false/*AddRef*/ );
    if ( arr ) {
      pr->x = 10;
      pr->y = 10;
      arr->ksAddArrayItem( -1, pr );
      pr->x = 20;
      pr->y = 20;
      arr->ksAddArrayItem( -1, pr );
      pr->x = 30;
      pr->y = 10;
      arr->ksAddArrayItem( -1, pr );
      pr->x = 40;
      pr->y = 20;
      arr->ksAddArrayItem( -1, pr );

      par->style = 2;
      reference p = doc->ksPolylineByParam( par );
      doc->ksLightObj( p, 1 );
      kompas->ksMessage( TO_OLE(L"Полилиния") );
      doc->ksLightObj( p, 0 );

      arr->ksDeleteArray();
    }
  }
}

//-------------------------------------------------------------------------------
// Создать  Nurbs - сплайн
// ---
void DrawNurbs( ksDocument2DPtr & doc ) {
  ksNurbsPointParamPtr par( (ksNurbsPointParam*)kompas->GetParamStruct(ko_NurbsPointParam), false/*AddRef*/ );
  if ( par ) {
    par->Init();
    //построить Nurbs сплайн  как составной объект
    doc->ksNurbs( 3, 0, 1 );
      par->x = 0;
      par->y = 0;
      par->weight = 1;
      doc->ksNurbsPoint( par );
      par->x = 20;
      par->y = 20;
      par->weight = 1;
      doc->ksNurbsPoint( par );
      par->x = 50;
      par->y = 10;
      par->weight = 1;
      doc->ksNurbsPoint( par );
      par->x = 70;
      par->y = 20;
      par->weight = 1;
      doc->ksNurbsPoint( par );
      par->x = 100;
      par->y = 0;
      par->weight = 1;
      doc->ksNurbsPoint( par );
      par->x =  50;
      par->y = -50;
      par->weight = 1;
      doc->ksNurbsPoint( par );
    reference p = doc->ksEndObj();
    doc->ksLightObj( p, 1 );
    kompas->ksMessage( TO_OLE(L"NURBS") );
    doc->ksLightObj( p, 0 );
  }
}

//-------------------------------------------------------------------------------
// Вставка внешнего фрагмента
// ---
void DrawInsFragment1( ksDocument2DPtr & doc ) {
  ksFragmentPtr frg( (ksFragment*)doc->GetFragment(), false/*AddRef*/ );
  if ( frg ) {
    // определим фрагмент для вставки
    reference pDefFrg = frg->ksFragmentDefinition( TO_OLE(L"c:\\1.frw"), // имя файла фрагмента
                                                   TO_OLE(L"frw1"),      // имя вставки
                                                  1 );         // тип вставки 1 - внешней ссылкой
    if ( pDefFrg ) {
      ksPlacementParamPtr par( (ksPlacementParam*)kompas->GetParamStruct(ko_PlacementParam), false/*AddRef*/ );
      if ( par ) {
        par->angle = 45;
        par->scale_= 2 ;
        par->xBase = 30;
        par->yBase = 40;
        // создаем объект "вставка фрагмента"
        reference p = frg->ksInsertFragment( pDefFrg,     // Указатель определения  фрагмента
                                            false,       // тип размещения по слоям false - на свои слои
                                            par );       // параметры привязки
        doc->ksLightObj( p, 1 );
        kompas->ksMessage( TO_OLE(L"вставка внешнего фрагмента") );
        doc->ksLightObj( p, 0 );
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Вставка локального фрагмента
// ---
void DrawInsFragment2( ksDocument2DPtr & doc ) {
  kompas->ksMessage( TO_OLE(L"1") );
  // определим фрагмент для вставки
  ksFragmentPtr frg( (ksFragment*)doc->GetFragment(), false/*AddRef*/ );
  if ( frg ) {
    kompas->ksMessage( TO_OLE(L"2") );
    reference pDefFrg;
    // определим локальный фрагмент
    if ( frg->ksLocalFragmentDefinition( TO_OLE(L"local") ) ) {
      kompas->ksMessage( TO_OLE(L"3") );
      ksDocument2DPtr fragmentDoc( kompas->ActiveDocument2D() );
      fragmentDoc->ksLineSeg( 0, 0, 10, 0,  1 );
      fragmentDoc->ksLineSeg( 0, 0,  0, 10, 1 );
      fragmentDoc->ksArcByPoint( 0, 0, 10, 10, 0, 0, 10, -1, 1 );
      pDefFrg = frg->ksCloseLocalFragmentDefinition();
      if ( pDefFrg ) {
        kompas->ksMessage( TO_OLE(L"4") );
        ksPlacementParamPtr par( (ksPlacementParam*)kompas->GetParamStruct(ko_PlacementParam), false/*AddRef*/ );
        if ( par ) {
          kompas->ksMessage( TO_OLE(L"5") );
          par->angle = 45;
          par->scale_= 2;
          par->xBase = 30;
          par->yBase = 40;
          // создаем объект "вставка фрагмента"
          reference p = frg->ksInsertFragment( pDefFrg,     // Указатель определения  фрагмента
                                              false,       // тип размещения по слоям false - на свои слои
                                              par );       // параметры привязки
          doc->ksLightObj( p, 1 );
          kompas->ksMessage( TO_OLE(L"вставка локального фрагмента") );
          doc->ksLightObj( p, 0 );
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawSpecRough( ksDocument2DPtr & doc ) {
  ksSpecRoughParamPtr par( (ksSpecRoughParam*)kompas->GetParamStruct(ko_SpecRoughParam), false/*AddRef*/ );
  if ( par ) {
    par->Init();
    par->t     = 1;
    par->s     = TO_OLE(L"Rz40");
    par->sign  = 2;
    par->style = 1;
    doc->ksSpecRough( par );
  }
}


