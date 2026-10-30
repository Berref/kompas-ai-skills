# SetOrigin - Установить координаты начала локальной системы координат

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IPlacement3D ](iplacement3d.html) > [IPlacement3D - методы ](iplacement3d_methods.html) |  Scroll [ [ [ ](iplacement3d_setvector.html "К следующему разделу")](iplacement3d_methods.html "На уровень выше")](iplacement3d_rotate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplacement3d.html)

Синтаксис Automation:

BOOL SetOrigin( double X, double Y, double Z );

Синтаксис COM:

HRESULT SetOrigin( double X, double Y, double Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

X | \- координата точки по X,  
---|---  
Y | \- координата точки по Y,  
Z | \- координата точки по Z.  
  
Подразделы:

(отсутствуют)
