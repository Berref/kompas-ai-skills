# SetDragPoint - Задать точку захвата (ручка)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner) ](kscomponentpositioner.html) > [IComponentPositioner - методы ](kscomponentpositioner_methods.html) |  Scroll [ [ [ ](kscomponentpositioner_setplane.html "К следующему разделу")](kscomponentpositioner_methods.html "На уровень выше")](kscomponentpositioner_setaxisbypoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscomponentpositioner.html)

Синтаксис Automation:

BOOL SetDragPoint (double x, double y, double z);

Синтаксис COM:

BOOL SetDragPoint (double x, double y, double z);

Входные параметры:

x, y, z | \- координаты точки захвата.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Точка захвата должна быть определена в системе координат сдвигаемого компонента.

Подразделы:

(отсутствуют)
