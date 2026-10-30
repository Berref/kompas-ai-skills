# MessageBoxResult - Вывести сообщение, соответствующее результату работы библиотеки (с кодом ошибки)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](pause.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](messagew.html "К предыдущему разделу")  
---|---  
  
[Пример...](returnresult_strresult_messageboxresult_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksMessageBoxResult](kompasobject_ksmessageboxresult.html).

Синтаксис:

void MessageBoxResult ( void );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Функция сбрасывает флаг ошибки в случае, если она не является фатальной.

Подразделы:

(отсутствуют)
