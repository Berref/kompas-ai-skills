# paperWidth - Толщина линии на бумаге

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров стилей объектов ](cf1711377.html) > [Стиль линии ](cf1753270.html) > [Стиль линии (Интерфейс ksCurveStyleParam) ](kscurvestyleparam.html) > [ksCurveStyleParam - свойства ](kscurvestyleparam_props.html) |  Scroll [ [ [ ](kscurvestyleparam_screenwidth.html "К следующему разделу")](kscurvestyleparam_props.html "На уровень выше")](kscurvestyleparam_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvestyleparam.html)

Тип данных:double.

Синтаксис Automation:

paperWidth = iCurveStyleParam.paperWidth | Получить свойство ([* ](1.html))  
---|---  
iCurveStyleParam.paperWidth = paperWidth | Установить свойство ([* ](1.html))  
paperWidth = iCurveStyleParam.GetPaperWidth() | Получить свойство ([**](2.html))  
iCurveStyleParam.SetPaperWidth( paperWidth ) | Установить свойство ([**](2.html))  
  
Примечание:

Толщина линии, заданная этим свойством, используется, если свойство [widthPen](kscurvestyleparam_widthpen.html) установлено в пользовательский тип толщины линии.

При инициализации параметров интерфейса методом [Init](kscurvestyleparam_init.html) также устанавливается пользовательский способ задания толщины линии.

Подразделы:

(отсутствуют)
