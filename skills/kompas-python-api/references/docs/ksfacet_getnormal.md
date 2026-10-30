# GetNormal - Получить координаты нормали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Триангуляция (аппроксимирующая поверхность грани), Интерфейсы ksTessellation, ITessellation ](kstessellation.html) > [Триангуляционная пластина (Интерфейсы ksFacet, IFacet) ](ksfacet.html) > [IFacet - методы ](ksfacet_methods.html) |  Scroll [ [ [ ](ksfacet_gettessellationindex.html "К следующему разделу")](ksfacet_methods.html "На уровень выше")](ksfacet_getpointscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfacet.html)

Синтаксис Automation:

BOOL GetNormal (long index, double * x, double *y, double *z);

Синтаксис COM:

BOOL GetNormal (int index, float * x, float *y, float *z);

Входной параметр:

index | \- индекс вершины в пластине.  
---|---  
  
Выходные параметры:

x, y, z | \- координаты вершины.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
