# Hidden - Oбъект скрыт/показан

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksObject3DNotify/IObject3DNotify ](ksobject3dnotify.html) > [ksObject3DNotify - события ](ksobject3dnotify_events.html) |  Scroll [ [ [ ](ksobject3dnotify_loadstatechange.html "К следующему разделу")](ksobject3dnotify_events.html "На уровень выше")](ksobject3dnotify_excluded.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject3dnotify.html)

Синтаксис Automation:

BOOL Hidden (LPDISPATCH obj, BOOL _hidden);

Синтаксис COM:

BOOL Hidden (LPUNKNOWN obj, BOOL _hidden);

Входные параметры:

Obj | \- указатель на интерфейс [ksFeature](ksfeature.html) ([IFeature](ksfeature.html)) либо [ksFeatureCollection](ksfeaturecollection.html) ([IFeatureCollection](ksfeaturecollection.html)),  
---|---  
_hidden | TRUE - объект скрыт FALSE - объект показан.  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс метода задан в [перечислении событий объектов документов-моделей...](ksobject3dnotifyenum.html)

Подразделы:

(отсутствуют)
