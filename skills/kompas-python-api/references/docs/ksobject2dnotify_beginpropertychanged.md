# BeginPropertyChanged - Начало изменения свойств объекта

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объектов графических документов ksObject2DNotify/ IObject2DNotify ](ksobject2dnotify.html) > [IObject2DNotify - события ](ksobject2dnotify_events.html) |  Scroll [ [ [ ](ksobject2dnotify_beginrotate.html "К следующему разделу")](ksobject2dnotify_events.html "На уровень выше")](ksobject2dnotify_beginprocess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject2dnotify.html)

Синтаксис Automation:

BOOL BeginPropertyChanged( long objRef );

Синтаксис COM:

BOOL BeginPropertyChanged( long objRef );

Входной параметр:

objRef | \- указатель на объект.  
---|---  
  
Возвращаемое значение:

TRUE | \- Разрешить изменение свойств объекта,  
---|---  
FALSE | \- Запретить изменение свойств объекта.  
  
Подразделы:

(отсутствуют)
