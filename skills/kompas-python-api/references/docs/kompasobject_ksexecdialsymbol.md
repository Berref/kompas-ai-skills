# ksExecDialSymbol - Вызов диалога Вставка символа

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksexecdialspecialsymbol.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksexecdialpredefinedtextex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций -[ ksExecDialSymbol](ksexecdialsymbol.html).

Синтаксис Automation:

BSTR ksExecDialSymbol( long HWindow, long * symb, BSTR font );

Входные параметры:

HWindow | \- дескриптор окна,  
---|---  
symb | \- номер символа, на котором будет стоять курсор,  
font | \- имя шрифта в диалоге.  
  
Выходные параметры:

symb | \- номер выбранного символа.  
---|---  
  
Возвращаемое значение:

Имя шрифта | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи или закрытии диалога по отмене.  
  
Подразделы:

(отсутствуют)
