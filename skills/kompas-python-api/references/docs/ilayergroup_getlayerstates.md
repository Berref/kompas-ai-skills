# GetLayerStates - Получить состояния слоя группы по индексу, имени или ссылке

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroup ](ilayergroup.html) > [ILayerGroup - методы ](ilayergroup_methods.html) |  Scroll [ [ [ ](ilayergroup_setlayerstates.html "К следующему разделу")](ilayergroup_methods.html "На уровень выше")](ilayergroup_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroup.html)

Синтаксис Automation:

BOOL GetLayerStates ([in] VARIANT LayerIndex,

[out] BOOL* visible,

[out] BOOL* background,

[out] BOOL* curent,

[out] long* color);

Синтаксис COM:

HRESULT GetLayerStates ([in] VARIANT LayerIndex,

[out] VARIANT_BOOL* visible,

[out] VARIANT_BOOL* background,

[out] VARIANT_BOOL* curent,

[out] long* color,

[out, retval] VARIANT_BOOL* pRes );

Входные параметры:

LayerIndex | \- индекс слоя.  
---|---  
  
Выходные параметры:

visible | \- свойство - видимый слой,  
---|---  
background | \- свойство - фоновый слой,  
current | \- свойство - текущий слой,  
color | \- цвет слоя.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Если в документе установлен режим Группировать свойства слоев, т. е. свойство [IDocument2DSettings::LayersGroupWay](idocument2dsettings_layersgroupway.html) имеет значение wgLayersCharacteristics, то метод позволяет получить свойства слоя в группе. При этом значения свойств могут отличаться от установленных в текущий момент у слоя в документе. Для передачи свойств слою из группы нужно сделать группу текущей, то есть установить значение [ILayerGroup::Current](ilayergroup_current.html) равным TRUE.

2\. Если в документе установлен режим Группировать слои, т. е. свойство [IDocument2DSettings::LayersGroupWay](idocument2dsettings_layersgroupway.html) имеет значение wgLayers, то метод используется для получения свойств конкретного слоя (LayerIndex - индекс слоя).

Подразделы:

(отсутствуют)
