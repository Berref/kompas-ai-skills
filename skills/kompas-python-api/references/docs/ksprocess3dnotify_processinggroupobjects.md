# ProcessingGroupObjects - Обработать объекты, пришедшие из рамки

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksProcess3DNotify\IProcess3DNotify ](ksprocess3dnotify.html) > [ksProcess3DNotify - методы ](ksprocess3dnotify_methods.html) |  Scroll [ [ [ ](ksprocess3dnotify_events.html "К следующему разделу")](ksprocess3dnotify_methods.html "На уровень выше")](ksprocess3dnotify_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dnotify.html)

Синтаксис Automation:

BOOL ProcessingGroupObjects( VARIANT Objects, long selectionType );

Синтаксис COM:

HRESULT ProcessingGroupObjects( VARIANT Objects, long selectionType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Выходные параметры:

Objects | \- массив объектов,  
---|---  
selectionType | \- тип выделения.  
  
Примечание

Если процесс должен поддерживать групповое селектирование рамкой, требуется установить свойство [IProcess3D::SelectionBandMode](iprocess3d_selectionbandmode.html).

Подразделы:

(отсутствуют)
