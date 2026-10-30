# Add - Создать новое хранилища по объекту и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [Интерфейс IUserDataStoragesMng ](iuserdatastoragesmng.html) > [IUserDataStoragesMng - методы ](iuserdatastoragesmng_methods.html) |  Scroll [ [ [ ](iuserdatastoragesmng_clear.html "К следующему разделу")](iuserdatastoragesmng_methods.html "На уровень выше")](iuserdatastoragesmng_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastoragesmng.html)

Синтаксис Automation:

LPDISPATCH Add( LPDISPATCH Object );

Синтаксис COM:

HRESULT Add( [in] IKompasAPIObject* Object,

[out, retval] IUserDataStorages ** Result );

Входные параметры:

Object | \- Указатель на интерфейс объекта [IKompasAPIObject](ikompasapiobject.html).  
---|---  
  
Выходные параметры:

| \- Указатель на интерфейс коллекции объектов хранилища [IUserDataStorages](iuserdatastorages.html).  
---|---  
  
Примечание:

1\. Метод позволяет добавить массив хранилищ по объекту в коллекцию. Если объект NULL, то хранилище добавляется к документу.

2\. Если в коллекции было создано хранилище по выбранному объекту, то метод сработает как GetItem.

Подразделы:

(отсутствуют)
