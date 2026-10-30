# MinValue - Минимальное значение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertySpinEdit ](ipropertyspinedit.html) > [IPropertySpinEdit - свойства ](ipropertyspinedit_props.html) |  Scroll [ [ [ ](ipropertyspinedit_readonly.html "К следующему разделу")](ipropertyspinedit_props.html "На уровень выше")](ipropertyspinedit_maxvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyspinedit.html)

Тип данных: VARIANT

Синтаксис Automation:

MinValue = iObject.MinValue | Получить свойство ([* ](1.html))  
---|---  
MinValue = iObject.GetMinValue() | Получить свойство([**](2.html))  
  
Синтаксис COM:

iObject->get_MinValue (&MinValue) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Тип данных определяется типом элемента управления:

•для типа ksControlSpinInt из [ControlTypeEnum](controltypeenum.html) используется тип long,

•для типа ksControlSpinReal из ControlTypeEnum используется тип double.

Подразделы:

(отсутствуют)
