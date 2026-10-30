# LibraryManagerFolder - Папка библиотеки в Менеджере библиотек

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - свойства ](ilibrary_props.html) |  Scroll [ [ [ ](ilibrary_librarytype.html "К следующему разделу")](ilibrary_props.html "На уровень выше")](ilibrary_enable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibrary.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

LibraryManagerFolder = iObject.LibraryManagerFolder | Получить свойство ([* ](1.html))  
---|---  
iObject->get_LibraryManagerFolder( &LibraryManagerFolder ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LibraryManagerFolder( &LibraryManagerFolder ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Если библиотека зарегистрирована в Менеджере библиотек, то свойство позволяет получить в виде строки папку или папки, где библиотека располагается. Если папка является вложенной в другую папку, имена папок отделяются символом "|".

Подразделы:

(отсутствуют)
