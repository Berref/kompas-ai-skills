# Attach - Добавить существующий слой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) > [Интерфейс ILayers ](ilayers.html) > [ILayers - методы ](ilayers_methods.html) |  Scroll [ [ [ ](ilayers_detach.html "К следующему разделу")](ilayers_methods.html "На уровень выше")](ilayers_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayers.html)

Синтаксис Automation:

BOOL Attach (LPDISPATCH pVal);

Синтаксис COM:

HRESULT Attach ([in] ILayer * pVal, [out, retval] VARIANT_BOOL * Result);

Входные параметры:

pVal | \- Указатель на интерфейс слоя [ILayer](ilayer.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Интерфейс слоя добавляется в коллекцию.

2\. Метод работает только для коллекции слоев группы [ILayerGroup](ilayergroup.html), если она не является динамической.

Подразделы:

(отсутствуют)
