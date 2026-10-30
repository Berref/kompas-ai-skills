# AddMenuCommand - Создать объект по образцу

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibraryMenu ](ikompaslibrarymenu.html) > [IKompasLibraryMenu - методы ](ikompaslibrarymenu_methods.html) |  Scroll [ [ [ ](ikompaslibrarymenu_addseparator.html "К следующему разделу")](ikompaslibrarymenu_methods.html "На уровень выше")](ikompaslibrarymenu_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrarymenu.html)

Синтаксис Automation:

BOOL AddMenuCommand( long Id, BSTR Title );

Синтаксис Com:

HRESULT AddMenuCommand( long Id, BSTR Title, BOOL * Result );

Входные параметры:

Id | \- идентификатор команды,  
---|---  
Title | \- отображаемое название команды.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
