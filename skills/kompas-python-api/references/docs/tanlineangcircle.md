# TanLineAngCircle - Получить точки касания окружности и прямой, проходящей под заданным углом

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления касаний и сопряжений ](tan_couple_fncts_common.html) |  Scroll [ [ [ ](tanlinepointcircle.html "К следующему разделу")](tan_couple_fncts_common.html "На уровень выше")](tancirclecircle.html "К предыдущему разделу")  
---|---  
  
[Пример...](tanlineangcircle_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksTanLineAngCircle](ksmathematic2d_kstanlineangcircle.html).

Синтаксис:

void TanLineAngCircle (double xc,

double yc,

double rad,

double ang,

double xp[],

double yp[]);

Входные параметры:

xc, yc | \- координаты центра окружности,  
---|---  
rad | \- радиус окружности,  
ang | \- угол касательной прямой.  
  
Выходные параметры:

xp, yp | \- координаты точки касания.  
---|---  
  
Подразделы:

(отсутствуют)
