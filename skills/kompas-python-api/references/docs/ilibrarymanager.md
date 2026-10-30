# Интерфейс ILibraryManager

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) |  Scroll [ [ [ ](ilibrarymanager_props.html "К следующему разделу")](library_maneger.html "На уровень выше")](library_maneger.html "К предыдущему разделу")  
---|---  
  
Интерфейс Менеджера библиотек.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ILibraryManager](ilibrarymanager.html)

Примечание:

1\. Данный интерфейс объединяет работу с библиотеками процедур (файлы *.rtw и *.dll ) и библиотеками документов: фрагментов (файлы *.lfr ) и моделей (файлы *.l3d). Интерфейс позволяет выполнять следующие действия:

•получить коллекции соответствующих библиотек, активный узел в менеджере библиотек, его название и комментарий;

•получить и управлять положением и видимостью Менеджера библиотек.

2\. Данный интерфейс можно получить у интерфейса приложения [IApplication](iapplication.html) с помощью свойства [IApplication::LibraryManager](iapplication_librarymanager.html).

Подразделы:

[ILibraryManager - свойства ](ilibrarymanager_props.html)

[ILibraryManager - методы ](ilibrarymanager_methods.html)
