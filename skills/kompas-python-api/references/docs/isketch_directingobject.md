# DirectingObject - Направляющий объект для оси

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - свойства ](isketch_props.html) |  Scroll [ [ [ ](isketch_edges.html "К следующему разделу")](isketch_props.html "На уровень выше")](isketch_coordinatesystem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

DirectingObject = Object.DirectingObject( Axis ); | Получить свойство ([* ](1.html))  
---|---  
Object.DirectingObject( Axis ) = DirectingObject; | Установить свойство ([* ](1.html))  
DirectingObject = Object.GetDirectingObject( Axis ); | Получить свойство ([**](2.html))  
Object.SetDirectingObject( Axis, DirectingObject ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DirectingObject( Axis, &DirectingObject ); | Получить свойство  
---|---  
Object.put_DirectingObject( Axis, DirectingObject ); | Установить свойство  
  
Входные параметры:

Axis | \- тип оси: o3d_axisOX - ось X, o3d_axisOY - ось Y  
---|---  
  
Примечание:

1\. При указании базовой плоскости можно задать направляющий объект для оси X или оси Y.

2\. Направление второй оси будет определяться как векторное произведение оси Z, направленной по нормали к плоскости, и заданным направлением.

3\. Направление осей можно задать также параметрами вектора.

Подразделы:

(отсутствуют)
