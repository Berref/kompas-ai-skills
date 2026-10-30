# Add - Добавить угловой размер в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс AngleDimensions ](iangledimensions.html) > [IAngleDimensions - методы ](iangledimensions_methods.html) |  Scroll [ [ [ ](iarcdimensions.html "К следующему разделу")](iangledimensions_methods.html "На уровень выше")](iangledimensions_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iangledimensions.html)

Синтаксис Automation:

LPDISPATCH Add( DrawingObjectTypeEnum DimType );

Синтаксис COM:

HRESULT Add( DrawingObjectTypeEnum DimType, [out, retval] IAngleDimension** Result);

Входной параметр:

DimType | \- тип объекта.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс углового размера [IAngleDimension](iangledimension.html).  
---|---  
  
Примечание:

Для добавления углового размера в качестве параметра DimType нужно передать константу ksDrADimension, для углового размера с обрывом нужно передать константу ksDrABreakDimension.

Подразделы:

(отсутствуют)
