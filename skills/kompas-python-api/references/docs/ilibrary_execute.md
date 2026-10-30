# Execute - Выполнить команду

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) |  Scroll [ [ [ ](iinsertslibrary.html "К следующему разделу")](ilibrary_methods.html "На уровень выше")](ilibrary_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibrary.html)

Синтаксис Automation:

BOOL Execute (long command, LPDISPATCH external, VARIANT_BOOL post);

Синтаксис COM:

HRESULT Execute([in] long command,

[in] LPDISPATCH external,

[in] VARIANT_BOOL post,

[out, retval] VARIANT_BOOL* pVal);

Входные параметры:

command | \- номер команды,  
---|---  
external | \- интерфейс для обмена данными между библиотекой, вызвавшей Execute, и библиотекой, в которой реализована команда. Интерфейс определен разработчиком библиотек. Может быть NULL,  
post | \- отложенное выполнение, если TRUE, если FALSE - немедленное.  
  
Возвращаемое значение:

TRUE | \- команда выполнена.  
---|---  
FALSE | \- команда не выполнена.  
  
Примечание:

Метод позволяет выполнить команду прикладной библиотеки. При этом проверяется лицензионная защита, и может быть передан пользовательский интерфейс для обмена данными между библиотеками. Выполнение команды может быть отложенное или немедленное.

Получить интерфейс для обмена данными между библиотекой в функции LibraryEntry можно с помощью свойства [IProceduresLibrary::ExternalInterface](iprocedureslibrary_externalinterface.html)

Подразделы:

(отсутствуют)
