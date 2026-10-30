# GetByIndex - Получить координаты точки по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции трехмерных координат (Интерфейсы ksCoordinate3dCollection, ICoordinate3dCollection) ](kscoordinate3dcollection.html) > [ICoordinate3dCollection - методы ](kscoordinate3dcollection_methods.html) |  Scroll [ [ [ ](kscoordinate3dcollection_getcount.html "К следующему разделу")](kscoordinate3dcollection_methods.html "На уровень выше")](kscoordinate3dcollection_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscoordinate3dcollection.html)

Синтаксис Automation:

BOOL GetByIndex (long index, double* x, double* y, double* z);

Синтаксис COM:

BOOL GetByIndex (long index, double* x, double* y, double* z);

Входные параметры:

index | \- индекс точки.  
---|---  
  
Выходные параметры:

x, y, z | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
