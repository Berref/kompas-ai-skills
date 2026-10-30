# TextPointer - Указатель от текста к дуге

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IArcDimension ](iarcdimension.html) > [IArcDimension - свойства ](iarcdimension_props.html) |  Scroll [ [ [ ](iarcdimension_xc.html "К следующему разделу")](iarcdimension_props.html "На уровень выше")](iarcdimension_shelfy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarcdimension.html)

Тип данных: BOOL

Значения свойства:

true | \- отрисовать указатель;  
---|---  
false | \- не отрисовывать указатель.  
  
Синтаксис Automation:

TextPointer = Object.TextPointer | Получить свойство([* ](1.html))  
---|---  
Object.TextPointer = TextPointer | Установить свойство ([* ](1.html))  
TextPointer = Object.GetTextPointer() | Получить свойство ([**](2.html))  
Object.SetTextPointer( TextPointer ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_TextPointer( &TextPointer ) | Получить свойство([* ](1.html))  
---|---  
Object.put_TextPointer( TextPointer ) | Установить свойство ([* ](1.html))  
  
Примечание:

Свойство позволяет включить соединить указателем дугу и текст, относящегося к ней размера. Это может потребоваться, например, при простановке размеров концентрических дуг с одинаковым раствором и начальным углом.

Подразделы:

(отсутствуют)
