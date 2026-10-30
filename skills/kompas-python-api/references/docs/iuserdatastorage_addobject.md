# AddObject - Добавить объект и комментарий в пользовательское хранилище

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - методы ](iuserdatastorage_methods.html) |  Scroll [ [ [ ](iuserdatastorage_addobjects.html "К следующему разделу")](iuserdatastorage_methods.html "На уровень выше")](iuserdatastorage_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

long AddObject( LPCTSTR pass,

const VARIANT & object,

LPCTSTR comment );

Синтаксис COM:

HRESULT AddObject( [in] BSTR Pass,

[in] VARIANT Object,

[in] BSTR Comment,

[out, retval] long* pVal);

Входные параметры:

Pass | \- пароль,  
---|---  
Object | \- указатель на объект,  
comment | \- комментарий.  
  
Возвращаемое значение:

| \- индекс объекта,  
---|---  
  
Примечание:

1\. Объект может быть variant'ом с типом VT_INT, VT_I2, VT_I4, VT_R4, VT_R8, VT_DATE, VT_UI1, VT_UINT, VT_BOOL, VT_BSTR, VT_DISPATCH, а также VT_ARRAY с этими типами данных. Индекс массива начинается с нуля.

2\. Если задан интерфейс VT_DISPATCH и массив объектов VT_ARRAY | VT_DISPATCH, то под объектом подразумевается указатель на IDispatch от объектов API. Они также будут сохранены вместе с документом и при следующем запросе найдены.

3\. Индексация массивов должна начинаться с нуля.

4\. Если хранилище защищено паролем от изменений, то метод будет выполнен только после указания правильного пароля.

5\. Под объектом API следует понимать объекты:

для 3D хранилища - наследник от [IModelObject](imodelobject.html),

для 2D хранилища - наследник от [IDrawingObject](idrawingobject.html) (кроме [ILayer](ilayer.html)).

Подразделы:

(отсутствуют)
