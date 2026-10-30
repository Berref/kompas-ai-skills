# DiamDimension - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void DiamDimension_Example (void)

K DiamDimension

{

reference p;

RDimParam linPar;

memset (&linPar, 0, sizeof (RDimParam));

Circle(50,50,70,1);

//параметры текста

linPar.tPar.bitFlag = _AUTONOMINAL; // автоматическая простановка текста

linPar.tPar.pText = 0;

linPar.tPar.sign = 0; // знак диаметра ставится автоматически

//параметры привязки диаметрального размера

linPar.sPar.xc = 50; linPar.sPar.yc = 50; // координаты центра

linPar.sPar.rad = 70;

//параметры отрисовки диаметрального размера

linPar.dPar.textPos = 75; // положение текста

inPar.dPar.pt1 = 1; // тип стрелки -изнутри

linPar.dPar.pt2 = 1; // тип стрелки -изнутри

//параметры выносной полки

linPar.dPar.shelfDir = 1; // полка направлена вправо

linPar.dPar.ang = -30; // угол наклона размерной линии

p = DiamDimension(&linPar); // диаметральный размер

};
