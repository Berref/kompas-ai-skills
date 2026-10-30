# IsChoosen - Выделен ли объект

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Подсветка и выделение объектов ](ba1952824.html) > [Интерфейс IChooseManager ](ichoosemanager.html) > [IChooseManager - методы ](ichoosemanager_methods.html) |  Scroll [ [ [ ](ichoosemanager_unchoose.html "К следующему разделу")](ichoosemanager_methods.html "На уровень выше")](ichoosemanager_getmanagerindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichoosemanager.html)

Синтаксис Automation:

BOOL IsChoosen( LPDISPATCH Object );

Синтаксис COM:

HRESULT IsChoosen( IKompasAPIObject * Object,

BOOL * Result );

Входные параметры:

Objects | \- объект.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет определить, выделен ли объект.

Подразделы:

(отсутствуют)
