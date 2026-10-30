# ksGetFullPathFromSystemPath - Сформировать полный путь к файлу из заданного относительного пути к файлу и системного пути установленного типа

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetfullpathfromsystempathw.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetcurrentdocument.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetfullpathfromsystempath_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetFullPathFromSystemPath](kompasobject_ksgetfullpathfromsystempath.html).

Синтаксис:

void ksGetFullPathFromSystemPath (char *relativePath,

char *destBuff,

int bufLen,

int pathType);

Входные параметры:

relativePath | \- относительный путь к файлу,  
---|---  
pathType | \- тип системной папки,  
bufLen | \- длина отведенного буфера для возвращаемого значения в символах.  
  
[Типы системных папок...](foldertypes.html)

Выходные параметры:

destBuff | \- буфер для сформированного полного пути к файлу.  
---|---  
  
Примечание.

При использовании Unicode следует использовать функцию [ksGetFullPathFromSystemPathW](ksgetfullpathfromsystempathw.html).

Подразделы:

(отсутствуют)
