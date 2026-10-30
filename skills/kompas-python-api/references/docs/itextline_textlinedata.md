# TextLineData - Интерфейс дополнительных данных строки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextLine ](itextline.html) > [ITextLine - свойства ](itextline_props.html) |  Scroll [ [ [ ](itextline_textlinetype.html "К следующему разделу")](itextline_props.html "На уровень выше")](itextline_textitems.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextline.html)

Тип данных: [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

TextLineData = Object.TextLineData | Получить свойство([* ](1.html))  
---|---  
TextLineData = Object.GetTextLineData () | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_TextLineData ( &TextLineData ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В зависимости от типа строки [TextLineType](itextline_textlinetype.html) возвращаются следующие значения свойства:

•ksTLText - NULL,

•ksTLVerticalText - указатель на интерфейс [IText](itext.html),

•ksTLFragment - указатель на интерфейс [IInsertionParameters](iinsertionparameters.html),

•ksTLRaster - указатель на интерфейс [IInsertionParameters](iinsertionparameters.html),

•ksTLTable - указатель на интерфейс [ITextTable](itexttable.html).

Подразделы:

(отсутствуют)
