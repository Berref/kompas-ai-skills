# Delete - Удалить объект, заданный по индексу или по комментарию

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - методы ](iuserdatastorage_methods.html) |  Scroll [ [ [ ](iuserdatastorage_getobject.html "К следующему разделу")](iuserdatastorage_methods.html "На уровень выше")](iuserdatastorage_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

BOOL Delete( LPCTSTR pass,

const VARIANT & index );

Синтаксис COM:

HRESULT Delete( [in] BSTR Pass,

[in] VARIANT Index,

[out, retval] VARIANT_BOOL* PVal );

Входные параметры:

Pass | \- пароль,  
---|---  
Index | \- индекс объекта или комментарий.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. В качестве индекса можно задать число или комментарий к объекту.

2\. Если хранилище защищено паролем от изменений, то метод будет выполнен только после указания правильного пароля.

Подразделы:

(отсутствуют)
