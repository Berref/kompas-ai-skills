# ControlCommand - Нажата кнопка элемента управления

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyManagerNotify/IPropertyManagerNotify ](kspropertymanagernotify.html) > [ksPropertyManagerNotify, IPropertyManagerNotify - события ](propertymanagernotify.html) |  Scroll [ [ [ ](kspropertymanagernotify_doubleclickitem.html "К следующему разделу")](propertymanagernotify.html "На уровень выше")](kspropertymanagernotify_commandhelp.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](propertymanagernotify.html)

Синтаксис Automation:

BOOL ControlCommand (IPropertyControl * сontrol, long buttonID);

Синтаксис COM:

BOOL ControlCommand (IUnknown* сontrol, long buttonID);

Входные параметры:

сontrol | \- указатель на интерфейс элемента панели свойств [IPropertyControl](ipropertycontrol.html),  
---|---  
buttonID | \- идентификатор нажатой кнопки.  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий Панели свойств [ksPropertyManagerNotifyEnum](kspropertymanagernotifyenum.html).

Подразделы:

(отсутствуют)
