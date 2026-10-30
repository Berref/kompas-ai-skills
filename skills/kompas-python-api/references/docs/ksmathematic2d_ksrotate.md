# ksRotate - Повернуть точку относительно центра

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kssind.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kspointsoncurvebystep.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [Rotate](rotate.html).

Синтаксис Automation:

BOOL ksRotate (double x,

double y,

double xc,

double yc,

double ang,

double* xr,

double* yr);

Входные параметры:

x, y | \- координаты базовой точки,  
---|---  
xс, yс | \- координаты центра поворота,  
ang | \- угол поворота.  
  
Выходные параметры:

xr, yr | \- координаты точки после поворота.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
