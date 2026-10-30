# SetPlacement - Установить местоположение растрового объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IRaster ](iraster.html) > [IRaster - методы ](iraster_methods.html) |  Scroll [ [ [ ](istraightslot.html "К следующему разделу")](iraster_methods.html "На уровень выше")](iraster_getplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iraster.html)

Синтаксис Automation:

BOOL SetPlacement( double X,

double Y,

double Angle,

BOOL * MirrorSymmetry );

Синтаксис COM:

HRESULT SetPlacement( double X,

double Y,

double Angle,

BOOL MirrorSymmetry,

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

1\. Метод позволяет установить точку привязки и угол поворота растрового объекта.

2\. После применения к растровому объекту операции Симметрия его признак зеркальной симметрии автоматически инвертируется.

Подразделы:

(отсутствуют)
