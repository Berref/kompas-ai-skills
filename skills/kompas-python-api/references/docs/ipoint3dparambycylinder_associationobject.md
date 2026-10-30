# AssociationObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamByCylinder ](ipoint3dparambycylinder.html) > [IPoint3DParamByCylinder - свойства ](ipoint3dparambycylinder_props.html) |  Scroll [ [ [ ](ipoint3dparambycylinder_r.html "К следующему разделу")](ipoint3dparambycylinder_props.html "На уровень выше")](ipoint3dparambycylinder_a.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparambycylinder.html)

Тип данных: указатель на интерфейс объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

AssociationObject = Object.AssociationObject | Получить свойство ([* ](1.html))  
---|---  
Object.AssociationObject = AssociationObject | Установить свойство ([* ](1.html))  
AssociationObject = Object.GetAssociationObject() | Получить свойство ([**](2.html))  
Object.SetAssociationObject( AssociationObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AssociationObject( &AssociationObject ) | Получить свойство  
---|---  
Object.put_AssociationObject( AssociationObject ) | Установить свойство  
  
Свойство позволяет связать точку с точечным объектом.

Примечание:

Если точка связана с точечным объектом, то координаты недоступны для изменения.

Подразделы:

(отсутствуют)
