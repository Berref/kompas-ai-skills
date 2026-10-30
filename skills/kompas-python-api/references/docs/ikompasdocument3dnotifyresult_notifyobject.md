# NotifyObject - Тип объекта

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс IKompasDocument3DNotifyResult ](ikompasdocument3dnotifyresult.html) > [IKompasDocument3DNotifyResul - свойства ](ikompasdocument3dnotifyresult_events.html) |  Scroll [ [ [ ](ikompasdocument3dnotifyresult_requestfilestype.html "К следующему разделу")](ikompasdocument3dnotifyresult_events.html "На уровень выше")](ikompasdocument3dnotifyresult_notifyobjecttype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3dnotifyresult.html)

Тип данных: указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

NotifyObject = Object.NotifyObject | Получить свойство ([* ](1.html))  
---|---  
NotifyObject = Object.GetNotifyObject() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_NotifyObject( &NotifyObject ) | Получить свойство  
---|---  
  
Возвращаемое значение:

В зависимости от типа объекта, возвращаемого методом [NotifyObjectType](ikompasdocument3dnotifyresult_notifyobjecttype.html) возвращается:

тип объекта | Интерфейс  
---|---  
o3d_part | \- [IPart7](ipart7.html)  
o3d_body | \- [IBody7](ibody7.html)  
o3d_uknown | \- NULL  
  
Примечание.

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
