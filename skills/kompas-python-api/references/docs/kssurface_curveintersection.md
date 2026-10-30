# CurveIntersection - Рассчитать пересечения с кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_getarea.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

BOOL CurveIntersection( LPDISPATCH curve, LPDISPATCH points, BOOL extSurf, BOOL extCurve );

Синтаксис COM:

BOOL CurveIntersection( LPCURVE3D curve, LPCOORDINATE3DCOLLECTION points, BOOL extSurf, BOOL extCurve );

Входные параметры:

curve | \- указатель на интерфейс 3D кривой [ksCurve3D](kscurve3d.html),  
---|---  
extSurf | \- TRUE - учитывать продолжение поверхности, \- FALSE - не учитывать продолжение поверхности,  
extCurve | \- TRUE - учитывать продолжение кривой, \- FALSE - не учитывать продолжение кривой.  
  
Выходные параметры:

points | \- Коллекция координат точек пересечений [ksCoordinate3dCollection.](kscoordinate3dcollection.html)  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Координаты точек сортируются по параметру кривой t.

2\. Параметр points является необязательным.

3\. Заполняются только присланные коллекции.

4\. Интерфейсы коллекций координат точек [ksCoordinate3dCollection](kscoordinate3dcollection.html) нужно получить с помощью функций [ksDocument3D::GetInterface](ksdocument3d_getinterface.html) с параметром o3dType = o3d_coordinate3dCollection.

Подразделы:

(отсутствуют)
