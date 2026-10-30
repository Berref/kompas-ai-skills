# BeginProcess - Начало редактирования\создания объекта

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksModelObjectNotify ](ksmodelobjectnotify.html) > [ksModelObjectNotify - события ](ksmodelobjectnotify_events.html) |  Scroll [ [ [ ](ksmodelobjectnotify_beginpropertychanged.html "К следующему разделу")](ksmodelobjectnotify_events.html "На уровень выше")](ksmodelobjectnotify_beginplacementchanged.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmodelobjectnotify.html)

Синтаксис Automation:

BOOL BeginProcess (long pType, VARIANT Obj);

Входные параметры:

iObj | \- VARIANT с типом VT_DISPATCH, если событие генерируется для одного объекта, \- массив SafeArray объектов, если событие генерируется для более чем одного объекта,  
---|---  
pType | \- тип объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
  
Возвращаемое значение:

TRUE | \- редактировать\создать объект,  
---|---  
FALSE | \- запрещает редактирование\создание объекта объекта.  
  
Примечание:

1\. Индекс события задан в перечислении событий для объектов документов-моделей [KsObject3DNotifyEnum](ksobject3dnotifyenum.html).

2\. Контейнером событий ksModelObjectNotify может использоваться объект документа-модели [IModelObject](imodelobject.html) и коллекция объектов [IModelObjects](imodelobjects.html).

Подразделы:

(отсутствуют)
