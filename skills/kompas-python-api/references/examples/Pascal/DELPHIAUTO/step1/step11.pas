unit step11;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface
  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYNAME : PAnsiChar;         Pascal;
  function   LIBRARYID   : Cardinal;      Pascal;

implementation
uses
  Windows,
  LDefin2D,
  ksAuto,
  ksApi7,
  ksTLB;

//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Самая простая библиотека на Delphi (Automation)';
end;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY(command: WORD); pascal;
var
  iKompasObject: KompasObject;
begin
  iKompasObject := KompasObject(CreateKompasObject);
  if iKompasObject <> nil then
    iKompasObject.ksMessage( 'Привет' );
  iKompasObject := nil;
end;

end.
