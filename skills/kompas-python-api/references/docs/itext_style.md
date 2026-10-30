# Style - Cтиль текста

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IText ](itext.html) > [IText - свойства ](itext_props.html) |  Scroll [ [ [ ](itext_textline.html "К следующему разделу")](itext_props.html "На уровень выше")](itext_str.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itext.html)

Тип данных: long

Синтаксис Automation:

Style = iObject.Style; | Получить свойство([* ](1.html))  
---|---  
iObject.Style = Style; | Установить свойство ([* ](1.html))  
Style = iObject.GetStyle(); | Получить свойство ([**](2.html))  
iObject.SetStyle(Style); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Style(&Style); | Получить свойство  
---|---  
iObject->put_Style(Style); | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить и установить стиль текста.

2\. Стиль может быть системным из перечисления [ksTextStyleEnum](kstextstyleenum.html) или пользовательским.

Подразделы:

(отсутствуют)
