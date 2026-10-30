# Интерфейс ISpecificationTuning

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationtuning_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationsubsection_delete.html "К предыдущему разделу")  
---|---  
  
Интерфейс настроек спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ISpecificationTuning](ispecificationtuning.html)

Описание:

Данный интерфейс позволяет получить доступ к настройкам стиля спецификации [ISpecificationStyle](ispecificationstyle.html) или настройкам описания спецификации [ISpecificationDescription](ispecificationdescription.html).

Если настройки взяты у стиля спецификации, то они являются умолчательными для данного стиля и изменять их нельзя. В этом случае данный интерфейс отражает содержимое настроек стиля в библиотеке стилей на момент получения и в дальнейшем не отслеживает изменений в библиотеке стилей.

Если настройки взяты у описания спецификации, то они отображают и отслеживают текущее состояние описания спецификации. Эти настройки можно изменять и они могут отличаться от умолчательных настроек стиля спецификации, по которому создано данное описание спецификации.

После изменения настроек (для того чтобы эти изменения реально отобразились в документе) необходимо вызвать метод [ISpecificationTuning::Update](ispecificationtuning_update.html).

Примечание:

Данный интерфейс можно получить от интерфейса описания спецификации документа [ISpecificationDescription](ispecificationdescription.html), используя свойство [ISpecificationDescription::SpecificationTuning](ispecificationdescription_specificationtuning.html) или от интерфейса стиля спецификации [ISpecificationStyle](ispecificationstyle.html) с помощью свойства [ISpecificationStyle::SpecificationTuning](ispecificationstyle_specificationtuning.html).

Подразделы:

[ISpecificationTuning - свойства ](ispecificationtuning_props.html)

[ISpecificationTuning - методы ](ispecificationtuning_methods.html)
