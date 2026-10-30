# GetSafeArray - Сформировать массив SAFEARRAY координат точек

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции трехмерных координат (Интерфейсы ksCoordinate3dCollection, ICoordinate3dCollection) ](kscoordinate3dcollection.html) > [ICoordinate3dCollection - методы ](kscoordinate3dcollection_methods.html) |  Scroll [ [ [ ](cb1715698.html "К следующему разделу")](kscoordinate3dcollection_methods.html "На уровень выше")](kscoordinate3dcollection_getcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscoordinate3dcollection.html)

Синтаксис Automation:

BOOL GetSafeArray (VARIANT* pArray);

Синтаксис COM:

BOOL GetSafeArray (VARIANT* pArray);

Выходные параметры:

pArray | \- одномерный массив вещественных чисел VT_ARRAR | VT_R8.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Координаты точек в полученном массиве лежат в следующей последовательности:

x0, y0, z0, x1, y1, z1, ...xi, yi, zi

Подразделы:

(отсутствуют)
