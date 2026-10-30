# Unselect - Снять выделение объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Подсветка и выделение объектов ](ba1952824.html) > [Интерфейс ISelectionManager ](iselectionmanager.html) > [ISelectionManager - методы ](iselectionmanager_methods.html) |  Scroll [ [ [ ](iselectionmanager_unselectall.html "К следующему разделу")](iselectionmanager_methods.html "На уровень выше")](iselectionmanager_select.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iselectionmanager.html)

Синтаксис Automation:

BOOL Unselect( VARIANT Objects );

Синтаксис COM:

HRESULT Unselect( VARIANT Objects,

BOOL * Result );

Входные параметры:

Objects | \- объект или массив объектов, с которых нужно снять выделение ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет снять выделение объекта.

Подразделы:

(отсутствуют)
