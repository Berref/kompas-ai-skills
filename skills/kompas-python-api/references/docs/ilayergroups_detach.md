# Detach - Отсоединить группу слоев

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroups ](ilayergroups.html) > [ILayerGroups - методы ](ilayergroups_methods.html) |  Scroll [ [ [ ](ilayerfilterconditions.html "К следующему разделу")](ilayergroups_methods.html "На уровень выше")](ilayergroups_attach.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroups.html)

Синтаксис Automation:

BOOL Detach (LPDISPATCH pVal);

Синтаксис COM:

HRESULT Detach ([in] ILayerGroup * pVal, [out, retval] VARIANT_BOOL * Result);

Входные параметры:

pVal | \- Указатель на интерфейс группы слоев [ILayerGroup.](ilayergroup.html)  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Интерфейс группы слоев отсоединяется от коллекции, группа при этом из документа не удаляется.

Подразделы:

(отсутствуют)
