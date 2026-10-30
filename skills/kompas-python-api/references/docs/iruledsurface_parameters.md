# Parameters - Получить интерфейс параметров линейчатой поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurface ](iruledsurface.html) > [IRuledSurface - свойства ](iruledsurface_props.html) |  Scroll [ [ [ ](iruledsurface_methods.html "К следующему разделу")](iruledsurface_props.html "На уровень выше")](iruledsurface_edgescount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itrimmedsurface.html)

Тип данных: Указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

Parameters = Object.Parameters | Получить свойство ([* ](1.html))  
---|---  
Parameters = Object.GetParameters() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Parameters( &Parameters ) | Получить свойство  
---|---  
  
Примечание

Свойство доступно только для чтения.

В зависимости от выбранного способа построения [IRuledSurface_BuildingType](iruledsurface_buildingtype.html) метод возвращает интерфейсы:

ksRuledSurfaceByCurves | 0 | [IRuledSurfaceParametersByCurves](iruledsurfaceparametersbycurves.html) \- Линейчатая поверхность по двум кривым  
---|---|---  
ksRuledSurfaceBySurfaces | 1 | [IRuledSurfaceParametersByFaces](iruledsurfaceparametersbyfaces.html) \- Линейчатая поверхность по двум поверхностям  
ksRuledSurfaceByCurveAndSurface | 2 | [IRuledSurfaceParametersByCurveAndFace](iruledsurfaceparametersbycurveandface.html) \- Линейчатая поверхность по кривой и поверхности.  
ksRuledSurfaceBySurfaceTangentCurve | 3 | [IRuledSurfaceTangentParametersByCurveAndFace](iruledsurfacetangentparametersbycurveandface.html) \- Линейчатая поверхность по кривой с касанием к поверхности.  
ksRuledSurfaceByCurveAndDir | 4 | [IRuledSurfaceParametersByCurveAndDir](iruledsurfaceparametersbycurveanddir.html) \- Линейчатая поверхность по кривой и направлению  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
