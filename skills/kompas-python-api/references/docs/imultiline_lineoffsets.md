# LineOffsets - Массив смещений в виде массива SAFEARRAY double - VT_ARRAY | VT_R8

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_linestyle.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_lineoffset.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: VARIANT

Значения свойства:

| Массив SafeArray типа VT_ARRAY | VT_R8.  
---|---  
  
Синтаксис Automation:

LineOffsets = iObject.LineOffsets; | Получить свойство([* ](1.html))  
---|---  
LineOffsets = iObject.GetLineOffsets(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LineOffsets( &LineOffsets ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получить массив SAFEARRAY смещения всех линий.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
