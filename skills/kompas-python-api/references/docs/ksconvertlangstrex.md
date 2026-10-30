# ksConvertLangStrEx - Конвертировать строку с идентификатором в соответствии с текущим словарем

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](ksconvertlangstrexw.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksconvertlangstrw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksConvertLangStrEx](kompasobject_ksconvertlangstrex.html).

Синтаксис:

int ksConvertLangStrEx (HINSTANCE hInstance,

unsigned int strID,

char* dst,

int dstMaxLen );

Входные параметры:

hInstance | \- HINSTANCE модуля, в котором находится переводимая строка,  
---|---  
strID | \- идентификатор строки,  
dst | \- результат - переведенная строка,  
dstMaxLen | \- максимально допустимая длина строки.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksConvertLangStrExW](ksconvertlangstrexw.html).

Подразделы:

(отсутствуют)
