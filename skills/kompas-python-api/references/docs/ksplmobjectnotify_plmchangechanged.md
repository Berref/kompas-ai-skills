# PLMChangeChanged - Изменение признака отличия

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPLMObjectNotify ](ksplmobjectnotify.html) > [ksPLMObjectNotify - методы ](ksplmobjectnotify_methods.html) |  Scroll [ [ [ ](ksplmobjectnotify_plmstatuschanged.html "К следующему разделу")](ksplmobjectnotify_methods.html "На уровень выше")](ksplmobjectnotify_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplmobjectnotify.html)

Синтаксис Automation:

BOOL PLMChangeChanged( IDispatch* Object, long newValue );

Синтаксис COM:

HRESULT PLMChangeChanged( IDispatch* Object, long newValue, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

Object | \- объект версионирования,  
---|---  
newValue | \- новое значение признака отличия из перечисления [ksPLMChangesEnum.](ksplmchangesenum.html)  
  
Подразделы:

(отсутствуют)
