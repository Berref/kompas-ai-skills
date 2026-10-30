# ksEllipseArc - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
EllipseArcParam par;

memset(&info, 0, sizeof(info));

par.xc = 20;

par.yc = 20; //координаты центра

par.a = 30;

par.b = 10; //полуоси эллипса

par.ang = 45; //угол наклона эллипса к оси X

par.angFirst = 10; //начальный угол дуги

par.angSecond =300; //конечный угол дуги

par.dir = 1; //направление

par.style = 1; //тип линии

reference p = KsEllipseArc(&par);

LightObj (p, 1); ConicArcParam par;
