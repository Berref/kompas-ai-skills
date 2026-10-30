unit Gayka2;

interface
uses
  Forms, Controls, Windows, SysUtils, LtDefine, LibTool, Base, LibDB, LibHpPar, LDefin2D;
const
COUNT_MASSA =1000;

AXIS_OFF     =$1;    // 0 рисовать >0 не рисовать
PITCH        =$2;    // крупный шаг >0 мелкий шаг
SIMPLE       =$10;   // нормальная отрисовка >0 упрощенная отрисовка
ISPOLN       =$80;   // исполнение 1 >0 исполнение 2
TAKEISPOLN   =$100;  // 0 не учитывать исполнение  >0 учитывать исполнение
//дополнитеоьные маски
KEY_S_ON     =$1; // 0- выключены дополнитеоьные размеры под ключ > 0 - включены
KOEFF_MAT_ON =$4; // 0- только металл, >0 другие материалы
KEY_S        =$2; // 0-обычный размер под ключ; > 0 дополнительный
KEY_S_GRAY   =$8; // > 0 греить checkbox "дополнитеоьные размеры под ключ"
PITCHOFF     =$800;  // есть крупный и мелкий шаг >0 есть только крупный

type
GaykaTMP = record
    dr : single;
    p1 : single;
    p2 : single;
     s : single;
     D : single;
    da : single;
     h : single;
    d2 : single;
     m : single;
    s1 : single;
    D1 : single;
    m1 : single;
end;

//---------------------------------------------------------------------------
GAYKA5915 = record
    dr         : single;
    s          : single;
    D          : single;
    da         : single;
    h          : single;
    d2         : single;
    p          : single;
    f          : word;      //битовые маски
    klass      : SmallInt;  //класс точности
    gost       : word;      //номер госта
    hatchAng   : single;
    hatchShag  : single;
    ver        : byte;      // версия макро
    massa      : single;
    indexMassa : byte;      //0-металл 1- алюмин сплав 2-латунь
    f1         : word;      //битовые маски
end;
//---------------------------------------------------------------------------
SimpleBase = record
  bg            : reference;         //указатель базы
  rg1, rg2, rg3 : reference;   //указатели на 2 отношения
end;
//---------------------------------------------------------------------------
PGayka = ^Gayka;
Gayka = class( CPar )
private
public
  tmp : GAYKA5915 ;

public
  constructor Create(  gost : word );
  destructor Destroy; override;
  procedure GetGroup( var gr : reference ); override;
  function  ChoiceMenuId : integer; override;
  procedure SetParam; override;
  function  Size: integer; override;
  procedure SetHatchShag; override;
  procedure SetHatchAngl; override;

  procedure gayka_sverhu;
  procedure gayka_p_k( j:integer );
  function  MacroElementParam : integer;  override;
  function  EditSpcObj( var spcObj : reference; geom : reference ) : reference; override;
  function  IsSpcObjCreate: boolean; override; {override;}//функция проверки подключения атрибутов или нет
  class function StaticEditSpcObj ( flagMode:boolean; tmp:GAYKA5915;
                               var spcObj : reference; geom : reference; flagAttr:word ): reference;
  procedure Assign ( other : CPar ); override; // оператор присваивания
  function  ChoiceBMP:integer;

// HOT_POINTS ##################################################################
  function  GetHotPoints( point : PHotPointDescription;  index : Integer ) : LongBool; stdcall;
//  function  GetHotPointsCount : Integer;
  function  SetHotPoint( point : PHotPointDescription;  index : Integer ) : LongBool; stdcall;
  function  GetCursorText( index : Integer; Var text : PAnsiChar ) : LongBool; stdcall;
  function  GetMenu : integer; stdcall;
  function  ExecuteCommand( id : Integer ) : LongBool; stdcall;
  function EditComplete( index : Integer; success : LongBool ) : LongBool; stdcall;
  function  ChangeHotPointParam( d : Double ) : LongBool; stdcall;
// HOT_POINTS ##################################################################
end;


function GetGayka( gost : word): Gayka;
procedure gayka_k( ls, l, d1, s, D, l1, H : single;  j : smallInt; j1 : integer;
                   d2 : single; j2 : integer ) ;
procedure  gayka_k_side( ls, s, D, d2, H : single; j, j2 : integer );
procedure gayka_k_y( ls : single; var tmp : GAYKA5915; j : integer );
function  OpenGaykaBase ( var base : SimpleBase ): integer;
procedure  CloseGaykaBase ( base : SimpleBase  );
function  ReadGaykaBase ( d : single; base : SimpleBase; var lpG : GAYKA5915 ): integer;

var
  bufGayka    : Gayka;
  gBase       : SimpleBase;
  textForHP_2 : PAnsiChar; // обязательно должен быть описан как static
  cursorText  : AnsiString;

implementation
uses  DlgGaika;

//-------------------------------------------------------------------------------
//
//------
procedure  Gayka.Assign( other : CPar );  // оператор присваивания
var
  p : Gayka;
begin
  inherited  Assign( other );
  p:= Gayka(other);
  Move( p.tmp, tmp, sizeof(tmp));
end;

//-------------------------------------------------------------------------------
//
//------
procedure gayka_k( ls, l, d1, s, D, l1, H : single;  j : smallInt; j1 : integer;
                   d2 : single; j2 : integer ) ;
var
  x, y : array [0..9] of single;
  c, h1, rb : single;
  xc2, yc2, xcbl, ycbl, xcbp, ycbp, ycml : single;

begin
  // Координаты контура рез_части

  //j1=1 -   контровочное отверстие  j1=0 - контров. отв. нет
  //j2=1 исполнение 1   j2=2    исполнение 2

  D  := s / cosd( 30 );
  c  := ( D - d2 ) / 2 * TanD( 30 );
  h1 := D * 0.5 * Sind( 30 );

  rb := ( h1 * h1 + c * c ) / 2 / c;

  x[1] := ls; y[1] := 0;
  if ( j2 = 1 ) then
  begin
    x[2] := ls;      y[2] := j * ( d2 * 0.5 );
    x[3] := ls + c;  y[3] := j * ( D * 0.5 );
    x[7] := ls + c;  y[7] := j * h1;
  end
  else begin
    x[2] := ls; y[2] := j * ( D * 0.5 );
    x[7] := ls; y[7] := j * h1;
  end;
  x[4] := ls + H - c;  y[4] := j * ( D * 0.5 );
  x[5] := ls + H;      y[5] := j * ( d2 * 0.5 );
  x[6] := ls + H;      y[6] := 0;

  x[8] := ls + H - c;  y[8] := j * h1;
  xc2  := ls + l;      yc2  := j * ( D * 0.5 - l1 );

  xcbl := ls + rb;     ycbl := 0;
  xcbp := ls + H - rb; ycbp := 0;
  ycml := j * ( (D *0.5 - h1) / 2 + h1 );


  if ( j2 = 1) then
  begin
    LineSeg( x[1], y[1], x[2], y[2], 1 );
    LineSeg( x[2], y[2], x[3], y[3], 1 );
    LineSeg( x[3], y[3], x[4], y[4], 1 );
    LineSeg( x[4], y[4], x[5], y[5], 1 );
    LineSeg( x[5], y[5], x[6], y[6], 1 );
    LineSeg( x[7], y[7], x[8], y[8], 1 );
    ArcByPoint( xcbl, ycbl, rb, x[1], y[1], x[7], y[7], -j, 1 );
    ArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
    ArcBy3Points( ls + c * 0.5, (D * 0.5 - (D - d2) / 4) * j,
                      ls, ycml, x[7], y[7], 1 );
    ArcBy3Points( ls + H - c * 0.5, (D * 0.5 - (D - d2) / 4) * j, ls + H,
                      ycml, x[8], y[8], 1 );
  end
  else begin
   LineSeg( x[1], y[1], x[2], y[2], 1 );
   LineSeg( x[2], y[2], x[4], y[4], 1 );
   LineSeg( x[4], y[4], x[5], y[5], 1 );
   LineSeg( x[5], y[5], x[6], y[6], 1 );
   LineSeg( x[7], y[7], x[8], y[8], 1 );
   ArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
   ArcBy3Points( ls + H - c * 0.5, (D * 0.5 - (D - d2) / 4) * j,
                     ls + H, ycml, x[8], y[8], 1 );

  end;

  if ( j1 = 1) then
  begin
   Circle( xc2, yc2, d1 * 0.5, 1 );
   LineSeg( xc2 - 2, yc2, xc2 + 2, yc2, 2 );
   LineSeg( xc2, yc2 - 2, xc2, yc2 + 2, 2 );
  end;


end;

//-------------------------------------------------------------------------------
//
//------
procedure  gayka_k_side( ls, s, D, d2, H : single; j, j2 : integer );
var
 x, y , x2, y2 : single;
 c             : single;
begin
//j2=1 исполнение 1   j2=2    упрощенное
 c := ( D - d2 ) / 2 * TanD( 30 );

  y := j * s * 0.5;
  if (j2 = 1)  then
  begin
    x := ls + c;
    LineSeg( ls, 0, ls, j * d2 * 0.5, 1 );
    LineSeg( ls, j * d2 * 0.5, x, y, 1 );
    ArcBy3Points( ls + c, j * (s * 0.5), ls, s * 0.25 * j, ls + c, 0, 1 );
  end
  else begin
    x := ls;
    LineSeg( x, 0, x, y, 1 );
  end;

  if ( j2 = 3 ) then
  begin
    x2 := ls + H;
    y2 := y;
  end
  else begin
    x2 := ls + H - c;
    y2 := j * d2 * 0.5;
  end;
  LineSeg( x, y, x2, y, 1 );
  if ( j2 <> 3 )  then
  begin
    LineSeg( x2, y, ls + H, y2 , 1 );
    ArcBy3Points( ls + H - c, j * (s * 0.5), ls + H,s * 0.25 * j,
                      ls + H - c, 0, 1 );
  end;
  LineSeg( ls + H, y2, ls + H, 0, 1 );
  if ( j > 0 ) then
    LineSeg( x, 0, x2, 0, 1 );
end;

//-------------------------------------------------------------------------------
//
//------
procedure gayka_k_y( ls : single; var tmp : GAYKA5915; j : integer );
var
  h1 : single;

begin
  tmp.D := tmp.s / CosD( 30 );

  h1 := tmp.D * 0.5 * SinD( 30 );

  LineSeg( ls, 0, ls, j * (tmp.D * 0.5 ), 1 );
  LineSeg( ls, j * ( tmp.D * 0.5), ls + tmp.h, j * (tmp.D * 0.5), 1 );
  LineSeg( ls + tmp.h, j * (tmp.D * 0.5), ls + tmp.h, 0, 1 );
  LineSeg( ls, j * h1, ls + tmp.h, j * h1, 1 );

end;

//-------------------------------------------------------------------------------
//     Гайки нормальные классов точности А,В,С
//     ГОСТ 5915
//------
constructor Gayka.Create( gost : word );
begin
  inherited create;
  if( _GetMacroParam( GetAddr, Size )=0 ) then
  begin
    tmp.gost := gost;
    par.ang       := 0;
    par.drawType  := ID_VID;
    tmp.hatchAng  := 45;
    tmp.hatchShag := 2;
    tmp.f := 0; tmp.dr:=20;  tmp.p:=2.5;
    tmp.f1:=0;
    tmp.ver := 1;
    tmp.indexMassa :=0;
    case (gost) of
      5915 : begin
        tmp.s:=30; tmp.D:=33;  tmp.da:=21.6;  tmp.h:=16;
        tmp.d2:=27.7;  tmp.klass:=2;   ///*класс точности*/
        tmp.f := TAKEISPOLN;
        tmp.f1 := KEY_S_ON or KOEFF_MAT_ON;
        tmp.massa := 71.44;
        end;
    end
  end;
end;

//----------------------------------------------------------------------------------------
//
//---
destructor Gayka.Destroy;
begin
  inherited Destroy;
end;

//-------------------------------------------------------------------------------
//
//------
procedure Gayka.GetGroup( var gr : reference );
var
  k2 : integer;
begin

  if ( (tmp.f and ISPOLN)=0 ) then k2:=1 else k2:=2;

  if ( gr<>0 ) then
    DeleteObj( gr );
  gr := NewGroup( 1 );
  Macro( 0 );
  case (par.drawType) of
    ID_VID : begin // /*вид*/
      if ( (tmp.f And SIMPLE)=0 ) then
      begin
       gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, 1, 0, tmp.d2, k2 );
       gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, -1, 0, tmp.d2, k2 );
      end
      else begin
       gayka_k_y( 0, tmp,  1 );
       gayka_k_y( 0, tmp, -1 );
      end;
      if ( (tmp.f and AXIS_OFF )=0 ) then
        LineSeg( -3, 0, tmp.h + 3, 0, 3 );
    end;
    ID_SIDEVID : begin///*вид сбоку*/
      if ( (tmp.f and AXIS_OFF )=0 ) then
        LineSeg( -3, 0, tmp.h + 3, 0, 3 );
      if ( (tmp.f and SIMPLE)<>0 ) then
        k2 := 3;
      gayka_k_side( 0, tmp.s, tmp.D, tmp.d2, tmp.h, 1, k2 );
      gayka_k_side( 0, tmp.s, tmp.D, tmp.d2, tmp.h, -1, k2 );
    end;
    ID_TOPVID    :begin ///*вид ссверху*/
                  gayka_sverhu;
                  end;
    ID_BOTTOMVID : begin///*вид снизу*/
                  gayka_sverhu;
                  end;
    ID_VIDSEC: begin ///*пол-вида/пол-разреза*/
      if( (tmp.f and SIMPLE)=0 ) then
      begin
        gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, 1, 0, tmp.d2, k2 );
        gayka_p_k( -1 );
      end
      else begin
        gayka_k_y( 0, tmp, 1 );
        gayka_p_k( -1 );
      end;
      if ( ( tmp.f and AXIS_OFF )=0 ) then
        LineSeg( -3, 0, tmp.h + 3, 0, 3 );
    end;
  end;

  refMacr :=EndObj();
  EndGroup();
end;

//-------------------------------------------------------------------------------
//
//------
function  Gayka.ChoiceMenuId() : integer;
begin
  if ( par.typeSwitch = 0 ) then
  begin
    case (par.drawType) of
      ID_VID    : begin result := MENU_G5915_1; exit; end;
      ID_TOPVID : begin result := MENU_G5915_2; exit; end;
      ID_SIDEVID: begin result := MENU_G5915_4; exit; end;
    end;
    result := MENU_G5915_3;
    exit;
  end
  else begin
    case (par.drawType) of
      ID_VID    : begin result := MENU_G5915_5; exit; end;
      ID_TOPVID : begin result := MENU_G5915_6; exit; end;
      ID_SIDEVID: begin result := MENU_G5915_8; exit; end;
    end;
    result := MENU_G5915_7;
    exit;
  end;
end;

//-------------------------------------------------------------------------------
//
//------
function  Gayka.ChoiceBMP( ):integer;
begin

  case ( par.drawType ) of
    ID_VID : begin
      if ( (tmp.f and SIMPLE)<>0 )  then
      begin
        result:= G5915_5;
        exit;
      end;
      if ( tmp.f and ISPOLN )<>0 then
      begin
        result:=G5915_9;
        exit;
      end;
      result:=G5915_1;
      exit;
      end;
    ID_SIDEVID : begin
      if ( tmp.f and SIMPLE ) <>0 then
      begin
        result:=G5915_6;
        exit;
      end;
      if ( tmp.f and ISPOLN )<> 0 then
      begin
        result:= G5915_10;
        exit;
      end;
      result:=G5915_2;
      exit;
      end;
    ID_TOPVID : begin
      if ( tmp.f and SIMPLE ) <>0 then
        result:=G5915_7
      else
        result:=G5915_3;
      exit;
      end;
    ID_BOTTOMVID : begin
      if ( tmp.f and SIMPLE ) <>0 then
        result:=G5915_7
      else
        result:=G5915_3;
      exit;
      end;
    ID_VIDSEC : begin
      if ( tmp.f and SIMPLE ) <>0 then
      begin
        result:= G5915_8;
        exit;
      end;
      if ( tmp.f and ISPOLN ) <>0 then
      begin
        result:= G5915_11;
        exit;
      end;
      result:= G5915_4;
      exit;
      end;
  end;
  result:=0;
end;

//-------------------------------------------------------------------------------
//
//------
procedure Gayka.SetParam;
begin
  ksSetMacroParam( refMacr, GetAddr, Size(), nil, nil, -1, MP_HOTPOINTS );
end;

//-------------------------------------------------------------------------------
//
//------
function   Gayka.Size: integer;
begin
  result:= CParSize + sizeof(tmp);
end;

//-------------------------------------------------------------------------------
//
//------
procedure  Gayka.SetHatchShag;
begin
  tmp.hatchShag := _SetHatchShag( tmp.hatchShag );
end;

//-------------------------------------------------------------------------------
//
//------
procedure  Gayka.SetHatchAngl;
begin
  tmp.hatchAng := _SetHatchAngl( tmp.hatchAng );
end;

//-------------------------------------------------------------------------------
//
//------
procedure Gayka.gayka_sverhu;
var
  D, s : single;
  h1, dd : single;

begin

  s := tmp.s * 0.5;
  D := s / cosd( 30 );
  dd := tmp.dr - 2 * MODSTEP_REAL * tmp.p;

  h1 := D * sind( 30 );


  LineSeg( -s, h1, 0, D, 1 );
  LineSeg( 0, D, s, h1, 1 );
  LineSeg( s, h1, s, -h1, 1 );
  LineSeg( s, -h1, 0, -D, 1 );
  LineSeg( 0, -D, -s, -h1, 1 );
  LineSeg( -s, -h1, -s, h1, 1 );

  if( (tmp.f and SIMPLE)=0 ) then
    Circle( 0, 0, tmp.d2 * 0.5, 1 );
  Circle( 0, 0, dd * 0.5, 1 );
  ArcByPoint( 0, 0, tmp.dr * 0.5, tmp.dr * 0.5 * sind(15),
       tmp.dr * 0.5 * cosd(15), tmp.dr * 0.5 * cosd(15),
       -tmp.dr * 0.5 * sind(15), 1, 2 );

  if ( (tmp.f and AXIS_OFF )=0 ) then
  begin
    if ( D >= 6 )  then
    begin
      LineSeg( -3 - s, 0, s + 3, 0, 3 );
      LineSeg( 0, -3 - D, 0, 3 + D, 3 );
    end
    else  begin
      LineSeg( -1 - s, 0, s + 1, 0, 3 );
      LineSeg( 0, -1 - D, 0, 1 + D, 3 );
    end;
  end;
end;

//-------------------------------------------------------------------------------
//
//------
procedure Gayka.gayka_p_k( j : integer );
var
  c, dd, c1, c2 : single;
  y, x , x1, x2, x3, y3, y2 : single;

begin
  c1 := 0; c2 := 0;
  x := 0;

  c := ( tmp.D - tmp.d2 ) / 2 * tand( 30 );

  if((tmp.f and ISPOLN)=0) And ((tmp.f and SIMPLE)=0 ) then
    y := j * tmp.d2 * 0.5
  else
    y := j * tmp.D * 0.5;

  LineSeg( 0, 0, 0, y, 1 );

  if ( (tmp.f and ISPOLN)=0) and ((tmp.f and SIMPLE)=0 ) then
  begin
    x := c;
    LineSeg( 0, y, x, j * (tmp.D * 0.5), 1 );
  end;
  dd := tmp.dr - 2 * MODSTEP_REAL * tmp.p;

  if ( (tmp.f and SIMPLE)=0 ) then
  begin
    x3 := tmp.h - c ;
    y3 := j * tmp.d2 * 0.5;
    y2 := j * tmp.da * 0.5;
  end
  else begin
    x3 := tmp.h;
    y3 := j * tmp.D * 0.5;
    y2 := j * dd * 0.5;
  end;

  LineSeg( x, j * (tmp.D * 0.5), x3, j * tmp.D * 0.5, 1 );
  if ( (tmp.f and SIMPLE)=0 )then
    LineSeg( x3, j * tmp.D * 0.5, tmp.h, y3, 1 );
  LineSeg( tmp.h, y3, tmp.h, 0, 1 );

  x1 := tmp.h;
  x2 := x1;
  if ( (tmp.f and SIMPLE)=0 ) then
  begin
    c1 := (tmp.da - dd) * 0.5;
    c2 := ( tmp.da - tmp.dr ) * 0.5;
    if ( (tmp.f and ISPOLN)=0 ) then
      x2 := x2 - c2;
  end;

  if ( (tmp.f and ISPOLN)=0 ) and ((tmp.f and SIMPLE)=0 ) then
  begin
    x1 := x1 - c1;
    LineSeg ( tmp.h, j * tmp.da * 0.5, x1, j * 0.5 * dd, 1 );
    LineSeg( x1, j * dd * 0.5, x1, 0, 1 );
  end;

  LineSeg( x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1 );

  if ( (tmp.f and SIMPLE)=0 ) then
  begin
    LineSeg( c1, j * 0.5 * dd, 0, j * 0.5 * tmp.da, 1);
    LineSeg( c1, j * dd * 0.5, c1, 0, 1 );
  end;

  Hatch( 0, tmp.hatchAng, tmp.hatchShag, 0, 0, 0 );
      LineSeg( 0, y2, 0, y, 1 );
    if ((tmp.f and ISPOLN)=0) and ((tmp.f and SIMPLE)=0 ) then
      LineSeg( 0, y, x, j * (tmp.D * 0.5), 1 );
    LineSeg( x, j * (tmp.D * 0.5), x3, j * tmp.D * 0.5, 1 );
    if ( (tmp.f and SIMPLE)=0 ) then
      LineSeg( x3, j * tmp.D * 0.5, tmp.h, y3, 1 );

    if ( (tmp.f and ISPOLN)=0 ) and ( (tmp.f and SIMPLE)=0 ) then
      LineSeg( tmp.h, y3, tmp.h, j * tmp.da * 0.5, 1 )
    else
      LineSeg( tmp.h, y3, tmp.h, j * dd * 0.5, 1 );


    if ((tmp.f and ISPOLN)=0) and ((tmp.f and SIMPLE)=0) then
      LineSeg( tmp.h, j * tmp.da * 0.5, x1, j * 0.5 * dd, 1 );
    LineSeg( x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1 );
    if ( (tmp.f and SIMPLE)=0 ) then
      LineSeg( c1, j * 0.5 * dd, 0, j * 0.5 * tmp.da, 1 );
  EndObj;
  LineSeg( c2, j * 0.5 * tmp.dr, x2, j * 0.5 * tmp.dr, 2 );

end;

//-------------------------------------------------------------------------------
//
//------
function Gayka.MacroElementParam : integer;
begin
  Result := 0;
  if OpenGaykaBase(gBase) <> 0 then
  begin
    bufGayka := Gayka.Create(0);
    bufGayka.Assign(self);
    EnableTaskAccess(0);
    fmDlgGaika := TfmDlgGaika.Create(Application);
    try
      if fmDlgGaika.ShowModal <> mrOk then
        result := 0
      else
      begin
        result := 1;
        Assign(bufGayka);
      end;
    finally
      fmDlgGaika.Free;
      EnableTaskAccess(1);
      bufGayka.Free;
    end;
    CloseGaykaBase(gBase);
  end
end;

//-------------------------------------------------------------------------------
//
//------
function Gayka.EditSpcObj( var spcObj : reference; geom : reference ) : reference;
begin
  result := Gayka.StaticEditSpcObj ( flagMode, tmp,  spcObj, geom, par.flagAttr );
end;

//-------------------------------------------------------------------------------
//
//------
function Gayka.IsSpcObjCreate: boolean; //функция проверки подключения атрибутов или нет
begin
  result :=SPCOBJ_CREATE;
end;

//-----------------------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------------------
class function Gayka.StaticEditSpcObj ( flagMode:boolean; tmp:GAYKA5915;
                                  var spcObj : reference; geom : reference; flagAttr:word ):reference ;
var
  uBuf  : cardinal;
  massa : single;
  buf   : AnsiString;
begin
  if ( not flagMode ) and ( flagAttr = 0 ) then
  begin
    result := 0;
    exit;
  end;
  if( flagMode ) then
  begin
    spcObj := ksGetSpcObjForGeomWithLimit( nil , //имя библиотеки типов
                                            0,         //   номер типа спецификации
                                            geom,
                                            0, // 1 - присланная геометрия идентична геометрии объекта СП; 0- входит в объект СП
                                            1, // 1 -первый объект 0- следующий объект
                                            STANDART_SECTION,    //номер раздела
                                            297327484710.0 ); //номер типа трибута "Гайка" в spc.lat
    if( flagAttr=0 ) then
    begin
      result := spcObj;
      exit;
    end;

    if ( spcObj<>0 ) and (ksSpcObjectEdit( spcObj )=0 ) then
      spcObj  := 0;
  end;

 flagMode  := spcObj<>0;
 //создаем объект спецификации для умолчательногостиля СП
 if( flagMode )  or ( ksSpcObjectCreate( nil , //имя библиотеки типов
                                         0,         //   номер типа спецификации
                                         STANDART_SECTION,  0,    //номер раздела и подраздела
                                         297327484710.0,0 )<>0) then    //тип атрибута
 begin

    //исполнение
    if( (tmp.f and ISPOLN)=0 ) then
      ksSpcVisible( SPC_NAME, 2, 0 )
    else begin
      uBuf := 2;
      ksSpcVisible( SPC_NAME, 2, 1 );
      ksSpcChangeValue( SPC_NAME , 2, Addr(uBuf), UINT_ATTR_TYPE  );
    end;
    //изменим диаметр
   ksSpcChangeValue( SPC_NAME , 4, Addr(tmp.dr), FLOAT_ATTR_TYPE  );

    //отследим мелкий шаг
    if( (tmp.f and PITCH)=0 )then//выключить шаг и его разделитель
    begin
      ksSpcVisible( SPC_NAME, 5, 0 );
      ksSpcVisible( SPC_NAME, 6, 0 );   //щаг
    end
    else begin
      ksSpcVisible( SPC_NAME, 5, 1 );
      ksSpcVisible( SPC_NAME, 6, 1 );   //щаг
      ksSpcChangeValue( SPC_NAME , 6, Addr(tmp.p), FLOAT_ATTR_TYPE );
    end;

    // выключим поле допуска
    if( not flagMode ) then
      ksSpcVisible( SPC_NAME, 7, 0 );

    // выключим класс прочности
    if( not flagMode ) then
      ksSpcVisible( SPC_NAME, 8, 0 );

   // выключим материал
   if( not flagMode ) then
     ksSpcVisible( SPC_NAME, 9, 0 );

   // выключим покрытие
   if( not flagMode  ) then
     ksSpcVisible( SPC_NAME, 10, 0 );

   //изменим ГОСТ
   uBuf := tmp.gost;
   ksSpcChangeValue( SPC_NAME , 12, Addr(uBuf), UINT_ATTR_TYPE  );

   massa := tmp.massa;
   case ( tmp.indexMassa) of
     0 : begin massa:=massa/COUNT_MASSA; end;
     1 : begin massa:=massa*0.356/COUNT_MASSA; end;
     2 : begin massa:=massa*1.08/COUNT_MASSA; end;
   end;
   buf := Format('%f', [massa] );
   ksSpcMassa ( PAnsiChar(buf) );        //масса детали

   //подключим геометрию
   if ( geom<>0 ) then
     ksSpcIncludeReference( geom, SPC_CLEAR_GEOM  );

   result :=ksSpcObjectEnd;
   exit;
 end;
 result := 0;
end;


function GetGayka( gost : word): Gayka;
begin
  result := Gayka.Create( gost );
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
function Gayka.GetHotPoints( point : PHotPointDescription; index : Integer ) : LongBool; stdcall;
begin
  result := false;
  case ( index ) of
       0 : begin // точка привязки
             point^.x := 0;
             point^.y := 0;
             point^.text := '0';
             result := true;
           end;
       1 : begin // изменение диаметра
             point^.x := 0;
             point^.y := tmp.dr / 2.0;
             point^.cursorInst := HInstance;
             point^.cursorId   := CURSOR_DIAMETER;
             point^.text       := 'Dr';
             result := true;
           end;
       2 : begin // угол поворота
             if ( par.drawType = ID_TOPVID ) then
                point^.x := tmp.s / 2.0
             else
                point^.x := tmp.h;

             point^.y := 0;
             point^.cursorInst := HInstance;
             point^.cursorId   := CURSOR_ROTATE;
             point^.text       := 'A';
              result := true;
           end;
  end;
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
function  Gayka.SetHotPoint( point : PHotPointDescription;  index : Integer ) : LongBool;
var
  x, y, alpha, ang : Double;
  gr : Reference;
begin
  gr := 0;
  if ( GetMacroPlacement(0, x, y, alpha) > 0 ) then begin
    case ( index ) of
        0 : begin
              refMacr := 0;
              SetParam();
              SetMacroPlacement( refMacr, point^.x, point^.y, 0.0, 1 );
            end;
        1 : begin
              if ( ChangeHotPointParam(Abs(point^.y * 2)) ) then begin
                GetGroup( gr );
              	SetParam();
              	SetMacroPlacement( refMacr, 0.0, 0.0, 0.0, 1 );
                StoreTmpGroup( gr );
                ClearGroup( gr );
              end;
            end;
        2 : begin
              refMacr := 0;
              if ( point^.y = 0 ) then
                ang := 0.0
              else
                if ( point^.x = 0 ) then
                  ang := 90.0
                else
                  ang := AtanD( point^.y / point^.x );

              par.ang := par.ang + ang;
              SetParam();
              SetMacroPlacement( refMacr, 0.0, 0.0, ang, 1 );
            end;
    end;
  end;
  result := True;
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
function  Gayka.GetCursorText( index : Integer; Var text : PAnsiChar ) : LongBool; stdcall;
begin
  result := false;
  case ( index ) of
    2 : begin
        cursorText := Format('A = %.2f',[par.ang]);
        text := PAnsiChar(cursorText);
        result := true;
        end;
    1 : begin
        cursorText := Format('D = %.2f'+#10+'H = %.2f',[tmp.dr, tmp.h]);
        text := PAnsiChar(cursorText);
        result := true;
        end;
  end;
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
function  Gayka.GetMenu : integer; stdcall;
var
  menu : HMENU;
begin
  menu := LoadMenu( HInstance, MAKEINTRESOURCE( GAIKA_POPUPMENU ) );
  CheckMenuItem( menu, par.drawType, MF_BYCOMMAND or MF_CHECKED );
  if ( par.drawType <> ID_VIDSEC ) Then
  Begin
    EnableMenuItem( menu, ID_HATCH_ANG,  MF_BYCOMMAND or MF_GRAYED );
    EnableMenuItem( menu, ID_HATCH_SHAG, MF_BYCOMMAND or MF_GRAYED );
  end;
  result := integer(menu);
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
function  Gayka.ExecuteCommand( id : Integer ) : LongBool; stdcall;
var
  x, y, alpha{, ang} : Double;
  gr : Reference;
begin
  if ( GetMacroPlacement(0, x, y, alpha)=1 ) then begin
    case ( id ) of
      ID_PARAM : MacroElementParam();
      ID_VID, ID_TOPVID, ID_SIDEVID, ID_VIDSEC  : begin
          par.drawType := id;
          FuncAfteDrawType();
          end;
      ID_HATCH_ANG :  SetHatchAngl();
      ID_HATCH_SHAG : SetHatchShag();
    end;

    GetGroup( gr );
    SetParam();
    SetMacroPlacement( refMacr, 0.0, 0.0, 0.0, 1 );
    StoreTmpGroup( gr );
    ClearGroup( gr );
  end;

  result := True;
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
function Gayka.EditComplete( index : Integer; success : LongBool ) : LongBool; stdcall;
var
  i, count : integer;
begin
  if (index = 1) And ( success ) then
  begin
    obj := Addr(self);
    DrawSpcObj( 0 );
    if ( spcObj[0] <> 0 ) Then
    begin
      count := obj^.GetObjCount();
      for i := 0 to count-1 do
      begin
        if ksEditWindowSpcObject( spcObj[i] ) <>0  then
          DrawPosLeader(spcObj[i]);
      end;
    end;
  end;
  result := True;
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
function  Gayka.ChangeHotPointParam( d : Double ) : LongBool;
type
  StTmpL = packed record
    s : array [0..19] of AnsiChar;
    dr : single;
  end;
var
  dR    : double;
  oldDR, tmpdR : double;
  code,i : integer;
  tmpL : StTmpL ;
begin
  // подобрать ближайший dR по d
  dR := 0.0;

  oldDR := tmp.dr;
  result := false;
  if OpenGaykaBase(gBase) <> 0 then
  begin
    i:=1;
    while( i<>0 ) do
    begin
      i:=ReadRecord(  gBase.bg, gBase.rg1, @tmpL );

      if ( i<>0 )  then
      begin
        Val( tmpL.s, tmpdR, code );
        if ( tmpdR <= d ) then
          dR := tmpdR
        else
          i := 0;
      end;
    end;

    if ( abs( dR - oldDR ) > 0.01 ) then
      result := LongBool(ReadGaykaBase ( dR, gBase, tmp ));
    CloseGaykaBase ( gBase );
  end;
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
function  OpenGaykaBase ( var base : SimpleBase ): integer;
begin
  base.bg := CreateDB('TXT_DB');  //TXT_DB

  if( _ConnectDB(base.bg, '5915.loa')=0 ) then //"5915.loa"
  begin
    result := 0;
    exit;
  end
  else begin
    base.rg1 := Relation( base.bg );
      RChar( '', 20,0 );
      RFloat('dr');
    EndRelation();
    if ( DoStatement(base.bg, base.rg1, '1 1' )=0 ) then //"1 1"
    begin
      result:= 0;
      exit;
    end
    else begin
      base.rg2 := Relation( base.bg );
        RFloat('dr');
        RFloat('');
        RFloat('');
        RFloat('');
        RFloat('');
        RFloat('');
        RFloat('');
        RFloat('');
        RFloat('');
        RFloat('');
        RFloat('');
        RFloat('');
      EndRelation();
      if ( DoStatement( base.bg, base.rg2, '')=0 )then //TXT_ALL
      begin
        result :=0;
        exit;
      end
      else
        result:=1;
    end;
  end;
end;

//--------------------------------------------------------------------------
//
//--------------------------------------------------------------------------
procedure CloseGaykaBase ( base : SimpleBase  );
begin
  DeleteDB( base.bg );
end;

//--------------------------------------------------------------------------
//  Читать параметры гайки по диаметру
//  возвращает 1 - успех 0 - не найдено записи , ошибка связи с БД
//--------------------------------------------------------------------------
function  ReadGaykaBase ( d : single; base : SimpleBase; var lpG : GAYKA5915 ): integer;
var
  s    : AnsiString;
  gTmp : GaykaTMP ;
     i :  integer;
begin
  {$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 17 }
   with  System.SysUtils.FormatSettings do
 {$IFEND}
{$IFEND}
   begin
     DecimalSeparator:='.';
   end;
  s := Format(  'dr=%.1f', [d] );    //dr=%.0f
  if ( Condition(base.bg, base.rg2, PAnsiChar(s))=0 ) then begin result := 0; exit; end;
  i := ReadRecord( base.bg, base.rg2, Addr(gTmp) );
  if ( i<>0 ) then
  begin

    lpG.dr := gTmp.dr;
    lpG.da := gTmp.da;
    lpG.h  := gTmp.h;
    lpG.d2 := gTmp.d2;

    if ( (lpG.f And PITCH)<>0 )  then lpG.p := gTmp.p2  else  lpG.p := gTmp.p1;

   if ( abs( gTmp.p2 - gTmp.p1 ) < 0.001 ) then
     lpG.f := lpG.f or PITCHOFF
   else
     lpG.f := lpG.f or PITCHOFF xor PITCHOFF;
   if( (lpG.f1 And KEY_S_ON)<>0 ) And (abs(gTmp.s1)> 0.001 ) then
     lpG.f1 := lpG.f1 or KEY_S_GRAY
   else begin
       lpG.f1 := lpG.f1 or KEY_S_GRAY xor KEY_S_GRAY;
       lpG.f1 := lpG.f1 or KEY_S xor KEY_S;
   end;
   if ( (lpG.f1 and KEY_S_ON)<>0) and ((lpG.f1 and KEY_S )<>0) then
   begin
     lpG.s      := gTmp.s1;    ///*размер под ключ*/
     lpG.D      := gTmp.D1;    ///* диаметр описанной окружности*/
     lpG.massa  := gTmp.m1;
   end
   else begin
     lpG.s      := gTmp.s;    ///*размер под ключ*/
     lpG.D      := gTmp.D;    ///* диаметр описанной окружности*/
     lpG.massa  := gTmp.m;
   end;

    result:= 1;
    exit;
  end;
  result := 0;
end;


end.
