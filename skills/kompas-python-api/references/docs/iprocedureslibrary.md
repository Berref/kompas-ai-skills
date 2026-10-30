# Интерфейс IProceduresLibrary

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) |  Scroll [ [ [ ](iprocedureslibrary_props.html "К следующему разделу")](ilibrary_methods.html "На уровень выше")](iinsertslibrary_setactivefolder.html "К предыдущему разделу")  
---|---  
  
Интерфейс прикладной библиотеки КОМПАС.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ILibrary](ilibrary.html)

[IProceduresLibrary](iprocedureslibrary.html)

Примечание:

1\. Интерфейс позволяет работать с прикладной библиотекой (*.rtw или *.dll), зарегистрированной в Менеджере библиотек. Можно получить стиль отображения библиотеки (панель, окно, диалог, меню) и массив процедур, реализованных в библиотеке.

2\. Данный интерфейс можно получить следующими способами:

•у интерфейса коллекции прикладных библиотек [IProceduresLibraries](iprocedureslibraries.html) c помощью свойства [IProceduresLibraries::Item](iprocedureslibraries_item.html),

•у интерфейса [ILibraryManager](ilibrarymanager.html) с помощью свойства [ILibraryManager::CurrentLibrary](ilibrarymanager_currentlibrary.html),

[ILibraryManager::SystemControlStartLibrary](ilibrarymanager_systemcontrolstartlibrary.html).

Подразделы:

[IProceduresLibrary - свойства ](iprocedureslibrary_props.html)

[IProceduresLibrary - методы ](iprocedureslibrary_methods.html)
