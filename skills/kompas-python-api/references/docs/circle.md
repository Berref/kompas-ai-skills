# Circle - Создать окружность

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](equidistant.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](arcbypoint.html "К предыдущему разделу")  
---|---  
  
[Пример...](circle_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCircle](ksdocument2d_kscircle.html).

Синтаксис:

reference Circle (double xc, double yc,

double rad,

int type);

Входные параметры:

xc, yc | \- координаты центра окружности,  
---|---  
rad | \- радиус окружности,  
type | \- [стиль линии](lstyles.html).  
  
Возвращаемое значение:

указатель на окружность | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
