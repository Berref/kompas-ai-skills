# ButtonClick - Нажата кнопка спецпанели

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyManagerNotify/IPropertyManagerNotify ](kspropertymanagernotify.html) > [ksPropertyManagerNotify, IPropertyManagerNotify - события ](propertymanagernotify.html) |  Scroll [ [ [ ](kspropertymanagernotify_buttonupdate.html "К следующему разделу")](propertymanagernotify.html "На уровень выше")](propertymanagernotify.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](propertymanagernotify.html)

Синтаксис Automation:

BOOL ButtonClick( long buttonID );

Синтаксис COM:

BOOL ButtonClick( long buttonID );

Входные параметры:

buttonID | \- идентификатор нажатой кнопки.  
---|---  
  
Возвращаемое значение:

Для кнопки Справка (pbHelp) | \- TRUE - выводить стандартную справку КОМПАС, \- FALSE - справку не выводить.  
---|---  
Для остальных | \- не используется.  
  
Примечание:

Индекс события задан в перечислении событий Панели свойств [ksPropertyManagerNotifyEnum](kspropertymanagernotifyenum.html).

Подразделы:

(отсутствуют)
