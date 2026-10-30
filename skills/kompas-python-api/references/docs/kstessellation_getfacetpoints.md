# GetFacetPoints - Получить параметры вершин триангуляционной сетки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Триангуляция (аппроксимирующая поверхность грани), Интерфейсы ksTessellation, ITessellation ](kstessellation.html) > [ITessellation - методы ](kstessellation_methods.html) |  Scroll [ [ [ ](kstessellation_getfacetsize.html "К следующему разделу")](kstessellation_methods.html "На уровень выше")](kstessellation_getfacetnormals.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kstessellation.html)

Синтаксис Automation:

BOOL GetFacetPoints (VARIANT * points, VARIANT * indexes);

Синтаксис COM:

BOOL GetFacetPoints (VARIANT * points, VARIANT * indexes);

Выходные параметры:

points | \- массив SafeArray вещественных чисел - координат вершин триангуляционной сетки,  
---|---  
indexes | \- массив SafeArray целых чисел - индексов вершин триангуляционной сетки.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. В массиве индексов вершин триангуляционной сетки хранятся индексы точек из массива координат точек points. Для получения параметров вершины триангуляционной сетки нужно получить индекс точки из массива indexes.

2\. Координаты точек в массиве points лежат в последовательности x, y, z первой точки, x, y, z второй точки и т.д.

Подразделы:

(отсутствуют)
