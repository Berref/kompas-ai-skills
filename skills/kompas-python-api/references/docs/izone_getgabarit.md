# GetGabarit - Выдать габарит

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Зоны ](cu1735335.html) > [Интерфейс IZone ](izone.html) > [IZone - методы ](izone_methods.html) |  Scroll [ [ [ ](izonesmanager.html "К следующему разделу")](izone_methods.html "На уровень выше")](izone_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](izone.html)

Синтаксис Automation:

BOOL GetGabarit( double * X1, double * Y1, double * Z1, double * X2, double * Y2, double * Z2 );

Синтаксис COM:

HRESULT GetGabarit( double * X1, double * Y1, double * Z1, double * X2, double * Y2, double * Z2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Выходные параметры:

X1, Y1, Z1, X2, Y2, Z2 | \- координаты габаритного параллелепипеда.  
---|---  
  
Подразделы:

(отсутствуют)
