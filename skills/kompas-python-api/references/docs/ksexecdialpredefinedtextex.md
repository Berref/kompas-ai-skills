# ksExecDialPredefinedTextEx - Получить предопределенный текст из файла текстовых шаблонов

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](ksexecdialsymbol.html "К следующему разделу")](enter_params_common.html "На уровень выше")](ksexecdialpredefinedtextw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksExecDialPredefinedText](kompasobject_ksexecdialpredefinedtext.html).

Синтаксис:

reference ksExecDialPredefinedTextEx (void *HWindow);

Входные параметры:

HWindow | \- дескриптор окна.  
---|---  
  
Возвращаемое значение:

указатель на интерфейс [ksDynamicArray](ksdynamicarray.html) массива строк, тип массива - TEXT_LINE_ARR. | \- в случае успеха,  
---|---  
NULL | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
