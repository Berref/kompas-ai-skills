# Интерфейс ITextLine

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) |  Scroll [ [ [ ](itextline_props.html "К следующему разделу")](bb2377713.html "На уровень выше")](itextitem_update.html "К предыдущему разделу")  
---|---  
  
Интерфейс строки текста.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ITextLine](itextline.html)

Описание:

Интерфейс позволяет получить и отредактировать строку текста.

Строка может иметь стиль, отличающийся от стиля текста. Стиль может быть системным из перечисления [ksTextStyleEnum](kstextstyleenum.html) или пользовательским.

Строки текста состоят из компонентов, которые представлены интерфейсом [ITextItem](itextitem.html).

Компонент - это часть строки, отличающаяся типом [ksTextItemEnum](kstextitemenum.html) и параметрами шрифта.

Примечание:

Данный интерфейс можно получить через интерфейс [IText](itext.html), используя свойство [IText::TextLine](itext_textline.html).

Подразделы:

[ITextLine - свойства ](itextline_props.html)

[ITextLine - методы ](itextline_methods.html)
