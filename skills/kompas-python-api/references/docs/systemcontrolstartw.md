# SystemControlStartW - Перейти под управление КОМПАС-ГРАФИК (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](systemcontrolstop.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](systemcontrolstart.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksSystemControlStart](kompasobject_kssystemcontrolstart.html).

Синтаксис:

int LIB_FUNC SystemControlStartW (LPWSTR menuCommand);

Входные параметры:

menuCommand | \- указатель на строку, помещаемую в меню для возврата в библиотеку.  
---|---  
  
Возвращаемое значение:

| [тип выхода из режима работы под управлением системы КОМПАС](stoptypes.html).  
---|---  
  
Примечание:

1\. Библиотечная функция отдает управление КОМПАС-ГРАФИК для интерактивной доработки документа. Возврат в библиотечную функцию будет осуществлен после нажатия команды в меню Библиотеки, обозначенной строкой menuCommand.

Если строка не задана, то ей автоматически будет присвоено значение "Вернуться в библиотеку" (функция вернет scStoppedByMenuCommand).

2\. При использовании ANSI следует использовать функцию [SystemControlStart](systemcontrolstart.html).

Подразделы:

(отсутствуют)
