# MaxValue - Максимальное значение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyEdit ](ipropertyedit.html) > [IPropertyEdit - свойства ](ipropertyedit_props.html) |  Scroll [ [ [ ](ipropertyedit_minvalue.html "К следующему разделу")](ipropertyedit_props.html "На уровень выше")](ipropertyedit_step.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyedit.html)

Тип данных: VARIANT

Синтаксис Automation:

MaxValue = iObject.MaxValue | Получить свойство ([* ](1.html))  
---|---  
MaxValue = iObject.GetMaxValue() | Получить свойство([**](2.html))  
  
Синтаксис COM:

iObject->get_MaxValue (&MaxValue) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Тип данных определяется типом элемента управления из перечисления [ControlTypeEnum](controltypeenum.html):

•для типа ksControlListInt используется тип long,

•для типа ksControlListReal используется тип double,

•для типа ksControlEditStr ограничения на значение не накладываются,

•для типа ksControlEditAngle используется тип double,

•для типа ksControlEditLength используется тип double,

•для типа ksControlEditPoint используется тип VT_ARRAY | VT_R8 - на 2 значения координат.

Подразделы:

(отсутствуют)
