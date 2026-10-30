# LoadCombinationChange - Завершение переключения типа загрузки

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksDocument3DNotify/IDocument3DNotify ](ksdocument3dnotify.html) > [IDocument3DNotify - события ](ksdocument3dnotify_events.html) |  Scroll [ [ [ ](ksdocument3dnotify_beginchoicematerial.html "К следующему разделу")](ksdocument3dnotify_events.html "На уровень выше")](ksdocument3dnotify_beginloadcombinationchange.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3dnotify.html)

Синтаксис Automation:

BOOL LoadCombinationChange( long index );

Синтаксис COM :

BOOL LoadCombinationChange( long index );

Входные параметры:

index | \- индекс стандартного или пользовательского набора загрузки.  
---|---  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание

У сборки есть умолчательные стандартные наборы, индексы которых соответствуют перечислению [ksLoadStateEnum](ksloadstateenum.html). Кроме этого, могут быть еще и пользовательские наборы.

Подразделы:

(отсутствуют)
