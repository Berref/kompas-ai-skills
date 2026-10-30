# TransformAngleFromMatrix - Перевод угла из локальной CK листа в CK вида

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_transformlengthfrommatrix.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_transformangleintomatrix.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL TransformAngleFromMatrix( double * Angle );

Синтаксис COM:

HRESULT TransformAngleFromMatrix( double * Angle, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входной параметр:

Angle | \- значение угла в градусах.  
---|---  
  
Выходной параметр

Angle | \- значение угла в градусах.  
---|---  
  
Примечание:

Параметр Angle является одновременно и входным, и выходным.

На входе он представляет собой угол в локальной СК, а в результате работы функции преобразуется в угол в СК вида.

Версия Компас v23

Подразделы:

(отсутствуют)
