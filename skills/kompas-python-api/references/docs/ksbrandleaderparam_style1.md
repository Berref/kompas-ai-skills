# style1 - Стиль текста в знаке клеймения

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения параметров клеймения (Интерфейс ksBrandLeaderParam) ](ksbrandleaderparam.html) > [ksBrandLeaderParam - свойства ](ksbrandleaderparam_props.html) |  Scroll [ [ [ ](ksbrandleaderparam_style2.html "К следующему разделу")](ksbrandleaderparam_props.html "На уровень выше")](ksbrandleaderparam_dirx.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbrandleaderparam.html)

Тип данных: long

Значения свойства:

номер системного стиля, |   
---|---  
номер пользовательского стиля, |   
INDICATIN_TEXT_LINE_ARR | \- в этом случае текст задается массивом строк и стиль текста может быть указан индивидуально для каждой строки.  
  
[Системные стили текстов...](tstyles.html)

Синтаксис Automation:

style1 = iBrandLeaderParam.style1 | Получить свойство ([* ](1.html))  
---|---  
iBrandLeaderParam.style1 = style1 | Установить свойство ([* ](1.html))  
style1 = iBrandLeaderParam.GetStyle1() | Получить свойство ([**](2.html))  
iBrandLeaderParam.SetStyle1( style1 ) | Установить свойство ([**](2.html))  
  
Примечание:

Если style1 = INDICATIN_TEXT_LINE_ARR, то динамический массив текстов - типа TEXT_LINE_ARR. В остальных случаях - типа CHAR_STR_ARR.

Подразделы:

(отсутствуют)
