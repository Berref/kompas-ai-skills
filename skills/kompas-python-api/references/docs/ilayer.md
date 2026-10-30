# Интерфейс ILayer

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) |  Scroll [ [ [ ](ilayer_props.html "К следующему разделу")](idrawingobject_methods.html "На уровень выше")](idrawingobject_update.html "К предыдущему разделу")  
---|---  
  
Интерфейс слоя графического документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[ILayer](ilayer.html)

Описание:

В графическом документе в каждом виде всегда присутствует хотя бы один слой, который создается автоматически при создании документа и нового вида.

Примечание:

Данный интерфейс можно получить через коллекцию слоев [ILayers](ilayers.html) с помощью свойства [ILayers::Layer](ilayers_layer.html), [ILayers::LayerByNumber](ilayers_layerbynumber.html), метода [ILayers::Add](ilayers_add.html), либо с помощью свойства [IDrawingObjects::Item](idrawingobjects_item.html) с последующим приведением к данному интерфейсу с помощью метода IUnknown QueryInterface.

Подразделы:

[ILayer - свойства ](ilayer_props.html)
