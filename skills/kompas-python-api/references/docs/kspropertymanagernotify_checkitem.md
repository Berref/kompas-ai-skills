# CheckItem - Элемент списка выбран

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyManagerNotify/IPropertyManagerNotify ](kspropertymanagernotify.html) > [ksPropertyManagerNotify, IPropertyManagerNotify - события ](propertymanagernotify.html) |  Scroll [ [ [ ](kspropertymanagernotify_changeactivetab.html "К следующему разделу")](propertymanagernotify.html "На уровень выше")](kspropertymanagernotify_selectitem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](propertymanagernotify.html)

Синтаксис Automation:

BOOL CheckItem (LPUNKNOWN Control, long Index, BOOL Check);

Синтаксис COM:

BOOL CheckItem (LPUNKNOWN Control, long Index, BOOL Check);

Входные параметры:

Control | \- указатель на указатель на интерфейс элемента Панели свойств [IPropertyControl](ipropertycontrol.html),  
---|---  
Index | \- идентификатор кнопки,  
Select | \- тип объекта: TRUE - комментарий, системная клавиша, FALSE - базовый объект.  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий Панели свойств [ksPropertyManagerNotifyEnum](kspropertymanagernotifyenum.html).

Подразделы:

(отсутствуют)
