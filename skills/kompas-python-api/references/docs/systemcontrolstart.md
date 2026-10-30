# SystemControlStart - Перейти под управление КОМПАС-ГРАФИК

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](systemcontrolstartw.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](resultnull.html "К предыдущему разделу")  
---|---  
  
[Пример...](systemcontrolstart_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksSystemControlStart](kompasobject_kssystemcontrolstart.html).

Синтаксис:

int SystemControlStart (char *menuCommand);

Входные параметры:

menuCommand | \- указатель на строку, помещаемую в меню для возврата в библиотеку.  
---|---  
  
Возвращаемое значение:

| \- [типы выхода из режима работы под управлением системы КОМПАС](stoptypes.html).  
---|---  
  
Примечание:

1\. Библиотечная функция отдает управление КОМПАС-ГРАФИК для интерактивной доработки документа. Возврат в библиотечную функцию будет осуществлен после нажатия команды в меню Библиотеки, обозначенной строкой menuCommand.

Если строка не задана, то ей автоматически будет присвоено значение "Вернуться в библиотеку" (функция вернет scStoppedByMenuCommand).

2\. При использовании Unicode следует использовать функцию [SystemControlStartW](systemcontrolstartw.html).

Подразделы:

(отсутствуют)
