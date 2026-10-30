# RemoveUniqueFileW - Удалить уникальный служебный файл (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](uniquefilename.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](removeuniquefile.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksRemoveUniqueFile](kompasobject_ksremoveuniquefile.html).

Синтаксис:

void LIB_FUNC RemoveUniqueFileW (LPWSTR nameFile);

Описание:

Удалить служебный файл с уникальным именем, предварительно полученным с помощью функции [UniqueFileName](uniquefilename.html).

Возвращаемое значение:

1 | \- в случае успешного выполнения,  
---|---  
0 | \- в случае ошибки.  
  
Примечание.

При использовании ANSI следует использовать функцию [RemoveUniqueFile](removeuniquefile.html).

Подразделы:

(отсутствуют)
