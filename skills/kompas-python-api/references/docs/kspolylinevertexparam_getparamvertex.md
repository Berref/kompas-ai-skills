# GetParamVertex - Получить параметры вершины

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс параметров вершины ломаной Интерфейсы ksPolyLineVertexParam, IPolygonalLineVertexParam) ](kspolylinevertexparam.html) > [IPolygonalLineVertexParam - методы ](kspolylinevertexparam_methods.html) |  Scroll [ [ [ ](kspolylinevertexparam_getvertex.html "К следующему разделу")](kspolylinevertexparam_methods.html "На уровень выше")](kspolylinevertexparam_getparambydistance.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinevertexparam.html)

Синтаксис:

BOOL GetParamVertex (double *x, double *y, double *z, double *radius);

Входные параметры:

x | \- x координата вершины,  
---|---  
y | \- y координата вершины,  
z | \- z координата вершины,  
radius | \- радиус.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
