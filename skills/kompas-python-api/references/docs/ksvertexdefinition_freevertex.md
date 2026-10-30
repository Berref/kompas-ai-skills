# freeVertex - Является ли вершина свободной

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Описание вершины (Интерфейсы ksVertexDefinition,IVertexDefinition) ](ksvertexdefinition.html) > [IVertexDefinition - свойства ](ksvertexdefinition_props.html) |  Scroll [ [ [ ](ksvertexdefinition_methods.html "К следующему разделу")](ksvertexdefinition_props.html "На уровень выше")](ksvertexdefinition_topologyvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksvertexdefinition.html)

Тип данных: BOOL

Синтаксис Automation:

freeVertex = iVertexDefinition.freeVertex | Получить свойство ([* ](1.html))  
---|---  
freeVertex = iVertexDefinition.GetFreeVertex() | Получить свойство ([**](2.html))  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Вершина является свободной, если не принадлежит ребру и не принадлежит элементам эскиза (дуги, отрезки, кривые).

Подразделы:

(отсутствуют)
