# Value - Значение элемента

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnItem ](ispecificationcolumnitem.html) > [ISpecificationColumnItem - свойства ](ispecificationcolumnitem_props.html) |  Scroll [ [ [ ](ispecificationcolumnitem_valuetype.html "К следующему разделу")](ispecificationcolumnitem_props.html "На уровень выше")](ispecificationcolumnitem_key.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnitem.html)

Тип данных: VARIANT

Синтаксис Automation:

Value = iObject.Value | Получить свойство ([* ](1.html))  
---|---  
iObject.Value = Value | Установить свойство ([* ](1.html))  
Value = iObject.GetValue() | Получить свойство ([**](2.html))  
iObject.SetValue( Value ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Value( &Value ) | Получить свойство  
---|---  
iObject->put_Value( Value ) | Установить свойство  
  
Примечание:

Позволяет получить и установить значение элемента колонки объекта спецификации.

В зависимости от типа значения [ValueType](ispecificationcolumnitem_valuetype.html) возвращаемое значение имеет тип:

•ksValueTypeInteger - VT_I4 (long),

•ksValueTypeFloat - VT_R8 (double),

•ksValueTypeString - VT_BSTR (строка).

Подразделы:

(отсутствуют)
