# GetNotifyObject - Получить объект, для которого посылается событие

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс дополнительных параметров для событий документа-модели ksDocument3DNotifyResult/IDocument3DNotifyResult ](ksdocument3dnotifyresult.html) > [ksDocument3DNotifyResult - методы ](ksdocument3dnotifyresult_methods.html) |  Scroll [ [ [ ](ksdocument3dnotifyresult_getnotifyobjecttype.html "К следующему разделу")](ksdocument3dnotifyresult_methods.html "На уровень выше")](ksdocument3dnotifyresult_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3dnotifyresult.html)

Синтаксис Automation:

LPDISPATCH GetNotifyObject();

Синтаксис COM:

IUnknown* GetNotifyObject();

Возвращаемое значение:

В зависимости от типа объекта, возвращаемого методом [GetNotifyObjectType ](ksdocument3dnotifyresult_getnotifyobjecttype.html)возвращается:

тип объекта | Интерфейс,  
---|---  
o3d_part | \- [IPart](kspart.html) или [ksPart](kspart.html),  
o3d_body | \- [IBody](ksbody.html) или [ksBody](ksbody.html),  
o3d_uknown | \- NULL.  
  
Подразделы:

(отсутствуют)
