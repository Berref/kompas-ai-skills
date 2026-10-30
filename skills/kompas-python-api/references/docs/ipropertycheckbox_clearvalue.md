# ClearValue - Очистить значение. Установить неопределенное состояние

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyCheckBox ](ipropertycheckbox.html) > [IPropertyCheckBox - методы ](ipropertycheckbox_methods.html) |  Scroll [ [ [ ](ipropertycheckbox_setcustombitmaps.html "К следующему разделу")](ipropertycheckbox_methods.html "На уровень выше")](ipropertycheckbox_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycheckbox.html)

Синтаксис Automation:

BOOL ClearValue();

Синтаксис COM:

HRESULT ClearValue( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Возможность установки неопределенного состояния доступна при использовании стиля [IPropertyCheckBox::VisualStyle](ipropertycheckbox_visualstyle.html) = ksCheckBoxOptional. 

Версия Компас v23

Подразделы:

(отсутствуют)
