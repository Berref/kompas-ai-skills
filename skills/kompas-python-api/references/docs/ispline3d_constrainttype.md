# ConstraintType - Тип сопряжения в заданной вершине. Управление кривизной

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_curvature.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_constraintreverse.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: Значение из перечисления [ksNurbsByPointsPointConstraintsEnum](ksnurbsbypointspointconstraintsenum.html).

Синтаксис Automation:

ConstraintType = Object.ConstraintType( PointIndex ); | Получить свойство ([* ](1.html))  
---|---  
Object.ConstraintType( PointIndex ) = ConstraintType; | Установить свойство ([* ](1.html))  
ConstraintType = Object.GetConstraintType( PointIndex ); | Получить свойство ([**](2.html))  
Object.SetConstraintType( PointIndex, ConstraintType ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ConstraintType( PointIndex, &ConstraintType ) | Получить свойство  
---|---  
Object.put_ConstraintType( PointIndex, ConstraintType ) | Установить свойство  
  
Входные параметры:

long PointIndex | \- индекс точки.  
---|---  
  
Подразделы:

(отсутствуют)
