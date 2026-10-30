# PointParameters - Получить интерфейс параметров точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Тексты ](bc3335025.html) > [Интерфейс IModelText ](imodeltext.html) > [IModelText - свойства ](imodeltext_propers.html) |  Scroll [ [ [ ](imodeltext_text.html "К следующему разделу")](imodeltext_propers.html "На уровень выше")](imodeltext_pointparametertype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodeltext.html)

Тип данных: Указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

PointParameters = Object.PointParameters | Получить свойство ([* ](1.html))  
---|---  
PointParameters = Object.GetPointParameters() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_PointParameters( &PointParameters ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В зависимости от типа PointType интерфейс параметров должен приводится к одному из следующих вариантов:

•ksPDisplace - [IPoint3DParamDisplace](ipoint3dparamdisplace.html) \- интерфейс параметров пространственной точки, заданной по смещению от опорного объекта.

•ksPIntersect - [IPoint3DParamIntersect](ipoint3dparamintersect.html) \- интерфейс параметров пространственной точки, заданной на пересечении опорных объектов.

•ksPCenter - [IPoint3DParamCenter](ipoint3dparamcenter.html) \- интерфейс параметров пространственной точки, заданной в центре опорного объекта.

•ksPCurve - [IPoint3DParamCurve](ipoint3dparamcurve.html) \- интерфейс параметров пространственной точки, заданной на кривой со смещением.

•ksPSurface - [IPoint3DparamSurface](ipoint3dparamsurface.html) \- интерфейс параметров пространственной точки, заданной на поверхности.

•ksPProjection - [IPoint3DParamProjection](ipoint3dparamprojection.html) \- интерфейс параметров пространственной точки, заданной проецированием.

Подразделы:

(отсутствуют)
