# ksRotateObj - Повернуть объект

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Операции редактирования ](bt1734633.html) |  Scroll [ [ [ ](ksdocument2d_kssymmetryobj.html "К следующему разделу")](bt1734633.html "На уровень выше")](ksdocument2d_ksreadgroupfromclip.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [RotateObj](rotateobj.html).

Синтаксис Automation:

long ksRotateObj (long ref,

double x,

double y,

double angle);

Входные параметры:

ref | \- указатель на объект,  
---|---  
x, y | \- координаты центра поворота,  
angle | \- угол поворота (в градусах).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель ref равен нулю, то поворачиваются выделенные объекты документа.

Подразделы:

(отсутствуют)
