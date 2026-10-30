# AddVertex - Добавить вершину

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Ломаная ( Интерфейсы ksPolyLineDefinition и IPolygonalLineDefinition) ](kspolylinedefinition.html) > [IPolygonalLineDefinition - методы ](kspolylinedefinition_methods.html) |  Scroll [ [ [ ](kspolylinedefinition_deletevertex.html "К следующему разделу")](kspolylinedefinition_methods.html "На уровень выше")](kspolylinedefinition_addpointwithparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinedefinition.html)

Синтаксис Automation:

BOOL AddVertex (double x,

double y,

double z,

double radius);

Синтаксис COM:

BOOL AddVertex (double x,

double y,

double z,

double radius);

Входные параметры:

X | \- x координата вершины,  
---|---  
Y | \- y координата вершины,  
Z | \- z координата вершины,  
Radius | \- радиус скругления в вершине.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
