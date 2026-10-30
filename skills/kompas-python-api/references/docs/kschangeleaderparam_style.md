# style - Стиль текста

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Знак изменения (Интерфейс ksChangeLeaderParam) ](kschangeleaderparam.html) > [ksChangeLeaderParam - свойства ](kschangeleaderparam_props.html) |  Scroll [ [ [ ](kschangeleaderparam_x.html "К следующему разделу")](kschangeleaderparam_props.html "На уровень выше")](kschangeleaderparam_signtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kschangeleaderparam.html)

Тип данных: long

Значения свойства:

номер системного стиля, |   
  
---|---  
номер пользовательского стиля. |   
INDICATIN_TEXT_LINE_ARR | \- в этом случае текст задается массивом строк, и стиль текста может быть указан индивидуально для каждой строки.  
  
[Системные стили текстов...](tstyles.html)

Синтаксис Automation:

style = iChangeLeaderParam.style | Получить свойство ([* ](1.html))  
---|---  
iChangeLeaderParam.style = style | Установить свойство ([* ](1.html))  
style = iChangeLeaderParam.GetStyle() | Получить свойство ([**](2.html))  
iChangeLeaderParam.SetStyle( style ) | Установить свойство ([**](2.html))  
  
Примечание:

Если style = INDICATIN_TEXT_LINE_ARR, то динамический массив pText - типа TEXT_LINE_ARR. В остальных случаях - типа CHAR_STR_ARR.

Подразделы:

(отсутствуют)
