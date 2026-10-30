# Ребро (Интерфейсы ksEdgeDefinition, IEdgeDefinition)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) |  Scroll [ [ [ ](ksedgedefinition_propers.html "К следующему разделу")](int_additional.html "На уровень выше")](ksvertexdefinition_getpoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс свойств ребра.

ksEdgeDefinition | \- интерфейс Automation  
---|---  
IEdgeDefinition | \- интерфейс COM  
  
Описание:

Ребро содержит информацию о математической кривой в трехмерном пространстве, о вершинах и о присоединенных гранях. Ориентация ребра относительно грани является положительной, если грань расположена слева от него или отрицательной, если справа.

Примечание:

Данный интерфейс можно получить, используя следующие методы:

•метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html)

•методы интерфейса [ksEdgeCollection](ksedgecollection.html) или [IEdgeCollection](ksedgecollection.html).

Подразделы:

[IEdgeDefinition - свойства ](ksedgedefinition_propers.html)

[IEdgeDefinition - методы ](ksedgedefinition_methods.html)
