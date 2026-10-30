# InitByMatrix3D - Установить систему координат по матрице. SAFEARRAY double (VT_ARRAY | VT_R8)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IPlacement3D ](iplacement3d.html) > [IPlacement3D - методы ](iplacement3d_methods.html) |  Scroll [ [ [ ](iplacement3d_rotate.html "К следующему разделу")](iplacement3d_methods.html "На уровень выше")](iplacement3d_getpointprojectiontoxy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplacement3d.html)

Синтаксис Automation:

BOOL InitByMatrix3D( VARIANT mtr );

Синтаксис COM:

HRESULT InitByMatrix3D( VARIANT mtr, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

mtr | \- массив координат SAFEARRAY double (VT_ARRAY | VT_R8).  
---|---  
  
Подразделы:

(отсутствуют)
