# LibraryName - Имя библиотеки, возвращаемое функцией LIBRARYNAME или LIBRARYID

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) > [Интерфейс IProceduresLibrary ](iprocedureslibrary.html) > [IProceduresLibrary - свойства ](iprocedureslibrary_props.html) |  Scroll [ [ [ ](iprocedureslibrary_procedures.html "К следующему разделу")](iprocedureslibrary_props.html "На уровень выше")](iprocedureslibrary_iconsfont.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedureslibrary.html)

Тип данных: BSTR

Синтаксис Automation:

LibraryName = Object.LibraryName | Получить свойство ([* ](1.html))  
---|---  
LibraryName = Object.GetLibraryName() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_LibraryName( &LibraryName ) | Получить свойство  
---|---  
  
Примечание:

Свойство возвращает имя библиотеки, возвращаемое функцией [LIBRARYNAME](libraryname.html) или [LIBRARYID](libraryid.html).

Отображаемое имя библиотеки может отличаться, если в библиотеке реализована функция [DisplayLibraryName](displaylibraryname.html).

Для получения отображаемого имени библиотеки используется свойство [ILibrary::Name](ilibrary_name.html).

При получении библиотеки по имени из коллекции можно использовать как отображаемое, так и внутреннее имя.

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
