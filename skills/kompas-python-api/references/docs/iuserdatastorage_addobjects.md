# AddObjects - Добавить объекты пользовательского хранилища и комментарии к ним

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - методы ](iuserdatastorage_methods.html) |  Scroll [ [ [ ](iuserdatastorage_clear.html "К следующему разделу")](iuserdatastorage_methods.html "На уровень выше")](iuserdatastorage_addobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

BOOL AddObjects( BSTR Pass, VARIANT Objects, VARIANT Comments );

Синтаксис COM:

HRESULT AddObjects( BSTR Pass, VARIANT Objects, VARIANT Comments, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Pass | \- пароль,  
---|---  
Objects | \- список данных в виде массива VT_ARRAY | VT_VARIANT,  
comments | \- список комментариев в виде массива VT_ARRAY | VT_BSTR.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
