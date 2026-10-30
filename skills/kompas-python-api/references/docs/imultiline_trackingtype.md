# TrackingType - Тип обхода вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_vertexcount.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_linestyle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: из перечисления [ksMlVertexTrackingEnum](ksmlvertextrackingenum.html)

Синтаксис Automation:

TrackingType = iObject.TrackingType( LineIndex ); | Получить свойство([* ](1.html))  
---|---  
iObject.TrackingType( LineIndex ) = TrackingType; | Установить свойство ([* ](1.html))  
TrackingType = iObject.GetTrackingType( LineIndex ); | Получить свойство ([**](2.html))  
iObject.SetTrackingType( LineIndex, TrackingType ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_TrackingType( LineIndex, &TrackingType ) | Получить свойство  
---|---  
iObject->put_TrackingType( LineIndex, TrackingType ) | Установить свойство  
  
Входные параметры:

long LineIndex | \- индекс линии.  
---|---  
  
Примечание:

Свойство позволяет устанавливать и получать тип обхода вершины мультилинии.

Подразделы:

(отсутствуют)
