# Add - Создает новый объект «кривая пересечения поверхностей» и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISurfacesIntersectionCurves ](isurfacesintersectioncurves.html) > [ISurfacesIntersectionCurves - методы ](isurfacesintersectioncurves_methods.html) |  Scroll [ [ [ ](ispirals3d.html "К следующему разделу")](isurfacesintersectioncurves_methods.html "На уровень выше")](isurfacesintersectioncurves_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isurfacesintersectioncurves.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ISurfacesIntersectionCurve **Object );

Возвращаемое значение:

| \- Указатель на интерфейс кривой пересечения поверхностей [ISurfacesIntersectionCurve.](isurfacesintersectioncurve.html)  
---|---  
  
После добавления объекта требуется задать параметры и вызвать метод [IModelObject::Update](imodelobject_update.html)

Подразделы:

(отсутствуют)
