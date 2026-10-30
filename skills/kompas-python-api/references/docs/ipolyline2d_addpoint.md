# AddPoint - Добавить точку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IPolyLine2D ](ipolyline2d.html) > [IPolyLine2D - методы ](ipolyline2d_methods.html) |  Scroll [ [ [ ](ipolyline2d_clear.html "К следующему разделу")](ipolyline2d_methods.html "На уровень выше")](ipolyline2d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolyline2d.html)

Синтаксис Automation:

BOOL AddPoint( long Index,

double X,

double Y );

Синтаксис COM:

HRESULT AddPoint( long Index,

double X,

double Y,

BOOL * Result );

Входные параметры:

Index | \- индекс добавляемой точки,  
---|---  
X, Y | \- координаты добавляемой точки.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить точку в полилинию.

Подразделы:

(отсутствуют)
