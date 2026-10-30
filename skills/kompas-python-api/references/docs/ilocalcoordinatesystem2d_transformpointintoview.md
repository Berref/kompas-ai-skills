# TransformPointIntoView - Перевести точку из СК вида в локальную СК

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вспомогательные объекты ](bb2330638.html) > [Интерфейс ILocalCoordinateSystem2D ](ilocalcoordinatesystem2d.html) > [ILocalCoordinateSystem2D - методы ](ilocalcoordinatesystem2d_methods.html) |  Scroll [ [ [ ](bb2331024.html "К следующему разделу")](ilocalcoordinatesystem2d_methods.html "На уровень выше")](ilocalcoordinatesystem2d_transformpointfromview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem2d.html)

Синтаксис Automation:

BOOL TransformPointIntoView( double X, double Y, double * Xn, double * Yn );

Синтаксис COM:

HRESULT TransformPointIntoView( double X, double Y, double * Xn, double * Yn, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- координаты точки в системе координат вида.  
---|---  
  
Выходные параметры:

Xn, Yn | \- координаты точки в локальной системе координат.  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
