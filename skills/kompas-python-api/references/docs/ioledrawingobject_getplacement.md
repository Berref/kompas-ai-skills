# GetPlacement - Получить местоположение объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IOleDrawingObject ](ioledrawingobject.html) > [IOleDrawingObject - методы ](ioledrawingobject_methods.html) |  Scroll [ [ [ ](ioledrawingobject_setplacement.html "К следующему разделу")](ioledrawingobject_methods.html "На уровень выше")](ioledrawingobject_doverb.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ioledrawingobject.html)

Синтаксис Automation:

BOOL GetPlacement( double * X,

double * Y,

double * Angle,

BOOL * MirrorSymmetry );

Синтаксис COM:

HRESULT GetPlacement( double * X,

double * Y,

double * Angle,

BOOL * MirrorSymmetry,

BOOL * Result );

Входные параметры:

X, Y | \- координаты точки привязки,  
---|---  
Angle | \- угол поворота объекта,  
MirrorSymmetry | \- признак зеркальной симметрии объекта.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить точку привязки и угол поворота растрового объекта.

Подразделы:

(отсутствуют)
