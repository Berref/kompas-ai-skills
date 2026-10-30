# GetVertex - Получить вершину

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс параметров вершины ломаной Интерфейсы ksPolyLineVertexParam, IPolygonalLineVertexParam) ](kspolylinevertexparam.html) > [IPolygonalLineVertexParam - методы ](kspolylinevertexparam_methods.html) |  Scroll [ [ [ ](kspolylinevertexparam_setassociation.html "К следующему разделу")](kspolylinevertexparam_methods.html "На уровень выше")](kspolylinevertexparam_getparamvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinevertexparam.html)

Синтаксис Automation:

ksEntity * GetVertex();

Синтаксис COM:

LPENTITY GetVertex();

Возвращаемое значение:

Указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html) | \- если объект задан,  
---|---  
NULL | \- если объект не задан.  
  
Примечание:

Тип возвращаемого объекта - вершина o3d_vertex.

Подразделы:

(отсутствуют)
