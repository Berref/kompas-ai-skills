# GetPoint - Получить координаты вершины триангуляционной сетки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Триангуляция (аппроксимирующая поверхность грани), Интерфейсы ksTessellation, ITessellation ](kstessellation.html) > [ITessellation - методы ](kstessellation_methods.html) |  Scroll [ [ [ ](kstessellation_getpointscount.html "К следующему разделу")](kstessellation_methods.html "На уровень выше")](kstessellation_getnormal.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kstessellation.html)

Синтаксис Automation:

BOOL GetPoint (long index, double * x, double * y, double * z);

Синтаксис COM:

BOOL GetPoint (int index, float * x, float * y, float * z);

Входные параметры:

index | \- индекс вершины в массиве вершин.  
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
