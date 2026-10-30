# SetObjectsFilter3D - Способ фильтрации 3D объектов в процессе

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - методы ](ksrequestinfo3d_methods.html) |  Scroll [ [ [ ](ksrequestinfo3d_setprocessinggroupobjectscallback.html "К следующему разделу")](ksrequestinfo3d_methods.html "На уровень выше")](irequestinfo_setmenuid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Синтаксис Automation:

BOOL SetObjectsFilter3D( long filterType, BOOL newVal);

Синтаксис COM:

BOOL SetObjectsFilter3D( long filterType, BOOL newVal);

Входные параметры:

filterType | \- тип объектов для фильтрации в процессе из перечисления [ksProcessObjectsFilter3DEnum](ksprocessobjectsfilter3denum.html),  
---|---  
newVal | \- признак фильтрации.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
