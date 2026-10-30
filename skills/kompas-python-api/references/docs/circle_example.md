# Circle - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Circle_Example (void)

{

int tc = 1; /сплошная основная

int tl = 3; /осевая линия

reference l1, l2, c1, c2 ;

double x=30, y=20;

double rad1=5; //радиус внутренней окружности

double rad2=8; //радиус внешней окружности

//задание осевых линий

l1 = LineSeg (x-rad2-5, y,x+rad2+5, y, tl);

l2 = LineSeg (x, y-rad2-5, x, y+rad2+5, tl);

//задание окружностей

c1 = Circle (x, y, rad1, tc);

c2 = Circle (x, y, rad2, tc);

};
