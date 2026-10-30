# GetDocOptions - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
DimensionsOptrions par;

memset (&par, 0, sizeof (DimensionsOptrions));

if (GetDocOptions (DIMENTION_OPTIONS, &par, sizeof(DimensionsOptrions)))

{

char buf[128];

Message("Настройки размеров текущего документа");

sprintf (buf, "Выход выносных линий за размерную=%0.1f;

Расстояние от разм.линии до текста=%0.1f;",

par.proLineExtension, par.textDistanceFromDimLine);

Message(buf);

sprintf (buf, "Расстояние от выносных линий до текста=%0.1f;

Выход размерной линии за текст=%0.1f;",

par.textDistanceFromProLine, par.dimLineExtension);

Message(buf);

sprintf (buf, "Длина стрелки для размера=%0.1f; Кол-во знаков после запятой=%d;",

par.arrowLength, par.decimalsCount);

Message(buf);

sprintf (buf, "Стиль текста=%d; точность углового размера=%s", par.style,

!par.anglePrecisionLevel ? "градусы" : par.anglePrecisionLevel ==1 ? "минуты" :

"секунды");

Message(buf);

}
