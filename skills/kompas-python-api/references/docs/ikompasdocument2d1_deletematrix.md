# DeleteMatrix - Удалить матрицу трансформации

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_destroyobjects.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_deletehyperlinks.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL DeleteMatrix();;

Синтаксис COM:

HRESULT DeleteMatrix( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод отменяет режим преобразования координат, линейных и угловых параметров, введенный методом [IKompasDocument2D1::CreateMatrix](ikompasdocument2d1_creatematrix.html).

Версия Компас v23

Подразделы:

(отсутствуют)
