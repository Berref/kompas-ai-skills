// step3a.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step3a.h"

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
// CStep3aApp

BEGIN_MESSAGE_MAP(CStep3aApp, CWinApp)
  //{{AFX_MSG_MAP(CStep3aApp)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep3aApp construction

CStep3aApp::CStep3aApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep3aApp object

CStep3aApp theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_LIBID;
}

KompasObjectPtr kompas;

void WorkContour( ksDocument2DPtr& doc );
void TDemWork( ksDocument2DPtr& doc );
void TableWork( ksDocument2DPtr& doc );
void DrawViewPointer( ksDocument2DPtr& doc );
void WorkStamp( ksDocument2DPtr& doc );
void WorkTolerance( ksDocument2DPtr& doc );
void DrawEquidistant( ksDocument2DPtr& doc );
void DrawEllipse( ksDocument2DPtr& doc );
void DrawPolyline( ksDocument2DPtr& doc );
void DrawNurbs( ksDocument2DPtr& doc );
void DrawInsFragment1( ksDocument2DPtr& doc );
void DrawInsFragment2( ksDocument2DPtr& doc );
void DrawSpecRough( ksDocument2DPtr& doc );

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
          kompas = IDispatchPtr(pCreateKompasObject(), false );
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
        case 1  : ::WorkContour( doc );      break; // контур
        case 2  : ::TDemWork( doc );         break; // технические требования
        case 3  : ::DrawViewPointer( doc );  break; // стрелка вида
        case 4  : ::WorkStamp( doc );         break; // работа со штампом
        case 5  : ::TableWork( doc );         break; // таблица
        case 6  : ::DrawEquidistant( doc );  break; // эквидистанта
        case 7  : ::DrawEllipse( doc );      break; // эллипс
        case 8  : ::DrawPolyline( doc );     break; // полилиния
        case 9  : ::DrawNurbs( doc );         break; // nurbs
        case 10 : ::WorkTolerance( doc );     break; // допуск формы
        case 11 : ::DrawSpecRough( doc );    break; // одинаковая шероховатость
        case 12 : ::DrawInsFragment1( doc ); break; // вставка фрагмента внешней ссылкой
        case 13 : ::DrawInsFragment2( doc ); break; // вставка локального фрагмента
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Построить контур
// ---
void WorkContour( ksDocument2DPtr& doc ) {
  if( doc->ksContour(1) ) {
    doc->ksLineSeg( 20, 30, 50, 30, 1 );
    doc->ksArcByPoint( 50, 20, 10, 50,30, 50, 10, -1, 1 );
    //вложенный контур
    doc->ksContour( 2 );
      doc->ksLineSeg( 50, 10, 20, 10, 1 );
      doc->ksArcByPoint( 20, 20, 10, 20,10, 20, 30, -1, 1 );
    doc->ksEndObj();
    reference _contour = doc->ksEndObj();

    doc->ksLightObj( _contour, 1 );
    kompas->ksMessage( _T("контур") );
    doc->ksLightObj( _contour, 1 );
    reference g = doc->ksNewGroup( 0 );
    doc->ksEndGroup();
    doc->ksAddObjGroup( g, _contour );
    doc->ksMoveObj( g, 10, 10 );
    kompas->ksMessage( _T("сдвинули группу") );
  }
}

//-------------------------------------------------------------------------------
// заполнение технических требований
// ---
void TDemWork( ksDocument2DPtr& doc ) {
  ksDynamicArrayPtr pGab( kompas->GetDynamicArray(RECT_ARR) );
  //поместим техтребования в двух габаритных окнах
  ksRectParamPtr      par ( kompas->GetParamStruct(ko_RectParam) );
  ksMathPointParamPtr pBot( kompas->GetParamStruct(ko_MathPointParam) );
  ksMathPointParamPtr pTop( kompas->GetParamStruct(ko_MathPointParam) );
  if ( pGab && par && pBot && pTop ) {
    pBot->Init();
    pTop->Init();

    pTop->x = 415;
    pTop->y = 80;
    par->SetpTop( pTop );
    pBot->x = 230;
    pBot->y = 65;
    par->SetpBot( pBot );
    pGab->ksAddArrayItem( -1, par );

    pTop->x = 230;
    pTop->y = 60;
    par->SetpTop( pTop );
    pBot->x = 45;
    pBot->y = 15;
    par->SetpBot( pBot );
    pGab->ksAddArrayItem( -1, par );

    if( doc->ksOpenTechnicalDemand(pGab, 0) ) {
      ksTextItemParamPtr itemParam( kompas->GetParamStruct(ko_TextItemParam) );
      if ( itemParam ) {
        itemParam->Init(); 
            
        ksTextItemFontPtr itemFont( itemParam->GetItemFont() );
        if ( itemFont ) {
          itemFont->Init();
           itemFont->SetBitVectorValue( NEW_LINE, true );
          itemParam->s = _T("1111111");
          doc->ksTextLine( itemParam );

          itemFont->Init();
           itemFont->SetBitVectorValue( NEW_LINE, true );
          itemParam->s = _T("2222222");
          doc->ksTextLine( itemParam );

          itemFont->Init();
           itemFont->SetBitVectorValue( NEW_LINE, true );
          itemParam->s = _T("3333333");
          doc->ksTextLine( itemParam );

          itemFont->Init();
           itemFont->SetBitVectorValue( NEW_LINE, true );
          itemParam->s = _T("4444444");
          doc->ksTextLine( itemParam );

          itemFont->Init();
           itemFont->SetBitVectorValue( NEW_LINE, true );
          itemParam->s = _T("5555555");
          doc->ksTextLine( itemParam );

          itemFont->Init();
           itemFont->SetBitVectorValue( NEW_LINE, true );
          itemParam->s = _T("6666666");
          doc->ksTextLine( itemParam );
        }
      }

      doc->ksCloseTechnicalDemand();
    }
  }
}

//-------------------------------------------------------------------------------
// Создание таблицы
// ---
void TableWork( ksDocument2DPtr& doc ) {
  doc->ksTable();
    doc->ksLineSeg( 50, 50, 90, 50, 1 );
    doc->ksLineSeg( 50, 40, 90, 40, 1 );
    doc->ksLineSeg( 50, 30, 90, 30, 1 );
    doc->ksLineSeg( 50, 50, 50, 30, 1 );
    doc->ksLineSeg( 70, 50, 70, 30, 1 );
    doc->ksLineSeg( 90, 50, 90, 30, 1 );

    doc->ksText( 52, 48, 0, 5, 1, 0, _T("1") );
    doc->ksText( 72, 48, 0, 5, 1, 0, _T("2") );
    doc->ksText( 52, 38, 0, 5, 1, 0, _T("3") );
    doc->ksText( 72, 38, 0, 5, 1, 0, _T("4") );
  doc->ksEndObj();
}

//-------------------------------------------------------------------------------
// Создание стрелки вида
// ---
void DrawViewPointer( ksDocument2DPtr& doc ) {
  ksViewPointerParamPtr par( kompas->GetParamStruct(ko_ViewPointerParam) );
  if ( par ) {
    par->Init();
    par->x1 = 55; 
    par->y1 = 50;   // координаты вершины( острия) стрелки
    par->x2 = 40; 
    par->y2 = 50;   // координаты конечной точки стрелки
    par->xt = 40; 
    par->yt = 52;   // координаты текста
    par->type = 0;
    par->str = _T("A"); // надпись

    reference  p = doc->ksViewPointer( par ); //параметры "стрелки вида"
    if ( doc->ksExistObj(p) )
      doc->ksLightObj( p, 1 );
  }
}

//-------------------------------------------------------------------------------
// заполнение основной надписи
// ---
void WorkStamp( ksDocument2DPtr& doc ) {
  ksStampPtr stamp( doc->GetStamp() );
  if ( stamp ) {
    if ( stamp->ksOpenStamp() ) {
      stamp->ksColumnNumber( 2 );

      ksTextItemParamPtr itemParam( kompas->GetParamStruct(ko_TextItemParam) );
      if ( itemParam ) {
        itemParam->Init(); 
           
        ksTextItemFontPtr itemFont( itemParam->GetItemFont() );
        if ( itemFont ) {
           itemFont->SetBitVectorValue( NEW_LINE, true );
          itemParam->s = _T("1111111");
          doc->ksTextLine( itemParam );
        }
      }
  
      stamp->ksCloseStamp();
    }
  }
}

//-------------------------------------------------------------------------------
// Допуск формы
// ---
void WorkTolerance( ksDocument2DPtr& doc ) {
  ksToleranceParamPtr  par     ( kompas->GetParamStruct(ko_ToleranceParam) );
  ksMathPointParamPtr  parPoint( kompas->GetParamStruct(ko_MathPointParam) );
  if ( par && parPoint ) {

    par->Init();
    parPoint->Init();

    ksDynamicArrayPtr    branchArr  ( par->GetBranchArr() );
    ksToleranceBranchPtr tolBran    ( kompas->GetParamStruct(ko_ToleranceBranch) );
    tolBran->Init();
    if ( branchArr && tolBran ) {

      ksDynamicArrayPtr    arr    ( tolBran->GetpMathPoint() );
      if ( arr ) {
        // заполняем параметры 1-ой ноги
        parPoint->x = 40;
        parPoint->y = 10;
        arr->ksAddArrayItem( -1, parPoint );
        tolBran->arrowType = 2;
        tolBran->tCorner   = 1;
        branchArr->ksAddArrayItem( -1, tolBran );

        // заполняем параметры 2-ой ноги
        arr->ksClearArray();
        parPoint->x = 100;
        parPoint->y = 50;
        arr->ksAddArrayItem( -1, parPoint );
        parPoint->x = 100;
        parPoint->x = 10;
        arr->ksAddArrayItem( -1, parPoint );
        tolBran->arrowType = 1;
        tolBran->tCorner   = 5;
        branchArr->ksAddArrayItem( -1, tolBran );

        par->x = 40;
        par->y = 40;
        par->type = 0;

        // допуск формы составной объект
        if ( doc->ksTolerance(par) ) {
          ksTextItemParamPtr itemParam( kompas->GetParamStruct(ko_TextItemParam) );
          if ( itemParam ) {
            itemParam->Init(); 
           
            ksTextItemFontPtr itemFont( itemParam->GetItemFont() );
            if ( itemFont ) {
              doc->ksColumnNumber( 1 );
               itemFont->SetBitVectorValue( SPECIAL_SYMBOL, true );
              itemParam->type = SPECIAL;
              itemParam->iSNumb = 26;
              doc->ksTextLine( itemParam );

              itemParam->Init(); 
              doc->ksColumnNumber( 2 );
               itemFont->SetBitVectorValue( NEW_LINE, true );
              itemParam->s = _T("2222");
              doc->ksTextLine( itemParam );

              doc->ksColumnNumber( 3 );
               itemFont->SetBitVectorValue( NEW_LINE, true );
              itemParam->s = _T("2222");
              doc->ksTextLine( itemParam );

              itemParam->Init(); 
              doc->ksColumnNumber( 11 );
               itemFont->SetBitVectorValue( SPECIAL_SYMBOL, true );
              itemParam->type = SPECIAL;
              itemParam->iSNumb = 23;
              doc->ksTextLine( itemParam );

              itemParam->Init(); 
              doc->ksColumnNumber( 12 );
               itemFont->SetBitVectorValue( NEW_LINE, true );
              itemParam->s = _T("444");
              doc->ksTextLine( itemParam );
              doc->ksColumnNumber( 13 );
              itemFont->SetBitVectorValue( NEW_LINE, true );
              itemParam->s = _T("555");
              doc->ksTextLine( itemParam );
            }
          }
        }
        
        reference p = doc->ksEndObj(); //вернется указатель на допуск формы
        doc->ksLightObj( p, 1 );
      }
      arr->ksDeleteArray();
      branchArr->ksDeleteArray();
    }
  }
}

//-------------------------------------------------------------------------------
// Построить эквидистанту
// ---
void DrawEquidistant( ksDocument2DPtr& doc ) {
  ksEquidistantParamPtr par( kompas->GetParamStruct(ko_EquidParam) );
  ksRequestInfoPtr      info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( par && info ) {
    par->side = 2;     // признак, с какой стороны строить эквидистанту
                          // 0-слева по направлению, 1-справа по направлению, 2-с двух сторон
    par->cutMode = 0;  // тип обхода углов контура
                          // 0-обход срезом, 1- обход дугой
    par->degState = 0; // флаг разрешения вырожденных сегментов эквидистанты
                          // 0-вырожденные сегменты запрещены, 1-вырожденные сегменты разрешены
    par->radRight = 5; // радиус эквидистанты
    par->radLeft  = 3;  // радиус эквидистанты
    par->style    = 1;    // тип линии
    info->commandsString = _T("Укажите объект");
    double x, y;
    // найдем объект
    int j;
    reference p1;
    do {
      j = doc->ksCursor( info, &x ,&y, NULL );
      if ( j ) {
        par->geoObj = doc->ksFindObj(x, y, doc->ksGetCursorLimit() );
        if ( doc->ksExistObj(par->geoObj ) ) 
        {
          if ( (p1 = doc->ksEquidistant(par)) != 0 ) { // параметры эквидистанты

            doc->ksLightObj( p1, 1 );
            kompas->ksMessage( _T("эквидистанта") );
            doc->ksLightObj( p1, 0 );
          }
          else
            kompas->ksMessageBoxResult();
        }
        else
          kompas->ksError( _T("объект не найден") );
      }
    } while( j );
  }
}

//-------------------------------------------------------------------------------
// Создать эллипс
// ---
void DrawEllipse( ksDocument2DPtr& doc ) {
  ksEllipseParamPtr par( kompas->GetParamStruct(ko_EllipseParam) );
  if ( par ) {
    par->Init();
    par->xc = 50;
    par->yc = 40;
    par->A  = 20;
    par->B  = 10;
    par->style = 1;
    reference p = doc->ksEllipse( par );
    doc->ksLightObj( p, 1 );
    kompas->ksMessage( _T("эллипс") );
    doc->ksLightObj( p, 0 );
  }
}

//-------------------------------------------------------------------------------
// Создание полилинии
// ---
void DrawPolyline( ksDocument2DPtr& doc ) {
  //пример создания полилинии одной функцией
  ksPolylineParamPtr  par( kompas->GetParamStruct(ko_PolylineParam) );
  ksMathPointParamPtr pr ( kompas->GetParamStruct(ko_MathPointParam) );
  if ( par && pr ) {
    par->Init();
    pr->Init();

    ksDynamicArrayPtr arr( par->GetpMathPoint() );
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
      kompas->ksMessage( _T("Полилиния") );
      doc->ksLightObj( p, 0 );

      arr->ksDeleteArray();
    }
  }
}

//-------------------------------------------------------------------------------
// Создать  Nurbs - сплайн
// ---
void DrawNurbs( ksDocument2DPtr& doc ) {
  ksNurbsPointParamPtr par( kompas->GetParamStruct(ko_NurbsPointParam) );
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
      par->x = 50;
      par->y = -50;
      par->weight = 1;
      doc->ksNurbsPoint( par );
    reference p = doc->ksEndObj();
    doc->ksLightObj( p, 1 );
    kompas->ksMessage( _T("NURBS") );
    doc->ksLightObj( p, 0 );
  }
}

//-------------------------------------------------------------------------------
// Вставка внешнего фрагмента
// ---
void DrawInsFragment1( ksDocument2DPtr& doc ) {
  ksFragmentPtr frg( doc->GetFragment() );
  if ( frg ) {
    // определим фрагмент для вставки
    reference pDefFrg = frg->ksFragmentDefinition( _T("c:\\1.frw"), // имя файла фрагмента
                                                  _T("frw1"),      // имя вставки
                                                  1 );         // тип вставки 1 - внешней ссылкой
    if ( pDefFrg ) {
      ksPlacementParamPtr par( kompas->GetParamStruct(ko_PlacementParam) );
      if ( par ) {
        par->angle = 45;
        par->scale_ = 2;
        par->xBase  = 30;
        par->yBase  = 40;
        // создаем объект "вставка фрагмента"
        reference p = frg->ksInsertFragment( pDefFrg,     // Указатель определения  фрагмента
                                            false,       // тип размещения по слоям false - на свои слои 
                                            par );       // параметры привязки
        doc->ksLightObj( p, 1 );
        kompas->ksMessage( _T("вставка внешнего фрагмента") );
        doc->ksLightObj( p, 0 );
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Вставка локального фрагмента
// ---
void DrawInsFragment2( ksDocument2DPtr& doc ) {
  // определим фрагмент для вставки
  ksFragmentPtr frg( doc->GetFragment() );
  if ( frg ) {
    reference pDefFrg;
    // определим локальный фрагмент
    if ( frg->ksLocalFragmentDefinition(_T("local")) ) {
      ksDocument2DPtr fragmentDoc( kompas->ActiveDocument2D() );
      fragmentDoc->ksLineSeg( 0, 0, 10, 0,  1 );
      fragmentDoc->ksLineSeg( 0, 0,  0, 10, 1 );
      fragmentDoc->ksArcByPoint( 0, 0, 10, 10, 0, 0, 10, -1, 1 );
      pDefFrg = frg->ksCloseLocalFragmentDefinition();
      if ( pDefFrg ) {
        ksPlacementParamPtr par( kompas->GetParamStruct(ko_PlacementParam) );
        if ( par ) {
          par->angle  = 45;
          par->scale_ = 2;
          par->xBase  = 30;
          par->yBase  = 40;
          // создаем объект "вставка фрагмента"
          reference p = frg->ksInsertFragment( pDefFrg,     // Указатель определения  фрагмента
                                              false,       // тип размещения по слоям false - на свои слои 
                                              par );       // параметры привязки
          doc->ksLightObj( p, 1 );
          kompas->ksMessage( _T("вставка локального фрагмента") );
          doc->ksLightObj( p, 0 );
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawSpecRough( ksDocument2DPtr& doc ) {
  ksSpecRoughParamPtr par( kompas->GetParamStruct(ko_SpecRoughParam) );
  if ( par ) {
    par->Init();
    par->t = 1;
    par->s = _T("Rz40");
    par->sign = 2;
    par->style = 1;
    doc->ksSpecRough( par );
  }
}
