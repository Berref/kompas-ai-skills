# GetFacetPoints - Получить параметры вершин триангуляционной сетки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ITessellation7 ](itessellation7.html) > [ITessellation7 - методы ](itessellation7_methods.html) |  Scroll [ [ [ ](itessellation7_getfacetparams.html "К следующему разделу")](itessellation7_methods.html "На уровень выше")](itessellation7_rebuildtessellation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itessellation7.html)

Синтаксис Automation:

BOOL GetFacetPoints( VARIANT * Points, VARIANT * Indexes, VARIANT * Normals );

Синтаксис COM:

HRESULT GetFacetPoints( VARIANT * Points, VARIANT * Indexes, VARIANT * Normals, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Выходные параметры:

Points | \- массив SafeArray вещественных чисел - координат вершин триангуляционной сетки,  
---|---  
Indexes | \- массив SafeArray целых чисел - индексов вершин триангуляционной сетки,  
Normals | \- массив SafeArray вещественных чисел - нормалей вершин триангуляционной сетки.  
  
Примечание:

1\. В массиве индексов вершин триангуляционной сетки хранятся индексы точек из массива координат точек points. Для получения параметров вершины триангуляционной сетки нужно получить индекс точки из массива indexes.

2\. Координаты точек в массиве points лежат в последовательности x, y, z первой точки, x, y, z второй точки и т.д.

3\. В массиве нормалей вершин триангуляционной сетки координаты нормалей лежат в последовательности x, y, z - нормаль для первой точки, x, y, z- нормаль второй точки и т.д.

Подразделы:

(отсутствуют)
