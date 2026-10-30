# IsCone - Определить, является ли поверхность конической

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_iscylinder.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_isclosedv.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

BOOL IsCone();

Синтаксис COM:

BOOL IsCone();

Возвращаемое значение:

TRUE | \- поверхность является конической,  
---|---  
FALSE | \- поверхность не является конической.  
  
Примечание:

Данный метод удобно использовать для приведения базового интерфейса (IUnknown в COM и IDispatch в Automation) к конечному интерфейсу трехмерных объектов. Зная тип объекта, можно привести его к соответствующему интерфейсу. Метод [GetSurfaceParam](kssurface_getsurfaceparam.html) вернет указатель на интерфейс параметра конуса [ksConeParam](ksconeparam.html) или [IConeParam](ksconeparam.html).

Подразделы:

(отсутствуют)
