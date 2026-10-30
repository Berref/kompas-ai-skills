# CurveIntersection - Рассчитать пересечения с кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_endedit.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_createoreditobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL CurveIntersection (LPDISPATCH curve,

LPDISPATCH parts,

LPDISPATCH fases,

LPDISPATCH points);

Синтаксис COM:

BOOL CurveIntersection (LPCURVE3D curve,

LPPARTCOLLECTION parts,

LPFACECOLLECTION faces,

LPCOORDINATE3DCOLLECTION points);

Входные параметры:

curve | \- Указатель на интерфейс 3D кривой [ICurve3D](kscurve3d.html)  
---|---  
  
Выходные параметры:

parts | \- коллекция деталей, пересекаемых кривой [IPartCollection](kspartcollection.html),  
---|---  
fases | \- коллекция граней, пересекаемых кривой [IFaceCollection,](ksfacecollection.html)  
points | \- коллекция координат точек пересечений [ICoordinate3dCollection.](kscoordinate3dcollection.html)  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Координаты точек сортируются по параметру кривой t.

2\. Параметры parts, faces, points являются не обязательными.

3\. Заполняются только присланные коллекции.

4\. Интерфейсы коллекций для заполнения нужно получить с помощью функций:

•[ksPartCollection](kspartcollection.html)

•[ksDocument3D::PartCollection](ksdocument3d_partcollection.html) c параметром refresh = FALSE;

•[ksFaceCollection](ksfacecollection.html)

•[ksDocument3D::GetInterface](ksdocument3d_getinterface.html) с параметром o3dType = o3d_faceCollection;

•[ksCoordinate3dCollection](kscoordinate3dcollection.html)

•[ksDocument3D::GetInterface](ksdocument3d_getinterface.html) с параметром o3dType = o3d_coordinate3dCollection.

Подразделы:

(отсутствуют)
