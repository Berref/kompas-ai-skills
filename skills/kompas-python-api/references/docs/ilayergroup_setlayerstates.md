# SetLayerStates - Изменить состояния слоя группы по индексу или имени

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroup ](ilayergroup.html) > [ILayerGroup - методы ](ilayergroup_methods.html) |  Scroll [ [ [ ](ilayerfiltercondition.html "К следующему разделу")](ilayergroup_methods.html "На уровень выше")](ilayergroup_getlayerstates.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroup.html)

Синтаксис Automation:

BOOL SetLayerStates ([in] VARIANT LayerIndex,

[in] BOOL visible,

[in]BOOL background,

[in] BOOL* curent,

[in] long color);

Синтаксис COM:

HRESULT SetLayerStates ([in] VARIANT LayerIndex,

[in] VARIANT_BOOL visible,

[in] VARIANT_BOOL background,

[in] VARIANT_BOOL curent,

[in] long color,

[out, retval] VARIANT_BOOL* pRes);

Входные параметры:

LayerIndex | \- индекс слоя,  
---|---  
visible | \- свойство - видимый слой,  
background | \- свойство - фоновый слой,  
current | \- свойство - текущий слой,  
color | \- цвет слоя.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Если в документе установлен режим Группировать свойства слоев, т. е. свойство [IDocument2DSettings::LayersGroupWay](idocument2dsettings_layersgroupway.html) имеет значение wgLayersCharacteristics, то метод позволяет установить свойства слоя в группе. При этом параметры слоя в документе не меняются. При этом значения свойств могут отличаться от установленных в текущий момент у слоя в документе. Для передачи свойств слою из группы нужно сделать группу текущей, то есть установить значение [ILayerGroup::Current](ilayergroup_current.html) равным TRUE.

2\. Если в документе установлен режим Группировать слои, т. е. свойство [IDocument2DSettings::LayersGroupWay](idocument2dsettings_layersgroupway.html) имеет значение wgLayers, то метод используется для установки свойств конкретного слоя (LayerIndex - индекс слоя). Для установки одинаковых состояний и цвета всем слоям, входящим в группу, нужно передать LayerIndex = -1.

Подразделы:

(отсутствуют)
