# Select - Выделить объект

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Подсветка и выделение объектов ](ba1952824.html) > [Интерфейс ISelectionManager ](iselectionmanager.html) > [ISelectionManager - методы ](iselectionmanager_methods.html) |  Scroll [ [ [ ](iselectionmanager_unselect.html "К следующему разделу")](iselectionmanager_methods.html "На уровень выше")](iselectionmanager_isselected.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iselectionmanager.html)

Синтаксис Automation:

BOOL Select( VARIANT Objects );

Синтаксис COM:

HRESULT Select( VARIANT Objects,

BOOL * Result );

Входные параметры:

Objects | \- объект или массив объектов, которые нужно выделить ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет выделить объект.

Подразделы:

(отсутствуют)
