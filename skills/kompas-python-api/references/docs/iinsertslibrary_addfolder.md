# AddFolder - Добавить папку в библиотеку элементов

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) > [Интерфейс IInsertsLibrary ](iinsertslibrary.html) > [IInsertsLibrary - методы ](iinsertslibrary_methods.html) |  Scroll [ [ [ ](iinsertslibrary_delete.html "К следующему разделу")](iinsertslibrary_methods.html "На уровень выше")](iinsertslibrary_methods.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](iinsertslibrary.html)

Синтаксис Automation:

BOOL AddFolder (BSTR PathFolder);

Синтаксис COM:

HRESULT AddFolder ([in] BSTR PathFolder, [out, retval] VARIANT_BOOL* pVal);

Входные параметры:

PathFolder | \- путь к папке,  
---|---  
post | \- TRUE - отложенное выполнение.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Добавляет новую папку в библиотеку элементов.

Подразделы:

(отсутствуют)
