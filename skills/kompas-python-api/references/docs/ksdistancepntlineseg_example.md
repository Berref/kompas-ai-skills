# ksDistancePntLineSeg - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Point (10, 10, 1);

LineSeg(20,15,20,25,1);

double len = ksDistancePntLineSeg (10, 10, //координаты точки

20, 15, //первая точка отрезка

20, 25); //вторая точка отрезка

char buf[128];

sprintf(buf, "len = %5.1f", len);

Message(buf);
