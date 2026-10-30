# DecomposeObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
{

reference p;

LDimParam linPar;

memset(&linPar, 0,sizeof(LDimParam));

//параметры текста

linPar.tPar.bitFlag = _AUTONOMINAL|_PREFIX|_TOLERANCE|_DEVIATION|_UNIT;

linPar.tPar.sign = 1; //диаметр

linPar.tPar.pText = CreateArray(CHAR_STR_ARR, 0);

AddArrayItem(linPar.tPar.pText, -1, 2отв., 6); // _PREFIX

AddArrayItem(linPar.tPar.pText, -1, H12, 4); // _TOLERANCE

AddArrayItem(linPar.tPar.pText, -1, мм, 5); // _UNIT

//параметры привязки

linPar.sPar.ps = 0; // 0-горизонтальный

linPar.sPar.x1 = 50; linPar.sPar.y1 = 50; // 1-ая точка

linPar.sPar.x2 = 70; linPar.sPar.y2 = 60; // 2-ая

linPar.sPar.dy = -20; // вектор определяющий положение размерной линии

linPar.sPar.dx = 0;

linPar.sPar.basePoint = 1; // признак 1-dx, dy -откладывать от первой точки, 2- от второй

// параметры отрисовки линейного размера

linPar.dPar.textPos = 0; // автоматическая простановка

linPar.dPar.textBase = 0; // от средины размера

linPar.dPar.pl1 = 0; // 1-ая выносная линия есть

linPar.dPar.pl2 = 0; // 2-ая выносная линия есть

linPar.dPar.pt1 = 1; // тип стрелки у 1-ой выносной линии 1-изнутри

linPar.dPar.pt2 = 1; // тип стрелки у 2-ой выносной линии 1-изнутри

linPar.dPar.shelfDir = -1; // полка направлена влево

linPar.dPar.ang = -30; // угол наклона ножки

linPar.dPar.length = 20; // длина ножки

p = LinDimension(&linPar); //параметры линейного размера

DecomposeObj(p, 0, 5, 0);

}
