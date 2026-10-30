////////////////////////////////////////////////////////////////////////////////
// Контроллер
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include <utilcls.h>
#include <systobj.h>

#ifdef __LIGHT_VERSION__
#include <Kl_TLB.h>
#else
#include <Ks_TLB.h>
#endif

#include <ldefin2d.h>
#include <ksConstants.h>

#include "blprj.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


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
  inline wchar_t * TO_OLE(wchar_t *x) { return WideString::Copy(x); }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).Copy(); }
  inline wchar_t * TO_OLE(WideString & x) { return x.Copy(); }
#endif

TForm1 *Form1;
KompasObjectPtr kompas;
int  libraryId = 0; // HANDLE загруженной библиотеки

//---------------------------------------------------------------------------
// Конструктор
// ---
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
// загрузить Компас
// ---
void __fastcall TForm1::btLoadGraphicClick(TObject *Sender)
{
  if ( !kompas ) {
#ifdef __LIGHT_VERSION__
    kompas.CreateInstance( L"KOMPASLT.Application.5" );
#else
    kompas.CreateInstance( L"KOMPAS.Application.5" );
#endif
    if ( kompas ) {
      kompas->Visible = true;           // Показать диалог Компаса
//      kompas->ActivateControllerAPI();
    }
  }
}

//---------------------------------------------------------------------------
// закрыть Компас
// ---
void __fastcall TForm1::btUnloadGraphicClick(TObject *Sender)
{
  if ( kompas ) {
    kompas->Quit();
    kompas.Unbind();
  }
}

//---------------------------------------------------------------------------
// закрыть Компас
// ---
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  if ( kompas ) {
    kompas->Quit();
    kompas.Unbind();
  }
}

//---------------------------------------------------------------------------
// открыть документ
// ---
void __fastcall TForm1::btLoadFileClick(TObject *Sender)
{
  if ( kompas ) {
    OpenDialog1->Filter = "Чертежи(*.cdw)|*.cdw|Фрагменты(*.frw)|*.frw"
                          "|Модели(*.m3d)|*.m3d|Сборки(*.a3d)|*.a3d|";
    OpenDialog1->FileName = "";
    if ( OpenDialog1->Execute()) {
//    Открыть документ с диска
//    первый параметр - имя открываемого файла
//    второй параметр указывает на необходимость выдачи запроса "Файл изменен. Сохранять?" при закрытии файла
//    третий параметр - указатель на IDispatch, по которому График вызывает уведомления об изменении своего состояния
      WideString fileName ( OpenDialog1->FileName );
      long type =  kompas->ksGetDocumentTypeByName( fileName.c_bstr() );
      switch (type) {
        case lt_DocPart3D:    //3d документы
        case lt_DocAssemble3D: {
          ksDocument3DPtr doc3D( (ksDocument3D*)kompas->Document3D(), false/*AddRef*/ );
          if ( doc3D )
            doc3D->Open( fileName.c_bstr(), 0 );
          break;
        }
        case lt_DocSheetStandart : //2d документы
        case lt_DocFragment: {
          ksDocument2DPtr doc2D( (ksDocument2D*)kompas->Document2D(), false/*AddRef*/ );
          if ( doc2D )
            doc2D->ksOpenDocument( fileName.c_bstr(), 0 );
          break;
        }
        case lt_DocSpc: {         //спецификации
          ksSpcDocumentPtr docSpc( (ksSpcDocument*) kompas->SpcDocument(), false/*AddRef*/ );
          if ( docSpc )
            docSpc->ksOpenDocument( fileName.c_bstr(), 0 );
          break;
        }
        case lt_DocTxtStandart: { //текстовые документы
          ksDocumentTxtPtr docTxt( (ksDocumentTxt*)kompas->DocumentTxt(), false/*AddRef*/ );
          if ( docTxt )
            docTxt->ksOpenDocument( fileName.c_bstr(), 0 );
          break;
        }
      }
      long err = kompas->ksReturnResult();
      if ( err )
      {
        kompas->ksMessageBoxResult();
        kompas->ksResultNULL();
      }
    }
  }
}

//---------------------------------------------------------------------------
// Закрыть документ
// ---
void __fastcall TForm1::btCloseFileClick(TObject *Sender)
{
  if ( kompas ) {
    ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
    if ( doc )
      doc->ksCloseDocument();
  }
}

//---------------------------------------------------------------------------
// создать новый документ
// ---
void __fastcall TForm1::btNewFileClick(TObject *Sender)
{
  if ( kompas ) {
//      создать новый документ
//      первый параметр - тип открываемого файла
//        0 - лист чертежа
//        1 - фрагмент
//        2 - текстовый документ
//        3 - спецификация
//        4 - 3D-модель
//      второй параметр указывает на необходимость выдачи запроса "Файл изменен. Сохранять?" при закрытии файла
//      третий параметр - указатель на IDispatch, по которому Графие вызывает уведомления об изенении своего состояния
//      ф-ия возвращает HANDLE открытого документа
    ksDocument2DPtr doc( (ksDocument2D*)kompas->Document2D(), false/*AddRef*/ );
    if ( doc ) {
      ksDocumentParamPtr docPar( (ksDocumentParam*)kompas->GetParamStruct( ko_DocumentParam ), false/*AddRef*/ );
      if ( docPar ) {
        docPar->Init();
        docPar->type = lt_DocSheetStandart;
        doc->ksCreateDocument( docPar );
      }
    }
  }
}

//---------------------------------------------------------------------------
// Сохранить файл
// ---
void __fastcall TForm1::btSaveFileClick(TObject *Sender)
{
  if ( kompas ) {
    ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
    if ( doc )
      doc->ksSaveDocument( 0 );
  }
}

//---------------------------------------------------------------------------
// загрузить библиотку
// ---
void __fastcall TForm1::btLoadLibraryClick(TObject *Sender)
{
  if ( kompas ) {
    OpenDialog1->Filter = "Библиотеки(*.rtw)|*.rtw";
    OpenDialog1->FileName = "";
    if (OpenDialog1->Execute() ) {
//    загрузить библиотеку
//    ф-ия возвращает HANDLE загруженной библиотеки
      libraryId = kompas->ksAttachKompasLibrary( WideString( OpenDialog1->FileName ).c_bstr() );
    }
  }
}

//---------------------------------------------------------------------------
// выполнить библиотечную команду
// ---
void __fastcall TForm1::btRunLibraryCommandClick(TObject *Sender)
{
  if ( kompas ) {
    if ( !libraryId )
      btLoadLibraryClick(Sender);
    if ( libraryId )
//      выполнить команду у загруженной библиотеки
//      первй параметр - HANDLE библиотеки
//      второй параметр - идентификатор выполняемой команды
      kompas->ksExecuteKompasLibraryCommand( libraryId, 1 );
  }
}

//---------------------------------------------------------------------------
// выгрузить библиотеку
// ---
void __fastcall TForm1::btUnloadLibraryClick(TObject *Sender)
{
  if ( kompas ) {
    if ( libraryId ) {
      kompas->ksDetachKompasLibrary( libraryId );
      libraryId = 0;
    }
  }
}

//---------------------------------------------------------------------------
// Выйти из контроллера не закрывая компас
// ---
void __fastcall TForm1::btQuitWOUnloadClick(TObject *Sender)
{
  kompas.Unbind();
  Close(); // завершить работу
}

//---------------------------------------------------------------------------
// Завершить работу и закрыть компас
// ---
void __fastcall TForm1::btQuitUnloadClick(TObject *Sender)
{
  Close(); // завершить работу
}

//---------------------------------------------------------------------------
// Выполнить команду
// ---
void __fastcall TForm1::ExecuteCommandClick(TObject *Sender)
{
  if ( kompas ) {
    ksDocument2DPtr doc( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
    if  ( doc ) {
      doc->ksCircle( 50, 50, 20, 1 );
      doc->ksCircle( 50, 50, 50, 2 );
    }
    kompas->ksMessage( TO_OLE(L"Привет") );
  }
}

//---------------------------------------------------------------------------
// Подключиться к активному Компасу
// ---
void __fastcall TForm1::btActiveClick(TObject *Sender)
{
  if ( !kompas ) {
#ifdef __LIGHT_VERSION__
    kompas.ActiveInstance( L"KOMPASLT.Application.5" );
#else
    kompas.ActiveInstance( L"KOMPAS.Application.5" );
#endif
    if ( kompas ) {
      kompas->Visible = true;           // Показать диалог Компаса
//      kompas->ActivateControllerAPI();
    }
  }
}

//---------------------------------------------------------------------------
// Показать/скрыть диалог Компаса
// ---
void __fastcall TForm1::btVisibleClick(TObject *Sender)
{
  if ( kompas )
    kompas->Visible = !kompas->Visible;
}

