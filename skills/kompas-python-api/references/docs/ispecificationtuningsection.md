# Интерфейс ISpecificationTuningSection

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationtuningsection_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationtuning_update.html "К предыдущему разделу")  
---|---  
  
Настройка раздела спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ISpecificationTuningSection](ispecificationtuningsection.html)

Описание:

Данный интерфейс позволяет получить доступ к настройкам раздела спецификации. Если настройки взяты у стиля спецификации, то они являются умолчательными для данного стиля и изменять их нельзя. В этом случае данный интерфейс отражает содержимое настроек стиля в библиотеке стилей на момент получения и в дальнейшем не отслеживает изменений в библиотеке стилей.

Если настройки взяты у описания спецификации, то они отображают и отслеживают текущее состояние описания спецификации. Эти настройки можно изменять и они могут отличаться от умолчательных настроек стиля спецификации, по которому создано данное описание спецификации.

После изменения настроек для того, чтобы эти изменения реально отобразились в документе, необходимо вызвать метод [ISpecificationTuning::Update](ispecificationtuning_update.html).

Примечание:

Данный интерфейс можно получить у коллекции [ISpecificationTuningSections](ispecificationtuningsections.html).

Подразделы:

[ISpecificationTuningSection - свойства ](ispecificationtuningsection_props.html)
