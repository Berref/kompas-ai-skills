# ksMovePointOnCurve - Получить координаты точки, находящейся на указанном расстоянии вдоль кривой от указанной точки

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksmovepointoncurveex.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](ksgetsnapinfo.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksmovepointoncurve_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksMovePointOnCurve](ksmathematic2d_ksmovepointoncurve.html).

Синтаксис:

int ksMovePointOnCurve (reference curve,

double * x, double * y,

double len,

int dir);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
len | \- расстояние, на которое нужно сместить точку,  
dir | \- направление продвижения точки: 1 - в направлении построения кривой, -1 - в обратном направлении.  
  
Выходные параметры:

x, y | \- координаты точки.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если точка не находится на кривой, она проецируется на кривую.

Подразделы:

(отсутствуют)
