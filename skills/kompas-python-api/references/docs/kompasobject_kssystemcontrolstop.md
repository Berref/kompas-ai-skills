# ksSystemControlStop - Отдать управление библиотеке

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Сервисные функции ](ag92071.html) |  Scroll [ [ [ ](kompasobject_kssystempath.html "К следующему разделу")](ag92071.html "На уровень выше")](kompasobject_kssystemcontrolstart.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [SystemControlStop](systemcontrolstop.html) Синтаксис Automation:

BOOL ksSystemControlStop();

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Функция принудительно передает управление библиотечной функции, запущенной в режиме немодального диалога (в этом случае управление может переходить от библиотеки к системе и наоборот).

Подразделы:

(отсутствуют)
