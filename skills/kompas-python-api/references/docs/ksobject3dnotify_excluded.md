# Excluded - Oбъект исключен/включен в расчет

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksObject3DNotify/IObject3DNotify ](ksobject3dnotify.html) > [ksObject3DNotify - события ](ksobject3dnotify_events.html) |  Scroll [ [ [ ](ksobject3dnotify_hidden.html "К следующему разделу")](ksobject3dnotify_events.html "На уровень выше")](ksobject3dnotify_endprocess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject3dnotify.html)

Синтаксис Automation:

BOOL Excluded (LPDISPATCH obj, BOOL excluded);

Синтаксис COM:

BOOL Excluded (LPUNKNOWN obj, BOOL excluded);

Входные параметры:

Obj | \- указатель на интерфейс [ksFeature](ksfeature.html) ([IFeature](ksfeature.html)) либо [ksFeatureCollection](ksfeaturecollection.html) ([IFeatureCollection](ksfeaturecollection.html)),  
---|---  
Excluded | TRUE - исключен из расчета, FALSE - включен в расчет.  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс метода задан в [перечислении событий объектов документов-моделей...](ksobject3dnotifyenum.html)

Подразделы:

(отсутствуют)
