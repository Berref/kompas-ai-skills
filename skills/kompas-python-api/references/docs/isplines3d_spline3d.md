# Spline3D - Сплайн, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISplines3D ](isplines3d.html) > [ISplines3D - свойства ](isplines3d_props.html) |  Scroll [ [ [ ](isplines3d_methods.html "К следующему разделу")](isplines3d_props.html "На уровень выше")](isplines3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isplines3d.html)

Тип данных: указатель на интерфейс [ISpline3D](ispline3d.html)

Синтаксис Automation:

Spline3D = Object.Spline3D( index ) | Получить свойство ([* ](1.html))  
---|---  
Spline3D = Object.GetSpline3D( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object->get_Spline3D( index, &Spline3D ) | Получить свойство  
---|---  
  
Входные параметры:

Index | VT_BSTR - имя объекта, VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
