# SetObjects - Добавить объект, слой, вид, группу или SAFEARRAY объектов в макрообъект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IMacroObject ](imacroobject.html) > [IMacroObject - методы ](imacroobject_methods.html) |  Scroll [ [ [ ](imacroobject_setplacement.html "К следующему разделу")](imacroobject_methods.html "На уровень выше")](imacroobject_getplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject.html)

Синтаксис Automation:

BOOL SetObjects( VARIANT Objects );

Синтаксис COM:

HRESULT SetObjects( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- объект (VT_DISPATCH) или список объектов (VT_ARRAY | VT_DISPATCH).  
---|---  
  
Примечание:

Перед добавлением старые объекты в макро удаляются.

Для добавления объектов без удаления старых используется метод [IMacroObject::AddObjects](imacroobject_addobjects.html).

Версия Компас v23

Подразделы:

(отсутствуют)
