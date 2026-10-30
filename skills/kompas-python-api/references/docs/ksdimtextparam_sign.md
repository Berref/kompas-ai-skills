# sign - Тип условного значка перед номиналом размера

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) > [Размерная надпись (Интерфейс ksDimTextParam) ](ksdimtextparam.html) > [ksDimTextParam - свойства ](ksdimtextparam_props.html) |  Scroll [ [ [ ](ksdimtextparam_stringflag.html "К следующему разделу")](ksdimtextparam_props.html "На уровень выше")](ksdimtextparam_bitflag.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdimtextparam.html)

Тип данных:long.

Значения свойства:

0 | \- нет значка,  
---|---  
1 | \- диаметр,  
2 | \- квадрат,  
3 | \- радиус,  
>3 | \- номер значка из шрифта "Symbol type A",  
4 | \- М - метрическая резьба,  
210 | \- символ сферы.  
  
Синтаксис Automation:

sign = iDimText.sign | Получить свойство ([* ](1.html))  
---|---  
iDimText.sign = sign | Установить свойство ([* ](1.html))  
sign = iDimText.GetSign() | Получить свойство ([**](2.html))  
iDimText.SetSign( sign ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
