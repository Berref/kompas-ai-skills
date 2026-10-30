# textPos - Положение текста размерной надписи

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) > [Линейные и угловые размеры ](cf1715343.html) > [Отрисовка линейных и угловых размеров (Интерфейс ksDimDrawingParam) ](ksdimdrawingparam.html) > [ksDimDrawingParam - свойства ](ksdimdrawingparam_props.html) |  Scroll [ [ [ ](ksdimdrawingparam_textbase.html "К следующему разделу")](ksdimdrawingparam_props.html "На уровень выше")](ksdimdrawingparam_shelfdir.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdimdrawingparam.html)

Тип данных:long.

Значения свойства:

0 | \- автоматическое размещение текста,  
---|---  
> 0 | \- размещение текста на указанное расстояние в направлении от первой точки ко второй,  
< 0 | \- размещение текста на указанное расстояние в направлении от второй точки к первой.  
  
Синтаксис Automation:

textPos = iDimDrawing.textPos | Получить свойство ([* ](1.html))  
---|---  
iDimDrawing.textPos = textPos | Установить свойство ([* ](1.html))  
textPos = iDimDrawing.GetTextPos() | Получить свойство ([**](2.html))  
iDimDrawing.SetTextPos( textPos ) | Установить свойство ([**](2.html))  
  
Примечание:

Значение данного свойства задается в миллиметрах для линейных размеров и в градусах - для угловых. Этот параметр - аннотационный (не зависит от масштаба, измеряется "по бумаге").

Подразделы:

(отсутствуют)
