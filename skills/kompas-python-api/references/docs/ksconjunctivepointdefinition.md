# Интерфейсы объекта “Присоединительная точка”ksConjunctivePointDefinition, IConjunctivePointDefinition

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) |  Scroll [ [ [ ](ksconjunctivepointdefinition_props.html "К следующему разделу")](int_geometry.html "На уровень выше")](kscontrolpointdefinition_setvertex.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров объекта "Присоединительная точка".

ksConjunctivePointDefinition | \- интерфейс Automation  
---|---  
IConjunctivePointDefinition | \- интерфейс COM  
  
Описание::

Объект "Присоединительная точка" создается в детали (или сборке) и используется для связывания элементов между собой и с траекторией трассы. "Присоединительная точка" может указываться в качестве вершины при создании или редактировании траектории. В детали (или сборке) может находиться любое количество объектов "Присоединительная точка".

Примечание:

Данный интерфейс можно получить, используя метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html).

Подразделы:

[IConjunctivePointDefinition - свойства ](ksconjunctivepointdefinition_props.html)

[IConjunctivePointDefinition - методы ](ksconjunctivepointdefinition_methods.html)
