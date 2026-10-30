# SystemControlStartLibrary - Получить прикладную библиотеку, которая запустила SystemControlStart

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibraryManager ](ilibrarymanager.html) > [ILibraryManager - свойства ](ilibrarymanager_props.html) |  Scroll [ [ [ ](ilibrarymanager_systemcontrolstartresult.html "К следующему разделу")](ilibrarymanager_props.html "На уровень выше")](ilibrarymanager_procedureslibraries.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibrarymanager.html)

Тип данных: [IProceduresLibrary](iprocedureslibrary.html)

Синтаксис Automation:

SystemControlStartLibrary = iObject.SystemControlStartLibrary | Получить свойство ([* ](1.html))  
---|---  
SystemControlStartLibrary = iObject.GetSystemControlStartLibrary() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SystemControlStartLibrary (&CurrentLibrary) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет вернуть интерфейс библиотеки.

2\. Библиотека во время выполнения может вызвать функцию [SystemControlStart](systemcontrolstart.html) для передачи управления системе КОМПАС. После вызова этой функции выполнение библиотеки приостанавливается.

3\. Управление возвращается библиотеке при вызове функции [SystemControlStop](systemcontrolstop.html) из этой же библиотеки или при выполнении соответствующей команды меню.

Подразделы:

(отсутствуют)
