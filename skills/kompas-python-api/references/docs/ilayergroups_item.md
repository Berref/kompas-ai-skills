# Item - Группа, заданная по индексу, имени или уникальному идентификатору

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroups ](ilayergroups.html) > [ILayerGroups - свойства ](ilayergroups_props.html) |  Scroll [ [ [ ](ilayergroups_methods.html "К следующему разделу")](ilayergroups_props.html "На уровень выше")](ilayergroups_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroups.html)

Тип данных: указатель на интерфейс [ILayerGroup](ilayergroup.html)

Синтаксис Automation:

Item = iObject.Item | Получить свойство ([* ](1.html))  
---|---  
Item = iObject.GetItem() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (&Item) | Получить свойство  
---|---  
  
Входные параметры:

index | \- индекс объекта в коллекции (тип VARIANT).  
---|---  
  
Примечание:

Свойство доступно только для чтения.

В качестве индекса может использоваться индекс элемента в массиве, имя или уникальный идентификатор [ILayerGroup::UniqueId](ilayergroup_uniqueid.html). Для получения группы по идентификатору нужно передать вещественное число, установив тип значения VT_R8.

Подразделы:

(отсутствуют)
