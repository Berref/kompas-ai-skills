# RemoveFolder - Удалить папку из библиотеки элементов

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) > [Интерфейс IInsertsLibrary ](iinsertslibrary.html) > [IInsertsLibrary - методы ](iinsertslibrary_methods.html) |  Scroll [ [ [ ](iinsertslibrary_setactivefolder.html "К следующему разделу")](iinsertslibrary_methods.html "На уровень выше")](iinsertslibrary_delete.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](iinsertslibrary.html)

Синтаксис Automation:

BOOL RemoveFolder (BSTR PathFolder);

Синтаксис COM:

HRESULT RemoveFolder ([in] BSTR PathFolder, [out, retval] VARIANT_BOOL* pVal);

Входные параметры:

PathFolder | \- путь к папке,  
---|---  
post | \- TRUE - отложенное выполнение.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Удаляет папку из библиотеки элементов.

Подразделы:

(отсутствуют)
