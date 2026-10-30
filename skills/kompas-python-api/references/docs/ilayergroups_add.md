# Add - Создать группу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroups ](ilayergroups.html) > [ILayerGroups - методы ](ilayergroups_methods.html) |  Scroll [ [ [ ](ilayergroups_attach.html "К следующему разделу")](ilayergroups_methods.html "На уровень выше")](ilayergroups_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroups.html)

Синтаксис Automation:

LPDISPATCH Add( [in] LPDISPATCH owner, [in] VARIANT_BOOL dinamic );

Синтаксис Automation:

HRESULT Add( [in] IView* owner, [in] VARIANT_BOOL dinamic, [out, retval] ILayerGroup** Result );

Входные параметры:

owner | \- вид - владелец группы,  
---|---  
dinamic | \- признак динамической группы.  
  
Возвращаемое значение:

[Указатель на интерфейс группы слоев ILayerGroup](ilayergroup.html) |   
  
---|---  
  
Примечание:

Группа добавляется в коллекцию.

Подразделы:

(отсутствуют)
