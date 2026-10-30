# BeginCopy - Начало копирования объекта

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksSpecificationObjectNotify ](ksspecificationobjectnotify.html) > [ksSpecificationObjectNotify - события ](ksspecificationobjectnotify_events.html) |  Scroll [ [ [ ](ksspecificationobjectnotify_begindelete.html "К следующему разделу")](ksspecificationobjectnotify_events.html "На уровень выше")](ksspecificationobjectnotify_events.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationobjectnotify.html)

Синтаксис Automation:

BOOL BeginCopy( ISpecificationObject * Obj );

Синтаксис COM:

HRESULT BeginCopy( ISpecificationObject * Obj, BOOL * Result );

Возвращаемое значение:

TRUE | \- изменить геометрию объекта спецификации,  
---|---  
FALSE | \- запрещает изменение геометрии объекта спецификации.  
  
Входные параметры:

Obj | \- указатель на интерфейс [ISpecificationObject](ispecificationobject.html) копируемого объекта спецификации.  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
