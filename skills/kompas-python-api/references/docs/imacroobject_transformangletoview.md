# TransformAngleToView - Перевод угла из CK вида в CK листа

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IMacroObject ](imacroobject.html) > [IMacroObject - методы ](imacroobject_methods.html) |  Scroll [ [ [ ](imacroobject_transformanglefromview.html "К следующему разделу")](imacroobject_methods.html "На уровень выше")](imacroobject_setplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject.html)

Синтаксис Automation:

BOOL TransformAngleToView( double * Angle );

Синтаксис COM:

HRESULT TransformAngleToView( double * Angle, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Angle | \- угол в системе координат макрообъекта.  
---|---  
  
Выходные параметры:

Angle | \- угол в системе координат вида.  
---|---  
  
Подразделы:

(отсутствуют)
