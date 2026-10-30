# Интерфейс событий объектов графических документов ksObject2DNotify/ IObject2DNotify

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) |  Scroll [ [ [ ](ksobject2dnotify_events.html "К следующему разделу")](eventscommon.html "На уровень выше")](ksdocument2dnotify_isnotifyprocess.html "К предыдущему разделу")  
---|---  
  
ksObject2DNotify | \- интерфейс Automation  
---|---  
IObject2DNotify | \- интерфейс COM  
  
Позволяют контролировать редактирование объектов графического документа.

В Automation источник событий для подписки [Object2DNotify](object2dnotify.html) можно получить при помощи метода [ksDocument2D::GetObject2DNotify](ksdocument2d_getobject2dnotify.html).

В СOM контейнером для подписки является указатель на графический документ.

Дополнительный параметр при подписке задает объекты, для которых предназначен данный интерфейс событий.

Таким параметром является либо [тип объекта](objtypes.html) (ALL_OBJ...AXISLINE_OBJ, VIEW_OBJ), либо указатель на объект.

Если задан тип объекта, события генерируются для всех объектов этого типа.

Если задан указатель на объект, события генерируются только для этого объекта.

Если задан тип объектов ALL_OBJ, события генерируются для всех объектов.

В процессе обработки события можно получить информацию о редактировании объекта при помощи интерфейса [IObject2DNotifyResult](ksobject2dnotifyresult.html) для COM или [ksObject2DNotifyResult](ksobject2dnotifyresult.html) для Automation.

В Automation получить интерфейс результата можно при помощи метода [ksDocument2D::GetObject2DNotifyResult](ksdocument2d_getobject2dnotifyresult.html).

В COM получить интерфейс результата можно при помощи экспортной функции [ksGetObject2DNotifyResult](ksgetobject2dnotifyresult.html).

Подразделы:

[IObject2DNotify - события ](ksobject2dnotify_events.html)

[ksObject2DNotify - методы ](ksobject2dnotify_methods.html)
