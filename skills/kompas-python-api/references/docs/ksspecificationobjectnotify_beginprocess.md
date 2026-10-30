# BeginProcess - Начало редактирования\создания объекта

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksSpecificationObjectNotify ](ksspecificationobjectnotify.html) > [ksSpecificationObjectNotify - события ](ksspecificationobjectnotify_events.html) |  Scroll [ [ [ ](ksspecificationobjectnotify_cellbeginedit.html "К следующему разделу")](ksspecificationobjectnotify_events.html "На уровень выше")](ksspecificationobjectnotify_begingeomchange.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationobjectnotify.html)

Синтаксис Automation:

BOOL BeginProcess( long pType, ISpecificationObject * obj );

Входные параметры:

obj | \- указатель на интерфейс [ISpecificationObject](ispecificationobject.html) редактируемого объекта спецификации,  
---|---  
pType | \- тип объекта из перечисления [ksSpecificationObjectTypeEnum](ksspecificationobjecttypeenum.html)( SPC_BASE_OBJECT, SPC_COMMENT ).  
  
Возвращаемое значение:

TRUE | \- редактировать\создать объект,  
---|---  
FALSE | \- запрещает редактирование\создание объекта объекта.  
  
Примечание:

Индекс события задан в перечислении событий для объектов спецификации [ksSpcObjectNotifyEnum](ksspcobjectnotifyenum.html).

Подразделы:

(отсутствуют)
