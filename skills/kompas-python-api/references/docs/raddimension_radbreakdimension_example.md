# RadDimension, RadBreakDimension - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void RadDimension_Example (void)

{

reference p;

RDimParam linPar;

memset (&linPar, 0, sizeof(RDimParam));

Circle(50,50,70,1);

//параметры текста

linPar.tPar.bitFlag = _AUTONOMINAL;

linPar.tPar.pText = 0

linPar.tPar.sign = 0; // значок радиуса ставится автоматически

//параметры привязки диаметрального размера

linPar.sPar.xc = 50; linPar.sPar.yc = 50; //центр

linPar.sPar.rad = 70;

//параметры отрисовки диаметрального размера

linPar.dPar.textPos = 75; // положение текста

linPar.dPar.pt1 = 2; // тип стрелки снаружи

linPar.dPar.pt2 = 0; // размерная линия рисуется

linPar.dPar.shelfDir = 1; //полка направлена вправо

linPar.dPar.ang = 30; //угол наклона размерной линии

p = RadDimension (&linPar); // радиальный размер

reference p1;

RBreakDimParam linPar;

memset (&linPar, 0, sizeof (RDimParam));

Circle(150,50,70,1);

//параметры текста

linPar.tPar.bitFlag = 0;

linPar.tPar.pText = CreateArray(CHAR_STR_ARR ,0);

AddArrayItem (linPar.tPar.pText, -1, "100", 8);

linPar.tPar.sign = 0;

//параметры привязки

linPar.sPar.xc = 50; linPar.sPar.yc = 50; //центр

linPar.sPar.rad = 70;

//параметры отрисовки

linPar.dPar.pt = 1; // тип стрелки изнутри

linPar.dPar.ang = 30; // угол

linPar.dPar.pb = 20; // длина излома

p = RadBreakDimension(&linPar); // радиальный размер с изломом

};
