# GetParamByDistance - Получить расстояние и радиус

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс параметров вершины ломаной Интерфейсы ksPolyLineVertexParam, IPolygonalLineVertexParam) ](kspolylinevertexparam.html) > [IPolygonalLineVertexParam - методы ](kspolylinevertexparam_methods.html) |  Scroll [ [ [ ](kspolylinevertexparam_getparamvertex.html "К следующему разделу")](kspolylinevertexparam_methods.html "На уровень выше")](kspolylinevertexparam_getindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinevertexparam.html)

Синтаксис:

BOOL GetParamByDistance (double * distance, double * radius);

Входные параметры:

distance | \- расстояние до предыдущей вершины,  
---|---  
radius | \- радиус.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Для вершины с индексом 0 расстояние выдается до вершины с индексом 1. Для остальных вершин расстояние выдается до вершины с индексом на 1 меньше, чем у данной вершины.

2\. Получить расстояние можно для любого типа построения.

3\. Установить расстояние можно, если тип построения [ksLineBuildingType](kslinebuildingtype.html) не равен ksLBTByPoint.

Подразделы:

(отсутствуют)
