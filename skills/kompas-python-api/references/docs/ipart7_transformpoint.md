# TransformPoint - Перевод координат точки присланной детали Part1 в систему координат детали

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_transformpoints.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_setmaterial.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BOOL TransformPoint( double * X, double * Y, double * Z, IPart7 * Part1 );

Синтаксис COM :

HRESULT TransformPoint( double * X, double * Y, double * Z, IPart7 * Part1, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y, Z | \- координаты точки в системе координат детали Part1,  
---|---  
Part1 | \- указатель на интерфейс детали [IPart7](ipart7.html), из системы координат которой нужно перевести точку.  
  
Выходные параметры:

X, Y, Z | \- координаты точки в системе координат детали.  
---|---  
  
Подразделы:

(отсутствуют)
