# SignFont - Шрифт для условного значка перед номиналом

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IDimensionText ](idimensiontext.html) > [IDimensionText - свойства ](idimensiontext_props.html) |  Scroll [ [ [ ](idimensiontext_style.html "К следующему разделу")](idimensiontext_props.html "На уровень выше")](idimensiontext_sign.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idimensiontext.html)

Тип данных: BSTR

Синтаксис Automation:

SignFont = Object.SignFont | Получить свойство([* ](1.html))  
---|---  
Object.SignFont = SignFont | Установить свойство ([* ](1.html))  
SignFont = Object.GetSignFont() | Получить свойство ([**](2.html))  
Object.SetSignFont( SignFont ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SignFont( &SignFont ) | Получить свойство([* ](1.html))  
---|---  
Object.put_SignFont( SignFont ) | Установить свойство ([* ](1.html))  
  
Примечание:

1\. Позволяет получить установить шрифт для условного значка перед номиналом.

2\. Используется для символов с номером [IDimensionText::Sign](idimensiontext_sign.html)> 4.

3\. По умолчанию используется шрифт Symbol type A.

Подразделы:

(отсутствуют)
