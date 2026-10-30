# ksMovePointOnCurve - Получить координаты точки, находящейся на указанном вдоль кривой расстоянии от указанной точки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksperpendicular.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksintersectlinslins.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksMovePointOnCurve](ksmovepointoncurve.html).

Синтаксис Automation:

long ksMovePointOnCurve (long curve,

double* x,

double* y,

double len,

long dir);

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
