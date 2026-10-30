# TanCircleCircle - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void TanCircleCircle_Example (void)

{

TAN Tang[4];

int k, i;

Circle(60,60,30,1);

Circle (0, 0, 50, 1);

TanCircleCircle (60, 60, 30, 0, 0, 50, &tang[]);

gprintf(Количество касаний = %2d, k);

if (k)

for (I=0; i<k; I)

{

LineSeg (tang.x1[i], tang.y1[i], tang.x2[i], tang.y2[i], 1); /* линия касания */

Point (tang.x1[i], tang.y1[i], 1); /* точка касания */

}

};
