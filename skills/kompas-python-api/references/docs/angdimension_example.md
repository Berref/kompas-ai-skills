# AngDimension - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void AngDimension_Example (void)

{

reference p;

ADimParam angPar;

memset (angPar, 0, sizeof (ADimParam));

LineSeg (40, 0, 40, 40, 1);

LineSeg (40, 0, 60, 20, 1);

//параметры текста

angPar.tPar.bitFlag = _AUTONOMINAL|_DEVIATION|;

angPar.tPar.sign = 0;

angPar.tPar.pText = CreateArray (CHAR_STR_ARR, 0);

AddArrayItem (angPar.tPar.pText, -1, "+0.3", 5);

AddArrayItem (angPar.tPar.pText, -1, "-0.3", 5);

//привязка углового размера

angPar.sPar.xc = 40; angPar.sPar.yc = 0; // центр

angPar.sPar.x1 = 40; angPar.sPar.y1 = 40; // 1 - точка выхода выносной линии

angPar.sPar.x2 = 60; angPar.sPar.y2 = 20; // 2 - точка выхода выносной линии

angPar.sPar.rad = 50; //радиус размерной дуги

angPar.sPar.dir = -1; // размерная линия по часовой стрелке

//отображение размера

angPar.dPar.textPos = 0; //автоматическая простановка

angPar.dPar.textBase = 0; //над серединой размерной линии

angPar.dPar.pl1 = 0; // 1-ая выносной линия есть

angPar.dPar.pl2 = 0; // 2-ая выносной линия есть

angPar.dPar.pt1 = 1; // стрелка изнутри у 1-ой выносной линии

angPar.dPar.pt2 = 1; // стрелка изнутри у 2-ой выносной линии

//параметры выносной полки

angPar.dPar.shelfDir = 0; //полки нет

p = AngDimension(&angPar); //параметры углового размера

};
