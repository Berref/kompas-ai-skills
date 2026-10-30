# VertexStyle - Стиль кривой в вершине

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_methods.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_vertexradius.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: long (соответствует перечислению [ksCurveStyleEnum](kscurvestyleenum.html))

Синтаксис Automation:

VertexStyle = iObject.VertexStyle( VertexIndex ); | Получить свойство([* ](1.html))  
---|---  
iObject.VertexStyle( VertexIndex ) = VertexStyle; | Установить свойство ([* ](1.html))  
VertexStyle = iObject.GetVertexStyle( VertexIndex ); | Получить свойство ([**](2.html))  
iObject.SetVertexStyle( VertexIndex, VertexStyle ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VertexStyle( VertexIndex, &VertexStyle ) | Получить свойство  
---|---  
iObject->put_VertexStyle( VertexIndex, VertexStyle ) | Установить свойство  
  
Входные параметры:

long VertexIndex | \- индекс вершины.  
---|---  
  
Примечание:

1\. Свойство позволяет устанавливать и получать тип ограничения в вершине мультилинии.

2\. Свойство доступно только при типе обхода вершины ksMTrShear ([ksMlEndLimiterEnum](ksmlendlimiterenum.html)).

Подразделы:

(отсутствуют)
