# NearPointProjection - Получить ближайшую проекцию точки на поверхность

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_tessellation.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_istorus.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

BOOL NearPointProjection (double x, double y, double z, double * u, double * v, BOOL ext);

Синтаксис COM:

BOOL NearPointProjection (double x, double y, double z, double * u, double * v, BOOL ext);

Входные параметры:

x, y, z | \- координаты исходной пространственной точки,  
---|---  
ext | \- если проекция точки вне поверхности: \- TRUE проецировать на продолжение поверхности, \- FALSE найти ближайшую граничную точку поверхности. Если проекция точки внутри поверхности, значение этого параметра не учитывается.  
  
Выходные параметры:

u, v | \- параметрические координаты точки на поверхности.  
---|---  
  
Возвращаемое значение:

TRUE | \- если проекция точки попала на саму поверхность или если ext равен TRUE,  
---|---  
FALSE | \- если проекция точки не попала на саму поверхность.  
  
Подразделы:

(отсутствуют)
