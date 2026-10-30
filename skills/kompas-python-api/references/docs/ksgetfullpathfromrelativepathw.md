# ksGetFullPathFromRelativePathW - Сформировать полный путь к файлу из заданного пути к задающему файлу и относительного пути к файлу (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetrelativepathfromfullpath.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetfullpathfromrelativepath.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetFullPathFromRelativePath](kompasobject_ksgetfullpathfromrelativepath.html).

Синтаксис:

void LIB_FUNC ksGetFullPathFromRelativePathW (LPWSTR mainFilePath,

LPWSTR relativePath,

LPWSTR destBuff,

int bufLen);

Входные параметры:

mainFilePath | \- полный путь к задающему файлу,  
---|---  
relativePath | \- относительный путь к требуемому файлу (без общей с задающим файлом части пути),  
bufLen | \- размер буфера для возвращаемого значения.  
  
Выходные параметры:

destBuff | \- буфер для сформированного относительного пути к файлу.  
---|---  
  
Примечание.

При использовании ANSI следует использовать функцию [ksGetFullPathFromRelativePath](ksgetfullpathfromrelativepath.html).

Подразделы:

(отсутствуют)
