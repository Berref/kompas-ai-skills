 // step3.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step3.h"

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
// CStep3App

BEGIN_MESSAGE_MAP(CStep3App, CWinApp)
  //{{AFX_MSG_MAP(CStep3App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep3App construction

CStep3App::CStep3App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep3App object

CStep3App theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_LIBID;
}

KompasObjectPtr kompas( NULL );

void WorkDocument();
void DrawView( ksDocument2DPtr& doc );
void DrawLayer( ksDocument2DPtr& doc );
void DrawGroup( ksDocument2DPtr& doc );
void WorkNameGroup( ksDocument2DPtr& doc );
void DrawLineSeg( ksDocument2DPtr& doc );
void DrawArc( ksDocument2DPtr& doc );
void DrawLine( ksDocument2DPtr& doc );
void DrawCircle( ksDocument2DPtr& doc );
void DrawPoint( ksDocument2DPtr& doc );
void DrawBezier( ksDocument2DPtr& doc );
void DrawHatch( ksDocument2DPtr& doc );
void DrawText( ksDocument2DPtr& doc );

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
          kompas = IDispatchPtr( pCreateKompasObject(), false );
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
    if ( comm == 1 ) 
      ::WorkDocument();  // создать документ
    else {
      ksDocument2DPtr doc( kompas->ActiveDocument2D() );
      if ( doc ) {
        switch ( comm ) {
          case 2  : ::DrawView( doc );      break; // виды
          case 3  : ::DrawLayer( doc );     break; // слои
          case 4  : ::DrawGroup( doc );     break; // группы
          case 5  : ::WorkNameGroup( doc ); break; // именная группа
          case 6  : ::DrawLineSeg( doc );   break; // отрезки
          case 7  : ::DrawArc( doc );       break; // дуги
          case 8  : ::DrawLine( doc );      break; // линии
          case 9  : ::DrawCircle( doc );    break; // окружности
          case 10 : ::DrawPoint( doc );      break; // точки
          case 11 : ::DrawBezier( doc );    break; // Bezier-сплайны
          case 12 : ::DrawHatch( doc );     break; // штриховка
          case 13 : ::DrawText( doc );      break; // текст
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------
//  работа с документом
//-------------------------------------------------------------------------------
void WorkDocument() {
  TCHAR buf[ 128 ];
  ksDocument2DPtr doc( kompas->Document2D() );
  ksDocumentParamPtr docPar ( kompas->GetParamStruct(ko_DocumentParam) );
  ksDocumentParamPtr docPar1( kompas->GetParamStruct(ko_DocumentParam) );
  if ( docPar && docPar1 ) {
    docPar->fileName = _T("c:\\2.cdw");
    docPar->comment  = _T("create document");
    docPar->author   = _T("user");
    docPar->regime   = 0;
    docPar->type     = lt_DocSheetStandart;
    ksSheetParPtr shPar( docPar->GetLayoutParam() );
    if ( shPar ) {
      shPar->shtType = 1;
      shPar->layoutName = _T("");
      ksStandartSheetPtr stPar( shPar->GetSheetParam() );
      if ( stPar ) {
        stPar->format   = 3;
        stPar->multiply = 1;
        stPar->direct   = false;
      }
    }
    // создали документ: лист, формат А3, горизонтально расположенный
    // и с системным штампом 1
    doc->ksCreateDocument( docPar );

    ksViewParamPtr par( kompas->GetParamStruct(ko_ViewParam) );
    if ( par ) {
      long number = 2;
      par->Init();
      par->x = 10;
      par->y = 20;
      par->scale_ = 0.5;
      par->angle = 45;
      par->color = RGB(10, 20, 10);
      par->state = stACTIVE;
      par->name = _T("user view");
      // у документа создадим вид с номером 2, масштабом 0.5, под углом 45 гр
      doc->ksCreateSheetView( par, &number );

      // создадим слой с номером 5
      doc->ksLayer( 5 );

      doc->ksLineSeg( 20, 10, 40, 10, 1 );
      doc->ksLineSeg( 40, 10, 40, 30, 1 );
      doc->ksLineSeg( 40, 30, 20, 30, 1 );
      doc->ksLineSeg( 20, 30, 20, 10, 1 );

      kompas->ksMessage( _T("нарисовали") );

      // получить параметры документа
      doc->ksGetObjParam( doc->reference, docPar1, ALLPARAM);
      ksSheetParPtr shPar1( docPar1->GetLayoutParam() );
      if ( shPar1 ) {
        ksStandartSheetPtr stPar( shPar1->GetSheetParam() );
        if ( stPar ) {
          ::_stprintf_s( buf, _T("type = %d, f = %d, m = %d, d = %d"), docPar1->type, stPar->format,
                     stPar->multiply, stPar->direct );
          kompas->ksMessage( buf );
        }
      }

      kompas->ksMessage( docPar1->fileName );
      kompas->ksMessage( docPar1->comment  );
      kompas->ksMessage( docPar1->author   );

      // сохраним документ
      doc->ksSaveDocument( _T("") );
    }
  }
}

//-------------------------------------------------------------------------------
// Создать вид
//-------------------------------------------------------------------------------
void DrawView( ksDocument2DPtr& doc )  {
  TCHAR buf[128];
  ksViewParamPtr par( kompas->GetParamStruct(ko_ViewParam) );
  if ( par ) {
    long number = 5;
    par->Init();
    par->x = 10;
    par->y = 20;
    par->scale_ = 0.5;
    par->angle  = 45;
    par->color  = RGB(10, 20, 10);
    par->state  = stACTIVE;
    par->name   = _T("user view");

    reference gr = doc->ksNewGroup( 0 );
      doc->ksLineSeg( 20, 10, 20, 30, 1 );
      doc->ksLineSeg( 20, 30, 40, 30, 1 );
      doc->ksLineSeg( 40, 30, 40, 10, 1 );
      doc->ksLineSeg( 40, 10, 20, 10, 1 );
    doc->ksEndGroup();

    // создали вид
    reference v = doc->ksCreateSheetView( par, &number );
    number = doc->ksGetViewNumber( v );
    ::_stprintf_s( buf, _T("создали вид: ref = %d, number = %d"), v, number );
    kompas->ksMessage( buf );

    doc->ksAddObjGroup( gr, v );
    kompas->ksMessage( _T("добавили вид в группу") );
    kompas->ksMessageBoxResult();
    
    reference p = doc->ksLineSeg( 10, 10, 30, 30, 0 );
    doc->ksAddObjGroup( gr, p );

    kompas->ksMessage( _T("добавили эл в группу") );
    kompas->ksMessageBoxResult();

    doc->ksRotateObj( gr, 0, 0, -45 );

    // взять параметры вида
    par->Init();
    doc->ksGetObjParam( v, par, ALLPARAM);

    ::_stprintf_s( buf, _T("x = %4.1f, y = %4.1f, angl = %4.1f, name = %s, st = %d"), par->x, 
                   par->y, par->angle, (LPCTSTR)par->name, par->state );
    kompas->ksMessage( buf );

    // сделать текущим системный вид( номер 0 )
    doc->ksOpenView( 0 );
    // состояние  вида  : только чтение
    ksLtVariantPtr var( kompas->GetParamStruct(ko_LtVariant) );
    if ( var ) {
      var->Init();
      var->intVal = stREADONLY;
      doc->ksSetObjParam( v, var, VIEW_LAYER_STATE );
    }
  }
}

//-------------------------------------------------------------------------------
// Создать слой
//-------------------------------------------------------------------------------
void DrawLayer( ksDocument2DPtr & doc ) {
  long n;
  if ( !kompas->ksReadInt(_T("Введите номер слоя"), 1, 0, 255, &n) )
    return;
  
  // создаем слой, слой становится текущим
  reference lay = doc->ksLayer( n );
  doc->ksMtr( 20, 15, 0, 1, 1 );
    doc->ksLineSeg( -10, 0,  10,  0,  1 );
    doc->ksLineSeg( 10,  0,  10,  20, 1 );
    doc->ksLineSeg( 10,  20, -10, 20, 1 );
    doc->ksLineSeg( -10, 20, -10, 0,  1 );
  doc->ksDeleteMtr();

  // подсветить слой
  doc->ksLightObj( lay, 1 );

  // получить номер слоя по указателю и указатель по номеру
  int n1 = doc->ksGetLayerNumber( lay );
  reference l = doc->ksGetLayerReference( n1 );

  TCHAR buf[128];
  ::_stprintf_s( buf, _T("n = %d, n1 = %d, layer = %d, l = %d"), n, n1, lay, l );
  kompas->ksMessage( buf );

  //установить параметры слоя и считать их обратно
  ksLayerParamPtr par ( kompas->GetParamStruct(ko_LayerParam) );
  ksLayerParamPtr par1( kompas->GetParamStruct(ko_LayerParam) );
  if ( par && par1 ) {
    par->Init();
    par1->Init();
    par->color = RGB(0, 255, 0);
    par->state = stACTIVE;
    par->name = _T("зеленый");
    doc->ksLayer( 0 );

    if ( !doc->ksSetObjParam(l, par, ALLPARAM) )
      kompas->ksMessageBoxResult();
    else {
      doc->ksGetObjParam( l, par1, ALLPARAM);
      ::_stprintf_s( buf, _T("col = %d, col1 = %d, name = %s, name1 = %s"), par->color,
                     par1->color, (LPCTSTR)par->name, (LPCTSTR)par1->name );
      kompas->ksMessage( buf );
    }
    doc->ksLightObj( lay, 0 );

    // изменить состояние слоя
    ksLtVariantPtr var( kompas->GetParamStruct(ko_LtVariant) );
    if ( var ) {
      var->Init();
      var->intVal = stACTIVE;
      doc->ksSetObjParam( l, var, VIEW_LAYER_STATE );
    }
  }
}

//-------------------------------------------------------------------------------
// работа с группой
//-------------------------------------------------------------------------------
void DrawGroup( ksDocument2DPtr & doc ) {
  reference p1 = doc->ksLineSeg( 10, 10, 20, 10, 0 );
  reference p2 = doc->ksLineSeg( 10, 10, 10, 20, 0 );

  // создать модельную группу   1
  reference gr1 = doc->ksNewGroup(0);
  doc->ksEndGroup();

  // создать модельную группу   2
  reference gr2 = doc->ksNewGroup(0);
  doc->ksEndGroup();

  doc->ksAddObjGroup( gr1, p1 );
  doc->ksAddObjGroup( gr1, p2 );

  doc->ksAddObjGroup( gr2, p1 );
  doc->ksAddObjGroup( gr2, p2 );

  kompas->ksMessage( _T("создали группы") );

  doc->ksMoveObj( gr1, 10, 0 );
  kompas->ksMessage( _T("сдвинули группу на 10 ММ") );

  doc->ksRotateObj( gr2, 20, 10, 45 );
  kompas->ksMessage( _T("повернули группу на 45 гр") );

  doc->ksRotateObj( gr2, 20, 10, -45 );
  kompas->ksMessage( _T("повернули группу на -45 гр") );

  doc->ksMoveObj( gr1, -10, 0 );
  kompas->ksMessage( _T("сдвинули группу на -10 ММ") );

  // очистили группу 2 ( объекты исключаются из группы )
  doc->ksClearGroup( gr2, false );
  // удалим  группу 2
  doc->ksDeleteObj( gr2 );

  kompas->ksMessage( _T("подсветили gr") );
  doc->ksLightObj( gr1, 1 );

  kompas->ksMessage( _T("выключили gr") );
  doc->ksLightObj( gr1, 0 );

  kompas->ksMessage( _T("подсветили el") );
  doc->ksLightObj( p1, 1 );
  kompas->ksMessage( _T("выключили el") );
  doc->ksLightObj( p1, 0 );

  //удалим  группу 1( объекты удалятся тоже )
  doc->ksDeleteObj( gr1 );
  kompas->ksMessageBoxResult();
}

//-------------------------------------------------------------------------------
//  работа с именнованной группой
//-------------------------------------------------------------------------------
void WorkNameGroup( ksDocument2DPtr& doc ) {
 //рабочая группа сущестует  до конца работы  функции
 reference gr = doc->ksNewGroup( 0 );
   reference p = doc->ksLineSeg( 20, 20, 40, 20, 1 );
   doc->ksLineSeg( 40, 20, 40, 40, 1 );
   doc->ksLineSeg( 40, 40, 20, 40, 1 );
   doc->ksLineSeg( 20, 40, 20, 20, 1 );
 doc->ksEndGroup();

 //рабочую группу сохраняем в именной
 //именная группа хранится в документе и
 if ( !doc->ksSaveGroup(gr, _T("group1")) )
   return;
 reference gr1 = doc->ksGetGroup( _T("group1") );
 if( !gr1 )
   return;

 reference c = doc->ksCircle( 30, 30, 10, 1 );
 doc->ksAddObjGroup( gr1, c );

 doc->ksLightObj( gr1, 1 );
 kompas->ksMessage( _T("добавили объект в именную группу") );
 doc->ksLightObj( gr1, 0 );

 doc->ksExcludeObjGroup( gr1, p );

 doc->ksLightObj( gr1, 1 );
 kompas->ksMessage( _T("исключили объект из именной группы") );
 doc->ksLightObj( gr1, 0 );
}

//-------------------------------------------------------------------------------
// создать отрезок
//--------------------------------------------------------------------------------
void DrawLineSeg( ksDocument2DPtr& doc ) {
  TCHAR buf [128];
  //построить отрезок
  //введем локальную систему ккординат
  doc->ksMtr( 30, 20, 45, 1, 1 );

  reference p = doc->ksLineSeg( 30, 20, 60, 20, 1 );

  //взять параметры отрезка
  ksLineSegParamPtr par( kompas->GetParamStruct(ko_LineSegParam) );
  if ( par ) {
    int t = doc->ksGetObjParam( p, par, ALLPARAM);

    ::_stprintf_s( buf, _T("t = %d, x1 = %4.1f, y1 = %4.1f, x2 = %4.1f, y2 = %4.1f, tl = %d"), t,
                   par->x1, par->y1, par->x2, par->y2, par->style );

    kompas->ksMessage( buf );

    // заменить параметры отрезка
    par->x2 = 30;
    par->y2 = 60;
    par->style = 2;

    if ( doc->ksSetObjParam(p, par, ALLPARAM) )
      kompas->ksMessage( _T("Изменили объект") );
    else
      kompas->ksMessageBoxResult();
  }
  // отключить локальную систему координат
  doc->ksDeleteMtr();
}

//-------------------------------------------------------------------------------
// создать дугу
//--------------------------------------------------------------------------------
void DrawArc( ksDocument2DPtr& doc )  {
  TCHAR buf [128];
  //построить дугу
  doc->ksMtr( 10, 10, 0, 1, 1 );
  reference p = doc->ksArcByAngle( 30, 20, 20, 45, 135, 1, 1 );

  //взять параметры дуги  по углам
  ksArcByAngleParamPtr par ( kompas->GetParamStruct(ko_ArcByAngleParam) );
  ksArcByPointParamPtr par1( kompas->GetParamStruct(ko_ArcByPointParam) );
  if ( par && par1 ) {
    int t = doc->ksGetObjParam( p, par, ALLPARAM);

    ::_stprintf_s( buf, _T("t = %d, xc = %4.1f, yc = %4.1f, rad = %4.1f, \n\n a1 = %4.1f, a2 = %4.1f, napr = %d , tl = %d"),
                   t, par->xc, par->yc, par->rad, par->ang1, par->ang2, 
                   par->dir, par->style );
    kompas->ksMessage( buf );

    // заменить параметры дуги по точкам
    par1->xc = 40;
    par1->yc = 30;
    par1->rad = 10;
    par1->dir = 1;
    par1->style = 2;
    par1->x1 = 50;
    par1->y1 = 30;
    par1->x2 = 40;
    par1->y2 = 20;

    if( doc->ksSetObjParam(p, par1, 1) )
      kompas->ksMessage( _T("Изменили объект") );
    else
      kompas->ksMessageBoxResult();
  }
  doc->ksDeleteMtr();
}

//-------------------------------------------------------------------------------
// создать вспомогательную линию
//--------------------------------------------------------------------------------
void DrawLine( ksDocument2DPtr& doc )  {
  doc->ksMtr( 0, 0, 45, 1, 1 );
  TCHAR buf [128];
  //построить вспомогательную линию
  reference p = doc->ksLine( 30, 20, 0 );

  //взять параметры вспомогательной линии
  ksLineParamPtr par( kompas->GetParamStruct(ko_LineParam) );
  if ( par ) {
    par->Init();
    int t = doc->ksGetObjParam( p, par, ALLPARAM);
    ::_stprintf_s( buf, _T("t = %d, x = %4.1f, y = %4.1f, alf = %4.1f"), t,
                   par->x, par->y, par->angle );
    kompas->ksMessage( buf );

    // заменить параметры вспомогательной линии
    par->angle = 90;

    if( doc->ksSetObjParam(p, par, ALLPARAM) )
      kompas->ksMessage( _T("Изменили объект") );
    else
      kompas->ksMessageBoxResult();
  }
  doc->ksDeleteMtr();
}

//-------------------------------------------------------------------------------
// создать окружность
//--------------------------------------------------------------------------------
void DrawCircle( ksDocument2DPtr & doc ) {
  doc->ksMtr( 0, 0, 0, 2, 2 );
  TCHAR buf[128];
  //построить окружность
  reference p = doc->ksCircle( 30, 20, 10, 1 );

  //взять параметры олружности
  ksCircleParamPtr par( kompas->GetParamStruct(ko_CircleParam) );
  if ( par ) {
    int t = doc->ksGetObjParam( p, par, ALLPARAM);
    ::_stprintf_s( buf, _T("t = %d, xc = %4.1f, yc = %4.1f, rad = %4.1f, tl = %d"), t,
                   par->xc, par->yc, par->rad, par->style );
    kompas->ksMessage( buf );

    //заменить параметры окружности
    par->rad = 20;
    par->style = 2;
    if ( doc->ksSetObjParam(p, par, ALLPARAM) )
      kompas->ksMessage( _T("Изменили объект") );
    else
      kompas->ksMessageBoxResult();
  }
  doc->ksDeleteMtr();
}

//-------------------------------------------------------------------------------
// создать точку
//--------------------------------------------------------------------------------
void DrawPoint( ksDocument2DPtr& doc ) {
  // 0-точка, 1-крестик, 2-х-точка, 3-квадрат, 4-треугольник, 5-окружность, 6-звезда,
  // 7-перечеркнутый квадрат

  doc->ksMtr( 10, 10, 0, 1, 1 );
  TCHAR buf [128];
  //построить точку
  reference p = doc->ksPoint( 30, 40, 0 );
  doc->ksPoint( 40,  40, 1 );
  doc->ksPoint( 50,  40, 2 );
  doc->ksPoint( 60,  40, 3 );
  doc->ksPoint( 70,  40, 4 );
  doc->ksPoint( 80,  40, 5 );
  doc->ksPoint( 90,  40, 6 );
  doc->ksPoint( 100, 40, 7 );

  //взять параметры точки
  ksPointParamPtr par( kompas->GetParamStruct(ko_PointParam) );
  if ( par ) {
    int t = doc->ksGetObjParam( p, par, ALLPARAM);
    ::_stprintf_s( buf, _T("t = %d, x = %4.1f, y = %4.1f, style = %d"), t,
                   par->x, par->y, par->style );
    kompas->ksMessage( buf );

    //заменить параметры точки
    par->x     = 20;
    par->y     = 30;
    par->style = 7;

    if ( doc->ksSetObjParam(p, par, ALLPARAM) )
      kompas->ksMessage( _T("Изменили объект") );
    else
      kompas->ksMessageBoxResult();
  }
  doc->ksDeleteMtr();
}

//-------------------------------------------------------------------------------
// создать Bezier сплайн
//--------------------------------------------------------------------------------
void DrawBezier( ksDocument2DPtr& doc ) {
  TCHAR buf [128];
  double x[] = { 0, 20, 50, 70, 100, 50  };
  double y[] = { 0, 20, 10, 20, 0,   -50 };

  //построить Bezier сплайн
  doc->ksBezier( 0, 1 );
    for ( int i = 0; i < 5; i++ )
      doc->ksPoint( x[i], y[i], 0 );
  reference p = doc->ksEndObj();
  
  //взять параметры Bezier сплайна
  ksMathPointParamPtr pPar( kompas->GetParamStruct(ko_MathPointParam) );
  ksBezierParamPtr    par ( kompas->GetParamStruct(ko_BezierParam)    );
  if ( pPar && par ) {
    par->Init();
    ksDynamicArrayPtr arr( par->GetMathPointArr() );
    if ( arr ) {
      int t = doc->ksGetObjParam( p, par, ALLPARAM);

      int count = arr->ksGetArrayCount();
      ::_stprintf_s( buf, _T("t = %d, count = %d, close = %d, tl = %d"), t,
                     count, par->closed, par->style );
      kompas->ksMessage( buf );

      for ( int i = 0; i < count; i++ ) {
        arr->ksGetArrayItem( i, pPar );
        ::_stprintf_s( buf, _T("x[%d] = %4.1f, y[%d] = %4.1f"),
                       i, pPar->x, i, pPar->y );
        kompas->ksMessage( buf );
      }


      //  заменить параметры Bezier сплайна
      arr->ksClearArray();
      // подставим свою память
      for ( int i = 0; i < 6; i++ ) {
        pPar->x = x[i];
        pPar->y = y[i];
        arr->ksAddArrayItem( -1, pPar );
      }

      par->style = 2;
      par->closed = 1;

      if ( doc->ksSetObjParam(p, par, ALLPARAM) )
        kompas->ksMessage( _T("Изменили объект") );
      else
        kompas->ksMessageBoxResult();
      arr->ksDeleteArray();
    }
  }
}

//-------------------------------------------------------------------------------
// создать штриховку
//--------------------------------------------------------------------------------
void DrawHatch( ksDocument2DPtr& doc )  {
  doc->ksMtr( 30, 20, 0, 0.5, 0.5 );
  TCHAR buf [128];

  //построить заштрихованный квадрат
  doc->ksLineSeg( 20, 30, 70, 30, 2 );
  doc->ksLineSeg( 70, 30, 70, 80, 2 );
  doc->ksLineSeg( 70, 80, 20, 80, 2 );
  doc->ksLineSeg( 20, 80, 20, 30, 2 );

  if( doc->ksHatch(0, 45, 2, 0, 0, 0) ) {
    doc->ksLineSeg( 20, 30, 70, 30, 2 );
    doc->ksLineSeg( 70, 30, 70, 80, 2 );
    doc->ksLineSeg( 70, 80, 20, 80, 2 );
    doc->ksLineSeg( 20, 80, 20, 30, 2 );
    reference p = doc->ksEndObj();

    //взять параметры штриховки
    ksHatchParamPtr par( kompas->GetParamStruct(ko_HatchParam) );
    if ( par ) {
      par->Init();
      int t = doc->ksGetObjParam( p, par, ALLPARAM);
      ::_stprintf_s( buf, _T("t = %d, tip = %d, angl = %4.1f, shag = %4.1f, \n\n width = %4.1f, x0 = %4.1f, y0 = %4.1f"),
                     t, par->style, par->ang, par->step, par->width, par->x, par->y );
      kompas->ksMessage( buf );
      doc->ksDeleteMtr();

      doc->ksMtr( 0, 0, 0, 2, 2 );

      //заменить параметры штриховки
      par->x = 0.8;

      if  ( doc->ksSetObjParam(p, par, ALLPARAM) )
        kompas->ksMessage( _T("Изменили объект") );
      else
        kompas->ksMessageBoxResult();
      doc->ksDeleteMtr();
    }
  }
  else
    kompas->ksMessageBoxResult();
}

//-------------------------------------------------------------------------------
//
// ---
static void PrintPar1( ksTextLineParamPtr& par2, ksTextItemParamPtr& par3, ksDynamicArrayPtr& arr2 ) {
  TCHAR buf[128];
  ::_stprintf_s( buf, _T("style = %d"), par2->style );
  kompas->ksMessage( buf );

  int count = arr2->ksGetArrayCount();
  for ( int j = 0; j < count; j++ ) {
    arr2->ksGetArrayItem( j, par3 );
    ksTextItemFontPtr font( par3->GetItemFont() );
    if ( font ) {
      ::_stprintf_s( buf, _T("j = %d, h = %5.1f, s = %s \n fontName = %s"), j, font->height, (LPCTSTR)par3->s,
                     (LPCTSTR)font->fontName );
      kompas->ksMessage( buf );
    }
  }
  kompas->ksMessageBoxResult();
}

//-------------------------------------------------------------------------------
//
// ---
void DrawText( ksDocument2DPtr& doc ) {
  ksParagraphParamPtr par ( kompas->GetParamStruct(ko_ParagraphParam) );
  ksTextParamPtr      par1( kompas->GetParamStruct(ko_TextParam)      );
  ksTextLineParamPtr  par2( kompas->GetParamStruct(ko_TextLineParam)  );
  ksTextItemParamPtr  par3( kompas->GetParamStruct(ko_TextItemParam)  );
  if ( par && par1 && par2 && par3 ) {
    par1->Init();
    par2->Init();
    par3->Init();
    par->Init();
    par->x = 30;
    par->y = 30;
    par->height = 25;
    par->width  = 20;

    doc->ksParagraph( par );

    // 4 пример задания дроби и нижнего и верхнего отклонений
    ksTextItemParamPtr itemParam( kompas->GetParamStruct(ko_TextItemParam) );
    if ( itemParam ) {
      itemParam->Init(); 
            
      ksTextItemFontPtr itemFont( itemParam->GetItemFont() );
      if ( itemFont ) {
        itemFont->Init();
         itemFont->SetBitVectorValue( NEW_LINE, true );
        itemParam->s = _T("111");
        doc->ksTextLine( itemParam );

        itemFont->Init();
         itemFont->SetBitVectorValue( NUMERATOR, true );
        itemFont->SetBitVectorValue( ITALIC_ON, true );
        itemParam->s = _T("55");
        doc->ksTextLine( itemParam );

        itemFont->Init();
         itemFont->SetBitVectorValue( DENOMINATOR, true );
        itemParam->s = _T("77");
        doc->ksTextLine( itemParam );

        itemFont->Init();
         itemFont->SetBitVectorValue( END_FRACTION, true );
        itemFont->SetBitVectorValue( BOLD_OFF, true );
        itemFont->SetBitVectorValue( ITALIC_OFF, true );
        itemParam->s = _T("4444");
        doc->ksTextLine( itemParam );
      }
    }

    reference p = doc->ksEndObj();

    // в параметрах текста задействованы два массива неопределенной длины :
    ksDynamicArrayPtr arr1( par1->GetTextLineArr() );   // массив по строкам
    ksDynamicArrayPtr arr2( par2->GetTextItemArr() );   // массив по компонентам строки
    if ( arr1 && arr2 ) {
      // возьмем параметры 1 -ой строки ( индекс 0 )
      doc->ksGetObjParam( p, par2, 0 );

      ::PrintPar1( par2, par3, arr2 );

      if ( kompas->ksYesNo(_T("Изменять параметры текста ?")) ) {
        // у первой строки отключаем ITALIC и BOLD и меняем цвет
        arr2->ksGetArrayItem( 0, par3 );
        ksTextItemFontPtr font( par3->GetItemFont() );
        if ( font ) {
          font->SetBitVectorValue( BOLD_OFF, true );
          font->SetBitVectorValue( ITALIC_OFF, true );
          font->color = RGB(0, 255, 0);
          arr2->ksSetArrayItem( 0, par3 );
          // заменим у тексиа первую строку
          doc->ksSetObjParam( p, par2, 0 );
          //возьмем параметры 1 -ой строки ( индекс 0 )  для проверки
          doc->ksGetObjParam( p, par2, 0 );
          ::PrintPar1( par2, par3, arr2 );
        }
      }
    }
  }
}

