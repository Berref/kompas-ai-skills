# Choose - Выделить объект

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Подсветка и выделение объектов ](ba1952824.html) > [Интерфейс IChooseManager ](ichoosemanager.html) > [IChooseManager - методы ](ichoosemanager_methods.html) |  Scroll [ [ [ ](ichoosemanager_getmanagerindex.html "К следующему разделу")](ichoosemanager_methods.html "На уровень выше")](ichoosemanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichoosemanager.html)

Синтаксис Automation:

BOOL Choose(VARIANT Objects);

Синтаксис COM:

HRESULT Choose (VARIANT Objects,

BOOL * Result);

Входные параметры:

Objects | \- объект или массив объектов, которые нужно выделить (VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет выделить объект.

Подразделы:

(отсутствуют)
