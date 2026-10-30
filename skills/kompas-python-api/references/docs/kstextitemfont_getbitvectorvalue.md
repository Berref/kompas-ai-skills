# GetBitVectorValue - Получить значение битового вектора, определяющего начертание символов

[API интерфейсов. Версия 5](ag57940.html) > [Текстовый документ (Интерфейс ksDocumentTxt) ](ksdocumenttxt.html) > [ksDocumentTxt - методы ](ksdocumenttxt_methods.html) > [Интерфейсы параметров элементов текста ](ck1918891.html) > [Интерфейс ksTextItemFont ](kstextitemfont.html) > [ksTextItemFont - методы ](kstextitemfont_methods.html) |  Scroll [ [ [ ](kstextitemfont_init.html "К следующему разделу")](kstextitemfont_methods.html "На уровень выше")](kstextitemfont_methods.html "К предыдущему разделу")  
---|---  
  
Синтаксис Automation:

BOOL GetBitVectorValue (long bitVector);

Выходной параметр:

bitVector | \- значение битового флага.  
---|---  
  
[Признаки начертания текста...](textflags.html)

Возвращаемое значение:

TRUE | \- если флаги "взведены",  
---|---  
FALSE | \- если флаги "сброшены".  
  
Примечание:

В отличие от GetBitVector этот метод позволяет получить значение конкретного флага.

Подразделы:

(отсутствуют)
