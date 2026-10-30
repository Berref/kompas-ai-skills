# Интерфейс ISpecificationSubsections

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationsubsections_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationsectionstyles_item.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции подразделов спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[ISpecificationSubsections](ispecificationsubsections.html)

Описание:

Управляет массивом интерфейсов [ISpecificationSubsection](ispecificationsubsection.html). Группы объектов внутри разделов называются подразделами. Подразделы, как и разделы, являются компонентом стиля спецификации. Их количество, названия и порядок внутри каждого раздела формируются при настройке стиля. Если деление на подразделы не запрещено в стиле текущей спецификации, то можно изменить список подразделов в каждом ее разделе. Подразделы располагаются в разделе в порядке возрастания номеров.

Примечание:

Данный интерфейс можно получить от интерфейса настройки раздела спецификации [ISpecificationTuningSection](ispecificationtuningsection.html) с помощью свойства [ISpecificationTuningSection::Subsections](ispecificationtuningsection_subsections.html).

Подразделы:

[ISpecificationSubsections - свойства ](ispecificationsubsections_props.html)

[ISpecificationSubsections - методы ](ispecificationsubsections_methods.html)
