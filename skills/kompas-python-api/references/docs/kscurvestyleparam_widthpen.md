# widthPen - Способ задания толщины линии

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров стилей объектов ](cf1711377.html) > [Стиль линии ](cf1753270.html) > [Стиль линии (Интерфейс ksCurveStyleParam) ](kscurvestyleparam.html) > [ksCurveStyleParam - свойства ](kscurvestyleparam_props.html) |  Scroll [ [ [ ](kscurvestyleparam_methods.html "К следующему разделу")](kscurvestyleparam_props.html "На уровень выше")](kscurvestyleparam_screenwidth.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvestyleparam.html)

Тип данных:short.

Значения свойства:

0 | \- толщина задается пользователем,  
---|---  
1 | \- толщина как у основной линии,  
2 | \- толщина как у тонкой линии,  
3 | \- толщина как у утолщенной линии.  
  
Синтаксис Automation:

widthPen = iCurveStyleParam. widthPen | Получить свойство ([* ](1.html))  
---|---  
iCurveStyleParam. widthPen = widthPen | Установить свойство ([* ](1.html))  
widthPen = iCurveStyleParam.GetWidthPen () | Получить свойство ([**](2.html))  
iCurveStyleParam.SetWidthPen( widthPen ) | Установить свойство ([**](2.html))  
  
Примечание:

Если выбрано задание толщины пользователем, то используются значения толщины линии, заданные свойствами [paperWidth](kscurvestyleparam_paperwidth.html) и [screenWidth](kscurvestyleparam_screenwidth.html).

Подразделы:

(отсутствуют)
