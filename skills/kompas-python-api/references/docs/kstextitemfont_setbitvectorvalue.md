# SetBitVectorValue - "Взвести" или "сбросить" значение битового вектора

[API интерфейсов. Версия 5](ag57940.html) > [Текстовый документ (Интерфейс ksDocumentTxt) ](ksdocumenttxt.html) > [ksDocumentTxt - методы ](ksdocumenttxt_methods.html) > [Интерфейсы параметров элементов текста ](ck1918891.html) > [Интерфейс ksTextItemFont ](kstextitemfont.html) > [ksTextItemFont - методы ](kstextitemfont_methods.html) |  Scroll [ [ [ ](kstextitemparam.html "К следующему разделу")](kstextitemfont_methods.html "На уровень выше")](kstextitemfont_init.html "К предыдущему разделу")  
---|---  
  
Синтаксис Automation:

BOOL SetBitVectorValue (long bitVector, BOOL state);

Входные параметры:

bitVector | \- значение битового вектора,  
---|---  
state | \- состояние вектора: TRUE - включить, FALSE - выключить.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

В отличие от SetBitVector этот метод позволяет установить значение конкретного флага.

Подразделы:

(отсутствуют)
