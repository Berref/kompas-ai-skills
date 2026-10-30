# SetLimit - Установить пределы поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IPlane3D1 ](iplane3d1.html) > [IPlane3D1 - методы ](iplane3d1_methods.html) |  Scroll [ [ [ ](iconjunctivepoints.html "К следующему разделу")](iplane3d1_methods.html "На уровень выше")](iplane3d1_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplane3d1.html)

Синтаксис Automation:

BOOL SetLimit( double Umin, double Vmin, double Umax, double Vmax );

Синтаксис COM:

HRESULT SetLimit( double Umin, double Vmin, double Umax, double Vmax, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Umin, Vmin, Umax, Vmax | \- новые граничные параметры поверхности.  
---|---  
  
Версия Компас v21

Подразделы:

(отсутствуют)
