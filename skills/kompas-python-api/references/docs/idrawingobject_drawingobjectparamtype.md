# DrawingObjectParamType - Тип для получения и изменения параметров объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - свойства ](idrawingobject_props.html) |  Scroll [ [ [ ](idrawingobject_layernumber.html "К следующему разделу")](idrawingobject_props.html "На уровень выше")](idrawingobject_drawingobjecttype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingobject.html)

Тип данных: [ksDrawingObjectParamTypeEnum](ksdrawingobjectparamtypeenum.html).

Синтаксис Automation:

type = iObject.DrawingObjectParamType | Получить свойство([* ](1.html))  
---|---  
iObject.DrawingObjectParamType = type | Установить свойство ([* ](1.html))  
type = iObject.GetDrawingObjectParamType() | Получить свойство ([**](2.html))  
iObject.SetDrawingObjectParamType (type) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DrawingObjectParamType (&type) | Получить свойство  
---|---  
iObject->put_DrawingObjectParamType (type) | Установить свойство  
  
Примечание:

Свойство позволяет установить и получить тип используемой матрицы для пересчета параметров объектов. От матрицы зависят возвращаемые значения координат, углов и скалярных величин размеров, например, радиус, высота, длина.

Подразделы:

(отсутствуют)
