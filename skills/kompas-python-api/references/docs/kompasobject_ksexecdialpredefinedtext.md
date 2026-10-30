# ksExecDialPredefinedText - Получить предопределенный текст из файла текстовых шаблонов (с расширением tdp)

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksexecdialpredefinedtextex.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksedittextline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksExecDialPredefinedText](ksexecdialpredefinedtext.html).

Синтаксис Automation:

BSTR ksExecDialPredefinedText (long HWindow, long FAR* res);

Входной параметр:

Hwindow | \- несущее окно.  
---|---  
  
Выходной параметр:

res | \- результат работы функции: 1 - в случае успеха, 0 - в случае неудачи.  
---|---  
  
Возвращаемое значение:

указатель на интерфейс [ksDynamicArray](ksdynamicarray.html) массива строк, тип массива - TEXT_LINE_ARR. | \- в случае успеха,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Метод возвращает все строки. Они складываются в одну с переводом строки "\n"

Подразделы:

(отсутствуют)
