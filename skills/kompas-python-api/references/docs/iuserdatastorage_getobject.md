# GetObject - Получить объект пользовательского хранилища и комментарий к нему по комментарию или индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - методы ](iuserdatastorage_methods.html) |  Scroll [ [ [ ](iuserdatastorage_setobject.html "К следующему разделу")](iuserdatastorage_methods.html "На уровень выше")](iuserdatastorage_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

BSTR GetObject( const VARIANT & index, VARIANT * object, long * numb );

Синтаксис COM:

HRESULT GetObject( [in] VARIANT Index,

[out] VARIANT * Object,

[out] long* numb,

[out, retval] BSTR * Comment );

Входные параметры:

Index | \- индекс объекта или комментарий.  
---|---  
  
Выходные параметры:

Object | \- указатель на объект хранилища,  
---|---  
numb | \- указатель на номер объекта.  
  
Возвращаемое значение:

Comment (BSTR) | \- комментарий.  
---|---  
  
Примечание:

1\. В качестве индекса можно задать число или комментарий к объекту.

2\. Объект может быть variant'ом с типом VT_INT, VT_I2, VT_I4, VT_R4, VT_R8, VT_DATE, VT_UI1, VT_UINT, VT_BOOL, VT_BSTR, VT_DISPATCH, а также VT_ARRAY с этими типами данных.

3\. Если задан интерфейс VT_DISPATCH и массив объектов VT_ARRAY | VT_DISPATCH, то под объектом подразумевается указатель на IDispatch от объектов API. Они также будут сохранены вместе с документом и при следующем запросе найдены.

Подразделы:

(отсутствуют)
