# textBase - Параметр отрисовки текста

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) > [Линейные и угловые размеры ](cf1715343.html) > [Отрисовка линейных и угловых размеров (Интерфейс ksDimDrawingParam) ](ksdimdrawingparam.html) > [ksDimDrawingParam - свойства ](ksdimdrawingparam_props.html) |  Scroll [ [ [ ](ksdimdrawingparam_methods.html "К следующему разделу")](ksdimdrawingparam_props.html "На уровень выше")](ksdimdrawingparam_textpos.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdimdrawingparam.html)

Тип данных: short.

Значения свойства:

0 | \- в центре,  
---|---  
1 | \- на расстояние (или угол) [textPos](ksdimdrawingparam_textpos.html) относительно первой точки,  
2 | \- на расстояние (или угол) textPos относительно второй точки,  
3 | \- общая размерная линия,  
4 | \- первый размер в цепочке размерных линий.  
  
Синтаксис Automation:

textBase = iDimDrawing.textBase | Получить свойство ([* ](1.html))  
---|---  
iDimDrawing.textBase = textBase | Установить свойство ([* ](1.html))  
textBase = iDimDrawing.GetTextBase() | Получить свойство ([**](2.html))  
iDimDrawing.SetTextBase( textBase ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
