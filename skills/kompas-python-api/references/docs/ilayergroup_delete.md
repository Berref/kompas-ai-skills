# Delete - Удалить группу слоев

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroup ](ilayergroup.html) > [ILayerGroup - методы ](ilayergroup_methods.html) |  Scroll [ [ [ ](ilayergroup_getlayerstates.html "К следующему разделу")](ilayergroup_methods.html "На уровень выше")](ilayergroup_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroup.html)

Синтаксис Automation:

BOOL Delete();

Синтаксис COM:

HRESULT Delete ([out, retval] VARIANT_BOOL * pVal);

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

При удалении группы слоев слои, входящие в нее, из документа не удаляются. Для удаления слоя используется метод [IDrawingObject::Delete](idrawingobject_delete.html).

Подразделы:

(отсутствуют)
