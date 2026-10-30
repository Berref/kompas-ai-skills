# ksConvertLangStr - Конвертировать строку src в dst в соответствии с текущим словарем

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](ksconvertlangstrw.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksconvertlangmenu.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksConvertLangStr](kompasobject_ksconvertlangstr.html).

Синтаксис:

int ksConvertLangStr (char* src, char* dst, int dstMaxLen);

Входные параметры:

src | \- строка для конвертирования,  
---|---  
dstMaxLen | \- максимальная длина переведённой строки.  
  
Выходные параметры:

dst | \- переведенная строка.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

1\. Функция устарела, предпочтительнее использовать ksConvertLangStrEx

2\. Словарь сохраняется в файле с расширением dic. Строки файла должны иметь следующий формат:

"Вращение"="Rotation"

"Параметры"="Parameters"

...

...

"Перемещение"="Moving"

Строки файла должны быть отсортированы по алфавиту.

3\. При использовании Unicode следует использовать функцию [ksConvertLangStrW](ksconvertlangstrw.html).

Подразделы:

(отсутствуют)
