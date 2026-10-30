# Points - Массив координат точек линии разреза/сечения в виде SAFEARRAY double - VT_ARRAY | VT_R8

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс ICutLine ](icutline.html) > [ICutLine - свойства ](icutline_props.html) |  Scroll [ [ [ ](icutline_text.html "К следующему разделу")](icutline_props.html "На уровень выше")](icutline_autozone.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutline.html)

Тип данных: VARIANT

Синтаксис Automation:

Points = Object.Points | Получить свойство([* ](1.html))  
---|---  
Object.Points = Points | Установить свойство ([* ](1.html))  
Points = Object.GetPoints() | Получить свойство ([**](2.html))  
Object.SetPoints( Points ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Points( &Points ) | Получить свойство  
---|---  
Object.put_Points( Points ) | Установить свойство  
  
Примечание:

Координаты точек располагаются в массиве в следующем порядке:

x0, y0 (начальная точка), x1, y1, ... x2, y2, ... (точки перегибов), xn, yn (конечная точка). Количество элементов массива должно быть четным.

Подразделы:

(отсутствуют)
