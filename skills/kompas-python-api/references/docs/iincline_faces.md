# Faces - Массив уклоняемых граней

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IIncline ](iincline.html) > [IIncline - свойства ](iincline_propers.html) |  Scroll [ [ [ ](iincline_plane.html "К следующему разделу")](iincline_propers.html "На уровень выше")](iincline_direction.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iincline.html)

Тип данных: VARIANT

Синтаксис Automation:

Faces = Object.Faces | Получить свойство ([* ](1.html))  
---|---  
Object.Faces = Faces | Установить свойство ([* ](1.html))  
Faces = Object.GetFaces() | Получить свойство ([**](2.html))  
Object.SetFaces( Faces ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Faces( &Faces ) | Получить свойство  
---|---  
Object.put_Faces( Faces ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать грань или массив граней, участвующих в операции уклон.

Массив граней возвращается в виде массива SAFEARRAY граней LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
