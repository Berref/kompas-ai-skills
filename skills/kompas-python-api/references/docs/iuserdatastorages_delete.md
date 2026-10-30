# Delete - Удалить хранилище из коллекции по имени или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [Интерфейс IUserDataStorages ](iuserdatastorages.html) > [IUserDataStorages - методы ](iuserdatastorages_methods.html) |  Scroll [ [ [ ](iuserdatastoragesmng.html "К следующему разделу")](iuserdatastorages_methods.html "На уровень выше")](iuserdatastorages_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorages.html)

Синтаксис Automation:

BOOL Delete ( LPCTSTR password, const VARIANT index );

Синтаксис COM:

HRESULT Delete( [in] BSTR password,

[in] VARIANT Index,

[out, retval] VARIANT_BOOL* PVal );

Входные параметры:

Index | \- индекс или имя хранилища,  
---|---  
password | \- пароль на хранилище.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. В качестве индекса можно задать число или имя хранилища (VT_BSTR).

2\. Если хранилище защищено паролем, то метод работает только в случае указания правильного пароля.

Подразделы:

(отсутствуют)
