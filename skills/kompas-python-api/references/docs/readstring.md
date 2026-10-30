# ReadString - Ввести строку заданной длины

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](readstringw.html "К следующему разделу")](enter_params_common.html "На уровень выше")](readlongw.html "К предыдущему разделу")  
---|---  
  
[Пример...](readint_readlong_readdouble_readstring_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksReadString](kompasobject_ksreadstring.html).

Синтаксис:

int ReadString(char *smess, char *str, int maxlen);

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

При использовании Unicode следует использовать функцию [ReadStringW](readstringw.html).

Подразделы:

(отсутствуют)
