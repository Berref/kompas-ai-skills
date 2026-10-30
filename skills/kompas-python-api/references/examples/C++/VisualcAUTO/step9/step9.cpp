// step9.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step9.h"


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
// CStep9App

BEGIN_MESSAGE_MAP(CStep9App, CWinApp)
  //{{AFX_MSG_MAP(CStep9App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep9App construction

CStep9App::CStep9App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep9App object

CStep9App theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDS_LIBOBJ;
}

void DrawLinDim( ksDocument2DPtr& doc );
void DrawAngDim( ksDocument2DPtr& doc );
void DrawRough( ksDocument2DPtr& doc );
void DrawLeader( ksDocument2DPtr& doc );
void DrawPosLeader( ksDocument2DPtr& doc );
void DrawBrandLeader( ksDocument2DPtr& doc );
void DrawMarkerLeader( ksDocument2DPtr& doc );
void DrawBase( ksDocument2DPtr& doc );
void DrawCutLine( ksDocument2DPtr& doc );
void DrawDiamDim( ksDocument2DPtr& doc );
void DrawRadDimt( ksDocument2DPtr& doc );
void DrawRadBreakDimt( ksDocument2DPtr& doc );
void DrawViewPointer( ksDocument2DPtr& doc );

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
      case 1  : ::DrawLinDim( doc );       break; //линейный размер
      case 2  : ::DrawAngDim( doc );       break; //угловой размер
      case 3  : ::DrawRough( doc );        break; //шероховатость
      case 4  : ::DrawLeader( doc );       break; //линия выноски
      case 5  : ::DrawPosLeader( doc );    break; //позиционная линия выноски
      case 6  : ::DrawBrandLeader( doc );  break; //клеймение
      case 7  : ::DrawMarkerLeader( doc ); break; //маркирование
      case 8  : ::DrawBase( doc );         break; //обозначение базы
      case 9  : ::DrawCutLine( doc );      break; //маркирование
      case 10 : ::DrawDiamDim( doc );     break; //диаметральный размер
      case 11 : ::DrawRadDimt( doc );      break; //радиальный размер
      case 12 : ::DrawRadBreakDimt( doc ); break; //радиальный размер c изломом
      case 13 : ::DrawViewPointer( doc );  break; //cтрелка вида
      }
    }
    else
      kompas->ksError( _T("Документ не активизирован или \nне является листом/фрагментом") );
  }
}


//-------------------------------------------------------------------------------
//
// ---
void DrawLinDim( ksDocument2DPtr& doc ) {
  ksLDimParamPtr param( kompas->GetParamStruct( ko_LDimParam ) );
  if ( !param )
    return;

  ksDimDrawingParamPtr dPar( param->GetDPar() );
  ksLDimSourceParamPtr sPar( param->GetSPar() );
  ksDimTextParamPtr tPar( param->GetTPar() );

  if ( !dPar || !sPar || !tPar )
    return;

  dPar->Init();
  dPar->textPos   = 10;
  dPar->textBase  = 2;
  dPar->pt1       = 2;
  dPar->pt2       = 2;
  dPar->ang       = -30;
  dPar->lenght    = 20;

  sPar->Init();
  sPar->x1        = 50;
  sPar->y1        = 50;
  sPar->x2        = 70;
  sPar->y2        = 60;
  sPar->dx        = 0;
  sPar->dy        = -20;
  sPar->basePoint = 1;

  tPar->Init(0);
  tPar->SetBitFlagValue( _AUTONOMINAL, true );
  tPar->SetBitFlagValue( _PREFIX, true );
  tPar->SetBitFlagValue( _DEVIATION, true );
  tPar->SetBitFlagValue( _UNIT, true );
  tPar->SetBitFlagValue( _SUFFIX, true );
  tPar->sign = 0;

  ksChar255Ptr str( kompas->GetParamStruct(ko_Char255) );
  ksDynamicArrayPtr arrText( tPar->GetTextArr() );

  if ( !str || !arrText )
    return;

  str->str = _T("prefix");
  arrText->ksAddArrayItem( -1, str );

  str->str = _T("+0,5");
  arrText->ksAddArrayItem( -1, str );

  str->str = _T("-0,5");
  arrText->ksAddArrayItem( -1, str );

  str->str = _T("mm");
  arrText->ksAddArrayItem( -1, str );

  str->str = _T("pp&04ww&01oo");
  arrText->ksAddArrayItem( -1, str );

  long obj = doc->ksLinDimension( param );

  if ( obj ) {
    doc->ksGetObjParam( obj, param, ALLPARAM );
    sPar->x2 = 50;
    sPar->y2 = 60;
    kompas->ksMessage( dPar->pl1 ? _T("Да") : _T("Нет") ); 
    kompas->ksMessage( _T("Поменяем параметры") );
    doc->ksSetObjParam( obj, param, ALLPARAM );
  }
}



//-------------------------------------------------------------------------------
//
// ---
void DrawLinDim1( ksDocument2DPtr& doc ) {
  ksLDimParamPtr param( kompas->GetParamStruct( ko_LDimParam ) );
  if ( !param )
    return;

  ksDimDrawingParamPtr dPar( param->GetDPar() );
  ksLDimSourceParamPtr sPar( param->GetSPar() );
  ksDimTextParamPtr tPar( param->GetTPar() );

  if ( !dPar || !sPar || !tPar )
    return;

  dPar->Init();
  dPar->textPos   = 10;
  dPar->textBase  = 2;
  dPar->pt1       = 2;
  dPar->pt2       = 2;
  dPar->ang       = -30;
  dPar->lenght    = 20;

  sPar->Init();
  sPar->x1        = 50;
  sPar->y1        = 50;
  sPar->x2        = 70;
  sPar->y2        = 60;
  sPar->dx        = 0;
  sPar->dy        = -20;
  sPar->basePoint = 1;

  tPar->Init(0);
  tPar->SetBitFlagValue( _AUTONOMINAL, false );
  tPar->SetBitFlagValue( _PREFIX, true );
  tPar->SetBitFlagValue( _NOMINALOFF, true );
  tPar->SetBitFlagValue( _DEVIATION, false );
  tPar->SetBitFlagValue( _UNIT, false );
  tPar->SetBitFlagValue( _SUFFIX, false );
  tPar->sign = 0;

  ksChar255Ptr str( kompas->GetParamStruct(ko_Char255) );
  ksDynamicArrayPtr arrText( tPar->GetTextArr() );

  if ( !str || !arrText )
    return;

  str->str = _T("12&0111\'10\"");
  arrText->ksAddArrayItem( -1, str );

  long obj = doc->ksLinDimension( param );

}


//-------------------------------------------------------------------------------
//
// ---
void DrawAngDim( ksDocument2DPtr& doc ) {
  ksADimParamPtr aDim( kompas->GetParamStruct(ko_ADimParam) );  
  ksTextLineParamPtr textLine( kompas->GetParamStruct( ko_TextLineParam ) );
  ksTextItemParamPtr textItem( kompas->GetParamStruct(ko_TextItemParam) );

  if ( !aDim || !textLine || !textItem )
    return;
    
  textLine->Init();
    
  textItem->Init();
  textItem->s = _T("Угловой размер");

  ksTextItemFontPtr font( textItem->GetItemFont() );
  ksDimTextParamPtr tPar( aDim->GetTPar() ); 
  ksADimSourceParamPtr sPar( aDim->GetSPar() ); 
  ksDimDrawingParamPtr dPar( aDim->GetDPar() );
  
  if ( !font || !tPar || !sPar || !dPar )
    return;

  dPar->Init();

  sPar->Init();
  sPar->rad = 50;

  tPar->Init( true );
  
  font->Init();
  font->height   = 5;
  font->ksu      = 1;
  font->fontName = _T("GOST type A");
  font->SetBitVectorValue( NEW_LINE, true );

  ksDynamicArrayPtr arr( textLine->GetTextItemArr() );
  if ( !arr )
    return;

  arr->ksAddArrayItem( -1, textItem );

  ksDynamicArrayPtr arr1( tPar->GetTextArr() );
  if ( !arr1 )
    return;

  arr1->ksAddArrayItem( -1, textLine );
    
  long obj = doc->ksAngDimension( aDim );
  if ( obj ) {
    doc->ksGetObjParam( obj, aDim, ALLPARAM );
    sPar->Init();
    sPar->rad = 100;
    kompas->ksMessage( _T("Поменяем параметры") );
    doc->ksSetObjParam( obj, aDim, ALLPARAM );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawRough( ksDocument2DPtr& doc ) {
  ksRoughParamPtr roughPar( kompas->GetParamStruct(ko_RoughParam) );  // 
  ksRoughParPtr rPar( roughPar->GetrPar() );   // 
  ksShelfParPtr shPar( roughPar->GetshPar() );   // 
  ksChar255Ptr str( kompas->GetParamStruct(ko_Char255) );
  if ( roughPar && rPar && shPar && str ) {
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
    ksDynamicArrayPtr ptext( rPar->GetpText() );
    if ( !ptext )
      return;
    str->str = _T("1");
    ptext->ksAddArrayItem( -1, str );
    str->str = _T("2");
    ptext->ksAddArrayItem( -1, str );
    str->str = _T("3");
    ptext->ksAddArrayItem( -1, str );
    str->str = _T("4");
    ptext->ksAddArrayItem( -1, str );
    str->str = _T("5");
    ptext->ksAddArrayItem( -1, str );
    str->str = _T("6");
    ptext->ksAddArrayItem( -1, str );
    str->str = _T("7");
    ptext->ksAddArrayItem( -1, str );

    //параметры выносной полки
    shPar->psh    = 0;   // полки нет
    shPar->ang    = 130; // угол наклона ножки
    shPar->length = 20;  // длина ножки

    long obj = doc->ksRough( roughPar );    

    if ( obj ) {
      doc->ksGetObjParam( obj, roughPar, ALLPARAM );
      rPar->ang = 100;
      kompas->ksMessage( _T("Поменяем параметры") );
      doc->ksSetObjParam( obj, roughPar, ALLPARAM );
    } 
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawLeader( ksDocument2DPtr& doc ) {
  ksLeaderParamPtr    lead      ( kompas->GetParamStruct(ko_LeaderParam)   );
  ksTextLineParamPtr  tLinePar  ( kompas->GetParamStruct(ko_TextLineParam) );
  ksTextItemParamPtr  ItemPar   ( kompas->GetParamStruct(ko_TextItemParam) );
  ksTextItemFontPtr   tFont     ( ItemPar->GetItemFont() );
  ksMathPointParamPtr tMathPoint( kompas->GetParamStruct(ko_MathPointParam));
  if ( lead && tLinePar && ItemPar && tFont && tMathPoint ) {
    lead->Init(); tLinePar->Init(); ItemPar->Init(); tFont->Init(); tMathPoint->Init();

    tFont->SetBitVectorValue( NEW_LINE, true );
    tLinePar->style = 0;

    ksDynamicArrayPtr pText( lead->GetpTextline() );
    ksDynamicArrayPtr TextItemArr( tLinePar->GetTextItemArr() );
    if ( !TextItemArr || !pText )
      return;

    ItemPar->s = _T("1");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );

    TextItemArr->ksClearArray();
    ItemPar->s = _T("2");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );

    TextItemArr->ksClearArray();
    ItemPar->s = _T("3");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );
        
    ksDynamicArrayPtr pPolyLin( lead->GetpPolyline() );
    ksDynamicArrayPtr pMathPoint( kompas->GetDynamicArray(POINT_ARR) );
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
    lead->arrowType = 1;  // тип стрелки
    lead->dirX      = 1;  // направление полки по X (1 -вправо -1-влево)
    lead->signType  = 0;  // тип знака
    lead->around    = 0;  // знак обработки по контуру 0-выключен 1- включен
    lead->cText0    = 1;  // количество строк текста над полкой 0- текст отсутствует
    lead->cText1    = 1;  // количество строк текста под полкой 0- текст отсутствует
    lead->cText2    = 0;  // количество строк текста над ножкой (не более 1 строки)0- текст отсутствует
    lead->cText3    = 1;  // количество строк текста под ножкой (не более 1 строки)0- текст отсутствует

    long obj = doc->ksLeader( lead );
    if ( obj ) {
      doc->ksGetObjParam( obj, lead, ALLPARAM );
      lead->x = 100;
      kompas->ksMessage( _T("Поменяем параметры") );
      doc->ksSetObjParam( obj, lead, ALLPARAM );
    } 
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawPosLeader( ksDocument2DPtr& doc ) {
  ksPosLeaderParamPtr lead      ( kompas->GetParamStruct(ko_PosLeaderParam) );
  ksTextLineParamPtr  tLinePar  ( kompas->GetParamStruct(ko_TextLineParam)  );
  ksTextItemParamPtr  ItemPar   ( kompas->GetParamStruct(ko_TextItemParam)  );
  ksTextItemFontPtr   tFont     ( ItemPar->GetItemFont() );
  ksMathPointParamPtr tMathPoint( kompas->GetParamStruct(ko_MathPointParam) );
  if ( lead && tLinePar && ItemPar && tFont && tMathPoint ) {//&& ref ) {
    lead->Init(); tLinePar->Init(); ItemPar->Init(); tFont->Init(); tMathPoint->Init();

    lead->style = INDICATIN_TEXT_LINE_ARR;
    tFont->SetBitVectorValue( NEW_LINE, true );
    tLinePar->style = 0;

    ksDynamicArrayPtr pText( lead->GetpTextline() );
    ksDynamicArrayPtr TextItemArr( tLinePar->GetTextItemArr() );
    if ( !pText || !TextItemArr )
      return;
    
    ItemPar->s = _T("1");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );

    TextItemArr->ksClearArray();
    ItemPar->s = _T("4");
    TextItemArr->ksAddArrayItem( -1, ItemPar );
    pText->ksAddArrayItem( -1, tLinePar );

        
    ksDynamicArrayPtr pPolyLin( lead->GetpPolyline() );
    ksDynamicArrayPtr pMathPoint( kompas->GetDynamicArray(POINT_ARR) );
    if ( !pPolyLin || !pMathPoint )
      return;

    tMathPoint->x = 10;
    tMathPoint->y = 10;

    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin  ->ksAddArrayItem( -1, pMathPoint );

    tMathPoint->x = 30;
    tMathPoint->y = 10;
    pMathPoint->ksClearArray();
    pMathPoint->ksAddArrayItem( -1, tMathPoint );
    pPolyLin  ->ksAddArrayItem( -1, pMathPoint );

    lead->SetpPolyline( pPolyLin );
        
    //заполним параметры 
    lead->x         = 50; // координаты базовой точки ( начало полки )
    lead->y         = 50;
    lead->arrowType = 1;
    lead->dirX      = -1;

    long obj = doc->ksPositionLeader( lead );
    if ( obj ) {
      doc->ksGetObjParam( obj, lead, ALLPARAM );
      lead->x = 100;
      kompas->ksMessage( _T("Поменяем параметры") );
      doc->ksSetObjParam( obj, lead, ALLPARAM );
    } 
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawBrandLeader( ksDocument2DPtr& doc ) {
  ksBrandLeaderParamPtr lead      ( kompas->GetParamStruct(ko_BrandLeaderParam) );
  ksTextLineParamPtr    tLinePar  ( kompas->GetParamStruct(ko_TextLineParam) );
  ksTextItemParamPtr    ItemPar   ( kompas->GetParamStruct(ko_TextItemParam) );
  ksChar255Ptr          str       ( kompas->GetParamStruct(ko_Char255) );
  ksMathPointParamPtr   tMathPoint( kompas->GetParamStruct(ko_MathPointParam) );
  ksDynamicArrayPtr     pMathPoint( kompas->GetDynamicArray(POINT_ARR) );
  if ( lead && tLinePar && ItemPar && tMathPoint && str && pMathPoint ) {
    lead->Init(); tLinePar->Init(); ItemPar->Init(); str->Init(); tMathPoint->Init();

    ksTextItemFontPtr tFont( ItemPar->GetItemFont() );
    ksDynamicArrayPtr ptext( lead->GetpTextline() );
    ksDynamicArrayPtr pPolyLin( lead->GetpPolyline() );
    if ( !ptext || !tFont || !pPolyLin )
      return;
    tFont->Init(); 

    lead->cText0 = 1;
  
    str->str = _T("1");
    ptext->ksAddArrayItem( -1, str );
    str->str = _T("2");
    ptext->ksAddArrayItem( -1, str );
    str->str = _T("3");
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
    lead->x         = 50; // координаты базовой точки ( начало полки )
    lead->y         = 50;
    lead->arrowType =  1;
    lead->dirX      = -1;
    lead->cText0    =  1;
    lead->cText1    =  1;
    lead->cText2    =  1;
        
    long obj = doc->ksBrandLeader( lead );
    if ( obj ) {
      doc->ksGetObjParam( obj, lead, ALLPARAM );
      lead->x = 100;
      kompas->ksMessage( _T("Поменяем параметры") );
      doc->ksSetObjParam( obj, lead, ALLPARAM );
    } 
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawMarkerLeader( ksDocument2DPtr& doc ) {
  ksMarkerLeaderParamPtr lead      ( kompas->GetParamStruct(ko_MarkerLeaderParam) );
  ksTextLineParamPtr     tLinePar  ( kompas->GetParamStruct(ko_TextLineParam) );
  ksTextItemParamPtr     ItemPar   ( kompas->GetParamStruct(ko_TextItemParam) );
  ksMathPointParamPtr    tMathPoint( kompas->GetParamStruct(ko_MathPointParam) );
  ksChar255Ptr           str       ( kompas->GetParamStruct(ko_Char255) );
  if ( lead && tLinePar && ItemPar && tMathPoint && str ) {
    lead->Init(); tLinePar->Init(); ItemPar->Init(); tMathPoint->Init(); str->Init();

    //заполним параметры 
    lead->x         = 50;// координаты базовой точки ( начало полки )
    lead->y         = 50;
    lead->arrowType = 1;
    lead->cText0    = 1;

    lead->style1    = 0;

    ksDynamicArrayPtr pCharArr( lead->GetpTextline() );
    ksDynamicArrayPtr pPolyLin( lead->GetpPolyline() );
    ksDynamicArrayPtr pMathPoint( kompas->GetDynamicArray(POINT_ARR) );
    ksTextItemFontPtr  tFont( ItemPar->GetItemFont() );
    if ( !tFont || !pCharArr || !pPolyLin )
      return;
    tFont->Init(); 

    str->str = _T("1");
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
      kompas->ksMessage( _T("Поменяем параметры") );
      doc->ksSetObjParam( obj, lead, ALLPARAM );
    } 
  }
}


//-------------------------------------------------------------------------------
//
// ---
void DrawBase( ksDocument2DPtr& doc ) {
  ksBaseParamPtr par( kompas->GetParamStruct(ko_BaseParam) );
  if ( par ) {
    par->style = 0;
    par->type  = false; // строка
    par->x1    = 10;
    par->y1    = 10;
    par->x2    = 30;
    par->y2    = 40;
    par->str   = _T("Это база");
    reference bas = doc->ksBase( par );
    par->Init();
    if ( bas ) {
      doc->ksGetObjParam( bas, par, ALLPARAM );
      par->x2 = -30;
      kompas->ksMessage( _T("Поменяем параметры") );
      doc->ksSetObjParam( bas, par, ALLPARAM );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawCutLine( ksDocument2DPtr& doc ) {
  ksCutLineParamPtr   cut        ( kompas->GetParamStruct(ko_CutLineParam) );
  ksTextLineParamPtr  tLinePar   ( kompas->GetParamStruct(ko_TextLineParam) );
  ksTextItemParamPtr  ItemPar    ( kompas->GetParamStruct(ko_TextItemParam) );
  ksTextItemFontPtr   tFont      ( ItemPar->GetItemFont() );
  ksMathPointParamPtr tMathPoint ( kompas->GetParamStruct(ko_MathPointParam) );
  if ( cut && tLinePar && ItemPar && tFont && tMathPoint ) {//&& ref ) {
    cut->Init(); tLinePar->Init(); ItemPar->Init(); tFont->Init(); tMathPoint->Init();

    cut->type  = 0;
    cut->x1    = 30;
    cut->y1    = 65;
    cut->x2    = 95;
    cut->y2    = 15;
    cut->right = 1;
    cut->str   = _T("A$;1$");
    ksDynamicArrayPtr pMathPoint( cut->GetpMathPoint() );

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

      kompas->ksMessage( _T("Поменяем параметры") );
      doc->ksSetObjParam( obj, cut, ALLPARAM );
    }
  }    
}

//-------------------------------------------------------------------------------
//
// ---
void DrawDiamDim( ksDocument2DPtr& doc ) {
  long cir = doc->ksCircle( 100, 100, 50, 1 ); 
  ksRDimParamPtr aDim        ( kompas->GetParamStruct(ko_RDimParam) );  
  ksTextLineParamPtr textLine( kompas->GetParamStruct( ko_TextLineParam ) );
  ksTextItemParamPtr textItem( kompas->GetParamStruct(ko_TextItemParam) );
  if ( !aDim || !textLine || !textItem  ) 
    return;

  textLine->Init();
  textItem->Init();

  ksDimTextParamPtr     tPar( aDim->GetTPar() ); 
  ksTextItemFontPtr     font( textItem->GetItemFont() );
  ksDynamicArrayPtr     arr ( textLine->GetTextItemArr() );
  ksRDimSourceParamPtr  sPar( aDim->GetSPar() ); 
  ksRDimDrawingParamPtr dPar( aDim->GetDPar() );
  if ( !tPar || !font || !sPar || !dPar )
    return;

  tPar->Init( true );
  tPar->SetBitFlagValue( _AUTONOMINAL, true );
  tPar->sign = 1;

  font->Init();
  font->height   = 5;
  font->ksu      = 1;
  font->fontName = _T("GOST type A");
  font->SetBitVectorValue( NEW_LINE, true );

  arr->ksAddArrayItem( -1, textItem );

  ksDynamicArrayPtr arr1( tPar->GetTextArr() );
  if ( !arr1 ) 
    return;
  arr1->ksAddArrayItem( -1, textLine );

  sPar->Init();
  sPar->xc  = 100;
  sPar->yc  = 100;
  sPar->rad = 50;
    
  dPar->Init();
  dPar->textPos = 75;
  dPar->pt1     = 2;
  dPar->pt2     = 2;
  dPar->shelfDir= 1;
  dPar->ang     = -30;

  long obj = doc->ksDiamDimension( aDim );
  if ( obj ) {
    doc->ksGetObjParam( obj, aDim, ALLPARAM );
    sPar->rad = 100;
    kompas->ksMessage( _T("Поменяем параметры") );
    doc->ksDeleteObj( cir );
    doc->ksCircle( 100, 100, 100, 1 ); 
    doc->ksSetObjParam( obj, aDim, ALLPARAM );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawRadDimt( ksDocument2DPtr& doc ) {
  long cir = doc->ksCircle( 100, 100, 50, 1 ); 
  ksRDimParamPtr     aDim    ( kompas->GetParamStruct(ko_RDimParam) );  
  ksTextLineParamPtr textLine( kompas->GetParamStruct( ko_TextLineParam ) );
  ksTextItemParamPtr textItem( kompas->GetParamStruct(ko_TextItemParam) );
  if ( !aDim || !textLine || !textItem  ) 
    return;
    
  textLine->Init();
  textItem->Init();

  ksDimTextParamPtr tPar( aDim->GetTPar() ); 
  ksTextItemFontPtr font( textItem->GetItemFont() );
  ksDynamicArrayPtr arr( textLine->GetTextItemArr() );
  ksRDimSourceParamPtr sPar( aDim->GetSPar() ); 
  ksRDimDrawingParamPtr dPar( aDim->GetDPar() );
  if ( !tPar || !font || !sPar || !dPar )
    return;

  tPar->Init( true );
  tPar->SetBitFlagValue( _AUTONOMINAL, true );
  tPar->sign = 1;
    

  font->Init();
  font->height   = 5;
  font->ksu      = 1;
  font->fontName = _T("GOST type A");
  font->SetBitVectorValue( NEW_LINE, true );

  arr->ksAddArrayItem( -1, textItem );

  ksDynamicArrayPtr arr1( tPar->GetTextArr() );
  if ( !arr1 )
    return;

  arr1->ksAddArrayItem( -1, textLine );

  sPar->Init();
  sPar->xc  = 100;
  sPar->yc  = 100;
  sPar->rad = 50;
    
  dPar->Init();
  dPar->textPos  = 75;
  dPar->pt1      = 2;
  dPar->pt2      = 1;
  dPar->shelfDir = 1;
  dPar->ang      = 30;

  long obj = doc->ksRadDimension( aDim );  
  if ( obj ) {
    doc->ksGetObjParam( obj, aDim, ALLPARAM );
    sPar->rad = 100;
    kompas->ksMessage( _T("Поменяем параметры") );
    doc->ksDeleteObj( cir );
    doc->ksCircle( 100, 100, 100, 1 ); 
    doc->ksSetObjParam( obj, aDim, ALLPARAM );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawRadBreakDimt( ksDocument2DPtr& doc ) {
  long cir = doc->ksCircle( 100, 100, 50, 1 ); 
  ksRBreakDimParamPtr aDim   ( kompas->GetParamStruct(ko_RBreakDimParam) );  
  ksDimTextParamPtr tPar     ( aDim->GetTPar() ); 
  ksTextLineParamPtr textLine( kompas->GetParamStruct( ko_TextLineParam ) );
  ksTextItemParamPtr textItem( kompas->GetParamStruct(ko_TextItemParam) );
  ksTextItemFontPtr font( textItem->GetItemFont() );
  if ( aDim && tPar && textLine && textItem && font ) {
    tPar->Init( true );
    textLine->Init();
    textItem->Init();
    font->Init();

    tPar->SetBitFlagValue( _AUTONOMINAL, true );
    tPar->sign = 1;

    font->height   = 5;
    font->ksu      = 1;
    font->fontName = _T("GOST type A");
    font->SetBitVectorValue( NEW_LINE, true );

    ksDynamicArrayPtr arr( textLine->GetTextItemArr() );
    ksDynamicArrayPtr arr1( tPar->GetTextArr() );
    ksRDimSourceParamPtr sPar( aDim->GetSPar() ); 
    ksRBreakDrawingParamPtr dPar( aDim->GetDPar() );
    if ( sPar && dPar && arr && arr1 ) {
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
        kompas->ksMessage( _T("Поменяем параметры") );
        doc->ksDeleteObj( cir );
        doc->ksCircle( 100, 100, 100, 1 ); 
        doc->ksSetObjParam( obj, aDim, ALLPARAM );
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawViewPointer( ksDocument2DPtr& doc ) {
  ksViewPointerParamPtr viewPoint( kompas->GetParamStruct(ko_ViewPointerParam) );
  ksTextItemParamPtr    ItemPar  ( kompas->GetParamStruct(ko_TextItemParam) );
  if ( viewPoint && ItemPar ) {
    ItemPar->Init();
    viewPoint->Init(); 
    ksTextItemFontPtr tFont( ItemPar->GetItemFont() );
    if ( tFont ) {
      tFont->Init();

      viewPoint->x1   = 55;
      viewPoint->y1   = 50;
      viewPoint->x2   = 40;
      viewPoint->y2   = 50;
      viewPoint->xt   = 40;
      viewPoint->yt   = 52;
      viewPoint->type = 0;
      viewPoint->str  = _T("стрелка");

      long p = doc->ksViewPointer( viewPoint );
      if ( p ) {
        doc->ksGetObjParam( p, viewPoint, ALLPARAM);
        viewPoint->type = 0;
        viewPoint->str = _T("стрелка вида");
        kompas->ksMessage( _T("Поменяем параметры") );
        doc->ksSetObjParam( p, viewPoint, ALLPARAM );
      } 
    }
  }
}
