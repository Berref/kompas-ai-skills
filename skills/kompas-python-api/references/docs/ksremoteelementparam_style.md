# style - Стиль текста

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Выносной элемент (Интерфейс ksRemoteElementParam) ](ksremoteelementparam.html) > [ksRemoteElementParam - свойства ](ksremoteelementparam_props.html) |  Scroll [ [ [ ](ksremoteelementparam_width.html "К следующему разделу")](ksremoteelementparam_props.html "На уровень выше")](ksremoteelementparam_smooth.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksremoteelementparam.html)

Тип данных: long

Синтаксис Automation:

style = iRemoteElementParam.style | Получить свойство ([* ](1.html))  
---|---  
iRemoteElementParam.style = style | Установить свойство ([* ](1.html))  
style = iRemoteElementParam.GetStyle() | Получить свойство ([**](2.html))  
iRemoteElementParam.SetStyle( style ) | Установить свойство ([**](2.html))  
  
Примечание:

Если style == INDICATIN_TEXT_LINE_ARR, создается динамический массив строк текста TEXT_LINE_ARR, структура которого описана в [StructTextLineParam](structtextlineparam.html). В противном случае создается динамический массив указателей на строки символов CHAR_STR_ARR.

Подразделы:

(отсутствуют)
