//////////////////////////////////////////////////////////////////////////////// 
// 
// step2.cpp - ћатематика
// 
// 1. ѕересечь пр€мые                      - Intersect2Line
// 2. ѕересечь кривые                      - Intersect2Curve
// 3. ѕересечь отрезок и дугу              - IntersectLineSegArc
// 4.  асательна€ из точки                 - TanLinePointCircle
// 5.  асательна€ под углом                - TanLineAngCircle
// 6. ѕоворот точки                        - RotatePoint
// 7. —имметри€ точки                      - SymmetryPoint
// 8. —опр€гающие окружности к двум пр€мым - Couplin2Lines
// 9. ѕерепендикул€р                       - Perpendicular
// 
//////////////////////////////////////////////////////////////////////////////// 
#include "stdafx.h"
#include "step2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStep2App

BEGIN_MESSAGE_MAP(CStep2App, CWinApp)
  //{{AFX_MSG_MAP(CStep2App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep2App construction

CStep2App::CStep2App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep2App object

CStep2App    theApp;
KompasObjectPtr kompas( NULL );

void Intersect2Line( ksDocument2DPtr& doc, ksMathematic2DPtr& mat );
void Intersect2Curve( ksDocument2DPtr& doc, ksMathematic2DPtr& mat );
void IntersectLineSegArc( ksDocument2DPtr& doc, ksMathematic2DPtr& mat );
void TanLinePointCircle( ksDocument2DPtr& doc, ksMathematic2DPtr& mat );
void TanLineAngCircle( ksDocument2DPtr& doc, ksMathematic2DPtr& mat );
void RotatePoint( ksMathematic2DPtr& mat );
void SymmetryPoint( ksMathematic2DPtr& mat );
void Couplin2Lines( ksDocument2DPtr& doc, ksMathematic2DPtr& mat );
void Perpendicular( ksMathematic2DPtr& mat );

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
// »дентификатор ресурсов библиотеки
// ---
unsigned int WINAPI LIBRARYID(){
  return IDS_LIBID;
}

//-------------------------------------------------------------------------------
// LIBRARYENTRY
// ---
void WINAPI LIBRARYENTRY( unsigned int comm ) {
  // по умолчанию ресурсы берутс€ из .exe файла, дл€ того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  GetKompas();
  if ( kompas ) {
    ksDocument2DPtr doc( kompas->ActiveDocument2D() );
    ksMathematic2DPtr mat( kompas->GetMathematic2D() );
    if ( doc && doc->reference ) {
      switch ( comm ) {
      case 1  : ::Intersect2Line( doc, mat );      break; // пересечь пр€мые
      case 2  : ::Intersect2Curve( doc, mat );     break; // пересечь кривые
      case 3  : ::IntersectLineSegArc( doc, mat ); break; // пересечь отрезок и дугу
      case 4  : ::TanLinePointCircle( doc, mat );  break; // касательна€ из точки
      case 5  : ::TanLineAngCircle( doc, mat );    break; // касательна€ под углом
      case 6  : ::RotatePoint( mat );              break; // поворот точки
      case 7  : ::SymmetryPoint( mat );             break; // симметри€ точки
      case 8  : ::Couplin2Lines( doc, mat );       break; // сопр€гающие окружности к двум пр€мым
      case 9  : ::Perpendicular( mat );             break; // перепендикул€р
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawPoints( ksDocument2DPtr& doc, ksDynamicArrayPtr& arr ) {
  ksMathPointParamPtr par( kompas->GetParamStruct(ko_MathPointParam) );
  if ( par ) {
    int count = arr->ksGetArrayCount();
    TCHAR buf[255];
    ::_stprintf_s( buf, _T("найдено пересечений: %d,"), count );
    kompas->ksMessage( buf );
    for ( int i = 0; i < count; i++ ) {
      if ( arr->ksGetArrayItem(i, par) ) {
        ::_stprintf_s( buf, _T("точка: %d, x=%4.2f, y=%4.2f "), i, par->x, par->y );
        kompas->ksMessage( buf );
        doc->ksPoint( par->x, par->y, 0 );
      }
    }
  }
}

//-------------------------------------------------------------------------------
// пересечь пр€мые
// ---
void Intersect2Line( ksDocument2DPtr& doc, ksMathematic2DPtr& mat ) {
  doc->ksLine( 10,10, 0 );
  doc->ksLine( 15, 5, 90 );

  ksDynamicArrayPtr arr( kompas->GetDynamicArray(POINT_ARR) );
  if ( arr && mat->ksIntersectLinLin(10, 10, 0, 15, 5, 90, arr) ) 
    ::DrawPoints( doc, arr );
}

//-------------------------------------------------------------------------------
// пересечь кривые
// ---
void Intersect2Curve( ksDocument2DPtr& doc, ksMathematic2DPtr& mat ) {
  reference pp1, pp2;
  doc->ksBezier( 0, 0 );
    doc->ksPoint( 0,  10, 0 );
    doc->ksPoint( 10, 20, 0 );
    doc->ksPoint( 20, 10, 0 );
    doc->ksPoint( 10, 0,  0 );
    doc->ksPoint( 0,  10, 0 );
  pp1 = doc->ksEndObj();
  doc->ksMtr( 0, 10, 0, 1, 1 );
  doc->ksBezier( 0, 0 );
    doc->ksPoint( 0,  10, 0 );
    doc->ksPoint( 10, 20, 0 );
    doc->ksPoint( 20, 10, 0 );
    doc->ksPoint( 10, 0,  0 );
    doc->ksPoint( 0,  10, 0 );
  pp2 = doc->ksEndObj();
  doc->ksDeleteMtr();

  ksDynamicArrayPtr arr( kompas->GetDynamicArray(POINT_ARR) );
  if ( arr && mat->ksIntersectCurvCurv(pp1, pp2, arr) ) 
    ::DrawPoints( doc, arr );
}

//-------------------------------------------------------------------------------
// пересечь отрезок и дугу
// ---
void IntersectLineSegArc( ksDocument2DPtr& doc, ksMathematic2DPtr& mat ) {
  doc->ksLineSeg( 0, 40, 100, 40, 1 );
  doc->ksArcByPoint( 50, 40, 20, 30, 40, 70, 40, 1, 1 );

  ksDynamicArrayPtr arr( kompas->GetDynamicArray(POINT_ARR) );
  if ( arr  
        && mat->ksIntersectLinSArc( 0, 40,                       // перва€ точка отрезка
                                   100, 40,                     // втора€ точка отрезка
                                   50, 40,                      // центр дуги
                                   20,                          // радиус дуги
                                   mat->ksAngle(50, 40, 30, 40), // начальный  и конечный угол дуги
                                   mat->ksAngle(50, 40, 70, 40), 
                                   1,                           // направление дуги
                                   arr) )                       // массив точек пересечени€
    ::DrawPoints( doc, arr );
}

//-------------------------------------------------------------------------------
//
// ---
void DrawPointsAndLines( ksDocument2DPtr& doc, ksDynamicArrayPtr& arr, ksMathematic2DPtr& mat ) {
  ksMathPointParamPtr par( kompas->GetParamStruct(ko_MathPointParam) );
  if ( par ) {
    int count = arr->ksGetArrayCount();
    TCHAR buf[255];
    ::_stprintf_s( buf, _T("найдено касаний: %d,"), count );
    kompas->ksMessage( buf );
    for ( int i = 0; i < count; i++ ) {
      if ( arr->ksGetArrayItem(i, par) ) {
        ::_stprintf_s( buf, _T("точка: %d, x=%4.2f, y=%4.2f"), i, par->x, par->y );
        kompas->ksMessage( buf );
        doc->ksPoint( par->x, par->y, 0 );
        doc->ksLine( 10, 50, mat->ksAngle(10, 50, par->x, par->y) );
      }
    }
  }
}

//-------------------------------------------------------------------------------
// касательна€ из точки
// ---
void TanLinePointCircle( ksDocument2DPtr& doc, ksMathematic2DPtr& mat ) {
  doc->ksPoint( 10, 50, 0 );
  doc->ksCircle( 50, 10, 40, 1 );

  ksDynamicArrayPtr arr( kompas->GetDynamicArray(POINT_ARR) );
  if ( arr && mat->ksTanLinePointCircle( 10, 50, 50, 10, 40, arr) ) // массив точек пересечени€
    ::DrawPointsAndLines( doc, arr, mat );
}

//-------------------------------------------------------------------------------
//
// ---
void DrawPointsAndLines1( ksDocument2DPtr & doc, ksDynamicArrayPtr& arr, ksMathematic2DPtr& mat ) {
  ksMathPointParamPtr par( kompas->GetParamStruct(ko_MathPointParam) );
  if ( par ) {
    int count = arr->ksGetArrayCount();
    TCHAR buf[255];
    ::_stprintf_s( buf, _T("найдено касаний: %d,"), count );
    kompas->ksMessage( buf );
    for ( int i = 0; i < count; i++ ) {
      if ( arr->ksGetArrayItem(i, par) ) {
        ::_stprintf_s( buf, _T("точка: %d, x=%4.2f, y=%4.2f"), i, par->x, par->y );
        kompas->ksMessage( buf );
        doc->ksPoint( par->x, par->y, 0 );
        doc->ksLine( par->x, par->y, -45 );
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void TanLineAngCircle( ksDocument2DPtr& doc, ksMathematic2DPtr& mat ) {
  doc->ksCircle( 50, 10, 40, 1 );
  ksDynamicArrayPtr arr( kompas->GetDynamicArray(POINT_ARR) );
  if ( arr && mat->ksTanLineAngCircle( 50, 10, 40, -45, arr) ) // массив точек пересечени€
    ::DrawPointsAndLines1( doc, arr, mat );
}

//-------------------------------------------------------------------------------
//
// ---
void RotatePoint( ksMathematic2DPtr& mat ) {
  double x, y;
  mat->ksRotate( 60, 50, 50, 50, 180, &x, &y );

  TCHAR buf[255];
  ::_stprintf_s( buf,_T("x=%4.2f, y=%4.2f"), x, y );
  kompas->ksMessage( buf );
}

//-------------------------------------------------------------------------------
//
// ---
void SymmetryPoint( ksMathematic2DPtr& mat ) {
  double x, y;
  mat->ksSymmetry( 55, 60, 60, 50, 50, 50,  &x, &y );

  TCHAR buf[255];
  ::_stprintf_s( buf,_T("x=%4.2f, y=%4.2f"), x, y );
  kompas->ksMessage( buf );
}

//-------------------------------------------------------------------------------
//
// ---
void Couplin2Lines( ksDocument2DPtr& doc, ksMathematic2DPtr& mat ) {
  ksCONPtr con( kompas->GetParamStruct(ko_CON) );
  double rad = 20;
  if ( con && mat->ksCouplingLineLine(100, 100, 45,  // перва€ пр€ма€
                                      100, 100, -45, // втора€ пр€ма€
                                      rad, con) ) 
  {

    doc->ksLine( 100, 100, 45  );
    doc->ksLine( 100, 100, -45 );
    for ( int i = 0, count = con->GetCount(); i < count; i++ ) {
      doc->ksCircle( con->GetXc(i), con->GetYc(i), rad, 2 );
      doc->ksPoint ( con->GetX1(i), con->GetY1(i), i );
      doc->ksPoint ( con->GetX2(i), con->GetY2(i), i );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Perpendicular( ksMathematic2DPtr& mat ) {
  double xp, yp;
  mat->ksPerpendicular( 50, 50, 60, 10, 100, 10, &xp, &yp);
  TCHAR buf[255];
  ::_stprintf_s( buf,_T("xp=%4.3f, yp=%4.3f"), xp, yp );
  kompas->ksMessage( buf );
}
