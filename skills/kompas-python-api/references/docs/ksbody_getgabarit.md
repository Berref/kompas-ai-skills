# GetGabarit - Получить габарит тела

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [Трехмерное тело (Интерфейсы ksBody, Body) ](ksbody.html) > [IBody - методы ](ksbody_methods.html) |  Scroll [ [ [ ](ksbody_getintersectionfaceswithbody.html "К следующему разделу")](ksbody_methods.html "На уровень выше")](ksbody_getfeature.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbody.html)

Синтаксис Automation:

BOOL GetGabarit (double *x1,

double *y1,

double *z1,

double * x2,

double *y2,

double *z2);

Синтаксис COM:

BOOL GetGabarit (double *x1,

double *y1,

double *z1,

double * x2,

double *y2,

double *z2);

Выходные параметры:

x1, y1, z1 | \- координаты первой вершины габаритного куба,  
---|---  
x2, y2, z2 | \- координаты второй вершины габаритного куба.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
