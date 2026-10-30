# CurveIntersection - Рассчитать пересечения с кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [Трехмерное тело (Интерфейсы ksBody, Body) ](ksbody.html) > [IBody - методы ](ksbody_methods.html) |  Scroll [ [ [ ](ksbody_facecollection.html "К следующему разделу")](ksbody_methods.html "На уровень выше")](ksbody_checkintersectionwithbody.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbody.html)

Automation:

BOOL CurveIntersection (LPDISPATCH curve,

LPDISPATCH fases,

LPDISPATCH points);

Синтаксис COM:

BOOL CurveIntersection (LPCURVE3D curve,

LPFACECOLLECTION faces,

LPCOORDINATE3DCOLLECTION points);

Входные параметры:

curve | \- Указатель на интерфейс 3D кривой [ksCurve3D.](kscurve3d.html)  
---|---  
  
Выходные параметры:

faces | \- Коллекция граней пересекаемых кривой [ksFaceCollection,](ksfacecollection.html)  
---|---  
points | \- Коллекция координат точек пересечений [ksCoordinate3dCollection.](kscoordinate3dcollection.html)  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Координаты точек сортируются по параметру кривой t.

2\. Параметры faсes, points являются необязательными.

3\. Заполняются только присланные коллекции.

4\. Интерфейсы коллекций для заполнения нужно получить с помощью функций:

•[ksFaceCollection](ksfacecollection.html), [ksD ocument3D::GetInterface](ksdocument3d_getinterface.html) с параметром o3dType = o3d_faceCollection;

•[ksCoordinate3dCollection](kscoordinate3dcollection.html), [ksDocument3D::GetInterface](ksdocument3d_getinterface.html) с параметром o3dType = o3d_coordinate3dCollection.

Подразделы:

(отсутствуют)
