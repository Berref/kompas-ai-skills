# BeginProcess - Начало редактирования\создания объекта

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объектов графических документов ksObject2DNotify/ IObject2DNotify ](ksobject2dnotify.html) > [IObject2DNotify - события ](ksobject2dnotify_events.html) |  Scroll [ [ [ ](ksobject2dnotify_beginpropertychanged.html "К следующему разделу")](ksobject2dnotify_events.html "На уровень выше")](ksobject2dnotify_beginmove.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject2dnotify.html)

Синтаксис Automation:

BOOL BeginProcess (long pType, long objRef);

Синтаксис COM:

BOOL BeginProcess (long pType, long objRef);

Входные параметры:

pType | \- [тип объекта](objtypes.html) (LINESEG_OBJ...AXISLINE_OBJ, VIEW_OBJ)  
---|---  
objRef | \- указатель на объект или группу объектов.  
  
Возвращаемое значение:

TRUE | \- преобразовать объект,  
---|---  
FALSE | \- преобразование объекта запрещено.  
  
Примечание:

Индекс метода задан в перечислении событий объектов графических документов [ksObject2DNotifyEnum](ksobject2dnotifyenum.html).

Подразделы:

(отсутствуют)
