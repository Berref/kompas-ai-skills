# ksTextLine - Задать компоненту строки текста или строку текста полностью

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Основная надпись (Интерфейс ksStamp) ](ksstamp.html) > [ksStamp - методы ](ksstamp_methods.html) |  Scroll [ [ [ ](ksobject2dnotifyresult.html "К следующему разделу")](ksstamp_methods.html "На уровень выше")](ksstamp_kssettextlinealign.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksstamp.html)

Аналог данного метода при использовании API экспортных функций - [TextLine](textline.html).

Синтаксис Automation:

ksTextLine(LPDISPATCH textItem);

Входной параметр:

textItem | \- указатель на интерфейс [ksTextItemParam](kstextitemparam.html) для компоненты текста или указатель на интерфейс [ksTextLineParam](kstextlineparam.html) для всей строки.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Данная функция предназначена для задания сложно-структурированного текста, отдельные компоненты которого имеют различные параметры.

Подразделы:

(отсутствуют)
