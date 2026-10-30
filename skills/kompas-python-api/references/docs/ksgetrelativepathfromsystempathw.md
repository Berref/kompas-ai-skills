# ksGetRelativePathFromSystemPathW - Сформировать относительный путь к файлу из заданного полного пути к файлу (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kslockfilecache.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetrelativepathfromsystempath.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetRelativePathFromSystemPath](kompasobject_ksgetrelativepathfromsystempath.html).

Синтаксис:

void LIB_FUNC ksGetRelativePathFromSystemPath (LPWSTR sourcePath,

LPWSTR destBuff,

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

При использовании ANSI следует использовать функцию [ksGetRelativePathFromSystemPath](ksgetrelativepathfromsystempath.html).

Подразделы:

(отсутствуют)
