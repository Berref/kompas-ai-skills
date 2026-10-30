# ReadLong - Ввести длинное целое число с контролем попадания значения в заданный интервал

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](readlongw.html "К следующему разделу")](enter_params_common.html "На уровень выше")](readintw.html "К предыдущему разделу")  
---|---  
  
[Пример...](readint_readlong_readdouble_readstring_example.html)

Синтаксис:

int ReadLong (char *smess, long def, long min, long max, long *value);

Входные параметры:

smess | \- строка приглашения,  
---|---  
def | \- предлагаемое значение по умолчанию,  
min,max | \- интервал возможных значений,  
R | \- результат ввода.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ReadLongW](readlongw.html).

Подразделы:

(отсутствуют)
