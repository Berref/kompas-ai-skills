# ksMessageBoxResult - Вывести сообщение, соответствующее результату работы библиотеки (с кодом ошибки)

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Методы вывода на экран ](ag91931.html) |  Scroll [ [ [ ](kompasobject_ksreturnresult.html "К следующему разделу")](ag91931.html "На уровень выше")](kompasobject_ksmessage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Вывести сообщение, соответствующее результату работы библиотеки (с кодом ошибки).

Аналог данного метода при использовании API экспортных функций - [MessageBoxResult](messageboxresult.html).

Синтаксис Automation:

BOOL ksMessageBoxResult();

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Функция сбрасывает флаг ошибки в случае, если эта ошибка не является фатальной.

Подразделы:

(отсутствуют)
