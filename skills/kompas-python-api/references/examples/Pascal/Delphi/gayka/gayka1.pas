unit Gayka1;
//******************************************************************/
//*                (c)Акционерное общество АСКОН                   */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                    Библиотека примеров                         */
//*              Проектирование конструкторского элемента          */
//*                                                                */
//******************************************************************/

interface
 uses  Base, Windows, SysUtils, Gayka2, LibHpPar, LDefin2D;

const
  LIB_ID = 100;

  procedure  LIBRARYENTRY( comm: WORD  ); pascal;
  function   LIBRARYID   : Cardinal;      pascal;
  procedure  LibObjInterfaceEntry( objType : integer; Comm : Cardinal; var _object : PILibHPObject ); stdcall;

type
  PGayka5915HP = ^Gayka5915HP;
  Gayka5915HP  = class( TInterfacedObject, ILibHPObject )

protected
  obj : Gayka;
public
  constructor Create;
  destructor Destroy; override;

    function  LibHotPnt_Prepare( index : Integer ) : LongBool; stdcall;// override;
    function  LibHotPnt_Complete( index : Integer; success : LongBool ): LongBool; stdcall; //override;
    function  LibHotPnt_Get( point : PHotPointDescription; index : Integer ) : LongBool; stdcall; //override;
    function  LibHotPnt_Set( point : PHotPointDescription; index : Integer ) : LongBool; stdcall;// override;
    function  LibHotPnt_GetCursorText( index : Integer; Var text : PAnsiChar ) : LongBool; stdcall; //override;
    function  LibHotPnt_GetMenu : Integer; stdcall;// override;
    function  LibHotPnt_ExecuteCommand( id : Integer ) : LongBool; stdcall; //override;
end;

  function   NewHPGayka : Gayka5915HP;

implementation

 uses  LtDefine, LibTool, forms;

var
  obj : Gayka5915HP;

//----------------------------------------------------------------------------------------
//
//---
function NewHPGayka : Gayka5915HP;
begin
  result :=Gayka5915HP.Create;
end;

//----------------------------------------------------------------------------------------
//
//---
function LIBRARYID: Cardinal;  pascal;
begin
  Result := LIB_ID;
end;

//----------------------------------------------------------------------------------------
//
//---
procedure LIBRARYENTRY( comm : Word );  pascal;
var
  el: CPar;
begin
  Application.Handle := GetHWindow;
  case comm of
    1:   el := GetGayka( 5915 );
    else el := GetGayka( 5915 );
  end;
  if el <> nil then
    el.Draw1();
  Application.Handle := 0;
  el.Free;
end;

//----------------------------------------------------------------------------------------
//
//---
procedure  LibObjInterfaceEntry( objType : integer; Comm : Cardinal; var _object : PILibHPObject ); stdcall;
var
  I   : ILibHPObject;
begin
    _object := Nil;
    if objType = idd_ILibHPObject Then
    Begin
      case Comm of
        1 : begin
         obj := NewHPGayka;
         I := obj;
        _object := PILibHPObject(I);
        obj._AddRef();
        end;
      end;
    End;
end;

//----------------------------------------------------------------------------------------
//
//---
constructor Gayka5915HP.Create;
begin
  inherited create;
  obj := GetGayka( 5915 );
end;

//----------------------------------------------------------------------------------------
//
//---
destructor Gayka5915HP.Destroy;
begin
  inherited Destroy;
  obj.Free;
end;

//----------------------------------------------------------------------------------------
//
//---
function Gayka5915HP.LibHotPnt_Prepare( index : Integer ) : LongBool; stdcall;
begin
  Result := true;
end;

//----------------------------------------------------------------------------------------
//
//---
function Gayka5915HP.LibHotPnt_Complete( index : Integer; success : LongBool ): LongBool; stdcall;
begin
     obj.EditComplete( index, success );
     Result := true;
end;

//----------------------------------------------------------------------------------------
//
//---
function  Gayka5915HP.LibHotPnt_Get( point : PHotPointDescription; index : Integer ) : LongBool; stdcall;
begin
     Result := obj.GetHotPoints( point, index );;
end;

//----------------------------------------------------------------------------------------
//
//---
function  Gayka5915HP.LibHotPnt_Set( point  : PHotPointDescription; index : Integer ) : LongBool; stdcall;
begin
     Result := obj.SetHotPoint( point, index );
end;

//----------------------------------------------------------------------------------------
//
//---
function  Gayka5915HP.LibHotPnt_GetCursorText( index : Integer; Var text : PAnsiChar ) : LongBool; stdcall;
begin
     Result := obj.GetCursorText( index, text );
end;

//----------------------------------------------------------------------------------------
//
//---
function  Gayka5915HP.LibHotPnt_GetMenu : integer; stdcall;
begin
     Result := integer(obj.GetMenu);
end;

//----------------------------------------------------------------------------------------
//
//---
function  Gayka5915HP.LibHotPnt_ExecuteCommand( id : Integer ) : LongBool; stdcall;
begin
     Result := obj.ExecuteCommand( id );
end;

end.
