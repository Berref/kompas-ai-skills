# Интерфейс ISpecificationColumnItems

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationcolumnitems_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationbaseobjects_getspecificationobjectsforgeom.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции элементов колонки объекта спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[ISpecificationColumnItems](ispecificationcolumnitems.html)

Описание:

Количество элементов колонки зависит от типа колонки.

Колонки типа Целое, Вещественное или Строка имеют только один элемент соответствующего типа.

Колонка типа запись (ksValueTypeRecord см. [ISpecificationColumn::ValueType](ispecificationcolumn_valuetype.html)) может иметь более одного элемента.

Если базовый объект спецификации создан на основе атрибута, то количество элементов в колонке будет равно количеству колонок атрибута. Если объекту не указан тип атрибута, то в колонке типа запись будет один элемент с типом значения - строка.

Примечание:

1\. Управляет массивом интерфейсов [ISpecificationColumnItem](ispecificationcolumnitem.html).

2\. Данный интерфейс можно получить от интерфейса колонки объекта спецификации [ISpecificationColumn](ispecificationcolumn.html) с помощью свойства [ISpecificationColumn::ColumnItems](ispecificationcolumn_columnitems.html).

Подразделы:

[ISpecificationColumnItems - свойства ](ispecificationcolumnitems_props.html)
