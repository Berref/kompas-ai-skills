# VertexRadius - Радиус дуги в вершине

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_vertexstyle.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_vertexlimiter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: double

Синтаксис Automation:

VertexRadius = iObject.VertexRadius( VertexIndex ); | Получить свойство([* ](1.html))  
---|---  
iObject.VertexRadius( VertexIndex ) = VertexRadius; | Установить свойство ([* ](1.html))  
VertexRadius = iObject.GetVertexRadius( VertexIndex ); | Получить свойство ([**](2.html))  
iObject.SetVertexRadius( VertexIndex, VertexRadius ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VertexRadius( VertexIndex, &VertexRadius ) | Получить свойство  
---|---  
iObject->put_VertexRadius( VertexIndex, VertexRadius ) | Установить свойство  
  
Входные параметры:

long VertexIndex | \- индекс вершины.  
---|---  
  
Примечание:

1\. Свойство позволяет устанавливать и получать радиус дуги в вершине мультилинии.

2\. Свойство доступно только при типе обхода вершины ksMTrShear ([ksMlEndLimiterEnum](ksmlendlimiterenum.html)).

Подразделы:

(отсутствуют)
