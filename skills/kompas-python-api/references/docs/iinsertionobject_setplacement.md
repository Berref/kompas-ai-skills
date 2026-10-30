# SetPlacement - Установить местоположение объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionObject ](iinsertionobject.html) > [IInsertionObject - методы ](iinsertionobject_methods.html) |  Scroll [ [ [ ](iinsertionfragment.html "К следующему разделу")](iinsertionobject_methods.html "На уровень выше")](iinsertionobject_getplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertionobject.html)

Синтаксис Automation:

BOOL SetPlacement( double X,

double Y,

double Angle,

BOOL MirrorSymmetry )

Синтаксис COM:

HRESULT SetPlacement( double X,

double Y,

double Angle,

BOOL MirrorSymmetry,

BOOL * Result );

Входные параметры:

X, Y | \- координаты объекта,  
---|---  
Angle | \- угол поворота объекта,  
MirrorSymmetry | \- признак зеркальной симметрии объекта.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить местоположение объекта.

Подразделы:

(отсутствуют)
