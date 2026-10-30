# LineOffset - Смещение линии

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_lineoffsets.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_linecount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: double

Синтаксис Automation:

LineOffset = iObject.LineOffset( LineIndex ); | Получить свойство([* ](1.html))  
---|---  
iObject.LineOffset( LineIndex ) = LineOffset; | Установить свойство ([* ](1.html))  
LineOffset = iObject.GetLineOffset( LineIndex ); | Получить свойство ([**](2.html))  
iObject.SetLineOffset( LineIndex, LineOffset );); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LineOffset( LineIndex, &LineOffset ) | Получить свойство  
---|---  
iObject->put_LineOffset( LineIndex, LineOffset ) | Установить свойство  
  
Входные параметры:

long LineIndex | \- индекс линии.  
---|---  
  
Примечание:

Свойство позволяет устанавливать смещение линии относительно базового контура.

Подразделы:

(отсутствуют)
