# TransformPointToView - Перевод координат точки из CK макроэлемента в CK вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IMacroObject ](imacroobject.html) > [IMacroObject - методы ](imacroobject_methods.html) |  Scroll [ [ [ ](iannotativecontainer.html "К следующему разделу")](imacroobject_methods.html "На уровень выше")](imacroobject_transformpointfromview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject.html)

Синтаксис Automation:

BOOL TransformPointToView( double * X, double * Y );

Синтаксис COM:

HRESULT TransformPointToView( double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- координаты точек в системе координат макрообъекта.  
---|---  
  
Выходные параметры:

X, Y | \- координаты точек в системе координат вида.  
---|---  
  
Подразделы:

(отсутствуют)
