# ksExecuteKompasLibraryCommandEx - Выполнить команду библиотеки

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksexecutelibrarycommand.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksexecutekompaslibrarycommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Синтаксис Automation:

long ksExecuteKompasLibraryCommandEx (long libId, long command, LPDISPATCH external);

Входные параметры:

libId | \- уникальный номер библиотеки, полученный при выполнении [ksAttachKompasLibrary,](kompasobject_ksattachkompaslibrary.html)  
---|---  
command | \- номер команды из библиотеки,  
external | \- указатель на интерфейс связи между библиотеками (приложениями).  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
