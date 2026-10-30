library Step4;

{$R 'Step44.res' 'Step44.rc'}

uses
  step44 in 'step44.pas',
  Step4_1 in 'Step4_1.pas';

{$E rtw}
// Ёкспортные функции
exports
  CallBackC,
  CallBackP,
  LIBRARYENTRY,
  LIBRARYID;

begin
end.
