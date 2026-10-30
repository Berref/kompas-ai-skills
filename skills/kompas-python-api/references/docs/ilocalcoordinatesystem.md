# Интерфейс ILocalCoordinateSystem

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_props.html "К следующему разделу")](bc2284488.html "На уровень выше")](icontrolpoint_showname.html "К предыдущему разделу")  
---|---  
  
Интерфейс локальной системы координат.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IPoint3D](ipoint3d.html)

[ILocalCoordinateSystem](ilocalcoordinatesystem.html)

[ILocalCSObject](ilocalcsobject.html)

Примечание:

1\. Интерфейс можно получить, используя свойство интерфейса коллекции ЛСК [ILocalCoordinateSystems::LocalCoordinateSystem](ilocalcoordinatesystems_localcoordinatesystem.html) или метод [ILocalCoordinateSystems::Add](ilocalcoordinatesystems_add.html).

2\. Интерфейс наследует от интерфейса 3D точки [IPoint3D](ipoint3d.html) все методы и свойства для позиционирования ЛСК.

3\. Интерфейс позволяет задавать смещение вдоль собственных осей ЛСК с помощью метода [ILocalCoordinateSystem::SetDisplacementByAxis](ilocalcoordinatesystem_setdisplacementbyaxis.html).

4\. С помощью метода [IUnknown::QueryInterface](recomendation.html) у интерфейса можно получить интерфейс подчиненного объекта ЛСК [ILocalCSObject](ilocalcsobject.html).

Подразделы:

[ILocalCoordinateSystem - свойства ](ilocalcoordinatesystem_props.html)

[ILocalCoordinateSystem - методы ](ilocalcoordinatesystem_methods.html)
