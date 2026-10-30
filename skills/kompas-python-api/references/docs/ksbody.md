# Трехмерное тело (Интерфейсы ksBody, Body)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) |  Scroll [ [ [ ](ksbody_props.html "К следующему разделу")](ksbodycollection.html "На уровень выше")](ksbodycollection_setbyindex.html "К предыдущему разделу")  
---|---  
  
Интерфейс трехмерного тела.

ksBody | \- интерфейс Automation  
---|---  
IBody | \- интерфейс COM  
  
Примечание:

1\. Твердое тело состоит из массива граней.

2\. Данный интерфейс может быть получен от интерфейса коллекции тел [ksBodyCollection](ksbodycollection.html), [IBodyCollection](ksbodycollection.html) или от интерфейса компонента [ksPart](kspart.html), [IPart](kspart.html) с помощью метода [ksPart::GetMainBody](kspart_getmainbody.html), [IPart::GetMainBody](kspart_getmainbody.html).

Подразделы:

[IBody - свойства ](ksbody_props.html)

[IBody - методы ](ksbody_methods.html)
