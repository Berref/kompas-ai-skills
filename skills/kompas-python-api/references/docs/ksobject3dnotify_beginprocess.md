# BeginProcess - Начало редактирования\создания объекта

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksObject3DNotify/IObject3DNotify ](ksobject3dnotify.html) > [ksObject3DNotify - события ](ksobject3dnotify_events.html) |  Scroll [ [ [ ](ksobject3dnotify_beginpropertychanged.html "К следующему разделу")](ksobject3dnotify_events.html "На уровень выше")](ksobject3dnotify_beginplacementchanged.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject3dnotify.html)

Синтаксис Automation:

BOOL BeginProcess (long pType, LPDISPATCH obj);

Синтаксис COM:

BOOL BeginProcess (long pType, LPUNKNOWN obj);

Входные параметры:

Obj | \- указатель на интерфейс [ksFeature](ksfeature.html) ([IFeature](ksfeature.html)) либо [ksFeatureCollection](ksfeaturecollection.html) ([IFeatureCollection](ksfeaturecollection.html)),  
---|---  
pType | \- [тип объекта](obj3dtype.html) (o3d_sketch, o3d_axis2Planes...o3d_lastEntityElement, o3d_part, o3d_feature).  
  
Возвращаемое значение:

TRUE | \- редактировать\создать объект,  
---|---  
FALSE | \- редактирование\создание объекта запрещено.  
  
Примечание:

Индекс метода задан в [перечислении событий объектов документов-моделей...](ksobject3dnotifyenum.html)

Подразделы:

(отсутствуют)
