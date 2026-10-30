# TanLinePointCircle- пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void TanLinePointCircle_Example (void) {

double x[2], y[2];

int k, i;

Circle ( 60, 60, 30, 1);

Point ( 20, 50, 1);

TanLinePointCircle (20, 50, 60, 60, 30, &k, x, y);

gprintf(Количество касаний = %2d, k);

if (k)

for (I=0; i<k; I) {

LineSeg (20, 50, x[i], y[i], 1); /* линия касания */

Point (x[i], y[i], 1); /* точка касания */

}

}; /* TanLinePointCircle_Example */
