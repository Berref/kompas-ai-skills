# IntersectLinSArc - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectLinSArc_Example (void) {

double x, y;

int k;

Arc ( 60, 60, 30, 0, 90, 1, 1);

LineSeg ( 20, 20, 100, 100, 1);

IntersectArcLin (20, 20, 100, 100, 60, 60, 30, 0, 90, 1, &k, x, y);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k) Point (x, y, 1); /* точка пересечения */

};
