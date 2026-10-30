library gayka;

{$R 'Gayka1.res' 'Gayka1.rc'}

uses
  gayka1 in 'gayka1.pas',
  gayka2 in 'gayka2.pas',
  base in 'base.pas',
  DlgGaika in 'DlgGaika.pas' {fmDlgGaika},
  Okcancl1 in 'Okcancl1.pas' {OKBottomDlg};

{$E rtw}
// Ёкспортные функции
exports
  LIBRARYENTRY,
  LIBRARYID,
  LibObjInterfaceEntry;

begin
end.
