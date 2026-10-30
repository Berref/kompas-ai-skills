# Интерфейс ksModelObjectNotify

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) |  Scroll [ [ [ ](ksmodelobjectnotify_events.html "К следующему разделу")](sobutiy.html "На уровень выше")](kslibrarymanagernotify_tryexecute.html "К предыдущему разделу")  
---|---  
  
Интерфейс событий для объектов документа-модели.

Описание:

Позволяют контролировать состояние объектов документа - модели.

В Automation источником событий для подписки на данный интерфейс являются объекты [IModelObject](imodelobject.html) (события генерируются только для этого объекта) или коллекции объектов 3D [IModelObjects](imodelobjects.html) (события генерируются для всех объектов данной коллекции).

В процессе обработки события можно получить дополнительную информацию о редактировании объекта при помощи интерфейса [IModelObjectNotifyResult](imodelobjectnotifyresult.html).

В API 5 аналогом является Интерфейс событий объектов документа-модели [ksObject3DNotify](ksobject3dnotify.html), поэтому перечисления событий совпадают с перечислением событий для объектов документа-модели KsObject3DNotifyEnum.

Подразделы:

[ksModelObjectNotify - события ](ksmodelobjectnotify_events.html)
