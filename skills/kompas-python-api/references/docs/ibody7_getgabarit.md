# GetGabarit - Получить габарит

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Твердое тело ](bc2297187.html) > [Интерфейс IBody7 ](ibody7.html) > [IBody7 - методы ](ibody7_methods.html) |  Scroll [ [ [ ](ibody7_update.html "К следующему разделу")](ibody7_methods.html "На уровень выше")](ibody7_curveintersection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibody7.html)

Синтаксис Automation:

BOOL GetGabarit( double * X1,

double * Y1,

double * Z1,

double * X2,

double * Y2,

double * Z2 );

Синтаксис COM:

HRESULT GetGabarit( double * X1,

double * Y1,

double * Z1,

double * X2,

double * Y2,

double * Z2

BOOL * Result );

Входные параметры:

X1, Y1, Z1, X2, Y2, Z2 | \- координаты габаритного прямоугольника.  
---|---  
  
Возвращаемое значение:

TRUE | \- успешное завершение,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить габаритный прямоугольник Панели свойств. Точки задаются в относительных координатах окна КОМПАС.

Подразделы:

(отсутствуют)
