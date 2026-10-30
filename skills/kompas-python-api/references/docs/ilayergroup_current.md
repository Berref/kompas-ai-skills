# Current - Группа является текущей (состояния слоев переданы в модель)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroup ](ilayergroup.html) > [ILayerGroup - свойства ](ilayergroup_props.html) |  Scroll [ [ [ ](ilayergroup_layers.html "К следующему разделу")](ilayergroup_props.html "На уровень выше")](ilayergroup_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroup.html)

Тип данных: BOOL

Синтаксис Automation:

Current = iObject.Current | Получить свойство ([* ](1.html))  
---|---  
iObject.Current = Current | Установить свойство ([* ](1.html))  
Current = iObject.GetCurrent() | Получить свойство ([**](2.html))  
iObject.SetCurrent (Current) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Current (&Current) | Получить свойство  
---|---  
iObject->put_Current (Current) | Установить свойство  
  
Примечание:

Свойство используется, если в документе установлен режим Группировать свойства слоев, т. е. свойство [IDocument2DSettings::LayersGroupWay](idocument2dsettings_layersgroupway.html) имеет значение wgLayersCharacteristics.

Подразделы:

(отсутствуют)
