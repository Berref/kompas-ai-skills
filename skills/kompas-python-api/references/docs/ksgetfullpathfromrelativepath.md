# ksGetFullPathFromRelativePath - Сформировать полный путь к файлу из заданного пути к задающему файлу и относительного пути к файлу

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetfullpathfromrelativepathw.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetrecovermode.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetfullpathfromrelativepath_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetFullPathFromRelativePath](kompasobject_ksgetfullpathfromrelativepath.html).

Синтаксис:

void ksGetFullPathFromRelativePath (char *mainFilePath,

char *relativePath,

char *destBuff,

int bufLen);

Входные параметры:

mainFilePath | \- полный путь к задающему файлу,  
---|---  
relativePath | \- относительный путь к требуемому файлу (без общей с задающим файлом части пути),  
bufLen | \- длина отведенного буфера для возвращаемого значения в символах.  
  
Выходные параметры:

destBuff | \- буфер для сформированного относительного пути к файлу.  
---|---  
  
Примечание.

При использовании Unicode следует использовать функцию [ksGetFullPathFromRelativePathW](ksgetfullpathfromrelativepathw.html).

Подразделы:

(отсутствуют)
