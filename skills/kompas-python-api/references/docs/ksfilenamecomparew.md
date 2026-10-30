# ksFileNameCompareW - Сравнить имена файлов (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetcurrentdocument.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksfilenamecompare.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int LIB_FUNC ksFileNameCompareW( LPWSTR fileName1, LPWSTR fileName2 );

Входные параметры:

fileName1, fileName2 | \- сравниваемые имена файлов.  
---|---  
  
Возвращаемое значение:

1 | \- имена не совпадают,  
---|---  
0 | \- имена совпадают.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksFileNameCompare](ksfilenamecompare.html).

Подразделы:

(отсутствуют)
