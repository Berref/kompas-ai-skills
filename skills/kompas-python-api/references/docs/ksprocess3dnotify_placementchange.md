# PlacementChange - Изменение положения

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksProcess3DNotify\IProcess3DNotify ](ksprocess3dnotify.html) > [ksProcess3DNotify - события ](ksprocess3dnotify_events.html) |  Scroll [ [ [ ](ksprocess3dnotify_run.html "К следующему разделу")](ksprocess3dnotify_events.html "На уровень выше")](ksprocess3dnotify_filterobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dnotify.html)

Синтаксис Automation:

BOOL PlacementChange( LPDISPATCH Object );

Синтаксис COM:

BOOL PlacementChange( LPUNKNOWN Object );

Возвращаемое значение:

TRUE | \- если параметры процесса изменились.  
---|---  
  
Входные параметры:

Object | \- указатель на выбранный объект: при использовании автоматизации указатель IModelObject, IPart7, IBody7 в зависимости от типа выбранного объекта, при использовании COM указатель IEntity, IPart, IBody в зависимости от типа выбранного объекта.  
---|---  
  
Подразделы:

(отсутствуют)
