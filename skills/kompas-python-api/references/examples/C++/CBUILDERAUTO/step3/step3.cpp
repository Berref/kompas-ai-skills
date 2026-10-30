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


extern "C" unsigned int __export __stdcall LIBRARYID()
{
	return 100;
}

KompasObjectPtr kompas;

reference pKeep;

void DrawLayer();
void DrawView();
void DrawGroup();
void DrawLineSeg();
void DrawArc();
void DrawLine();
void DrawPoint();
void DrawCircle();
void DrawBezier();
void DrawHatch();
void DrawText();
void WorkDocument();
void WorkNameGroup();

extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int  comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
    switch ( comm ) {
    case 1: // создать документ
      WorkDocument();
      break;
    case 2: // виды
      DrawView();
      break;
    case 3: // слои
      DrawLayer();
      break;
    case 4: // группы
      DrawGroup();
      break;
    case 5: // именная группа
      WorkNameGroup();
      break;
    case 6: // отрезки
      DrawLineSeg();
      break;
    case 7: // дуги
      DrawArc();
      break;
    case 8: // линии
      DrawLine();
      break;
    case 9: // окружности
      DrawCircle();
      break;
    case 10: // точки
      DrawPoint();
      break;
    case 11: // Bezier-сплайны
      DrawBezier();
      break;
    case 12: // штриховка
      DrawHatch();
      break;
    case 13: // текст
      DrawText();
      break;
    }
    kompas.Unbind();
  }
}


//------------------------------------------------------------------------------
// Создать слой
// ---
void DrawLayer() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/);
  if ( doc ) {
    long n;
    char buf [128];
		if ( !kompas->ksReadInt( TO_OLE(L"Введите номер слоя"), 1, 0, 255, &n) )
      return;


    // создаем слой, слой становится текущим
    reference lay = doc->ksLayer( n );
    doc->ksMtr( 20, 15, 0, 1, 1 );
    doc->ksLineSeg( -10, 0, 10, 0, 1 );
    doc->ksLineSeg( 10, 0, 10, 20, 1 );
    doc->ksLineSeg( 10, 20,  -10, 20, 1 );
    doc->ksLineSeg( -10, 20,  -10, 0, 1 );
    doc->ksDeleteMtr();

    // подсветить слой
    doc->ksLightObj( lay, 1 );

    // получить номер слоя по указателю и указатель по номеру
    int n1 = doc->ksGetLayerNumber( lay );
    reference l = doc->ksGetLayerReference ( n1 );
		::sprintf( buf, "n = %d n1 = %d layer = %ld l = %ld", n, n1, lay, l );
    kompas->ksMessage( TO_OLE(buf) );

    //установить параметры слоя и считать их обратно
    ksLayerParamPtr par ( (ksLayerParam*)kompas->GetParamStruct( ko_LayerParam ), false/*AddRef*/ );
    ksLayerParamPtr par1( (ksLayerParam*)kompas->GetParamStruct( ko_LayerParam ), false/*AddRef*/ );
    if ( (bool)par && (bool)par1 ) {
      par->color = RGB( 0, 255, 0 );
      par->state = stACTIVE;
			par->name  = TO_OLE(L"зеленый");
      doc->ksLayer( 0 );

      if ( !doc->ksSetObjParam( l, par, ALLPARAM) )
        kompas->ksMessageBoxResult();
      else {
				doc->ksGetObjParam( l, par1, ALLPARAM );
        sprintf( buf, " col = %ld col1 = %ld name = %s name1 = %s", par->color,
								 par1->color, WideToAnsi(par->name), WideToAnsi(par1->name) );
        kompas->ksMessage( TO_OLE(buf) );
      }

      doc->ksLightObj( lay, 0 );

      // изменить состояние слоя
      ksLtVariantPtr st( (ksLtVariant*)kompas->GetParamStruct( ko_LtVariant ), false/*AddRef*/ );
      if ( st ) {
        st->intVal = stACTIVE;
        doc->ksSetObjParam( l, st, VIEW_LAYER_STATE );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Создать вид
// ---
void DrawView() {
  ksViewParamPtr par( (ksViewParam*)kompas->GetParamStruct( ko_ViewParam ), false/*AddRef*/ );
  if ( par ) {
    par->Init();
    par->x = 10;
    par->y = 20;
    par->scale_ = 0.5;
    par->angle = 45;
    par->color = RGB( 10, 20, 10 );
    par->state = stACTIVE;
		par->name = TO_OLE(L"user view");

    ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
    if ( doc ) {
      reference gr = doc->ksNewGroup( 0 );
        doc->ksLineSeg( 20, 10, 20, 30, 1 );
        doc->ksLineSeg( 20, 30, 40, 30, 1 );
        doc->ksLineSeg( 40, 30, 40, 10, 1 );
        doc->ksLineSeg( 40, 10, 20, 10, 1 );
      doc->ksEndGroup();

      long number = 5;
      // создали вид
      reference v = doc->ksCreateSheetView( par, &number );
      number = doc->ksGetViewNumber(  v );
      char buf[128];
			sprintf( buf, "создали вид ref = %ld, number = %d", v, number );
      kompas->ksMessage( TO_OLE(buf) );

      doc->ksAddObjGroup( gr, v );
			kompas->ksMessage( TO_OLE(L"добавили вид в группу") );
      kompas->ksMessageBoxResult();

      doc->ksRotateObj( gr, 0, 0, -45 );
      // взять параметры вида
      doc->ksGetObjParam( v, par, ALLPARAM );
      sprintf( buf,"x = %4.1f y = %4.1f, angl = %4.1f name = %s st = %d", par->x,
               par->y, par->angle, WideToAnsi(par->name), par->state );

      kompas->ksMessage( TO_OLE(buf) );
      // сделать текущим системный вид( номер 0 )
      doc->ksOpenView( 0 );


      // изменить состояние слоя
      ksLtVariantPtr st( (ksLtVariant*)kompas->GetParamStruct( ko_LtVariant ), false/*AddRef*/ );
      if ( st ) {
        st->intVal = stREADONLY; // состояние  вида  : только чтение
        doc->ksSetObjParam( v, st, VIEW_LAYER_STATE );
      }
    }
  }
}

//------------------------------------------------------------------------------
// работа с группой
// ---
void DrawGroup() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  if ( doc ) {
    reference p1 = doc->ksLineSeg( 10, 10, 20, 10, 0 );
    reference p2 = doc->ksLineSeg( 10, 10, 10, 20, 0 );

    // создать модельную группу   1
    reference gr1 = doc->ksNewGroup( 0 );
    doc->ksEndGroup();

    // создать модельную группу   2
    reference gr2 = doc->ksNewGroup( 0 );
    doc->ksEndGroup();

    doc->ksAddObjGroup( gr1, p1 );
    doc->ksAddObjGroup( gr1, p2 );

    doc->ksAddObjGroup( gr2, p1 );
    doc->ksAddObjGroup( gr2, p2 );

		kompas->ksMessage( TO_OLE(L"создали группы") );

    doc->ksMoveObj( gr1, 10, 0 );
		kompas->ksMessage( TO_OLE(L"сдвинули группу на 10 ММ") );

    doc->ksRotateObj( gr2, 20, 10, 45 );
		kompas->ksMessage( TO_OLE(L"повернули группу на 45 гр") );

    doc->ksRotateObj( gr2, 20, 10, -45 );
		kompas->ksMessage( TO_OLE(L"повернули группу на -45 гр") );

    doc->ksMoveObj( gr1, -10, 0 );
		kompas->ksMessage( TO_OLE(L"сдвинули группу на -10 ММ") );

    // очистили группу 2 ( объекты исключаются из группы )
    doc->ksClearGroup( gr2, true );
    // удалим  группу 2
    doc->ksDeleteObj( gr2 );


		kompas->ksMessage( TO_OLE(L"подсветили gr") );
    doc->ksLightObj( gr1, 1 );

		kompas->ksMessage( TO_OLE(L"выключили gr") );
    doc->ksLightObj( gr1, 0 );

		kompas->ksMessage( TO_OLE(L"подсветили el") );
    doc->ksLightObj(  p1, 1 );
		kompas->ksMessage( TO_OLE(L"выключили el") );
    doc->ksLightObj(  p1, 0 );

    //удалим  группу 1( объекты удалятся тоже )
    doc->ksDeleteObj( gr1 );
    kompas->ksMessageBoxResult();
  }
}

//------------------------------------------------------------------------------
// создать отрезок
// ---
void DrawLineSeg() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  if ( doc ) {
    // введем локальную систему ккординат
    doc->ksMtr( 30, 20, 45, 1, 1 );
    reference p = doc->ksLineSeg( 30, 20, 60, 20, 1 );

    // взять параметры отрезка
    ksLineSegParamPtr par( (ksLineSegParam*)kompas->GetParamStruct( ko_LineSegParam ), false/*AddRef*/ );
    if ( par ) {
      int t = doc->ksGetObjParam( p, par, ALLPARAM );
      char buf[128];
			sprintf( buf, "t = %d, x1 = %4.1f y1 = %4.1f x2 = %4.1f y2 = %4.1f tl = %d", t,
               par->x1, par->y1, par->x2, par->y2, par->style );

      kompas->ksMessage( TO_OLE(buf) );
      // заменить параметры отрезка
      par->x2    = 30;
      par->y2    = 60;
      par->style = 2;

      if ( doc->ksSetObjParam(p, par, ALLPARAM) )
				kompas->ksMessage( TO_OLE(L"Изменили объект") );
      else
        kompas->ksMessageBoxResult();

      // отключить локальную систему координат
      doc->ksDeleteMtr();
    }
  }
}

//------------------------------------------------------------------------------
// создать дугу
// ---
void DrawArc() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false );
  if ( doc ) {
    // введем локальную систему ккординат
    doc->ksMtr( 30, 20, 45, 1, 1 );
    reference p = doc->ksArcByAngle( 30, 20, 20, 45, 135, 1, 1 );
    // взять параметры дуги  по углам
    ksArcByAngleParamPtr par( (ksArcByAngleParam*)kompas->GetParamStruct( ko_ArcByAngleParam ), false/*AddRef*/ );
    if ( par ) {
      par->Init();
      int t = doc->ksGetObjParam( p, par, ALLPARAM );
      char buf[128];
			sprintf( buf, "t = %d, xc = %4.1f yc = %4.1f rad = %4.1f \n\n a1 = %4.1f a2 = %4.1f napr = %d tl = %d",
               t, par->xc, par->yc, par->rad, par->ang1, par->ang2, par->dir, par->style );
      kompas->ksMessage( TO_OLE(buf) );

      //заменить параметры дуги по точкам
      ksArcByPointParamPtr par1( (ksArcByPointParam*)kompas->GetParamStruct( ko_ArcByPointParam ), false/*AddRef*/ );
      if ( par1 ) {
        par1->Init();
        par1->xc    = 40;
        par1->yc    = 30;
        par1->rad   = 10;
        par1->dir   = 1;
        par1->style = 2;
        par1->x1    = 50;
        par1->y1    = 30;
        par1->x2    = 40;
        par1->y2    = 20;

        if( doc->ksSetObjParam(p, par1, 1) )
					kompas->ksMessage( TO_OLE(L"Изменили объект") );
        else
          kompas->ksMessageBoxResult();
      }
    }

    doc->ksDeleteMtr();
  }
}

//------------------------------------------------------------------------------
// создать вспомогательную линию
// ---
void DrawLine() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  if ( doc ) {
    // введем локальную систему ккординат
    doc->ksMtr( 0, 0, 45, 1, 1 );
    // построить вспомогательную линию
    reference p = doc->ksLine( 30, 20, 0 );

    // взять параметры вспомогательной линии
    ksLineParamPtr par( (ksLineParam*)kompas->GetParamStruct( ko_LineParam ), false/*AddRef*/ );
    if ( par ) {
      int t = doc->ksGetObjParam( p, par, ALLPARAM );
      char buf[128];
      sprintf( buf, "t = %d, x = %4.1f y = %4.1f alf = %4.1f ", t,
               par->x, par->y, par->angle );
      kompas->ksMessage( TO_OLE(buf) );

      // заменить параметры вспомогательной линии
      par->angle = 90;

      if( doc->ksSetObjParam( p, par, ALLPARAM ) )
				kompas->ksMessage( TO_OLE(L"Изменили объект") );
      else
        kompas->ksMessageBoxResult();
    }

    doc->ksDeleteMtr();
  }
}

//------------------------------------------------------------------------------
// создать точку
// 0 -точка,1-крестик,2-х-точка,3-квадрат,4-треугольник,5-окружность,6-звезда,7-перечеркнутый квадрат
// ---
void DrawPoint() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  if ( doc ) {
    // введем локальную систему ккординат
    doc->ksMtr( 10, 10, 0, 1, 1 );
    // построить точку
    reference p = doc->ksPoint( 30, 40, 0 );
    doc->ksPoint( 40, 40, 1 );
    doc->ksPoint( 50, 40, 2 );
    doc->ksPoint( 60, 40, 3 );
    doc->ksPoint( 70, 40, 4 );
    doc->ksPoint( 80, 40, 5 );
    doc->ksPoint( 90, 40, 6 );
    doc->ksPoint( 100, 40, 7 );
    // взять параметры точки
    ksPointParamPtr par( (ksPointParam*)kompas->GetParamStruct( ko_PointParam ), false/*AddRef*/ );
    if ( par ) {
      int t = doc->ksGetObjParam( p, par, ALLPARAM );
      char buf[128];
			::sprintf( buf, "t = %d, x = %4.1f y = %4.1f style = %d ", t,
                 par->x, par->y, par->style );
      kompas->ksMessage( TO_OLE(buf) );

      // заменить параметры точки
      par->x = 20;
      par->y = 30;
      par->style = 7;

      if( doc->ksSetObjParam(p, par, ALLPARAM) )
				kompas->ksMessage( TO_OLE(L"Изменили объект") );
      else
        kompas->ksMessageBoxResult();
    }

    doc->ksDeleteMtr();
  }
}

//------------------------------------------------------------------------------
// создать окружность
// ---
void DrawCircle() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  if ( doc ) {
    // введем локальную систему ккординат
    doc->ksMtr( 0, 0, 0, 2, 2 );
    char buf [128];
    // построить окружность
    reference p = doc->ksCircle( 30, 20, 10, 1 );

    // взять параметры олружности
    ksCircleParamPtr par( (ksCircleParam*)kompas->GetParamStruct( ko_CircleParam ), false/*AddRef*/ );
    if ( par ) {
      int t = doc->ksGetObjParam( p, par, ALLPARAM );
			sprintf( buf, " t = %d, xc = %4.1f yc = %4.1f rad = %4.1f tl = %d ",t,
               par->xc, par->yc, par->rad, par->style );
      kompas->ksMessage( TO_OLE(buf) );

      // заменить параметры окружности
      par->rad = 20;
      par->style = 2;
      if( doc->ksSetObjParam(p, par, ALLPARAM) )
				kompas->ksMessage( TO_OLE(L"Изменили объект") );
      else
        kompas->ksMessageBoxResult();
    }

    doc->ksDeleteMtr();
  }
}

//------------------------------------------------------------------------------
// создать Bezier сплайн
// ---
void DrawBezier() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  if ( doc ) {
    double x[] = { 0, 20, 50, 70, 100, 50 };
    double y[] = { 0, 20, 10, 20, 0,  -50 };

    // построить Bezier сплайн
    doc->ksBezier( 0, 1 );
    for ( int i = 0; i < 5; i++ )
      doc->ksPoint( x[i], y[i], 0 );

    reference p = doc->ksEndObj();
    // взять параметры Bezier сплайна

    ksMathPointParamPtr pPar( (ksMathPointParam*)kompas->GetParamStruct ( ko_MathPointParam ), false/*AddRef*/);
    ksBezierParamPtr    par ( (ksBezierParam*)   kompas->GetParamStruct ( ko_BezierParam    ), false/*AddRef*/);
    ksDynamicArrayPtr   arr ( (ksDynamicArray*)  kompas->GetDynamicArray( POINT_ARR         ), false/*AddRef*/);
    if ( (bool)pPar && (bool)par && (bool)arr ) {
      par->SetMathPointArr( arr );
      int t = doc->ksGetObjParam( p, par, ALLPARAM );
      int count = arr->ksGetArrayCount();
      char buf[128];
			::sprintf( buf, " t = %d, count = %d close = %d tl = %d ", t, count, par->closed, par->style );
      kompas->ksMessage( TO_OLE(buf) );
      for ( int i = 0; i < count; i++ ) {
        arr->ksGetArrayItem( i,/*индекс в массиве*/ pPar/*структура элемента*/ );
        ::sprintf( buf, "x[%d] = %4.1f y[%d] = %4.1f", i, pPar->x, i, pPar->y );
        kompas->ksMessage( TO_OLE(buf) );
      }

      // заменить параметры Bezier сплайна
      arr->ksClearArray();
      // подставим свою память
      for ( int i = 0; i < 6; i++ ) {
        pPar->x = x[i];
        pPar->y = y[i];
        arr->ksAddArrayItem( -1,/*индекс в массиве - в конец*/ pPar/*указатель на структуру элемента*/ );
      }

      par->style = 2;
      par->closed = 1;

      if ( doc->ksSetObjParam(p, par, ALLPARAM) )
				kompas->ksMessage( TO_OLE(L"Изменили объект") );
      else
        kompas->ksMessageBoxResult();

      arr->ksDeleteArray();
    }
  }
}

//------------------------------------------------------------------------------
// создать штриховку
// ---
void DrawHatch() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  if ( doc ) {
    doc->ksMtr( 30, 20, 0, 0.5, 0.5 );
    // построить заштрихованный квадрат
    doc->ksLineSeg( 20, 30, 70, 30, 2 );
    doc->ksLineSeg( 70, 30, 70, 80, 2 );
    doc->ksLineSeg( 70, 80, 20, 80, 2 );
    doc->ksLineSeg( 20, 80, 20, 30, 2 );
    reference p = 0;
    if ( doc->ksHatch(0, 45, 2, 0, 0, 0) ) {
      doc->ksLineSeg( 20, 30, 70, 30, 2 );
      doc->ksLineSeg( 70, 30, 70, 80, 2 );
      doc->ksLineSeg( 70, 80, 20, 80, 2 );
      doc->ksLineSeg( 20, 80, 20, 30, 2 );
      p = doc->ksEndObj();
    }

    // взять параметры штриховки
    ksHatchParamPtr par( (ksHatchParam*)kompas->GetParamStruct( ko_HatchParam ), false/*AddRef*/ );
    if ( par ) {
      int t = doc->ksGetObjParam( p, par, ALLPARAM );
      char buf[128];
			sprintf( buf, " t = %d, tip = %d angl = %4.1f shag = %4.1f \n\n width = %4.1f x0 = %4.1f y0 = %4.1f ",
               t, par->style, par->ang, par->step, par->width, par->x, par->y );
      kompas->ksMessage( TO_OLE(buf) );
    }

    doc->ksDeleteMtr();
    doc->ksMtr( 0, 0, 0, 2, 2 );
    // заменить параметры штриховки
    par->x = 0.8;

    if( doc->ksSetObjParam(p, par, ALLPARAM) )
			kompas->ksMessage( TO_OLE(L"Изменили объект") );
    else
      kompas->ksMessageBoxResult();

    doc->ksDeleteMtr();
  }
}

//------------------------------------------------------------------------------
//
// ---
static void PrintPar1( ksTextLineParamPtr & par ) {
  char buf[128];
	::sprintf( buf, "style = %d", par->style );
  kompas->ksMessage( TO_OLE(buf) );
  ksDynamicArrayPtr arr( (ksDynamicArray*)par->GetTextItemArr(), false/*AddRef*/ );
  ksTextItemParamPtr itemPar( (ksTextItemParam*)kompas->GetParamStruct( ko_TextItemParam ), false/*AddRef*/ );
  if ( (bool)arr && (bool)itemPar ) {
    for ( int j = 0; j < arr->ksGetArrayCount(); j++ ) {
      arr->ksGetArrayItem( j, itemPar );
      ksTextItemFontPtr font( (ksTextItemFont*)itemPar->GetItemFont(), false/*AddRef*/ );
      if ( font ) {
				sprintf( buf, "j = %d h = %5.1f  s = %s \n fontName = %s ", j, font->height, WideToAnsi(itemPar->s),
								 WideToAnsi(font->fontName) );
        kompas->ksMessage( TO_OLE(buf) );
      }
    }
	}

  kompas->ksMessageBoxResult();
}

//------------------------------------------------------------------------------
//
// ---
void DrawText() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  ksParagraphParamPtr par( (ksParagraphParam*)kompas->GetParamStruct( ko_ParagraphParam ), false/*AddRef*/ );
  if ( (bool)doc && (bool)par )
  {
    ksTextStyleParamPtr textStPar( (ksTextStyleParam*)kompas->GetParamStruct(ko_TextStyleParam), false/*AddRef*/ );
    if ( textStPar ) {
      // Создаем его на основе стиля по умолчанию
      doc->ksGetStyleParam(1, 0, textStPar);
      textStPar->name = WideString( WideString(L"Text") + WideString(100) ).c_bstr();
      textStPar->height = 20;
      textStPar->step = 15;
      textStPar->posKS = 0.;
  //    textStPar->align = ksLEFT;
      // Создаем пользовательский стиль текста
      // П.2 здесь получаем сообщение о неверной структуре параметров
      /*CurrentStyle = */doc->ksAddStyle(TEXT_STYLE, textStPar, 0); // в ручную  */
    }


    par->Init();
    par->style   = 0;
    par->x       = 30;
    par->y       = 30;
    par->ang     = 0;
    par->hFormat = 0;
    par->vFormat = 0;
    par->height  = 25;
    par->width   = 20;

    doc->ksParagraph( par );

    ksTextItemParamPtr item( (ksTextItemParam*)kompas->GetParamStruct( ko_TextItemParam ), false/*AddRef*/ );
    if ( item ) {
      // 5  пример задания дроби
      item->Init();
			item->s = TO_OLE(L"111");
      ksTextItemFontPtr font( (ksTextItemFont*)item->GetItemFont(), false/*AddRef*/ );
      if ( font ) {
        font->SetBitVectorValue( NEW_LINE, true );
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( NUMERATOR, true );
        font->SetBitVectorValue( ITALIC_ON, true );
        item->type = FRACTION_TYPE;
				item->s = TO_OLE(L"222");
        item->iSNumb = 2;
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( DENOMINATOR, true );
        font->SetBitVectorValue( BOLD_ON,     true );
        item->s = TO_OLE(L"333");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( END_FRACTION, true );
        font->SetBitVectorValue( BOLD_OFF,     true );
        font->SetBitVectorValue( ITALIC_OFF,   true );
				item->s = TO_OLE(L"444");
        doc->ksTextLine( item );

/*
//4 пример задания дроби и нижнего и верхнего отклонений

        item->Init();
        font->SetBitVectorValue( NEW_LINE, true );
        item->s = TO_OLE(L"111");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( NUMERATOR, true );
        font->SetBitVectorValue( ITALIC_ON, true );
        item->s = TO_OLE(L"55");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( S_BASE, true );
        item->s = TO_OLE(L"222");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( S_UPPER_INDEX, true );
        item->s = TO_OLE(L"up");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( S_LOWER_INDEX, true );
        item->s = TO_OLE(L"lo");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( S_END, true );
        item->s = TO_OLE(L"66");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( DENOMINATOR, true );
        item->s = TO_OLE(L"77");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( END_FRACTION, true );
        font->SetBitVectorValue( BOLD_OFF,     true );
        font->SetBitVectorValue( ITALIC_OFF,   true );
        item->s = TO_OLE(L"4444");
        doc->ksTextLine( item );
*/
/*
//3 пример задания спецсимвола
        item->Init();
        font->SetBitVectorValue( NEW_LINE, true );
        item->s = TO_OLE(L"111");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( SPECIAL_SYMBOL, true );
        item->type   = SPECIAL;
        item->iSNumb = 41;
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( SPECIAL_SYMBOL_END, true );
        item->s = TO_OLE(L"222");
        doc->ksTextLine( item );
*/
/*
//1
        item->Init();
        font->SetBitVectorValue( NEW_LINE,  true );
        font->SetBitVectorValue( NUMERATOR, true );
        item->s = TO_OLE(L"111");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( FONT_SYMBOL,  true );
        item->type   = FONT_NAME;
        item->s = TO_OLE(L"Arial");
        item->iSNumb = 64;
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( DENOMINATOR,  true );
        item->s = TO_OLE(L"222");
        doc->ksTextLine( item );

        item->Init();
        font->SetBitVectorValue( END_FRACTION,  true );
        doc->ksTextLine( item );
*/
        reference p = doc->ksEndObj();

        ksTextParamPtr par1( (ksTextParam*)kompas->GetParamStruct( ko_TextParam ), false/*AddRef*/ );
        if ( par1 ) {
          par1->Init();
          ksTextLineParamPtr linePar( (ksTextLineParam*)kompas->GetParamStruct( ko_TextLineParam ), false/*AddRef*/ );
          if ( linePar ) {
            // возьмем параметры 1 -ой строки ( индекс 0 )
            doc->ksGetObjParam( p, linePar, 0 );

            PrintPar1( linePar );
						if ( kompas->ksYesNo( TO_OLE(L"Изменять параметры текста ?") ) ) {
              ksDynamicArrayPtr arr( (ksDynamicArray*)linePar->GetTextItemArr(), false/*AddRef*/ );
              if ( arr ) {
                // у первой строки отключаем ITALIC и BOLD и меняем цвет
                arr->ksGetArrayItem( 0, item );
                font.Bind( (ksTextItemFont*)item->GetItemFont(), false );
                font->SetBitVectorValue( ITALIC_OFF, false );
                font->SetBitVectorValue( BOLD_OFF,   false );
                font->color = RGB( 0, 255, 0 );

                arr->ksSetArrayItem( 0, item );
                // заменим у тексиа первую строку
                doc->ksSetObjParam( p, linePar, 0 );
                // возьмем параметры 1 -ой строки ( индекс 0 )  для проверки
                doc->ksGetObjParam( p, linePar, 0 );
                PrintPar1( linePar );
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// работа с документом
// ---
void WorkDocument() {
  ksDocumentParamPtr docPar ( (ksDocumentParam*)kompas->GetParamStruct( ko_DocumentParam ), false/*AddRef*/ );
  ksDocumentParamPtr docPar2( (ksDocumentParam*)kompas->GetParamStruct( ko_DocumentParam ), false/*AddRef*/ );
  if ( (bool)docPar && (bool)docPar2 ) {
    docPar->Init();
		docPar->fileName = TO_OLE(L"d:\\gr\\2.cdw");
		docPar->comment  = TO_OLE(L"create document");
		docPar->author   = TO_OLE(L"user");
    docPar->regime   = 0;
    docPar->type     = lt_DocSheetStandart;

    ksSheetParPtr sheet( (ksSheetPar*)docPar->GetLayoutParam(), false/*AddRef*/ );
    sheet->shtType       = 1;
    sheet->layoutName[0] = '\0';

    ksStandartSheetPtr stSheet( (ksStandartSheet*)sheet->GetSheetParam(), false/*AddRef*/ );

    stSheet->format   = 3;
    stSheet->multiply = 1;
    stSheet->direct   = 0;
    // создали документ: лист, формат А3, горизонтально расположенный
    // и с системным штампом 1
    ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
    if ( (bool)doc && doc->ksCreateDocument(docPar) ) {
      ksViewParamPtr par( (ksViewParam*)kompas->GetParamStruct( ko_ViewParam ), false/*AddRef*/ );
      if ( par ) {
        par->x = 10;
        par->y = 20;
        par->scale_ = 0.5;
        par->angle = 45;
        par->color = RGB(10,20,10);
        par->state = stACTIVE;
				par->name  = TO_OLE(L"user view");
        long number = 2;
        // у документа создадим вид с номером 2, масштабом 0.5, под углом 45 гр
        doc->ksCreateSheetView( par, &number );
        // создадим слой с номером 5
        doc->ksLayer( 5 );

        doc->ksLineSeg( 20, 10, 40, 10, 1 );
        doc->ksLineSeg( 40, 10, 40, 30, 1 );
        doc->ksLineSeg( 40, 30, 20, 30, 1 );
        doc->ksLineSeg( 20, 30, 20, 10, 1 );

				kompas->ksMessage( TO_OLE(L"нарисовали") );

        // получить параметры документа
        doc->ksGetObjParam( doc->reference, docPar2, ALLPARAM );
        char buf[128];

        ksSheetParPtr      sheet2  ( (ksSheetPar*)    docPar2->GetLayoutParam(),   false/*AddRef*/ );
        ksStandartSheetPtr stSheet2( (ksStandartSheet*)sheet2->GetSheetParam() ,   false/*AddRef*/ );

        if ( (bool)sheet2 && (bool)stSheet2 ) {
          sprintf( buf, "type = %d f = %d m = %d d = %d", docPar->type, stSheet2->format,
                   stSheet2->multiply, stSheet2->direct ? 1 : 0 );

          kompas->ksMessage( TO_OLE(buf) );
        }

        kompas->ksMessage( docPar2->fileName );
        kompas->ksMessage( docPar->comment );
        kompas->ksMessage( docPar->author );

        // сохраним документ
				doc->ksSaveDocument( TO_OLE(L"") );
        // закрыть документ
        doc->ksCloseDocument();
      }
    }
  }
}

//------------------------------------------------------------------------------
// работа с именнованной группой
// ---
void WorkNameGroup() {
  ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
  if ( doc ) {
    // рабочая группа сущестует  до конца работы  функции
    reference gr = doc->ksNewGroup( 0 );
      doc->ksLineSeg( 20, 20, 40, 20, 1 );
      doc->ksLineSeg( 40, 20, 40, 40, 1 );
      doc->ksLineSeg( 40, 40, 20, 40, 1 );
      doc->ksLineSeg( 20, 40, 20, 20, 1 );
    doc->ksEndGroup();

    // рабочую группу сохраняем в именной
    // именная группа хранится в документе и
		if( !doc->ksSaveGroup( gr, TO_OLE(L"group1") ) )
      exit( EXIT_SUCCESS );

		reference gr1 = doc->ksGetGroup( TO_OLE(L"group1") );
    if( !gr1 )
      exit(EXIT_SUCCESS);

    reference c = doc->ksCircle( 30, 30, 10, 1 );
    doc->ksAddObjGroup( gr1, c );

    doc->ksLightObj( gr1, 1 );
		kompas->ksMessage( TO_OLE(L"добавили объект в именную группу") );
    doc->ksLightObj( gr1, 0 );
  }
}


