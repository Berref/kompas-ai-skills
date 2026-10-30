# Clear - Очистить хранилище, удалив все объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - методы ](iuserdatastorage_methods.html) |  Scroll [ [ [ ](iuserdatastorage_delete.html "К следующему разделу")](iuserdatastorage_methods.html "На уровень выше")](iuserdatastorage_addobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

BOOL Clear ( LPCTSTR Pass );

Синтаксис COM:

HRESULT Clear( [in] BSTR Pass,

[out, retval] VARIANT_BOOL* Result);

Входные параметры:

Pass | \- пароль.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если хранилище защищено паролем от изменений, то метод будет выполнен только после указания правильного пароля.

Подразделы:

(отсутствуют)
