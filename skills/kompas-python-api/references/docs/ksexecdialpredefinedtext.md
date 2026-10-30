# ksExecDialPredefinedText - Получить предопределенный текст из файла текстовых шаблонов

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](ksexecdialpredefinedtextw.html "К следующему разделу")](enter_params_common.html "На уровень выше")](getvalidator.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksExecDialPredefinedText](kompasobject_ksexecdialpredefinedtext.html).

Синтаксис:

int ksExecDialPredefinedText (void *HWindow, char * str, int sizeStr);

Входные параметры:

HWindow | \- несущее окно,  
---|---  
sizeStr | \- размер строки str.  
  
Выходной параметр:

str | \- строка-буфер, в которую будет помещен текст.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Все строки складываются в одну строку str с переводом строки "\n".

2\. При использовании Unicode следует использовать функцию [ksExecDialPredefinedTextW](ksexecdialpredefinedtextw.html).

Подразделы:

(отсутствуют)
