# ksOpenHelpFile - Открыть файл справки

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Сервисные функции ](ag92071.html) |  Scroll [ [ [ ](kompasobject_kspumpwaitingmessages.html "К следующему разделу")](ag92071.html "На уровень выше")](kompasobject_ksisenabletaskaccess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)..

Аналог данного метода при использовании API экспортных функций - [ksOpenHelpFile](ksopenhelpfile.html).

Синтаксис Automation:

BOOL ksOpenHelpFile (BSTR file, long command, long id);

Входные параметры:

file | \- полное имя файла Справки,  
---|---  
command | \- тип Справки (контекстная, по команде и т.д.),  
id | \- идентификатор страницы справки.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Синтаксис соответствует WinHelp.

2\. Функция открывает файл Справки КОМПАС.

3\. При закрытии системы окно Справки закроется автоматически.

Подразделы:

(отсутствуют)
