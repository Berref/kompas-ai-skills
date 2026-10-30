# PLMStatusChanged - Изменение статуса в системе версионирования

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPLMObjectNotify ](ksplmobjectnotify.html) > [ksPLMObjectNotify - методы ](ksplmobjectnotify_methods.html) |  Scroll [ [ [ ](ksplmobjectnotify_events.html "К следующему разделу")](ksplmobjectnotify_methods.html "На уровень выше")](ksplmobjectnotify_plmchangechanged.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplmobjectnotify.html)

Синтаксис Automation:

BOOL PLMStatusChanged( IDispatch* Object, long newValue );

Синтаксис COM:

HRESULT PLMStatusChanged( IDispatch* Object, long newValue, BOOL * Result );

Возвращаемое значение:

| \- не используется.  
---|---  
  
Входные параметры:

Object | \- объект версионирования,  
---|---  
newValue | \- новое значение статуса из перечисления [ksPLMStatusEnum](ksplmstatusenum.html).  
  
Подразделы:

(отсутствуют)
