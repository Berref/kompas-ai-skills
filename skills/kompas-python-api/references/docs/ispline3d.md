# Интерфейс ISpline3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) |  Scroll [ [ [ ](ispline3d_props.html "К следующему разделу")](imodelobjects_props.html "На уровень выше")](imultispline3d_removeobjects.html "К предыдущему разделу")  
---|---  
  
Интерфейс cплайна.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[ISpline3D](ispline3d.html)

[ILocalCSObject](ilocalcsobject.html)

Примечание:

1\. Интерфейс можно получить у коллекции сплайнов, используя свойство [ISplines3D::Spline3D](isplines3d_spline3d.html) или метод [ISplines3D::Add](isplines3d_add.html).

2\. После задания параметров сплайна требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

3\. С помощью метода [IUnknown::QueryInterface](recomendation.html) у интерфейса можно получить интерфейс подчиненного объекта ЛСК [ILocalCSObject](ilocalcsobject.html).

Подразделы:

[ISpline3D - свойства ](ispline3d_props.html)

[ISpline3D - методы ](ispline3d_methods.html)
