# SizeFactor - Размерный коэффициент текста для дроби, отклонений, выражения типа суммы

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextItem ](itextitem.html) > [ITextItem - свойства ](itextitem_props.html) |  Scroll [ [ [ ](itextitem_str.html "К следующему разделу")](itextitem_props.html "На уровень выше")](itextitem_number.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextitem.html)

Тип данных: из перечисления [ksTextSizeEnum](kstextsizeenum.html)

Синтаксис Automation:

SizeFactor = iObject.SizeFactor | Получить свойство([* ](1.html))  
---|---  
iObject.SizeFactor = SizeFactor | Установить свойство ([* ](1.html))  
SizeFactor = iObject.GetSizeFactor() | Получить свойство ([**](2.html))  
iObject.SetSizeFactor(SizeFactor) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SizeFactor(&SizeFactor) | Получить свойство  
---|---  
iObject->put_SizeFactor(SizeFactor) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить размерный коэффициент текста для дроби, отклонений, выражения типа суммы.

2\. Это свойство используется для компонент типа ksTItNumerator, ksTItDenominator, ksTItSBase из перечисления [ksTextItemEnum](kstextitemenum.html).

3\. Размерный коэффициент текста используется для задания размера текста дроби, отклонений, для выражения типа суммы

Для дроби и отклонений используются:

ksTextNormal | \- полной высоты,  
---|---  
ksTextMiddle | \- в 1.5 раза меньше,  
ksTextSmall | \- в 2 раза меньше.  
  
Для выражения типа суммы используются:

ksTextNormal | \- нормальной высоты,  
---|---  
ksTextBig | \- в 1.5 раза больше.  
  
Подразделы:

(отсутствуют)
