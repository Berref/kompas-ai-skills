# ChoiceFile - Показать диалог и выбрать в нем имя файла для чтения

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](fullfilename.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](work_with_files_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](createattrtype_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksChoiceFile](kompasobject_kschoicefile.html).

Синтаксис:

unsigned int ChoiceFile (char *ext, char *filtr, char *name, unsigned int sizeBuf);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
filtr | \- фильтр поиска (0 - формируется автоматически),  
sizeBuf | \- размер буфера для имени файла.  
  
Выходные параметры:

name | \- буфер для имени файла.  
---|---  
  
Возвращаемое значение:

длина имени файла | \- в случае удачного завершения,  
---|---  
NULL | \- в случае отказа от выбора.  
  
Подразделы:

(отсутствуют)
