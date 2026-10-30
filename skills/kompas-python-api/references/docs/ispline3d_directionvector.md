# DirectionVector - Направляющий вектор в точке сопряжения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_knots.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_curvatureradius.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: Указатель на интерфейс [IVector3D](ivector3d.html).

Синтаксис Automation:

DirectionVector = Object.DirectionVector( PointIndex, VectorIndex, PVal ); | Получить свойство ([* ](1.html))  
---|---  
DirectionVector = Object.GetDirectionVector( PointIndex, VectorIndex, PVal ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DirectionVector( PointIndex, VectorIndex, PVal, &DirectionVector ) | Получить свойство  
---|---  
  
Входные параметры:

long PointIndex | \- индекс точки.  
---|---  
VectorIndex | \- cпособ создания сопряжения в заданной вершине сплайна из перечисления [ksTransitionVectorIndexEnum](kstransitionvectorindexenum.html).  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
