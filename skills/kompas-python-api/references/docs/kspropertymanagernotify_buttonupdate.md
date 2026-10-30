# ButtonUpdate - Задано состояние кнопки спецпанели

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyManagerNotify/IPropertyManagerNotify ](kspropertymanagernotify.html) > [ksPropertyManagerNotify, IPropertyManagerNotify - события ](propertymanagernotify.html) |  Scroll [ [ [ ](kspropertymanagernotify_changecontrolvalue.html "К следующему разделу")](propertymanagernotify.html "На уровень выше")](kspropertymanagernotify_buttonclick.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](propertymanagernotify.html)

Синтаксис Automation:

BOOL ButtonUpdate (long buttonID, long *check, BOOL * enable);

Синтаксис COM:

BOOL ButtonUpdate (long buttonID, long *check, boolean * enable);

Входные параметры:

buttonID | \- идентификатор кнопки,  
---|---  
check | \- состояние кнопки (нажата/отжата),  
enable | \- доступность кнопки (доступна/недоступна).  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий Панели свойств [ksPropertyManagerNotifyEnum](kspropertymanagernotifyenum.html).

Подразделы:

(отсутствуют)
