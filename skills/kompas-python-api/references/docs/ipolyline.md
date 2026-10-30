# Интерфейс IPolyLine

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) |  Scroll [ [ [ ](ipolyline_props.html "К следующему разделу")](imodelobjects_props.html "На уровень выше")](ipointsarronsurface_destroy.html "К предыдущему разделу")  
---|---  
  
Интерфейс пространственной ломаной.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IPolyLine](ipolyline.html)

[ILocalCSObject](ilocalcsobject.html)

Примечание:

1\. Интерфейс можно получить у коллекции пространственных ломаных, используя свойство [IPolyLines::PolyLine](ipolylines_polyline.html) или метод [IPolyLines::Add](ipolylines_add.html).

2\. После задания параметров объекта требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

3\. С помощью метода [IUnknown::QueryInterface](recomendation.html) у интерфейса можно получить интерфейс подчиненного объекта ЛСК [ILocalCSObject](ilocalcsobject.html).

Подразделы:

[IPolyLine - свойства ](ipolyline_props.html)

[IPolyLine - методы ](ipolyline_methods.html)
