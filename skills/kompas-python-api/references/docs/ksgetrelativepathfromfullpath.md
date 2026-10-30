# ksGetRelativePathFromFullPath - Сформировать относительный путь к файлу из полного пути к задающему файлу и полного пути к файлу

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetrelativepathfromfullpathw.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetfullpathfromrelativepathw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetrelativepathfromfullpath_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetRelativePathFromFullPath](kompasobject_ksgetrelativepathfromfullpath.html).

Синтаксис:

void ksGetRelativePathFromFullPath (char *mainFilePath,

char *sourcePath,

char *destBuff,

int bufLen);

Входные параметры:

mainFilePath | \- полный путь к задающему файлу,  
---|---  
sourcePath | \- полный путь к требуемому файлу,  
bufLen | \- длина отведенного буфера для возвращаемого значения в символах.  
  
Выходные параметры:

destBuff | \- буфер для сформированного относительного пути к файлу.  
---|---  
  
Примечание.

При использовании Unicode следует использовать функцию [ksGetRelativePathFromFullPathW](ksgetrelativepathfromfullpathw.html).

Подразделы:

(отсутствуют)
