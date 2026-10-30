# SelectItem - Элемент списка выделен

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyManagerNotify/IPropertyManagerNotify ](kspropertymanagernotify.html) > [ksPropertyManagerNotify, IPropertyManagerNotify - события ](propertymanagernotify.html) |  Scroll [ [ [ ](kspropertymanagernotify_checkitem.html "К следующему разделу")](propertymanagernotify.html "На уровень выше")](kspropertymanagernotify_processdeactivate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](propertymanagernotify.html)

Синтаксис Automation:

BOOL SelectItem (LPUNKNOWN Control, long Index, BOOL Select);

Синтаксис COM:

BOOL SelectItem (LPUNKNOWN Control, long Index, BOOL Select);

Входные параметры:

Control | \- указатель на указатель на интерфейс элемента Панели свойств [IPropertyControl](ipropertycontrol.html),  
---|---  
Index | \- индекс строки в раскрывающемся списке,  
Select | \- тип объекта: TRUE - комментарий, системная клавиша, FALSE - базовый объект.  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий Панели свойств [ksPropertyManagerNotifyEnum](kspropertymanagernotifyenum.html).

Подразделы:

(отсутствуют)
