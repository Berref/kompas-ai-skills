unit Entry;

interface

  uses Windows, SysUtils, UserSymbol1, LDefin2D, ksApi7,
  ksConstTLB;

  procedure  LIBRARYENTRY( comm: WORD  ); pascal;
  function   LIBRARYID   : Cardinal;      pascal;
  function   LoadStr( ID : Integer ) : string;
  procedure  GetNewKompasAPI;
//type
  //PUserSymbol = ^UserSymbol;

var
 newKompasAPI : IApplication;


implementation

uses
  LtDefine,
  forms, ksAuto, Libtool;



//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
procedure GetNewKompasAPI;
var
  disp : IDispatch;
begin
	if newKompasAPI = nil then
  begin
    disp := IDispatch(CreateKompasApplication);
    newKompasAPI := disp As IApplication;
  end;
end;


//----------------------------------------------------------------------------------------
//
//---
function LIBRARYID: Cardinal;  pascal;
begin
  Result := 100;
end;


//----------------------------------------------------------------------------------------
//
//---
procedure LIBRARYENTRY( comm : Word );  pascal;
var
  obj : UserSymbol;
begin
  Application.Handle := GetHWindow;
  GetNewKompasAPI;
  ksSetDebugMessagesMode( 1 );
  case comm of
    1:
    begin
      if newKompasAPI <> nil then
      begin
        obj := UserSymbol.Create;
        obj.Draw;
      end;
    end;
  end;
end;


//----------------------------------------------------------------------------------------------
// Загрузить строку из ресурсов
//---
function LoadStr( ID : Integer ) : string;
var
  buf : array [0..255] of WideChar;
begin
  ksConvertLangStrExW( hInstance, ID, buf, 255 );
  Result := buf;
end;


end.
