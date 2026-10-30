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


//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch* far __export WINAPI CreateKompasObject();

//------------------------------------------------------------------------------
//
// ---
#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  return 1;
}

//------------------------------------------------------------------------------
//
// ---
extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return 100;
}

//------------------------------------------------------------------------------
//
// ---
void DrawPoint( ksDocument2DPtr & doc, ksDynamicArrayPtr & arr, KompasObjectPtr & kompas ) {
  if ( (bool)doc && (bool)arr && (bool)kompas ) {
    ksMathPointParamPtr point( (ksMathPointParam*)kompas->GetParamStruct( ko_MathPointParam ), false/*AddRef*/ );
    if ( point ) {
      char buf[128];
      for ( int i = 0, count = arr->ksGetArrayCount(); i < count; i++ ) {
        arr->ksGetArrayItem( i, point );
        sprintf( buf, "Точка %i: kp = %d xp = %6.2f yp = %6.2f ", i + 1, arr->ksGetArrayCount(), point->x, point->y );
        kompas->ksMessage( TO_OLE(buf) );
        doc->ksPoint( point->x, point->y, 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
//
// ---
void DrawPoint_Line( ksDocument2DPtr & doc, ksDynamicArrayPtr & arr, KompasObjectPtr & kompas, ksMathematic2D * math, double angle ) {
  if ( (bool)doc && (bool)arr && (bool)kompas ) {
    ksMathPointParamPtr point( (ksMathPointParam*)kompas->GetParamStruct( ko_MathPointParam ), false/*AddRef*/ );
    if ( point ) {
      char buf[128];
      for ( int i = 0, count = arr->ksGetArrayCount(); i < count; i++ ) {
        arr->ksGetArrayItem( i, point );
        sprintf( buf, "Точка %i: kp = %d xp = %6.2f yp = %6.2f ", i + 1, arr->ksGetArrayCount(), point->x, point->y );
        kompas->ksMessage( TO_OLE(buf) );
        doc->ksPoint( point->x, point->y, 0 );
        if ( math )
          doc->ksLine( 10, 50, math->ksAngle(10, 50, point->x, point->y) );
        else
          doc->ksLine( point->x, point->y, angle );
      }
    }
  }
}


//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  KompasObjectPtr kompas( IDispatchPtr(::CreateKompasObject(), false/*AddRef*/));
  if ( kompas ) {
    ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/);
		ksMathematic2DPtr math( (ksMathematic2D*)kompas->GetMathematic2D(), false/*AddRef*/);
    if ( (bool)doc && (bool)math ) {
      char buf[128];
      switch ( comm ) {
        case 1 : { // пересечь прямые
          int kp;
					double x,y;
          doc->ksLine( 10,10, 0 );
          doc->ksLine( 15, 5, 90 );
          ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( POINT_ARR ), false/*AddRef*/ );
          if ( arr ) {
            math->ksIntersectLinLin( 10, 10, 0, 15, 5, 90, arr );
            ::DrawPoint( doc, arr, kompas );
          }
        }

        break;

        case 2 : {    // пересечь кривые
          reference pp1, pp2;
          int i, kp;
          double xp[2], yp[2];
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

          ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( POINT_ARR ), false/*AddRef*/ );
          if ( arr ) {
            math->ksIntersectCurvCurv( pp1, pp2, arr );
            ::DrawPoint( doc, arr, kompas );
          }
        }

        break;

        case 3 : { // пересечь отрезок и дугу
          int i;
          doc->ksLineSeg( 0, 40, 100, 40, 1 );
          doc->ksArcByPoint( 50, 40, 20, 30, 40, 70, 40, 1, 1 );
          ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( POINT_ARR ), false/*AddRef*/ );
          if ( arr ) {
            math->ksIntersectLinSArc( 0, 40,   // первая точка отрезка
                                      100, 40, // вторая точка отрезка
                                      50, 40,  // центр дуги
                                      20,      // радиус дуги
                                      math->ksAngle(50, 40, 30, 40), // начальный  и конечный угол дуги
                                      math->ksAngle(50, 40, 70, 40),
                                      1,       // направление дуги
                                      arr );   // массив точек пересечения
            ::DrawPoint( doc, arr, kompas );
          }
          break;
        }

        case 4 : { // касательная из точки
          doc->ksPoint( 10, 50, 0 );
          doc->ksCircle( 50, 10, 40, 1 );
          ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( POINT_ARR ), false/*AddRef*/ );
          if ( arr ) {
            math->ksTanLinePointCircle( 10, 50,
                                        50, 10, 40,
                                        arr );
            ::DrawPoint_Line( doc, arr, kompas, math, 0 );
          }
        }
        break;

        case 5: { // касательная под углом
          doc->ksCircle( 50, 10, 40, 1 );
          ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray( POINT_ARR ), false/*AddRef*/ );
          if ( arr ) {
            math->ksTanLineAngCircle( 50, 10, 40, -45, arr );
            ::DrawPoint_Line( doc, arr, kompas, NULL, -45 );
          }
        }

        break;

        case 6: { // поворот точки
          double x, y;
          math->ksRotate( 60, 50, 50, 50, 180, &x, &y );
          ::sprintf( buf,"x = %4.2f y = %4.2f", x, y );
          kompas->ksMessage( TO_OLE(buf) );
        }

        break;

        case 7: { // симметрия точки
          double x, y;
          math->ksSymmetry( 55, 60, 60, 50, 50, 50,  &x, &y );

          ::sprintf( buf, "x = %4.2f y = %4.2f  ", x, y );
					kompas->ksMessage( TO_OLE(buf) );
        }

        break;

        case 8: { // сопрягающие окружности к двум прямым
          double rad = 20;
          ksCONPtr con( (ksCON*)kompas->GetParamStruct( ko_CON ), false/*AddRef*/ );
          if ( con ) {
            math->ksCouplingLineLine( 100,100,45,  // первая прямая
                                      100,100,-45, // вторая прямая
                                      rad, con );
            doc->ksLine( 100, 100, 45);
            doc->ksLine( 100, 100, -45);

            for ( short i = 0 ; i < 4; i++ ) {
              doc->ksCircle( con->GetXc(i), con->GetYc(i), rad, 2 );
              doc->ksPoint( con->GetX1(i), con->GetY1(i), i );
              doc->ksPoint( con->GetX2(i), con->GetY2(i), i );
            }
					}
        }

        break;

        case 9: {  // перепендикуляр
          double xp, yp;
          math->ksPerpendicular( 50, 50, 60, 10, 100, 10, &xp, &yp );
          ::sprintf( buf," xp = %4.3f yp = %4.3f", xp, yp );
          kompas->ksMessage( TO_OLE(buf) );
        }
        break;

      }
    }
  }
}
