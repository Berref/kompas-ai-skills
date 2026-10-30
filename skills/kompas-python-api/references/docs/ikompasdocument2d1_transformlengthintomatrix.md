# TransformLengthIntoMatrix - Перевести длину в локальную СК

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_transformobjects.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_transformlengthfrommatrix.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL TransformLengthIntoMatrix( double * Length );

Синтаксис COM:

HRESULT TransformLengthIntoMatrix( double * Length, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входной параметр:

Length | \- длина.  
---|---  
  
Выходной параметр:

Length | \- длина.  
---|---  
  
Примечание:

Параметр Length является одновременно и входным, и выходным.

На входе он представляет собой длину в СК вида, а в результате работы функции преобразуется в длину в локальной СК.

Версия Компас v23

Подразделы:

(отсутствуют)
