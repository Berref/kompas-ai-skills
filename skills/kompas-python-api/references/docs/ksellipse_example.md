# ksEllipse - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
EllipseParam par;

par.xc = 20;

par.yc = 20; //координаты центра

par.a = 30;

par.b = 10; //полуоси эллипса

par.ang = 45; //угол наклона эллипса к оси X

par.style = 1; //тип линии

reference p = ksEllipse(&par);

LightObj (p, 1);
