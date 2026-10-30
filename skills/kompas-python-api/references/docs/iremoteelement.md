# Интерфейс IRemoteElement

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitMarking ](iunitmarking.html) > [IUnitMarking - свойства ](iunitmarking_props.html) |  Scroll [ [ [ ](iremoteelement_props.html "К следующему разделу")](iunitmarking_props.html "На уровень выше")](iunitmarking_yc.html "К предыдущему разделу")  
---|---  
  
Интерфейс выносного элемента.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IUnitMarking](iunitmarking.html)

[IRemoteElement](iremoteelement.html)

Описание:

Интерфейс позволяет задавать параметры выносного элемента.

Примечание:

1\. Интерфейс можно получить у коллекции выносных элементов, используя свойство [IRemoteElements::RemoteElement](iremoteelements_remoteelement.html) или метод [IRemoteElements::Add](iremoteelements_add.html).

2\. После задания параметров выносного элемента требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[IRemoteElement - свойства ](iremoteelement_props.html)
