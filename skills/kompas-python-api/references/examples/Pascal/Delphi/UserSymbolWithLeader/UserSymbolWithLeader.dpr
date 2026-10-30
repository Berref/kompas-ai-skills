library UserSymbolWithLeader;

{$R 'UserSymbolWithLeader1.res' 'UserSymbolWithLeader1.rc'}

uses
  ManagerEvents in 'ManagerEvents.pas',
  UserSymbol1 in 'UserSymbol1.pas',
  Entry in 'Entry.pas';

{$E rtw}

exports
  LIBRARYENTRY,
  LIBRARYID;

begin
  DLLProc := @MyDLLProc;
end.
