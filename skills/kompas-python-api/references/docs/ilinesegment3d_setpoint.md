# SetPoint - Установить координату точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ILineSegment3D ](ilinesegment3d.html) > [ILineSegment3D - методы ](ilinesegment3d_methods.html) |  Scroll [ [ [ ](imesharoundpointparam.html "К следующему разделу")](ilinesegment3d_methods.html "На уровень выше")](ilinesegment3d_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinesegment3d.html)

Синтаксис Automation:

BOOL SetPoint( BOOL Begin, double X, double Y, double Z );

Синтаксис COM:

HRESULT SetPoint( BOOL Begin, double X, double Y, double Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Begin | \- начальная точка,  
---|---  
X | \- координата точки,  
Y | \- координата точки,  
Z | \- координата точки.  
  
Подразделы:

(отсутствуют)
