# IntersectCurvCurv - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectCurvCurv_Example (void) {

double x[8], y[8];

int k, I;

reference p1, p2;

p1 = Circle ( 60, 60, 30, 1);

p2 = Bezier ( 0, 2);

Point ( 20, 20, 0);

Point ( 40, 50, 0);

Point ( 50, 30, 0);

Point ( 70, 90, 0);

Point (100, 20, 0);

EndObj();

IntersectCurvCurv (p1, p2, &k, x, y, 99);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k)

for (I=0; i<k; I) Point (x[i], y[i], 1); /* точки пересечения */

};
