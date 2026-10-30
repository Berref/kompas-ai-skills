# Excluded - Oбъект исключен/включен в расчет

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksModelObjectNotify ](ksmodelobjectnotify.html) > [ksModelObjectNotify - события ](ksmodelobjectnotify_events.html) |  Scroll [ [ [ ](ksmodelobjectnotify_hidden.html "К следующему разделу")](ksmodelobjectnotify_events.html "На уровень выше")](ksmodelobjectnotify_endprocess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmodelobjectnotify.html)

Синтаксис Automation:

BOOL Excluded(VARIANT obj, VARIANT_BOOL excluded);

Входные параметры:

iObj | \- VARIANT с типом VT_DISPATCH, если событие генерируется для одного объекта, \- массив SafeArray объектов, если событие генерируется для более чем одного объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- объект исключен из расчета,  
---|---  
FALSE | \- объект включен в расчет.  
  
Примечание:

1\. Индекс события задан в перечислении событий для объектов документов-моделей [KsObject3DNotifyEnum](ksobject3dnotifyenum.html).

2\. Контейнером событий ksModelObjectNotify может использоваться объект документа-модели [IModelObject](imodelobject.html) и коллекция объектов [IModelObjects](imodelobjects.html).

Подразделы:

(отсутствуют)
