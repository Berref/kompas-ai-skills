# RemoveUniqueFile - Удалить уникальный служебный файл

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](removeuniquefilew.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](kssetrecovermode.html "К предыдущему разделу")  
---|---  
  
[Пример...](uniquefilename_removeuniquefile_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksRemoveUniqueFile](kompasobject_ksremoveuniquefile.html).

Синтаксис:

void RemoveUniqueFile (char *nameFile);

Описание:

Удалить служебный файл с уникальным именем, предварительно полученным с помощью функции [UniqueFileName](uniquefilename.html).

Возвращаемое значение:

1 | \- в случае успешного выполнения,  
---|---  
0 | \- в случае ошибки.  
  
Примечание.

При использовании Unicode следует использовать функцию [RemoveUniqueFileW](removeuniquefilew.html).

Подразделы:

(отсутствуют)
