# GetPlacement - Получить точку привязки и угол поворота системы координат макроэлемента

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IMacroObject ](imacroobject.html) > [IMacroObject - методы ](imacroobject_methods.html) |  Scroll [ [ [ ](imacroobject_setobjects.html "К следующему разделу")](imacroobject_methods.html "На уровень выше")](imacroobject_findobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject.html)

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
Angle | \- угол поворота макроэлемента,  
MirrorSymmetry | \- признак зеркальной симметрии объекта.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить точку привязки и угол поворота макроэлемента.

Подразделы:

(отсутствуют)
