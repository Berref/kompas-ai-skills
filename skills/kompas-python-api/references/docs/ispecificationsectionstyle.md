# Интерфейс ISpecificationSectionStyle

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationsectionstyle_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationobjectcreateparam_subsection.html "К предыдущему разделу")  
---|---  
  
Интерфейс стиля раздела спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ISpecificationSectionStyle](ispecificationsectionstyle.html)

Описание:

В спецификации все объекты располагаются в своем разделе, если включено разбиение на разделы [ISpecificationStyle::SectionOn](ispecificationstyle_sectionon.html). Разделы располагаются в порядке возрастания или убывания их номеров [ISpecificationSectionStyle::Number](ispecificationsectionstyle_number.html), в зависимости от значения свойства [ISpecificationStyle::SortSectionDown](ispecificationstyle_sortsectiondown.html). Раздел автоматически добавляется в спецификацию, если в нем создается базовый объект спецификации или комментарий, и автоматически удаляется из спецификации при удалении последнего объекта спецификации.

Примечание:

Данный интерфейс можно получить от интерфейса стиля раздела спецификации [ISpecificationSectionStyles](ispecificationsectionstyles.html), [ISpecificationSectionStyles::Item](ispecificationsectionstyles_item.html).

Подразделы:

[ISpecificationSectionStyle - свойства ](ispecificationsectionstyle_props.html)
