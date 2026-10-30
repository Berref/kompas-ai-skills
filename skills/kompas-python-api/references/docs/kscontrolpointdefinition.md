# Интерфейсы объекта “Контрольная точка” - ksControlPointDefinition, IControlPointDefinition

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) |  Scroll [ [ [ ](kscontrolpointdefinition_methods.html "К следующему разделу")](int_geometry.html "На уровень выше")](int_geometry.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров объекта "Контрольная точка"

ksControlPointDefinition | \- интерфейс Automation  
---|---  
IControlPointDefinition | \- интерфейс COM  
  
Описание:

Объект "Контрольная точка" создается в детали или сборке и используется для размещения этой детали или сборки в указанной вершине траектории трассы.

"Контрольная точка" может указываться в качестве вершины при создании или редактировании траектории.

В детали (или сборке) может находиться любое количество объектов "Контрольная точка".

Примечание:

Данный интерфейс можно получить, используя метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html).

Подразделы:

[IControlPointDefinition - методы ](kscontrolpointdefinition_methods.html)
