# AddPoint - Добавить точку

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ICloudPointsSurface ](icloudpointssurface.html) > [ICloudPointsSurface - методы ](icloudpointssurface_methods.html) |  Scroll [ [ [ ](icloudpointssurface_addpoints.html "К следующему разделу")](icloudpointssurface_methods.html "На уровень выше")](icloudpointssurface_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icloudpointssurface.html)

Синтаксис Automation:

LPDISPATCH AddPoint( double X,

double Y,

double Z,

ksPoint3DTypeEnum PVal,

IModelObject * AssociationObject );

Синтаксис COM:

HRESULT AddPoint( double X,

double Y,

double Z,

ksPoint3DTypeEnum PVal,

IModelObject * AssociationObject,

IKompasAPIObject ** Result );

Возвращаемое значение:

Указатель на интерфейс параметров точки

Выходные параметры:

X, Y, Z | \- координаты точки,  
---|---  
PVal | \- тип параметров точки,  
AssociationObject | \- опорный объект для точки.  
  
Подразделы:

(отсутствуют)
