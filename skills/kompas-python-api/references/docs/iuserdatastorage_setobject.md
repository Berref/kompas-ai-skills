# SetObject - Установить объект пользовательского хранилища и комментарий к нему по комментарию или индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - методы ](iuserdatastorage_methods.html) |  Scroll [ [ [ ](iuserdatastorage_setpassword.html "К следующему разделу")](iuserdatastorage_methods.html "На уровень выше")](iuserdatastorage_getobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

long SetObject( LPCTSTR pass,

const VARIANT index,

const VARIANT & object,

LPCTSTR comment );

Синтаксис COM:

HRESULT SetObject( [in] BSTR Pass,

[in] VARIANT Index,

[in] VARIANT Object,

[in] BSTR Comment,

[out, retval] long* pVal);

Входные параметры:

Pass | \- пароль,  
---|---  
Index | \- индекс объекта или комментарий,  
Object | \- указатель на объект,  
comment | \- комментарий.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. В качестве индекса можно задать число или комментарий к объекту.

2\. Объект может быть variant'ом с типом VT_INT, VT_I2, VT_I4, VT_R4, VT_R8, VT_DATE, VT_UI1, VT_UINT, VT_BOOL, VT_BSTR, VT_DISPATCH, а также VT_ARRAY с этими типами данных.

3\. Если задан интерфейс VT_DISPATCH и массив объектов VT_ARRAY | VT_DISPATCH, то под объектом подразумевается указатель на IDispatch от объектов API. Они также будут сохранены вместе с документом и при следующем запросе найдены.

4\. Если хранилище защищено паролем от изменений, то метод будет выполнен только после указания правильного пароля.

Подразделы:

(отсутствуют)
