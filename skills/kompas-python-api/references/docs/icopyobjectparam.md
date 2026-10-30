# Интерфейс ICopyObjectParam

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) |  Scroll [ [ [ ](icopyobjectparam_props.html "К следующему разделу")](bb2370796.html "На уровень выше")](itoleranceparam_vertical.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров копирования объектов.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[ICopyObjectParam](icopyobjectparam.html)

[ICurveCopyObjectParam](icurvecopyobjectparam.html)

[ICopyObjectParam1](icopyobjectparam1.html)

Описание:

Интерфейс позволяет задавать и получать параметры копирования объектов.

Примечание:

1\. Данный интерфейс можно получить с помощью метода [IKompasDocument1::GetInterface](ikompasdocument1_getinterface.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительные интерфейсы [ICurveCopyObjectParam](icurvecopyobjectparam.html) и [ICopyObjectParam1](icopyobjectparam1.html).

Подразделы:

[ICopyObjectParam - свойства ](icopyobjectparam_props.html)
