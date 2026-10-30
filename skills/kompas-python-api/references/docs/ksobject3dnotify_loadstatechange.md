# LoadStateChange - Завершение изменения типа загрузки

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksObject3DNotify/IObject3DNotify ](ksobject3dnotify.html) > [ksObject3DNotify - события ](ksobject3dnotify_events.html) |  Scroll [ [ [ ](ksobject3dnotify_placementchanged.html "К следующему разделу")](ksobject3dnotify_events.html "На уровень выше")](ksobject3dnotify_hidden.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject3dnotify.html)

Синтаксис Automation:

BOOL LoadStateChange( LPDISPATCH obj, long loadState );

Синтаксис COM:

BOOL LoadStateChange( IUnknown* obj, long loadState );

Входные параметры:

index | \- индекс стандартного или пользовательского набора загрузки.  
---|---  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание

У сборки есть умолчательные стандартные наборы, индексы которых соответствуют перечислению [ksLoadStateEnum](ksloadstateenum.html). Кроме этого могут быть еще и пользовательские наборы

Подразделы:

(отсутствуют)
