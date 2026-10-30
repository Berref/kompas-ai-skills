unit step4_3;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, LDefin2D, ksAuto, ExtCtrls,
{$IFDEF __LIGHT_VERSION__}
  klTLB;
{$ELSE}
  ksTLB;
{$ENDIF}

type
  TTestSlideDlg = class(TForm)
    pPreviewPanel: TPanel;
    pPreviewBox: TPaintBox;
    Button1: TButton;
    Button2: TButton;
    procedure pPreviewBoxPaint(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    kompasDocName : String;
    IdSlide       : Cardinal;
    resurs        : String;
    doc           : ksDocument2D;
    kompas        : KompasObject;
    { Public declarations }
  end;

var
  TestSlideDlg: TTestSlideDlg;

implementation

{$R *.DFM}

procedure TTestSlideDlg.pPreviewBoxPaint(Sender: TObject);
var
  gr : reference;
begin
  if ( kompas <> nil ) then begin
//    kompas.ksDrawSlide ( pPreviewPanel.Handle, IdSlide );
//    kompas.ksDrawBitmap( pPreviewPanel.Handle, IdSlide );

    if ( (doc <> nil) And (doc.Reference <> 0) ) then begin
//      doc.ksDrawKompasDocument( pPreviewPanel.Handle, kompasDocName );
      gr := doc.ksNewGroup( 1 );
        doc.ksMtr( 20, 15, 45, 1, 1 );
        doc.ksLineSeg( -10, 0,  10,  0,  1 );
        doc.ksLineSeg( 10,  0,  10,  20, 1 );
        doc.ksLineSeg( 10,  20, -10, 20, 1 );
        doc.ksLineSeg( -10, 20, -10, 0,  1 );
        doc.ksDeleteMtr;
      doc.ksEndGroup;
      doc.ksDrawKompasGroup( pPreviewPanel.Handle, // несущее окно
                             gr );                  // группа
      doc.ksDeleteObj( gr ); 
    end
    else
      kompas.ksError( 'Графический документ не активен' );

    //  Для отладки слайда можно использовать функцию: при изменении файла .rc не нужно
    //  перекомпилировать библиотеку
//	  if ( resurs <> '' ) then
//		  kompas.ksDrawSlideFromFile( pPreviewPanel.Handle, resurs );
  end;
end;

procedure TTestSlideDlg.FormCreate(Sender: TObject);
begin
  kompasDocName := 'c:\1.frw';
  IdSlide       := 100;
  // для отрисовки слайда из файла ресурса
//	resurs := kompas.ksReadString( 'Введите имя *.rc файла', 'c:\libPasAuto\st4.rc' );

end;

end.
