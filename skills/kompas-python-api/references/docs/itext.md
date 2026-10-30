# Интерфейс IText

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) |  Scroll [ [ [ ](itext_props.html "К следующему разделу")](bb2377713.html "На уровень выше")](itabulator_position.html "К предыдущему разделу")  
---|---  
  
Интерфейс текста для работы с аннотационными объектами.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IText](itext.html)

Описание:

Интерфейс позволяет получить и отредактировать текст.

Текст имеет стиль. Стиль может быть системным из перечисления [ksTextStyleEnum](kstextstyleenum.html) или пользовательским.

Состоит из строк, которые представлены интерфейсом [ITextLine](itextline.html).

Строки текста состоят из компонент, которые представлены интерфейсом [ITextItem](itextitem.html).

Компонент текста - это часть строки, отличающаяся типом [ksTextItemEnum](kstextitemenum.html) и параметрами шрифта.

Примечание:

Данный интерфейс можно получить как дополнительный через интерфейс [IDrawingText](idrawingtext.html) посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) или как самостоятельный объект у аннотационных объектов, имеющих тексты (линия-выноска, размер и т.п.).

Подразделы:

[IText - свойства ](itext_props.html)

[IText - методы ](itext_methods.html)
