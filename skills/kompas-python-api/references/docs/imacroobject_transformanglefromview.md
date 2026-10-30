# TransformAngleFromView - Перевод угла из CK листа в CK вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IMacroObject ](imacroobject.html) > [IMacroObject - методы ](imacroobject_methods.html) |  Scroll [ [ [ ](imacroobject_transformpointfromview.html "К следующему разделу")](imacroobject_methods.html "На уровень выше")](imacroobject_transformangletoview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject.html)

Синтаксис Automation:

BOOL TransformAngleFromView( double * Angle );

Синтаксис COM:

HRESULT TransformAngleFromView( double * Angle, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Angle | \- угол в системе координат вида.  
---|---  
  
Выходные параметры:

Angle | \- угол в системе координат макрообъекта.  
---|---  
  
Подразделы:

(отсутствуют)
