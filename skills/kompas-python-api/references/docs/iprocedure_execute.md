# Execute - Выполнить команду

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IProcedure ](iprocedure.html) > [IProcedure - методы ](iprocedure_methods.html) |  Scroll [ [ [ ](iinsert.html "К следующему разделу")](iprocedure_methods.html "На уровень выше")](iprocedure_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedure.html)

Синтаксис Automation:

BOOL Execute (LPDISPATCH external, BOOL post);

Синтаксис COM:

HRESULT Execute([in] LPDISPATCH external,

[in] VARIANT_BOOL post,

[out, retval] VARIANT_BOOL* pVal);

Входные параметры:

external | \- интерфейс для обмена данными между библиотекой, вызвавшей Execute, и библиотекой, в которой реализована команда. Интерфейс определен разработчиком библиотек. Может быть NULL,  
---|---  
post | \- TRUE - отложенное выполнение.  
  
Возвращаемое значение:

TRUE | \- команда выполнена,  
---|---  
FALSE | \- команда не выполнена.  
  
Примечание:

Метод позволяет выполнить команду прикладной библиотеки. При этом проверяется лицензионная защита и может быть передан пользовательский интерфейс для обмена данными между библиотеками. Выполнение команды может быть отложенное или немедленное.

Подразделы:

(отсутствуют)
