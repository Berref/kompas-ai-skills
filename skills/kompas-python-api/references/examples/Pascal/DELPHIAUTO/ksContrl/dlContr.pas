unit dlContr;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface


uses
   Forms, StdCtrls, Dialogs, Classes, Controls;

type
  TForm1 = class(TForm)
    btLoadGraphic: TButton;
    btQuitUnload: TButton;
    btQuitWoUnload: TButton;
    btUnloadGraphic: TButton;
    OpenDialog1: TOpenDialog;
    btLoadFile: TButton;
    btNewFile: TButton;
    btLoadLibrary: TButton;
    btRunLibCommand: TButton;
    btUnloadLibrary: TButton;
    btSaveFile: TButton;
    btCloseFile: TButton;
    ExecuteCommand: TButton;
    btActive: TButton;
    btVisible: TButton;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure btLoadGraphicClick(Sender: TObject);
    procedure btQuitUnloadClick(Sender: TObject);
    procedure btQuitWoUnloadClick(Sender: TObject);
    procedure btUnloadGraphicClick(Sender: TObject);
    procedure btLoadFileClick(Sender: TObject);
    procedure btNewFileClick(Sender: TObject);
    procedure btLoadLibraryClick(Sender: TObject);
    procedure btRunLibCommandClick(Sender: TObject);
    procedure btUnloadLibraryClick(Sender: TObject);
    procedure btSaveFileClick(Sender: TObject);
    procedure btCloseFileClick(Sender: TObject);
    procedure ExecuteCommandClick(Sender: TObject);
    procedure btActiveClick(Sender: TObject);
    procedure btVisibleClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;


var
  Form1: TForm1;
  libraryId  : integer; // HANDLE загруженной библиотеки


implementation

{$R *.DFM}

uses ComObj, ksTlb, ksConstTlb, LDefin2D;

var
  Kompas : KompasObject;

{------------------------------------------------------------------------------}
{                                                                              }
{------------------------------------------------------------------------------}
procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  if Kompas <> nil then
  begin
    //принудительно закрыть График
    Kompas.Quit;
    Kompas := nil;
  end;
end;

{------------------------------------------------------------------------------}
{ загрузить Компас                                                                              }
{------------------------------------------------------------------------------}
procedure TForm1.btLoadGraphicClick(Sender: TObject);
begin
  // Создать объект автоматизации KOMPAS_Graphic
  if Kompas = nil then
  begin
{$IFDEF __LIGHT_VERSION__}
    Kompas:= KompasObject( CreateO leObject('KompasLT.Application.5') );
{$ELSE}
    Kompas:= KompasObject( CreateOleObject('Kompas.Application.5') );
{$ENDIF}
    if Kompas <> nil then
      Kompas.Visible := true;
  end;
end;

{------------------------------------------------------------------------------}
{ закрыть график и задачу                                                                             }
{------------------------------------------------------------------------------}
procedure TForm1.btQuitUnloadClick(Sender: TObject);
begin
  btUnloadGraphicClick(Sender);
  close; //завершить работу
end;

{------------------------------------------------------------------------------}
{ отсоедиться от Компас-а и закрыть задачу                                                                             }
{------------------------------------------------------------------------------}
procedure TForm1.btQuitWoUnloadClick(Sender: TObject);
begin
  if Kompas <> nil then
  begin
    //принудительно закрыть График
    Kompas := nil;
  end;
  close; //завершить работу
end;

{------------------------------------------------------------------------------}
{ закрыть Компас                                                                             }
{------------------------------------------------------------------------------}
procedure TForm1.btUnloadGraphicClick(Sender: TObject);
begin
  if Kompas <> nil then
  begin
    // принудительно закрыть График
    Kompas.Quit;
    Kompas := nil;
  end;

end;

{------------------------------------------------------------------------------}
{ открыть документ                                                                             }
{------------------------------------------------------------------------------}
procedure TForm1.btLoadFileClick(Sender: TObject);
var
 doc : ksDocument2D;
begin
  if Kompas <> nil then
  begin
    OpenDialog1.Filter := 'Чертежи(*.cdw)|*.cdw|Фрагменты(*.frw)|*.frw';
    OpenDialog1.FileName := '';
    if OpenDialog1.Execute then
    begin
//    Открыть документ с диска
//    первый параметр - имя открываемого файла
//    второй параметр указывает на необходимость выдачи запроса "Файл изменен. Сохранять?" при закрытии файла
//    третий параметр - указатель на IDispatch, по которому График вызывает уведомления об изменении своего состояния
      doc := ksDocument2D( Kompas.Document2D );
      if doc <> nil then
        doc.ksOpenDocument( OpenDialog1.FileName, false );
    end;
  end;
end;

{------------------------------------------------------------------------------}
{ создать новый документ                                                                            }
{------------------------------------------------------------------------------}
procedure TForm1.btNewFileClick(Sender: TObject);
var
 doc    : ksDocument2D;
 docPar : ksDocumentParam;

begin
  if Kompas <> nil then
  begin

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
    doc := ksDocument2D( Kompas.Document2D );
    if doc <> nil then
    begin
      docPar := ksDocumentParam( kompas.GetParamStruct(ko_DocumentParam) );
      if ( docPar <> nil ) then
      begin
        docPar.Init();
        docPar.type_ := lt_DocSheetStandart;
        doc.ksCreateDocument( docPar );
      end;
    end
  end;
end;

{------------------------------------------------------------------------------}
{ загрузить библиотку
{------------------------------------------------------------------------------}
procedure TForm1.btLoadLibraryClick(Sender: TObject);
begin
  if Kompas <> nil then
  begin
    OpenDialog1.Filter := 'Библиотеки(*.rtw)|*.rtw';
    OpenDialog1.FileName := '';
    if OpenDialog1.Execute then
    begin
//    загрузить библиотеку
//    ф-ия возвращает HANDLE загруженной библиотеки
      libraryId := Kompas.ksAttachKompasLibrary(OpenDialog1.FileName)
    end;
  end;
end;

{------------------------------------------------------------------------------}
{ выполнить библиотечную команду
{------------------------------------------------------------------------------}
procedure TForm1.btRunLibCommandClick(Sender: TObject);
begin
  if  ( Kompas <> nil ) and ( libraryId <> 0 ) then
  begin
//      выполнить команду у загруженной библиотеки
//      первй параметр - HANDLE библиотеки
//      второй параметр - идентификатор выполняемой команды
    Kompas.ksExecuteKompasLibraryCommand( libraryId, 1 );
  end;
end;

{------------------------------------------------------------------------------}
{ выгрузить библиотеку
{------------------------------------------------------------------------------}
procedure TForm1.btUnloadLibraryClick(Sender: TObject);
begin
  if ( Kompas <> nil ) and ( libraryId <> 0 ) then
  begin
    Kompas.ksDetachKompasLibrary (libraryId);
    libraryId := 0;
  end;
end;

{------------------------------------------------------------------------------}
{ сохранить документ, открытый на редактирование
{------------------------------------------------------------------------------}
procedure TForm1.btSaveFileClick(Sender: TObject);
var
 doc : ksDocument2D;
begin
  if Kompas <> nil then
  begin
    doc := ksDocument2D( kompas.ActiveDocument2D() );
    if  doc <> nil then
    begin
      doc.ksSaveDocument(WideString(''));
      doc := nil;
    end;
  end;
end;

{------------------------------------------------------------------------------}
{ закрыть документ, открытый на редактирование
{------------------------------------------------------------------------------}
procedure TForm1.btCloseFileClick(Sender: TObject);
var
 doc : ksDocument2D;
begin
  if Kompas <> nil then
  begin
    doc := ksDocument2D( kompas.ActiveDocument2D() );
    if  doc <> nil then
    begin
      doc.ksCloseDocument();
      doc := nil;
    end
  end;
end;

{------------------------------------------------------------------------------}
{ Выполнить некоторый код
{------------------------------------------------------------------------------}
procedure TForm1.ExecuteCommandClick(Sender: TObject);
var
  doc : ksDocument2D;
  ellPar : ksEllipseParam;
begin
  if Kompas <> nil then
  begin
    doc := ksDocument2D(kompas.ActiveDocument2D);
    if  doc <> nil then
    begin
      doc.ksCircle( 50, 50, 20, 1 );
      doc.ksCircle( 50, 50, 50, 2 );
      ellPar := ksEllipseParam(kompas.GetParamStruct(ko_EllipseParam));
      if ellPar <> nil then begin
        ellPar.Init();
        ellPar.xc := 10;
        ellPar.yc := 20;
        ellPar.A  := 35;
        ellPar.B  := 45;
        ellPar.style := 1;
        doc.ksEllipse( ellPar );
      end;
      doc := nil;
    end;
  end;
end;

procedure TForm1.btActiveClick(Sender: TObject);
begin
  if Kompas = nil then
  begin
    // Создать объект автоматизации KOMPAS_Graphic
{$IFDEF __LIGHT_VERSION__}
   Kompas:= KompasObject( GetActiveOleObject('KompasLT.Application.5') );
{$ELSE}
   Kompas:= KompasObject( GetActiveOleObject('Kompas.Application.5') );
{$ENDIF}
    if Kompas <> nil then
      Kompas.Visible := true;
  end;
end;

procedure TForm1.btVisibleClick(Sender: TObject);
begin
  if Kompas <> nil then
    Kompas.Visible := not Kompas.Visible;
end;

end.
