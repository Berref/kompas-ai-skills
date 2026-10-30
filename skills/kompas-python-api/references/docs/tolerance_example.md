# Tolerance - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Tolerance_Example (void) {

ToleranceParam par;

memset(&par, 0, sizeof(ToleranceParam));

MathPointParam parPoint;

reference p;

par.branch1.pMathPoint = CreateArray(POINT_ARR, 0);

parPoint.x = 40; parPoint.y = 10;

AddArrayItem(par.branch1.pMathPoint, -1, &parPoint , sizeof(parPoint));

par.branch1.arrowType = 2;

par.branch1.tCorner = 1;

par.branch2.pMathPoint = CreateArray(POINT_ARR, 0);

parPoint.x = 100; parPoint.y = 50;

AddArrayItem(par.branch2.pMathPoint, -1, &parPoint , sizeof(parPoint));

parPoint.x = 100; parPoint.y = 10;

AddArrayItem(par.branch2.pMathPoint, -1, &parPoint , sizeof(parPoint));

par.branch2.arrowType = 1;

par.branch2.tCorner = 5;

par.x = 40 ; par.y = 40; par.type = 0;

if (Tolerance(&par)) {

ColumnNumber(1);

int tip = 26; //значек допуск соосности

TextLine (SPECIAL_SYMBOL ,SPECIAL, &tip ,);

ColumnNumber(2);

tip = 2; //значек диаметр

TextLine (SPECIAL_SYMBOL ,SPECIAL, &tip ,);

TextLine (NEW_LINE ,0,0 ,0,004);

tip=30; //зависимый допуск

TextLine (SPECIAL_SYMBOL ,SPECIAL, &tip ,);

ColumnNumber(3);

TextLine (NEW_LINE ,0,0 ,A);

p = EndObj();

}

DeleteArray(par.branch2.pMathPoint);

DeleteArray(par.branch1.pMathPoint);

}; /* Tolerance_Example */
