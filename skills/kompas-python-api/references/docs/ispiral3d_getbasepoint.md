# GetBasePoint - Получить координаты точки привязки спирали на базовой плоскости (точку пересечения оси спирали с базовой плоскостью)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpiral3D ](ispiral3d.html) > [ISpiral3D - методы ](ispiral3d_methods.html) |  Scroll [ [ [ ](ispiral3d_setbasepoint.html "К следующему разделу")](ispiral3d_methods.html "На уровень выше")](ispiral3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispiral3d.html)

Синтаксис Automation:

BOOL GetBasePoint( double * X, double * Y );

Синтаксис COM:

HRESULT GetBasePoint( double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

X, Y - координаты точки привязки спирали.

Примечание:

Метод возвращает координаты точки привязки спирали.

Подразделы:

(отсутствуют)
