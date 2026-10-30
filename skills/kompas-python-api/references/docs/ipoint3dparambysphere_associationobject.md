# AssociationObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamBySphere ](ipoint3dparambysphere.html) > [IPoint3DParamBySphere - свойства ](ipoint3dparambysphere_props.html) |  Scroll [ [ [ ](ipoint3dparambysphere_b.html "К следующему разделу")](ipoint3dparambysphere_props.html "На уровень выше")](ipoint3dparambysphere_a.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparambysphere.html)

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
