# ksGetRelativePathFromSystemPath - Сформировать относительный путь к файлу из заданного полного пути к файлу

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetrelativepathfromsystempathw.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetrelativepathfromfullpathw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetrelativepathfromsystempath_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetRelativePathFromSystemPath](kompasobject_ksgetrelativepathfromsystempath.html).

Синтаксис:

void ksGetRelativePathFromSystemPath (char *sourcePath,

char *destBuff,

int bufLen,

int pathType);

Входные параметры:

sourcePath | \- полный путь к файлу,  
---|---  
bufLen | \- длина отведенного буфера для возвращаемого значения в символах,  
pathType | \- тип системной папки.  
  
[Типы системных папок...](foldertypes.html)

Выходные параметры:

destBuff | \- буфер для сформированного относительного пути к файлу.  
---|---  
  
Примечание.

При использовании Unicode следует использовать функцию [ksGetRelativePathFromSystemPathW](ksgetrelativepathfromsystempathw.html).

Подразделы:

(отсутствуют)
