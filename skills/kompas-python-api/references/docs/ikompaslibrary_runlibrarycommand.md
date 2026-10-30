# RunLibraryCommand - Выполнить команду библиотеки

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrarymenu.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_getlibrarycommandstate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT RunLibraryCommand( long Command, long DemoMode, long * Result );

Входные параметры:

Command | \- номер команды приложения,  
---|---  
DemoMode | \- признак деморежима: \- 0 - обычный режим, \- 1 - вызов из дистрибутивной задачи в деморежиме, \- 2 - вызов из демоверсии.  
  
Возвращаемое значение:

Не используется

Примечание:

При вызове команды библиотеки из меню панели инструментов или при редактировании библиотечного элемента по двойному нажатию кнопки мыши управление передается этому методу с номером выбранной команды.

Подразделы:

(отсутствуют)
