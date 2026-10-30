# GetCurvePoint - Получить точку на кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс IConditionIntersect ](iconditionintersect.html) > [IConditionIntersect - методы ](iconditionintersect_methods.html) |  Scroll [ [ [ ](iconditionintersect_getintersectpoint.html "К следующему разделу")](iconditionintersect_methods.html "На уровень выше")](iconditionintersect_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconditionintersect.html)

Синтаксис Automation:

BOOL GetCurvePoint( BOOL FirstCurve, double * X, double * Y );

Синтаксис COM :

HRESULT GetCurvePoint( BOOL FirstCurve, double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
  
Входные параметры:

FirstCurve | \- получить точку первой кривой.  
---|---  
  
Выходные параметры:

X | \- первая координата точки,  
---|---  
Y | \- вторая координата точки.  
  
Подразделы:

(отсутствуют)
