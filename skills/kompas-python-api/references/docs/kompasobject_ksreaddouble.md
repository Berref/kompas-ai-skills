# ksReadDouble - Запросить ввод вещественного числа с контролем попадания значения в заданный интервал

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksreadint.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksprintpreviewwindow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ReadDouble](readdouble.html).

Синтаксис Automation:

long ksReadDouble (BSTR mess,

double defValue,

double min,

double max,

double* value);

Входные параметры:

mess | \- строка приглашения,  
---|---  
defValue | \- предлагаемое значение по умолчанию,  
min, max | \- интервал возможных значений.  
  
Выходной параметр:

value | \- результат ввода.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
