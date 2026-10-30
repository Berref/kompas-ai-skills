# Интерфейс ksDrawingObjectNotify/IDrawingObjectNotify

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) |  Scroll [ [ [ ](bo1866135.html "К следующему разделу")](sobutiy.html "На уровень выше")](ksdocumentframenotify_showocxtree.html "К предыдущему разделу")  
---|---  
  
ksDrawingObjectNotify | \- интерфейс Automation  
---|---  
  
Интерфейс событий для графического объекта.

Позволяет контролировать состояние объектов графического документа.

В Automation источником событий для подписки на данный интерфейс являются объекты [IDrawingObject](idrawingobject.html) \- базового интерфейса для графических объектов (события генерируются только для этого объекта) или коллекции объектов 2D [IDrawingObjects](idrawingobjects.html) (события генерируются для всех объектов данной коллекции).

Для получения указателей на документ и объект можно использовать свойство [IKompasAPIObject::Reference](ikompasapiobject_reference.html).

В API5 аналогом является интерфейс событий объектов графических документов [ksObject2DNotify](ksobject2dnotify.html), поэтому перечисления событий совпадают с перечислением событий для объектов графических документов [KsObject2DNotifyEnum](ksobject2dnotifyenum.html).

В процессе обработки события можно получить дополнительную информацию о редактировании объекта при помощи интерфейса [ksObject2DNotifyResult](ksobject2dnotifyresult.html), который можно получить при помощи метода [IKompasDocument2D::GetDrawingObjectNotifyResult](ikompasdocument2d_getdrawingobjectnotifyresult.html).

Подразделы:

[ksDrawingObjectNotify - события ](bo1866135.html)
