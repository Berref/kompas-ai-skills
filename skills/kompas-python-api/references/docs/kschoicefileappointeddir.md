# ksChoiceFileAppointedDir - Выдать диалог выбора файла для чтения

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kschoicefileappointeddirw.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](kschoicefiles.html "К предыдущему разделу")  
---|---  
  
[Пример...](kschoicefileappointeddir_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksChoiceFileAppointedDir](kompasobject_kschoicefileappointeddir.html)

Синтаксис:

unsigned int ksChoiceFileAppointedDir (char *ext,

char * filter,

char * name,

unsigned int bufLen,

unsigned char preview

int typeDir);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
filter | \- фильтр поиска (0 - фильтр формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
typeDir | \- [стартовая папка](foldertypes.html).  
  
Выходные параметры:

Name | \- буфер для имени файла,  
---|---  
bufLen | \- длина отведенного буфера для name в символах.  
  
Возвращаемое значение:

требуемая длина буфера в символах | \- в случае удачного завершения,  
---|---  
NULL | \- в случае отказа от выбора.  
  
Примечание:

1\. Параметр typeDir может иметь значения:

– sptSYSTEM_FILES - 0 - открывается папка системных файлов,

– sptLIBS_FILES - 1 - открывается папка файлов библиотек. Во всех остальных случаях открывается текущая папка.

2\. Если размер отведенного буфера bufLen меньше требуемой длины - name не заполняется. В этом случае имя файла можно получить функцией [GetRightFileName](getrightfilename.html).

3\. При использовании Unicode следует использовать функцию [ksChoiceFileAppointedDirW](kschoicefileappointeddirw.html).

Подразделы:

(отсутствуют)
