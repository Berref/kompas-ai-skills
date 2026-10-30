# ValueType - Тип значения элемента колонки

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnItem ](ispecificationcolumnitem.html) > [ISpecificationColumnItem - свойства ](ispecificationcolumnitem_props.html) |  Scroll [ [ [ ](ispecificationcolumnitem_visible.html "К следующему разделу")](ispecificationcolumnitem_props.html "На уровень выше")](ispecificationcolumnitem_value.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnitem.html)

Тип данных: из перечисления [ksValueTypeEnum](ksvaluetypeenum.html)

Синтаксис Automation:

ValueType = iObject.ValueType | Получить свойство ([* ](1.html))  
---|---  
ValueType = iObject.GetValueType() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ValueType( &ValueType ) | Получить свойство  
---|---  
  
Значение свойства:

ksValueTypeInteger | \- Элемент колонки содержит целое со знаком и состоит из одного элемента,  
---|---  
ksValueTypeFloat | \- Элемент колонки – вещественное число и состоит из одного элемента,  
ksValueTypeString | \- Элемент колонки – строка длиной 255 символов и состоит из одного элемента,  
ksValueTypeRecord | \- не используется.  
  
Примечание:

1\. См также [ISpecificationColumnItem::Value](ispecificationcolumnitem_value.html).

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
