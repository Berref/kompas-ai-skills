# TransformPoint - Перевести координаты точки присланной детали part1 в систему координат детали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_transformpoints.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_setuserparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL TransformPoint (double* x, double* y, double* z, LPDISPATCH part1);

Синтаксис COM:

BOOL TransformPoint (double* x, double* y, double* z, LPPART part1);

Входные параметры:

x, y, z | \- координаты точки в системе координат детали part1,  
---|---  
part1 | указатель на интерфейс детали [ksPart](kspart.html), из системы координат которой нужно перевести точку.  
  
Выходные параметры:

x, y, z | \- координаты точки в системе координат детали.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
