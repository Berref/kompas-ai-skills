# ReadStringW - Ввести строку заданной длины (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](screen_output_fncts_common.html "К следующему разделу")](enter_params_common.html "На уровень выше")](readstring.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksReadString](kompasobject_ksreadstring.html).

Синтаксис:

int LIB_FUNC ReadString(LPWSTR smess, char *str, int maxlen);

Входные параметры:

smess | \- строка приглашения,  
---|---  
maxlen | \- максимально допустимая длина строки,  
str | \- результат ввода.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [ReadString](readstring.html).

Подразделы:

(отсутствуют)
