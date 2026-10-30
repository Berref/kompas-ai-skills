# AddPoint - Добавить точку в создаваемый ряд точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - методы ](bc2291576.html) |  Scroll [ [ [ ](imeshpointssurface_addpointsseries.html "К следующему разделу")](bc2291576.html "На уровень выше")](bc2291576.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](imeshpointssurface.html)

Синтаксис Automation:

LPDISPATCH AddPoint( double X,

double Y,

double Z,

double Weight,

ksPoint3DTypeEnum PointType,

IModelObject * AssociationObject );

Синтаксис COM:

HRESULT AddPoint( double X,

double Y,

double Z,

double Weight,

ksPoint3DTypeEnum PointType,

IModelObject * AssociationObject,

IKompasAPIObject ** Result );

Возвращаемое значение:

Указатель на интерфейс параметров точки

Входные параметры:

X, Y, Z | \- координаты точки,  
---|---  
Weight | \- вес точки,  
PointType | \- тип параметров точки,  
AssociationObject | \- опорный объект.  
  
Примечание:

Метод должен вызываться между вызовами методов [IMeshPointsSurface::BeginPointsSeries](imeshpointssurface_beginpointsseries.html) и [IMeshPointsSurface::EndPointsSeries](imeshpointssurface_endpointsseries.html).

Подразделы:

(отсутствуют)
