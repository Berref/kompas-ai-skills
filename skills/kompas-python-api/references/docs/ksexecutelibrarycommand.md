# ksExecuteLibraryCommand - Выполнить команду другой библиотеки

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](ksexecutelibrarycommandw.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksconvertlangwindowexw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksexecutelibrarycommand_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksExecuteLibraryCommand](kompasobject_ksexecutelibrarycommand.html).

Синтаксис:

int ksExecuteLibraryCommand (char *fileName, int command);

Входные параметры:

fileName | \- имя файла прикладной библиотеки,  
---|---  
command | \- номер команды из библиотеки.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если задано короткое имя файла прикладной библиотеки (без пути), то эта библиотека ищется в подпапке …\Libs главной папки КОМПАС.

2\. При использовании Unicode следует использовать функцию [ksExecuteLibraryCommandW](ksexecutelibrarycommandw.html).

Подразделы:

(отсутствуют)
