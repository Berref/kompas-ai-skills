# NearPointProjection - Получить ближайшую проекцию точки на поверхность

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [ICurve3D - методы ](kscurve3d_methods.html) |  Scroll [ [ [ ](kslineseg3dparam.html "К следующему разделу")](kscurve3d_methods.html "На уровень выше")](kscurve3d_isstraight.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurve3d.html)

Синтаксис Automation:

BOOL NearPointProjection (double x, double y, double z, double * t, BOOL ext);

Синтаксис COM:

BOOL NearPointProjection (double x, double y, double z, double * t, BOOL ext);

Входные параметры:

x, y, z | \- координаты исходной пространственной точки,  
---|---  
ext | \- если проекция точки вне кривой: \- TRUE проецировать на продолжение кривой, \- FALSE найти ближайшую граничную точку кривой. Если проекция точки внутри кривой, значение этого параметра не учитывается.  
  
Выходные параметры:

t | \- параметрические координаты точки на кривой.  
---|---  
  
Возвращаемое значение:

TRUE | \- если проекция точки попала на саму кривую или если ext равен TRUE,  
---|---  
FALSE | \- если проекция точки не попала на саму кривую.  
  
Подразделы:

(отсутствуют)
