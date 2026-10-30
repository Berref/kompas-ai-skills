# ksGetRelativePathFromFullPathW - Сформировать относительный путь к файлу из полного пути к задающему файлу и полного пути к файлу (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetrelativepathfromsystempath.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetrelativepathfromfullpath.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetRelativePathFromFullPath](kompasobject_ksgetrelativepathfromfullpath.html).

Синтаксис:

void LIB_FUNC ksGetRelativePathFromFullPath (LPWSTR mainFilePath,

LPWSTR sourcePath,

LPWSTR destBuff,

int bufLen);

Входные параметры:

mainFilePath | \- полный путь к задающему файлу,  
---|---  
sourcePath | \- полный путь к требуемому файлу,  
bufLen | \- длина отведенного буфера для возвращаемого значения в символах.  
  
Возвращаемое значение:

destBuff | \- буфер для сформированного относительного пути к файлу.  
---|---  
  
Примечание.

При использовании ANSI следует использовать функцию [ksGetRelativePathFromFullPath](ksgetrelativepathfromfullpath.html).

Подразделы:

(отсутствуют)
