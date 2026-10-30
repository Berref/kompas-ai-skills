# ksSaveFileW - Выдать диалог выбора файла для сохранения (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kssetrecovermode.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](kssavefile.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksSaveFile](kompasobject_kssavefile.html).

Синтаксис:

unsigned int LIB_FUNC ksSaveFile (LPWSTR ext,

LPWSTR oldName,

LPWSTR filter,

LPWSTR name,

unsigned int bufLen,

unsigned char preview);

Входные параметры:

Ext | \- расширение имени файла,  
---|---  
oldName | \- имя файла по умолчанию,  
Filter | \- фильтр поиска (0 - формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Выходные параметры:

Name | \- буфер для имени файла,  
---|---  
bufLen | \- длина отведенного буфера для name в символах.  
  
Возвращаемое значение:

| \- требуемая длина буфера в символах.  
---|---  
  
Описание:

Если размер отведенного буфера меньше требуемой длины bufLen - имя файла не заполняется. В этом случае имя файла можно получить функцией [GetRightFileName](getrightfilename.html).

Примечание.

При использовании ANSI следует использовать функцию [ksSaveFile](kssavefile.html).

Подразделы:

(отсутствуют)
