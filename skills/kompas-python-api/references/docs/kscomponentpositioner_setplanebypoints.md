# SetPlaneByPoints - Задать плоскость по точкам

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner) ](kscomponentpositioner.html) > [IComponentPositioner - методы ](kscomponentpositioner_methods.html) |  Scroll [ [ [ ](cb1714748.html "К следующему разделу")](kscomponentpositioner_methods.html "На уровень выше")](kscomponentpositioner_setplanebyplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscomponentpositioner.html)

Синтаксис Automation:

BOOL SetPlaneByPoints (double x1,

double y1,

double z1,

double x2,

double y2,

double z2,

double x3,

double y3,

double z3);

Синтаксис COM:

BOOL SetPlaneByPoints (double x1,

double y1,

double z1,

double x2,

double y2,

double z2,

double x3,

double y3,

double z3);

Входные параметры:

x1, y1, z1 | \- координаты первой точки на плоскости,  
---|---  
x2, y2, z2 | \- координаты второй точки на плоскости,  
x3, y3, z3 | \- координаты третьей точки на плоскости.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Координаты точек, задающих плоскость, должны быть определены относительно сборки.

Подразделы:

(отсутствуют)
