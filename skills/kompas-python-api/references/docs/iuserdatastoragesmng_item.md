# Item - Объект, заданный по ссылке на объект или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [Интерфейс IUserDataStoragesMng ](iuserdatastoragesmng.html) > [IUserDataStoragesMng - свойства ](iuserdatastoragesmng_props.html) |  Scroll [ [ [ ](iuserdatastoragesmng_methods.html "К следующему разделу")](iuserdatastoragesmng_props.html "На уровень выше")](iuserdatastoragesmng_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastoragesmng.html)

Тип данных: указатель на интерфейс [IUserDataStorages](iuserdatastorages.html) коллекции объектов хранилища.

Синтаксис Automation:

StorageObj = iObject.Item (Index) | Получить свойство ([* ](1.html))  
---|---  
StorageObj = iObject.GetItem (Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (Index, &StorageObj) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса можно задать число или объект, к которому привязано хранилище (тип VT_DISPATCH).

Подразделы:

(отсутствуют)
