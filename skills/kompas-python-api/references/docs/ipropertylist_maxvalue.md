# MaxValue - Максимальное значение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyList ](ipropertylist.html) > [IPropertyList - свойства ](ipropertylist_props.html) |  Scroll [ [ [ ](ipropertylist_minvalue.html "К следующему разделу")](ipropertylist_props.html "На уровень выше")](ipropertylist_step.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylist.html)

Тип данных: VARIANT (long или double).

Синтаксис Automation:

MaxValue = iObject.MinValue | Получить свойство ([* ](1.html))  
---|---  
MaxValue = iObject.GetMinValue() | Получить свойство([**](2.html))  
  
Синтаксис COM:

iObject->get_MaxValue (&MaxValue) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Тип данных определяется типом элемента управления из перечисления [ControlTypeEnum](controltypeenum.html):

•для типа ksControlListInt используется тип long,

•для типа ksControlListReal используется тип double,

•для типа ksControlListStr ограничения на значение не накладываются,

•для типа ksControlListLength используется тип double,

•для типа ksControlListAngle используется тип double.

Подразделы:

(отсутствуют)
