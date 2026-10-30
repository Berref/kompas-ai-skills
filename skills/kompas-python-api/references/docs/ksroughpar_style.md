# style - Стиль текста

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Обозначение шероховатости ](ch1721808.html) > [Обозначение шероховатости (Интерфейс ksRoughPar) ](ksroughpar.html) > [ksRoughPar - свойства ](ksroughpar_props.html) |  Scroll [ [ [ ](ksroughpar_type.html "К следующему разделу")](ksroughpar_props.html "На уровень выше")](ksroughpar_ctext3.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksroughpar.html)

Тип данных: long

Значения свойства:

номер системного стиля, |   
  
---|---  
номер пользовательского стиля, |   
INDICATIN_TEXT_LINE_ARR | \- в этом случае текст задается массивом строк, и стиль текста может быть указан индивидуально для каждой строки.  
  
[Системные стили текстов...](tstyles.html)

Синтаксис Automation:

style = iRoughPar.style | Получить свойство ([* ](1.html))  
---|---  
iRoughPar.style = style | Установить свойство ([* ](1.html))  
style = iRoughPar.GetStyle() | Получить свойство ([**](2.html))  
iRoughPar.SetStyle( style ) | Установить свойство ([**](2.html))  
  
Примечание:

Если style = INDICATIN_TEXT_LINE_ARR, то динамический массив pText - типа TEXT_LINE_ARR. В остальных случаях - типа CHAR_STR_ARR.

Подразделы:

(отсутствуют)
