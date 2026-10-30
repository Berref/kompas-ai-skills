# Интерфейс IVector3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вектор ](bc2295802.html) |  Scroll [ [ [ ](ivector3d_props.html "К следующему разделу")](bc2295802.html "На уровень выше")](bc2295802.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров вектора 3D.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IVector3D](ivector3d.html)

Интерфейс позволяет получать параметры вектора 3D.

Интерфейс можно получить:

•у интерфейса массива по сетке с помощью свойств [ILinearPattern::Vector1](ilinearpattern_vector1.html) и [ILinearPattern::Vector2](ilinearpattern_vector2.html);

•у интерфейса локальной системы координат с помощью свойства [ILocalCoordinateSystem::Vector3D](ilocalcoordinatesystem_vector3d.html);

•у интерфейса параметров точки, заданной по смещению от опорного объекта с помощью свойства [IPoint3DParamDisplace::Vector3D](ipoint3dparamdisplace_vector3d.html);

•у интерфейса присоединительной точки с помощью свойства [IConjunctivePoint::Vector3D](iconjunctivepoint_vector3d.html);

•у интерфейса эквидистанты кривой с помощью свойства [IEquidistant3D::Vector3D](iequidistant3d_vector3d.html);

•у интерфейса операции продления поверхности с помощью свойства [IExtensionSurface::BuildingVectorParameters](iextensionsurface_buildingvectorparameters.html);

•у интерфейса линии очерка с помощью свойства [ICurveOutLine::Vector3D](icurveoutline_vector3d.html).

Подразделы:

[IVector3D - свойства ](ivector3d_props.html)
