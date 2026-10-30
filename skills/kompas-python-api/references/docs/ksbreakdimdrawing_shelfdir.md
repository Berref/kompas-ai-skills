# shelfDir - Признак отрисовки полки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) > [Линейные и угловые размеры ](cf1715343.html) > [Отрисовка линейных и угловых размеров с обрывом (Интерфейс ksBreakDimDrawing) ](ksbreakdimdrawing.html) > [ksBreakDimDrawing - свойства ](ksbreakdimdrawing_props.html) |  Scroll [ [ [ ](ksbreakdimdrawing_textpos.html "К следующему разделу")](ksbreakdimdrawing_props.html "На уровень выше")](ksbreakdimdrawing_pt.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbreakdimdrawing.html)

Тип данных:long.

Значения свойства:

0 | \- нет полки,  
---|---  
-1 | \- полка влево,  
1 | \- полка вправо,  
2 | \- полка вверх,  
3 | \- пока вниз.  
  
Синтаксис Automation:

shelfDir = iBreakDimDrawing.shelfDir | Получить свойство ([* ](1.html))  
---|---  
iBreakDimDrawing.shelfDir = shelfDir | Установить свойство ([* ](1.html))  
shelfDir = iBreakDimDrawing.GetShelfDir() | Получить свойство ([**](2.html))  
iBreakDimDrawing.SetShelfDir( shelfDir ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
