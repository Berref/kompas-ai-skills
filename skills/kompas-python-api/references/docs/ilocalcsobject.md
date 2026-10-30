# Интерфейс ILocalCSObject

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) |  Scroll [ [ [ ](ilocalcsobject_props.html "К следующему разделу")](bc1712124.html "На уровень выше")](ilocalcsorientbyobjectparam_setorientationobject.html "К предыдущему разделу")  
---|---  
  
Интерфейс подчиненного объекта ЛСК.

Иерархия:

IDispatch

[ILocalCSObject](ilocalcsobject.html)

Описание

Интерфейс является дополнительным для следующих объектов:

•[IPoint3D](ipoint3d.html) \- Точка 3D,

•[IControlPoint](icontrolpoint.html) \- Контрольная точка,

•[IConjunctivePoint](iconjunctivepoint.html) \- Присоединительная точка,

•[ILocalCoordinateSystem - ЛСК,](ilocalcoordinatesystem.html)

•[ISketch](isketch.html) \- Эскиз,

•[ITablePattern](itablepattern.html) \- Массив по таблице,

•[IMeshPointsSurface](imeshpointssurface.html) \- Поверхность по сети точек,

•[ICloudPointsSurface](icloudpointssurface.html) \- Поверхность по пласту (облаку) точек,

•[IImportedSurface](iimportedsurface.html) \- Импортированная поверхность,

•[IArc3D](iarc3d.html) \- 3D дуга,

•[IPolyLine](ipolyline.html) \- Пространственная ломаная,

•[ISpline3D](ispline3d.html) \- Сплайн,

•[IHole3D](ihole3d.html)

Данный интерфейс можно получить от интерфейсов перечисленных объектов посредством вызова метода [IUnknown::QueryInterface](recomendation.html).

Интерфейс позволяет получать и изменять параметры объектов в удобной для этого системе координат. По умолчанию используется СК компонента.

Подразделы:

[ILocalCSObject - свойства ](ilocalcsobject_props.html)
