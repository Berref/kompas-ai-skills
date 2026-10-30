# Интерфейс ISpecificationColumns

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationcolumns_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationcolumnitems_item.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции колонок объекта спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[ISpecificationColumns](ispecificationcolumns.html)

Описание:

Различаются основные и дополнительные колонки объектов спецификации. Основные колонки отображаются в таблице спецификации и выводятся на печать. Дополнительные колонки содержат сведения, дополняющие информацию, включаемую в стандартный бланк. В таблице спецификации такие колонки не видны и на печать не выводятся. Количество основных колонок может не соответствовать количеству колонок в таблице спецификации. Это вызвано наличием исполнений для групповых спецификаций.

Примечание:

1\. Управляет массивом интерфейсов [ISpecificationColumn](ispecificationcolumn.html).

2\. Интерфейс коллекции основных колонок объекта спецификации может быть получен от интерфейса [ISpecificationObject](ispecificationobject.html) с помощью свойства [ISpecificationObject::Columns](ispecificationobject_columns.html).

3\. Интерфейс коллекции дополнительных колонок может быть получен от интерфейса [ISpecificationObject](ispecificationobject.html) с помощью свойства [ISpecificationObject::AdditionalColumns](ispecificationobject_additionalcolumns.html).

Подразделы:

[ISpecificationColumns - свойства ](ispecificationcolumns_props.html)
