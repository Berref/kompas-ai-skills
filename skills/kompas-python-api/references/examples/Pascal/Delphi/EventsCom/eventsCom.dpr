////////////////////////////////////////////////////////////////////////////////
// Библиотека примеров: 'Самая простая библиотека'
////////////////////////////////////////////////////////////////////////////////
library eventsCom;

{$E rtw}


{$R 'events.res' 'events.rc'}

uses
  events in 'events.pas',
  ApplicationEvents in 'ApplicationEvents.pas',
  DocumentEvents in 'DocumentEvents.pas',
  cBaseEvents in 'cBaseEvents.pas';

exports
  LibraryName name 'LIBRARYNAME',
  LibraryId    name 'LIBRARYID',
  LibraryEntry name 'LIBRARYENTRY';

begin
  DLLProc := @MyDLLProc;
end.
