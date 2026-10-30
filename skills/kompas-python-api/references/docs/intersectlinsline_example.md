# IntersectLinSLine - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectLinSLine_Example (void) {

double x, y;

int k;

LineSeg ( 20, 20, 100, 100, 1);

Line ( 80, 20, 120);

IntersectLinSLine (20, 20, 100, 100, 80, 20, 120, &k, &x, &y);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k) Point (x, y, 1); /* точка пересечения */

};
