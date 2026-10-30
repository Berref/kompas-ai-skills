# Value - Значение элемента управления

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertycontrol_visible.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertycontrol_tips.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycontrol.html)

Тип данных: VARIANT

Синтаксис Automation:

Value = iObject.Value | Получить свойство ([* ](1.html))  
---|---  
iObject.Value = Value | Установить свойство ([* ](1.html))  
Value = iObject.GetValue() | Получить свойство([**](2.html))  
iObject.SetValue (Value) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Value (&Value) | Получить свойство  
---|---  
iObject->put_Value (Value) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить значение элемента управления.

2\. Тип данных определяется типом элемента управления из перечисления [СontrolTypeEnum](controltypeenum.html):

•для типа ksControlListInt используется тип long,

•для типа ksControlListReal используется тип double,

•для типа ksControlEditStr ограничения на значение не накладываются,

•для типа ksControlEditAngle используется тип double,

•для типа ksControlEditLength используется тип double,

•для типа ksControlEditPoint используется тип VT_ARRAY | VT_R8 - на 2 значения координат.

Подразделы:

(отсутствуют)
