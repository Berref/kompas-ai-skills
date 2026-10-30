# Precision - Точность сравнения

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyList ](ipropertylist.html) > [IPropertyList - свойства ](ipropertylist_props.html) |  Scroll [ [ [ ](ipropertylist_readonly.html "К следующему разделу")](ipropertylist_props.html "На уровень выше")](ipropertylist_minvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylist.html)

Тип данных: double.

Синтаксис Automation:

Precision = iObject.Precision | Получить свойство ([* ](1.html))  
---|---  
iObject.Precision = Precision | Установить свойство ([* ](1.html))  
Precision = iObject.GetPrecision() | Получить свойство([**](2.html))  
iObject.SetPrecision(Precision) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Precision(&Precision) | Получить свойство  
---|---  
iObject->put_Precision(Precision) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить точность сравнения значений в списке. Сравнение происходит при добавлении значения в список [IPropertyList::Add](ipropertylist_add.html).

2\. Если добавляемое значение в списке есть, то оно не добавляется при установке значения [IPropertyControl::Value](ipropertycontrol_value.html).

3\. Если устанавливается значение, которое есть в списке, оно селектируется при поиске [IPropertyList::Find](ipropertylist_find.html).

4\. Свойство работает для вещественных типов списка: ksControlListReal, ksControlListLength, ksControlListAngle.

5\. По умолчанию устанавливается точность 0.000001.

Подразделы:

(отсутствуют)
