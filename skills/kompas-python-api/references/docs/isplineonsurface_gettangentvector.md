# GetTangentVector - Получить направление касательного вектора

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISplineOnSurface ](isplineonsurface.html) > [ISplineOnSurface - методы ](isplineonsurface_methods.html) |  Scroll [ [ [ ](isplineonsurface_getvertex.html "К следующему разделу")](isplineonsurface_methods.html "На уровень выше")](isplineonsurface_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isplineonsurface.html)

Синтаксис Automation:

BOOL GetTangentVector( long Index, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetTangentVector( long Index, double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс вершины.  
---|---  
  
Выходные параметры:

X | \- координата по X,  
---|---  
Y | \- координата по Y,  
Z | \- координата по Z.  
  
Подразделы:

(отсутствуют)
