# SetPassword - Установить пароль на изменение данных в хранилище

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - методы ](iuserdatastorage_methods.html) |  Scroll [ [ [ ](iuserdatastorages.html "К следующему разделу")](iuserdatastorage_methods.html "На уровень выше")](iuserdatastorage_setobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

BOOL SetPassword( LPCTSTR oldPass, LPCTSTR newPass );

Синтаксис COM:

HRESULT SetPassword( [in] BSTR OldPass,

[in] BSTR NewPass,

[out, retval] VARIANT_BOOL* Result);

Входные параметры:

OldPass | \- старый пароль,  
---|---  
NewPass | \- новый пароль.  
  
Примечание:

1\. Если хранилище защищено паролем от изменений, то изменить пароль можно, только указав текущий пароль.

2\. По умолчанию пароль представляет собой пустую строку или нулевой указатель.

Подразделы:

(отсутствуют)
