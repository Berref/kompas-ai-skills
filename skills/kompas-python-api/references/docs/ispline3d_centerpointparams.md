# CenterPointParams - Получение параметров точки центра кривизны

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_centerpointtype.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_centerpointassociationobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: Указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html).

Синтаксис Automation:

CenterPointParams = Object.CenterPointParams( PointIndex ); | Получить свойство ([* ](1.html))  
---|---  
CenterPointParams = Object.GetCenterPointParams( PointIndex ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_CenterPointParams( PointIndex, &CenterPointParams ) | Получить свойство  
---|---  
  
Входные параметры:

long PointIndex | \- индекс точки.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В зависимости от типа [ISpline3D::CenterPointType](ispline3d_centerpointtype.html), интерфейс параметров должен приводиться к одному из следующих вариантов:

•ksPDisplace - [IPoint3DParamDisplace](ipoint3dparamdisplace.html) (интерфейс параметров пространственной точки, заданной по смещению от опорного объекта),

•ksPIntersect - [IPoint3DParamIntersect](ipoint3dparamintersect.html) (интерфейс параметров пространственной точки, заданной на пересечении опорных объектов),

•ksPCenter - [IPoint3DParamCenter](ipoint3dparamcenter.html) (интерфейс параметров пространственной точки, заданной в центре опорного объекта),

•ksPCurve - [IPoint3DParamCurve](ipoint3dparamcurve.html) (интерфейс параметров пространственной точки, заданной на кривой со смещением),

•ksPSurface - [IPoint3DparamSurface](ipoint3dparamsurface.html) (интерфейс параметров пространственной точки, заданной на поверхности),

•ksPProjection - [IPoint3DParamProjection](ipoint3dparamprojection.html) (интерфейс параметров пространственной точки, заданной проецированием).

Подразделы:

(отсутствуют)
