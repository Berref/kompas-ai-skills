# MoveObjects - Сдвинуть объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_rebuilddocument.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_isvariablenamevalid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL MoveObjects( VARIANT Objects, double DX, double DY );

Синтаксис COM:

HRESULT MoveObjects( VARIANT Objects, double DX, double DY, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- объект (VT_DISPATCH) или список объектов (VT_ARRAY | VT_DISPATCH),  
---|---  
DX, DY | \- вектор смещения объекта.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
