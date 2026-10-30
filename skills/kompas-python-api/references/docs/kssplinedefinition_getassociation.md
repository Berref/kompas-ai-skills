# GetAssociation - Получить указатель на опорную точку по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Сплайн (Интерфейсы ksSplineDefinition и ISplineDefinition) ](kssplinedefinition.html) > [ISplineDefinition - методы ](kssplinedefinition_methods.html) |  Scroll [ [ [ ](kssplinedefinition_getcountvertex.html "К следующему разделу")](kssplinedefinition_methods.html "На уровень выше")](kssplinedefinition_flush.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssplinedefinition.html)

Синтаксис Automation:

LPDISPATCH GetAssociation(long index);

Синтаксис COM:

LPENTITY GetAssociation(long index);

Входные параметры:

index | \- индекс вершины в массиве.  
---|---  
  
Возвращаемое значение:

\- указатель на интерфейс точки [ksEntity](ksentity.html) или [IEntity](ksentity.html), | \- в случае успешного завершения,  
---|---  
\- FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить опорный объект для существующей вершины с номером index пространственной кривой, если он был задан.

Подразделы:

(отсутствуют)
