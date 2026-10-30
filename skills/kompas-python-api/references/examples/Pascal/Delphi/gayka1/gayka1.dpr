library gayka1;

{$R 'Gayka.res' 'Gayka.rc'}

uses
  GaykaRC in 'GaykaRC.pas',
  ManagerEvents in 'ManagerEvents.pas',
  base in 'base.pas',
  gayka2 in 'gayka2.pas',
  Entry in 'Entry.pas',
  UserControlEvent in 'UserControlEvent.pas';

{$E rtw}
// Ёкспортные функции
exports
  LIBRARYENTRY,
  LIBRARYID,
  LibObjInterfaceEntry,
  CallBackP,
  LeaderCallBack;

begin
  SysInit.DLLProc := @MyDLLProc;
end.
