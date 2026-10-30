# ksCouplingLineCircle - Получить параметры сопрягающих окружностей определенного радиуса и точки касания при сопряжении окружности и прямой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления касаний и сопряжений ](tan_couple_fncts_common.html) |  Scroll [ [ [ ](kscouplinglineline.html "К следующему разделу")](tan_couple_fncts_common.html "На уровень выше")](kscouplingcirclecircle.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscouplinglinecircle_example.html)

Аналог данной функции при использовании Automation - метод [Mathematic2D::ksCouplingLineCircle](ksmathematic2d_kscouplinglinecircle.html).

Синтаксис:

void ksCouplingLineCircle (double xc,

double yc,

double radc,

double x1,

double y1,

double angle1,

double rad,

int *kp,

CON *con);

Входные параметры:

xc, yc | \- координаты центра окружности,  
---|---  
radc | \- радиус окружности,  
x1, y1 | \- координаты точки на прямой,  
angle1 | \- угол наклона прямой.  
  
Выходные параметры:

rad | \- радиус окружности сопряжения,  
---|---  
kp | -количество сопрягающих окружностей,  
con | \- [Структура параметров сопрягающей окружности...](structcon.html) (описана в LTDEFINE.H).  
  
Примечание:

Заполняются до 8 структур CON, если сопряжение существует.

Подразделы:

(отсутствуют)
