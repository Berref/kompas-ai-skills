# Side1Faces - Боковые грани 1

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFullFillet ](ifullfillet.html) > [IFullFillet - свойства ](ifullfillet_props.html) |  Scroll [ [ [ ](ifullfillet_side2faces.html "К следующему разделу")](ifullfillet_props.html "На уровень выше")](ifullfillet_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifullfillet.html)

Тип данных: VARIANT

Синтаксис Automation:

Side1Faces = Object.Side1Faces | Получить свойство ([* ](1.html))  
---|---  
Object.Side1Faces = Side1Faces | Установить свойство ([* ](1.html))  
Side1Faces = Object.GetSide1Faces() | Получить свойство ([**](2.html))  
Object.SetSide1Faces( Side1Faces ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Side1Faces( &Side1Faces ) | Получить свойство  
---|---  
Object.put_Side1Faces( Side1Faces ) | Установить свойство  
  
Примечание.

1\. Позволяет получать и устанавливать грань или массив граней первой стороны, участвующих в операции полного скругления.

2\. Массив объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
