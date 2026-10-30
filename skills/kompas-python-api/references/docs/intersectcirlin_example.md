# IntersectCirLin - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectCirLin_Example (void) {

double x, y;

int k;

Circle ( 60, 60, 30, 1);

Line ( 20, 20, 45);

IntersectCirLine (60, 60, 30, 20, 20, 45, &k, &x, &y);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k) Point (x, y, 1); /* точка пересечения */

};
