# ksSheetSetupDlg - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
DocumentParam par;

par.type = lt_DocSheetStandart;

par.sheet.stPar.format = 4;

par.sheet.stPar.multiply = 1;

par.sheet.stPar.direct = 0;

if ( ::ksSheetSetupDlg(&par, ::GetHWindow()) ) {

char buf[256];

if ( par.type == lt_DocSheetStandart ) {

::sprintf( buf, "Стандартный лист : формат A%d, кратность %d, расположение %s", par.sheet.stPar.format,

par.sheet.stPar.multiply, par.sheet.stPar.direct ? "горизонтально" : "вертикально" );

}

else {

::sprintf( buf, "Пользовательский формат : Длина %g, Высота %g", par.sheet.usPar.width,

par.sheet.usPar.height );

}

::Message( buf );

}
