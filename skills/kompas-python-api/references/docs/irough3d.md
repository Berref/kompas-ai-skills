# Интерфейс IRough3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) |  Scroll [ [ [ ](irough3d_props.html "К следующему разделу")](bc2275772.html "На уровень выше")](ibaseleader3d_setposition.html "К предыдущему разделу")  
---|---  
  
Интерфейс обозначения шероховатости 3D.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IRough3D](irough3d.html)

[IRoughParams](iroughparams.html)

Примечание:

1\. Интерфейс можно получить у коллекции обозначений шероховатости 3D, используя свойство [IRoughs3D::Rough3D](iroughs3d_rough3d.html) или метод [IRoughs3D::Add](iroughs3d_add.html).

2\. После задания параметров объекта требуется вызвать метод [IModelObject_Update](imodelobject_update.html).

3\. Интерфейс [IRoughParams](iroughparams.html) является дополнительным, его можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IRough3D - свойства ](irough3d_props.html)

[IRough3D - методы ](irough3d_methods.html)
