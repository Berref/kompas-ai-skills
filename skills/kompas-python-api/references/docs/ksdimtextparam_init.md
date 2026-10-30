# IniIt - Инициализировать параметры

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) > [Размерная надпись (Интерфейс ksDimTextParam) ](ksdimtextparam.html) > [ksDimTextParam - методы ](ksdimtextparam_methods.html) |  Scroll [ [ [ ](ksdimtextparam_setbitflagvalue.html "К следующему разделу")](ksdimtextparam_methods.html "На уровень выше")](ksdimtextparam_gettextarr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdimtextparam.html)

Синтаксис Automation:

BOOL Init(BOOL stringFlag);

Входной параметр:

stringFlag | \- признак типа создаваемого массива строк: TRUE - создается динамический массив строк текста типа TEXT_LINE_ARR, FALSE - создается динамический массив строк текста типа CHAR_STR_ARR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Метод обнуляет все параметры размерной надписи.

Подразделы:

(отсутствуют)
