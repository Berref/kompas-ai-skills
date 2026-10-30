# VertexLimiter - Типы ограничений в вершинах мультилинии

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_vertexradius.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_vertexdirection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: из перечисления [ksMlVertexLimiterEnum](ksmlvertexlimiterenum.html)

Синтаксис Automation:

VertexLimiter = iObject.VertexLimiter( VertexIndex ); | Получить свойство([* ](1.html))  
---|---  
iObject.VertexLimiter( VertexIndex ) = VertexLimiter; | Установить свойство ([* ](1.html))  
VertexLimiter = iObject.GetVertexLimiter( VertexIndex ); | Получить свойство ([**](2.html))  
iObject.SetVertexLimiter( VertexIndex, VertexLimiter ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VertexLimiter( VertexIndex, &VertexLimiter ) | Получить свойство  
---|---  
iObject->put_VertexLimiter( VertexIndex, VertexLimiter ) | Установить свойство  
  
Входные параметры:

long VertexIndex | \- индекс вершины.  
---|---  
  
Примечание:

1\. Свойство позволяет устанавливать и получать тип ограничения в вершине мультилинии.

2\. Свойство доступно только при типе обхода вершины ksMTrShear ([ksMlEndLimiterEnum](ksmlendlimiterenum.html)).

Подразделы:

(отсутствуют)
