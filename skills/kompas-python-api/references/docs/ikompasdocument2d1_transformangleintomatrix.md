# TransformAngleIntoMatrix - Перевод угла из CK вида в локальную CK

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_transformanglefrommatrix.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_symmetryobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL TransformAngleIntoMatrix( double * Angle );

Синтаксис COM:

HRESULT TransformAngleIntoMatrix( double * Angle, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входной параметр:

Angle | \- значение угла в градусах.  
---|---  
  
Выходной параметр:

Angle | \- значение угла в градусах.  
---|---  
  
Примечание:

Параметр Angle является одновременно и входным, и выходным.

На входе он представляет собой угол в СК вида, а в результате работы функции преобразуется в угол в локальной СК.

Версия Компас v23

Подразделы:

(отсутствуют)
