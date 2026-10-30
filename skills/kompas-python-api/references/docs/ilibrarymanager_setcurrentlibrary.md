# SetCurrentLibrary - Установить текущую прикладную библиотеку

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibraryManager ](ilibrarymanager.html) > [ILibraryManager - методы ](ilibrarymanager_methods.html) |  Scroll [ [ [ ](ilibrary.html "К следующему разделу")](ilibrarymanager_methods.html "На уровень выше")](ilibrarymanager_removefolder.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibrarymanager.html)

Синтаксис Automation:

BOOL SetCurrentLibrary (LPDISPATCH pVal);

Синтаксис COM:

HRESULT SetCurrentLibrary ([in] IProceduresLibrary* pVal, [out, retval] VARIANT_BOOL* result);

Входные параметры:

pVal | \- интерфейс библиотеки [IProceduresLibrary](iprocedureslibrary.html), которую нужно сделать текущей.  
---|---  
  
Возвращаемое значение:

TRUE | \- библиотека стала текущей,  
---|---  
FALSE | \- в случае ошибки.  
  
Примечание:

Данный метод следует использовать осторожно, иначе можно нарушить последовательность выполнения библиотек.

Метод может быть применен к подключенной библиотеке.

Метод позволяет остановить режим [SystemControlStart](kompasobject_kssystemcontrolstart.html), запущенный не из выполняемой (текущей) библиотеки. Для этого необходимо выполнить следующие действия:

1\. При помощи свойства [SystemControlStartLibrary](ilibrarymanager_systemcontrolstartlibrary.html) получить библиотеку, вызвавшую SystemControlStart.

2\. Сделать ее текущей методом SetCurrentLibrary.

3\. При помощи метода [ksSystemControlStop](kompasobject_kssystemcontrolstop.html) вернуть управление библиотеке, которая запустила SystemControlStart.

4\. Восстановить в качестве текущей выполняемую ранее библиотеку.

Подразделы:

(отсутствуют)
