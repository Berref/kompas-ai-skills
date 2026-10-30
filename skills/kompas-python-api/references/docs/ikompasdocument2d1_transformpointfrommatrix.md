# TransformPointFromMatrix - Перевести точку из локальной СК в СК вида

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_updatevariables.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_transformpointintomatrix.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL TransformPointFromMatrix( double X, double Y, double * Xn, double * Yn );

Синтаксис COM:

HRESULT TransformPointFromMatrix( double X, double Y, double * Xn, double * Yn, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- координаты точки в локальной системе координат.  
---|---  
  
Выходные параметры:

Xn, Yn | \- координаты точки в СК вида.  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
