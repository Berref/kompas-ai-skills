# ksExecuteKompasLibraryCommand - Выполнить команду библиотеки

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksexecutekompaslibrarycommandex.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksexecutekompascommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Синтаксис Automation:

long ksExecuteKompasLibraryCommand (long libId, long command);

Входные параметры:

libId | \- уникальный номер библиотеки, полученный при выполнении [ksAttachKompasLibrary,](kompasobject_ksattachkompaslibrary.html)  
---|---  
command | \- номер команды из библиотеки.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

В отличии от функции [ksExecuteLibraryCommand](kompasobject_ksexecutelibrarycommand.html) выполняется команда у подключенной ранее библиотеки. ksExecuteLibraryCommand - подключает библиотеку, выполняет команду, если защита позволяет и отключает библиотеку.

Подразделы:

(отсутствуют)
