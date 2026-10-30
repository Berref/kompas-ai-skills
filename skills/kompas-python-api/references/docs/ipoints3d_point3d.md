# Point3D - Элемент, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoints3D ](ipoints3d.html) > [IPoints3D - свойства ](ipoints3d_props.html) |  Scroll [ [ [ ](ipoints3d_methods.html "К следующему разделу")](ipoints3d_props.html "На уровень выше")](ipoints3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoints3d.html)

Тип данных: указатель на интерфейс [IPoint3D](ipoint3d.html)

Синтаксис Automation:

Point3D = iObject.Point3D( index ) | Получить свойство ([* ](1.html))  
---|---  
Point3D = iObject.GetPoint3D( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Point3D( index, &Point3D ) | Получить свойство  
---|---  
  
Входные параметры:

Index | VT_BSTR - имя объекта, VT_I4 - индекс объекта.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
