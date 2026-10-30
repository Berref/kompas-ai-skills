# ksFileNameCompare - Сравнить имена файлов

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksfilenamecomparew.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksclearrecovererror.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int LIB_FUNC ksFileNameCompare( char * fileName1, char * fileName2 );

Входные параметры:

fileName1, fileName2 | \- сравниваемые имена файлов.  
---|---  
  
Возвращаемое значение:

1 | \- имена не совпадают,  
---|---  
0 | \- имена совпадают.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksFileNameCompareW](ksfilenamecomparew.html).

Подразделы:

(отсутствуют)
