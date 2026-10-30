# style - Стиль текста

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения позиции (Интерфейс ksPosLeaderParam) ](ksposleaderparam.html) > [ksPosLeaderParam - свойства ](ksposleaderparam_props.html) |  Scroll [ [ [ ](ksposleaderparam_x.html "К следующему разделу")](ksposleaderparam_props.html "На уровень выше")](ksposleaderparam_diry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksposleaderparam.html)

Тип данных: long

Значения свойства:

номер системного стиля, |   
  
---|---  
номер пользовательского стиля, |   
INDICATIN_TEXT_LINE_ARR | \- в этом случае текст задается массивом строк, и стиль текста может быть указан индивидуально для каждой строки.  
  
[Системные стили текстов...](tstyles.html)

Синтаксис Automation:

style = iPosLeaderParam.style | Получить свойство ([* ](1.html))  
---|---  
iPosLeaderParam.style = style | Установить свойство ([* ](1.html))  
style = iPosLeaderParam.GetStyle() | Получить свойство ([**](2.html))  
iPosLeaderParam.SetStyle( style ) | Установить свойство ([**](2.html))  
  
Примечание:

Если style = INDICATIN_TEXT_LINE_ARR, то динамический массив pText - типа TEXT_LINE_ARR. В остальных случаях - типа CHAR_STR_ARR.

Подразделы:

(отсутствуют)
