# Parameters - Интерфейс параметров точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [IPoint3D - свойства ](ipoint3d_props.html) |  Scroll [ [ [ ](ipoint3d_parametertype.html "К следующему разделу")](ipoint3d_props.html "На уровень выше")](ipoint3d_associationobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3d.html)

Тип данных: указатель на интерфейс объекта [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

Parameters = iObject.Parameters; | Получить свойство ([* ](1.html))  
---|---  
Parameters = iObject.GetParameters(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Parameters( &Parameters ); | Получить свойство  
---|---  
  
Примечание.

В зависимости от типа [IPoint3D::ParameterType](ipoint3d_parametertype.html), интерфейс параметров должен приводиться к одному из следующих вариантов:

•ksPDisplace - [IPoint3DParamDisplace](ipoint3dparamdisplace.html) \- Интерфейс параметров пространственной точки, заданной по смещению от опорного объекта,

•ksPIntersect - [IPoint3DParamIntersect](ipoint3dparamintersect.html) \- Интерфейс параметров пространственной точки, заданной на пересечении опорных объектов,

•ksPCenter - [IPoint3DParamCenter](ipoint3dparamcenter.html) \- Интерфейс параметров пространственной точки, заданной в центре опорного объекта,

•ksPCurve - [IPoint3DParamCurve](ipoint3dparamcurve.html) \- Интерфейс параметров пространственной точки, заданной на кривой со смещением,

•ksPSurface - [IPoint3DparamSurface](ipoint3dparamsurface.html) \-  Интерфейс параметров пространственной точки, заданной на поверхности,

•ksPProjection - [IPoint3DParamProjection](ipoint3dparamprojection.html) \- Интерфейс параметров пространственной точки, заданной проецированием,

•ksPBetweenPoints - [IPoint3DParamBetweenPoints](ipoint3dparambetweenpoints.html) \- Интерфейс параметров пространственной точки между точками.

Подразделы:

(отсутствуют)
