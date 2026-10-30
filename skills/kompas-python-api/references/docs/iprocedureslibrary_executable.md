# Executable - Признак выполнения библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) > [Интерфейс IProceduresLibrary ](iprocedureslibrary.html) > [IProceduresLibrary - свойства ](iprocedureslibrary_props.html) |  Scroll [ [ [ ](iprocedureslibrary_externalinterface.html "К следующему разделу")](iprocedureslibrary_props.html "На уровень выше")](iprocedureslibrary_dictionary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedureslibrary.html)

Тип данных: BOOL

Синтаксис Automation:

Executable = iObject.Executable | Получить свойство ([* ](1.html))  
---|---  
Executable = iObject.GetExecutable() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Executable( &Executable ) | Получить свойство  
---|---  
  
Примечание:

Если выполняется команда библиотеки или отрабатывается событие, на которое подписалась библиотека, то свойство вернет TRUE.

Подразделы:

(отсутствуют)
