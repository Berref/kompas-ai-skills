# CenterFaces - Центральные грани

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFullFillet ](ifullfillet.html) > [IFullFillet - свойства ](ifullfillet_props.html) |  Scroll [ [ [ ](ifullfillet_tangent.html "К следующему разделу")](ifullfillet_props.html "На уровень выше")](ifullfillet_side2faces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifullfillet.html)

Тип данных: VARIANT

Синтаксис Automation:

CenterFaces = Object.CenterFaces | Получить свойство ([* ](1.html))  
---|---  
Object.CenterFaces = CenterFaces | Установить свойство ([* ](1.html))  
CenterFaces = Object.GetCenterFaces() | Получить свойство ([**](2.html))  
Object.SetCenterFaces( CenterFaces ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_CenterFaces( &CenterFaces ) | Получить свойство  
---|---  
Object.put_CenterFaces( CenterFaces ) | Установить свойство  
  
Примечание.

1\. Позволяет получать и устанавливать грань или массив центральных граней, участвующих в операции полного скругления.

2\. Массив объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
