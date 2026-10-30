# IsNurbsSurface - Определить, является ли поверхность NURBS

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_isplane.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_iscylinder.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

BOOL IsNurbsSurface();

Синтаксис COM:

BOOL IsNurbsSurface();

Возвращаемое значение:

TRUE | \- поверхность является NURBS,  
---|---  
FALSE | \- поверхность не является NURBS.  
  
Примечание:

Данный метод удобно использовать для приведения базового интерфейса (IUnknown в COM и IDispatch в Automation) к конечному интерфейсу трехмерных объектов. Зная тип объекта, можно привести его к соответствующему интерфейсу. Метод [GetCurveParam](kscurve3d_getcurveparam.html) вернет указатель на интерфейс параметра NURBS [ksNurbsSurfaceParam](ksnurbssurfaceparam.html) или [INurbsSurfaceParam](ksnurbssurfaceparam.html).

Подразделы:

(отсутствуют)
