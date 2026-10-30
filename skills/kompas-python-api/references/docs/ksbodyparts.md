# Интерфейс частей тела (Интерфейсы ksBodyParts, IBodyParts)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) |  Scroll [ [ [ ](ksbodyparts_props.html "К следующему разделу")](ksentity.html "На уровень выше")](ksbody_massinertiaparam.html "К предыдущему разделу")  
---|---  
  
Интерфейс частей тела.

ksBodyParts | \- интерфейс Automation  
---|---  
IBodyParts | \- интерфейс COM  
  
Описание:

Некоторые операции в 3D позволяют создавать несколько частей результирующего тела. Интерфейс позволяет получить информацию о частях тела и управлять их включением в расчет и выключением из расчета. Желательно включить части таким образом, чтобы тело оказалось целым.

Примечание:

Данный интерфейс можно получить, используя метод интерфейса элемента модели [ksEntity::GetBodyParts](ksentity_getbodyparts.html) или [IEntity::GetBodyParts](ksentity_getbodyparts.html).

Подразделы:

[IBodyParts - свойства ](ksbodyparts_props.html)

[IBodyParts - методы ](ksbodyparts_methods.html)
