# ksGetExternalInterface - Получить указатель внешнего интерфейса

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksgetlookstyle.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksexecutekompascommand.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetExternalInterface](kompasobject_ksgetexternalinterface.html).

Синтаксис:

LPDISPATCH ksGetExternalInterface();

Примечание:

1\. Функция не выполняет Addref на выдаваемый интерфейс.

2\. Внешний интерфейс можно использовать для обмена данными между двумя приложениями. Первое приложение передает интерфейс при вызове метода [KompasObject::ksExecuteKompasLibraryCommandEx](kompasobject_ksexecutekompaslibrarycommandex.html).

3\. После выполнения [KompasObject::ksExecuteKompasLibraryCommandEx](kompasobject_ksexecutekompaslibrarycommandex.html), функция ksGetExternalInterface возвращает NULL.

Подразделы:

(отсутствуют)
