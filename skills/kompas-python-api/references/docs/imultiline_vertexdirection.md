# VertexDirection - Направление дуги в вершине

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_vertexlimiter.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_vertexcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- по часовой стрелке,  
---|---  
FALSE | \- против часовой стрелки.  
  
Синтаксис Automation:

VertexDirection = iObject.VertexDirection( VertexIndex ); | Получить свойство([* ](1.html))  
---|---  
iObject.VertexDirection( VertexIndex ) = VertexDirection; | Установить свойство ([* ](1.html))  
VertexDirection = iObject.GetVertexDirection( VertexIndex ); | Получить свойство ([**](2.html))  
iObject.SetVertexDirection( VertexIndex, VertexDirection ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VertexDirection( VertexIndex, &VertexDirection ) | Получить свойство  
---|---  
iObject->put_VertexDirection( VertexIndex, VertexDirection ) | Установить свойство  
  
Входные параметры:

long VertexIndex | \- индекс вершины.  
---|---  
  
Примечание:

1\. Свойство позволяет устанавливать и получать направление дуги в вершине мультилинии.

2\. Свойство доступно только при типе обхода вершины ksMTrShear ([ksMlEndLimiterEnum](ksmlendlimiterenum.html)).

Подразделы:

(отсутствуют)
