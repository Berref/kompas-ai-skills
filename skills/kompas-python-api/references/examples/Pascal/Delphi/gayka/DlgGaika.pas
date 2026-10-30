unit DlgGaika;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, Base,
     StdCtrls,  Buttons, ExtCtrls, OkCancl1,  gayka2, LibDB, libtool, LDefin2D;

type
  TfmDlgGaika = class(TOKBottomDlg)
    HelpBtn: TButton;
    Label1: TLabel;
    cmbDm: TComboBox;
    GroupBox1: TGroupBox;
    Label2: TLabel;
    Label3: TLabel;
    edAngle: TEdit;
    edShag: TEdit;
    rgVid: TRadioGroup;
    CheckBox1: TCheckBox;
    CheckBox2: TCheckBox;
    CheckBox3: TCheckBox;
    CheckBox4: TCheckBox;
    CheckBox5: TCheckBox;
    rgIspoln: TRadioGroup;
    Panel1: TPanel;
    PaintBox1: TPaintBox;
    procedure FormCreate(Sender: TObject);
    procedure edAngleChange(Sender: TObject);
    procedure EShagChange(Sender: TObject);
    procedure EVidClick(Sender: TObject);
    procedure CheckBox2Click(Sender: TObject);
    procedure cmbDmChange(Sender: TObject);
    procedure CheckBox1Click(Sender: TObject);
    procedure CheckBox3Click(Sender: TObject);
    procedure CheckBox4Click(Sender: TObject);
    procedure rgIspolnClick(Sender: TObject);
    procedure CheckBox5Click(Sender: TObject);
    procedure HelpBtnClick(Sender: TObject);
    procedure PaintBox1Paint(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;



var
  fmDlgGaika: TfmDlgGaika;


implementation

uses Dialogs;

{$R *.DFM}
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.FormCreate(Sender: TObject);
type
  StTmpL = record
    s : array [0..19] of AnsiChar;
    dr : single;
  end;

var
  tmpL : StTmpL ;
  s    : string[255];
  i    : integer;
  flag : boolean;
  v    : single;
  code : integer;

begin
  ConvertComponentLang( self ); // перевод формы на соответствующий язык

  // Application.HelpContext(HelpContext);

  Str(bufGayka.tmp.hatchAng:5:3, s);
  edAngle.Text := s;
  Str(bufGayka.tmp.hatchShag:5:3, s);
  edShag.Text := s;
  case ( bufGayka.par.drawType ) of
    ID_VID    : rgVid.ItemIndex:= 0;
    ID_SIDEVID : rgVid.ItemIndex:= 1;
    ID_TOPVID  : rgVid.ItemIndex:= 2;
    ID_VIDSEC  : rgVid.ItemIndex:= 3;
  end;
  edAngle.Enabled:= bufGayka.par.drawType = ID_VIDSEC;
  edShag.Enabled := bufGayka.par.drawType = ID_VIDSEC;

  caption := LoadStr_(STR6);
  CheckBox1.Checked:= (bufGayka.tmp.f and PITCH) <> 0;
  CheckBox2.Checked :=  bufGayka.par.flagAttr <> 0;
  CheckBox3.Checked:=( bufGayka.tmp.f and SIMPLE ) <> 0;
  CheckBox4.Checked:=( bufGayka.tmp.f and AXIS_OFF ) = 0;
  CheckBox5.Checked :=(bufGayka.tmp.f1 and KEY_S) <> 0;
  CheckBox5.Enabled := (bufGayka.tmp.f1 and KEY_S_GRAY) <> 0;

  i:=1;
  while( i<>0 ) do
  begin
    i:=ReadRecord(  gBase.bg, gBase.rg1, Addr(tmpL) );

    if ( i<>0 )  then
      cmbDm.Items.Add( String(tmpL.s) );
  end;
  i :=0;  cmbDm.Items.count;
  flag := true;
  while( flag ) do
  begin
    s:= cmbDm.Items[i];
    Val( cmbDm.Items[i], v , code );
    if( abs(v-bufGayka.tmp.dr) < 0.001 ) then
    begin
      cmbDm.ItemIndex:= i;
      flag := false;
    end
    else
      Inc(i);
  end;
  if ( bufGayka.tmp.f and ISPOLN )<>0 then
    rgIspoln.ItemIndex := 1
  else
    rgIspoln.ItemIndex := 0;

  PaintBox1.Repaint;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.edAngleChange(Sender: TObject);
var
  code : integer;
  value  : single;
begin
  Val( edAngle.Text, value, Code);
  if code <> 0 then
    MessageDlg(LoadStr_(STR7), mtWarning, [mbOk], 0)
  else
    bufGayka.tmp.hatchAng := value;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.EShagChange(Sender: TObject);
var
  code : integer;
  value  : single;
begin
  Val( edShag.Text, value, Code);
  if code <> 0 then
    MessageDlg( LoadStr_(STR8), mtWarning, [mbOk], 0)
  else
    bufGayka.tmp.hatchshag := value;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.EVidClick(Sender: TObject);
begin
  case ( rgVid.ItemIndex) of
    0 : bufGayka.par.drawType := ID_VID;
    1 : bufGayka.par.drawType := ID_SIDEVID;
    2 : bufGayka.par.drawType := ID_TOPVID;
    3 : bufGayka.par.drawType := ID_VIDSEC;
  end;
  edAngle.Enabled:= bufGayka.par.drawType = ID_VIDSEC;
  edShag.Enabled := bufGayka.par.drawType = ID_VIDSEC;

  PaintBox1.Repaint;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.CheckBox2Click(Sender: TObject);
begin
  inherited;
  if ( CheckBox2.Checked ) then
    bufGayka.par.flagAttr := 1
  else
    bufGayka.par.flagAttr := 0;
end;



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.cmbDmChange(Sender: TObject);
var
  s : string;
  value : single;
  code : integer;

begin
  inherited;
  s :=  cmbDm.Items[cmbDm.ItemIndex];
  Val( s, value, Code);
  if code <> 0 then
    MessageDlg( LoadStr_(STR9), mtWarning, [mbOk], 0)
  else
  begin
    bufGayka.tmp.dr := value;
    if ( ReadGaykaBase ( bufGayka.tmp.dr, gBase, bufGayka.tmp )=0 ) then
      Close;
    CheckBox5.Checked :=(bufGayka.tmp.f1 and KEY_S)<>0;
    CheckBox5.Enabled := (bufGayka.tmp.f1 and KEY_S_GRAY)<>0;
  end;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.CheckBox1Click(Sender: TObject);
begin
  inherited;
  if ( CheckBox1.Checked ) then
    bufGayka.tmp.f := bufGayka.tmp.f or PITCH
  else
    bufGayka.tmp.f := bufGayka.tmp.f or PITCH xor PITCH;
  if ( ReadGaykaBase ( bufGayka.tmp.dr, gBase, bufGayka.tmp )=0 ) then
      Close;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.CheckBox3Click(Sender: TObject);
begin
  inherited;
  if ( CheckBox3.Checked ) then
    bufGayka.tmp.f := bufGayka.tmp.f or SIMPLE
  else
    bufGayka.tmp.f := bufGayka.tmp.f or SIMPLE xor SIMPLE;

  PaintBox1.Repaint;
end;


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.CheckBox4Click(Sender: TObject);
begin
  inherited;
  if not CheckBox4.Checked then
    bufGayka.tmp.f := bufGayka.tmp.f or AXIS_OFF
  else
    bufGayka.tmp.f := bufGayka.tmp.f or AXIS_OFF xor AXIS_OFF;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.rgIspolnClick(Sender: TObject);
begin
  inherited;
  if ( rgIspoln.ItemIndex=1 ) then
    bufGayka.tmp.f := bufGayka.tmp.f or ISPOLN
  else
    bufGayka.tmp.f := bufGayka.tmp.f or ISPOLN xor ISPOLN;

  PaintBox1.Repaint;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.CheckBox5Click(Sender: TObject);
begin
  inherited;
  if ( CheckBox5.Checked ) then
    bufGayka.tmp.f1 := bufGayka.tmp.f1 or KEY_S
  else
    bufGayka.tmp.f1 := bufGayka.tmp.f1 or KEY_S xor KEY_S;

  if ( ReadGaykaBase ( bufGayka.tmp.dr, gBase, bufGayka.tmp )=0 ) then
      Close;
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.HelpBtnClick(Sender: TObject);
var
  fileName : array[0..255] of AnsiChar;
begin
  inherited;
  if ( GetFullName( PAnsiChar(LoadStr_(STR10)),  fileName  )<> 0) then
    ksOpenHelpFile( fileName, HELP_CONTEXT, 1 )
  else
    Error( PAnsiChar(LoadStr_(STR12)) );
end;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
procedure TfmDlgGaika.PaintBox1Paint(Sender: TObject);
begin
  inherited;
  DrawSlide(Panel1.Handle, bufGayka.ChoiceBMP); // отрисовка слайда
end;

end.

