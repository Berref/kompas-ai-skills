# SplineOnPoles - Тип построения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_splineorder.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_reverse.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- сплайн по полюсам,  
---|---  
FALSE | \- сплайн по точкам.  
  
Синтаксис Automation:

SplineOnPoles = iObject.SplineOnPoles; | Получить свойство ([* ](1.html))  
---|---  
iObject.SplineOnPoles = SplineOnPoles; | Установить свойство ([* ](1.html))  
SplineOnPoles = iObject.GetSplineOnPoles(); | Получить свойство ([**](2.html))  
iObject.SetSplineOnPoles(SplineOnPoles); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SplineOnPoles (&SplineOnPoles) | Получить свойство  
---|---  
iObject->put_SplineOnPoles (SplineOnPoles) | Установить свойство  
  
Примечание.

Свойство позволяет получить/установить сплайн по точкам/полюсам.

Подразделы:

(отсутствуют)
