# ksOpenTextFileEx - Открыть текстовый файл, в котором хранятся SQL запросы

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](ksopentextfileexw.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](isodbcokey.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksCloseTextFile](ksdatabaseobject_ksclosetextfile.html).

Синтаксис:

reference ksOpenTextFileEx( char * fileName, int textFileType );

Входные параметры:

fileName | \- имя файла,  
---|---  
textFileType | \- тип текстового файла: 0 - текстовая база данных 1 - простой текстовый файл 2 - текстовый файл с комментариями (комментарии не выдаются).  
  
Примечание:

Комментарии могут иметь следующие варианты формата:

/*

многострочный

комментарий

*/

// однострочный комментарий

Подразделы:

(отсутствуют)
