# EditFocus - Установка/снятие фокуса на поле ввода

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyManagerNotify/IPropertyManagerNotify ](kspropertymanagernotify.html) > [ksPropertyManagerNotify, IPropertyManagerNotify - события ](propertymanagernotify.html) |  Scroll [ [ [ ](kspropertymanagernotify_layoutchanged.html "К следующему разделу")](propertymanagernotify.html "На уровень выше")](kspropertymanagernotify_changeactivetab.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](propertymanagernotify.html)

Синтаксис Automation:

BOOL EditFocus( IPropertyControl * Control, BOOL Set );

Синтаксис COM:

BOOL EditFocus( LPUNKNOWN ctrl, BOOL Set );

Входные параметры:

ctrl | \- указатель на интерфейс элемента управления [IPropertyContro](ipropertycontrol.html)l,  
---|---  
Set | true - фокус установлен, false - фокус снят.  
  
Возвращаемое значение:

Не используется.

Примечание:

Индекс события задан в перечислении событий Панели свойств [ksPropertyManagerNotifyEnum](kspropertymanagernotifyenum.html).

Подразделы:

(отсутствуют)
