# SetAxisByPoints - Задать ось по точкам

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner) ](kscomponentpositioner.html) > [IComponentPositioner - методы ](kscomponentpositioner_methods.html) |  Scroll [ [ [ ](kscomponentpositioner_setdragpoint.html "К следующему разделу")](kscomponentpositioner_methods.html "На уровень выше")](kscomponentpositioner_setaxis.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscomponentpositioner.html)

Синтаксис Automation:

BOOL SetAxisByPoints (double x1,

double y1,

double z1,

double x2,

double y2,

double z2);

Синтаксис COM:

BOOL SetAxisByPoints (double x1,

double y1,

double z1,

double x2,

double y2,

double z2);

Входные параметры:

x1, y1, z1 | \- координаты первой точки оси,  
---|---  
x2, y2, z2 | \- координаты второй точки оси.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Координаты точек, задающих ось, должны быть определены относительно сборки.

Подразделы:

(отсутствуют)
