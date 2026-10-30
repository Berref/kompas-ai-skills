//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>

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

void DrawLinDim      ( ksDocument2DPtr & doc );
void DrawAngDim      ( ksDocument2DPtr & doc );
void DrawRough       ( ksDocument2DPtr & doc );
void DrawLeader      ( ksDocument2DPtr & doc );
void DrawPosLeader   ( ksDocument2DPtr & doc );
void DrawBrandLeader ( ksDocument2DPtr & doc );
void DrawMarkerLeader( ksDocument2DPtr & doc );
void DrawBase        ( ksDocument2DPtr & doc );
void DrawCutLine     ( ksDocument2DPtr & doc );
void DrawDiamDim     ( ksDocument2DPtr & doc );
void DrawRadDimt     ( ksDocument2DPtr & doc );
void DrawRadBreakDimt( ksDocument2DPtr & doc );
void DrawViewPointer ( ksDocument2DPtr & doc );

char buf[128];

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
        case 1  : ::DrawLinDim      ( doc ); break; // линейный размер
        case 2  : ::DrawAngDim      ( doc ); break; // угловой размер
        case 3  : ::DrawRough       ( doc ); break; // шероховатость
        case 4  : ::DrawLeader      ( doc ); break; // линия выноски
        case 5  : ::DrawPosLeader   ( doc ); break; // позиционная линия выноски
        case 6  : ::DrawBrandLeader ( doc ); break; // клеймение
        case 7  : ::DrawMarkerLeader( doc ); break; // маркирование
        case 8  : ::DrawBase        ( doc ); break; // обозначение базы
        case 9  : ::DrawCutLine     ( doc ); break; // Линия разреза/cечения
        case 10 : ::DrawDiamDim     ( doc ); break; // диаметральный размер
        case 11 : ::DrawRadDimt     ( doc ); break; // радиальный размер
        case 12 : ::DrawRadBreakDimt( doc ); break; // радиальный размер c изломом
        case 13 : ::DrawViewPointer ( doc ); break; // cтрелка вида
      }
    }
    else
      kompas->ksError(  TO_OLE(L"Документ не активизирован или \nне является листом/фрагментом") );
    kompas->Release();
  }
}

//------------------------------------------------------------------------------
// линейный размер
// ---
void DrawLinDim( ksDocument2DPtr & doc ) {
  ksLDimParamPtr param( (ksLDimParam*)kompas->GetParamStruct( ko_LDimParam ), false/*AddRef*/ );
  if ( !param )
    return;

  ksDimDrawingParamPtr dPar( (ksDimDrawingParam*)param->GetDPar(), false/*AddRef*/ );
  ksLDimSourceParamPtr sPar( (ksLDimSourceParam*)param->GetSPar(), false/*AddRef*/ );
  ksDimTextParamPtr tPar   ( (ksDimTextParam*)param->GetTPar(), false/*AddRef*/ );
  if ( !(bool)dPar || !(bool)sPar || !(bool)tPar )
    return;

  dPar->Init();
  dPar->textPos  = 10;
  dPar->textBase = 2;
  dPar->pt1      = 2;
  dPar->pt2      = 2;
  dPar->ang      = -30;
  dPar->lenght   = 20;

  sPar->Init();
  sPar->x1 = 50;
  sPar->y1 = 50;
  sPar->x2 = 70;
  sPar->y2 = 60;
  sPar->dx = 0;
  sPar->dy = -20;
  sPar->basePoint = 1;

  tPar->Init(0);
  tPar->SetBitFlagValue( _AUTONOMINAL, true );
  tPar->SetBitFlagValue( _PREFIX, true );
  tPar->SetBitFlagValue( _DEVIATION, true );
  tPar->SetBitFlagValue( _UNIT, true );
  tPar->SetBitFlagValue( _SUFFIX, true );
  tPar->sign = 0;

  ksChar255Ptr str( (ksChar255*)kompas->GetParamStruct(ko_Char255), false/*AddRef*/ );
  ksDynamicArrayPtr arrText( (ksDynamicArray*)tPar->GetTextArr(), false/*AddRef*/ );
  if ( !(bool)str || !(bool)arrText )
    return;

  str->str =  TO_OLE(L"prefix");
  arrText->ksAddArrayItem( -1, str );

  str->str =  TO_OLE(L"+0,5");
  arrText->ksAddArrayItem( -1, str );

  str->str =  TO_OLE(L"-0,5");
  arrText->ksAddArrayItem( -1, str );

  str->str =  TO_OLE(L"mm");
  arrText->ksAddArrayItem( -1, str );

  str->str =  TO_OLE(L"pp&04ww&01oo");
  arrText->ksAddArrayItem( -1, str );

  long obj = doc->ksLinDimension( param );

  if ( obj ) {
    doc->ksGetObjParam( obj, param, ALLPARAM );
    sPar->x2 = 50;
    sPar->y2 = 60;
    kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
    doc->ksSetObjParam( obj, param, ALLPARAM );
  }
}

//------------------------------------------------------------------------------
// угловой размер
// ---
void DrawAngDim( ksDocument2DPtr & doc ) {
  ksADimParamPtr aDim( (ksADimParam*)kompas->GetParamStruct(ko_ADimParam), false/*AddRef*/ );
  ksTextLineParamPtr textLine( (ksTextLineParam*)kompas->GetParamStruct( ko_TextLineParam ), false/*AddRef*/ );
  ksTextItemParamPtr textItem( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );

  if ( !(bool)aDim || !(bool)textLine || !(bool)textItem )
    return;

  textLine->Init();

  textItem->Init();
  textItem->s =  TO_OLE(L"Угловой размер");

  ksTextItemFontPtr font( (ksTextItemFont*)textItem->GetItemFont(), false/*AddRef*/ );
  ksDimTextParamPtr tPar( (ksDimTextParam*)aDim->GetTPar(), false/*AddRef*/ );
  ksADimSourceParamPtr sPar( (ksADimSourceParam*)aDim->GetSPar(), false/*AddRef*/ );
  ksDimDrawingParamPtr dPar( (ksDimDrawingParam*)aDim->GetDPar(), false/*AddRef*/ );

  if ( !(bool)font || !(bool)tPar || !(bool)sPar || !(bool)dPar )
    return;

  dPar->Init();

  sPar->Init();
  sPar->rad = 50;

  tPar->Init( true );

  font->Init();
  font->height = 5;
  font->ksu    = 1;
  font->fontName =  TO_OLE(L"GOST type A");
  font->bitVector = NEW_LINE;

  ksDynamicArrayPtr arr( (ksDynamicArray*)textLine->GetTextItemArr(), false/*AddRef*/ );
  if ( !arr )
    return;

  arr->ksAddArrayItem( -1, textItem );

  ksDynamicArrayPtr arr1( (ksDynamicArray*)tPar->GetTextArr(), false/*AddRef*/ );
  if ( !arr1 )
    return;

  arr1->ksAddArrayItem( -1, textLine );

  long obj = doc->ksAngDimension( aDim );
  if ( obj ) {
    doc->ksGetObjParam( obj, aDim, ALLPARAM );
    sPar->Init();
    sPar->rad = 100;
    kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
    doc->ksSetObjParam( obj, aDim, ALLPARAM );
  }
}

//------------------------------------------------------------------------------
// шероховатость
// ---
void DrawRough( ksDocument2DPtr & doc ) {
  ksRoughParamPtr roughPar( (ksRoughParam*)kompas->GetParamStruct(ko_RoughParam), false/*AddRef*/ );
  ksRoughParPtr rPar( (ksRoughPar*)roughPar->GetrPar(), false/*AddRef*/ );
  ksShelfParPtr shPar( (ksShelfPar*)roughPar->GetshPar(), false/*AddRef*/ );
  ksChar255Ptr str( (ksChar255*)kompas->GetParamStruct(ko_Char255), false/*AddRef*/ );
  if ( (bool)roughPar && (bool)rPar && (bool)shPar && (bool)str ) {
    rPar->Init();
    shPar->Init();
    str->Init();

    //заполним параметры текста шероховатости
    rPar->style  = 0;
    rPar->type   = 0;
    rPar->around = 0;
    rPar->x      = 50;
    rPar->y      = 50;
    rPar->ang    = 90;
    rPar->cText0 = 2;
    rPar->cText1 = 2;
    rPar->cText2 = 2;
    rPar->cText3 = 1;

    //режим, когда тексты задаются массивом строк символов
    ksDynamicArrayPtr ptext( (ksDynamicArray*)rPar->GetpText(), false/*AddRef*/ );
    if ( !ptext )
      return;

    str->str =  TO_OLE(L"1");
    ptext->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"2");
    ptext->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"3");
    ptext->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"4");
    ptext->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"5");
    ptext->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"6");
    ptext->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"7");
    ptext->ksAddArrayItem( -1, str );

    //параметры выносной полки
    shPar->psh    = 0;   //полки нет
    shPar->ang    = 130; //угол наклона ножки
    shPar->length = 20;  //длина ножки

    long obj = doc->ksRough( roughPar );

    if ( obj ) {
      doc->ksGetObjParam( obj, roughPar, ALLPARAM );
      rPar->ang = 100;
      kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
      doc->ksSetObjParam( obj, roughPar, ALLPARAM );
    }
  }
}

//------------------------------------------------------------------------------
// линия выноски
// ---
void DrawLeader( ksDocument2DPtr & doc ) {
  ksLeaderParamPtr lead( (ksLeaderParamPtr)kompas->GetParamStruct(ko_LeaderParam), false/*AddRef*/ );
  ksTextLineParamPtr tLinePar( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
  ksTextItemParamPtr ItemPar( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  ksTextItemFontPtr tFont( (ksTextItemFont*)ItemPar->GetItemFont(), false/*AddRef*/ );
  ksMathPointParamPtr tMathPoint( (ksMathPointParam*)kompas->GetParamStruct(ko_MathPointParam), false/*AddRef*/ );
  if ( (bool)lead && (bool)tLinePar && (bool)ItemPar && (bool)tFont && (bool)tMathPoint ) {
    lead->Init(); tLinePar->Init(); ItemPar->Init(); tFont->Init(); tMathPoint->Init();

    tFont->bitVector = NEW_LINE;
    tLinePar->style = 0;

    ksDynamicArrayPtr pText( (ksDynamicArray*)lead->GetpTextline(), false/*AddRef*/ );
    ksDynamicArrayPtr TextItemArr( (ksDynamicArray*)tLinePar->GetTextItemArr(), false/*AddRef*/ );
    if ( !(bool)TextItemArr || !(bool)pText )
      return;

    ItemPar->s =  TO_OLE(L"1");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );

    TextItemArr->ksClearArray();
    ItemPar->s =  TO_OLE(L"2");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );

    TextItemArr->ksClearArray();
    ItemPar->s =  TO_OLE(L"3");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );

    ksDynamicArrayPtr pPolyLin( (ksDynamicArray*)lead->GetpPolyline(), false/*AddRef*/ );
    ksDynamicArrayPtr pMathPoint( (ksDynamicArray*)kompas->GetDynamicArray(POINT_ARR), false/*AddRef*/ );
    if ( !pPolyLin || !pMathPoint )
      return;

    tMathPoint->x = 10;
    tMathPoint->y = 10;

    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin->ksAddArrayItem( -1, pMathPoint );

    tMathPoint->x = 30;
    tMathPoint->y = 10;
    pMathPoint->ksClearArray();
    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin->ksAddArrayItem( -1, pMathPoint );

    lead->SetpPolyline( pPolyLin );

    //заполним параметры
    lead->x         = 50; // координаты базовой точки ( начало полки )
    lead->y         = 50;
    lead->arrowType = 1; // тип стрелки
    lead->dirX      = 1; // направление полки по X (1 -вправо -1-влево)
    lead->signType  = 0; // тип знака
    lead->around    = 0; // знак обработки по контуру 0-выключен 1- включен
    lead->cText0    = 1; // количество строк текста над полкой 0- текст отсутствует
    lead->cText1    = 1; // количество строк текста под полкой 0- текст отсутствует
    lead->cText2    = 0; // количество строк текста над ножкой (не более 1 строки)0- текст отсутствует
    lead->cText3    = 1; // количество строк текста под ножкой (не более 1 строки)0- текст отсутствует

    long obj = doc->ksLeader( lead );
    if ( obj ) {
      doc->ksGetObjParam( obj, lead, ALLPARAM );
      lead->x = 100;
      kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
      doc->ksSetObjParam( obj, lead, ALLPARAM );
    }
  }
}

//------------------------------------------------------------------------------
// позиционная линия выноски
// ---
void DrawPosLeader( ksDocument2DPtr & doc ) {
  ksPosLeaderParamPtr lead( (ksPosLeaderParam*)kompas->GetParamStruct(ko_PosLeaderParam), false/*AddRef*/ );
  ksTextLineParamPtr tLinePar( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
  ksTextItemParamPtr ItemPar( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  ksTextItemFontPtr tFont( (ksTextItemFont*)ItemPar->GetItemFont(), false/*AddRef*/ );
  ksMathPointParamPtr tMathPoint( (ksMathPointParam*)kompas->GetParamStruct(ko_MathPointParam), false/*AddRef*/ );
  if ( (bool)lead && (bool)tLinePar && (bool)ItemPar && (bool)tFont && (bool)tMathPoint ) {
    lead->Init(); tLinePar->Init(); ItemPar->Init(); tFont->Init(); tMathPoint->Init();

    lead->style = INDICATIN_TEXT_LINE_ARR;
    tFont->bitVector = NEW_LINE;
    tLinePar->style = 0;

    ksDynamicArrayPtr pText( (ksDynamicArray*)lead->GetpTextline(), false/*AddRef*/ );
    ksDynamicArrayPtr TextItemArr( (ksDynamicArray*)tLinePar->GetTextItemArr(), false/*AddRef*/ );
    if ( !pText || !TextItemArr )
      return;

    ItemPar->s =  TO_OLE(L"1");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );


    TextItemArr->ksClearArray();
    ItemPar->s =  TO_OLE(L"4");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );


    ksDynamicArrayPtr pPolyLin( (ksDynamicArray*)lead->GetpPolyline(), false/*AddRef*/ );
    ksDynamicArrayPtr pMathPoint( (ksDynamicArray*)kompas->GetDynamicArray(POINT_ARR), false/*AddRef*/ );
    if ( !pPolyLin || !pMathPoint )
      return;

    tMathPoint->x = 10;
    tMathPoint->y = 10;

    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin->ksAddArrayItem( -1, pMathPoint );

    tMathPoint->x = 30;
    tMathPoint->y = 10;
    pMathPoint->ksClearArray();
    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin->ksAddArrayItem( -1, pMathPoint );

    lead->SetpPolyline( pPolyLin );

    //заполним параметры
    lead->x         = 50;// координаты базовой точки ( начало полки )
    lead->y         = 50;
    lead->arrowType = 1;
    lead->dirX      = -1;

    long obj = doc->ksPositionLeader( lead );
    if ( obj ) {
      doc->ksGetObjParam( obj, lead, ALLPARAM );
      lead->x = 100;
      kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
      doc->ksSetObjParam( obj, lead, ALLPARAM );
    }
  }
}

//------------------------------------------------------------------------------
// клеймение
// ---
void DrawBrandLeader( ksDocument2DPtr & doc ) {
  ksBrandLeaderParamPtr lead( (ksBrandLeaderParamPtr)kompas->GetParamStruct(ko_BrandLeaderParam), false/*AddRef*/ );
  ksTextLineParamPtr tLinePar( (ksTextLineParamPtr)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
  ksTextItemParamPtr ItemPar( (ksTextItemParamPtr)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  ksChar255Ptr str( (ksChar255*)kompas->GetParamStruct(ko_Char255), false/*AddRef*/ );
  ksMathPointParamPtr tMathPoint( (ksMathPointParamPtr)kompas->GetParamStruct(ko_MathPointParam), false/*AddRef*/ );
  ksDynamicArrayPtr pMathPoint( (ksDynamicArrayPtr)kompas->GetDynamicArray(POINT_ARR), false/*AddRef*/ );
  if ( (bool)lead && (bool)tLinePar && (bool)ItemPar && (bool)tMathPoint && (bool)str && (bool)pMathPoint ) {
    lead->Init(); tLinePar->Init(); ItemPar->Init(); str->Init(); tMathPoint->Init();

    ksTextItemFontPtr tFont( (ksTextItemFont *)ItemPar->GetItemFont(), false/*AddRef*/ );
    ksDynamicArrayPtr ptext( (ksDynamicArrayPtr)lead->GetpTextline(), false/*AddRef*/ );
    ksDynamicArrayPtr pPolyLin( (ksDynamicArrayPtr)lead->GetpPolyline(), false/*AddRef*/ );
    if ( !(bool)ptext || !(bool)tFont || !(bool)pPolyLin )
      return;
    tFont->Init();

    str->str =  TO_OLE(L"1");
    ptext->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"2");
    ptext->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"3");
    ptext->ksAddArrayItem( -1, str );

    tMathPoint->x = 10;
    tMathPoint->y = 10;

    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin->ksAddArrayItem( -1, pMathPoint );

    tMathPoint->x = 30;
    tMathPoint->y = 10;
    pMathPoint->ksClearArray();
    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin->ksAddArrayItem( -1, pMathPoint );

    //заполним параметры
    lead->x         = 50;// координаты базовой точки ( начало полки )
    lead->y         = 50;
    lead->arrowType = 1;
    lead->dirX      = -1;
    lead->cText0    = 1;
    lead->cText1    = 1;
    lead->cText2    = 1;

    long obj = doc->ksBrandLeader( lead );
    if ( obj ) {
      doc->ksGetObjParam( obj, lead, ALLPARAM );
      lead->x = 100;
      kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
      doc->ksSetObjParam( obj, lead, ALLPARAM );
    }
  }
}

//------------------------------------------------------------------------------
// маркирование
// ---
void DrawMarkerLeader( ksDocument2DPtr & doc ) {
ksMarkerLeaderParamPtr lead( (ksMarkerLeaderParam*)kompas->GetParamStruct(ko_MarkerLeaderParam), false/*AddRef*/ );
  ksTextLineParamPtr tLinePar( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
  ksTextItemParamPtr ItemPar( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  ksMathPointParamPtr tMathPoint( (ksMathPointParam*)kompas->GetParamStruct(ko_MathPointParam), false/*AddRef*/ );
  ksChar255Ptr str( (ksChar255*)kompas->GetParamStruct(ko_Char255), false/*AddRef*/ );
  ksDynamicArrayPtr pMathPoint( (ksDynamicArray*)kompas->GetDynamicArray(POINT_ARR), false/*AddRef*/ );
  if ( (bool)lead && (bool)tLinePar && (bool)ItemPar && (bool)tMathPoint && (bool)str && (bool)pMathPoint ) {
    lead->Init(); tLinePar->Init(); ItemPar->Init(); tMathPoint->Init(); str->Init();

    //заполним параметры
    lead->x         = 50;// координаты базовой точки ( начало полки )
    lead->y         = 50;
    lead->arrowType = 1;
    lead->cText0    = 1;
    lead->cText1    = 1;
    lead->cText2    = 1;
    lead->style1    = 0;

    ksTextItemFontPtr tFont   ( (ksTextItemFont*)ItemPar->GetItemFont(), false/*AddRef*/ );
    ksDynamicArrayPtr pCharArr( (ksDynamicArray*)lead->GetpTextline(), false/*AddRef*/ );
    ksDynamicArrayPtr pPolyLin( (ksDynamicArray*)lead->GetpPolyline(), false/*AddRef*/ );
    if ( !(bool)tFont || !(bool)pCharArr || !(bool)pPolyLin )
      return;

    tFont->Init();

    str->str =  TO_OLE(L"1");
    pCharArr->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"2");
    pCharArr->ksAddArrayItem( -1, str );
    str->str =  TO_OLE(L"3");
    pCharArr->ksAddArrayItem( -1, str );

    tMathPoint->x = 10;
    tMathPoint->y = 10;

    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin->ksAddArrayItem( -1, pMathPoint );

    tMathPoint->x = 30;
    tMathPoint->y = 10;
    pMathPoint->ksClearArray();
    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin->ksAddArrayItem( -1, pMathPoint );

    long obj = doc->ksMarkerLeader( lead );
    if ( obj ) {
      doc->ksGetObjParam( obj, lead, ALLPARAM );
      lead->x = 100;
      kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
      doc->ksSetObjParam( obj, lead, ALLPARAM );
    }
  }
}

//------------------------------------------------------------------------------
// обозначение базы
// ---
void DrawBase( ksDocument2DPtr & doc ) {
  ksBaseParamPtr par( (ksBaseParam*)kompas->GetParamStruct(ko_BaseParam), false/*AddRef*/ );
  if ( par ) {
    par->style = 0;
    par->type  = false; // строка
    par->x1    = 10;
    par->y1    = 10;
    par->x2    = 30;
    par->y2    = 40;
    par->str =  TO_OLE(L"Это база");
    reference bas = doc->ksBase( par );
    par->Init();
    if ( bas ) {
      doc->ksGetObjParam( bas, par, ALLPARAM );
      par->x2 = -30;
      kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
      doc->ksSetObjParam( bas, par, ALLPARAM );
    }
  }
}

//------------------------------------------------------------------------------
// Линия разреза/cечения
// ---
void DrawCutLine( ksDocument2DPtr & doc ) {
  ksCutLineParamPtr cut( (ksCutLineParam*)kompas->GetParamStruct(ko_CutLineParam), false/*AddRef*/ );
  ksTextLineParamPtr tLinePar( (ksTextLineParam*)kompas->GetParamStruct(ko_TextLineParam), false/*AddRef*/ );
  ksTextItemParamPtr ItemPar( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  ksMathPointParamPtr tMathPoint( (ksMathPointParam*)kompas->GetParamStruct(ko_MathPointParam), false/*AddRef*/ );
  if ( (bool)cut && (bool)tLinePar && (bool)ItemPar && (bool)tMathPoint ) {
    cut->Init(); tLinePar->Init(); ItemPar->Init(); tMathPoint->Init();

    cut->type  = 0;
    cut->x1    = 30;
    cut->y1    = 65;
    cut->x2    = 95;
    cut->y2    = 15;
    cut->right = 1;
    cut->str   =  TO_OLE(L"A$;1$");

    ksTextItemFontPtr tFont( (ksTextItemFont*)ItemPar->GetItemFont(), false/*AddRef*/ );
    ksDynamicArrayPtr pMathPoint( (ksDynamicArray*)cut->GetpMathPoint(), false/*AddRef*/ );
    if ( !(bool)tFont || !(bool)pMathPoint )
      return;
    tFont->Init();

    tMathPoint->x = 50;
    tMathPoint->y = 50;

    pMathPoint->ksAddArrayItem( -1, tMathPoint );

    tMathPoint->x = 50;
    tMathPoint->y = 30;

    pMathPoint->ksAddArrayItem( -1, tMathPoint );

    tMathPoint->x = 80;
    tMathPoint->y = 30;

    pMathPoint->ksAddArrayItem( -1, tMathPoint );

    long obj = doc->ksCutLine( cut );
    if ( obj ) {
      doc->ksGetObjParam( obj, cut, ALLPARAM );

      pMathPoint->ksClearArray();

      tMathPoint->x = 30;
      tMathPoint->y = 50;

      pMathPoint->ksAddArrayItem( -1, tMathPoint );

      tMathPoint->x = 30;
      tMathPoint->y = 30;

      pMathPoint->ksAddArrayItem( -1, tMathPoint );

      tMathPoint->x = 80;
      tMathPoint->y = 30;

      pMathPoint->ksAddArrayItem( -1, tMathPoint );

      kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
      doc->ksSetObjParam( obj, cut, ALLPARAM );
    }
  }
}

//------------------------------------------------------------------------------
// диаметральный размер
// ---
void DrawDiamDim( ksDocument2DPtr & doc ) {
  long cir = doc->ksCircle( 100, 100, 50, 1 );
  ksRDimParamPtr aDim( (ksRDimParam*)kompas->GetParamStruct(ko_RDimParam), false/*AddRef*/ );
  ksTextLineParamPtr textLine( (ksTextLineParam*)kompas->GetParamStruct( ko_TextLineParam ), false/*AddRef*/ );
  ksTextItemParamPtr textItem( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  if ( !(bool)aDim || !(bool)textLine || !(bool)textItem  )
    return;

  textLine->Init();
  textItem->Init();

  ksDimTextParamPtr tPar( (ksDimTextParam*)aDim->GetTPar(), false/*AddRef*/ );
  ksTextItemFontPtr font( (ksTextItemFont*)textItem->GetItemFont(), false/*AddRef*/ );
  ksDynamicArrayPtr arr( (ksDynamicArray*)textLine->GetTextItemArr(), false/*AddRef*/ );
  ksRDimSourceParamPtr sPar( (ksRDimSourceParam*)aDim->GetSPar(), false/*AddRef*/ );
  ksRDimDrawingParamPtr dPar( (ksRDimDrawingParam*)aDim->GetDPar(), false/*AddRef*/ );
  if ( !(bool)tPar || !(bool)font || !(bool)arr ||!(bool)sPar || !(bool)dPar )
    return;

  tPar->Init( true );
  tPar->SetBitFlagValue( _AUTONOMINAL, true );
  tPar->sign = 1;

  font->Init();
  font->height = 5;
  font->ksu    = 1;
  font->fontName =  TO_OLE(L"GOST type A");
  font->bitVector = NEW_LINE;

  arr->ksAddArrayItem( -1, textItem );

  ksDynamicArrayPtr arr1( (ksDynamicArray*)tPar->GetTextArr(), false/*AddRef*/ );
  if ( !arr1 )
    return;
  arr1->ksAddArrayItem( -1, textLine );

  sPar->Init();
  sPar->xc  = 100;
  sPar->yc  = 100;
  sPar->rad = 50;

  dPar->Init();

  long obj = doc->ksDiamDimension( aDim );
  if ( obj ) {
    doc->ksGetObjParam( obj, aDim, ALLPARAM );
    sPar->rad = 100;
    kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
    doc->ksDeleteObj( cir );
    doc->ksCircle( 100, 100, 100, 1 );
    doc->ksSetObjParam( obj, aDim, ALLPARAM );
  }
}

//------------------------------------------------------------------------------
// радиальный размер
// ---
void DrawRadDimt( ksDocument2DPtr & doc ) {
  long cir = doc->ksCircle( 100, 100, 50, 1 );
  ksRDimParamPtr aDim( (ksRDimParam*)kompas->GetParamStruct(ko_RDimParam), false/*AddRef*/ );
  ksTextLineParamPtr textLine( (ksTextLineParam*)kompas->GetParamStruct( ko_TextLineParam ), false/*AddRef*/ );
  ksTextItemParamPtr textItem( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  if ( !(bool)aDim || !(bool)textLine || !(bool)textItem  )
    return;

  textLine->Init();
  textItem->Init();

  ksDimTextParamPtr tPar( (ksDimTextParam*)aDim->GetTPar(), false/*AddRef*/ );
  ksTextItemFontPtr font( (ksTextItemFont*)textItem->GetItemFont(), false/*AddRef*/ );
  ksDynamicArrayPtr arr( (ksDynamicArray*)textLine->GetTextItemArr(), false/*AddRef*/ );
  ksRDimSourceParamPtr sPar( (ksRDimSourceParam*)aDim->GetSPar(), false/*AddRef*/ );
  ksRDimDrawingParamPtr dPar( (ksRDimDrawingParam*)aDim->GetDPar(), false/*AddRef*/ );
  if ( !(bool)tPar || !(bool)font || !(bool)arr || !(bool)sPar || !(bool)dPar )
    return;

  tPar->Init( true );
  tPar->SetBitFlagValue( _AUTONOMINAL, true );
  tPar->sign = 1;


  font->Init();
  font->height = 5;
  font->ksu    = 1;
  font->fontName =  TO_OLE(L"GOST type A");
  font->bitVector = NEW_LINE;

  arr->ksAddArrayItem( -1, textItem );

  ksDynamicArrayPtr arr1( (ksDynamicArray*)tPar->GetTextArr(), false/*AddRef*/ );
  if ( !arr1 )
    return;

  arr1->ksAddArrayItem( -1, textLine );

  sPar->Init();
  sPar->xc  = 100;
  sPar->yc  = 100;
  sPar->rad = 50;

  dPar->Init();

  long obj = doc->ksRadDimension( aDim );
  if ( obj ) {
    doc->ksGetObjParam( obj, aDim, ALLPARAM );
    sPar->rad = 100;
    kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
    doc->ksDeleteObj( cir );
    doc->ksCircle( 100, 100, 100, 1 );
    doc->ksSetObjParam( obj, aDim, ALLPARAM );
  }
}

//------------------------------------------------------------------------------
// радиальный размер c изломом
// ---
void DrawRadBreakDimt( ksDocument2DPtr & doc ) {
  long cir = doc->ksCircle( 100, 100, 50, 1 );
  ksRBreakDimParamPtr aDim( (ksRBreakDimParam*)kompas->GetParamStruct(ko_RBreakDimParam), false/*AddRef*/ );
  ksDimTextParamPtr tPar( (ksDimTextParam*)aDim->GetTPar(), false/*AddRef*/ );
  ksTextLineParamPtr textLine( (ksTextLineParam*)kompas->GetParamStruct( ko_TextLineParam ), false/*AddRef*/ );
  ksTextItemParamPtr textItem( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  ksTextItemFontPtr font( (ksTextItemFont*)textItem->GetItemFont(), false/*AddRef*/ );
  if ( (bool)aDim && (bool)tPar && (bool)textLine && (bool)textItem && (bool)font ) {
    tPar->Init( true );
    textLine->Init();
    textItem->Init();
    font->Init();

    tPar->SetBitFlagValue( _AUTONOMINAL, true );
    tPar->sign = 1;

    font->height = 5;
    font->ksu    = 1;
    font->fontName =  TO_OLE(L"GOST type A");
    font->bitVector = NEW_LINE;

    ksDynamicArrayPtr arr( (ksDynamicArray*)textLine->GetTextItemArr(), false/*AddRef*/ );
    ksDynamicArrayPtr arr1( (ksDynamicArray*)tPar->GetTextArr(), false/*AddRef*/ );
    ksRDimSourceParamPtr sPar( (ksRDimSourceParam*)aDim->GetSPar(), false/*AddRef*/ );
    ksRBreakDrawingParamPtr dPar( (ksRBreakDrawingParam*)aDim->GetDPar(), false/*AddRef*/ );
    if ( (bool)sPar && (bool)dPar && (bool)arr && (bool)arr1 ) {
      sPar->Init();
      dPar->Init();

      arr->ksAddArrayItem( -1, textItem );
      arr1->ksAddArrayItem( -1, textLine );

      sPar->xc  = 100;
      sPar->yc  = 100;
      sPar->rad = 50;

      dPar->ang = 0;
      dPar->pb  = 30;
      dPar->pt  = 1;

      long obj = doc->ksRadBreakDimension( aDim );
      if ( obj ) {
        doc->ksGetObjParam( obj, aDim, ALLPARAM );
        sPar->rad = 100;
        kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
        doc->ksDeleteObj( cir );
        doc->ksCircle( 100, 100, 100, 1 );
        doc->ksSetObjParam( obj, aDim, ALLPARAM );
      }
    }
  }
}

//------------------------------------------------------------------------------
// cтрелка вида
// ---
void DrawViewPointer( ksDocument2DPtr & doc ) {
  ksViewPointerParamPtr viewPoint( (ksViewPointerParam*)kompas->GetParamStruct(ko_ViewPointerParam), false/*AddRef*/ );
  ksTextItemParamPtr ItemPar( (ksTextItemParam*)kompas->GetParamStruct(ko_TextItemParam), false/*AddRef*/ );
  if ( (bool)viewPoint && (bool)ItemPar ) {
    ItemPar->Init();
    viewPoint->Init();
    ksTextItemFontPtr tFont( (ksTextItemFont*)ItemPar->GetItemFont(), false/*AddRef*/ );
    if ( tFont ) {
      tFont->Init();

      viewPoint->x1 = 55;
      viewPoint->y1 = 50;
      viewPoint->x2 = 40;
      viewPoint->y2 = 50;
      viewPoint->xt = 40;
      viewPoint->yt = 52;
      viewPoint->type = 0;
      viewPoint->str  =  TO_OLE(L"стрелка");

      long p = doc->ksViewPointer( viewPoint );
      if ( p ) {
        doc->ksGetObjParam( p, viewPoint, ALLPARAM);
        viewPoint->type = 0;
        viewPoint->str  =  TO_OLE(L"стрелка вида");
        kompas->ksMessage(  TO_OLE(L"Поменяем параметры") );
        doc->ksSetObjParam( p, viewPoint, ALLPARAM );
      }
    }
  }
}

