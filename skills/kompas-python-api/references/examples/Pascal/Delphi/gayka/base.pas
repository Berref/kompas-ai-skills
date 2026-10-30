unit Base;

interface
 uses  Windows,  Sysutils, LtDefine, LibTool, LibDB, LDefin2D, ksConstTLB, forms, controls, classes;

// var
// stroka : string;

const
 SPC_FORMAT    = 1;     //формат
 SPC_ZONA      = 2;     //зона
 SPC_POSITION  = 3;     //позиция
 SPC_MARKER    = 4;     //обозначение
 SPC_NAME      = 5;     //наименование
 SPC_COUNT     = 6;     //количество
 SPC_NOTE      = 7;     //примечание


 SPC_CLEAR_GEOM      = 0;     // очищать геометрию при редактировании объекта спецификации
 STANDART_SECTION    = 25;
 LIB_HELPFILE        =  'gayka.chm'; // имя файла помощи


MIN_H_ANG  =-90;
MAX_H_ANG  = 90;
MIN_H_SHAG =0.1;
MAX_H_SHAG =1000;
SPC_LIB    ='graphic.lyt';


SPCOBJ_CREATE = true;                 //признак подключения объекта к спецификации
MAX_COUNT_SPCOBJ =4;     //максимальное число объектов СП за раз 4

ID_ANGLE        =1;   // угол
ID_CALC_PAKET   =19;  // измерить пакет для болта гайки шайбы
ID_VID          = 2;   //(Вид) macroPar.drawType = 0;
ID_SIDEVID      = 4;   //(Вид_сбоку)  macroPar.drawType = 6;
ID_SEC          = 8;   //разрез
ID_SEC_R        =15;   //разрез
ID_SHPONSLOT    =16;  //шпоночный паз
ID_HATCH_ANG    = 6;   //угол штриховки
ID_HATCH_SHAG   = 7;   //шаг штриховки
ID_SIMPLE       = 9;   //упрощенное изображение
ID_DIMENSION    =13;   //с размерами или без
ID_TOPVID       = 3;   //(Вид_сверху)  macroPar.drawType = 8;
ID_VIDDIMENSION = 4;   //(Вид_c размерами)
ID_VIDSEC       = 5;   //Пол-вида/пол-разреза  macroPar.drawType = 2;
ID_PARAM        =10;   //параметры макроэлемента
ID_ATTR         =11;   //атрибуты макроэлемента
ID_BOTTOMVID    =12;   //(Вид_снизу)  macroPar.drawType = 16;
ID_VID_R        =14;   //Вид
ID_CONE         =2 ;   //конус
ID_OGIVALO      =3 ;   //оживало
ID_CARVING      =4 ;   //резьба
ID_ROUNDING     =5 ;   //скругление
ID_CHAMFER      =14;   //фаска
ID_SPHERE       =8 ;   //сфера
ID_CYLINDER     =15;   //цилиндр
ID_SERVICE    =17 ; //
ID_SERVICE1   =18 ; //

FIRST_DLG        =300;
GAYKA_DIALOG	 =   FIRST_DLG+1;

FIRST_MN        =2000;
MENU_POS_LEADER =FIRST_MN+282;
MENU_G5915_1    =FIRST_MN+19 ;
MENU_G5915_2    =FIRST_MN+20;
MENU_G5915_3    =FIRST_MN+21;
MENU_G5915_4    =FIRST_MN+22;
MENU_G5915_5    =FIRST_MN+31;
MENU_G5915_6    =FIRST_MN+32;
MENU_G5915_7    =FIRST_MN+33;
MENU_G5915_8    =FIRST_MN+34;

FIRST_STR       = 500;

STR11  = FIRST_STR+11;
STR144 = FIRST_STR+144;
STR226 = FIRST_STR+226;
STR228 = FIRST_STR+228;  // "Ошибка! Объект не позиционная линия выноски!"

FIRST_ID       = 200;

IDD_DIAM       = FIRST_ID+2;
IDD_SHOW       = FIRST_ID+3;
IDD_ATTR       = FIRST_ID+4;
IDD_SIMPL      = FIRST_ID+5;
IDD_PITCH      = FIRST_ID+45;
IDD_ISPOLN1    = FIRST_ID+8;
IDC_GROUP1     = FIRST_ID+16;
IDD_ISPOLN2    = FIRST_ID+11;
IDD_VID	       = FIRST_ID+10;
IDD_VIDSEC     = FIRST_ID+20;
IDD_SIDEVID    = FIRST_ID+12;
IDD_TOPVID     = FIRST_ID+35;
IDD_H_ANG      = FIRST_ID+14;
IDD_H_SHAG     = FIRST_ID+15;
IDC_GROUP      = FIRST_ID+17 ;
IDC_CHECK_KEY_S= FIRST_ID+85 ;
IDD_AXIS       = FIRST_ID+44 ;
IDC_GRP        =  FIRST_ID+7 ;

FIRST_BMP      =  4000;

G5915_1  =FIRST_BMP +11;
G5915_2  =FIRST_BMP +12;
G5915_3  =FIRST_BMP +13;
G5915_4  =FIRST_BMP +14;
G5915_5  =FIRST_BMP +15;
G5915_6  =FIRST_BMP +16;
G5915_7  =FIRST_BMP +17;
G5915_8  =FIRST_BMP +18;
G5915_9  =FIRST_BMP +19;
G5915_10 =FIRST_BMP +20;
G5915_11 =FIRST_BMP +21;

CURSOR_ROTATE   = 5001;
CURSOR_DIAMETER = 5002;
GAIKA_POPUPMENU = 5003;

STR1            = 5101;
STR2            = 5102;
STR3            = 5103;
STR4            = 5104;
STR5            = 5105;
STR6            = 5106;
STR7            = 5107;
STR8            = 5108;
STR9            = 5109;
STR10           = 6000;
STR12           = 6001;

// коэффициент для расчета диаметра резьбы по шагу резьбы
MODSTEP_REAL : Double = 0.5412765877;

type
BaseMakroParam  = record
  ang        : single;
  flagAttr   : word;
  drawType   : smallInt;
  typeSwitch : byte;  // тип запроса положения базовой точки элемента 0 Placement 1 Curso
                    //   0 - точка + направление оси 0X ( Placement );
                    //   1 - точка, направление совпадает с осью 0X текущей СК ( Cursor ).

end;
{
// класс, позволяющий доступиться к caption и text у сontrol
TOpenControl = class(TControl)
published
  property Caption;
  property Text;
end;
}

// базовый класс параметров
PCPar = ^CPar;
CPar  = class
protected
  refMacr : reference;
  countObj : integer;
  flagMode : boolean;
public

  par : BaseMakroParam ;


   constructor Create;
   procedure  Assign ( other : CPar );virtual; // оператор присваивания

   procedure  Draw1;
   function   GetObjCount: cardinal ;
   procedure  GetGroup( var gr : reference ); virtual; abstract;
   function   ChoiceMenuId: integer; virtual; abstract;
   procedure  SetParam; virtual; abstract;
   function   Size: integer; virtual;
   function   CParSize: integer;
   procedure  SetHatchShag; virtual;
   procedure  SetHatchAngl; virtual;
   procedure  SetDimension; virtual;
   procedure  SetSimple; virtual;

   function   MacroElementParam : integer; virtual;
   procedure  FuncAfteDrawType; virtual;
   function   GetDrawType: smallInt;
   procedure  SetDrawType( tip : smallInt );
   function   GetFlagAttr: word;
   procedure  SetAttr;

  function    EditSpcObj( var spcObj : reference; geom : reference ) : reference; virtual;
  function    IsSpcObjCreate: boolean;virtual; //функция проверки подключения атрибутов или нет
  function    GetAddr: pointer;
  procedure   SetPlacement( x, y, angl : Double );

end;

//---------------------------------------------------------------------------------
function  CallBackP ( com : integer;  var x, y : double; var angl : double;
                      info : PRequestInfo; phantom : pointer; _dynamic : integer ) : integer;  stdcall ;

function  CallBackC ( com : integer; var x,y : double;
                      info : PRequestInfo; phantom : pointer; _dynamic : integer ) : integer;  stdcall ;
function  DrawSpcObj( group : reference ) : boolean;
procedure _MessageBoxResult;
procedure DrawPosLeader( _spcObj: reference );
function  _SetHatchAngl( ang : single ): single ;
function  _SetHatchShag( shag : single) : single;
procedure CheckDecimelPart(s : PAnsiChar; pointToComma : Byte);
function  GetFullName(  name : PAnsiChar; fName:PAnsiChar  ): integer;
function  _ConnectDB(bd : reference; name : PAnsiChar ): integer;
function  _GetMacroParam( value : pointer;  size : cardinal ): integer;
// function LoadStr_( id : integer; str : string ) : string;
// procedure ConvertLangForm( form : TForm );
function LoadStr_( id: Integer ): AnsiString; // Функция перевода строки ресурса
procedure ConvertComponentLang( component: TComponent ); // Функция перевода компонента

var
  obj        : PCPar;
  spcObj     : array [0..MAX_COUNT_SPCOBJ-1] of reference;
  flagSwitch : boolean;  // false переключения нет true переключение с
                         // Placement на Cursor

implementation

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
constructor CPar.Create;
begin
  par.flagAttr      := 0 ;

  par.typeSwitch  := 0;
  par.ang         := 0;
  par.drawType    := 0;

  refMacr := 0;
  countObj := 1;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
function    CPar.GetAddr: pointer;
begin
  result := Addr(par.ang);
end;

// оператор присваивания
//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
procedure CPar.Assign( other : CPar );
begin
  refMacr     := other.refMacr;
  flagMode    := other.flagMode;
  par         := other.par;
end;

//------------------------------------------------------------------------------
//
// ---
procedure CPar.SetPlacement( x, y, angl : Double );
begin
  if refMacr <> 0 then
    SetMacroPlacement( refMacr, x, y, angl, 0 );
end;

//------------------------------------------------------------------------------
//
//---
function CPar.GetObjCount;
begin
  result := countObj;
end;

//------------------------------------------------------------------------------
//
//---
function   CPar.CParSize: integer;
begin
  result := SizeOf(par);
end;

//------------------------------------------------------------------------------
//
//---
function CPar.Size: integer;
begin
  result := CParSize;
end;
//------------------------------------------------------------------------------
//
//---
procedure CPar.SetHatchAngl;
begin
end;

//------------------------------------------------------------------------------
//
//---
procedure CPar.SetHatchShag;
begin
end;
//------------------------------------------------------------------------------
//
//---
procedure CPar.SetSimple;
begin
end;
//------------------------------------------------------------------------------
//
//---
procedure CPar.SetDimension;
begin
end;

//------------------------------------------------------------------------------
//
//---
function  CPar.MacroElementParam : integer;
begin
  MacroElementParam := 0;
end;

//------------------------------------------------------------------------------
//
//---
procedure CPar.FuncAfteDrawType;
begin
end;

//------------------------------------------------------------------------------
//
//---
function  CPar.GetDrawType: smallInt;
begin
  GetDrawType := par.drawType;
end;

//------------------------------------------------------------------------------
//
//---
procedure  CPar.SetDrawType( tip : smallInt );
begin
  par.drawType := tip;
end;

//------------------------------------------------------------------------------
//
//---
function   CPar.GetFlagAttr : word;
begin
  GetFlagAttr := par.flagAttr;
end;

//------------------------------------------------------------------------------
//
//---
procedure  CPar.SetAttr;
begin
  if ( par.flagAttr<>0 ) then par.flagAttr := 0  else  par.flagAttr := 1;
end;

//------------------------------------------------------------------------------
//
//---
function CPar.EditSpcObj( var spcObj : reference; geom : reference ) : reference;
begin
  EditSpcObj := 0;
end;

//------------------------------------------------------------------------------
//
//---
function CPar.IsSpcObjCreate: boolean;
begin
  IsSpcObjCreate := false;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
procedure CPar.Draw1;
var
  rub  : Phantom  ;
  j    : integer;
  x, y : double ;
  menuId,i, count : integer;
  info   : RequestInfo;
begin
  FillChar( rub, sizeof(rub), 0 );
  j:=1;
  rub.type1.scale := 1;
  rub.phType      := 1;
  if ( ReturnResult=0 ) then
  begin
    flagMode := EditMacroMode=1;
    obj := Addr(self);
    if ( obj^.MacroElementParam()= 0 ) then
      exit;
    while ( j<>0 ) do
    begin
      flagSwitch := false;
      GetGroup ( rub.type1.gr );
      rub.type1.ang  := par.ang;

      menuId := ChoiceMenuId ( );

      FillChar(info, sizeof(info), 0 );
      info.commands := PAnsiChar(menuId);
      info._dynamic := 1;
      if ( par.typeSwitch<>0 ) then
      begin
        info.callBack := Addr(CallBackC);
        j:=ksCursor( Addr(info), x, y, Addr(rub) );
      end
      else begin
        info.callBack := Addr(CallBackP);
        j:=Placement( Addr(info), x, y, rub.type1.ang, Addr(rub) );
      end;

      if ( spcObj[0]<>0 ) then
      begin
        count := GetObjCount;
        for i := 0 to count-1 do
        begin
          if (ksEditWindowSpcObject( spcObj[i] ) <>0) then
            DrawPosLeader(spcObj[i]);
        end;
        FillChar( spcObj, sizeof(reference)*MAX_COUNT_SPCOBJ, 0 );
        if ( not flagMode ) then
        begin
          flagSwitch := true;
          if  par.typeSwitch<>0 then  par.typeSwitch := 0 else par.typeSwitch := 1;
        end;
      end;

      if ( flagSwitch <> false ) then
      begin
        j := 1;
        if par.typeSwitch<>0 then par.typeSwitch := 0 else par.typeSwitch := 1;
      end;
    end;
  end;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
function  CallBackP ( com : integer;  var x, y : double; var angl : double;
                      info : PRequestInfo; phantom : pointer; _dynamic : integer ) : integer;  stdcall ;
var
  rub : PPhantom;
begin

  rub := PPhantom (phantom);
  if( _dynamic = 0 ) then //фиксация
  begin
    case ( com ) of
      ID_ANGLE  :  begin
        flagSwitch := true;
        result:= 0;
        exit;
        end;
      ID_HATCH_ANG : begin
        obj^.SetHatchAngl();
        end;
      ID_HATCH_SHAG : begin
        obj^.SetHatchShag();
        end;
      ID_SIMPLE : begin
        obj^.SetSimple();
        end;
      ID_DIMENSION : begin
        obj^.SetDimension();
        end;
      ID_ATTR : begin
        obj^.SetAttr();
        end;
      ID_PARAM : begin
        obj^.MacroElementParam();
        end;
      -1:begin //поставить в модель
        obj^.par.ang := angl;
        obj^.SetParam();
// HOT_POINTS ##################################################################
        obj^.SetPlacement( x, y, angl );
        StoreTmpGroup( rub^.type1.gr );
// HOT_POINTS ##################################################################
        if ( DrawSpcObj( rub^.type1.gr ) ) then
        begin
          ClearGroup( rub^.type1.gr );
          result := 0;
          exit;
        end;
        ClearGroup( rub^.type1.gr );
        if( obj^.flagMode ) then
        begin
          result:= 0;
          exit;
        end;
        end;
    end;
    info^.commands := PAnsiChar(obj^.ChoiceMenuId());
    obj^.GetGroup ( rub^.type1.gr );
  end
  else begin
    obj^.par.ang := angl;
  end;
  result:= 1;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
function CallBackC ( com : integer; var x,y : double;
                      info : PRequestInfo; phantom : pointer; _dynamic : integer ) : integer;  stdcall ;
var
  rub : PPhantom;
begin
  rub := PPhantom (phantom);
  if( _dynamic = 0 ) then //фиксация
  begin
    case ( com ) of
      ID_ANGLE  :  begin
        flagSwitch := true;
        result:= 0;
        exit;
        end;
      ID_HATCH_ANG : begin
        obj^.SetHatchAngl();
        end;
      ID_HATCH_SHAG : begin
        obj^.SetHatchShag();
        end;
      ID_SIMPLE : begin
        obj^.SetSimple();
        end;
      ID_DIMENSION : begin
        obj^.SetDimension();
        end;
      ID_ATTR : begin
        obj^.SetAttr();
        end;
      ID_PARAM : begin
        obj^.MacroElementParam();
        end;
      -1:begin //поставить в модель
        obj^.SetParam();
        MoveObj( rub^.type1.gr, x, y );
        if( abs(obj^.par.ang) > 0.001 ) then
           RotateObj( rub^.type1.gr, x, y, obj^.par.ang );
        StoreTmpGroup( rub^.type1.gr );
        ClearGroup( rub^.type1.gr );

        if ( DrawSpcObj( rub^.type1.gr )) Or (obj^.flagMode ) then
        begin
          result := 0;
          exit;
        end;
        end;
    end;
    info^.commands := PAnsiChar(obj^.ChoiceMenuId());
    obj^.GetGroup ( rub^.type1.gr );
  end;

  result:=1;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
procedure _MessageBoxResult;
begin
  if ( ReturnResult<>0 ) then
  begin
    if ( ReturnResult = etError10 ) then   //  10  "Ошибка! Вырожденный объект"
      ResultNULL()
    else
      MessageBoxResult();
  end;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
function DrawSpcObj( group : reference  ): boolean;
var
  i, count : integer;
begin

  FillChar( spcObj,  sizeof(reference)*MAX_COUNT_SPCOBJ, 0 );
  if( obj^.IsSpcObjCreate ) then
  begin
    if ( ReturnResult() = etError10 ) then   //  10  "Ошибка! Вырожденный объект"
      ResultNULL();

    spcObj[0] := obj^.EditSpcObj( spcObj[0], group );
    if( obj^.par.flagAttr=0) And (spcObj[0]<>0 ) then
    begin
      count := obj^.GetObjCount();
      for i := 0 to count-1 do
      begin
        if( spcObj[i]<>0 ) then
        begin
          if ( ksSpcObjectEdit( spcObj[i] )>0 )then
          begin
            ksSpcIncludeReference( 0, 0 ); //очистим геометрию, чтобы не удалялась в месте с объектом
            ksSpcObjectEnd();
          end;
          DeleteObj ( spcObj[i] );
          spcObj[i] := 0;
        end;
      end;
    end;
  end;
  result := spcObj[0]<>0 ;
end;

//----------------------------------------------------------------------------------------------
// отрисовать позиционную линию выноски
// уже проверено , что объект спецификации есть
// Функцию нужно запускать вне Cursor и Placement
//----------------------------------------------------------------------------------------------
Procedure DrawPosLeader( _spcObj: reference );
var
  info : RequestInfo;
  flag : boolean;
  posLeater : reference;
  x1, y1 : double ;
  j1 : integer;
begin
  flag      := false;
  posLeater := 0;


  repeat
    FillChar(info, sizeof(info), 0 );
    info.commands := PAnsiChar(MENU_POS_LEADER);

    info.prompt := PAnsiChar(LoadStr_(STR1));//Укажите позиционную линию выноски
    j1 := ksCursor( Addr(info), x1, y1, nil );
    case ( j1 ) of
      1:begin //Создать новую линию выноски
        posLeater := ksCreateViewObject( POSLEADER_OBJ );
        flag := false;
        end;
      2: begin//Подключить существующую
        FillChar(info, sizeof(info), 0 );
        info.commands := PAnsiChar(LoadStr_(STR2));//Укажите линию выноски
        if( ksCursor( Addr(info), x1, y1, nil )<>0 ) then
        begin
          posLeater := FindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
          if (posLeater<>0) And (GetObjParam( posLeater, nil, 0, 0) <> POSLEADER_OBJ  ) then
          begin
             Error( PAnsiChar(LoadStr_(STR3)));//Объект не позиционная линия выноски!
             posLeater := 0;
             flag := true;
          end
          else
            flag := false;
        end
        else
          flag := false;
      end;
      -1: begin
        posLeater := FindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
        if (posLeater<>0) And (GetObjParam( posLeater, nil, 0, 0) <> POSLEADER_OBJ  ) then
        begin
           Error( PAnsiChar(LoadStr_(STR3))); //Объект не позиционная линия выноски!
           posLeater := 0;
           flag := true;
        end
        else
          flag := false;
      end;
    end;
  until( flag = false );

  //линия выноски есть, подключим ее к объекту спецификации
  if ( posLeater <>0 ) then
  begin
    //ввойдем в режим редактирования объекта спецификации
    if ( ksSpcObjectEdit( _spcObj )<>0 ) then
    begin
      //подключим линию выноски
      ksSpcIncludeReference( posLeater, 1 );
      //закроем объект спецификации
      ksSpcObjectEnd();
    end;
  end;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
function _SetHatchAngl( ang : single ): single ;
var
  a : double;
  rez : integer;
begin
  EnableTaskAccess( 0 );
  rez :=  ReadDouble( PAnsiChar(LoadStr_(STR4)), ang, -90, 90, a );
  EnableTaskAccess( 1 );
  if ( rez<>0 ) then
    ang := a;
  result :=ang;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
function _SetHatchShag( shag : single) : single;
var
  a : double;
  rez : integer;
begin
  EnableTaskAccess( 0 );
  rez := ReadDouble( PAnsiChar(LoadStr_(STR5)), shag, 0.1, 1000, a );
  EnableTaskAccess( 1 );
  if ( rez<>0 ) then
    shag := a;
  result:= shag;
end;

//--------------------------------------------------------------------------
// отбросить дробную часть у строки если после "." нули
// "123.000" -> "123";   "123.10" -> "123.1"
// pointToComma =1 заменить '.' на ','
//--------------------------------------------------------------------------
procedure CheckDecimelPart(s : PAnsiChar; pointToComma : Byte);
var
  pos  : integer;
  flag : boolean;
  i    : integer;
function strchr ( s: PAnsiChar; c : AnsiChar ) : integer;
var
  i   : integer;
begin
  for i:=0 to strlen( s )-1 do
  begin
    if ( s[i] = c ) then
    begin
      result := i;
      exit;
    end;
  end;
  result := -1;
end;
begin
  if( s<>nil) And (strlen(s)<>0 ) then
  begin
    pos := strchr( s, '.');
    flag := false;
    if ( pos<>-1 ) then
    begin
      i:=pos;
      inc(i);
      while( s[i] <> '0') And (flag=false ) do
      begin
        if ( s[i] <> '0' ) then
          flag := true;
        inc(i);
      end;
      if( flag=false )then
        s[pos] := AnsiChar(0)
      else 
      begin
        i :=  strlen(s)-1;
        while( s[i]='0' ) do
        begin
          s[i] := AnsiChar(0);
          dec(i);
        end;
        if ( pointToComma<>0 ) then
          s[pos] := ',';
      end;
    end;
  end;
end;

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
function GetFullName( name : PAnsiChar;  fName : PAnsiChar ): integer;
type
OFSTRUCT = record
   cBytes : byte;
   fFixedDisk:byte;
   nErrCode: word;
   Reserved1:word;
   Reserved2:word;
   szPathName: array [0..255] of AnsiChar;
end;

var
  //pos : integer;
  ofs : TOFSTRUCT;
  c   : PAnsiChar;
begin
  if( GetModuleFileNameA( HInstance, fName, 255)<>0 ) then
  begin
    c := strrscan( fName, '\');
    if ( c<>nil ) then
    begin
      StrCopy( c+1, '');
      strcat ( fName, name );
      if ( OpenFile(fName , ofs, OF_EXIST) <> HFILE_ERROR )then
      begin
        result:= 1;
        exit;
      end
      else begin
        StrCopy( c+1, '');
        strcat ( fName, 'LOAD\' );
        strcat ( fName, name );
        if ( OpenFile(fName , ofs, OF_EXIST) <> HFILE_ERROR )then
        begin
          result:= 1;
          exit;
        end;
      end;
    end;
  end;
  result := 0;
end;

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
function   _ConnectDB(bd : reference; name: PAnsiChar ): integer;
var
  buf : array[0..255] of AnsiChar;
begin
  if ( GetFullName( name, buf  )=1 ) then
    result := ConnectDB( bd, buf )
  else
    result := ConnectDB( bd, name );
end;

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
function   _GetMacroParam( value : pointer;  size : cardinal ): integer;
begin
  result := GetMacroParam( 0, value, size);
end;

{
//-------------------------------------------------------------------------------------
// функция перевода строки
//-------------------------------------------------------------------------------------
function LoadStr_( id : integer; str : string ) : string;
Var
  buf     : array[0..MAX_TEXT_LENGTH] of Char; //имя фонта
begin
  str := LoadStr( id );
//  ksMessage( PAnsiChar(str) );
  if ( ksConvertLangStr( PAnsiChar(str), buf, MAX_TEXT_LENGTH ) <> 0  ) Then
    str := buf;
//  ksMessage( PAnsiChar(str) );
  result := str;
end;

//-------------------------------------------------------------------------------------
// функция перевода формы
//-------------------------------------------------------------------------------------
procedure ConvertLangForm( form : TForm );

var
  I: Integer;

  procedure ConvertLangControl( opControl : TOpenControl );
    var
    buf     : array[0..MAX_TEXT_LENGTH] of Char; //имя фонта
  begin
    if ( ksConvertLangStr( PAnsiChar(opControl.caption), buf, MAX_TEXT_LENGTH ) <> 0  ) Then
      opControl.caption := buf;
    if ( ksConvertLangStr( PAnsiChar(opControl.hint), buf, MAX_TEXT_LENGTH ) <> 0  ) Then
      opControl.hint := buf;
    if ( ksConvertLangStr( PAnsiChar(opControl.text), buf, MAX_TEXT_LENGTH ) <> 0  ) Then
      opControl.text := buf;
  end;

begin
  for I:= 0 to form.ControlCount -1 do
  begin
    if ( form.Components[I] is TControl ) then
      ConvertLangControl( TOpenControl(form.Components[I] as TControl) );
  end;
  //переводим радиогруппы и др оконные контролы
  ksConvertLangWindow( form.Handle );
end;
}

//------------------------------------------------------------------------------
// Функция перевода строки ресурса
//-
function LoadStr_( id: Integer ): AnsiString;
var
  buf: array[0..MAX_TEXT_LENGTH] of AnsiChar;

begin
  ksConvertLangStrEx( hInstance, id, buf, SizeOf(buf) );
  result := buf;
end;

//------------------------------------------------------------------------------
// Функция перевода компонента
//-
procedure ConvertComponentLang( component: TComponent );
var
  control: TControl;
  buf: array[0..MAX_TEXT_LENGTH] of WideChar;
  i: Integer;

begin
{  if component <> nil then
  begin
    if component is TControl then
    begin
      control := component as TControl;

      if ksConvertLangStrW( PWideChar(control.Hint), buf, SizeOf(buf)) <> 0 then
        control.Hint := buf;

      control.GetTextBuf( buf, SizeOf(buf) );

      if ksConvertLangStrW(buf, buf, SizeOf(buf)) <> 0 then
        control.SetTextBuf( buf );
    end;

    if component.ComponentCount > 0 then
      for i := 0 to component.ComponentCount - 1 do
        ConvertComponentLang( component.Components[i] );
  end;
}
end;

end.


