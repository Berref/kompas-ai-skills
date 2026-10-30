# Sign - Номер условного значка перед номиналом

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IDimensionText ](idimensiontext.html) > [IDimensionText - свойства ](idimensiontext_props.html) |  Scroll [ [ [ ](idimensiontext_signfont.html "К следующему разделу")](idimensiontext_props.html "На уровень выше")](idimensiontext_rectangle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idimensiontext.html)

Тип данных: long

Значения свойства:

0 | \- нет значка,  
---|---  
1 | \- диаметр,  
2 | \- квадрат,  
3 | \- К - радиус,  
4 | \- М - метрическая резьба,  
>4 | \- символ из любого шрифта, задаваемого через свойство [IDimensionText::SignFont](idimensiontext_signfont.html) (по умолчанию 'Symbol type A').  
  
Синтаксис Automation:

Sign = Object.Sign | Получить свойство([* ](1.html))  
---|---  
Object.Sign = Sign | Установить свойство ([* ](1.html))  
Sign = Object.GetSign() | Получить свойство ([**](2.html))  
Object.SetSign( Sign ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Sign( &Sign ) | Получить свойство([* ](1.html))  
---|---  
Object.put_Sign( Sign ) | Установить свойство ([* ](1.html))  
  
Примечание:

Позволяет получить установить номер условного значка перед номиналом.

Подразделы:

(отсутствуют)
