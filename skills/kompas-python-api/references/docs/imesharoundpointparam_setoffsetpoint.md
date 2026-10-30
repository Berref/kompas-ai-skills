# SetOffsetPoint - Задать смещение по точке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IMeshAroundPointParam ](imesharoundpointparam.html) > [IMeshAroundPointParam - методы ](imesharoundpointparam_methods.html) |  Scroll [ [ [ ](ipointsarrfromfile.html "К следующему разделу")](imesharoundpointparam_methods.html "На уровень выше")](imesharoundpointparam_getoffsetpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imesharoundpointparam.html)

Синтаксис Automation:

BOOL SetOffsetPoint( double X, double Y, double Z );

Синтаксис COM:

HRESULT SetOffsetPoint( double X, double Y, double Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y, Z | \- координаты точки смещения.  
---|---  
  
Примечание:

Метод задает координаты точки смещения.

Подразделы:

(отсутствуют)
