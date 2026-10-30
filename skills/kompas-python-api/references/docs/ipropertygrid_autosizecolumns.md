# AutoSizeColumns - Авторазмер колонок

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyGrid ](ipropertygrid.html) > [IPropertyGrid - свойства ](ipropertygrid_props.html) |  Scroll [ [ [ ](ipropertygrid_cellformat.html "К следующему разделу")](ipropertygrid_props.html "На уровень выше")](ipropertygrid_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertygrid.html)

Тип данных: BOOL

Синтаксис Automation:

AutoSizeColumns = iObject.AutoSizeColumns | Получить свойство ([* ](1.html))  
---|---  
iObject.AutoSizeColumns = AutoSizeColumns | Установить свойство ([* ](1.html))  
AutoSizeColumns = iObject.GetAutoSizeColumns() | Получить свойство([**](2.html))  
iObject.SetAutoSizeColumns (AutoSizeColumns) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AutoSizeColumns (&AutoSizeColumns) | Получить свойство  
---|---  
iObject->put_AutoSizeColumns (AutoSizeColumns) | Установить свойство  
  
Значение свойства:

TRUE | \- расчет размера колонок от ширины элемента управления,  
---|---  
FALSE | \- фиксированный размер колонок.  
  
Примечание:

Ширина колонки определяется путем деления всей ширины элемента управления на количество колонок.

Подразделы:

(отсутствуют)
