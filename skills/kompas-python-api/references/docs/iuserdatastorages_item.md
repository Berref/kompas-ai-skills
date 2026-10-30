# Item - Хранилище, заданное по имени или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [Интерфейс IUserDataStorages ](iuserdatastorages.html) > [IUserDataStorages - свойства ](iuserdatastorages_props.html) |  Scroll [ [ [ ](iuserdatastorages_methods.html "К следующему разделу")](iuserdatastorages_props.html "На уровень выше")](iuserdatastorages_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorages.html)

Тип данных: указатель на интерфейс [IUserDataStorage](iuserdatastorage.html) хранилища

Синтаксис Automation:

StorageObj = iObject.Item (Index) | Получить свойство ([* ](1.html))  
---|---  
StorageObj = iObject.GetItem (Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (Index, &StorageObj) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- индекс хранилища.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса можно задать число или имя хранилища (VT_BSTR).

Подразделы:

(отсутствуют)
