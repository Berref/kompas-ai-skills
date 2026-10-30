# ksCouplingLineLine - Получить параметры сопряжения двух прямых

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления касаний и сопряжений ](tan_couple_fncts_common.html) |  Scroll [ [ [ ](kstanlinepointcurve.html "К следующему разделу")](tan_couple_fncts_common.html "На уровень выше")](kscouplinglinecircle.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscouplinglineline_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksCouplingLineLine](ksmathematic2d_kscouplinglineline.html).

Синтаксис:

void CouplingLineLine (double x1,

double y1,

double angle1,

double x2,

double y2,

double angle2,

double rad,

int *kp,

CON *con);

Входные параметры:

x1, y1 | \- координаты точки на первой прямой,  
---|---  
angle1 | \- угол наклона первой прямой,  
x2, y2 | \- координаты точки на второй прямой,  
angle2 | \- угол наклона второй прямой.  
  
Выходные параметры:

rad | \- радиус окружности сопряжения,  
---|---  
kp | -количество сопрягающих окружностей,  
con | \- [Структура параметров сопрягающей окружности...](structcon.html) (описана в LTDEFINE.H).  
  
Примечание:

Заполняются 4 структуры con, если сопряжение есть.

Подразделы:

(отсутствуют)
