# Массив граней (Интерфейсы ksFaceCollection, IFaceCollection)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) |  Scroll [ [ [ ](ksfacecollection_methods.html "К следующему разделу")](int_additional.html "На уровень выше")](ksedgedefinition_isplanar.html "К предыдущему разделу")  
---|---  
  
Интерфейс массива граней.

ksFaceCollection | \- интерфейс Automation  
---|---  
IFaceCollection | \- интерфейс COM  
  
Примечание:

Данный интерфейс может быть получен следующими способами:

•от интерфейса свойств грани [ksFaceDefinition](ksfacedefinition.html), [IFaceDefinition](ksfacedefinition.html) с помощью метода [ksFaceDefinition::ConnectedFaceCollection](ksfacedefinition_connectedfacecollection.html),

•от интерфейса тела [ksBody](ksbody.html), [IBody](ksbody.html) с помощью методов [ksBody::FaceCollection](ksbody_facecollection.html), [IBody::FaceCollection](ksbody_facecollection.html).

Подразделы:

[IFaceCollection - методы ](ksfacecollection_methods.html)
