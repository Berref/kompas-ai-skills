# TransformObjects - Трансформировать объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_transformpointintomatrix.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_transformlengthintomatrix.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL TransformObjects( VARIANT Objects );

Синтаксис COM:

HRESULT TransformObjects( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- объект (VT_DISPATCH) или список объектов (VT_ARRAY | VT_DISPATCH).  
---|---  
  
Примечание:

Для работы с матрицами служат методы [IKompasDocument2D1::CreateMatrix](ikompasdocument2d1_creatematrix.html) и [IKompasDocument2D1::DeleteMatrix](ikompasdocument2d1_deletematrix.html).

Версия Компас v23

Подразделы:

(отсутствуют)
