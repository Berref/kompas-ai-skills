# PointType - Тип параметров построения точки поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - свойства ](imeshpointssurface_props.html) |  Scroll [ [ [ ](bc2291576.html "К следующему разделу")](imeshpointssurface_props.html "На уровень выше")](imeshpointssurface_pointparameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imeshpointssurface.html)

Тип данных: из перечисления [ksPoint3DTypeEnum](kspoint3dtypeenum.html)

Синтаксис Automation:

PointType = Object.PointType( UIndex, VIndex ) | Получить свойство ([* ](1.html))  
---|---  
Object.PointType( UIndex, VIndex ) = PointType | Установить свойство ([* ](1.html))  
PointType = Object.GetPointType( UIndex, VIndex ) | Получить свойство ([**](2.html))  
Object.SetPointType( UIndex, VIndex, PointType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_PointType( UIndex, VIndex, &PointType ) | Получить свойство  
---|---  
Object.put_PointType( UIndex, VIndex, PointType ) | Установить свойство  
  
Входные параметры:

long UIndex | \- индекс точки по U,  
---|---  
long VIndex | \- индекс точки по V.  
  
Подразделы:

(отсутствуют)
