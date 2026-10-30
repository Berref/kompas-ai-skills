# FilterObject - Фильтрация объектов под курсором

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksProcess3DNotify\IProcess3DNotify ](ksprocess3dnotify.html) > [ksProcess3DNotify - события ](ksprocess3dnotify_events.html) |  Scroll [ [ [ ](ksprocess3dnotify_placementchange.html "К следующему разделу")](ksprocess3dnotify_events.html "На уровень выше")](ksprocess3dnotify_executecommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dnotify.html)

Синтаксис Automation:

BOOL FilterObject( LPDISPATCH Object );

Синтаксис COM:

BOOL FilterObject( LPUNKNOWN Object );

Возвращаемое значение:

TRUE | \- если объект подходит.  
---|---  
  
Входные параметры:

Object | \- указатель на объект под курсором: при использовании автоматизации указатель IModelObject, IPart7, IBody7, IMateConstraint3D в зависимости от типа выбранного объекта, при использовании COM указатель IEntity, IPart, IBody, IMateConstraint в зависимости от типа выбранного объекта.  
---|---  
  
Подразделы:

(отсутствуют)
