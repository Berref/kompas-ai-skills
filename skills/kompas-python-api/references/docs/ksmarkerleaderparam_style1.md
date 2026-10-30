# style1 - Стиль текста в знаке маркировки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения маркировки (Интерфейс ksMarkerLeaderParam) ](ksmarkerleaderparam.html) > [ksMarkerLeaderParam - свойства ](ksmarkerleaderparam_props.html) |  Scroll [ [ [ ](ksmarkerleaderparam_style2.html "К следующему разделу")](ksmarkerleaderparam_props.html "На уровень выше")](ksmarkerleaderparam_ctext2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmarkerleaderparam.html)

Тип данных: long

Значения свойства:

номер системного стиля, |   
  
---|---  
номер пользовательского стиля, |   
INDICATIN_TEXT_LINE_ARR | \- в этом случае текст задается массивом строк и стиль текста может быть указан индивидуально для каждой строки.  
  
[Системные стили текстов..](tstyles.html).

Синтаксис Automation:

style1 = iMarkerLeaderParam.style1 | Получить свойство ([* ](1.html))  
---|---  
iMarkerLeaderParam.style1 = style1 | Установить свойство ([* ](1.html))  
style1 = iMarkerLeaderParam.GetStyle1() | Получить свойство ([**](2.html))  
iMarkerLeaderParam.SetStyle1( style1 ) | Установить свойство ([**](2.html))  
  
Примечание:

Если style1 = INDICATIN_TEXT_LINE_ARR, то динамический массив текстов - типа TEXT_LINE_ARR. В остальных случаях - типа CHAR_STR_ARR.

Подразделы:

(отсутствуют)
