# GetPoint - Получить координату точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IConicCurve3D](iconiccurve3d.html) > [IConicCurve3D - методы](iconiccurve3d_methods.html) |  Scroll [ [ [ ](iconiccurve3d_setpoint.html "К следующему разделу")](iconiccurve3d_methods.html "На уровень выше")](iconiccurve3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconiccurve3d.html)

Синтаксис Automation:

BOOL GetPoint( ksConicCurve3DParameterEnum Index, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetPoint( ksConicCurve3DParameterEnum Index, double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс вершины из перечисления [ksConicCurve3DParameterEnum](ksconiccurve3dparameterenum.html)  
---|---  
  
Выходные параметры:

X, Y, Z | \- координаты точки.  
---|---  
  
Подразделы:

(отсутствуют)
