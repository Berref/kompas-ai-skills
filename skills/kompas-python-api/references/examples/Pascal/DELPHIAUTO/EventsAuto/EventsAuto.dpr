////////////////////////////////////////////////////////////////////////////////
// Библиотека примеров: 'Самая простая библиотека'
////////////////////////////////////////////////////////////////////////////////
library EventsAuto;

{$E rtw}


{$R 'events.res' 'events.rc'}

uses
  events in 'events.pas',
  BaseEvents in 'BaseEvents.pas';

exports
  LibraryName  name 'LIBRARYNAME',
  LibraryId    name 'LIBRARYID',
  LibraryEntry name 'LIBRARYENTRY',
  LibInterfaceNotifyEntry name 'LibInterfaceNotifyEntry';


begin
  DLLProc := @MyDLLProc;
end.
