# GetFacetParams - Получить параметрические координаты вершин триангуляционных сетки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Триангуляция (аппроксимирующая поверхность грани), Интерфейсы ksTessellation, ITessellation ](kstessellation.html) > [ITessellation - методы ](kstessellation_methods.html) |  Scroll [ [ [ ](kstessellation_getfacetsag.html "К следующему разделу")](kstessellation_methods.html "На уровень выше")](kstessellation_getfacetsize.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kstessellation.html)

Синтаксис Automation:

BOOL GetFacetParams( VARIANT * params );

Синтаксис COM:

BOOL GetFacetParams( VARIANT * params );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходной параметр:

params | \- SafeArray - массив вещественных чисел - параметрических координат вершин триангуляционных сетки. Для формирование параметрических координат триангуляционной сетки требуется установить признак [ksTessellation::SetNeedParams](kstessellation_setneedparams.html).  
---|---  
  
Примечание:

В массиве параметрические координаты вершин лежат в последовательности:

u, v для первой точки, u, v второй точки и т.д.

Подразделы:

(отсутствуют)
