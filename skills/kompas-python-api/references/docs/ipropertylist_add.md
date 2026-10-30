# Add - Добавить значение в список

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyList ](ipropertylist.html) > [IPropertyList - методы ](ipropertylist_methods.html) |  Scroll [ [ [ ](ipropertylist_clearlist.html "К следующему разделу")](ipropertylist_methods.html "На уровень выше")](ipropertylist_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylist.html)

Синтаксис Automation:

void Add (const VARIANT& newVal);

Синтаксис COM:

HRESULT Add ([in]VARIANT newVal);

Входные параметры:

newVal | \- новое значение в раскрывающемся списке.  
---|---  
  
Примечание:

1\. Тип данных нового значения определяется типом элемента управления из перечисления [ControlTypeEnum](controltypeenum.html):

•для типа ksControlListInt используется тип long,

•для типа ksControlListReal используется тип double,

•для типа ksControlListStr ограничения на значение не накладываются,

•для типа ksControlListLength используется тип double,

•для типа ksControlListAngle используется тип double.

2\. В список можно добавить только уникальные значения. Если в списке уже есть значение, которое пытаются добавить повторно, то оно не будет добавлено.

3\. В список можно сразу передать массив значений. [Пример...](ipropertylist_add_example.html)

4\. См. также: [IPropertyControl::Value](ipropertycontrol_value.html) \- Значение элемента управления.

Подразделы:

(отсутствуют)
