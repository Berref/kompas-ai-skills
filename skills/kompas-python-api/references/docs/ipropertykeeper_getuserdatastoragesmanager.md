# GetUserDataStoragesManager - Менеджер для работы с пользовательским хранилищем данных

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyKeeper ](ipropertykeeper.html) > [IPropertyKeeper - методы ](ipropertykeeper_methods.html) |  Scroll [ [ [ ](ipropertykeeper_inserthypertextreference.html "К следующему разделу")](ipropertykeeper_methods.html "На уровень выше")](ipropertykeeper_getpropertyvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertykeeper.html)

Синтаксис Automation:

LPDISPATCH GetUserDataStoragesManager( BOOL FromSource );

Синтаксис COM:

HRESULT GetUserDataStoragesManager( BOOL FromSource, IUserDataStoragesMng** PVal);

Входные параметры:

FromSource | \- TRUE вернуть менеджер из файла источника объекта, \- FALSE - вернуть менеджер из файла владельца объекта.  
---|---  
  
Возвращаемое значение:

| \- Указатель на интерфейс менеджера пользовательских данных [IUserDataStoragesMng](iuserdatastoragesmng.html),  
---|---  
  
Подразделы:

(отсутствуют)
