# ksCouplingCircleCircle - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//поиск окружностей сопряжения для двух окружностей

double rad = 20;

int kp;

CON con[8];

Circle(100, 100, 100, 1);

Circle(100, 150, 100, 1);

ksCouplingCircleCircle(100, 100, 100, //параметры первой окружности

100, 150, 100, //параметры второй окружности

rad, &kp, con);

//отрисуем окружности и точки сопряжения

for (short i = 0 ; i<8; i) {

Circle(con[i].xc, con[i].yc, rad,2);

Point(con[i].x1,con[i].y1,i);

Point(con[i].x2,con[i].y2,i);

}
