# ksChoiceFiles - Выдать диалог выбора файлов для чтения

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kschoicefileappointeddir.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](kschoicefilew.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssavefile_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksChoiceFiles](kompasobject_kschoicefiles.html)

Синтаксис:

int ksChoiceFile (char * ext,

char * filter,

reference p,

unsigned char preview);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
filter | \- фильтр поиска (0 - формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Выходной параметр:

p | \- указатель на динамический массив строк CHAR_STR_ARR или CHAR_STR_ARR_W.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksChoiceFilesW](kschoicefilesw.html).

Подразделы:

(отсутствуют)
