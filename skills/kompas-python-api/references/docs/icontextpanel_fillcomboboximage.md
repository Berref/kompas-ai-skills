# FillComboBoxImage - Заполнить комбобокс иконок по идентификатору группы команд в манифесте

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с контекстной панелью и меню ](ap2038597.html) > [Интерфейс IContextPanel ](icontextpanel.html) > [IContextPanel - методы ](icontextpanel_methods.html) |  Scroll [ [ [ ](icontextpanel_fillcomboboxstyle.html "К следующему разделу")](icontextpanel_methods.html "На уровень выше")](icontextpanel_fill.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontextpanel.html)

Синтаксис Automation:

BOOL FillComboBoxImage( BSTR ComboBoxID, BSTR CommandsGroupID, VARIANT FilterCommands, long CurrentCommand );

Синтаксис COM:

HRESULT FillComboBoxImage( BSTR ComboBoxID, BSTR CommandsGroupID, VARIANT FilterCommands, long CurrentCommand, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ComboBoxID | \- строковый идентификатор комбобокса,  
---|---  
CommandsGroupID | \- строковый идентификатор группы в манифесте библиотеки,  
FilterCommands | \- фильтр команд,  
CurrentCommand | \- текущая команда.  
  
Примечание:

Если в комбобокс требуется добавить только часть команд из группы, можно задать список SafeArray VT_ARRAY | VT_I4 команд, которые требуется добавить в список.

Подразделы:

(отсутствуют)
