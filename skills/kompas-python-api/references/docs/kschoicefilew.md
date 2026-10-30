# ksChoiceFileW - Выдать диалог выбора файла для чтения (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kschoicefiles.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](kschoicefile.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksChoiceFile](kompasobject_kschoicefile.html)

Синтаксис:

unsigned int LIB_FUNK ksChoiceFileW (LPWSTR ext,

LPWSTR filter,

LPWSTR name,

unsigned int bufLen,

unsigned char preview);

Входные параметры:

Ext | \- расширение имени файла,  
---|---  
Filter | \- фильтр поиска (0 - формируется автоматически),  
Preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Выходные параметры:

name | \- буфер для имени файла,  
---|---  
bufLen | \- длина отведенного буфера для name в символах.  
  
Возвращаемое значение:

требуемая длина буфера в символах | \- в случае удачного завершения,  
---|---  
NULL | \- в случае отказа от выбора.  
  
Примечание:

1\. Если размер отведенного буфера bufLen меньше требуемой длины - имя файла не заполняется. В этом случае имя файла можно получить функцией [GetRightFileName](getrightfilename.html).

2\. При использовании ANSI следует использовать функцию [ksChoiceFile](kschoicefile.html).

Подразделы:

(отсутствуют)
