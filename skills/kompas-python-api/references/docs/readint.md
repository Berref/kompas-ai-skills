# ReadInt - Ввести целое число с контролем попадания значения в заданный интервал

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](readintw.html "К следующему разделу")](enter_params_common.html "На уровень выше")](readdoublew.html "К предыдущему разделу")  
---|---  
  
[Пример...](readint_readlong_readdouble_readstring_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksReadInt](kompasobject_ksreadint.html).

Синтаксис:

int ReadInt (char *smess, int def, int min, int max, int *value);

Входные параметры:

smess | \- строка приглашения,  
---|---  
def | \- значение, предлагаемое по умолчанию,  
min,max | \- интервал возможных значений,  
value | \- результат ввода.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ReadIntW](readintw.html).

Подразделы:

(отсутствуют)
