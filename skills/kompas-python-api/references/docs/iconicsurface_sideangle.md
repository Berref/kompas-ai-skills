# SideAngle - Значение угла для построения угла треугольника

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IConicSurface](iconicsurface.html) > [IConicSurface - свойства](iconicsurface_propers.html) |  Scroll [ [ [ ](iconicsurface_sideanglebuildingtype.html "К следующему разделу")](iconicsurface_propers.html "На уровень выше")](iconicsurface_sectioncurvetangentsurface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconicsurface.html)

Тип данных: double

Синтаксис Automation:

SideAngle = Object.SideAngle( FirstSide, ValueType ) | Получить свойство ([* ](1.html))  
---|---  
Object.SideAngle( FirstSide, ValueType ) = SideAngle | Установить свойство ([* ](1.html))  
SideAngle = Object.GetSideAngle( FirstSide, ValueType ) | Получить свойство ([**](2.html))  
Object.SetSideAngle( FirstSide, ValueType, SideAngle ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SideAngle( FirstSide, ValueType, &SideAngle ) | Получить свойство  
---|---  
Object.put_SideAngle( FirstSide, ValueType, SideAngle ) | Установить свойство  
  
Входные параметры:

BOOL FirstSide | \- TRUE - первая сторона, FALSE - вторая сторона,  
---|---  
ValueType | \- тип движения сечения из перечисления [ksSideAngleTypeEnum](kssideangletypeenum.html).  
  
Подразделы:

(отсутствуют)
