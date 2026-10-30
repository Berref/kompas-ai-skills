# ValueType - Тип значения колонки

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumn ](ispecificationcolumn.html) > [ISpecificationColumn - свойства ](ispecificationcolumn_props.html) |  Scroll [ [ [ ](ispecificationcolumnitem.html "К следующему разделу")](ispecificationcolumn_props.html "На уровень выше")](ispecificationcolumn_text.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumn.html)

Тип данных: из перечисления [ksValueTypeEnum](ksvaluetypeenum.html)

Синтаксис Automation:

ValueType = iObject.ValueType | Получить свойство ([* ](1.html))  
---|---  
ValueType = iObject.GetValueType() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ValueType( &ValueType ) | Получить свойство  
---|---  
  
Значение свойства:

ksValueTypeInteger | \- Колонка содержит целое со знаком и состоит из одного элемента,  
---|---  
ksValueTypeFloat | \- Колонка содержит вещественное число и состоит из одного элемента,  
ksValueTypeString | \- Колонка содержит строку длиной 255 символов и состоит из одного элемента,  
ksValueTypeRecord | \- Колонка содержит запись, количество элементов в колонке определяется типом атрибута.  
  
Примечание:

1\. Тип ksValueTypeRecord доступен только для базовых объектов спецификации, и может быть только одна колонка данного типа. Тип атрибута для такой колонки определяется при создании базового объекта (см. AttributeNumber, [ISpecificationBaseObject::AttributeNumber](ispecificationbaseobject_attributenumber.html) и [ISpecificationBaseObjects::Add](ispecificationbaseobjects_add.html)). Если тип атрибута 0 или объект не является базовым объектом спецификации, то данная колонка используется аналогично колонкам с типом значения ksValueTypeString.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
