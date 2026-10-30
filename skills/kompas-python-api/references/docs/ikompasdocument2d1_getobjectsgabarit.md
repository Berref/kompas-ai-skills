# GetObjectsGabarit - Габарит объекта, вида, слоя, группы или списка объектов

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_findobject.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_getobjectbyid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL GetObjectsGabarit( VARIANT Objects, double * X1, double * Y1, double * X2, double * Y2 );

Синтаксис COM:

HRESULT GetObjectsGabarit( VARIANT Objects, double * X1, double * Y1, double * X2, double * Y2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- объект (VT_DISPATCH) или список объектов (VT_APPAY | VT_DISPATCH).  
---|---  
  
Выходные параметры:

X1, Y1 | \- первая точка габарита - левая нижняя,  
---|---  
X2, Y2 | \- вторая точка габарита - правая верхняя.  
  
Примечание:

Габаритный прямоугольник возвращается в координатах листа.

Версия Компас v23

Подразделы:

(отсутствуют)
