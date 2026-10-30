# IntersectLinSLinS - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectLinSLinS_Example (void) {

double x, y;

int k;

LineSeg ( 20, 20, 100, 100, 1);

LineSeg ( 80, 20, 0, 50, 1);

IntersectLinSLinS (20, 20, 100, 100, 80, 20, 0, 50, &k, &x, &y);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k) Point (x, y, 1); /* точка пересечения */

};
