# GetEntityCollection - Получить указатель на интерфейс массива объектов, указанных в процессе

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - методы ](ksrequestinfo3d_methods.html) |  Scroll [ [ [ ](ksrequestinfo3d_getfiltercallback.html "К следующему разделу")](ksrequestinfo3d_methods.html "На уровень выше")](irequestinfo_getdynamicfiltering.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Синтаксис Automation:

LPDISPATCH GetEntityCollection();

Синтаксис COM:

LPENTITYCOLLECTION GetEntityCollection();

Возвращаемое значение:

| \- указатель на интерфейс [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html).  
---|---  
  
Примечание:

В возвращаемом массиве контроль выключен, что позволяет добавлять в массив нулевые указатели.

Подразделы:

(отсутствуют)
