////////////////////////////////////////////////////////////////////////////////
// Библиотека примеров: 'Самая простая библиотека'
////////////////////////////////////////////////////////////////////////////////
library step12;

{$E rtw}


{$R 'step.res' 'step.rc'}

uses
  step12_1 in 'step12_1.pas',
  cBaseEvents in 'cBaseEvents.pas',
  ApplicationEvents in 'ApplicationEvents.pas',
  DocumentEvents in 'DocumentEvents.pas',
  PropMen in 'PropMen.pas';

exports
//  LibraryName name 'LIBRARYNAME',
  LibraryId    name 'LIBRARYID',
  LibraryEntry name 'LIBRARYENTRY',
  LibIsOnApplication7 name 'LibIsOnApplication7',
  LibInterfaceNotifyEntry name 'LibInterfaceNotifyEntry',
  LibToolBarId            name 'LibToolBarId';
begin
  DLLProc := @MyDLLProc;
end.
