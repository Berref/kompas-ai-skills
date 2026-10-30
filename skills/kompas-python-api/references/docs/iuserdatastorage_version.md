# Version - Версия хранилища

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - свойства ](iuserdatastorage_props.html) |  Scroll [ [ [ ](iuserdatastorage_methods.html "К следующему разделу")](iuserdatastorage_props.html "На уровень выше")](iuserdatastorage_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

Тип данных: long

Version = StorageObj.Version(Pass) | Получить свойство ([* ](1.html))  
---|---  
StorageObj.Version(Pass) = Version | Установить свойство ([* ](1.html))  
Version = StorageObj.GetVersion(Pass) | Получить свойство ([**](2.html))  
StorageObj.SetVersion (Version, Pass) | Установить свойство ([**](2.html))  
  
Входные параметры:

Pass (LPSTR) | \- пароль хранилища.  
---|---  
  
Синтаксис COM:

Тип данных: long

StorageObj->get_Version (Pass, &Version) | Получить свойство  
---|---  
StorageObj->put_Version (Pass, Version) | Установить свойство  
  
Входные параметры:

Pass (BSTR) | \- пароль хранилища.  
---|---  
  
Примечание:

Если хранилище защищено паролем, то изменить свойство можно, только указав пароль.

Подразделы:

(отсутствуют)
