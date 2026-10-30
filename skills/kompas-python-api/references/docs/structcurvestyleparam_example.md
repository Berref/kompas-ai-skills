# Пример использования структуры параметров CurveStyleParam

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
CurveStyleParam par; //структура параметров стиля кривой

memset (&par, 0, sizeof (par));

CurvePattern cPatt; //структура параметров участка штриховой кривой

par.pattern = CreateArray (CURVE_PATTERN_ARR, 0);

cPatt.visibleSeg = 15;

cPatt.invisibleSeg = 7;

AddArrayItem (par.pattern, -1, &cPatt, sizeof (cPatt));

cPatt.visibleSeg = 3;

cPatt.invisibleSeg = 7;

AddArrayItem (par.pattern, -1, &cPatt, sizeof (cPatt));

strcpy (par.name, "style from library"); //имя стиля

par.color = RGB (255, 0, 0); //цвет линии

par.paperWidth = 0.8; //толщина пера на бумаге

par.screenWidth = 3; //толщина линии на экране

par.curveType = 1|LIKE_BASIC_LINE; //прерывистая линия с параметрами пера

//как у системной основной линии

par.even = 1; //кривая всегда оканчивается штрихом

UINT tl = AddStyle (CURVE_STYLE, &par, sizeof (par), 0);

LineSeg (20, 20, 70, 20, tl);

int t = GetStyleParam (CURVE_STYLE, tl, &par, sizeof (par));

if (t) {

char buf[128];

sprintf (buf, "curveType = %s",

par.curveType & LIKE_BASIC_LINE ? "LIKE_BASIC_LINE" : "NO");

Message (buf);

}

else

Error("Ошибка");
