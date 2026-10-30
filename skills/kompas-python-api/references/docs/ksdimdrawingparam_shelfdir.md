# shelfDir - Направление выносной полки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) > [Линейные и угловые размеры ](cf1715343.html) > [Отрисовка линейных и угловых размеров (Интерфейс ksDimDrawingParam) ](ksdimdrawingparam.html) > [ksDimDrawingParam - свойства ](ksdimdrawingparam_props.html) |  Scroll [ [ [ ](ksdimdrawingparam_textpos.html "К следующему разделу")](ksdimdrawingparam_props.html "На уровень выше")](ksdimdrawingparam_pt2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdimdrawingparam.html)

Тип данных:long.

Значения свойства:

0 | \- нет полки,  
---|---  
-1 | \- полка влево,  
1 | \- полка вправо,  
2 | \- полка вверх,  
3 | \- полка вниз.  
  
Синтаксис Automation:

shelfDir = iDimDrawing.shelfDir | Получить свойство ([* ](1.html))  
---|---  
iDimDrawing.shelfDir = shelfDir | Установить свойство ([* ](1.html))  
shelfDir = iDimDrawing.GetShelfDir() | Получить свойство ([**](2.html))  
iDimDrawing.SetShelfDir( shelfDir ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
