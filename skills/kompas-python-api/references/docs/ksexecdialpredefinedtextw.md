# ksExecDialPredefinedTextW - Получить предопределенный текст из файла текстовых шаблонов (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](ksexecdialpredefinedtextex.html "К следующему разделу")](enter_params_common.html "На уровень выше")](ksexecdialpredefinedtext.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksExecDialPredefinedText](kompasobject_ksexecdialpredefinedtext.html).

Синтаксис:

int LIB_FUNC ksExecDialPredefinedTextW (void *HWindow, LPWSTR str, int sizeStr);

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

2\. При использовании ANSI следует использовать функцию [ksExecDialPredefinedText](ksexecdialpredefinedtext.html).

Подразделы:

(отсутствуют)
