# Error - Выдать сообщение об ошибке

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](errorw.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](drawslide.html "К предыдущему разделу")  
---|---  
  
[Пример...](message_error_pause_yesno_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksError](kompasobject_kserror.html).

Синтаксис:

void Error ( char * s );

Входной параметр:

s | \- строка с текстом сообщения.  
---|---  
  
Примечание::

1\. После вывода сообщения будет ожидаться нажатие любой клавиши.

2\. При использовании Unicode следует использовать функцию [ErrorW](errorw.html).

Подразделы:

(отсутствуют)
