# GetFacetNormals - Получить параметры нормалей вершин триангуляционной сетки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Триангуляция (аппроксимирующая поверхность грани), Интерфейсы ksTessellation, ITessellation ](kstessellation.html) > [ITessellation - методы ](kstessellation_methods.html) |  Scroll [ [ [ ](kstessellation_getfacetpoints.html "К следующему разделу")](kstessellation_methods.html "На уровень выше")](kstessellation_getfacetdata.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kstessellation.html)

Синтаксис Automation:

BOOL GetFacetNormals (VARIANT * normals);

Синтаксис COM:

BOOL GetFacetNormals (VARIANT * normals);

Выходные параметры:

normals | \- массив SafeArray вещественных чисел - нормалей вершин триангуляционной сетки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. В массиве нормалей вершин триангуляционной сетки координаты нормалей лежат в последовательности x, y, z нормаль для первой точки, x, y, z нормаль второй точки и т.д.

2\. Функция используется совместно с [GetFacetPoints](kstessellation_getfacetpoints.html).

Подразделы:

(отсутствуют)
