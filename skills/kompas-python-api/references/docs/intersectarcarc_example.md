# IntersectArcArc - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectArcArc_Example (void) {

double x[2], y[2];

int k, i;

Arc ( 60, 60, 30, -90, 90, 1, 1);

Arc ( 75, 60, 30, -90, 90, -1, 1);

IntersectArcArc (60, 60, 30, -90, 90, 1, 75, 60, 30, -90, 90, -1, &k, x, y);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k)

for (I=0; i<k; I) Point (x[i], y[i], 1); /* точки пересечения */

};
