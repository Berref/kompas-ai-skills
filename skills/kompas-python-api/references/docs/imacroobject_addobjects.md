# AddObjects - Добавить объект, слой, вид, группу или SAFEARRAY объектов в макрообъект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IMacroObject ](imacroobject.html) > [IMacroObject - методы ](imacroobject_methods.html) |  Scroll [ [ [ ](imacroobject_deleteattachedleaders.html "К следующему разделу")](imacroobject_methods.html "На уровень выше")](imacroobject_adddefaulthotpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject.html)

Синтаксис Automation:

BOOL AddObjects( VARIANT Objects );

Синтаксис COM:

HRESULT Add( VARIANT Objects, BOOL * Result );

Входные параметры:

Objects | \- объект или массив объектов, добавляемых в макроэлемент.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавлять объект, слой, вид, группу или SAFEARRAY объектов в макроэлемент

Подразделы:

(отсутствуют)
