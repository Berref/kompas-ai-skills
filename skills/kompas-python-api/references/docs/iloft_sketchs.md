# Sketchs - Сечения. Эскизы, контуры, пространственные кривые, грани

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс ILoft ](iloft.html) > [ILoft - свойства ](iloft_propers.html) |  Scroll [ [ [ ](iloft_methods.html "К следующему разделу")](iloft_propers.html "На уровень выше")](iloft_operationresult.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloft.html)

Тип данных: VARIANT

Синтаксис Automation:

Sketchs = Object.Sketchs | Получить свойство ([* ](1.html))  
---|---  
Object.Sketchs = Sketchs | Установить свойство ([* ](1.html))  
Sketchs = Object.GetSketchs() | Получить свойство ([**](2.html))  
Object.SetSketchs( Sketchs ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Sketchs( &Sketchs ) | Получить свойство  
---|---  
Object.put_Sketchs( Sketchs ) | Установить свойство  
  
Примечание.

Свойство позволяет получать и устанавливать массив сечений, участвующих в операции.

Массив возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
