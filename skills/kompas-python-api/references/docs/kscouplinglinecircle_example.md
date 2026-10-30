# ksCouplingLineCircle - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//поиск окружностей сопряжения для прямой и окружности

double rad = 20;

int kp;

CON con[8];

Circle(100, 100, 100, 1);

Line(100, 100, 45);

ksCouplingLineCircle(100, 100, 100, //параметры окружности

100, 100, 45, //параметры линии

rad, &kp, con);

//отрисуем окружности и точки сопряжения

for (short i = 0 ; i<8; i) {

Circle(con[i].xc, con[i].yc, rad,2);

Point(con[i].x1,con[i].y1,i);

Point(con[i].x2,con[i].y2,i);

}
