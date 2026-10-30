# GetGabarit - Получить габаритный параллелепипед кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [ICurve3D - методы ](kscurve3d_methods.html) |  Scroll [ [ [ ](kscurve3d_getlength.html "К следующему разделу")](kscurve3d_methods.html "На уровень выше")](kscurve3d_getderivativettt.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurve3d.html)

Синтаксис Automation:

BOOL GetGabarit (double * x1,

double *y1,

double *z1,

double * x2,

double *y2,

double *z2);

Синтаксис COM:

BOOL GetGabarit (double * x1,

double *y1,

double *z1,

double * x2,

double *y2,

double *z2);

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
