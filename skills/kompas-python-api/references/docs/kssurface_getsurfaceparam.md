# GetSurfaceParam - Получить параметры плоскости, конуса, цилиндра, тора, сферы, NURBS или NULL

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_gettangentvectoru.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

LPDISPATCH GetSurfaceParam();

Синтаксис COM:

LPDISPATCH GetSurfaceParam();

Возвращаемое значение:

| \- указатель на интерфейс параметра поверхности.  
---|---  
  
Примечание:

В соответствии с типом объекта метод вернет указатель на интерфейс параметра:

\- плоскости | [ksPlaneParam](ksplaneparam.html) или [IPlaneParam](ksplaneparam.html),  
---|---  
\- конуса | [ksConeParam](ksconeparam.html) или [IConeParam](ksconeparam.html),  
\- цилиндра | [ksCylinderParam](kscylinderparam.html) или [ICylinderParam](kscylinderparam.html),  
\- тора | [ksTorusParam](kstorusparam.html) или [ITorusParam](kstorusparam.html),  
\- сферы | [ksSphereParam](kssphereparam.html) или [ISphereParam](kssphereparam.html),  
\- NURBS- поверхности | [ksNurbsSurfaceParam](ksnurbssurfaceparam.html) или [INurbsSurfaceParam](ksnurbssurfaceparam.html).  
  
Зная тип объекта, можно базовый интерфейс привести к конечному (IDispatch или IUnknown). Для определения типа объекта можно воспользоваться методами [IsPlane](kssurface_isplane.html),

[IsCone](kssurface_iscone.html), [IsCylinder](kssurface_iscylinder.html), [IsTorus](kssurface_istorus.html), [IsSphere](kssurface_issphere.html), [IsNurbsSurface](kssurface_isnurbssurface.html).

Подразделы:

(отсутствуют)
