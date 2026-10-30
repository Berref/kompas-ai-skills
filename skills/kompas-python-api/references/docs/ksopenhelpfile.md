# ksOpenHelpFile - Открыть файл справки

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](ksopenhelpfilew.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksgetsystemcontrolstartresult.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksopenhelpfile_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksOpenHelpFile](kompasobject_ksopenhelpfile.html)

Синтаксис:

void ksOpenHelpFile (char * file, unsigned int command, unsigned int id);

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

1\. Синтаксис соответствует::WinHelp.

2\. Функция открывает файл Справки КОМПАС.

3\. При закрытии системы окно Справки закроется автоматически.

[4\. При использовании Unicode следует использовать функцию ](ksopenhelpfilew.html)[ksOpenHelpFileW](ksopenhelpfilew.html).

Подразделы:

(отсутствуют)
