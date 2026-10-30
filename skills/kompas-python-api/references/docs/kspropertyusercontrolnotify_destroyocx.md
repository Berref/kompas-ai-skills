# DestroyOCX - Элемент управления OCX удален

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyUserControlNotify/IPropertyUserControlNotify ](kspropertyusercontrolnotify.html) > [ksPropertyUserControlNotify - события ](propertyusercontrolnotify_events.html) |  Scroll [ [ [ ](kscontentdialognotify.html "К следующему разделу")](propertyusercontrolnotify_events.html "На уровень выше")](kspropertyusercontrolnotify_createocx.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspropertyusercontrolnotify.html)

Синтаксис Automation:

BOOL DestroyOCX();

Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

1\. При обработке этого события библиотека должна отписаться от событий элемента управления OCX, если она на них подписывалась в событии [CreateOCX](kspropertyusercontrolnotify_createocx.html).

2\. Индекс события задан в перечислении событий пользовательского элемента управления [ksPropertyUserControlNotifyEnum](kspropertyusercontrolnotifyenum.html).

Подразделы:

(отсутствуют)
