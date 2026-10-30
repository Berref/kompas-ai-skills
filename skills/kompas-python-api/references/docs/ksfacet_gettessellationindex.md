# GetTessellationIndex - Получить индекс вершины в массиве вершин триангуляционной сетки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Триангуляция (аппроксимирующая поверхность грани), Интерфейсы ksTessellation, ITessellation ](kstessellation.html) > [Триангуляционная пластина (Интерфейсы ksFacet, IFacet) ](ksfacet.html) > [IFacet - методы ](ksfacet_methods.html) |  Scroll [ [ [ ](kssphereparam.html "К следующему разделу")](ksfacet_methods.html "На уровень выше")](ksfacet_getnormal.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfacet.html)

Синтаксис Automation:

long GetTessellationIndex (long index);

Синтаксис COM:

int GetTessellationIndex (int index);

Входной параметр:

index | \- индекс вершины в пластине.  
---|---  
  
Возвращаемое значение:

Индекс вершины в массиве вершин триангуляционной сетки | \- в случае успеха,  
---|---  
-1 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
