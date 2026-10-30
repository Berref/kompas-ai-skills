# ConstraintObject - Объект сопряжения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_constraintreverse.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_constraintlimitobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html).

Синтаксис Automation:

ConstraintObject = Object.ConstraintObject( PointIndex ); | Получить свойство ([* ](1.html))  
---|---  
Object.ConstraintObject( PointIndex ) = ConstraintObject; | Установить свойство ([* ](1.html))  
ConstraintObject = Object.GetConstraintObject( PointIndex ); | Получить свойство ([**](2.html))  
Object.SetConstraintObject( PointIndex, ConstraintObject ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ConstraintObject( PointIndex, &ConstraintObject ) | Получить свойство  
---|---  
Object.put_ConstraintObject( PointIndex, ConstraintObject ) | Установить свойство  
  
Входные параметры:

long PointIndex | \- индекс точки.  
---|---  
  
Подразделы:

(отсутствуют)
