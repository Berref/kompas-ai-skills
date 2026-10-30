# SetPlacement - Установить точку привязки и угол поворота системы координат макроэлемента

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IMacroObject ](imacroobject.html) > [IMacroObject - методы ](imacroobject_methods.html) |  Scroll [ [ [ ](imacroobject_transformangletoview.html "К следующему разделу")](imacroobject_methods.html "На уровень выше")](imacroobject_setobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject.html)

Синтаксис Automation:

BOOL SetPlacement( double X,

double Y,

double Angle,

BOOL * MirrorSymmetry );

Синтаксис COM:

HRESULT SetPlacement( double X,

double Y,

double Angle,

BOOL * MirrorSymmetry,

BOOL * Result );

Входные параметры:

X, Y | \- координаты точки привязки,  
---|---  
Angle | \- угол поворота макроэлемента,  
MirrorSymmetry | \- признак зеркальной симметрии объекта (NULL – не изменять признак).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить точку привязки и угол поворота макроэлемента.

Смотрите также:

Рекомендации по обеспечению корректного редактирования библиотекой макроэлементов, [геометрия которых зеркально отражена относительно исходного ее построения](mirrored_macro.html)

Подразделы:

(отсутствуют)
