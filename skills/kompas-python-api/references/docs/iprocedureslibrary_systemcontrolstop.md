# SystemControlStop - Вернуть управление в библиотеку

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) > [Интерфейс IProceduresLibrary ](iprocedureslibrary.html) > [IProceduresLibrary - методы ](iprocedureslibrary_methods.html) |  Scroll [ [ [ ](iprocedure.html "К следующему разделу")](iprocedureslibrary_methods.html "На уровень выше")](iprocedureslibrary_systemcontrolstart.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedureslibrary.html)

Синтаксис Automation:

BOOL SystemControlStop();

Синтаксис COM:

HRESULT SystemControlStop ([out, retval] VARIANT_BOOL* pVal);

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет вернуть управление в библиотеку, если она находится в режиме [SystemControlStart](iprocedureslibrary_systemcontrolstart.html).

Подразделы:

(отсутствуют)
