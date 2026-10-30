# BeginLoadStateChange - Начало изменения типа загрузки

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksObject3DNotify/IObject3DNotify ](ksobject3dnotify.html) > [ksObject3DNotify - события ](ksobject3dnotify_events.html) |  Scroll [ [ [ ](ksobject3dnotify_beginplacementchanged.html "К следующему разделу")](ksobject3dnotify_events.html "На уровень выше")](ksobject3dnotify_begindelete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject3dnotify.html)

Синтаксис Automation:

BOOL BeginLoadStateChange( LPDISPATCH obj, long loadState );

Синтаксис COM:

BOOL BeginLoadStateChange( IUnknown* obj, long loadState );

Входные параметры:

obj | \- объект-вставка модели, для которой изменяется вариант загрузки,  
---|---  
index | \- индекс стандартного или пользовательского набора загрузки.  
  
Возвращаемое значение:

TRUE | \- запретить переключение,  
---|---  
FALSE | \- разрешить переключение.  
  
Примечание

У сборки есть умолчательные стандартные наборы, индексы которых соответствуют перечислению [ksLoadStateEnum](ksloadstateenum.html). Кроме этого могут быть еще и пользовательские наборы

Подразделы:

(отсутствуют)
