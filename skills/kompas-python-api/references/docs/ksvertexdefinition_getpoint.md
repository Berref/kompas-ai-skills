# GetPoint - Получить координаты вершины

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Описание вершины (Интерфейсы ksVertexDefinition,IVertexDefinition) ](ksvertexdefinition.html) > [IVertexDefinition - методы ](ksvertexdefinition_methods.html) |  Scroll [ [ [ ](ksedgedefinition.html "К следующему разделу")](ksvertexdefinition_methods.html "На уровень выше")](ksvertexdefinition_getownerentity.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksvertexdefinition.html)

Синтаксис Automation:

BOOL GetPoint (double *x, double *y, double *z);

Синтаксис COM:

BOOL GetPoint (double *x, double *y, double *z);

Выходные параметры:

x, y, z | \- координаты вершины.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
