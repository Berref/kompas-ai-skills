# VertexParamsArray - Массив параметров вершин в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPolyLine ](ipolyline.html) > [IPolyLine - свойства ](ipolyline_props.html) |  Scroll [ [ [ ](ipolyline_vertexvisible.html "К следующему разделу")](ipolyline_props.html "На уровень выше")](ipolyline_vertexparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolyline.html)

Тип данных: VARIANT

Значения свойства:

Массив SafeArray типа VT_ARRAY | VT_DISPATCH. |   
---|---  
  
Синтаксис Automation:

VertexParamsArray = iObject.VertexParamsArray; | Получить свойство ([* ](1.html))  
---|---  
VertexParamsArray = iObject.GetVertexParamsArray(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VertexParamsArray( &VertexParamsArray ) | Получить свойство  
---|---  
  
Примечание.

1\. Свойство доступно только для чтения.

2\. Свойство позволяет получить массив SAFEARRAY параметров всех вершин. Массив VT_DISPATCH, которые можно преобразовать в интерфейсы [ICurveVertexParam](icurvevertexparam.html).

Подразделы:

(отсутствуют)
