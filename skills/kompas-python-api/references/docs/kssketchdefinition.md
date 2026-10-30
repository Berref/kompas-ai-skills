# Эскиз (Интерфейсы ksSketchDefinition, ISketchDefinition)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) |  Scroll [ [ [ ](kssketchdefinition_props.html "К следующему разделу")](int_operation.html "На уровень выше")](ksbaseevolutiondefinition_thinparam.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров эскиза.

ksSketchDefinition | \- интерфейс Automation  
---|---  
ISketchDefinition | \- интерфейс COM  
  
Примечание:

1\. Данный интерфейс можно получить, используя метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html).

2\. На момент редактирования (до вызова метода [EndEdit)](kssketchdefinition_endedit.html), текущим документом является документ эскиза.

Подразделы:

[ISketchDefinition - свойства ](kssketchdefinition_props.html)

[ISketchDefinition - методы ](kssketchdefinition_methods.html)
