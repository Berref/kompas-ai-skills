////////////////////////////////////////////////////////////////////////////////
// Библиотека примеров: 'Самая простая библиотека'
////////////////////////////////////////////////////////////////////////////////
library Cube;

{$E rtw}


{$R 'Cube2.res' 'Cube2.rc'}

uses
  Cube1 in 'Cube1.pas',
  cBaseEvents in 'cBaseEvents.pas',
  DocumentFrameEvents in 'DocumentFrameEvents.pas';

exports
  LibraryId    name 'LIBRARYID',
  LibraryEntry name 'LIBRARYENTRY';
begin
  DLLProc := @MyDLLProc;
end.
