# IntersectLinLin - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void IntersectLinLin_Example (void) {

double x, y;

int k;

Line ( 20, 20, 45);

Line ( 80, 20, 120);

IntersectLinLine (20, 20, 45, 80, 20, 120, &k, &x, &y);

char buf[128];

sprintf(buf, "Количество пересечений = %i", k);

::Message(buf);

if (k) Point (x, y, 1); /* точка пересечения */

}; /* IntersectLinLin_Example */
