# IsCylinder - Определить, является ли поверхность цилиндрической

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_isnurbssurface.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_iscone.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

BOOL IsCylinder();

Синтаксис COM:

BOOL IsCylinder();

Возвращаемое значение:

TRUE | \- поверхность является цилиндрической,  
---|---  
FALSE | \- поверхность не является цилиндрической.  
  
Примечание:

Данный метод удобно использовать для приведения базового интерфейса (IUnknown в COM и IDispatch в Automation) к конечному интерфейсу трехмерных объектов. Зная тип объекта, можно привести его к соответствующему интерфейсу. Метод [GetSurfaceParam](kssurface_getsurfaceparam.html) вернет указатель на интерфейс параметра цилиндра [ksCylinderParam](kscylinderparam.html) или [IPlaneCylinder](kscylinderparam.html).

Подразделы:

(отсутствуют)
