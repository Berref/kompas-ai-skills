# AddVertexAndAssociation - Добавить вершину по опорному объекту

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Сплайн (Интерфейсы ksSplineDefinition и ISplineDefinition) ](kssplinedefinition.html) > [ISplineDefinition - методы ](kssplinedefinition_methods.html) |  Scroll [ [ [ ](kssplinedefinition_attachassociation.html "К следующему разделу")](kssplinedefinition_methods.html "На уровень выше")](kssplinedefinition_addvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssplinedefinition.html)

Синтаксис Automation:

BOOL AddVertexAndAssociation (long index, LPDISPATCH obj, double weight);

Синтаксис COM:

BOOL AddVertexAndAssociation (long index, LPENTITY obj, double weight);

Входные параметры:

index | \- индекс, с которым добавляется вершина,  
---|---  
obj | \- указатель на интерфейс точки [ksEntity](ksentity.html) или [IEntity](ksentity.html),  
weight | \- вес вершины.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет добавить в пространственную кривую новую вершину. Координаты новой вершины будут равны координатам опорного объекта obj. Вес вершины равен weight.

2\. Объект (точка) obj становится опорным.

3\. Если index = -1 или значение index превышает количество вершин, то новая вершина добавляется после последней.

Подразделы:

(отсутствуют)
