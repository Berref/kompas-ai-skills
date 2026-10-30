# ksGetCurvePointProjection - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference curve = ::LineSeg (300, 100, -400, -200, 1);

double x = 100;

double y = 50;

::ksGetCurvePointProjection (curve, x, y, &x, &y); // проецируем точку на кривую

char buf[128];

::sprintf (buf, "координаты проекции точки на кривой: (%g, %g)", x, y);

::Message(buf);
