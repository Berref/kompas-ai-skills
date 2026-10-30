# DefaultObject - Получить примитив ЛСК (ось или плоскость)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - свойства ](ilocalcoordinatesystem_props.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_hidden.html "К следующему разделу")](ilocalcoordinatesystem_props.html "На уровень выше")](ilocalcoordinatesystem_current.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Тип данных: указатель на интерфейс объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

DefaultObject = iObject.DefaultObject( type ); | Получить свойство ([* ](1.html))  
---|---  
DefaultObject = iObject.GetDefaultObject( type ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DefaultObject( type, &DefaultObject ); | Получить свойство  
---|---  
  
Входные параметры:

type | \- тип объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html); допустимые типы: \- o3d_axisOX, \- o3d_axisOY \- o3d_axisOZ, \- o3d_planeXOY, \- o3d_planeXOZ, \- o3d_planeYOZ.  
---|---  
  
Возвращаемое значение:

Указатель на примитив ЛСК (ось или плоскость). | \- в случае успеха;  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Позволяет получить указатель на примитив ЛСК (ось или плоскость) в виде указателя на интерфейс [IModelObject](imodelobject.html).

Подразделы:

(отсутствуют)
