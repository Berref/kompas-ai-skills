# CurrentLibrary - Текущая прикладная библиотека

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibraryManager ](ilibrarymanager.html) > [ILibraryManager - свойства ](ilibrarymanager_props.html) |  Scroll [ [ [ ](ilibrarymanager_documentslibraries.html "К следующему разделу")](ilibrarymanager_props.html "На уровень выше")](ilibrarymanager_activefoldercomment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibrarymanager.html)

Тип данных: указатель на интерфейс [IProceduresLibrary](iprocedureslibrary.html)

Синтаксис Automation:

CurrentLibrary = iObject.CurrentLibrary | Получить свойство ([* ](1.html))  
---|---  
CurrentLibrary = iObject.GetCurrentLibrary() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CurrentLibrary (&CurrentLibrary) | Получить свойство  
---|---  
  
Примечание:

1\. Подключенными одновременно могут быть несколько библиотек, но текущей библиотекой может быть одна.

2\. Текущей является библиотека, у которой непосредственно выполняется команда или вызван обработчик события.

Подразделы:

(отсутствуют)
