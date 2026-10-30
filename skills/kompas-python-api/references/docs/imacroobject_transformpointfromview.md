# TransformPointFromView - Перевод координат точки из CK вида в CK макроэлемента

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IMacroObject ](imacroobject.html) > [IMacroObject - методы ](imacroobject_methods.html) |  Scroll [ [ [ ](imacroobject_transformpointtoview.html "К следующему разделу")](imacroobject_methods.html "На уровень выше")](imacroobject_transformanglefromview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject.html)

Синтаксис Automation:

BOOL TransformPointFromView( double * X, double * Y );

Синтаксис COM:

HRESULT TransformPointFromView( double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- координаты точек в системе координат вида.  
---|---  
  
Выходные параметры:

X, Y | \- координаты точек в системе координат макрообъекта.  
---|---  
  
Подразделы:

(отсутствуют)
