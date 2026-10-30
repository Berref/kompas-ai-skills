# GetPointFirst - Получить координаты первой точки отрезка

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [Параметры отрезка (Интерфейсы ksLineSeg3dParam,ILineSeg3dParam) ](kslineseg3dparam.html) > [ILineSeg3dParam - методы ](kslineseg3dparam_methods.html) |  Scroll [ [ [ ](kslineseg3dparam_getpointlast.html "К следующему разделу")](kslineseg3dparam_methods.html "На уровень выше")](kslineseg3dparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kslineseg3dparam.html)

Синтаксис Automation:

BOOL GetPointFirst (double * x, double *y, double *z);

Синтаксис COM:

BOOL GetPointFirst (double * x, double *y, double *z);

Выходные параметры:

x, y, z | \- координаты первой точки отрезка.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Значения x, y, z возвращаются в системе координат компонента.

Подразделы:

(отсутствуют)
