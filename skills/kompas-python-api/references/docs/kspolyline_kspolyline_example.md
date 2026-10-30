# ksPolyline, _ksPolyline - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ksPolyline_Example (void) {

static MathPointParam pr1[] = { {10,10}, {20,20}, {30, 10}, {40,20} };

static MathPointParam pr2[] = { {10,15}, {20,25}, {30, 15}, {40,25} };

reference p;

if(ksPolyline(1)) {

for(int i = 0; i < 4; i)

Point(pr1[i].x, pr1[i].y, 1);

p = EndObj();

LightObj(p, 1);

Message(Полилиния);

LightObj(p, 0);

}

PolylineParam par;

//создадим массив неопределенной длины для математических точек

par.pMathPoint = CreateArray(POINT_ARR , 0);

//наполним массив

for(int i = 0; i < 4; i)

AddArrayItem(pMathPoint, -1, &pr2[i], sizeof(MathPointParam));

par.style = 2;

//создадим полилинию (тип линии - тонкая)

reference p = _ksPolyline(&par);

LightObj(p, 1);

Message(Полилиния);

LightObj(p, 0);

}; /* ksPolyline_Example */
