# ksGetExternalInterface - Получить указатель внешнего интерфейса

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetlibrarystylesarray.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetselectedembodimentadditionalnumber.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetExternalInterface](ksgetexternalinterface.html).

Синтаксис Automation:

LPDISPATCH ksGetExternalInterface();

Возвращаемое значение:

| \- указатель на интерфейс IDispatch связи между библиотеками (приложениями).  
---|---  
  
Примечание:

1\. Метод не выполняет Addref на выдаваемый интерфейс.

2\. Внешний интерфейс можно использовать для обмена данными между двумя приложениями. Первое приложение передает интерфейс при вызове метода [KompasObject::ksExecuteKompasLibraryCommandEx](kompasobject_ksexecutekompaslibrarycommandex.html).

3\. После выполнения KompasObject::ksExecuteKompasLibraryCommandEx метод ksGetExternalInterface возвращает NULL.

Подразделы:

(отсутствуют)
