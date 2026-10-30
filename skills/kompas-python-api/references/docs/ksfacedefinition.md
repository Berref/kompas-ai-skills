# Грань (Интерфейсы ksFaceDefinition, IFaceDefinition)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) |  Scroll [ [ [ ](ksfacedefinition_props.html "К следующему разделу")](int_additional.html "На уровень выше")](ksfacecollection_refresh.html "К предыдущему разделу")  
---|---  
  
Интерфейс свойств грани.

ksFaceDefinition | \- интерфейс Automation  
---|---  
IFaceDefinition | \- интерфейс COM  
  
Описание:

Грань - это объект топологии. Содержит информацию о геометрии (поверхность), информацию о связях с другими гранями (массив циклов) и признакj относительной ориентации нормали. Этот признак имеет значение TRUE, если он совпадает с направлением нормали математической поверхности.

Примечание:

Данный интерфейс может быть получен следующими способами:

•от интерфейса коллекции свойств грани [ksFaceCollection](ksfacecollection.html), [IFaceCollection](ksfacecollection.html),

•от интерфейса свойств ребра [ksEdgeDefinition](ksedgedefinition.html), [IEdgeDefinition](ksedgedefinition.html).

•используя метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html).

Подразделы:

[IFaceDefinition - свойства ](ksfacedefinition_props.html)

[IFaceDefinition - методы ](ksfacedefinition_methods.html)
