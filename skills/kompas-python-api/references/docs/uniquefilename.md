# UniqueFileName - Получить уникальное имя файла

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](uniquefilenamew.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](removeuniquefilew.html "К предыдущему разделу")  
---|---  
  
[Пример...](uniquefilename_removeuniquefile_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksUniqueFileName](kompasobject_ksuniquefilename.html).

Синтаксис:

unsigned int UniqueFileName (char *buff, unsigned int sizeBuf);

Входные параметры:

buff | \- буфер для имени файла,  
---|---  
sizeBuf | \- размер буфера для имени файла.  
  
Возвращаемое значение:

длина имени файла | \- в случае удачного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

1\. Получить уникальное имя для создания служебного файла в процессе работы библиотеки и поместить его в буфер buff. Параметр sizeBuf определяет размер буфера. Имя регистрируется и запоминается системой. По окончании работы в случае, если файл с таким именем существует, он будет автоматически удален.

2\. При использовании Unicode следует использовать функцию [UniqueFileNameW](uniquefilenamew.html).

Подразделы:

(отсутствуют)
