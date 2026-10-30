# ksExecuteLibraryCommand - Выполнить команду другой библиотеки

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksexecqualitydialog.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksexecutekompaslibrarycommandex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksExecuteLibraryCommand](ksexecutelibrarycommand.html).

Синтаксис Automation:

long ksExecuteLibraryCommand (BSTR fileName, long command);

Входные параметры:

fileName | \- имя файла прикладной библиотеки,  
---|---  
command | \- номер команды из библиотеки.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если задано короткое имя файла прикладной библиотеки (без пути), то эта библиотека ищется в подпапке ..\Libs главной папки системы КОМПАС.

Подразделы:

(отсутствуют)
