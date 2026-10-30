# GetRequestInfo - Получить указатель интерфейса параметров запроса к системе ksRequestInfo3D

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_getrollbackfeature.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_getpart.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH GetRequestInfo (LPDISPATCH part);

Синтаксис COM:

LPREQUESTINFO GetRequestInfo (LPPART part);

Входной параметр:

part | \- указатель на интерфейс компонента (детали или подсборки) [ksPart](kspart.html) или [IPart](kspart.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс параметров запроса к системе [ksRequestInfo3D](ksrequestinfo3d.html) или [IRequestInfo](ksrequestinfo3d.html).  
---|---  
  
См. также интерфейс параметров запроса к системе [ksRequestInfo3D](ksrequestinfo3d.html)

Подразделы:

(отсутствуют)
