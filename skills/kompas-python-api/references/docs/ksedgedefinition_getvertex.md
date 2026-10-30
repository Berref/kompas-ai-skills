# GetVertex - Получить указатель на интерфейс вершин: начальной и конечной

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Ребро (Интерфейсы ksEdgeDefinition, IEdgeDefinition) ](ksedgedefinition.html) > [IEdgeDefinition - методы ](ksedgedefinition_methods.html) |  Scroll [ [ [ ](ksedgedefinition_isstraight.html "К следующему разделу")](ksedgedefinition_methods.html "На уровень выше")](ksedgedefinition_getownerentity.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksedgedefinition.html)

Синтаксис Automation:

LPDISPATCH GetVertex (BOOL start);

Синтаксис COM:

LPVERTEXDEFINITION GetVertex (BOOL start);

Входные параметры:

start | \- TRUE - начальная вершина, \- FALSE - конечная вершина.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksVertexDefinition](ksvertexdefinition.html) или [IVertexDefinition](ksvertexdefinition.html).  
---|---  
  
Подразделы:

(отсутствуют)
