# SetDisplacementByAxis - Установить смещение по оси

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - методы ](ilocalcoordinatesystem_methods.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_setstartingorientation.html "К следующему разделу")](ilocalcoordinatesystem_methods.html "На уровень выше")](ilocalcoordinatesystem_setassociationobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Синтаксис Automation:

BOOL SetDisplacementByAxis( ksObj3dTypeEnum axis,

double NewVal );

Синтаксис COM:

HRESULT SetDisplacementByAxis( ksObj3dTypeEnum axis,

double NewVal

BOOL * Result);

Входные параметры:

axis | \- тип оси из перечисления [ksObj3dTypeEnum](obj3dtype.html) допустимые типы: \- o3d_axisOX, \- o3d_axisOY \- o3d_axisOZ.  
---|---  
NewVal | \- величина смещения.  
  
Возвращаемое значение:

TRUE | \- в случае успеха;  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Позволяет установить смещение точки начала координат ЛСК вдоль оси ЛСК.

2\. Чтобы изменения вступили в силу, нужно вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
