# GetPointParams - Получить параметры вершины ломаной

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Ломаная ( Интерфейсы ksPolyLineDefinition и IPolygonalLineDefinition) ](kspolylinedefinition.html) > [IPolygonalLineDefinition - методы ](kspolylinedefinition_methods.html) |  Scroll [ [ [ ](kspolylinedefinition_insertvertex.html "К следующему разделу")](kspolylinedefinition_methods.html "На уровень выше")](kspolylinedefinition_getparamvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinedefinition.html)

Синтаксис Automation:

LPDISPATCH GetPointParams( int index );

Синтаксис COM:

LPPOLYGONALLINEVERTEXPARAM GetPointParams( int index );

Входные параметры:

index | \- индекс вершины.  
---|---  
  
Возвращаемое значение:

\- указатель на интерфейс параметров вершины ломаной [IPolygonalLineVertexParam](kspolylinevertexparam.html) или [ksPolyLineVertexParam](kspolylinevertexparam.html), |   
---|---  
  
Подразделы:

(отсутствуют)
