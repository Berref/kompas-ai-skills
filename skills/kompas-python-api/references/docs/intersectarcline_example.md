# IntersectArcLine - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectArcLin_Example (void) {

double x[2], y[2];

int k, i;

Arc ( 60, 60, 30, 0, 90, 1, 1);

Line ( 20, 20, 45);

IntersectArcLin (60, 60, 30, 0, 90, 1, 20, 20, 45, &k, x, y);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k)

for (I=0; i<k; I) Point (x[i], y[i], 1); /* точки пересечения */

};
