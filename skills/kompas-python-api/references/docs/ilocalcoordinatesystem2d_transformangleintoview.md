# TransformAngleIntoView - Перевод угла из CK вида в локальную CK

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вспомогательные объекты ](bb2330638.html) > [Интерфейс ILocalCoordinateSystem2D ](ilocalcoordinatesystem2d.html) > [ILocalCoordinateSystem2D - методы ](ilocalcoordinatesystem2d_methods.html) |  Scroll [ [ [ ](ilocalcoordinatesystem2d_transformpointfromview.html "К следующему разделу")](ilocalcoordinatesystem2d_methods.html "На уровень выше")](ilocalcoordinatesystem2d_transformanglefromview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem2d.html)

Синтаксис Automation:

BOOL TransformAngleIntoView( double * Angle );

Синтаксис COM:

HRESULT TransformAngleIntoView( double * Angle, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входной параметр:

Angle | \- значение угла (в градусах).  
---|---  
  
Выходной параметр:

Angle | \- значение угла (в градусах).  
---|---  
  
Примечание:

Параметр Angle является одновременно и входным, и выходным.

На входе он представляет собой угол в СК вида, а в результате работы функции преобразуется в угол в локальной СК.

Версия Компас v23

Подразделы:

(отсутствуют)
