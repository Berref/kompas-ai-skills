# TransformPointIntoMatrix - Перевести точку из СК вида в локальную СК

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_transformpointfrommatrix.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_transformobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL TransformPointIntoMatrix( double X, double Y, double * Xn, double * Yn );

Синтаксис COM:

HRESULT TransformPointIntoMatrix( double X, double Y, double * Xn, double * Yn, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- координаты точки в системе координат вида.  
---|---  
  
Выходные параметры:

Xn, Yn | \- координаты точки в локальной СК.  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют).
