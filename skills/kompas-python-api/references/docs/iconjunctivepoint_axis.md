# Axis - Получить ось присоединительной точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс IConjunctivePoint ](iconjunctivepoint.html) > [IConjunctivePoint - свойства ](iconjunctivepoint_props.html) |  Scroll [ [ [ ](iconjunctivepoint_buildingtype.html "К следующему разделу")](iconjunctivepoint_props.html "На уровень выше")](iconjunctivepoint_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconjunctivepoint.html)

Тип данных: указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

Axis = Object.Axis(type) | Получить свойство ([* ](1.html))  
---|---  
Axis = Object.GetAxis(type) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ObjectX( type, &ObjectX ) | Получить свойство  
---|---  
  
Входные параметры:

type | \- тип запрашиваемой оси из перечисления [ksObj3dTypeEnum](obj3dtype.html), допустимыми значениями являются следующие: \- o3d_axisOX - ось со стрелкой, \- o3d_axisOY - ось без стрелки.  
---|---  
  
Возвращаемое значение:

указатель на ось | \- в случае успеха,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание.

1\. Свойство позволяет получить указатель на интерфейс оси присоединительной точки в соответствии с переданным типом.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
