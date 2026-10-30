# TanCircleCircle - Получить координаты точек касания прямых к двум окружностям

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления касаний и сопряжений ](tan_couple_fncts_common.html) |  Scroll [ [ [ ](tanlineangcircle.html "К следующему разделу")](tan_couple_fncts_common.html "На уровень выше")](kstanlinepointcurve.html "К предыдущему разделу")  
---|---  
  
[Пример...](tancirclecircle_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksTanCircleCircle](ksmathematic2d_kstancirclecircle.html).

Синтаксис:

int TanCircleCircle (double xc1,

double yc1,

double radius1,

double xc2,

double yc2,

double radius2,

struct TAN tang);

Входные параметры:

xc1, yc1 | \- координаты центра первой окружности,  
---|---  
radius1 | \- радиус первой окружности,  
xc2, yc2 | \- координаты центра второй окружности,  
radius2 | \- радиус второй окружности.  
  
Выходной параметр:

tang | \- указатель на массив [структур параметров касательных отрезков](structtan.html).  
---|---  
  
Описание:

Функция определяет точки касания прямых к двум окружностям. Структура типа TAN (описана в LIBTOOL.H) содержит координаты двух точек касания и определяет одну касательную прямую. Касательных прямых может быть от 0 до 4.

Подразделы:

(отсутствуют)
