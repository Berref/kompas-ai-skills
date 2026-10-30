# Attach - Добавить существующую группу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroups ](ilayergroups.html) > [ILayerGroups - методы ](ilayergroups_methods.html) |  Scroll [ [ [ ](ilayergroups_detach.html "К следующему разделу")](ilayergroups_methods.html "На уровень выше")](ilayergroups_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroups.html)

Синтаксис Automation:

BOOL Attach (LPDISPATCH pVal);

Синтаксис Automation:

HRESULT Attach ([in] ILayerGroup * pVal, [out, retval] VARIANT_BOOL * Result);

Входные параметры:

pVal | \- Указатель на интерфейс группы слоев [ILayerGroup](ilayergroup.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Интерфейс группы добавляется в коллекцию.

Подразделы:

(отсутствуют)
