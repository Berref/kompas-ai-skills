# TransferObjects - Перенести в СК

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_unload.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_transformpoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BOOL TransferObjects( VARIANT objects,

LPDISPATCH Lcs,

BOOL holdPosition );

Синтаксис COM:

HRESULT TransferObjects( VARIANT objects,

ILocalCoordinateSystem * Lcs,

VARIANT_BOOL holdPosition,

BOOL * Result );

Входные параметры:

objects | \- объект или список SafeArray объектов которые требуется перенести в другую систему координат,  
---|---  
Lcs | \- указатель на интерфейс локальной системы координат [ILocalCoordinateSystem](ilocalcoordinatesystem.html),  
holdPosition | \- сохранять положение.  
  
Возвращаемое значение:

TRUE | \- в случае успеха.  
---|---  
  
Примечание:

1\. Метод позволяет перенести следующие объекты модели [IModelObject](imodelobject.html):

•3D точка,

•ломаная,

•сплайн,

•эскиз,

•импортированная поверхность,

•операция без истории,

•деталь заготовка,

•локальная система координат.

2\. Если объекты нужно перенести в систему координат детали, нужно в качестве параметра Lcs передать NULL.

3\. Если нужно перенести один объект, его можно передать в VARIANT-е как указатель на DISPATCH, тип VARIANT-а VT_DISPATCH.

4\. Если нужно перенести несколько объектов, нужно передать в VARIANT-е как указатель на массив SafeArray тип VARIANT-а VT_ARRAY | VT_DISPATCH.

5\. Если параметр holdPosition == TRUE, то положение объекта в документе не изменяется.

6\. Если параметр holdPosition == FALSE, то положение объекта будет задано относительно новой системы координат.

7\. Значение флага holdPosition может не учитываться при наличии ассоциативных связей объектов или особенностей создания объекта.

Подразделы:

(отсутствуют)
