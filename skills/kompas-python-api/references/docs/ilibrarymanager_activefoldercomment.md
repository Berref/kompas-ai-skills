# ActiveFolderComment - Комментарий активной папки

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibraryManager ](ilibrarymanager.html) > [ILibraryManager - свойства ](ilibrarymanager_props.html) |  Scroll [ [ [ ](ilibrarymanager_currentlibrary.html "К следующему разделу")](ilibrarymanager_props.html "На уровень выше")](ilibrarymanager_activefolder.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ilibrarymanager.html)

Тип данных: VARIANT

Синтаксис Automation:

ActiveFolderComment = iObject.ActiveFolderComment | Получить свойство ([* ](1.html))  
---|---  
iObject.ActiveFolderComment = ActiveFolderComment | Установить свойство ([* ](1.html))  
ActiveFolderComment = iObject.GetActiveFolderComment() | Получить свойство ([**](2.html))  
iObject.SetActiveFolderComment (ActiveFolderComment) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ActiveFolderComment (&ActiveFolderComment) | Получить свойство  
---|---  
iObject->put_ActiveFolderComment (ActiveFolderComment) | Установить свойство  
  
Примечание:

Комментарий текущей папки может быть многострочным. Поэтому свойство возвращает или принимает переменную типа VARIANT на безопасный массив строк SAFEARRAY (VT_ARRAY | VT_BSTR).

Подразделы:

(отсутствуют)
