# Средняя плоскость (Интерфейсы ksPlaneMiddleDefinition, IPlaneMiddleDefinition)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) |  Scroll [ [ [ ](ksplanemiddledefinition_props.html "К следующему разделу")](int_geometry.html "На уровень выше")](ksplaneedgepointdefinition_setpoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров конструктивной плоскости "Средняя плоскость".

ksPlaneMiddleDefinition | \- интерфейс Automation  
---|---  
IPlaneMiddleDefinition | \- интерфейс COM  
  
Описание::

Плоскость проходит через биссектрису для двух плоских или прямолинейных объектов. Может быть построена для двух прямолинейных или плоских объектов типа Ребро, Конструктивная ось, Грань (плоская), Конструктивная плоскость.

Примечание:

Данный интерфейс можно получить, используя метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html).

Подразделы:

[IPlaneMiddleDefinition - свойства ](ksplanemiddledefinition_props.html)

[IPlaneMiddleDefinition - методы ](ksplanemiddledefinition_methods.html)
