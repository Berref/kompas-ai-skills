# Side2Faces - Боковые грани 2

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFullFillet ](ifullfillet.html) > [IFullFillet - свойства ](ifullfillet_props.html) |  Scroll [ [ [ ](ifullfillet_centerfaces.html "К следующему разделу")](ifullfillet_props.html "На уровень выше")](ifullfillet_side1faces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifullfillet.html)

Тип данных: VARIANT

Синтаксис Automation:

Side2Faces = Object.Side2Faces | Получить свойство ([* ](1.html))  
---|---  
Object.Side2Faces = Side2Faces | Установить свойство ([* ](1.html))  
Side2Faces = Object.GetSide2Faces() | Получить свойство ([**](2.html))  
Object.SetSide2Faces( Side2Faces ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Side2Faces( &Side2Faces ) | Получить свойство  
---|---  
Object.put_Side2Faces( Side2Faces ) | Установить свойство  
  
Примечание.

1\. Позволяет получать и устанавливать грань или массив граней второй стороны, участвующих в операции полного скругления.

2\. Массив объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
