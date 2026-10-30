# Delete - Удалить коллекцию по ссылке на объект или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [Интерфейс IUserDataStoragesMng ](iuserdatastoragesmng.html) > [IUserDataStoragesMng - методы ](iuserdatastoragesmng_methods.html) |  Scroll [ [ [ ](iusermetadatamanager.html "К следующему разделу")](iuserdatastoragesmng_methods.html "На уровень выше")](iuserdatastoragesmng_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastoragesmng.html)

Синтаксис Automation:

BOOL Delete (const VARIANT & index );

Синтаксис COM:

HRESULT Delete( [in] VARIANT Index,

[out, retval] VARIANT_BOOL* pVal );

Входные параметры:

Index | \- Индекс или указатель на интерфейс коллекции объектов хранилища [IUserDataStorages](iuserdatastorages.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

В качестве индекса можно задать число или объект, к которому привязано хранилище (тип VT_DISPATCH)

Подразделы:

(отсутствуют)
