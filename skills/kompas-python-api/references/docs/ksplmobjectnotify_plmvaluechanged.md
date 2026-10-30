# PLMValueChanged - Изменение значений объектов в системе версионирования

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPLMObjectNotify ](ksplmobjectnotify.html) > [ksPLMObjectNotify - события](ksplmobjectnotify_events.html) |  Scroll [ [ [ ](ksprocess2dnotify.html "К следующему разделу")](ksplmobjectnotify_events.html "На уровень выше")](ksplmobjectnotify_plmcompositionchanged.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplmobjectnotify.html)

Синтаксис Automation:

BOOL PLMValueChanged( IDispatch* Object, long ValueId, VARIANT NewValue );

Синтаксис COM:

HRESULT PLMValueChanged( IDispatch* Object, long ValueId, VARIANT NewValue, BOOL * Result );

Возвращаемое значение:

| \- не используется.  
---|---  
  
Входные параметры:

Object | \- указатель на объект версионирования,  
---|---  
ValueId | \- идентификатор значения,  
NewValue | \- новое значение.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
