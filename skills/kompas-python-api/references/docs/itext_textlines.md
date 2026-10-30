# TextLines - Массив SAFEARRAY строк текста

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IText ](itext.html) > [IText - свойства ](itext_props.html) |  Scroll [ [ [ ](itext_methods.html "К следующему разделу")](itext_props.html "На уровень выше")](itext_textline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itext.html)

Тип данных: VARIANT ( VT_ARRAY|VT_DISPATCH )

Синтаксис Automation:

TextLines = iObject.TextLines; | Получить свойство([* ](1.html))  
---|---  
TextLines = iObject.GetTextLines(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_TextLines(&TextLines); | Получить свойство  
---|---  
  
Примечание:

Свойство позволяет получить массив SAFEARRAY строк текста. Это массив интерфейсов [ITextLine](itextline.html). Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
