# DeleteProperty - Значение свойства удалено

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksDocument3DNotify/IDocument3DNotify ](ksdocument3dnotify.html) > [IDocument3DNotify - события ](ksdocument3dnotify_events.html) |  Scroll [ [ [ ](ksdocument3dnotify_rebuild.html "К следующему разделу")](ksdocument3dnotify_events.html "На уровень выше")](ksdocument3dnotify_deletematerial.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3dnotify.html)

Синтаксис Automation:

BOOL DeleteProperty(LPDISPATCH obj, double propID);

Синтаксис COM:

BOOL DeleteProperty(LPUNKNOWN obj, double propID);

Входные параметры:

obj | \- указатель на интерфейс объекта,  
---|---  
propID | \- идентификатор свойства.  
  
Возвращаемое значение:

TRUE | \- разрешить удаление материала,  
---|---  
FALSE | \- запретить удаление.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
