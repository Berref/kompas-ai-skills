# Name - Имя хранилища

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserDataStorage ](iuserdatastorage.html) > [IUserDataStorage - свойства ](iuserdatastorage_props.html) |  Scroll [ [ [ ](iuserdatastorage_version.html "К следующему разделу")](iuserdatastorage_props.html "На уровень выше")](iuserdatastorage_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdatastorage.html)

Синтаксис Automation:

Тип данных: LPSTR

Name = StorageObj.Name(Pass) | Получить свойство ([* ](1.html))  
---|---  
StorageObj.Name(Pass) = Name | Установить свойство ([* ](1.html))  
Name = StorageObj.GetName(Pass) | Получить свойство ([**](2.html))  
StorageObj.SetName (Name, Pass) | Установить свойство ([**](2.html))  
  
Входные параметры:

Pass (LPSTR) | \- пароль хранилища.  
---|---  
  
Синтаксис COM:

Тип данных:BSTR.

StorageObj>get_Name (Pass, &Name) | Получить свойство  
---|---  
StorageObj>put_Name (Pass, Name) | Установить свойство  
  
Входные параметры:

Pass (BSTR) | \- пароль хранилища.  
---|---  
  
Примечание:

Если хранилище защищено паролем, то изменить свойство можно, только указав правильный пароль.

Подразделы:

(отсутствуют)
