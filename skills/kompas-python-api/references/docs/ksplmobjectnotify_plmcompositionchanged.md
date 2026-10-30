# PLMCompositionChanged - Изменение состояния состава в системе версионирования

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPLMObjectNotify ](ksplmobjectnotify.html) > [ksPLMObjectNotify - события](ksplmobjectnotify_events.html) |  Scroll [ [ [ ](ksplmobjectnotify_plmvaluechanged.html "К следующему разделу")](ksplmobjectnotify_events.html "На уровень выше")](ksplmobjectnotify_events.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplmobjectnotify.html)

Синтаксис Automation:

BOOL PLMCompositionChanged( IDispatch* Object, long NewValue );

Синтаксис COM:

HRESULT PLMCompositionChanged( IDispatch* Object, long NewValue, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

Object | \- указатель на объект версионирования,  
---|---  
NewValue | \- новое значение из перечисления [ksPLMCompositionEnum](ksplmcompositionenum.html).  
  
Версия Компас v23

Подразделы:

(отсутствуют)
