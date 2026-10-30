# ReadOnly - Запрет редактирования таблицы

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyGrid ](ipropertygrid.html) > [IPropertyGrid - свойства ](ipropertygrid_props.html) |  Scroll [ [ [ ](ipropertygrid_methods.html "К следующему разделу")](ipropertygrid_props.html "На уровень выше")](ipropertygrid_width.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertygrid.html)

Тип данных: BOOL

Синтаксис Automation:

ReadOnly = iObject.ReadOnly | Получить свойство ([* ](1.html))  
---|---  
iObject.ReadOnly = ReadOnly | Установить свойство ([* ](1.html))  
ReadOnly = iObject.GetReadOnly() | Получить свойство([**](2.html))  
iObject.SetReadOnly (ReadOnly) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ReadOnly (&ReadOnly) | Получить свойство  
---|---  
iObject->put_ReadOnly (ReadOnly) | Установить свойство  
  
Значение свойства:

TRUE | \- редактирование ячеек запрещено,  
---|---  
FALSE | \- не реализовано.  
  
Примечание:

Временно сетка работает только в режиме Только для чтения. Редактирование ее ячеек запрещено.

Подразделы:

(отсутствуют)
