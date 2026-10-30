# ksSaveFile - Выдать диалог выбора файла для сохранения

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kssavefilew.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](kslockfilecache.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssavefile_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksSaveFile](kompasobject_kssavefile.html).

Синтаксис:

unsigned int ksSaveFile (char * ext,

char * oldName,

char * filter,

char * name,

unsigned int bufLen,

unsigned char preview);

Входные параметры:

Ext | \- расширение имени файла,  
---|---  
oldName | \- имя файла по умолчанию,  
Filter | \- фильтр поиска (0 - формируется автоматически),  
Preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Выходные параметры:

Name | \- буфер для имени файла,  
---|---  
bufLen | \- длина отведенного буфера для name в символах.  
  
Возвращаемое значение:

| \- требуемая длина буфера в символах.  
---|---  
  
Описание:

Если размер отведенного буфера меньше требуемой длины bufLen, имя файла не заполняется. В этом случае имя файла можно получить функцией [GetRightFileName](getrightfilename.html).

Примечание.

При использовании Unicode следует использовать функцию [ksSaveFileW](kssavefilew.html).

Подразделы:

(отсутствуют)
