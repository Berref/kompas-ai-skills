# LocalFragmentEdit - Редактирование локального фрагмента

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейсы событий графического документа ksDocument2DNotify/ IDocument2DNotify ](ksdocument2dnotify.html) > [IDocument2DNotify - события ](ksdocument2dnotify_events.html) |  Scroll [ [ [ ](ksdocument2dnotify_rebuild.html "К следующему разделу")](ksdocument2dnotify_events.html "На уровень выше")](ksdocument2dnotify_choiceproperty.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2dnotify.html)

Синтаксис Automation:

BOOL LocalFragmentEdit (LPDISPATCH newDoc, BOOL newFrw);

Синтаксис COM:

BOOL LocalFragmentEdit (long newDoc, BOOL newFrw);

Входные параметры:

newDoc | \- указатель на интерфейс документа, в котором создаётся локальный фрагмент,  
---|---  
newFrw | \- TRUE - при создании нового фрагмента, \- FALSE – при редактировании.  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс метода задан в [перечислении событий графического документа..](ksdocument2dnotifyenum.html).

Подразделы:

(отсутствуют)
