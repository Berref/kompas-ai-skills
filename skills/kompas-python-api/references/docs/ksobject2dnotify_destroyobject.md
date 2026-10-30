# DestroyObject - Завершение удаления объекта

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объектов графических документов ksObject2DNotify/ IObject2DNotify ](ksobject2dnotify.html) > [IObject2DNotify - события ](ksobject2dnotify_events.html) |  Scroll [ [ [ ](ksobject2dnotify_endprocess.html "К следующему разделу")](ksobject2dnotify_events.html "На уровень выше")](ksobject2dnotify_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject2dnotify.html)

Синтаксис Automation:

BOOL DestroyObject (long objRef);

Синтаксис COM:

VARIANT_BOOL DestroyObject( VARIANT Objects );

Входные параметры:

objRef | \- указатель на объект или группу объектов.  
---|---  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

1\. Индекс метода задан в перечислении событий объектов графических документов [ksObject2DNotifyEnum](ksobject2dnotifyenum.html).

2\. Разрушить объекты можно см. описание [ksDocument2D::ksDestroyObjects](ksdocument2d_ksdestroyobjects.html).

Подразделы:

(отсутствуют)
