# DefaultObject - Получить предопределенные элементы (плоскости, ось и СК)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - свойства ](ipart7_props.html) |  Scroll [ [ [ ](ipart7_density.html "К следующему разделу")](ipart7_props.html "На уровень выше")](ipart7_createspcobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Тип данных: указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

DefaultObject = Object.DefaultObject( Type ) | Получить свойство ([* ](1.html))  
---|---  
DefaultObject = Object.GetDefaultObject( Type ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DefaultObject( &Type ) | Получить свойство  
---|---  
  
Входной параметр:

Type | \- тип объекта - константа из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Типы объектов (Type):

o3d_planeXOY | 1 | плоскость XOY,  
---|---|---  
o3d_planeXOZ | 2 | плоскость XOZ,  
o3d_planeYOZ | 3 | плоскость YOZ,  
o3d_pointCS | 4 | точка начала системы координат,  
o3d_axisOX | 71 | ось OX,  
o3d_axisOY | 72 | ось OY,  
o3d_axisOZ | 73 | ось OZ.  
  
Подразделы:

(отсутствуют)
