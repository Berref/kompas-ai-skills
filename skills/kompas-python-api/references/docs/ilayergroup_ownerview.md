# OwnerView - Владелец группы - вид

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerGroup ](ilayergroup.html) > [ILayerGroup - свойства ](ilayergroup_props.html) |  Scroll [ [ [ ](ilayergroup_uniqueid.html "К следующему разделу")](ilayergroup_props.html "На уровень выше")](ilayergroup_ownergroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayergroup.html)

Тип данных: указатель на интерфейс вида [IView](iview.html)

Синтаксис Automation:

OwnerView = iObject.OwnerView | Получить свойство ([* ](1.html))  
---|---  
iObject.OwnerView = OwnerView | Установить свойство ([* ](1.html))  
OwnerView = iObject.GetOwnerView() | Получить свойство ([**](2.html))  
iObject.SetOwnerView (OwnerView) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_OwnerView (&OwnerView) | Получить свойство  
---|---  
iObject->put_OwnerView (OwnerView) | Установить свойство  
  
Примечание:

1\. Свойство позволяет отсоединить группу от вида.

2\. Чтобы установить свойство отсоединения группы от вида, необходимо передать параметр с нулевым значением.

Подразделы:

(отсутствуют)
