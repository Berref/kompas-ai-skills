# InitByObjects - Инициализация по объектам

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс IConditionIntersect ](iconditionintersect.html) > [IConditionIntersect - методы ](iconditionintersect_methods.html) |  Scroll [ [ [ ](ilinearcentres.html "К следующему разделу")](iconditionintersect_methods.html "На уровень выше")](iconditionintersect_getintersectpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconditionintersect.html)

Синтаксис Automation:

BOOL InitByObjects( LPDISPATCH Curve1, LPDISPATCH Curve2, double * X1, double * Y1, double * X2, double * Y2, BOOL RemoteLine1Visible, BOOL RemoteLine2Visible );

Синтаксис COM:

HRESULT InitByObjects( IKompasAPIObject * Curve1, IKompasAPIObject * Curve2, double * X1, double * Y1, double * X2, double * Y2, BOOL RemoteLine1Visible, BOOL RemoteLine2Visible, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
  
Входные параметры:

Curve1 | \- первая кривая,  
---|---  
Curve2 | \- вторая кривая,  
X1, Y1 | \- координаты точки на первой кривой,  
X2, Y2 | \- координаты точки на второй кривой,  
RemoteLine1Visible | \- признак видимости первой кривой.  
  
Подразделы:

(отсутствуют)
