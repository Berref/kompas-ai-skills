# SetVector - Задать вектор для указанной оси

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IPlacement3D ](iplacement3d.html) > [IPlacement3D - методы ](iplacement3d_methods.html) |  Scroll [ [ [ ](bc2014000.html "К следующему разделу")](iplacement3d_methods.html "На уровень выше")](iplacement3d_setorigin.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplacement3d.html)

Синтаксис Automation:

BOOL SetVector( ksObj3dTypeEnum Axis, double X, double Y, double Z );

Синтаксис COM:

HRESULT SetVector( ksObj3dTypeEnum Axis, double X, double Y, double Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

Axis | \- ось,  
---|---  
X | \- координата точки по X,  
Y | \- координата точки по Y,  
Z | \- координата точки по Z.  
  
Подразделы:

(отсутствуют)
