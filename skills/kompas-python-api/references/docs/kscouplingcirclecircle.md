# ksCouplingCircleCircle - Получить параметры сопрягающих окружностей определенного радиуса и точки сопряжения для двух окружностей

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления касаний и сопряжений ](tan_couple_fncts_common.html) |  Scroll [ [ [ ](kscouplinglinecircle.html "К следующему разделу")](tan_couple_fncts_common.html "На уровень выше")](couplinglineline.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscouplingcirclecircle_exampls.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksCouplingCircleCircle.](ksmathematic2d_kscouplingcirclecircle.html)

Синтаксис:

void ksCouplingCircleCircle (double xc1,

double yc1,

double radc1,

double xc2,

double yc2,

double radc2,

double rad,

int *kp,

CON *con);

Входные параметры:

xc1, yc1 | \- координаты центра первой окружности,  
---|---  
radc1 | \- радиус первой окружности,  
xc2, yc2 | \- координаты центра второй окружности,  
radc2 | \- радиус второй окружности,  
rad | \- радиус окружности сопряжения.  
  
Выходные параметры:

kp | -количество сопрягающих окружностей,  
---|---  
con | [Структура параметров сопрягающей окружности...](structcon.html) (описана в LTDEFINE.H).  
  
Примечание:

Заполняются до 8 структур CON, если сопряжение существует.

Подразделы:

(отсутствуют)
