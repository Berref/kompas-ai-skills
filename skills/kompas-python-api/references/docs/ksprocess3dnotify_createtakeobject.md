# CreateTakeObject - Создание объекта в подпроцессе

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksProcess3DNotify\IProcess3DNotify ](ksprocess3dnotify.html) > [ksProcess3DNotify - события ](ksprocess3dnotify_events.html) |  Scroll [ [ [ ](ksprocess3dnotify_deactivate.html "К следующему разделу")](ksprocess3dnotify_events.html "На уровень выше")](ksprocess3dnotify_activate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dnotify.html)

Синтаксис Automation:

BOOL CreateTakeObject( LPDISPATCH Object );

Синтаксис COM:

BOOL CreateTakeObject( LPUNKNOWN Object );

Возвращаемое значение:

TRUE | \- если объект подходит.  
---|---  
  
Входные параметры:

Object | \- указатель на на созданный объект при использовании автоматизации указатель IModelObject, IMateConstraint3D в зависимости от типа подпроцесса, при использовании COM указатель IEntity, IMateConstraint в зависимости от типа подпроцесса.  
---|---  
  
Подразделы:

(отсутствуют)
