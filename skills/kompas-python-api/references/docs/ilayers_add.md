# Add - Создать слой (добавляет слой в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) > [Интерфейс ILayers ](ilayers.html) > [ILayers - методы ](ilayers_methods.html) |  Scroll [ [ [ ](ilayers_attach.html "К следующему разделу")](ilayers_methods.html "На уровень выше")](ilayers_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayers.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add ([out, retval] ILayer** Layer);

Возвращаемое значение:

| \- Указатель на интерфейс слоя [ILayer](ilayer.html).  
---|---  
  
Примечание:

1\. Интерфейс слоя добавляется в коллекцию.

2\. Слой в документе будет создан после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
