unit Entry;
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
 uses  Base, Windows, SysUtils, Gayka2, LibHpPar, LDefin2D, GaykaRC;


  procedure  LIBRARYENTRY( comm: WORD  ); stdcall;
  function   LIBRARYID   : Cardinal;      stdcall;
  procedure  LibObjInterfaceEntry( objType : integer; Comm : Cardinal; var _object : PILibHPObject ); stdcall;

type
  PHotPointObj = ^HotPointObj;
  HotPointObj  = class( TInterfacedObject, ILibHPObject )

protected
  obj : CPar;
public
  constructor Create( _obj : CPar );
  destructor Destroy; override;

    function  LibHotPnt_Prepare( index : Integer ) : LongBool; stdcall; // override;
    function  LibHotPnt_Complete( index : Integer; success : LongBool ): LongBool; stdcall; //override;
    function  LibHotPnt_Get( point : PHotPointDescription; index : Integer ) : LongBool; stdcall; //override;
    function  LibHotPnt_Set( point : PHotPointDescription; index : Integer ) : LongBool; stdcall;// override;
    function  LibHotPnt_GetCursorText( index : Integer; Var text : PAnsiChar ) : LongBool; stdcall; //override;
    function  LibHotPnt_GetMenu : Integer; stdcall; // override;
    function  LibHotPnt_ExecuteCommand( id : Integer ) : LongBool; stdcall; //override;
end;

function NewElement( command : Integer; ref : Reference ) : CPar;
//function GetGayka( command : Integer; ref : Reference; gost : Word ) : CPar;

implementation

 uses  LtDefine, LibTool, forms;

//----------------------------------------------------------------------------------------
//
//---
function NewElement( command : Integer; ref : Reference ) : CPar;
begin
  result := nil;
  case command of
    CM_GAYKA5915 : result := GetGayka( command, ref, 5915 ); // Gayka5915.Create;
  end;
end;

//----------------------------------------------------------------------------------------
//
//---
function LIBRARYID: Cardinal;  stdcall;
begin
  Result := ID_LIBID;
end;

//----------------------------------------------------------------------------------------
//
//---
procedure LIBRARYENTRY( comm : Word );  stdcall;
var
  el: CPar;
begin
  Application.Handle := GetHWindow;

  el := NewElement( comm, EditMacroMode );
  if el <> nil then
  begin
    el.Draw1();
//    el.Free;
  end;

  Application.Handle := 0;
end;

//----------------------------------------------------------------------------------------
//
//---
procedure  LibObjInterfaceEntry( objType : integer; Comm : Cardinal; var _object : PILibHPObject ); stdcall;
var
  I   : ILibHPObject;
  obj : CPar;
begin
  _object := Nil;
  if objType = idd_ILibHPObject Then
  Begin
    obj := NewElement( Comm, EditMacroMode );
    if obj <> nil then begin
      I := HotPointObj.Create( obj );
      _object := PILibHPObject(I);
      I._AddRef();
    end;
  end;
end;

//----------------------------------------------------------------------------------------
//
//---
constructor HotPointObj.Create( _obj : CPar );
begin
  inherited create;
  obj := _obj;
end;

//----------------------------------------------------------------------------------------
//
//---
destructor HotPointObj.Destroy;
begin
  inherited Destroy;
  obj.Free;
end;

//----------------------------------------------------------------------------------------
//
//---
function HotPointObj.LibHotPnt_Prepare( index : Integer ) : LongBool; stdcall;
begin
  Result := true;
end;

//----------------------------------------------------------------------------------------
//
//---
function HotPointObj.LibHotPnt_Complete( index : Integer; success : LongBool ): LongBool; stdcall;
begin
  obj.EditComplete( index, success );
  Result := true;
end;

//----------------------------------------------------------------------------------------
//
//---
function HotPointObj.LibHotPnt_Get( point : PHotPointDescription; index : Integer ) : LongBool; stdcall;
begin
  Result := obj.GetHotPoints( point, index );;
end;

//----------------------------------------------------------------------------------------
//
//---
function HotPointObj.LibHotPnt_Set( point  : PHotPointDescription; index : Integer ) : LongBool; stdcall;
begin
  Result := obj.SetHotPoint( point, index );
end;

//----------------------------------------------------------------------------------------
//
//---
function HotPointObj.LibHotPnt_GetCursorText( index : Integer; Var text : PAnsiChar ) : LongBool; stdcall;
begin
  Result := obj.GetCursorText( index, text );
end;

//----------------------------------------------------------------------------------------
//
//---
function HotPointObj.LibHotPnt_GetMenu : integer; stdcall;
begin
  Result := 0; // integer(obj.GetMenu);
end;

//----------------------------------------------------------------------------------------
//
//---
function HotPointObj.LibHotPnt_ExecuteCommand( id : Integer ) : LongBool; stdcall;
begin
  Result := true; // obj.ExecuteCommand( id );
end;

end.
