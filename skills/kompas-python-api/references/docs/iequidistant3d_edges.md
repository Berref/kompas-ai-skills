# Edges - Массив ребер

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IEquidistant3D ](iequidistant3d.html) > [IEquidistant3D - свойства ](iequidistant3d_props.html) |  Scroll [ [ [ ](iequidistant3d_edgescount.html "К следующему разделу")](iequidistant3d_props.html "На уровень выше")](iequidistant3d_distance.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iequidistant3d.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

Edges = Object.Edges | Получить свойство ([* ](1.html))  
---|---  
Object.Edges = Edges | Установить свойство ([* ](1.html))  
Edges = Object.GetEdges() | Получить свойство ([**](2.html))  
Object.SetEdges( Edges ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Edges( &Edges ) | Получить свойство  
---|---  
Object.put_Edges( Edges ) | Установить свойство  
  
Свойство позволяет устанавливать и получать массив ребер эквидистанты.

Примечание

Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
