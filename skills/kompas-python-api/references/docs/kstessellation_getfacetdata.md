# GetFacetData - Получить данные триангуляционной пластины по индексу в массиве триангуляционных пластин

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Триангуляция (аппроксимирующая поверхность грани), Интерфейсы ksTessellation, ITessellation ](kstessellation.html) > [ITessellation - методы ](kstessellation_methods.html) |  Scroll [ [ [ ](kstessellation_getfacetnormals.html "К следующему разделу")](kstessellation_methods.html "На уровень выше")](kstessellation_getfacetscoun.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kstessellation.html)

Синтаксис Automation:

BOOL GetFacetData (long index, LPDISPATCH facet);

Синтаксис COM:

BOOL GetFacetData (int index, LPFACET facet);

Входные параметры:

index | \- индекс триангуляционной пластины в массиве,  
---|---  
facet | \- указатель на интерфейс [ksFacet](ksfacet.html) или [IFacet](ksfacet.html).  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Указатель на интерфейс триангуляционной пластины не должен быть равен 0.

Подразделы:

(отсутствуют)
