//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "testform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTestSlideDlg *TestSlideDlg;
extern KompasObjectPtr kompas;

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
__fastcall TTestSlideDlg::TTestSlideDlg(TComponent* Owner, ksDocument2DPtr & _doc)
  : TForm(Owner),
  doc ( _doc ),
  gr  ( 0    )
{
	kompasDocName = L"c:\\1.frw";
	IdSlide  = 100;
  if ( (bool)doc && doc->reference ) {
    long gr = doc->ksNewGroup( 1 );
      doc->ksMtr( 20, 15, 45, 1, 1 );
      doc->ksLineSeg( -10, 0,  10,  0,  1 );
      doc->ksLineSeg( 10,  0,  10,  20, 1 );
      doc->ksLineSeg( 10,  20, -10, 20, 1 );
      doc->ksLineSeg( -10, 20, -10, 0,  1 );
      doc->ksDeleteMtr();
    doc->ksEndGroup();
  }
  // для отрисовки слайда из файла ресурса
  resurs   = kompas->ksReadString( TO_OLE(L"Введите имя *.rc файла"),
                                   TO_OLE(L"c:\\4.rc") );
}

//---------------------------------------------------------------------------
__fastcall TTestSlideDlg::~TTestSlideDlg()
{
  if ( gr && (bool)doc )
    doc->ksDeleteObj( gr );
}

//---------------------------------------------------------------------------
void __fastcall TTestSlideDlg::pPreviewBoxPaint(TObject *Sender)
{
//  kompas->ksDrawSlide ( (long)pPreviewPanel->Handle, IdSlide );
//  kompas->ksDrawBitmap( (long)pPreviewPanel->Handle, IdSlide );
//    doc->ksDrawKompasDocument( (long)pPreviewPanel->Handle, kompasDocName );

  doc->ksDrawKompasGroup( (long)pPreviewPanel->Handle, // несущее окно
                           gr );                       // группа

//  Для отладки слайда можно использовать функцию: при изменении файла .rc не нужно
//  перекомпилировать библиотеку
//    if ( !resurs.IsEmpty() )
//      kompas->ksDrawSlideFromFile( (long)pPreviewPanel->Handle, TO_OLE(resurs) );
}
//---------------------------------------------------------------------------

