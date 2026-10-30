# StrResult - Вывести строку, соответствующую результату работы библиотеки

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](strresultw.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](returnresult.html "К предыдущему разделу")  
---|---  
  
[Пример...](returnresult_strresult_messageboxresult_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksStrResult](kompasobject_ksstrresult.html).

Синтаксис:

void StrResult ( char *str, int limit );

Входной параметр:

limit | \- ограничение по длине строки.  
---|---  
  
Возвращаемое значение:

str | \- строка сообщения, соответствующая результату работы библиотеки.  
---|---  
  
Примечание:

1\. Функция сбрасывает флаг ошибки в случае, если она не является фатальной.

2\. При использовании Unicode следует использовать функцию [StrResultW](strresultw.html).

Подразделы:

(отсутствуют)
