# ErrorW - Выдать сообщение об ошибке (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](filepreviewfunccallback.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](error.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksError](kompasobject_kserror.html).

Синтаксис:

void LIB_FUNC ErrorW( LPWSTR s );

Входной параметр:

s | \- строка с текстом сообщения.  
---|---  
  
Примечание::

1\. После вывода сообщения будет ожидаться нажатие любой клавиши.

2\. При использовании ANSI следует использовать функцию [Error](error.html).

Подразделы:

(отсутствуют)
