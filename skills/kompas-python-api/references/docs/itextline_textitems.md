# TextItems - Массив SAFEARRAY компонентов строки текста

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextLine ](itextline.html) > [ITextLine - свойства ](itextline_props.html) |  Scroll [ [ [ ](itextline_textlinedata.html "К следующему разделу")](itextline_props.html "На уровень выше")](itextline_textitem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextline.html)

Тип данных: VARIANT ( VT_ARRAY|VT_DISPATCH )

Синтаксис Automation:

TextItems = iObject.TextItems; | Получить свойство([* ](1.html))  
---|---  
TextItems = iObject.GetTextItems (); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_TextItems (&TextItems); | Получить свойство  
---|---  
  
Примечание:

Свойство позволяет получить массив SAFEARRAY компонентов строки текста. Это массив интерфейсов [ITextItem](itextitem.html). Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
