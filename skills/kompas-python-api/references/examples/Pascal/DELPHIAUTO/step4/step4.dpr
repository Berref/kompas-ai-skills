library step4;

{$R 'Step41.res' 'Step41.rc'}

uses
  step4_1 in 'step4_1.pas',
  step4_3 in 'step4_3.pas' {TestSlideDlg};

{$E rtw}


exports
  LibraryId name 'LIBRARYID',
  LibraryEntry name 'LIBRARYENTRY',
  CallBackProcCursor name 'CALLBACKPROCCURSOR',
  CallBackProcPlacement name 'CALLBACKPROCPLACEMENT';

begin
end.
