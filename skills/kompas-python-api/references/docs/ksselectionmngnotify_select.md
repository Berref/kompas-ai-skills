# Select - Объект выделен

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий менеджера выделенных объектов ksSelectionMngNotify/ISelectionMngNotify ](ksselectionmngnotify.html) > [ISelectionMngNotify - события ](ksselectionmngnotify_events.html) |  Scroll [ [ [ ](ksselectionmngnotify_unselect.html "К следующему разделу")](ksselectionmngnotify_events.html "На уровень выше")](ksselectionmngnotify_events.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksselectionmngnotify.html)

Синтаксис Automation:

BOOL Select (VARIANT obj);

Синтаксис COM:

BOOL Select (VARIANT obj);

Входные параметры:

obj | \- выделенный объект.  
---|---  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

1\. Индекс метода задан в [перечислении событий менеджера выделенных объектов...](ksselectionmngnotifyenum.html).

2\. Выделенный объект для графического документа: obj.vt = VT_I4, obj.lVal - reference объекта

3\. Выделенный объект для документа-модели: obj.vt = VT_UNKNOWN, obj.punkVal - указатель на интерфейс объекта (объекты дерева - объекты, компоненты, сопряжения)

Подразделы:

(отсутствуют)
