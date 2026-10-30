# GetGabarit - Получить габаритный параллелепипед поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_getnormal.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_getedgescount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

BOOL GetGabarit (double * x1, double *y1, double *z1, double * x2, double *y2, double *z2);

Синтаксис COM:

BOOL GetGabarit (double * x1, double *y1, double *z1, double * x2, double *y2, double *z2);

Выходные параметры:

x1, y1, z1, x2, y2, z2 | \- координаты вершин габаритного параллелепипеда.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Координаты вершин параллелепипеда возвращаются в системе координат компонента.

Подразделы:

(отсутствуют)
