# GetGabarit - Выдать габарит

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_getmaxsag.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_getdummyembodimentmarking.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BOOL GetGabarit( BOOL Full, BOOL Customizable, double * X1, double * Y1, double * Z1, double * X2, double * Y2, double * Z2 );

Синтаксис COM:

HRESULT GetGabarit( BOOL Full, BOOL Customizable, double * X1, double * Y1, double * Z1, double * X2, double * Y2, double * Z2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Full | -TRUE - полный, \- FALSE - только тела,  
---|---  
Customizable | \- TRUE - с учетом настроек видимости, \- FALSE - без учета настроек видимости; при full == FALSE игнорируется.  
  
Выходные параметры:

x1, y1, z1 | \- координаты первой точки габаритного параллелепипеда,  
---|---  
x2, y2, z2 | \- координаты второй точки габаритного параллелепипеда.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
