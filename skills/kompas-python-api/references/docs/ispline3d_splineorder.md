# SplineOrder - Порядок сплайна

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_splinetransitiontype.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_splineonpoles.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: long

Значения свойства:

TRUE | \- сплайн по полюсам,  
---|---  
FALSE | \- сплайн по точкам.  
  
Синтаксис Automation:

SplineOrder = iObject.SplineOrder; | Получить свойство ([* ](1.html))  
---|---  
iObject.SplineOrder = SplineOrder; | Установить свойство ([* ](1.html))  
SplineOrder = iObject.GetSplineOrder(); | Получить свойство ([**](2.html))  
iObject.SetSplineOrder(SplineOrder); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SplineOrder (&SplineOrder) | Получить свойство  
---|---  
iObject->put_SplineOrder (SplineOrder) | Установить свойство  
  
Примечание.

Свойство позволяет получить/установить порядок сплайна. Значение порядка кривой должно принадлежать диапазону 3 ... 10.

Подразделы:

(отсутствуют)
