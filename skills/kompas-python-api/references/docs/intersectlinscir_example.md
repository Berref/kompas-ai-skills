# IntersectLinSCir - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectLinSCir_Example (void) {

double x, y;

int k;

Circle ( 60, 60, 30, 1);

LineSeg ( 20, 20, 100, 100, 1);

IntersectLinSCir (20, 20, 100, 100, 60, 60, 30, &k, &x, &y);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k) Point (x, y, 1); /* точка пересечения */

};
