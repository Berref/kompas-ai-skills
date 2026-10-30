# CutLine - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void CutLine_Example (void) {

reference p;

CutLineParam cutPar;

memset(&cutPar, 0, sizeof(CutLineParam));

cutPar.right =1; // стрелка справа

strcpy (cutPar.str, A); // надпись

cutPar.x1 = 30; // координаты надписи у первого участка

cutPar.y1 = 65;

cutPar.x2 = 95; // координаты надписи у второго участка

cutPar.y2 = 15;

cutPar.pMathPoint = CreateArray(POINT_ARR, 0);

MathPointParam par;

par.x=50; par.y=50; // первая точка

AddArrayItem(cutPar.pMathPoint, -1, &par, sizeof(par));

par.x=50; par.y=30; // вторая точка

AddArrayItem(cutPar.pMathPoint, -1, &par, sizeof(par));

p = CutLine(&cutPar);

}; /* CutLine_Example */
