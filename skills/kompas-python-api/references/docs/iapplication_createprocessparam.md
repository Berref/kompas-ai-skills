# CreateProcessParam - Получить интерфейс параметров процесса

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - методы ](iapplication_methods.html) |  Scroll [ [ [ ](iapplication_createpropertymanager.html "К следующему разделу")](iapplication_methods.html "На уровень выше")](iapplication_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Синтаксис Automation:

LPDISPATCH CreateProcessParam();

Синтаксис COM:

HRESULT CreateProcessParam([out, retval] IProcessParam** processParam);

Возвращаемое значение:

указатель на интерфейс [IProcessParam](iprocessparam.html) | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Данный метод создает новые параметры процесса и возвращает их. Параметры будут удалены после их освобождения библиотекой, поэтому библиотека должна держать ссылку на параметры все время от начала до завершения их использования. При повторном вызове этого метода будут созданы новые параметры.

Подразделы:

(отсутствуют)
