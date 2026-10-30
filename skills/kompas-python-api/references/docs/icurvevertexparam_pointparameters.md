# PointParameters - Интерфейс параметров точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс ICurveVertexParam ](icurvevertexparam.html) > [ICurveVertexParam - свойства ](icurvevertexparam_props.html) |  Scroll [ [ [ ](icurvevertexparam_pointtype.html "К следующему разделу")](icurvevertexparam_props.html "На уровень выше")](icurvevertexparam_index.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvevertexparam.html)

Тип данных: Указатель на интерфейс параметров вершины ломанной [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

PointParameters = iObject.PointParameters( Index ); | Получить свойство ([* ](1.html))  
---|---  
PointParameters = iObject.GetPointParameters( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_PointParameters( Index, &PointParameters ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- индекс вершины.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В зависимости от типа PointType интерфейс параметров должен приводится к одному из следующих вариантов:

•ksPDisplace - [IPoint3DParamDisplace](ipoint3dparamdisplace.html) \- Интерфейс параметров пространственной точки, заданной по смещению от опорного объекта.

•ksPIntersect - [IPoint3DParamIntersect](ipoint3dparamintersect.html) \- Интерфейс параметров пространственной точки, заданной на пересечении опорных объектов.

•ksPCenter - [IPoint3DParamCenter](ipoint3dparamcenter.html) \- Интерфейс параметров пространственной точки, заданной в центре опорного объекта,

•ksPCurve - [IPoint3DParamCurve](ipoint3dparamcurve.html) \- Интерфейс параметров пространственной точки, заданной на кривой со смещением.

•ksPSurface - [IPoint3DparamSurface](ipoint3dparamsurface.html) \- Интерфейс параметров пространственной точки, заданной на поверхности.

•ksPProjection - [IPoint3DParamProjection](ipoint3dparamprojection.html) Интерфейс параметров пространственной точки, заданной проецированием.

Подразделы:

(отсутствуют)
