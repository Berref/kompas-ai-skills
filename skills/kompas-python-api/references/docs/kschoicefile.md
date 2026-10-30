# ksChoiceFile - Выдать диалог выбора файла для чтения

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kschoicefilew.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetselectedembodimentadditionalnumberw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksreadfragmenttogroup_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksChoiceFile](kompasobject_kschoicefile.html)

Синтаксис:

unsigned int ksChoiceFile (char *ext,

char * filter,

char * name,

unsigned int bufLen,

unsigned char preview);

Входные параметры:

Ext | \- расширение имени файла,  
---|---  
Filter | \- фильтр поиска (0 - формируется автоматически),  
Preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Выходные параметры:

Name | \- буфер для имени файла,  
---|---  
bufLen | \- длина отведенного буфера для name в символах.  
  
Возвращаемое значение:

требуемая длина буфера в символах | \- в случае удачного завершения,  
---|---  
NULL | \- в случае отказа от выбора.  
  
Примечание:

1\. Если размер отведенного буфера bufLen меньше требуемой длины, то имя файла не заполняется. В этом случае имя файла можно получить функцией [GetRightFileName](getrightfilename.html).

2\. При использовании Unicode следует использовать функцию [ksChoiceFileW](kschoicefilew.html).

Подразделы:

(отсутствуют)
