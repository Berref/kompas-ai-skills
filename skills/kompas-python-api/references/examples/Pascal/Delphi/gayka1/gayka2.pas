unit gayka2;

interface
uses
  Forms, Controls, Windows, SysUtils, LtDefine, LibTool,
  Base, LibDB, LibHpPar, LDefin2D, GaykaRC, ManagerEvents, ksConstTlb,
{$IFDEF __LIGHT_VERSION__}
  klAPI7;
{$ELSE}
  ksApi7;
{$ENDIF}

const

  BF_ISPOLN   : Byte = $1;  // исполнение = 0 - 1 > 0 исполнение 2
  BF_PITCH    : Byte = $2;  // крупный шаг >0 мелкий шаг
  BF_PITCH_ON : Byte = $4;  // есть крупный и мелкий шаг >0 есть только крупный
  BF_KEY_S    : Byte = $8;  // 0-обычный размер под ключ; > 0 дополнительный
  BF_KEY_S_ON : Byte = $F;  // 0- выключены дополнитеоьные размеры под ключ > 0 - включены
  // коэффициент для расчета диаметра резьбы по шагу резьбы
  MODSTEP_REAL : Double = 0.5412765877;

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

//------------------------------------------------------------------------------
// Флаги гайки ГОСТ 5915
// ---
//struct G5915Flags {
//  bool isp       : 1; // FALSE - исполнение 1,            TRUE - исполнение 2
//  bool pitch     : 1; // FALSE - крупный шаг,             TRUE - мелкий шаг
//  bool pitch_on  : 1; // FALSE - есть только крупный шаг, TRUE - есть крупный и мелкий шаг
//  bool key_s     : 1; // FALSE - обычный размер под ключ, TRUE - дополнительный размер под ключ,
//  bool key_s_on  : 1; // FALSE - греить "Дополнитеоьные размеры под ключ"
//};

//---------------------------------------------------------------------------
GAYKA5915 = record
  dr         : single;
  s          : single;
  D          : single;
  da         : single;
  h          : single;
  d2         : single;
  p          : single;
  klass      : SmallInt;  //класс точности
  gost       : word;      //номер госта
  hatchAngle : single;
  hatchStep  : single;
  massa      : single;
  indexMassa : byte;      //0-металл 1- алюмин сплав 2-латунь
  flags      : byte;      //битовые маски
  { // G5915Flags
    bool isp       : 1; // FALSE - исполнение 1,            TRUE - исполнение 2
    bool pitch     : 1; // FALSE - крупный шаг,             TRUE - мелкий шаг
    bool pitch_on  : 1; // FALSE - есть только крупный шаг, TRUE - есть крупный и мелкий шаг
    bool key_s     : 1; // FALSE - обычный размер под ключ, TRUE - дополнительный размер под ключ,
    bool key_s_on  : 1; // FALSE - греить "Дополнитеоьные размеры под ключ"
  }
end;

//------------------------------------------------------------------------------
PGayka = ^Gayka;
Gayka = class( CPar )

protected
  m_GaykaParam : GAYKA5915 ;

public

  constructor Create( comm :Integer; ref : reference; gost_ : word );
  procedure   Assign( other: CPar );   override; // оператор присваивания
  destructor  Destroy;                 override;

//*******************ЭТИ ФУКЦИИ НЕОБХОДИМЫ ЭЛЕМЕНТУ*****************************
  // виртуальные функции для работы  с элементом
  function    OpenBase(): Boolean;     override; // открыть БД
//  procedure   CloseBase();             override; // закрыть БД
  procedure   GetGroup;                override;

//  function    GetPromptID: Integer;    override;
  procedure   SetParam;                override;
  function    GetSize:        Integer; override;
  function    IsSpcObjCreate: Boolean; override; // функция проверки подключения атрибутов или нет
  function    _EditSpcObj   : Boolean; override;
  function    AttrNumber    : Double;  override; // номер атрибута
//*******************ЭТИ ФУКЦИИ НЕОБХОДИМЫ ЭЛЕМЕНТУ*****************************

// HOT_POINTS ##################################################################
  function  GetHotPoints( point : PHotPointDescription;  index : Integer ) : LongBool; override;
  function  SetHotPoint(  point : PHotPointDescription;  index : Integer ) : LongBool; override;
  function  GetCursorText( index : Integer; Var text : PAnsiChar )         : LongBool; override;
  function  EditComplete( index : Integer; success : LongBool )            : LongBool; override;
  function  ChangeHotPointParam( d : Double )                              : Boolean;
// HOT_POINTS ##################################################################

  // Отрисовать группу
  procedure RedrawPreview;               override;
  // Количество параметров выводимых в гриде
  function  GetParamCount : Integer;     override;

// Менеджер свойств ############################################################
  // События
  // prButtonClick - Нажатие кнопки.
  procedure OnButtonClick( buttonID : Integer ); override;

  //prChangeControlValue - Изменение значения контрола
  procedure OnChangeControlValue( {var cntrl : IPropertyControl,} ctrlID : LongInt; const Val: Variant );  override;

  // puCreateOCX - Cобытие создания пользовательского контрола
  //  procedure  OnCreateOCX( ctrlID : LongInt; var control : IDispatch ); override;

  //prControlCommand Нажатие кнопки контрола
  // function OnControlCommand(LPUNKNOWN  ctrl);  override;

  //prButtonUpdate        - Установка состояния кнопки спецпанели.
  // function OnButtonUpdate(long buttonID, long* check, BOOL* _enable);  override;
          // Инициализация параметров процесса

  // Виртуальная функция наполнения контролов элемента
  procedure ShowControls;  override;

  // Виртуальная функция вывода параметров элемента
  procedure ShowParam;  override;

// Менеджер свойств ############################################################

protected
// Свойства
  function  GetIsp          : Integer;
  procedure SetIsp(   val   : Integer );
  function  GetPitch        : Boolean;
  procedure SetPitch( val   : Boolean );
  function  GetPitchOn      : Boolean;
  procedure SetPitchOn( val : Boolean );
  function  GetKeyS         : Boolean;
  procedure SetKeyS( val    : Boolean );
  function  GetKeySOn       : Boolean;
  procedure SetKeySOn( val  : Boolean );

  // Параметры штриховки
  procedure SetHatchStep(  step  : Double ); override;
  procedure SetHatchAngle( angle : Double ); override;
  function  GetHatchStep         : Double;   override;
  function  GetHatchAngle        : Double;   override;

  // Признак наличия штриховки у объекта
  function  IsHatchObject        : Boolean;  override;

  // Масса
  function  GetMassa             : Double;   override;

public

  // исполнение 1 или 2
  property  Isp     : Integer read GetIsp     write SetIsp;
  // FALSE - крупный шаг,     TRUE - мелкий шаг
  property  Pitch   : Boolean read GetPitch   write SetPitch;
  // FALSE - есть только крупный шаг, TRUE - есть крупный и мелкий шаг
  property  PitchOn : Boolean read GetPitchOn write SetPitchOn;
  // FALSE - обычный размер под ключ, TRUE - дополнительный размер под ключ
  property  KeyS    : Boolean read GetKeyS    write SetKeyS;
  // FALSE - греить "Дополнитеоьные размеры под ключ"
  property  KeySOn  : Boolean read GetKeySOn  write SetKeySOn;
  // Количество параметров
  property  ParamCount : Integer read GetParamCount;

protected
  procedure   InitParam;
  procedure   gayka_sverhu( appl : boolean );
  procedure   gayka_p_k( j : integer; appl : boolean );

end;

function GetGayka( command : Integer; ref : Reference; gost : Word ) : CPar;
//function GetGayka( gost : word): Gayka;
procedure  gayka_k( ls, l, d1, s, D, l1, H : single;  j : smallInt; j1 : integer;
                    d2 : single; j2 : integer; appl : boolean ) ;
procedure  gayka_k_side( ls, s, D, d2, H : single; j, j2 : integer; appl : boolean );
procedure  gayka_k_y( ls : single; var tmp : GAYKA5915; j : integer; appl : boolean );
function   OpenGaykaBase ( var base : SimpleBase ): integer;
//procedure  CloseGaykaBase ( base : SimpleBase  );
function   ReadGaykaBase ( d : single; base : SimpleBase; var lpG : GAYKA5915 ): integer;

var
  textForHP_2 : PChar; // обязательно должен быть описан как static
  cursorText  : AnsiString;

implementation

//------------------------------------------------------------------------------
//     Гайки нормальные классов точности А,В,С
//     ГОСТ 5915
//------
constructor Gayka.Create(  comm :Integer; ref : reference; gost_ : word );
begin
  inherited create(  comm {comm = CM_GAYKA}, ref );
  FillChar( m_GaykaParam, sizeof( m_GaykaParam), 0 );
  if ( ( ref = 0 ) or ( GetMacroParam( m_refMacr, GetAddr, Size ) = 0 ) ) then
  begin
    m_GaykaParam.gost := gost_;
    InitParam;
  end;
end;

//------------------------------------------------------------------------------
//  Инициализация параметров
//------
procedure Gayka.InitParam;
begin
  with m_GaykaParam do
  begin
    hatchAngle := 45;
    hatchStep  := 2;
    flags      := 0;
    dr         := 20;
    p          := 2.5;
    indexMassa := 0;
    case ( gost ) of
      5915 : begin
        s      := 30;
        D      := 33;
        da     := 21.6;
        h      := 16;
        d2     := 27.7;
        klass  := 2;
        flags  := BF_KEY_S_ON; // KeySOn = true
        massa  := 71.44;
      end;
    end
  end
end;

//------------------------------------------------------------------------------
//
//---
destructor Gayka.Destroy;
begin
  inherited Destroy;
end;

//------------------------------------------------------------------------------
// Присваивание
//---
procedure Gayka.Assign( other : CPar );  // оператор присваивания
var
  p : Gayka;
begin
  inherited  Assign( other );
  p := Gayka(other);
  Move( p.m_GaykaParam, m_GaykaParam, sizeof(m_GaykaParam));
end;

//------------------------------------------------------------------------------
// Исполнение
//---
function Gayka.GetIsp : Integer;
begin
  Result := ( m_GaykaParam.flags and BF_ISPOLN ) + 1;
end;

//------------------------------------------------------------------------------
// Исполнение
//---
procedure Gayka.SetIsp( val : Integer );
begin
  SetBitFlag( m_GaykaParam.flags, BF_ISPOLN, val = 2 );
end;

//------------------------------------------------------------------------------
// Шаг резьбы
//---
function Gayka.GetPitch   : Boolean;
begin
  Result := ( ( m_GaykaParam.flags and BF_PITCH ) <> 0 );
end;

//------------------------------------------------------------------------------
// Шаг резьбы
//---
procedure Gayka.SetPitch( val : Boolean );
begin
  SetBitFlag( m_GaykaParam.flags, BF_PITCH, val );
end;

//------------------------------------------------------------------------------
// Шаг резьбы включен
//---
function Gayka.GetPitchOn : Boolean;
begin
  Result := ( m_GaykaParam.flags and BF_PITCH_ON ) <> 0;
end;

//------------------------------------------------------------------------------
// Шаг резьбы включен
//---
procedure Gayka.SetPitchOn( val : Boolean );
begin
  SetBitFlag( m_GaykaParam.flags, BF_PITCH_ON, val );
end;

//------------------------------------------------------------------------------
// Размер под ключ
//---
function Gayka.GetKeyS: Boolean;
begin
  Result := ( m_GaykaParam.flags and BF_KEY_S ) <> 0;
end;

//------------------------------------------------------------------------------
// Размер под ключ
//---
procedure Gayka.SetKeyS( val : Boolean );
begin
  SetBitFlag( m_GaykaParam.flags, BF_KEY_S, val );
end;

//------------------------------------------------------------------------------
// Размер под ключ есть
//---
function Gayka.GetKeySOn: Boolean;
begin
  Result := ( m_GaykaParam.flags and BF_KEY_S_ON ) <> 0;
end;

//------------------------------------------------------------------------------
// Размер под ключ есть
//---
procedure Gayka.SetKeySOn( val : Boolean );
begin
  SetBitFlag( m_GaykaParam.flags, BF_KEY_S_ON, val );
end;

//------------------------------------------------------------------------------
//
//------
procedure gayka_k( ls, l, d1, s, D, l1, H : single;  j : smallInt; j1 : integer;
                   d2 : single; j2 : integer; appl : boolean );
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
    if not appl then
    begin
      LineSeg( x[7], y[7], x[8], y[8], 1 );
      ArcByPoint( xcbl, ycbl, rb, x[1], y[1], x[7], y[7], -j, 1 );
      ArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
      ArcBy3Points( ls + c * 0.5, (D * 0.5 - (D - d2) / 4) * j,
                    ls, ycml, x[7], y[7], 1 );
      ArcBy3Points( ls + H - c * 0.5, (D * 0.5 - (D - d2) / 4) * j, ls + H,
                      ycml, x[8], y[8], 1 );
    end
  end
  else begin
    LineSeg( x[1], y[1], x[2], y[2], 1 );
    LineSeg( x[2], y[2], x[4], y[4], 1 );
    LineSeg( x[4], y[4], x[5], y[5], 1 );
    LineSeg( x[5], y[5], x[6], y[6], 1 );
    if not appl then
    begin
      LineSeg( x[7], y[7], x[8], y[8], 1 );
      ArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
      ArcBy3Points( ls + H - c * 0.5, (D * 0.5 - (D - d2) / 4) * j,
                    ls + H, ycml, x[8], y[8], 1 );
    end
  end;

  if not appl and ( j1 = 1 ) then
  begin
    Circle( xc2, yc2, d1 * 0.5, 1 );
    LineSeg( xc2 - 2, yc2, xc2 + 2, yc2, 2 );
    LineSeg( xc2, yc2 - 2, xc2, yc2 + 2, 2 );
  end;

end;

//------------------------------------------------------------------------------
//
//---
procedure gayka_k_side( ls, s, D, d2, H : single; j, j2 : integer; appl : boolean );
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
    if not appl then
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
    if not appl then
      ArcBy3Points( ls + H - c, j * (s * 0.5), ls + H,s * 0.25 * j,
                    ls + H - c, 0, 1 );
  end;
  LineSeg( ls + H, y2, ls + H, 0, 1 );
  if not appl and ( j > 0 ) then
    LineSeg( x, 0, x2, 0, 1 );
end;

//------------------------------------------------------------------------------
//
//------
procedure gayka_k_y( ls : single; var tmp : GAYKA5915; j : integer; appl: boolean );
var
  h1 : single;

begin
  tmp.D := tmp.s / CosD( 30 );

  h1 := tmp.D * 0.5 * SinD( 30 );

  LineSeg( ls, 0, ls, j * (tmp.D * 0.5 ), 1 );
  LineSeg( ls, j * ( tmp.D * 0.5), ls + tmp.h, j * (tmp.D * 0.5), 1 );
  LineSeg( ls + tmp.h, j * (tmp.D * 0.5), ls + tmp.h, 0, 1 );
  if not appl then
    LineSeg( ls, j * h1, ls + tmp.h, j * h1, 1 );
end;

//------------------------------------------------------------------------------
// Получить группу
//------
procedure Gayka.GetGroup;
var
  k2 : integer;
begin

  with m_GaykaParam do
    case DrawType of
      // вид ссверху
      ID_TOP  :
      begin
        // Рисуем аппликативную заливку
        ksColouring( WORKWINDOWCOLOR );
          gayka_sverhu( true );
        EndObj;
        // рисуем основную графику
        gayka_sverhu( false );
      end;
      // вид
      ID_VIEW :
      begin

        if Simple then
        begin
        // Рисуем аппликативную заливку
          ksColouring( WORKWINDOWCOLOR );
            gayka_k_y( 0, m_GaykaParam,  1, true );
            gayka_k_y( 0, m_GaykaParam, -1, true );
          EndObj();
          // рисуем основную графику
          gayka_k_y( 0, m_GaykaParam,  1, false );
          gayka_k_y( 0, m_GaykaParam, -1, false );
        end
        else begin
          // Рисуем аппликативную заливку
          ksColouring( WORKWINDOWCOLOR );
            gayka_k( 0, 0, 0, s, D, 0, h,  1, 0, d2, Isp, true );
            gayka_k( 0, 0, 0, s, D, 0, h, -1, 0, d2, Isp, true );
          EndObj();
          // рисуем основную графику
          gayka_k( 0, 0, 0, s, D, 0, h,  1, 0, d2, Isp, false );
          gayka_k( 0, 0, 0, s, D, 0, h, -1, 0, d2, Isp, false );
        end;

        if Axis then
          LineSeg( -AXIS_END, 0, h + AXIS_END, 0, AXIS_LINE );
      end;

      // вид сбоку
      ID_LEFT :
      begin
        if Axis then
          LineSeg( -AXIS_END, 0, h + AXIS_END, 0, AXIS_LINE );

        if Simple then
          k2 := 3
        else
          k2 := Isp;

        // Рисуем аппликативную заливку
        ksColouring( WORKWINDOWCOLOR );
          gayka_k_side( 0, s, D, d2, h,  1, k2, true );
          gayka_k_side( 0, s, D, d2, h, -1, k2, true );
        EndObj();
        // рисуем основную графику
        gayka_k_side( 0, s, D, d2, h,  1, k2, false );
        gayka_k_side( 0, s, D, d2, h, -1, k2, false );
      end;

      // пол-вида/пол-разреза
      ID_SEC:
      begin
        if Simple then
        begin
          // Рисуем аппликативную заливку
          ksColouring( WORKWINDOWCOLOR );
            gayka_k_y( 0, m_GaykaParam, 1, true );
            gayka_p_k( -1, true );
          EndObj();
          // рисуем основную графику
          gayka_k_y( 0, m_GaykaParam, 1, false );
          gayka_p_k( -1, false );
        end
        else begin
          // Рисуем аппликативную заливку
          ksColouring( WORKWINDOWCOLOR );
            gayka_k( 0, 0, 0, s, D, 0, h, 1, 0, d2, Isp, true );
            gayka_p_k( -1, true );
          EndObj();
          // рисуем основную графику
          gayka_k( 0, 0, 0, s, D, 0, h, 1, 0, d2, Isp, false );
          gayka_p_k( -1, false );
        end;
        if Axis then
          LineSeg( -AXIS_END, 0, h + AXIS_END, 0, AXIS_LINE );
      end;
    end;
end;

//------------------------------------------------------------------------------
// Установить параметры
//---
procedure Gayka.SetParam;
begin
  ksSetMacroParam( m_refMacr, GetAddr, Size, nil, nil, -1, MP_HOTPOINTS );
end;

//------------------------------------------------------------------------------
// Размер
//------
function Gayka.GetSize: integer;
begin
  result:= GetCParSize + sizeof(m_GaykaParam);
end;

//------------------------------------------------------------------------------
// Шаг
//------
procedure Gayka.SetHatchStep( step : Double );
begin
  m_GaykaParam.hatchStep := step;
end;

//------------------------------------------------------------------------------
// Угол
//------
procedure Gayka.SetHatchAngle( angle : Double );
begin
  m_GaykaParam.hatchAngle := angle;
end;

//------------------------------------------------------------------------------
// Шаг
//------
function Gayka.GetHatchStep : Double;
begin
  Result := m_GaykaParam.hatchStep;
end;

//------------------------------------------------------------------------------
// Угол
//------
function Gayka.GetHatchAngle;
begin
  Result := m_GaykaParam.hatchAngle;
end;

//------------------------------------------------------------------------------
// Вид сверху
//------
procedure Gayka.gayka_sverhu( appl : boolean );
var
  DD2, ss2 : single;
  h12, dd3 : single;

begin
  with m_GaykaParam do
  begin
    ss2 := s * 0.5;
    DD2 := ss2 / cosd( 30 );
    dd3 := dr - 2 * MODSTEP_REAL * p;

    h12 := DD2 * sind( 30 );

    LineSeg( -ss2,  h12,    0,  DD2, BASE_LINE );
    LineSeg(    0,  DD2,  ss2,  h12, BASE_LINE );
    LineSeg(  ss2,  h12,  ss2, -h12, BASE_LINE );
    LineSeg(  ss2, -h12,    0, -DD2, BASE_LINE );
    LineSeg(    0, -DD2, -ss2, -h12, BASE_LINE );
    LineSeg( -ss2, -h12, -ss2,  h12, BASE_LINE );

    if not appl and not Simple then
      Circle( 0, 0, d2  * 0.5, BASE_LINE );

    Circle(   0, 0, dd3 * 0.5, BASE_LINE );

    if not appl then
      ArcByPoint( 0, 0, dr * 0.5, dr * 0.5 * sind(15),
                                  dr * 0.5 * cosd(15),
                                  dr * 0.5 * cosd(15),
                                 -dr * 0.5 * sind(15), 1, SLIM_LINE );

    if not appl and Axis then
    begin
      if D >= 6 then
      begin
        LineSeg(    -AXIS_END - ss2, 0, ss2 + AXIS_END, 0, AXIS_LINE );
        LineSeg( 0, -AXIS_END - DD2, 0, DD2 + AXIS_END,    AXIS_LINE );
      end
      else
      begin
        LineSeg(  -1 - s, 0, s + 1, 0, AXIS_LINE );
        LineSeg(  0, -1 - D, 0, 1 + D, AXIS_LINE );
      end;
    end;
  end;
end;

//------------------------------------------------------------------------------
//
//------
procedure Gayka.gayka_p_k( j : integer; appl : boolean );
var
  c, dd, c1, c2 : single;
  y, x , x1, x2, x3, y3, y2 : single;

begin
  c1 := 0; c2 := 0;
  x  := 0;
  with m_GaykaParam do
  begin
    c := ( D - d2 ) * 0.5 * tand( 30 );

    if ( Isp = 1 ) And not Simple then
      y := j * d2 * 0.5
    else
      y := j * D  * 0.5;

    LineSeg( 0, 0, 0, y, BASE_LINE );

    if ( Isp = 1 ) and not Simple then
    begin
      x := c;
      LineSeg( 0, y, x, j * (D * 0.5), BASE_LINE );
    end;

    dd := dr - 2 * MODSTEP_REAL * p;

    if Simple then
    begin
      x3 := h;
      y3 := j * D  * 0.5;
      y2 := j * dd * 0.5;
    end
    else  begin
      x3 := h - c ;
      y3 := j * d2 * 0.5;
      y2 := j * da * 0.5;
    end;

    LineSeg( x, j * D * 0.5, x3, j * D * 0.5, BASE_LINE );

    if not Simple then
      LineSeg( x3, j * D * 0.5, h, y3, BASE_LINE );

    LineSeg( h, y3, h, 0, BASE_LINE );

    x1 := h;
    x2 := x1;
    if not appl then
    begin
      if not Simple then
      begin
        c1 := ( da - dd ) * 0.5;
        c2 := ( da - dr ) * 0.5;
        if Isp = 1 then
          x2 := x2 - c2;
      end;


      if ( Isp = 1 ) and not Simple then
      begin
        x1 := x1 - c1;
        LineSeg(    h, j * da * 0.5,  x1, j * dd * 0.5, BASE_LINE );
        LineSeg(   x1, j * dd * 0.5,  x1,            0, BASE_LINE );
      end;

      LineSeg(     x1, j * dd * 0.5,  c1, j * dd * 0.5, BASE_LINE );

      if not Simple then
      begin
        LineSeg(   c1, j * dd * 0.5,   0, j * da * 0.5, BASE_LINE );
        LineSeg(   c1, j * dd * 0.5,  c1,            0, BASE_LINE );
      end;

      Hatch( 0, HatchAngle, HatchStep, 0, 0, 0 );

        LineSeg(    0,     y2,        0,      y      , BASE_LINE );

        if ( Isp = 1 ) and not Simple then
          LineSeg(  0,     y,         x, j *  D * 0.5, BASE_LINE );

        LineSeg(    x, j * D * 0.5,  x3, j *  D * 0.5, BASE_LINE );

        if not Simple then
          LineSeg( x3, j * D * 0.5,   h,     y3      , BASE_LINE );

        if ( Isp = 1 ) and not Simple then
          LineSeg( h,      y3,        h, j * da * 0.5, BASE_LINE )
        else
          LineSeg( h,      y3,        h, j * dd * 0.5, BASE_LINE );


        if ( Isp = 1 ) and not Simple then
          LineSeg( h,  j * da * 0.5, x1, j * dd * 0.5, BASE_LINE );

        LineSeg(   x1, j * dd * 0.5, c1, j * dd * 0.5, BASE_LINE );

        if Simple then
          LineSeg( c1, j * dd * 0.5,  0, j * da * 0.5, BASE_LINE );

      EndObj;

      LineSeg(    c2,  j * dr * 0.5, x2, j * dr * 0.5, SLIM_LINE );
    end
  end;
end;

//------------------------------------------------------------------------------
// Функция проверки подключения атрибутов
//---
function Gayka.IsSpcObjCreate: boolean;
begin
  result := true;
end;

//------------------------------------------------------------------------------
// Номер атрибута
//---
function Gayka.AttrNumber : Double; // номер атрибута
begin
  Result := 297327484710.0;
end;

//------------------------------------------------------------------------------
// Масса
//---
function Gayka.GetMassa: Double;
begin
  Result := m_GaykaParam.massa / COUNT_MASSA;
  case ( m_GaykaParam.indexMassa ) of
     1 : Result := Result * 0.356;
     2 : Result := Result * 1.08;
  end;
end;

//------------------------------------------------------------------------------
// Редактирование
//---
function Gayka._EditSpcObj: Boolean;
var
  uBuf : cardinal;
begin

  with m_GaykaParam do
  begin
    //исполнение
    if Isp = 1 then
      ksSpcVisible( SPC_NAME, 2, 0 )
    else begin
      uBuf := 2;
      ksSpcVisible( SPC_NAME, 2, 1 );
      ksSpcChangeValue( SPC_NAME , 2, Addr(uBuf), UINT_ATTR_TYPE  );
    end;

    //изменим диаметр
    ksSpcChangeValue( SPC_NAME , 4, Addr(dr), FLOAT_ATTR_TYPE  );

    //отследим мелкий шаг
    if Pitch then  // выключить шаг и его разделитель
    begin
      ksSpcVisible( SPC_NAME, 5, 0 );
      ksSpcVisible( SPC_NAME, 6, 0 );   //щаг
    end
    else begin
      ksSpcVisible( SPC_NAME, 5, 1 );
      ksSpcVisible( SPC_NAME, 6, 1 );   //щаг
      ksSpcChangeValue( SPC_NAME , 6, Addr(p), FLOAT_ATTR_TYPE );
    end;

    // выключим поле допуска
    if ( not m_flagMode ) then
      ksSpcVisible( SPC_NAME, 7, 0 );

    // выключим класс прочности
    if ( not m_flagMode ) then
      ksSpcVisible( SPC_NAME, 8, 0 );

   // выключим материал
   if ( not m_flagMode ) then
     ksSpcVisible( SPC_NAME, 9, 0 );

   // выключим покрытие
   if ( not m_flagMode  ) then
     ksSpcVisible( SPC_NAME, 10, 0 );

   //изменим ГОСТ
   uBuf := gost;
   ksSpcChangeValue( SPC_NAME, 12, Addr(uBuf), UINT_ATTR_TYPE  );
  end;

  result := true;
end;

//------------------------------------------------------------------------------
// Создать гайку
//---
function GetGayka( command : Integer; ref : Reference; gost : Word ) : CPar;
begin
  result := CPar( Gayka.Create(  command, ref, gost ) );
end;

//------------------------------------------------------------------------------
// Запрос хот точек
//---
function Gayka.GetHotPoints( point : PHotPointDescription; index : Integer ) : LongBool;
begin
  result := false;
  with point^ do
  begin
    case ( index ) of
      0 : begin // точка привязки
            x    :=   0;
            y    :=   0;
            text := '0';
            result := true;
          end;

      1 : begin // угол поворота
            if DrawType = ID_TOP then
              x        := m_GaykaParam.s / 2.0
            else
              x        := m_GaykaParam.h;

            y          := 0;
            cursorInst := HInstance;
            cursorId   := CURSOR_ROTATE;
            text       := 'A';
            result := true;
          end;

      2 : begin // изменение диаметра
            x := 0;
            y := m_GaykaParam.dr / 2.0;
            cursorInst := HInstance;
            cursorId   := CURSOR_DIAMETER;
            text       := 'Dr';
            result := true;
          end;
    end;
  end;
end;

//------------------------------------------------------------------------------
// Установка хот точек
//---
function Gayka.SetHotPoint( point : PHotPointDescription;  index : Integer ) : LongBool;
var
  ang : Double;
  gr  : Reference;
begin

  gr := 0;

  with point^ do
  begin
    case ( index ) of
      0 : SetMacroPlacement( m_refMacr, x, y, 0.0, 1 );

      1 : begin
            ang := Angle( 0, 0, x, y );
            m_Angle := m_Angle + ang;
            SetMacroPlacement( m_refMacr, 0.0, 0.0, ang, 1 );
          end;

      2 : begin
            if ( ChangeHotPointParam( Abs(y + y) ) ) then begin
              DrawGroup( gr );
              SetParam;
              SetMacroPlacement( m_refMacr, 0.0, 0.0, 0.0, 1 );
              StoreTmpGroup( gr );
              ClearGroup( gr );
            end;
          end;
    end;
  end;
  result := True;
end;

//------------------------------------------------------------------------------
//  Текст курсора
//---
function Gayka.GetCursorText( index : Integer; Var text : PAnsiChar ) : LongBool;
begin
  result := false;
  case ( index ) of
    1 : begin
        cursorText := Format('A = %.2f',[m_Angle]);
        text := PAnsiChar(cursorText);
        result := true;
        end;
    2 : begin
        cursorText := Format('D = %.2f'+#10+'H = %.2f',[m_GaykaParam.dr, m_GaykaParam.h]);
        text := PAnsiChar(cursorText);
        result := true;
        end;
  end;
end;

//------------------------------------------------------------------------------
// Завершене редактирования
//---
function Gayka.EditComplete( index : Integer; success : LongBool ) : LongBool;
begin
  if (index = 2) And ( success ) then
  begin
    DrawSpcObj( 0 );
    if m_spcObject <> 0 Then
    begin
      if ksEditWindowSpcObject( m_spcObject ) <>0  then
        DrawPosLeader;
    end;
  end;
  result := True;
end;

//------------------------------------------------------------------------------
// Изменение параметров
//---
function Gayka.ChangeHotPointParam( d : Double ) : Boolean;
type
  StTmpL = record
    s  : array [0..19] of AnsiChar;
    dr : single;
  end;
var
  dR           : double;
  tmpdR, oldDR : double;
  code,  i     : integer;
  tmpL         : StTmpL ;
begin
  // подобрать ближайший dR по d
  dR     := 0.0;

  oldDR  := m_GaykaParam.dr;
  Result := false;
  if OpenBase then
  begin
    i := 1;
    while( i <> 0 ) do
    begin
      // Считать запись
      i := ReadRecord( m_base.bg, m_base.rg1, @tmpL );

      if ( i <> 0 )  then
      begin
        Val( tmpL.s, tmpdR, code );
        if ( tmpdR <= d ) then
          dR := tmpdR
        else
          i  := 0;
      end;
    end;

    if ( abs( dR - oldDR ) > 0.01 ) then
      result := ReadGaykaBase( dR, m_base, m_GaykaParam ) <> 0;
    CloseBase;  // Закрытие БД
  end;
end;

//------------------------------------------------------------------------------
// Открытие БД
//---
function OpenGaykaBase ( var base : SimpleBase ): integer;
begin
  base.bg := CreateDB('TXT_DB');  // TXT_DB

  if( _ConnectDB(base.bg, '5915.loa') = 0 ) then // "5915.loa"
  begin
    result := 0;
    exit;
  end
  else begin
    base.rg1 := Relation( base.bg );
      RChar( '', 20,0 );
      RFloat('dr');
    EndRelation();
    if ( DoStatement(base.bg, base.rg1, '1 1' ) = 0 ) then // "1 1"
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
      if ( DoStatement( base.bg, base.rg2, '' ) = 0 ) then // TXT_ALL
      begin
        result :=0;
        exit;
      end
      else
        result:=1;
    end;
  end;
end;

//------------------------------------------------------------------------------
// Открытие БД
//---
function Gayka.OpenBase : Boolean;
begin
  Result := OpenGaykaBase( m_base ) <> 0;
end;

//------------------------------------------------------------------------------
//  Читать параметры гайки по диаметру
//  возвращает 1 - успех 0 - не найдено записи , ошибка связи с БД
//---
function  ReadGaykaBase ( d : single; base : SimpleBase; var lpG : GAYKA5915 ): integer;
var
  s    : AnsiString;
  gTmp : GaykaTMP ;
     i :  integer;
begin

  result := 0;
{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 17 }
   with  System.SysUtils.FormatSettings do
 {$IFEND}
{$IFEND}
   begin
    DecimalSeparator := '.';
   end;
  s := Format( 'dr=%g', [d] ); // dr=%.0f

  if ( Condition(base.bg, base.rg2, PAnsiChar(s) ) = 0 ) then
    exit;

  i := ReadRecord( base.bg, base.rg2, Addr(gTmp) );

  if ( i <> 0 ) then
  begin

    lpG.dr := gTmp.dr;
    lpG.da := gTmp.da;
    lpG.h  := gTmp.h;
    lpG.d2 := gTmp.d2;

    if (lpG.flags And BF_PITCH) <> 0  then
      lpG.p := gTmp.p2
    else
      lpG.p := gTmp.p1;

   SetBitFlag( lpG.flags, BF_PITCH_ON, abs( gTmp.p2 - gTmp.p1 ) > 0.001 );

   SetBitFlag( lpG.flags, BF_KEY_S_ON, abs( gTmp.s1           ) > 0.001 );

   if ( lpG.flags and BF_KEY_S_ON ) =  0 then
     SetBitFlag( lpG.flags, BF_KEY_S, false );

   if ( lpG.flags and BF_KEY_S    ) <> 0  then
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

   result := 1;
  end;
end;

//------------------------------------------------------------------------------
// Перерисовать группу
// ---
procedure Gayka.RedrawPreview;
begin
  GetGroup();
end;

//------------------------------------------------------------------------------
// Наполнить панель контролами
// ---
procedure Gayka.ShowControls;
type
  StTmpL = record
    s    : array [0..19] of AnsiChar;
    dr   : single;
  end;

var
  diamList     : IPropertyList;
  flagRepeat   : Boolean;
  tmpRec       : StTmpL;
  sep          : IPropertySeparator;
  buttons,
  ispButtons,
  simpleButtons,
  paramButtons : IPropertyMultiButton;
begin
  //------------
  // Комбобокс диаметров резьбы
  diamList := CreateList( 0, 0 );
  if diamList <> nil then
  begin

    InitPropertyControl( IPropertyControl(diamList), IDP_DIAM, IDS_DIAM_HINT, IDS_DIAM_TIPS, ksNameAlwaysVisible, true, true );
    flagRepeat := true;
	  while flagRepeat do
    begin
		  flagRepeat := ReadRecord( m_base.bg, m_base.rg1, Addr(tmpRec) ) <> 0;
		  if flagRepeat then
      begin
			  diamList.Add( tmpRec.dr );
      end
    end;

	  diamList.Value := m_GaykaParam.dr;

  end;
  //------------
  // Отображение
  sep := CreateSeparator(ksSeparatorDownName);
  if sep <> nil then
    sep.Name := 'Отображение';

  buttons := CreateMultiButton(ksRadioButton);
  if buttons <> nil then
  begin
    InitPropertyControl( IPropertyControl(buttons), IDP_REFLECTION, IDS_REFLECTION_HINT, IDS_REFLECTION_TIPS, ksNameVerticalVisible, true, true );
    // Кнопка вид
    AddButton2( buttons, ID_VIEW, IDP_BMP_G_VIEW, DrawType = ID_VIEW, true );
    // Кнопка сбоку
    AddButton2( buttons, ID_LEFT, IDP_BMP_G_LEFT, DrawType = ID_LEFT, true );
    // Кнопка сверху
    AddButton2( buttons, ID_TOP,  IDP_BMP_G_TOP,  DrawType = ID_TOP,  true );
    // Кнопка Вид/разрез
    AddButton2( buttons, ID_SEC,  IDP_BMP_G_SEC,  DrawType = ID_SEC,  true );
  end;

  // Исполнение
  ispButtons := CreateMultiButton(ksRadioButton);
  if ispButtons <> nil then
  begin
    InitPropertyControl( IPropertyControl(ispButtons), IDP_ISP, IDS_ISP_HINT, IDS_ISP_TIPS, ksNameVerticalVisible, true, true );
    // Кнопка исполнение 1
    AddButton( ispButtons, IDP_BMP_G_I1,  Isp = 1, true );
    // Кнопка исполнение 2
    AddButton( ispButtons, IDP_BMP_G_I2,  Isp = 2, true );
  end;

  // Упрощенно
  simpleButtons := CreateMultiButton(ksCheckButton);
  if simpleButtons <> nil then
  begin
    InitPropertyControl( IPropertyControl(simpleButtons), IDP_SIMPLE, IDS_SIMPLE_HINT, IDS_SIMPLE_TIPS, ksNameVerticalVisible, true, true );
    AddButton2( simpleButtons, ID_SIMPLE, IDP_BMP_G_SIMPLE, Simple, true );
    AddButton( simpleButtons,  ID_AXIS,                     Axis  , true );
  end;

  sep := CreateSeparator( ksSeparatorDownName );

  //------------
  // Дополнительные параметры
  paramButtons := CreateMultiButton(ksCheckButton);
  if paramButtons <> nil then
  begin
    InitPropertyControl( IPropertyControl(paramButtons), IDP_FLAGS, IDS_FLAGS_TIPS, IDS_FLAGS_TIPS, ksNameVerticalVisible, true, true );
    // Шаг мелкий
    AddButton( paramButtons, IDP_BMP_G_STEP,  Pitch, PitchOn );
    // Размер под ключ
    AddButton( paramButtons, IDP_BMP_KEY,     KeyS,  PitchOn );
  end;

  //------------
  // Параметры штриховки
  inherited ShowControls;
end;

//------------------------------------------------------------------------------
// Значение контрола изменились нужно передать в гайку
// ---
procedure Gayka.OnChangeControlValue( {var cntrl : IPropertyControlDisp;} ctrlID : LongInt; const val : Variant );
var
  diam    : single;
  control : IPropertyMultiButton;
begin
  inherited OnChangeControlValue( ctrlID, val );
  if not Changed then
  begin

    case ctrlID of

     IDP_DIAM: // Диаметр
      begin
        diam := val;
      	if abs(diam - m_GaykaParam.dr) > 0.001 then
        begin
		      m_GaykaParam.dr := diam;
          if ReadGaykaBase ( m_GaykaParam.dr, m_base, m_GaykaParam ) <> 0 then
          begin
            control := GetPropertyControl(IDP_FLAGS) As IPropertyMultiButton;
            if control <> nil then
            begin
              control.ButtonEnable [ IDP_BMP_G_STEP] := PitchOn;
              control.ButtonEnable [ IDP_BMP_KEY   ] := KeySOn;
              control.ButtonChecked[ IDP_BMP_KEY   ] := KeyS;
            end;
          end;
          changed := true;
        end
      end;
    end;
  end
end;

//------------------------------------------------------------------------------
// Обработка нажатия кнопок
// ---
procedure Gayka.OnButtonClick( buttonID : LongInt );
begin
  case buttonID of
    IDP_BMP_G_I1:                      // Исполнение 1
      begin
        Isp     := 1;
        changed := true;               // Нужно перерисовать и перезаполнить грид
      end;
    IDP_BMP_G_I2:                      // Исполнение 2
      begin
        Isp     := 2;
        changed := true;               // Нужно перерисовать и перезаполнить грид
      end;

    IDP_BMP_G_STEP:                    // Шаг
      begin
        Pitch   := not Pitch;
        changed := true;               // Нужно перерисовать и перезаполнить грид
      end;

    IDP_BMP_KEY:                       // Размер поз ключ
      begin
        KeyS    := not KeyS;
        changed := true;               // Нужно перерисовать и перезаполнить грид
      end;
  end;

  inherited OnButtonClick( buttonID ); // Обработчик кнопки в базовом классе
end;

//------------------------------------------------------------------------------
// Вывод параметров гайки
// ---
procedure Gayka.ShowParam;
begin
  with m_GaykaParam do
  begin
    AddDoubleToGrig( IDS_PITCH,      p     ); // "Шаг резьбы"
    AddDoubleToGrig( IDS_DIM_KEY,    s     ); // "Размер под ключ"
    AddDoubleToGrig( IDS_HEAD_H,     h     ); // "Высота головки"
    AddDoubleToGrig( IDS_MASSA_1000, massa ); // "Масса 1000 шт"
  end;
end;

//------------------------------------------------------------------------------
// Количество параметров выводимых в гриде
// ---
function Gayka.GetParamCount : Integer;
begin
  Result := 3;
end;

//------------------------------------------------------------------------------
// Признак наличия штриховки у объекта
// ---
function Gayka.IsHatchObject : Boolean;
begin
  Result := true;
end;

end.
