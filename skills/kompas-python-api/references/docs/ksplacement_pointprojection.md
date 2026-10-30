# PointProjection - Получить проекцию точки на плоскость XY

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Положение объекта (Интерфейсы ksPlacement, IPlacement) ](ksplacement.html) > [IPlacement - методы ](ksplacement_methods.html) |  Scroll [ [ [ ](ksplacement_pointprojection.html "К следующему разделу")](ksplacement_methods.html "На уровень выше")](ksplacement_initbymatrix3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplacement.html)

Синтаксис Automation:

BOOL PointProjection (double XIn, double YIn, double ZIn, double * XOut, double * YOut);

Синтаксис COM:

BOOL PointProjection (double XIn, double YIn, double ZIn, double * XOut, double * YOut);

Входные параметры:

XIn, YIn, ZIn | \- координаты исходной пространственной точки.  
---|---  
  
Выходные параметры:

XOut, YOut | \- координаты точки на плоскости XY.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
