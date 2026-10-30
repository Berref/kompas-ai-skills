# TanLinePointCircle - Получить точки касания окружности и прямой, проходящей через заданную точку

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления касаний и сопряжений ](tan_couple_fncts_common.html) |  Scroll [ [ [ ](measures_fncts_common.html "К следующему разделу")](tan_couple_fncts_common.html "На уровень выше")](tanlineangcircle.html "К предыдущему разделу")  
---|---  
  
[Пример...](tanlinepointcircle_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksTanLinePointCircle](ksmathematic2d_kstanlinepointcircle.html).

Синтаксис:

void TanLinePointCircle (double x,

double y,

double xc,

double yc,

double rad,

int *kp,

double xp,

double yp);

Входные параметры:

x, y | \- координаты точки,  
---|---  
xc, yc | \- координаты центра окружности,  
rad | \- радиус окружности.  
  
Выходной параметр:

kp | \- число касательных (от 0 до 2),  
---|---  
xp, yp | \- координаты точки касания.  
  
Примечание:

Построение касательной невозможно в случае, если точка лежит внутри окружности. В противном случае точек касания или две (точка вне окружности), или одна (если точка принадлежит окружности).

Подразделы:

(отсутствуют)
