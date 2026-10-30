# ksConicArc - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
ConicArcParam par;

//заполним структуру канонического уравнения для конического сечения- дуги эллипса

// A*x*x B*x*y C*y*y D*x E*y F = 0;

par.A = 16.;

par.B = 0;

par.C = 9.;

par.D = 0;

par.E = 0;

par.F = -144.;

par.x1 = 3; par.y1 =0;

par.x2 = -3; par.y2 = 0;

par.style = 2;

reference p = ksConicArc(& par);

//подсветим объект

LightObj (p, 1);

Message ("Коническое сечение");

//выключим подсветку объекта

LightObj (p, 0);
